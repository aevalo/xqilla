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

#ifndef _FLOOKUP_HPP
#define _FLOOKUP_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/utils/HashMap.hpp>

#include <vector>
#include <xercesc/util/XercesDefs.hpp>
#include <xqilla/ast/ASTNode.hpp>

class FuncFactory;
class XPath2MemoryManager;
class ExternalFunction;
class DynamicContext;

class XQILLA_API FunctionLookup
{
public:
  FunctionLookup(XPath2MemoryManager* memMgr);
  ~FunctionLookup();

  ///adds a function to the custom function table
  void insertFunction(const FuncFactory *func);
  /// Remove a function
  void removeFunction(const FuncFactory *func);
  ///returns the approriate Function object
  ASTNode* lookUpFunction(const XMLCh* URI, const XMLCh* fname,
                          const VectorOfASTNodes &args,
                          XPath2MemoryManager* memMgr) const;

  ///adds a function to the external function table
  void insertExternalFunction(const ExternalFunction *func);
  ///returns the approriate ExternalFunction object
  const ExternalFunction *lookUpExternalFunction(const XMLCh* URI,
                                                 const XMLCh* fname,
                                                 size_t numArgs) const;
  void copyExternalFunctionsTo(DynamicContext *context) const;

  void insertUpdateFunctions(XPath2MemoryManager *memMgr);

private:
  typedef HashMap<const XMLCh*, const FuncFactory*> FuncMap;
  typedef HashMap<const XMLCh*, const ExternalFunction*> ExFuncMap;
  FuncMap _funcTable;
  ExFuncMap _exFuncTable;

public:
  // static (global table interfaces)
  static void insertGlobalFunction(const FuncFactory *func);
  static void insertGlobalExternalFunction(const ExternalFunction *func);
  // next two look in global table first, then the contextTable
  static ASTNode* lookUpGlobalFunction(const XMLCh* URI, const XMLCh* fname,
                                       const VectorOfASTNodes &args,
                                       XPath2MemoryManager* memMgr,
                                       const FunctionLookup *contextTable);
  static const ExternalFunction *lookUpGlobalExternalFunction(const XMLCh* URI, const XMLCh* fname, size_t numArgs,
                                                              const FunctionLookup *contextTable);
  static void initialize();
  static void terminate();
private:
  static FunctionLookup *g_globalFunctionTable;
  static XPath2MemoryManager *g_memMgr;
};

#endif 
