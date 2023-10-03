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

#include <xqilla/ast/ConvertFunctionArg.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/exceptions/XPath2TypeCastException.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/context/ItemFactory.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

#if defined(XERCES_HAS_CPP_NAMESPACE)
XERCES_CPP_NAMESPACE_USE
#endif

XQPromoteUntyped::XQPromoteUntyped(ASTNode* expr, const ItemType *type, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(PROMOTE_UNTYPED, memMgr),
    expr_(expr),
    type_(type)
{
}

ASTNode* XQPromoteUntyped::staticResolution(StaticContext *context)
{
  expr_ = expr_->staticResolution(context);

  // crioux thinks this should also add: unless the target type is anyAtomicType!
  if(type_->getTypeName() == 0) {
    return substitute(expr_);
  }

  return this;
}

ASTNode *XQPromoteUntyped::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.getStaticType() = expr_->getStaticAnalysis().getStaticType();
  _src.add(expr_->getStaticAnalysis());

  if(!_src.getStaticType().containsType(TypeFlags::UNTYPED_ATOMIC)) {
    return substitute(expr_);
  }

  _src.getStaticType().substitute(TypeFlags::UNTYPED_ATOMIC, type_);

  return this;
}

Result XQPromoteUntyped::createResult(DynamicContext* context, int flags) const
{
  return new PromoteUntypedResult(this, expr_->createResult(context, flags));
}

PromoteUntypedResult::PromoteUntypedResult(const XQPromoteUntyped *di, const Result &parent)
  : ResultImpl(di),
    parent_(parent),
    isPrimitive_(di->getItemType()->isPrimitive()),
    typeIndex_(di->getItemType()->getPrimitiveType()),
    uri_(di->getItemType()->getTypeURI()),
    name_(di->getItemType()->getTypeName())
{
}

PromoteUntypedResult::PromoteUntypedResult(const LocationInfo *location, const Result &parent,
                                           bool isPrimitive, AnyAtomicType::AtomicObjectType typeIndex,
                                           const XMLCh *uri, const XMLCh *name)
  : ResultImpl(location),
    parent_(parent),
    isPrimitive_(isPrimitive),
    typeIndex_(typeIndex),
    uri_(uri),
    name_(name)
{
}

Item::Ptr PromoteUntypedResult::next(DynamicContext *context)
{
  Item::Ptr item = parent_->next(context);
  if(item.notNull()) {
    assert(item->getType() == Item::ATOMIC);
    const AnyAtomicType *atomic = (const AnyAtomicType *)item.get();

    // 2. Each item in the atomic sequence that is of type xdt:untypedAtomic is cast to the expected atomic
    //    type. For built-in functions where the expected type is specified as numeric, arguments of type
    //    xdt:untypedAtomic are cast to xs:double.
    if(atomic->getPrimitiveTypeIndex() == AnyAtomicType::UNTYPED_ATOMIC) {
      try {
        if(isPrimitive_) {
          item = atomic->castAs(typeIndex_, 0, 0, context);
        }
        else {
          item = atomic->castAs(typeIndex_, uri_, name_, context);
        }
      }
      catch(XPath2TypeCastException &e) {
        if(e.getXQueryLine() == 0)
          e.setXQueryPosition(this);
        throw;
      }
    }
  }
  else {
    parent_ = 0;
  }

  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

XQPromoteNumeric::XQPromoteNumeric(ASTNode* expr, const ItemType *type, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(PROMOTE_NUMERIC, memMgr),
    expr_(expr),
    type_(type)
{
}

ASTNode* XQPromoteNumeric::staticResolution(StaticContext *context)
{
  expr_ = expr_->staticResolution(context);

  if(!((XPath2Utils::equals(type_->getTypeName(), SchemaSymbols::fgDT_DOUBLE) ||
        XPath2Utils::equals(type_->getTypeName(), SchemaSymbols::fgDT_FLOAT)) &&
       XPath2Utils::equals(type_->getTypeURI(), SchemaSymbols::fgURI_SCHEMAFORSCHEMA))) {
    return substitute(expr_);
  }

  return this;
}

ASTNode *XQPromoteNumeric::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.getStaticType() = expr_->getStaticAnalysis().getStaticType();
  _src.add(expr_->getStaticAnalysis());

  if(type_->getPrimitiveType() == AnyAtomicType::DOUBLE) {
    if(!_src.getStaticType().containsType(TypeFlags::DECIMAL | TypeFlags::FLOAT))
      return substitute(expr_);
    _src.getStaticType().substitute(TypeFlags::DECIMAL | TypeFlags::FLOAT, StaticType::DOUBLE);
  }
  else if(type_->getPrimitiveType() == AnyAtomicType::FLOAT) {
    if(!_src.getStaticType().containsType(TypeFlags::DECIMAL))
      return substitute(expr_);
    _src.getStaticType().substitute(TypeFlags::DECIMAL | TypeFlags::FLOAT, StaticType::FLOAT);
  }
  else {
    return substitute(expr_);
  }

  return this;
}

Result XQPromoteNumeric::createResult(DynamicContext* context, int flags) const
{
  return new PromoteNumericResult(this, expr_->createResult(context, flags), type_->getPrimitiveType());
}

Item::Ptr PromoteNumericResult::next(DynamicContext *context)
{
  Item::Ptr item = parent_->next(context);
  if(item.notNull()) {
    assert(item->getType() == Item::ATOMIC);
    const AnyAtomicType *atomic = (const AnyAtomicType *)item.get();

    // 3. For each numeric item in the atomic sequence that can be promoted to the expected atomic type using
    //    the promotion rules in B.1 Type Promotion, the promotion is done.
    if(atomic->isNumericValue()) {
      try {
        const Numeric::Ptr promotedType = ((const Numeric*)atomic)->
          promoteTypeIfApplicable(typeIndex_, context);
        if(promotedType.notNull()) {
          item = promotedType;
        }
      } catch (XPath2TypeCastException &e) {
        XQThrow(XPath2ErrorException, X("SequenceType::AtomicTypeConvertFunctionArgResult::next"),
                 X("Numeric type promotion failed (for promotable type)"));
      } catch (const XMLException& e) {
        XQThrow(XPath2ErrorException, X("SequenceType::AtomicTypeConvertFunctionArgResult::next"),
                 X("Numeric type promotion failed (for promotable type)"));
      }
    }
  }
  else {
    parent_ = 0;
  }

  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

XQPromoteAnyURI::XQPromoteAnyURI(ASTNode* expr, const ItemType *type, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(PROMOTE_ANY_URI, memMgr),
    expr_(expr),
    type_(type)
{
}

ASTNode* XQPromoteAnyURI::staticResolution(StaticContext *context)
{
  expr_ = expr_->staticResolution(context);

  if(!XPath2Utils::equals(type_->getTypeName(), SchemaSymbols::fgDT_STRING) ||
     !XPath2Utils::equals(type_->getTypeURI(), SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
    return substitute(expr_);
  }

  return this;
}

ASTNode *XQPromoteAnyURI::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.getStaticType() = expr_->getStaticAnalysis().getStaticType();
  _src.add(expr_->getStaticAnalysis());

  if(!_src.getStaticType().containsType(TypeFlags::ANY_URI)) {
    return substitute(expr_);
  }

  _src.getStaticType().substitute(TypeFlags::ANY_URI, StaticType::STRING);

  return this;
}

Result XQPromoteAnyURI::createResult(DynamicContext* context, int flags) const
{
  return new PromoteAnyURIResult(this, expr_->createResult(context, flags));
}

Item::Ptr PromoteAnyURIResult::next(DynamicContext *context)
{
  Item::Ptr item = parent_->next(context);
  if(item.notNull()) {
    assert(item->getType() == Item::ATOMIC);
    const AnyAtomicType *atomic = (const AnyAtomicType *)item.get();

    // 4. For each item of type xs:anyURI in the atomic sequence that can be promoted to the expected atomic
    //    type using URI promotion as described in B.1 Type Promotion, the promotion is done.
    if(atomic->getPrimitiveTypeIndex() == AnyAtomicType::ANY_URI) {
      try {
        item = atomic->castAs(AnyAtomicType::STRING, context);
      } catch (XPath2TypeCastException &e) {
        XQThrow(XPath2ErrorException, X("SequenceType::AtomicTypeConvertFunctionArgResult::next"),
                 X("AnyURI type promotion failed (for promotable type)"));
      } catch (const XMLException& e) {
        XQThrow(XPath2ErrorException, X("SequenceType::AtomicTypeConvertFunctionArgResult::next"),
                 X("AnyURI type promotion failed (for promotable type)"));
      }
    }
  }
  else {
    parent_ = 0;
  }

  return item;
}
