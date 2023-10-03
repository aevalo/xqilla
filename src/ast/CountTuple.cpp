/*
 * Copyright (c) 2001, 2008,
 *     DecisionSoft Limited. All rights reserved.
 * Copyright (c) 2004, 2010,
 *     Oracle and/or its affiliates. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <xqilla/ast/CountTuple.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/utils/XStr.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

CountTuple::CountTuple(TupleNode *parent, const XMLCh *varQName, XPath2MemoryManager *mm)
  : TupleNode(COUNT, parent, mm),
    var_(new (mm) ArgumentSpec(varQName, 0, mm))
{
}

CountTuple::CountTuple(TupleNode *parent, const ArgumentSpec *var, XPath2MemoryManager *mm)
  : TupleNode(COUNT, parent, mm),
    var_(new (mm) ArgumentSpec(var, mm))
{
}

TupleNode *CountTuple::staticResolution(StaticContext *context)
{
  parent_ = parent_->staticResolution(context);
  var_->staticResolution(context);
  return this;
}

static bool canPushCountBack(TupleNode *ancestor)
{
  switch(ancestor->getType()) {
  case TupleNode::COUNT: {
    return canPushCountBack(ancestor->getParent());
  }
  case TupleNode::ORDER_BY:
  case TupleNode::WHERE:
  case TupleNode::FOR:
  case TupleNode::CONTEXT_TUPLE:
    break;
  case TupleNode::LET:
  case TupleNode::DEBUG_HOOK:
    return true;
  }
  return false;
}

TupleNode *CountTuple::staticTypingImpl(StaticContext *context)
{
  // Push back if possible
  if(canPushCountBack(parent_)) {
    // Swap parent_ and this LetTuple, re-executing their staticTypingImpl() methods
    TupleNode *tmp = parent_;
    parent_ = tmp->getParent();
    tmp->setParent(this->staticTypingImpl(context));
    return tmp->staticTypingImpl(context);
  }

  const StaticType &pType = parent_->getStaticAnalysis().getStaticType();

  assert(pType.getTypes().size() == 1);
  const ItemType *pItemType = pType.getTypes()[0];
  assert(pItemType->getItemTestType() == ItemType::TEST_TUPLE);

  src_.clear();

  TupleMembers *members = new (getMemoryManager()) TupleMembers(true, getMemoryManager());
  const_cast<StaticType&>(var_->getStaticType()) = StaticType::DECIMAL;
  members->put(var_->getURIName(), var_);

  TupleMembers *pMembers = const_cast<TupleMembers*>(pItemType->getTupleMembers());
  if(pMembers) members->putAll(*pMembers);

  ItemType *type = new (getMemoryManager()) ItemType(members, pItemType->getDocumentCache());
  type->setLocationInfo(this);

  src_.getStaticType() = type;
  src_.getStaticType().setCardinality(pType.getMin(), pType.getMax());
  src_.add(parent_->getStaticAnalysis());

  return this;
}

class CountTupleResult : public TupleResult
{
public:
  CountTupleResult(const CountTuple *ast, const TupleResult::Ptr &parent)
    : TupleResult(ast),
      ast_(ast),
      parent_(parent),
      position_(0)      
  {
  }

  virtual Result getVar(const XMLCh *namespaceURI, const XMLCh *name) const
  {
    if(XPath2Utils::equals(name, ast_->getVarName()) && XPath2Utils::equals(namespaceURI, ast_->getVarURI()))
      return posItem_;

    return parent_->getVar(namespaceURI, name);
  }

  virtual void getInScopeVariables(std::vector<std::pair<const XMLCh*, const XMLCh*> > &variables) const
  {
    variables.push_back(std::pair<const XMLCh*, const XMLCh*>(ast_->getVarURI(), ast_->getVarName()));

    parent_->getInScopeVariables(variables);
  }

  virtual bool next(DynamicContext *context)
  {
    context->testInterrupt();

    if(!parent_->next(context))
      return false;

    posItem_ = context->getItemFactory()->createInteger(++position_, context);
    return true;
  }

  virtual void createTuple(DynamicContext *context, size_t capacity, TupleImpl::Ptr &result) const
  {
    parent_->createTuple(context, capacity + 1, result);
    result->add(ast_->getVar()->getURI(), ast_->getVar()->getName(), posItem_, context);
  }

private:
  const CountTuple *ast_;
  TupleResult::Ptr parent_;
  Item::Ptr posItem_;
  int position_;
};

TupleResult::Ptr CountTuple::createResult(DynamicContext* context) const
{
  return new CountTupleResult(this, parent_->createResult(context));
}

