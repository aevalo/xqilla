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
#include <xqilla/functions/FunctionDistinctValues.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/runtime/Sequence.hpp>
#include <xqilla/operators/Equals.hpp>
#include <xqilla/context/Collation.hpp>
#include <xqilla/context/impl/CodepointCollation.hpp>
#include <xqilla/exceptions/FunctionException.hpp>
#include <xqilla/exceptions/IllegalArgumentException.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/items/ATDoubleOrDerived.hpp>
#include <xqilla/items/ATFloatOrDerived.hpp>
#include <xqilla/items/ATStringOrDerived.hpp>
#include <xqilla/items/ATUntypedAtomic.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/DatatypeFactory.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/functions/XQillaFunction.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

#include <set>

#if defined(XERCES_HAS_CPP_NAMESPACE)
XERCES_CPP_NAMESPACE_USE
#endif

const XMLCh FunctionDistinctValues::name[] = {
  chLatin_d, chLatin_i, chLatin_s, 
  chLatin_t, chLatin_i, chLatin_n, 
  chLatin_c, chLatin_t, chDash, 
  chLatin_v, chLatin_a, chLatin_l, 
  chLatin_u, chLatin_e, chLatin_s, 
  chNull 
};
const unsigned int FunctionDistinctValues::minArgs = 1;
const unsigned int FunctionDistinctValues::maxArgs = 2;

/**
 * fn:distinct-values($arg as xs:anyAtomicType*) as xs:anyAtomicType*
 * fn:distinct-values($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType*
**/

FunctionDistinctValues::FunctionDistinctValues(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : XQFunction(name, "($arg as xs:anyAtomicType*, $collation as xs:string) as xs:anyAtomicType*", args, memMgr)
{
}

ASTNode *FunctionDistinctValues::staticTypingImpl(StaticContext *context)
{
  _src.clearExceptType();
  calculateSRCForArguments(context);
  _src.getStaticType() = _args.front()->getStaticAnalysis().getStaticType();
  _src.getStaticType().setCardinality(_src.getStaticType().getMin() == 0 ? 0 : 1, _src.getStaticType().getMax());
  return this;
}

int AnyAtomicType::compare(const AnyAtomicType::Ptr &b, const Collation *collation,
  const DynamicContext *context) const
{
  const AnyAtomicType *a = this;

  AnyAtomicType::AtomicObjectType atype = a->getSortType();
  AnyAtomicType::AtomicObjectType btype = b->getSortType();

  if(atype != btype) return atype - btype;

  // Items are comparable
  switch(atype) {
  case AnyAtomicType::STRING:
    return collation->compare(a->asString(context), b->asString(context));
  case AnyAtomicType::DOUBLE:
    return ((const Numeric *)a)->compare((const Numeric *)b.get(), context);
  case AnyAtomicType::DURATION:
    return ((const ATDurationOrDerived *)a)->compare((const ATDurationOrDerived *)b.get(), context);
  case AnyAtomicType::BASE_64_BINARY:
    return ((const ATBase64BinaryOrDerived *)a)->compare((const ATBase64BinaryOrDerived *)b.get(), context);
  case AnyAtomicType::BOOLEAN:
    return ((const ATBooleanOrDerived *)a)->compare((const ATBooleanOrDerived *)b.get(), context);
  case AnyAtomicType::DATE:
    return ((const ATDateOrDerived *)a)->compare((const ATDateOrDerived *)b.get(), context);
  case AnyAtomicType::DATE_TIME:
    return ((const ATDateTimeOrDerived *)a)->compare((const ATDateTimeOrDerived *)b.get(), context);
  case AnyAtomicType::G_DAY:
    return ((const ATGDayOrDerived *)a)->compare((const ATGDayOrDerived *)b.get(), context);
  case AnyAtomicType::G_MONTH:
    return ((const ATGMonthOrDerived *)a)->compare((const ATGMonthOrDerived *)b.get(), context);
  case AnyAtomicType::G_MONTH_DAY:
    return ((const ATGMonthDayOrDerived *)a)->compare((const ATGMonthDayOrDerived *)b.get(), context);
  case AnyAtomicType::G_YEAR:
    return ((const ATGYearOrDerived *)a)->compare((const ATGYearOrDerived *)b.get(), context);
  case AnyAtomicType::G_YEAR_MONTH:
    return ((const ATGYearMonthOrDerived *)a)->compare((const ATGYearMonthOrDerived *)b.get(), context);
  case AnyAtomicType::HEX_BINARY:
    return ((const ATHexBinaryOrDerived *)a)->compare((const ATHexBinaryOrDerived *)b.get(), context);
  case AnyAtomicType::NOTATION:
    return ((const ATNotationOrDerived *)a)->compare((const ATNotationOrDerived *)b.get(), context);
  case AnyAtomicType::QNAME:
    return ((const ATQNameOrDerived *)a)->compare((const ATQNameOrDerived *)b.get(), context);
  case AnyAtomicType::TIME:
    return ((const ATTimeOrDerived *)a)->compare((const ATTimeOrDerived *)b.get(), context);
  default: break;
  }

  assert(false);
  return 0;
}

struct dvCompare
{
  dvCompare(const Collation *collation, const DynamicContext *context)
    : collation_(collation), context_(context) {}

  bool operator()(const AnyAtomicType::Ptr &a, const AnyAtomicType::Ptr &b) const
  {
    return a->compare(b, collation_, context_) < 0;
  }

  const Collation *collation_;
  const DynamicContext *context_;
};

typedef std::set<AnyAtomicType::Ptr, dvCompare> DistinctSet;

class DistinctValueResult : public ResultImpl
{
public:
  DistinctValueResult(const FunctionDistinctValues *fdv, const DynamicContext *context);
  ~DistinctValueResult();
  Item::Ptr next(DynamicContext *context);
private:
  const FunctionDistinctValues *fdv_;
  Result parent_;
  bool toDo_;

  DistinctSet *alreadySeen_;
};

DistinctValueResult::DistinctValueResult(const FunctionDistinctValues *fdv, const DynamicContext *context)
  : ResultImpl(fdv),
    fdv_(fdv),
    parent_(0),
    toDo_(true),
    alreadySeen_(0)
{
}

DistinctValueResult::~DistinctValueResult()
{
  delete alreadySeen_;
}

Item::Ptr DistinctValueResult::next(DynamicContext *context)
{
  if(toDo_) {
    toDo_ = false;
    parent_ = fdv_->getParamNumber(1, context);

    Collation* collation;
    if(fdv_->getNumArgs() > 1) collation = context->getCollation(fdv_->getParamNumber(2,context)->
      next(context)->asString(context), this);
    else collation = context->getDefaultCollation(this);

    alreadySeen_ = new DistinctSet(dvCompare(collation, context));
  }

  AnyAtomicType::Ptr item;
  while(true) {
    item = (const AnyAtomicType *)parent_->next(context).get();
    if(item.isNull()) break;

    if(alreadySeen_->insert(item).second)
      return item;
  }

  parent_ = 0;
  return 0;
}

Result FunctionDistinctValues::createResult(DynamicContext* context, int flags) const
{
  return new DistinctValueResult(this, context);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result atomicCompare(const VectorOfASTNodes &args, DynamicContext *context,
                            const LocationInfo *info)
{
  Item::Ptr item1 = args[0]->createResult(context)->next(context);
  Item::Ptr item2 = args[1]->createResult(context)->next(context);

  Collation* collation;
  if(args.size() > 2) collation = context->getCollation(args[2]->createResult(context)->
    next(context)->asString(context), info);
  else collation = context->getDefaultCollation(info);

  int cmp = ((AnyAtomicType*)item1.get())->compare(item2, collation, context);
  return (Item::Ptr)context->getMemoryManager()->createInteger(cmp < 0 ? -1 : cmp > 0 ? 1 : 0);
}

const XMLCh atomicCompareName[] =
{ 'c', 'o', 'm', 'p', 'a', 'r', 'e', 0 };

static SimpleBuiltinFactory atomicCompareFactory(
  XQillaFunction::XMLChFunctionURI, atomicCompareName, 2,
  "($a as xs:anyAtomicType, $b as xs:anyAtomicType) as xs:integer", atomicCompare
);

static SimpleBuiltinFactory atomicCompareFactory2(
  XQillaFunction::XMLChFunctionURI, atomicCompareName, 3,
  "($a as xs:anyAtomicType, $b as xs:anyAtomicType, $collation as xs:string) as xs:integer", atomicCompare
);
