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
#include <assert.h>
#include <xqilla/operators/Minus.hpp>
#include <xqilla/operators/Plus.hpp>
#include <xqilla/items/ATDurationOrDerived.hpp>
#include <xqilla/items/ATDateTimeOrDerived.hpp>
#include <xqilla/items/ATDateOrDerived.hpp>
#include <xqilla/items/ATTimeOrDerived.hpp>
#include <xqilla/items/Numeric.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

#include <xercesc/util/XMLUniDefs.hpp>

XERCES_CPP_NAMESPACE_USE;

const XMLCh Minus::name[]={ chLatin_M, chLatin_i, chLatin_n, chLatin_u, chLatin_s, chNull };

Minus::Minus(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : ArithmeticOperator(MINUS, name, args, memMgr)
{
}

void Minus::calculateStaticType(StaticContext *context)
{
  const StaticType &arg0 = _args[0]->getStaticAnalysis().getStaticType();
  const StaticType &arg1 = _args[1]->getStaticAnalysis().getStaticType();

  calculateStaticTypeForNumerics(arg0, arg1, context);

  // Subtracting a duration from a date, dateTime, time, or duration
  if(arg1.containsType(TypeFlags::DAY_TIME_DURATION)) {
    StaticType tmp(BasicMemoryManager::get()); tmp = arg0;
    tmp.typeIntersect(TypeFlags::DATE|TypeFlags::DATE_TIME|TypeFlags::TIME|
                      TypeFlags::DAY_TIME_DURATION);
    _src.getStaticType().typeUnion(tmp);
  }
  if(arg1.containsType(TypeFlags::YEAR_MONTH_DURATION)) {
    StaticType tmp(BasicMemoryManager::get()); tmp = arg0;
    tmp.typeIntersect(TypeFlags::DATE|TypeFlags::DATE_TIME|
                      TypeFlags::YEAR_MONTH_DURATION);
    _src.getStaticType().typeUnion(tmp);
  }

  // Subtracting date, dateTime and time
  if(arg0.containsType(TypeFlags::DATE) && arg1.containsType(TypeFlags::DATE)) {
    _src.getStaticType().typeUnion(StaticType::DAY_TIME_DURATION);
  }
  if(arg0.containsType(TypeFlags::DATE_TIME) && arg1.containsType(TypeFlags::DATE_TIME)) {
    _src.getStaticType().typeUnion(StaticType::DAY_TIME_DURATION);
  }
  if(arg0.containsType(TypeFlags::TIME) && arg1.containsType(TypeFlags::TIME)) {
    _src.getStaticType().typeUnion(StaticType::DAY_TIME_DURATION);
  }
}

Item::Ptr Minus::execute(const AnyAtomicType::Ptr &atom1, const AnyAtomicType::Ptr &atom2, DynamicContext *context) const
{
  if(atom1 == NULLRCP || atom2 == NULLRCP) return 0;

  if(atom1->isNumericValue()) {
    if(atom2->isNumericValue()) {
      return ((Numeric*)atom1.get())->subtract((const Numeric::Ptr )atom2, context);
    }
    else {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An attempt to subtract a non numeric type from a numeric type has occurred [err:XPTY0004]"));
    }
  }
  
  switch(atom1->getPrimitiveTypeIndex()) {
  case AnyAtomicType::DATE : {
    switch(atom2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DAY_TIME_DURATION: {
      return ((ATDateOrDerived*)atom1.get())->subtractDayTimeDuration((const ATDurationOrDerived *)atom2.get(), context);
    }
    case AnyAtomicType::YEAR_MONTH_DURATION: {
      return ((ATDateOrDerived*)atom1.get())->subtractYearMonthDuration((const ATDurationOrDerived *)atom2.get(), context);
    }
    case AnyAtomicType::DATE: {
      return ((ATDateOrDerived*)atom1.get())->subtractDate((const ATDateOrDerived *)atom2.get(), context);
    }
    default: {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An invalid attempt to subtract from xs:date type has occurred [err:XPTY0004]"));
    }
    }
  }
  case AnyAtomicType::TIME : {
    switch(atom2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DAY_TIME_DURATION : {
      return ((ATTimeOrDerived*)atom1.get())->subtractDayTimeDuration((const ATDurationOrDerived *)atom2.get(), context );
    }
    case AnyAtomicType::TIME : {
      return ((ATTimeOrDerived*)atom1.get())->subtractTime((const ATTimeOrDerived *)atom2.get(), context);
    }
    default: {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An invalid attempt to subtract from xs:time type has occurred [err:XPTY0004]"));
    }
    }
  }
  case AnyAtomicType::DATE_TIME : {
    switch(atom2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DAY_TIME_DURATION: {
      return ((ATDateTimeOrDerived*)atom1.get())->subtractDayTimeDuration((const ATDurationOrDerived*)atom2.get(), context);
    }
    case AnyAtomicType::YEAR_MONTH_DURATION: {
      return ((ATDateTimeOrDerived*)atom1.get())->subtractYearMonthDuration((const ATDurationOrDerived*)atom2.get(), context);
    }
    case AnyAtomicType::DATE_TIME : {
      return ((ATDateTimeOrDerived*)atom1.get())->subtractDateTimeAsDayTimeDuration((const ATDateTimeOrDerived::Ptr )atom2, context);
    }
    default: {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An invalid attempt to subtract from xs:dateTime type has occurred [err:XPTY0004]"));
    }
    }
  }
  case AnyAtomicType::DAY_TIME_DURATION: {
    switch(atom2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DAY_TIME_DURATION: {
      return ((ATDurationOrDerived*)atom1.get())->subtract((const ATDurationOrDerived *)atom2.get(), context);
    }
    default: {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An invalid attempt to subtract from xdt:dayTimeDuration type has occurred [err:XPTY0004]"));
    }
    }
  }
  case AnyAtomicType::YEAR_MONTH_DURATION: {
    switch(atom2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::YEAR_MONTH_DURATION: {
      return ((ATDurationOrDerived*)atom1.get())->subtract((const ATDurationOrDerived *)atom2.get(), context);
    }
    default: {
      XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("An invalid attempt to subtract from xdt:yearMonthDuration type has occurred [err:XPTY0004]"));
    }
    }
  }
  default: {
    XQThrow(XPath2ErrorException,X("Minus::createSequence"), X("The operator subtract ('-') has been called on invalid operand types [err:XPTY0004]"));
  }
  }
}

