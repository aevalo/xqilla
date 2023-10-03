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

#include <assert.h>
#include <limits>

#include "../config/xqilla_config.h"
#include <xqilla/items/Numeric.hpp>
#include <xqilla/items/impl/ATDecimalOrDerivedImpl.hpp>
#include <xqilla/items/impl/ATFloatOrDerivedImpl.hpp>
#include <xqilla/items/impl/ATDoubleOrDerivedImpl.hpp>
#include <xqilla/mapm/m_apm.h>
#include <xqilla/exceptions/IllegalArgumentException.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/lookup3.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/runtime/Result.hpp>
#include <xqilla/ast/XQFunction.hpp>

#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/validators/schema/SchemaSymbols.hpp>

// Added so xqilla will compile on SunOS 10 using STLPort
#include <stdio.h>

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#if defined(XERCES_HAS_CPP_NAMESPACE)
XERCES_CPP_NAMESPACE_USE
#endif

const XMLCh Numeric::NaN_string[] = 
{ chLatin_N, chLatin_a, chLatin_N, chNull };

const XMLCh Numeric::NAN_string[] = 
{ chLatin_N, chLatin_A, chLatin_N, chNull };

const XMLCh Numeric::INF_string[] = 
{ chLatin_I, chLatin_N, chLatin_F, chNull };

const XMLCh Numeric::NegINF_string[] =
{ chDash, chLatin_I, chLatin_N, chLatin_F, chNull };

const XMLCh Numeric::NegZero_string[] =
{ chDash, chDigit_0, chNull };

const XMLCh Numeric::PosZero_string[] =
{ chDigit_0, chNull };

void Numeric::checkFloatLimits(Numeric::State &state, MAPM &value)
{
  if(state==NUM || state==NEG_NUM) {
    int exp=value.exponent();
    if(exp>38 || (exp==38 && value.abs()>MAPM("3.4028235e+38"))) {
      state=(state==NEG_NUM)?NEG_INF:INF;
      value = MAPM();
    }
    else if(exp<-38 || (exp==-38 && value.abs()<MAPM("1.1754944e-38")))
      value=MAPM();
  }
}

void Numeric::checkDoubleLimits(Numeric::State &state, MAPM &value)
{
  if(state==NUM || state==NEG_NUM) {
    int exp=value.exponent();
    if(exp>308 || (exp==308 && value.abs()>MAPM("1.7976931348623157e+308"))) {
      state=(state==NEG_NUM)?NEG_INF:INF;
      value = MAPM();
    }
    else if(exp<-308 || (exp==-308 && value.abs()<MAPM("2.2250738585072014e-308")))
      value=MAPM();
  }
}

inline int compare(Numeric::State state1, const MAPM &value1, Numeric::State state2, const MAPM &value2)
{
  // Arbitrarily ranks NaN as greater than all other states

  int cmp = state1 - state2;
  if(cmp != 0) return cmp;

  switch(state1) {
  case Numeric::NaN:
  case Numeric::INF:
  case Numeric::NEG_INF:
    return 0;
  case Numeric::NUM:
  case Numeric::NEG_NUM:
    return value1.compare(value2);
  }

  assert(false); // should never get here
  return 0;
}

inline int typePromoteCompare(const Numeric::Ptr &num1, const Numeric::Ptr &num2)
{
  Numeric::State state1 = num1->getState();
  MAPM value1 = num1->asMAPM();

  Numeric::State state2 = num2->getState();
  MAPM value2 = num2->asMAPM();

  switch(num1->getPrimitiveTypeIndex()) {
  case AnyAtomicType::DECIMAL:
    switch(num2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DECIMAL:
      break;
    case AnyAtomicType::FLOAT:
      Numeric::checkFloatLimits(state1, value1);
      Numeric::checkFloatLimits(state2, value2);
      break;
    case AnyAtomicType::DOUBLE:
      Numeric::checkDoubleLimits(state1, value1);
      Numeric::checkDoubleLimits(state2, value2);
      break;
    default: break;
    }
    break;
  case AnyAtomicType::FLOAT:
    switch(num2->getPrimitiveTypeIndex()) {
    case AnyAtomicType::DECIMAL:
    case AnyAtomicType::FLOAT:
      Numeric::checkFloatLimits(state1, value1);
      Numeric::checkFloatLimits(state2, value2);
      break;
    case AnyAtomicType::DOUBLE:
      Numeric::checkDoubleLimits(state1, value1);
      Numeric::checkDoubleLimits(state2, value2);
      break;
    default: break;
    }
    break;
  case AnyAtomicType::DOUBLE:
    Numeric::checkDoubleLimits(state1, value1);
    Numeric::checkDoubleLimits(state2, value2);
    break;
  default: break;
  }

  return compare(state1, value1, state2, value2);
}

int Numeric::compare(const Numeric::Ptr &other, const DynamicContext *context) const
{
  return ::compare(getState(), asMAPM(), other->getState(), other->asMAPM());
}

void Numeric::hashMAPM(const MAPM &m, uint32_t *pc, uint32_t *pb)
{
  M_APM val = m.c_struct();
  hashlittle2((void*)&val->m_apm_exponent, sizeof(int), pc, pb);
  hashlittle2(val->m_apm_data, (val->m_apm_datalength + 1) >> 1, pc, pb);
}

size_t Numeric::hash(const Collation *collation, const DynamicContext *context) const
{
  uint32_t pc = 0xF00BAA56, pb = 0xBADFACE2;

  // Hash the sort type
  uint32_t u32 = (uint32_t)getSortType();
  hashword2(&u32, 1, &pc, &pb);

  // Hash the state
  u32 = getState();
  hashword2(&u32, 1, &pc, &pb);

  // Hash the mapm
  hashMAPM(asMAPM(), &pc, &pb);

  return (size_t)pc + (((size_t)pb)<<32);
}

bool Numeric::equals(const AnyAtomicType::Ptr &target, const DynamicContext* context) const
{
  if(!target->isNumericValue()) {
    XQThrow2(::IllegalArgumentException,X("Numeric::equals"),
	    X("Equality operator for given types not supported [err:XPTY0004]"));
  } 

  const Numeric *otherImpl = (const Numeric*)target.get();

  if(getState() == NaN || otherImpl->getState() == NaN) return false;
  return typePromoteCompare(this, otherImpl) == 0;
}

/** Returns true if this is less than other, false otherwise */
bool Numeric::lessThan(const Numeric::Ptr &other, const DynamicContext* context) const
{
  if(getState() == NaN || other->getState() == NaN) return false;
  return typePromoteCompare(this, other) < 0;
}

/** Returns true if this is greater than other, false otherwise */
bool Numeric::greaterThan(const Numeric::Ptr &other, const DynamicContext* context) const
{
  if(getState() == NaN || other->getState() == NaN) return false;
  return typePromoteCompare(this, other) > 0;
}

AnyAtomicType::Ptr Numeric::castAsInternal(AtomicObjectType targetIndex, const XMLCh* targetURI,
                                           const XMLCh* targetType, const DynamicContext* context) const
{
  switch(targetIndex) {
  case DECIMAL:
    switch(getState()) {
    case NaN:
    case INF:
    case NEG_INF:
      XQThrow2(::IllegalArgumentException, X("Numeric::castAsInternal"),
              X("Special values like NaN, INF or -INF cannot be cast to decimal [err:FOCA0002]"));
    case NUM:
    case NEG_NUM:
      if(targetType != 0 && context->isTypeOrDerivedFromType(targetURI, targetType,
                                                             SchemaSymbols::fgURI_SCHEMAFORSCHEMA,
                                                             SchemaSymbols::fgDT_INTEGER)) {
        if(XPath2Utils::equals(targetType, SchemaSymbols::fgDT_INTEGER) &&
           XPath2Utils::equals(targetURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
          return context->getItemFactory()->createInteger(isNegative() ? asMAPM().ceil() : asMAPM().floor(), context);
        }

        return context->getItemFactory()->createDecimalOrDerived(targetURI, targetType, isNegative() ? asMAPM().ceil() : asMAPM().floor(), context);
      }    
      else {
        if(targetType == 0) {
          return context->getItemFactory()->createDecimal(asMAPM(), context);
        }
        return context->getItemFactory()->createDecimalOrDerived(targetURI, targetType, asMAPM(), context);
      }
    }
  case FLOAT:
    switch(getState()) {
    case NaN:
      return context->getItemFactory()->createFloatOrDerived(targetURI, targetType, NaN_string, context);
    case INF:
      return context->getItemFactory()->createFloatOrDerived(targetURI, targetType, INF_string, context);
    case NEG_INF:
      return context->getItemFactory()->createFloatOrDerived(targetURI, targetType, NegINF_string, context);
    case NEG_NUM:
      if(isZero()) {
        return context->getItemFactory()->createFloatOrDerived(targetURI, targetType, NegZero_string, context);
      }
      // Fall through
    case NUM:
      if(targetType == 0) {
        return context->getItemFactory()->createFloat(asMAPM(), context);
      }
      return context->getItemFactory()->createFloatOrDerived(targetURI, targetType, asMAPM(), context);
    }
  case DOUBLE:
    switch(getState()) {
    case NaN:
      return context->getItemFactory()->createDoubleOrDerived(targetURI, targetType, NaN_string, context);
    case INF:
      return context->getItemFactory()->createDoubleOrDerived(targetURI, targetType, INF_string, context);
    case NEG_INF:
      return context->getItemFactory()->createDoubleOrDerived(targetURI, targetType, NegINF_string, context);
    case NEG_NUM:
      if(isZero()) {
        return context->getItemFactory()->createDoubleOrDerived(targetURI, targetType, NegZero_string, context);
      }
      // Fall through
    case NUM:
      if(targetType == 0) {
        return context->getItemFactory()->createDouble(asMAPM(), context);
      }
      return context->getItemFactory()->createDoubleOrDerived(targetURI, targetType, asMAPM(), context);
    }
  case BOOLEAN:
    if(targetType == 0) {
      targetURI = SchemaSymbols::fgURI_SCHEMAFORSCHEMA;
      targetType = SchemaSymbols::fgDT_BOOLEAN;
    }
    if(isZero() || isNaN()) {
      return context->getItemFactory()->createBooleanOrDerived(targetURI, targetType, false, context);
    } else {
      return context->getItemFactory()->createBooleanOrDerived(targetURI, targetType, true, context);
    }
  default:
    return AnyAtomicType::castAsInternal(targetIndex, targetURI, targetType, context);
  }
}

const XMLCh *Numeric::asDecimalString(int significantDigits, const StaticContext* context) const
{
  return asDecimalString(asMAPM(), significantDigits, context);
}

const XMLCh *Numeric::asDecimalString(const MAPM &number, int significantDigits, const StaticContext* context)
{
  char obuf[1024];
  if(number.is_integer())
    number.toIntegerString(obuf);
  else {
    number.toFixPtString(obuf, significantDigits);

    // Note in the canonical representation the decimal point is required
    // and there must be at least one digit to the right and one digit to 
    // the left of the decimal point (which may be 0)
    if(strchr(obuf,'.')!=0) {
      // remove trailing 0's
      char* lastChar=obuf+strlen(obuf)-1;
      while(*lastChar=='0') {
        *lastChar--=0;
      }
      // remove decimal point, if there are no digits after it
      if(*lastChar=='.')
        *lastChar=0;
    }
  }
  return context->getMemoryManager()->getPooledString(obuf);
}

const XMLCh *Numeric::asDoubleString(int significantDigits, const StaticContext* context) const
{
  State state1 = getState();
  MAPM value1 = asMAPM();

  switch(getPrimitiveTypeIndex()) {
  case FLOAT:
    checkFloatLimits(state1, value1);
    break;
  case DOUBLE:
    checkDoubleLimits(state1, value1);
    break;
  default: break;
  }

  return asDoubleString(state1, value1, significantDigits, context);
}

const XMLCh *Numeric::asDoubleString(State state1, const MAPM &value1, int significantDigits, const StaticContext* context)
{
  switch(state1) {
  case NaN:     return NaN_string;
  case INF:     return INF_string;
  case NEG_INF: return NegINF_string;
  case NEG_NUM:
    if(value1.sign() == 0) return NegZero_string;
    break;
  case NUM:
    if(value1.sign() == 0) return PosZero_string;
    break;
  }

  MAPM absVal = value1.abs();
  MAPM lower("0.000001"), upper("1000000");
  if(absVal < upper && absVal >= lower) {
    return asDecimalString(value1, significantDigits, context);
  }
  else {
    char obuf[1024];
    if(significantDigits==7)
    {
      value1.toString(obuf, 25);
      double num=atof(obuf);
      sprintf(obuf, "%.*G", min(8,value1.significant_digits()), num);
      MAPM val=obuf;
      int precision = val.significant_digits() - 1;
      if(precision <= 0) precision = 1;
      val.toString(obuf, precision);
      return context->getMemoryManager()->getPooledString(obuf);
    }
    else if(significantDigits==16)
    {
      value1.toString(obuf, 25);
      double num=atof(obuf);
      sprintf(obuf, "%.*G", min(17,value1.significant_digits()), num);
      MAPM val=obuf;
      int precision = val.significant_digits() - 1;
      if(precision <= 0) precision = 1;
      val.toString(obuf, precision);
      return context->getMemoryManager()->getPooledString(obuf);
    }
    int precision = value1.significant_digits() - 1;
    if(precision > significantDigits) precision = significantDigits;
    if(precision <= 0) precision = 1;
    value1.toString(obuf, precision);
    return context->getMemoryManager()->getPooledString(obuf);
  }

  return 0;
}

double Numeric::asDouble() const
{
  switch(getState()) {
  case NaN:
    return std::numeric_limits<double>::quiet_NaN();
  case INF:
    return std::numeric_limits<double>::infinity();
  case NEG_INF:
    return -std::numeric_limits<double>::infinity();
  case NUM:
  case NEG_NUM:
    break;
  }
  return asMAPM().toDouble();
}

int Numeric::asInt() const
{
  return (int)asMAPM().toDouble();
}

bool Numeric::isInteger() const
{
  return asMAPM().is_integer();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/* http://exslt.org/math */
const XMLCh exsltMathURI[] =
{ 'h', 't', 't', 'p', ':', '/', '/', 'e', 'x', 's', 'l', 't', '.', 'o', 'r', 'g', '/', 'm', 'a', 't', 'h', 0 };

// http://www.w3.org/2005/xpath-functions/math
static const XMLCh mathURI[] =
{ 'h', 't', 't', 'p', ':', '/', '/', 'w', 'w', 'w', '.', 'w', '3', '.', 'o', 'r', 'g', '/', '2',
  '0', '0', '5', '/', 'x', 'p', 'a', 't', 'h', '-', 'f', 'u', 'n', 'c', 't', 'i', 'o', 'n', 's',
  '/', 'm', 'a', 't', 'h', 0 };

static Numeric::Ptr numericParam(ASTNode *arg, DynamicContext *context, const LocationInfo *info)
{
  Item::Ptr item = arg->createResult(context)->next(context);
  if(item.notNull() && (item->getType() != Item::ATOMIC || !((const AnyAtomicType *)item.get())->isNumericValue()))
    XQThrow3(XPath2TypeMatchException, X("numericParam"),
             X("Non-numeric argument in numeric function [err:XPTY0004]"), info);
  return (Numeric*)item.get();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result abs(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->abs(context);
}

static const XMLCh absName[] =
{ 'a', 'b', 's', 0 };

static SimpleBuiltinFactory absFactory(
  XQFunction::XMLChFunctionURI, absName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", abs,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory absEXSLTFactory(
  exsltMathURI, absName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", abs,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result ceiling(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->ceiling(context);
}

static const XMLCh ceilingName[] =
{ 'c', 'e', 'i', 'l', 'i', 'n', 'g', 0 };

static SimpleBuiltinFactory ceilingFactory(
  XQFunction::XMLChFunctionURI, ceilingName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", ceiling,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result floor(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->floor(context);
}

static const XMLCh floorName[] =
{ 'f', 'l', 'o', 'o', 'r', 0 };

static SimpleBuiltinFactory floorFactory(
  XQFunction::XMLChFunctionURI, floorName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", floor,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result round(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->round(context);
}

static const XMLCh roundName[] =
{ 'r', 'o', 'u', 'n', 'd', 0 };

static SimpleBuiltinFactory roundFactory(
  XQFunction::XMLChFunctionURI, roundName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", round,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result roundHalfToEven(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr numericArg = numericParam(args[0], context, info);
  if(numericArg.isNull()) return 0;

  ATDecimalOrDerived::Ptr precision;
  if(args.size() > 1)
    precision = (ATDecimalOrDerived*)args[1]->createResult(context)->next(context).get();
  else precision = context->getMemoryManager()->createInteger(0);
  
  return (Item::Ptr)numericArg->roundHalfToEven(precision, context);
}

static const XMLCh roundHalfToEvenName[] =
{ 'r', 'o', 'u', 'n', 'd', '-', 'h', 'a', 'l', 'f', '-', 't', 'o', '-', 'e', 'v', 'e', 'n', 0 };

static SimpleBuiltinFactory roundHalfToEvenFactory(
  XQFunction::XMLChFunctionURI, roundHalfToEvenName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", roundHalfToEven,
  0, SimpleBuiltinFactory::NUMERIC
);
static SimpleBuiltinFactory roundHalfToEvenFactory2(
  XQFunction::XMLChFunctionURI, roundHalfToEvenName, 2,
  "($arg as xs:anyAtomicType?, $precision as xs:integer) as xs:anyAtomicType?", roundHalfToEven,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathSin(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->sin(context);
}

static const XMLCh mathSinName[] =
{ 's', 'i', 'n', 0 };

static SimpleBuiltinFactory mathSinEXSLTFactory(
  exsltMathURI, mathSinName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathSin,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathSinFactory(
  mathURI, mathSinName, 1,
  "($arg as xs:double?) as xs:double?", mathSin
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathCos(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->cos(context);
}

static const XMLCh mathCosName[] =
{ 'c', 'o', 's', 0 };

static SimpleBuiltinFactory mathCosEXSLTFactory(
  exsltMathURI, mathCosName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathCos,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathCosFactory(
  mathURI, mathCosName, 1,
  "($arg as xs:double?) as xs:double?", mathCos
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathTan(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->tan(context);
}

static const XMLCh mathTanName[] =
{ 't', 'a', 'n', 0 };

static SimpleBuiltinFactory mathTanEXSLTFactory(
  exsltMathURI, mathTanName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathTan,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathTanFactory(
  mathURI, mathTanName, 1,
  "($arg as xs:double?) as xs:double?", mathTan
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathAsin(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->asin(context);
}

static const XMLCh mathAsinName[] =
{ 'a', 's', 'i', 'n', 0 };

static SimpleBuiltinFactory mathAsinEXSLTFactory(
  exsltMathURI, mathAsinName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathAsin,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathAsinFactory(
  mathURI, mathAsinName, 1,
  "($arg as xs:double?) as xs:double?", mathAsin
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathAcos(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->acos(context);
}

static const XMLCh mathAcosName[] =
{ 'a', 'c', 'o', 's', 0 };

static SimpleBuiltinFactory mathAcosEXSLTFactory(
  exsltMathURI, mathAcosName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathAcos,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathAcosFactory(
  mathURI, mathAcosName, 1,
  "($arg as xs:double?) as xs:double?", mathAcos
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathAtan(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->atan(context);
}

static const XMLCh mathAtanName[] =
{ 'a', 't', 'a', 'n', 0 };

static SimpleBuiltinFactory mathAtanEXSLTFactory(
  exsltMathURI, mathAtanName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathAtan,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathAtanFactory(
  mathURI, mathAtanName, 1,
  "($arg as xs:double?) as xs:double?", mathAtan
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathSqrt(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->sqrt(context);
}

static const XMLCh mathSqrtName[] =
{ 's', 'q', 'r', 't', 0 };

static SimpleBuiltinFactory mathSqrtEXSLTFactory(
  exsltMathURI, mathSqrtName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathSqrt,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathSqrtFactory(
  mathURI, mathSqrtName, 1,
  "($arg as xs:double?) as xs:double?", mathSqrt
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathLog(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->log(context);
}

static const XMLCh mathLogName[] =
{ 'l', 'o', 'g', 0 };

static SimpleBuiltinFactory mathLogEXSLTFactory(
  exsltMathURI, mathLogName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathLog,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathLogFactory(
  mathURI, mathLogName, 1,
  "($arg as xs:double?) as xs:double?", mathLog
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathExp(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr num = numericParam(args[0], context, info);
  if(num.isNull()) return 0;
  return (Item::Ptr)num->exp(context);
}

static const XMLCh mathExpName[] =
{ 'e', 'x', 'p', 0 };

static SimpleBuiltinFactory mathExpEXSLTFactory(
  exsltMathURI, mathExpName, 1,
  "($arg as xs:anyAtomicType?) as xs:anyAtomicType?", mathExp,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathExpFactory(
  mathURI, mathExpName, 1,
  "($arg as xs:double?) as xs:double?", mathExp
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathPow(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Numeric::Ptr base = numericParam(args[0], context, info);
  if(base.isNull()) return 0;
  Numeric::Ptr pow = numericParam(args[1], context, info);
  if(pow.isNull()) return 0;
  return (Item::Ptr)base->power(pow, context);
}

static const XMLCh mathPowerName[] =
{ 'p', 'o', 'w', 'e', 'r', 0 };

static const XMLCh mathPowName[] =
{ 'p', 'o', 'w', 0 };

static SimpleBuiltinFactory mathPowerEXSLTFactory(
  exsltMathURI, mathPowerName, 2,
  "($arg as xs:anyAtomicType?, $arg2 as xs:anyAtomicType?) as xs:anyAtomicType?", mathPow,
  0, SimpleBuiltinFactory::NUMERIC
);

static SimpleBuiltinFactory mathPowFactory(
  mathURI, mathPowName, 2,
  "($x as xs:double?, $y as xs:anyAtomicType) as xs:double?", mathPow,
  0, SimpleBuiltinFactory::NUMERIC
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static const XMLCh s_pi[] =
{ '3', '.', '1', '4', '1', '5', '9', '2', '6', '5', '3', '5', '8', '9', '7', '9', '3', 'e', '0', 0 };

static Result mathPi(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  return (Item::Ptr)context->getItemFactory()->createDouble(s_pi, context);
}

static const XMLCh mathPiName[] =
{ 'p', 'i', 0 };

static SimpleBuiltinFactory mathPiFactory(
  mathURI, mathPiName, 0,
  "() as xs:double", mathPi
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathAtan2(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Item::Ptr y = args[0]->createResult(context)->next(context);
  Item::Ptr x = args[1]->createResult(context)->next(context);
  MAPM result = ((Numeric*)y.get())->asMAPM().atan2(((Numeric*)x.get())->asMAPM());
  return (Item::Ptr)context->getItemFactory()->createDouble(result, context);
}

static const XMLCh mathAtan2Name[] =
{ 'a', 't', 'a', 'n', '2', 0 };

static SimpleBuiltinFactory mathAtan2Factory(
  mathURI, mathAtan2Name, 2,
  "($y as xs:double, $x as xs:double) as xs:double", mathAtan2
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathLog10(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)context->getItemFactory()->createDouble(((Numeric*)item.get())->asMAPM().log10(), context);
}

static const XMLCh mathLog10Name[] =
{ 'l', 'o', 'g', '1', '0', 0 };

static SimpleBuiltinFactory mathLog10Factory(
  mathURI, mathLog10Name, 1,
  "($arg as xs:double?) as xs:double?", mathLog10
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mathExp10(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)context->getItemFactory()->createDouble(MAPM(10).pow(((Numeric*)item.get())->asMAPM()), context);
}

static const XMLCh mathExp10Name[] =
{ 'e', 'x', 'p', '1', '0', 0 };

static SimpleBuiltinFactory mathExp10Factory(
  mathURI, mathExp10Name, 1,
  "($arg as xs:double?) as xs:double?", mathExp10
);

