/*
 * Copyright (c) 2010,
 *     John Snelson. All rights reserved.
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

#include <sstream>

#include "../config/xqilla_config.h"
#include <xqilla/ast/XQTupleMember.hpp>
#include <xqilla/items/Tuple.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/exceptions/TypeErrorException.hpp>
#include <xqilla/exceptions/DynamicErrorException.hpp>
#include <xqilla/ast/XQContextItem.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

XERCES_CPP_NAMESPACE_USE;

XQTupleMember::XQTupleMember(const XMLCh *qname, XPath2MemoryManager *mm)
  : ASTNodeImpl(TUPLE_MEMBER, mm),
    qname_(qname),
    uri_(0),
    name_(0)
{
}

XQTupleMember::XQTupleMember(const XMLCh *qname, const XMLCh *uri, const XMLCh *name, XPath2MemoryManager *mm)
  : ASTNodeImpl(TUPLE_MEMBER, mm),
    qname_(qname),
    uri_(uri),
    name_(name)
{
}

ASTNode* XQTupleMember::staticResolution(StaticContext *context)
{
  if(name_ == 0) {
    uri_ = context->getUriBoundToPrefix(XPath2NSUtils::getPrefix(qname_, context->getMemoryManager()), this);
    name_ = XPath2NSUtils::getLocalName(qname_);
  }
  return this;
}

ASTNode *XQTupleMember::staticTypingImpl(StaticContext *context)
{
  if(context == 0) return this;

  _src.clear();

  if(!context->getContextItemType().containsType(TypeFlags::ITEM)) {
    XQThrow(DynamicErrorException,X("XQTupleMember::staticTyping"),
            X("It is an error for the context item to be undefined when using it [err:XPDY0002]"));
  }

  _src.contextItemUsed(true);
  _src.getStaticType() = StaticType::EMPTY;

  const StaticType::ItemTypes &types = context->getContextItemType().getTypes();
  StaticType::ItemTypes::const_iterator i = types.begin();
  for(; i != types.end(); ++i) {
    if((*i)->getItemTestType() == ItemType::TEST_MAP) {
      if((*i)->getValueType()) {
        StaticType tmp((*i)->getValueType(), BasicMemoryManager::get());
        tmp.multiply(0,1);
        _src.getStaticType().typeUnion(tmp);
        continue;
      }
    } else if((*i)->getItemTestType() == ItemType::TEST_TUPLE) {
      const TupleMembers *members = (*i)->getTupleMembers();
      if(members) {
        XMLBuffer buf;
        XPath2NSUtils::makeURIName(uri_, name_, buf);
        ArgumentSpec* const *spec = members->get(buf.getRawBuffer());
        if(spec) {
          StaticType tmp((*spec)->getType(), BasicMemoryManager::get());
          _src.getStaticType().typeUnion(tmp);
          continue;
        }
      }
    } else continue;

    _src.getStaticType() = StaticType::ITEM_STAR;
    break;
  }

  return this;
}

class TupleMemberResult : public ResultImpl
{
public:
  TupleMemberResult(const Result &parent, const XQTupleMember *step)
    : ResultImpl(step),
      parent_(parent),
      step_(step),
      stepResult_(0)
  {
  }

  Item::Ptr next(DynamicContext *context)
  {
    Item::Ptr result;
    while((result = stepResult_->next(context)).isNull()) {
      context->testInterrupt();

      Item::Ptr item = parent_->next(context);

      if(item.isNull()) {
        return 0;
      }
      if(item->getType() != Item::TUPLE) {
        XQThrow(TypeErrorException,X("TupleMemberResult::next"),
                X("Context item is not a tuple while executing a tuple member expression [err:TBD]"));
      }

      stepResult_ = 0;
      ((Tuple*)item.get())->get(step_->getURI(), step_->getName(), context, stepResult_);
    }

    return result;
  }

protected:
  Result parent_;
  const XQTupleMember *step_;
  Result stepResult_;
};

Result XQTupleMember::createResult(DynamicContext *context, int flags) const 
{
  return new TupleMemberResult(XQContextItem::result(context, this), this);
}

Result XQTupleMember::iterateResult(const Result &contextItems, DynamicContext* context) const
{
  return new TupleMemberResult(contextItems, this);
}

