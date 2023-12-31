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

#include "../config/xqilla_config.h"

#include <xqilla/ast/XQAtomize.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/items/Node.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/runtime/Sequence.hpp>

XERCES_CPP_NAMESPACE_USE

XQAtomize::XQAtomize(ASTNode* expr, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(ATOMIZE, memMgr),
    expr_(expr),
    doPSVI_(true)
{
}

XQAtomize::XQAtomize(ASTNode* expr, bool doPSVI, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(ATOMIZE, memMgr),
    expr_(expr),
    doPSVI_(doPSVI)
{
}

ASTNode* XQAtomize::staticResolution(StaticContext *context)
{
  expr_ = expr_->staticResolution(context);
  doPSVI_ = context->getDocumentCache()->getDoPSVI();
  return this;
}

ASTNode *XQAtomize::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.getStaticType() = expr_->getStaticAnalysis().getStaticType();
  _src.add(expr_->getStaticAnalysis());

  if(expr_->getStaticAnalysis().isUpdating()) {
    XQThrow(StaticErrorException,X("XQAtomize::staticTyping"),
            X("It is a static error for an atomized expression "
              "to be an updating expression [err:XUST0001]"));
  }

  if(!_src.getStaticType().containsType(TypeFlags::NODE|TypeFlags::ANY_ATOMIC_TYPE) &&
     _src.getStaticType().getMin() > 0) {
    XMLBuffer buf;
    buf.set(X("Sequence does not match type (xs:anyAtomicType | node())*"));
    buf.append(X(" - the expression has a static type of "));
    _src.getStaticType().typeToBuf(buf);
    buf.append(X(" [err:XPTY0004]"));
    XQThrow(XPath2TypeMatchException, X("XQAtomize::staticTyping"), buf.getRawBuffer());
  }

  if(!_src.getStaticType().containsType(TypeFlags::NODE|TypeFlags::FUNCTION)) {
    // If the expression has no nodes, this function does nothing
    return substitute(expr_);
  }

  // Remove types other than node and atomic
  _src.getStaticType().typeIntersect(TypeFlags::NODE | TypeFlags::ANY_ATOMIC_TYPE);

  if(doPSVI_) {
    if(_src.getStaticType().substitute(TypeFlags::ELEMENT | TypeFlags::ATTRIBUTE,
                                       StaticType::ANY_ATOMIC_TYPE))
      _src.getStaticType().setCardinality(0, StaticType::UNLIMITED);
  } else {
    _src.getStaticType().substitute(TypeFlags::ELEMENT | TypeFlags::ATTRIBUTE,
                                    StaticType::UNTYPED_ATOMIC);
  }

  _src.getStaticType().substitute(TypeFlags::DOCUMENT | TypeFlags::TEXT,
                                  StaticType::UNTYPED_ATOMIC);
  _src.getStaticType().substitute(TypeFlags::NAMESPACE | TypeFlags::COMMENT |
                                  TypeFlags::PI, StaticType::STRING);

  return this;
}

Result XQAtomize::createResult(DynamicContext* context, int flags) const
{
  return new AtomizeResult(this, expr_->createResult(context, flags));
}

Item::Ptr AtomizeResult::next(DynamicContext *context)
{
  // for $item in (Expr) return
  //   typeswitch ($item)
  //     case $value as atomic value return $value
  //     default $node return fn:data($node)

  Item::Ptr result = _sub->next(context);
  while(result.isNull()) {
    _sub = 0;
    result = _parent->next(context);
    if(result.isNull()) {
      _parent = 0;
      return 0;
    }
    if(result->getType() == Item::NODE) {
      _sub = ((Node*)result.get())->dmTypedValue(context);
      result = _sub->next(context);
    }
    else if(result->getType() != Item::ATOMIC) {
      XMLBuffer buf;
      buf.set(X("Sequence does not match type (xs:anyAtomicType | node())*"));
      buf.append(X(" - found item of type "));
      result->typeToBuffer(context, buf);
      buf.append(X(" [err:XPTY0004]"));
      XQThrow(XPath2TypeMatchException, X("AtomizeResult::next"), buf.getRawBuffer());
    }
  }
  return result;
}

