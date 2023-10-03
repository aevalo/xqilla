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
#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/XQLiteral.hpp>
#include <xqilla/ast/XQSequence.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/Item.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/events/EventHandler.hpp>
#include <xqilla/items/impl/ATQNameOrDerivedImpl.hpp>
#include <xqilla/items/impl/ATDecimalOrDerivedImpl.hpp>
#include <xqilla/items/impl/ATDoubleOrDerivedImpl.hpp>
#include <xqilla/items/impl/ATFloatOrDerivedImpl.hpp>
#include <xqilla/exceptions/IllegalArgumentException.hpp>
#include <xqilla/utils/XPath2Utils.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

XERCES_CPP_NAMESPACE_USE;

ASTNode *XQLiteral::create(const Item::Ptr &item, DynamicContext *context, XPath2MemoryManager* mm,
                           const LocationInfo *location)
{
  if(item->getType() == Item::ATOMIC) {
    const AnyAtomicType *atom = (const AnyAtomicType*)item.get();

    const XMLCh *puri, *pname;
    context->getItemFactory()->getPrimitiveTypeName(atom->getPrimitiveTypeIndex(), puri, pname);
    bool isPrimitive = XPath2Utils::equals(atom->getTypeName(), pname) && XPath2Utils::equals(atom->getTypeURI(), puri);

    ItemType *type = new (mm) ItemType(atom->getPrimitiveTypeIndex(), isPrimitive, atom->getTypeURI(), atom->getTypeName(), 0);
    ASTNode *result = 0;

    switch(atom->getPrimitiveTypeIndex()) {
    case AnyAtomicType::QNAME: {
      const ATQNameOrDerived *qname = (const ATQNameOrDerived*)atom;
      result = new (mm) XQQNameLiteral(type, qname->getURI(), qname->getPrefix(),
                                       qname->getName(), mm);
      break;
    }
    case AnyAtomicType::DECIMAL:
    case AnyAtomicType::DOUBLE:
    case AnyAtomicType::FLOAT: {
      const Numeric *number = (const Numeric*)atom;
      if(number->getState() == Numeric::NUM || (number->getState() == Numeric::NEG_NUM && !number->isZero())) {
        result = new (mm) XQNumericLiteral(type, number->asMAPM(), mm);
        break;
      }
      // Fall through
    }
    default:
      result = new (mm) XQLiteral(type, atom->asString(context), mm);
      break;
    }

    result->setLocationInfo(location);
    return result;
  }
  else {
    XQThrow2(::IllegalArgumentException, X("XQLiteral::create"), X("Cannot create an ASTNode literal for a non atomic item"));
  }
}

ASTNode *XQLiteral::create(bool value, XPath2MemoryManager* mm, const LocationInfo *location)
{
  ASTNode *result = new (mm) XQLiteral((ItemType*)&ItemType::BOOLEAN, value ? SchemaSymbols::fgATTVAL_TRUE : SchemaSymbols::fgATTVAL_FALSE, mm);
  result->setLocationInfo(location);
  return result;
}

XQLiteral::XQLiteral(ItemType *type, const XMLCh* value,
                     XPath2MemoryManager* memMgr)
  : ASTNodeImpl(LITERAL, memMgr),
    type_(type),
    value_(value)
{
  _src.getStaticType() = type_;
}

bool XQLiteral::isDateOrTimeAndHasNoTimezone(StaticContext *context) const
{
  switch(type_->getPrimitiveType()) {
  case AnyAtomicType::DATE:
  case AnyAtomicType::DATE_TIME:
  case AnyAtomicType::TIME:
  case AnyAtomicType::G_DAY:
  case AnyAtomicType::G_MONTH:
  case AnyAtomicType::G_MONTH_DAY:
  case AnyAtomicType::G_YEAR:
  case AnyAtomicType::G_YEAR_MONTH: {
    if(context == 0) return true;
    AutoDelete<DynamicContext> dContext(context->createDynamicContext());
    dContext->setMemoryManager(context->getMemoryManager());
    Item::Ptr item = dContext->getItemFactory()->createDerivedFromAtomicType(type_->getPrimitiveType(), type_->getTypeURI(), type_->getTypeName(), value_, dContext);
    return !((const DateOrTimeType*)item.get())->hasTimezone();
  }
  default: break;
  }

  return false;
}

ASTNode* XQLiteral::staticResolution(StaticContext *context)
{
  type_->staticResolution(context, this);

  switch(type_->getPrimitiveType()) {
  case AnyAtomicType::DECIMAL:
  case AnyAtomicType::FLOAT:
  case AnyAtomicType::DOUBLE: {
    // Pre-parse numeric literals
    XPath2MemoryManager* mm = context->getMemoryManager();
    AutoDelete<DynamicContext> dContext(context->createDynamicContext());
    dContext->setMemoryManager(mm);

    Numeric::Ptr number = (Numeric*)createResult(dContext)->next(dContext).get();
    if(number->getState() == Numeric::NUM || (number->getState() == Numeric::NEG_NUM && !number->isZero())) {
      ASTNode *result = new (mm) XQNumericLiteral(type_, number->asMAPM(), mm);
      this->release();
      return result->staticResolution(context);;
    }
    break;
  }
  default: break;
  }

  return this;
}

ASTNode *XQLiteral::staticTypingImpl(StaticContext *context)
{
  return this;
}

BoolResult XQLiteral::boolResult(DynamicContext* context) const
{
  assert(type_->getPrimitiveType() == AnyAtomicType::BOOLEAN);
  return XPath2Utils::equals(SchemaSymbols::fgATTVAL_TRUE, value_);
}

Result XQLiteral::createResult(DynamicContext* context, int flags) const
{
  if(type_->isPrimitive()) {
    return (Item::Ptr)context->getItemFactory()->
      createDerivedFromAtomicType(type_->getPrimitiveType(), value_, context).get();
  }
  else {
    return (Item::Ptr)context->getItemFactory()->
      createDerivedFromAtomicType(type_->getPrimitiveType(), type_->getTypeURI(), type_->getTypeName(), value_, context).get();
  }
}

EventGenerator::Ptr XQLiteral::generateEvents(EventHandler *events, DynamicContext *context,
                                              bool preserveNS, bool preserveType) const
{
  events->atomicItemEvent(type_->getPrimitiveType(), value_, type_->getTypeURI(), type_->getTypeName());
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

XQQNameLiteral::XQQNameLiteral(ItemType *type, const XMLCh* uri,
                               const XMLCh* prefix, const XMLCh* localname, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(QNAME_LITERAL, memMgr),
    type_(type),
    uri_(uri),
    prefix_(prefix),
    localname_(localname)
{
  _src.getStaticType() = type_;
}

bool XQQNameLiteral::isDateOrTimeAndHasNoTimezone(StaticContext *context) const
{
  return false;
}

ASTNode* XQQNameLiteral::staticResolution(StaticContext *context)
{
  type_->staticResolution(context, this);
  return this;
}

ASTNode *XQQNameLiteral::staticTypingImpl(StaticContext *context)
{
  return this;
}

Result XQQNameLiteral::createResult(DynamicContext* context, int flags) const
{
  return Item::Ptr(new ATQNameOrDerivedImpl(type_->getTypeURI(), type_->getTypeName(), uri_, prefix_, localname_, context));
}

EventGenerator::Ptr XQQNameLiteral::generateEvents(EventHandler *events, DynamicContext *context,
                                                   bool preserveNS, bool preserveType) const
{
  XMLBuffer buf;
  if(prefix_ && *prefix_) {
    buf.append(prefix_);
    buf.append(':');
  }
  buf.append(localname_);
  events->atomicItemEvent(AnyAtomicType::QNAME, buf.getRawBuffer(), type_->getTypeURI(), type_->getTypeName());
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

XQNumericLiteral::XQNumericLiteral(ItemType *type, const MAPM &value, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(NUMERIC_LITERAL, memMgr),
    type_(type)
{
  _src.getStaticType() = type_;

  memset(&value_, 0, sizeof(value_));

  const M_APM cval = value.c_struct();

  value_.m_apm_datalength = cval->m_apm_datalength;
  value_.m_apm_exponent = cval->m_apm_exponent;
  value_.m_apm_sign = cval->m_apm_sign;

  int len = (cval->m_apm_datalength + 1) >> 1;
  value_.m_apm_data = (UCHAR*)memMgr->allocate(len);

  memcpy(value_.m_apm_data, cval->m_apm_data, len);
}

bool XQNumericLiteral::isDateOrTimeAndHasNoTimezone(StaticContext *context) const
{
  return false;
}

ASTNode* XQNumericLiteral::staticResolution(StaticContext *context)
{
  type_->staticResolution(context, this);
  return this;
}

ASTNode *XQNumericLiteral::staticTypingImpl(StaticContext *context)
{
  return this;
}

MAPM XQNumericLiteral::getValue() const
{
  // Use the C API to copy our fake MAPM
  MAPM copy;
  m_apm_copy(const_cast<M_APM>(copy.c_struct()), const_cast<M_APM>(&value_));
  return copy;
}

Result XQNumericLiteral::createResult(DynamicContext* context, int flags) const
{
  switch(type_->getPrimitiveType()) {
  case AnyAtomicType::DECIMAL:
    return (Item::Ptr)new ATDecimalOrDerivedImpl(type_->getTypeURI(), type_->getTypeName(), getValue(), context);
  case AnyAtomicType::FLOAT:
    return (Item::Ptr)new ATFloatOrDerivedImpl(type_->getTypeURI(), type_->getTypeName(), getValue(), context);
  case AnyAtomicType::DOUBLE:
    return (Item::Ptr)new ATDoubleOrDerivedImpl(type_->getTypeURI(), type_->getTypeName(), getValue(), context);
  default: break;
  }
  return 0;
}

EventGenerator::Ptr XQNumericLiteral::generateEvents(EventHandler *events, DynamicContext *context,
                                              bool preserveNS, bool preserveType) const
{
  switch(type_->getPrimitiveType()) {
  case AnyAtomicType::DECIMAL:
    events->atomicItemEvent(type_->getPrimitiveType(), Numeric::asDecimalString(getValue(), ATDecimalOrDerivedImpl::g_nSignificantDigits,
                                                                                context), type_->getTypeURI(), type_->getTypeName());
    break;
  case AnyAtomicType::FLOAT:
    events->atomicItemEvent(type_->getPrimitiveType(), Numeric::asDoubleString(Numeric::NUM, getValue(),
                                                                               ATFloatOrDerivedImpl::g_nSignificantDigits, context),
                            type_->getTypeURI(), type_->getTypeName());
    break;
  case AnyAtomicType::DOUBLE:
    events->atomicItemEvent(type_->getPrimitiveType(), Numeric::asDoubleString(Numeric::NUM, getValue(),
                                                                               ATDoubleOrDerivedImpl::g_nSignificantDigits, context),
                            type_->getTypeURI(), type_->getTypeName());
    break;
  default: break;
  }
  return 0;
}

