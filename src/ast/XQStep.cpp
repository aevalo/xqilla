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

#include <sstream>

#include "../config/xqilla_config.h"
#include <xqilla/ast/XQStep.hpp>
#include <xqilla/axis/NodeTest.hpp>
#include <xqilla/items/Item.hpp>
#include <xqilla/items/ATDecimalOrDerived.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/DatatypeFactory.hpp>
#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/exceptions/TypeErrorException.hpp>
#include <xqilla/exceptions/DynamicErrorException.hpp>
#include <xqilla/ast/XQDocumentOrder.hpp>
#include <xqilla/ast/XQContextItem.hpp>

XQStep::XQStep(Node::Axis axis, NodeTest* nodeTest, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(STEP, memMgr),
    nodeTest_(nodeTest),
    axis_(axis)
{
}

XQStep::~XQStep()
{
}

unsigned int XQStep::getAxisProperties(Node::Axis axis)
{
  unsigned int properties = 0;
  // properties depend on the axis of the step
  switch (axis) {
  case Node::SELF:
    properties |= StaticAnalysis::ONENODE | StaticAnalysis::SELF;
    // Fall through
  case Node::CHILD:
  case Node::ATTRIBUTE:
  case Node::NAMESPACE:
    properties |= StaticAnalysis::SUBTREE | StaticAnalysis::PEER;
    break;
  case Node::DESCENDANT:
  case Node::DESCENDANT_OR_SELF:
    properties |= StaticAnalysis::SUBTREE;
    break;
  case Node::FOLLOWING_SIBLING:
  case Node::PRECEDING_SIBLING:
    properties |= StaticAnalysis::PEER;
    break;
  case Node::PARENT:
    properties |= StaticAnalysis::PEER | StaticAnalysis::ONENODE;
    break;
  default:
    break;
  }
  properties |= StaticAnalysis::GROUPED | StaticAnalysis::SAMEDOC;

  if(isForwardAxis(axis) || axis == Node::PARENT) {
    properties |= StaticAnalysis::DOCORDER;
  }

  return properties;
}

ASTNode* XQStep::staticResolution(StaticContext *context)
{
  nodeTest_->staticResolution(context, this);
  return this;
}

ASTNode *XQStep::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  if(context && !context->getContextItemType().containsType(TypeFlags::ITEM)) {
    XQThrow(DynamicErrorException,X("XQStep::staticTyping"),
            X("It is an error for the context item to be undefined when using it [err:XPDY0002]"));
  }

  _src.setProperties(getAxisProperties(axis_));
  _src.contextItemUsed(true);

  bool isExact;
  nodeTest_->getStaticType(_src.getStaticType(), context, isExact, this);
  _src.getStaticType().multiply(0, StaticType::UNLIMITED);

  switch(axis_) {
  case Node::SELF:
    if(context) {
      _src.getStaticType().typeIntersect(context->getContextItemType());
      _src.getStaticType().setCardinality(context->getContextItemType().getMin(), context->getContextItemType().getMax());
    }
    else {
      _src.getStaticType().setCardinality(0, 1);
    }
    break;
  case Node::ATTRIBUTE:
    _src.getStaticType().typeIntersect(TypeFlags::ATTRIBUTE);
    break;
  case Node::NAMESPACE:
    _src.getStaticType().typeIntersect(TypeFlags::NAMESPACE);
    break;
  case Node::CHILD:
  case Node::DESCENDANT:
  case Node::FOLLOWING:
  case Node::FOLLOWING_SIBLING:
  case Node::PRECEDING:
  case Node::PRECEDING_SIBLING:
    _src.getStaticType().typeIntersect(TypeFlags::ELEMENT | TypeFlags::TEXT | TypeFlags::PI |
                                       TypeFlags::COMMENT);
    break;
  case Node::ANCESTOR:
  case Node::PARENT:
    _src.getStaticType().typeIntersect(TypeFlags::DOCUMENT | TypeFlags::ELEMENT);
    break;
  case Node::DESCENDANT_OR_SELF:
  case Node::ANCESTOR_OR_SELF:
    // Could be any type
    break;
  }

  return this;
}

bool XQStep::isForwardAxis(Node::Axis axis)
{
  switch(axis) {
  case Node::ANCESTOR:
  case Node::ANCESTOR_OR_SELF:
  case Node::PARENT:
  case Node::PRECEDING:
  case Node::PRECEDING_SIBLING:
    return false;

  case Node::ATTRIBUTE:
  case Node::CHILD:
  case Node::DESCENDANT:
  case Node::DESCENDANT_OR_SELF:
  case Node::FOLLOWING:
  case Node::FOLLOWING_SIBLING:
  case Node::NAMESPACE:
  case Node::SELF:
    return true;
  }
  return false;
}

NodeTest *XQStep::getNodeTest() const {
  return nodeTest_;
}

void XQStep::setNodeTest(NodeTest *nt) {
  nodeTest_ = nt;
}

Node::Axis XQStep::getAxis() const {
  return axis_;
}

void XQStep::setAxis(Node::Axis a) {
  axis_ = a;
}

class StepResult : public ResultImpl
{
public:
  StepResult(const Result &parent, const XQStep *step)
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
      if(item->getType() != Item::NODE) {
        XQThrow(TypeErrorException,X("StepResult::next"), X("An attempt was made to perform an axis step when the Context Item was not a node [err:XPTY0020]"));
      }

      stepResult_ = ((Node*)item.get())->getAxisResult(step_->getAxis(), step_->getNodeTest(), context, this);
    }

    return result;
  }

protected:
  Result parent_;
  const XQStep *step_;
  Result stepResult_;
};

Result XQStep::createResult(DynamicContext* context, int flags) const 
{
  return new StepResult(XQContextItem::result(context, this), this);
}

Result XQStep::iterateResult(const Result &contextItems, DynamicContext* context) const
{
  return new StepResult(contextItems, this);
}

