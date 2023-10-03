/*
 * Copyright (c) 2001, 2008,
 *     DecisionSoft Limited. All rights reserved.
 * Copyright (c) 2004, 2010,
 *     Oracle and/or its affiliates. All rights reserved.
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

#include "../config/xqilla_config.h"
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/ast/XQFunction.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/context/ContextHelpers.hpp>

#include <stdlib.h>

XERCES_CPP_NAMESPACE_USE;

FuncFactory::FuncFactory(const XMLCh *uri, const XMLCh *name, size_t minArgs, size_t maxArgs,
                         XPath2MemoryManager *mm)
  : uri_(uri),
    name_(name),
    minArgs_(minArgs),
    maxArgs_(maxArgs),
    uriname_(0)
{
  setURIName(uri, name, mm);
}

FuncFactory::FuncFactory(const XMLCh *uri, const XMLCh *name, size_t minArgs, size_t maxArgs,
                         const XMLCh *uriname)
  : uri_(uri),
    name_(name),
    minArgs_(minArgs),
    maxArgs_(maxArgs),
    uriname_(uriname)
{
}

FuncFactory::FuncFactory(size_t numArgs, XPath2MemoryManager *mm)
  : uri_(0),
    name_(0),
    minArgs_(numArgs),
    maxArgs_(numArgs),
    uriname_(0)
{
}

void FuncFactory::setURIName(const XMLCh *uri, const XMLCh *name, XPath2MemoryManager *mm)
{
  uri_ = uri;
  name_ = name;
  uriname_ = XPath2NSUtils::makeURIName(uri, name, mm);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

SimpleBuiltinFactory::SimpleBuiltinFactory(const XMLCh *uri, const XMLCh *name,
  unsigned args, const char *signature, ResultFunc result,
  unsigned staticAnalysisFlags, unsigned flags)
  : FuncFactory(uri, name, args, args, (const XMLCh*)0),
    buf_(1023, BasicMemoryManager::get()),
    signature_(signature),
    result_(result),
    staticAnalysisFlags_(staticAnalysisFlags),
    flags_(flags),
    next_(getAll())
{
  XPath2NSUtils::makeURIName(uri, name, buf_);
  uriname_ = buf_.getRawBuffer();

  // Build a simple static linked list of the SimpleBuiltinFactory instances
  getAll() = this;
}

const SimpleBuiltinFactory *&SimpleBuiltinFactory::getAll()
{
  static const SimpleBuiltinFactory *all = 0;
  return all;
}

class SimpleBuiltin : public XQFunction
{
public:
  SimpleBuiltin(const SimpleBuiltinFactory *sbf, const VectorOfASTNodes &args,
    XPath2MemoryManager *mm)
    : XQFunction(sbf->name_, sbf->signature_, args, mm),
      sbf_(sbf)
  {
    uri_ = sbf->uri_;
  }

  virtual ASTNode *staticResolution(StaticContext *context)
  {
    resolveArguments(context, sbf_->flags_ & SimpleBuiltinFactory::NUMERIC);
    return this;
  }

  virtual ASTNode *staticTypingImpl(StaticContext *context)
  {
    _src.clearExceptType();
    calculateSRCForArguments(context);
    _src.addFlags(sbf_->staticAnalysisFlags_);
    return this;
  }

  virtual Result createResult(DynamicContext* context, int flags) const
  {
    return sbf_->result_(_args, context, this);
  }

private:
  const SimpleBuiltinFactory *sbf_;
};

class NamespaceSensitiveBuiltin : public SimpleBuiltin
{
public:
  NamespaceSensitiveBuiltin(const SimpleBuiltinFactory *sbf, const VectorOfASTNodes &args,
                            XPath2MemoryManager *mm)
    : SimpleBuiltin(sbf, args, mm),
      resolver_(0)
  {
  }

  virtual ASTNode *staticResolution(StaticContext *context)
  {
    SimpleBuiltin::staticResolution(context);
    resolver_ = const_cast<DOMXPathNSResolver*>(context->getNSResolver());
    return this;
  }

  virtual Result createResult(DynamicContext* context, int flags) const
  {
    AutoNsScopeReset jan(context, resolver_);
    return SimpleBuiltin::createResult(context, flags);
  }

private:
  DOMXPathNSResolver *resolver_;
};

ASTNode *SimpleBuiltinFactory::createInstance(const VectorOfASTNodes &args,
  XPath2MemoryManager* memMgr) const
{
  if(flags_ & NAMESPACE_SENSITIVE)
    return new (memMgr) NamespaceSensitiveBuiltin(this, args, memMgr);
  return new (memMgr) SimpleBuiltin(this, args, memMgr);
}
