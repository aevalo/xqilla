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

#ifndef _XQILLATUPLEIMPL_HPP
#define _XQILLATUPLEIMPL_HPP

#include <xqilla/items/Tuple.hpp>
#include <xqilla/utils/IHashMap.hpp>
#include <xqilla/runtime/ResultBuffer.hpp>

struct AtomicHashFunctor
{
  AtomicHashFunctor(const Collation *collation, const DynamicContext *context)
    : collation_(collation), context_(context) {}

  inline size_t operator()(const AnyAtomicType::Ptr &a) const
  {
    return a->hash(collation_, context_);
  }

  const Collation *collation_;
  const DynamicContext *context_;
};

struct AtomicEqualsFunctor
{
  AtomicEqualsFunctor(const Collation *collation, const DynamicContext *context)
    : collation_(collation), context_(context) {}

  inline bool operator()(const AnyAtomicType::Ptr &a, const AnyAtomicType::Ptr &b) const
  {
    return a->compare(b, collation_, context_) == 0;
  }

  const Collation *collation_;
  const DynamicContext *context_;
};

class XQILLA_API TupleImpl : public Tuple
{
public:
  typedef RefCountPointer<TupleImpl> Ptr;
  typedef IHashMap<AnyAtomicType::Ptr, ResultBuffer, AtomicHashFunctor, AtomicEqualsFunctor> ValueMap;

  TupleImpl(DynamicContext *context);
  TupleImpl(size_t capacity, const Collation *collation, DynamicContext *context);
  TupleImpl(const TupleImpl *o);
  ~TupleImpl();

  void add(const XMLCh *uri, const XMLCh *name, const Result &value, const DynamicContext *context);
  void add(const AnyAtomicType::Ptr &key, const Result &value);

  virtual bool get(const XMLCh *uri, const XMLCh *name, const DynamicContext *context, Result &result) const;
  virtual void getInScopeVariables(std::vector<std::pair<const XMLCh*, const XMLCh*> > &variables) const;

  virtual Result get(const AnyAtomicType::Ptr &key) const;
  virtual bool contains(const AnyAtomicType::Ptr &key) const;
  virtual Result entries(const LocationInfo *location) const;
  virtual Tuple::Ptr put(const AnyAtomicType::Ptr &key, const Result &value) const;
  virtual Tuple::Ptr remove(const AnyAtomicType::Ptr &key) const;
  virtual size_t size() const;

  virtual ATQNameOrDerived::Ptr getName(const DynamicContext *context) const;
  virtual size_t getNumArgs() const;
  virtual const FunctionSignature *getSignature() const;
  virtual Result execute(const VectorOfResults &args, DynamicContext *context, const LocationInfo *location) const;
  virtual FunctionRef::Ptr partialApply(const Result &arg, unsigned int argNum, DynamicContext *context, const LocationInfo *location) const;

  virtual const XMLCh *asString(const DynamicContext *context) const;

  virtual void generateEvents(EventHandler *events, const DynamicContext *context,
                              bool preserveNS, bool preserveType) const;

  virtual void typeToBuffer(DynamicContext *context, XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buffer) const;

  virtual void *getInterface(const XMLCh *name) const;

protected:
  ValueMap values_;
  mutable FunctionSignature *signature_;
  XPath2MemoryManager *mm_;
};
#endif
