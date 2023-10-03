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
#include <xqilla/operators/Multiply.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/Numeric.hpp>
#include <xqilla/items/ATDurationOrDerived.hpp>
#include <xqilla/items/ATDecimalOrDerived.hpp>
#include <xqilla/items/AnyAtomicType.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

#include <xercesc/util/XMLUniDefs.hpp>

/*static*/ const XMLCh Multiply::name[]={ XERCES_CPP_NAMESPACE_QUALIFIER chLatin_M, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_u, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_l, XERCES_CPP_NAMESPACE_QUALIFIER chNull };

Multiply::Multiply(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : ArithmeticOperator(MULTIPLY, name, args, memMgr)
{
  // Nothing to do
}

void Multiply::calculateStaticType(StaticContext *context)
{
  const StaticType &arg0 = _args[0]->getStaticAnalysis().getStaticType();
  const StaticType &arg1 = _args[1]->getStaticAnalysis().getStaticType();

  calculateStaticTypeForNumerics(arg0, arg1, context);

  // Multiplying a duration by a number
  if(arg0.containsType(TypeFlags::DAY_TIME_DURATION|TypeFlags::YEAR_MONTH_DURATION) && arg1.containsType(TypeFlags::NUMERIC)) {
    StaticType tmp(BasicMemoryManager::get()); tmp = arg0;
    tmp.typeIntersect(TypeFlags::DAY_TIME_DURATION|TypeFlags::YEAR_MONTH_DURATION);
    _src.getStaticType().typeUnion(tmp);
  }
  if(arg0.containsType(TypeFlags::NUMERIC) && arg1.containsType(TypeFlags::DAY_TIME_DURATION|TypeFlags::YEAR_MONTH_DURATION)) {
    StaticType tmp(BasicMemoryManager::get()); tmp = arg1;
    tmp.typeIntersect(TypeFlags::DAY_TIME_DURATION|TypeFlags::YEAR_MONTH_DURATION);
    _src.getStaticType().typeUnion(tmp);
  }
}

Item::Ptr Multiply::execute(const AnyAtomicType::Ptr &atom1, const AnyAtomicType::Ptr &atom2, DynamicContext *context) const
{
  if(atom1.isNull() || atom2.isNull()) return 0;

  // xs:double * xs:duration (only xdt:dayTimeDuration and xdt:yearMonthDuration)
  if(atom1->isNumericValue() &&
     (atom2->getPrimitiveTypeIndex() == AnyAtomicType::DAY_TIME_DURATION ||
      atom2->getPrimitiveTypeIndex() == AnyAtomicType::YEAR_MONTH_DURATION)) {
      return ((const ATDurationOrDerived*)atom2.get())->multiply((const Numeric*)atom1.get(), context);
  }
  // xs:duration * xs:double (only xdt:dayTimeDuration and xdt:yearMonthDuration)
  if(atom2->isNumericValue() &&
     (atom1->getPrimitiveTypeIndex() == AnyAtomicType::DAY_TIME_DURATION ||
      atom1->getPrimitiveTypeIndex() == AnyAtomicType::YEAR_MONTH_DURATION)) {
    return ((const ATDurationOrDerived*)atom1.get())->multiply((const Numeric*)atom2.get(), context);
  }

  // numeric * numeric
  if(atom1->isNumericValue()) {
    if(atom2->isNumericValue()) {
      return ((const Numeric*)atom1.get())->multiply((const Numeric*)atom2.get(), context);
    }
    else {
      XQThrow(XPath2ErrorException,X("Multiply::createSequence"), X("An attempt to multiply a non numeric type to a numeric type has occurred [err:XPTY0004]"));
    }
  }

  XQThrow(XPath2ErrorException,X("Multiply::createSequence"), X("The operator * has been called on invalid operand types [err:XPTY0004]"));

}

