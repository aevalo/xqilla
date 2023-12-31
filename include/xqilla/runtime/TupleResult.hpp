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

#ifndef TUPLERESULT_HPP
#define TUPLERESULT_HPP

#include <xqilla/ast/LocationInfo.hpp>
#include <xqilla/context/VariableStore.hpp>
#include <xqilla/framework/ReferenceCounted.hpp>
#include <xqilla/items/impl/TupleImpl.hpp>

class DynamicContext;

class XQILLA_API TupleResult : public VariableStore, public LocationInfo, public ReferenceCounted
{
public:
  typedef RefCountPointer<TupleResult> Ptr;

  virtual ~TupleResult() {}

  virtual bool next(DynamicContext *context) = 0;

  virtual Tuple::Ptr getTuple(DynamicContext *context) const
  {
    TupleImpl::Ptr result;
    createTuple(context, 0, result);
    return result;
  }

  virtual void createTuple(DynamicContext *context, size_t capacity, TupleImpl::Ptr &result) const = 0;

protected:
  TupleResult(const LocationInfo *location)
  {
    setLocationInfo(location);
  }
};

#endif
