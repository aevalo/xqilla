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

#ifndef _FUNCFACTORY_HPP
#define _FUNCFACTORY_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/ASTNode.hpp>

#include <xercesc/framework/XMLBuffer.hpp>

class XQILLA_API FuncFactory
{
public:
  FuncFactory(const XMLCh *uri, const XMLCh *name, size_t minArgs, size_t maxArgs,
              XPath2MemoryManager *mm);
  FuncFactory(size_t numArgs, XPath2MemoryManager *mm);
  virtual ~FuncFactory() {}

  ///Create instance of a function, using FuncFactoryTemplate to determine type
  virtual ASTNode *createInstance(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr) const = 0;

  const XMLCh *getURI() const { return uri_; }
  const XMLCh *getName() const { return name_; }
  const XMLCh *getURIName() const { return uriname_; }
  void setURIName(const XMLCh *uri, const XMLCh *name, XPath2MemoryManager *mm);
  size_t getMinArgs() const { return minArgs_; }
  size_t getMaxArgs() const { return maxArgs_; }

protected:
  FuncFactory(const XMLCh *uri, const XMLCh *name, size_t minArgs, size_t maxArgs,
              const XMLCh *uriname);

  const XMLCh *uri_, *name_;
  size_t minArgs_, maxArgs_;
  const XMLCh *uriname_;
};

class XQILLA_API SimpleBuiltinFactory : public FuncFactory
{
public:
  enum Flags {
    NUMERIC             = 1<<0,
    NAMESPACE_SENSITIVE = 1<<1
  };

  typedef Result (*ResultFunc) (const VectorOfASTNodes &args, DynamicContext *context,
                                const LocationInfo *info);

  SimpleBuiltinFactory(const XMLCh *uri, const XMLCh *name, unsigned args,
                       const char *signature, ResultFunc result,
                       unsigned staticAnalysisFlags = 0,
                       unsigned flags = 0);

  virtual ASTNode *createInstance(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr) const;

  static const SimpleBuiltinFactory *&getAll();
  const SimpleBuiltinFactory *getNext() const { return next_; }

protected:
  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer buf_;
  const char *signature_;
  ResultFunc result_;
  unsigned staticAnalysisFlags_;
  unsigned flags_;

  const SimpleBuiltinFactory *next_;

  friend class SimpleBuiltin;
};

#endif

