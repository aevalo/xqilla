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

#include "../../config/xqilla_config.h"
#include <xqilla/items/impl/TupleImpl.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/events/EventHandler.hpp>
#include <xqilla/utils/XStr.hpp>
#include <xqilla/axis/NodeTest.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/runtime/Sequence.hpp>
#include <xqilla/ast/ASTNode.hpp>
#include <xqilla/ast/XQFunction.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/runtime/ClosureResult.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/ast/XQTreatAs.hpp>
#include <xqilla/ast/XQAtomize.hpp>

XERCES_CPP_NAMESPACE_USE;
using namespace std;

TupleImpl::TupleImpl(DynamicContext *context)
  : values_(17, AtomicHashFunctor(context->getDefaultCollation(0), context),
            AtomicEqualsFunctor(context->getDefaultCollation(0), context)),
    signature_(0),
    mm_(context->getMemoryManager())
{
}

TupleImpl::TupleImpl(size_t capacity, const Collation *collation, DynamicContext *context)
  : values_(capacity < 1 ? 1 : capacity, AtomicHashFunctor(collation, context),
            AtomicEqualsFunctor(collation, context)),
    signature_(0),
    mm_(context->getMemoryManager())
{
}

TupleImpl::TupleImpl(const TupleImpl *o)
  : values_(o->values_),
    signature_(0),
    mm_(o->mm_)
{
}

TupleImpl::~TupleImpl()
{
  if(signature_)
    const_cast<FunctionSignature*>(signature_)->release();
}

void TupleImpl::generateEvents(EventHandler *events, const DynamicContext *context,
                               bool preserveNS, bool preserveType) const
{
  // TBD What is the correct way to generate events for a Tuple? - jpcs
  events->atomicItemEvent(AnyAtomicType::STRING, asString(context), 0, 0);
}

const XMLCh *TupleImpl::asString(const DynamicContext *context) const
{
  XMLBuffer buf;
  buf.set(X("tuple{"));

  bool addComma = false;
  ValueMap::iterator i = const_cast<ValueMap&>(values_).begin();
  ValueMap::iterator end = const_cast<ValueMap&>(values_).end();
  for(; i != end; ++i) {
    if(addComma)
      buf.append(X(", "));
    else addComma = true;

    buf.append(i.getKey()->asString(context));

    buf.append(X(": "));

    Sequence sequence = i.getValue().createResult()->
      toSequence(const_cast<DynamicContext*>(context));

    size_t len = sequence.getLength();
    if(len == 1) {
      buf.append(sequence.first()->asString(context));
    }
    else {
      buf.append('(');
      Sequence::const_iterator i = sequence.begin();
      Sequence::const_iterator end = sequence.end();
      while(i != end) {
        buf.append((*i)->asString(context));
        if(++i != end) buf.append(X(", "));
      }
      buf.append(')');
    }
  }

  buf.append(X("}"));

  return context->getMemoryManager()->getPooledString(buf.getRawBuffer());
}

void TupleImpl::typeToBuffer(DynamicContext *context, XMLBuffer &buffer) const
{
  // TBD output a better type - jpcs
  buffer.append(X("tuple()"));
}

void *TupleImpl::getInterface(const XMLCh *name) const
{
  return 0;
}

void TupleImpl::add(const XMLCh *uri, const XMLCh *name, const Result &value, const DynamicContext *context)
{
  values_.put(context->getItemFactory()->createQName(uri, 0, name, context), ResultBuffer(value));
}

void TupleImpl::add(const AnyAtomicType::Ptr &key, const Result &value)
{
  values_.put(key, ResultBuffer(value));
}

bool TupleImpl::get(const XMLCh *uri, const XMLCh *name, const DynamicContext *context, Result &result) const
{
  ATQNameOrDerived::Ptr qname = context->getItemFactory()->createQName(uri, 0, name, context);
  ResultBuffer *buffer = const_cast<ResultBuffer*>(values_.get(qname));
  if(!buffer) return false;
  result = buffer->createResult();
  return true;
}

Result TupleImpl::get(const AnyAtomicType::Ptr &key) const
{
  ResultBuffer *buffer = const_cast<ResultBuffer*>(values_.get(key));
  if(!buffer) return 0;
  return buffer->createResult();
}

bool TupleImpl::contains(const AnyAtomicType::Ptr &key) const
{
  return values_.contains(key);
}

void TupleImpl::getInScopeVariables(vector<pair<const XMLCh*, const XMLCh*> > &variables) const
{
  pair<const XMLCh*, const XMLCh*> pair;
  ValueMap::iterator i = const_cast<ValueMap&>(values_).begin();
  ValueMap::iterator end = const_cast<ValueMap&>(values_).end();
  for(; i != end; ++i) {
    if(i.getKey()->getPrimitiveTypeIndex() == AnyAtomicType::QNAME) {
      pair.first = ((ATQNameOrDerived*)i.getKey().get())->getURI();
      pair.second = ((ATQNameOrDerived*)i.getKey().get())->getName();
      variables.push_back(pair);
    }
  }
}

size_t TupleImpl::size() const
{
  return values_.size();
}

Tuple::Ptr TupleImpl::put(const AnyAtomicType::Ptr &key, const Result &value) const
{
  TupleImpl::Ptr newTuple = new TupleImpl(this);
  newTuple->values_.put(key, ResultBuffer(value));
  return (Tuple::Ptr)newTuple;
}

Tuple::Ptr TupleImpl::remove(const AnyAtomicType::Ptr &key) const
{
  TupleImpl::Ptr newTuple = new TupleImpl(this);
  newTuple->values_.remove(key);
  return (Tuple::Ptr)newTuple;
}

class TupleEntries : public ResultImpl
{
public:
  TupleEntries(const TupleImpl *tuple, const TupleImpl::ValueMap::iterator &begin,
               const TupleImpl::ValueMap::iterator &end, const LocationInfo *location)
    : ResultImpl(location),
      tuple_(tuple),
      i_(begin),
      end_(end)
  {
  }

  virtual Item::Ptr nextOrTail(Result &tail, DynamicContext *context)
  {
    static const XMLCh s_key[] = { 'k', 'e', 'y', 0 };
    static const XMLCh s_value[] = { 'v', 'a', 'l', 'u', 'e', 0 };

    TupleImpl::Ptr newTuple = new TupleImpl(2, context->getDefaultCollation(this), context);
    newTuple->add(context->getItemFactory()->createString(s_key, context),
                  (Item::Ptr)i_.getKey());
    newTuple->add(context->getItemFactory()->createString(s_value, context),
                  i_.getValue().createResult());

    if(++i_ == end_) tail = 0;
    return newTuple;
  }

private:
  Tuple::Ptr tuple_;
  TupleImpl::ValueMap::iterator i_, end_;
};

Result TupleImpl::entries(const LocationInfo *location) const
{
  if(values_.size() == 0) return 0;
  return new TupleEntries(this, const_cast<ValueMap&>(values_).begin(),
                          const_cast<ValueMap&>(values_).end(), location);
}

ATQNameOrDerived::Ptr TupleImpl::getName(const DynamicContext *context) const
{
  return 0;
}

size_t TupleImpl::getNumArgs() const
{
  return 1;
}

const FunctionSignature *TupleImpl::getSignature() const
{
  if(signature_ == 0) {
    static const XMLCh s_key[] = { 'k', 'e', 'y', 0 };
    ArgumentSpec *arg = new (mm_) ArgumentSpec(s_key, (SequenceType*)&SequenceType::ANY_ATOMIC_TYPE, mm_);
    arg->setName(s_key);
    const_cast<StaticType&>(arg->getStaticType()) = StaticType::ITEM_STAR;

    ArgumentSpecs *args = new (mm_) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(mm_));
    args->push_back(arg);

    signature_ = new (mm_) FunctionSignature(args, 0, mm_);
  }
  return signature_;
}

Result TupleImpl::execute(const VectorOfResults &args, DynamicContext *context, const LocationInfo *location) const
{
  if(args.size() != 1) {
    XMLBuffer buf;
    buf.set(X("The function item invoked does not accept "));
    XPath2Utils::numToBuf((unsigned int)args.size(), buf);
    buf.append(X(" arguments - found item of type "));
    typeToBuffer(context, buf);
    buf.append(X(" [err:XPTY0004]"));
    XQThrow3(XPath2TypeMatchException, X("FunctionRefImpl::execute"), buf.getRawBuffer(), location);
  }

  Result argResult = SequenceType::ANY_ATOMIC_TYPE.matches(
    new AtomizeResult(location, args[0]), location, XQTreatAs::err_XPTY0004);
  return get(argResult->next(context));
}

FunctionRef::Ptr TupleImpl::partialApply(const Result &arg, unsigned int argNum, DynamicContext *context, const LocationInfo *location) const
{
  // Never called
  return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result emptyMap(const VectorOfASTNodes &args, DynamicContext *context,
                       const LocationInfo *info)
{
  Collation* collation;
  if(args.size() > 0) collation = context->getCollation(args[0]->createResult(context)->
    next(context)->asString(context), info);
  else collation = context->getDefaultCollation(info);

  return (Item::Ptr)new TupleImpl(13, collation, context);
}

const XMLCh emptyMapName[] =
{ 'e', 'm', 'p', 't', 'y', '-', 'm', 'a', 'p', 0 };

static SimpleBuiltinFactory emptyMapFactory(
  XQFunction::XMLChFunctionURI, emptyMapName, 0,
  "() as map()", emptyMap
);

static SimpleBuiltinFactory emptyMapFactory2(
  XQFunction::XMLChFunctionURI, emptyMapName, 1,
  "($collation as xs:string) as map()", emptyMap
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mapContains(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  Tuple::Ptr tuple = (Tuple*)args[0]->createResult(context)->next(context).get();
  AnyAtomicType::Ptr key = (AnyAtomicType*)args[1]->createResult(context)->next(context).get();

  return (Item::Ptr)context->getItemFactory()->createBoolean(tuple->contains(key), context);
}

const XMLCh mapContainsName[] =
{ 'm', 'a', 'p', '-', 'c', 'o', 'n', 't', 'a', 'i', 'n', 's', 0 };

static SimpleBuiltinFactory mapContainsFactory(
  XQFunction::XMLChFunctionURI, mapContainsName, 2,
  "($map as map(), $key as xs:anyAtomicType) as xs:boolean", mapContains
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mapPut(const VectorOfASTNodes &args, DynamicContext *context,
                     const LocationInfo *info)
{
  Tuple::Ptr tuple = (Tuple*)args[0]->createResult(context)->next(context).get();
  AnyAtomicType::Ptr key = (AnyAtomicType*)args[1]->createResult(context)->next(context).get();

  return (Item::Ptr)tuple->put(key, args[2]->createResult(context));
}

const XMLCh mapPutName[] =
{ 'm', 'a', 'p', '-', 'p', 'u', 't', 0 };

static SimpleBuiltinFactory mapPutFactory(
  XQFunction::XMLChFunctionURI, mapPutName, 3,
  "($map as map(), $key as xs:anyAtomicType, $value as item()*) as map()", mapPut
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result mapEntries(const VectorOfASTNodes &args, DynamicContext *context,
                         const LocationInfo *info)
{
  Tuple::Ptr tuple = (Tuple*)args[0]->createResult(context)->next(context).get();
  return tuple->entries(info);
}

const XMLCh mapEntriesName[] =
{ 'm', 'a', 'p', '-', 'e', 'n', 't', 'r', 'i', 'e', 's', 0 };

static SimpleBuiltinFactory mapEntriesFactory(
  XQFunction::XMLChFunctionURI, mapEntriesName, 1,
  "($map as map()) as map()*", mapEntries
);

