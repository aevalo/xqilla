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

#include <xqilla/ast/ForTuple.hpp>
#include <xqilla/ast/ASTNode.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/VariableTypeStore.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/utils/XStr.hpp>

#include <xercesc/framework/XMLBuffer.hpp>

XERCES_CPP_NAMESPACE_USE;

ForTuple::ForTuple(TupleNode *parent, const XMLCh *varQName, const XMLCh *posQName,
                   ASTNode *expr, XPath2MemoryManager *mm)
  : TupleNode(FOR, parent, mm),
    var_(varQName ? new (mm) ArgumentSpec(varQName, 0, mm) : 0),
    pos_(posQName ? new (mm) ArgumentSpec(posQName, 0, mm) : 0),
    expr_(expr)
{
}

ForTuple::ForTuple(TupleNode *parent, const ArgumentSpec *var, const ArgumentSpec *pos,
                   ASTNode *expr, XPath2MemoryManager *mm)
  : TupleNode(FOR, parent, mm),
    var_(var ? new (mm) ArgumentSpec(var, mm) : 0),
    pos_(pos ? new (mm) ArgumentSpec(pos, mm) : 0),
    expr_(expr)
{
}

TupleNode *ForTuple::staticResolution(StaticContext *context)
{
  parent_ = parent_->staticResolution(context);

  if(var_) var_->staticResolution(context);
  if(pos_) pos_->staticResolution(context);

  if(var_ && pos_ && XPath2Utils::equals(pos_->getName(), var_->getName()) &&
     XPath2Utils::equals(pos_->getURI(), var_->getURI())) {
    XMLBuffer errMsg;
    errMsg.set(X("The positional variable with name {"));
    errMsg.append(pos_->getURI());
    errMsg.append(X("}"));
    errMsg.append(pos_->getName());
    errMsg.append(X(" conflicts with the iteration variable [err:XQST0089]"));
    XQThrow(StaticErrorException,X("ForTuple::staticResolution"), errMsg.getRawBuffer());
  }

  expr_ = expr_->staticResolution(context);

  return this;
}

TupleNode *ForTuple::staticTypingImpl(StaticContext *context)
{
  if(expr_->getStaticAnalysis().isUpdating()) {
    XQThrow(StaticErrorException,X("ForTuple::staticTypingSetup"),
            X("It is a static error for the for expression of a FLWOR expression "
              "to be an updating expression [err:XUST0001]"));
  }

  const StaticType &pType = parent_->getStaticAnalysis().getStaticType();
  const StaticType &sType = expr_->getStaticAnalysis().getStaticType();

  assert(pType.getTypes().size() == 1);
  const ItemType *pItemType = pType.getTypes()[0];
  assert(pItemType->getItemTestType() == ItemType::TEST_TUPLE);

  src_.clear();
  src_.add(expr_->getStaticAnalysis());

  TupleMembers *members = new (getMemoryManager()) TupleMembers(true, getMemoryManager());
  if(var_) {
    const_cast<StaticType&>(var_->getStaticType()) = sType;
    const_cast<StaticType&>(var_->getStaticType()).setCardinality(1,1);
    members->put(var_->getURIName(), var_);
  }
  if(pos_) {
    const_cast<StaticType&>(pos_->getStaticType()) = StaticType::DECIMAL;
    members->put(pos_->getURIName(), pos_);
  }

  TupleMembers *pMembers = const_cast<TupleMembers*>(pItemType->getTupleMembers());
  if(pMembers) {
    members->putAll(*pMembers);

    TupleMembers::iterator i = pMembers->begin();
    for(; i != pMembers->end(); ++i) {
      src_.removeVariable(i.getValue()->getURI(), i.getValue()->getName());
    }
  }

  ItemType *type = new (getMemoryManager()) ItemType(members, pItemType->getDocumentCache());
  type->setLocationInfo(this);

  src_.getStaticType() = type;
  unsigned min = pType.getMin() * sType.getMin();
  unsigned max;
  if(pType.getMax() == StaticType::UNLIMITED || sType.getMax() == StaticType::UNLIMITED)
    max = StaticType::UNLIMITED;
  else max = pType.getMax() * sType.getMax();
  // Setting max to 0 causes the ItemType to be removed and made into the empty sequence
  if(max == 0) max = 1;
  src_.getStaticType().setCardinality(min, max);

  src_.add(parent_->getStaticAnalysis());

  return this;
}

class ForTupleResult : public TupleResult
{
public:
  ForTupleResult(const ForTuple *ast, const TupleResult::Ptr &parent)
    : TupleResult(ast),
      ast_(ast),
      parent_(parent),
      values_(0),
      position_(0)
  {
  }

  virtual Result getVar(const XMLCh *namespaceURI, const XMLCh *name) const
  {
    if(XPath2Utils::equals(name, ast_->getVarName()) && XPath2Utils::equals(namespaceURI, ast_->getVarURI()))
      return item_;

    if(XPath2Utils::equals(name, ast_->getPosName()) && XPath2Utils::equals(namespaceURI, ast_->getPosURI()))
      return posItem_;

    return parent_->getVar(namespaceURI, name);
  }

  virtual void getInScopeVariables(std::vector<std::pair<const XMLCh*, const XMLCh*> > &variables) const
  {
    variables.push_back(std::pair<const XMLCh*, const XMLCh*>(ast_->getVarURI(), ast_->getVarName()));
    if(ast_->getPosName())
      variables.push_back(std::pair<const XMLCh*, const XMLCh*>(ast_->getPosURI(), ast_->getPosName()));

    parent_->getInScopeVariables(variables);
  }

  virtual bool next(DynamicContext *context)
  {
    AutoVariableStoreReset reset(context, parent_);
    while((item_ = values_->next(context)).isNull()) {
      context->testInterrupt();

      reset.reset();
      if(!parent_->next(context)) return false;

      context->setVariableStore(parent_);
      values_ = ast_->getExpression()->createResult(context);
      position_ = 0;
    }

    if(ast_->getPosName())
      posItem_ = context->getItemFactory()->createInteger(++position_, context);
    return true;
  }

  virtual void createTuple(DynamicContext *context, size_t capacity, TupleImpl::Ptr &result) const
  {
    parent_->createTuple(context, capacity + (ast_->getPosName() ? 2 : 1), result);
    result->add(ast_->getVarURI(), ast_->getVarName(), item_, context);
    if(ast_->getPosName())
      result->add(ast_->getPosURI(), ast_->getPosName(), posItem_, context);
  }

private:
  const ForTuple *ast_;
  TupleResult::Ptr parent_;
  Result values_;
  Item::Ptr item_;
  Item::Ptr posItem_;
  int position_;
};

TupleResult::Ptr ForTuple::createResult(DynamicContext* context) const
{
  return new ForTupleResult(this, parent_->createResult(context));
}

