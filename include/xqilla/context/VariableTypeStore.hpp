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

#ifndef _VARIABLETYPESTORE_HPP
#define _VARIABLETYPESTORE_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMemory.hpp>

class SequenceType;
class XPath2MemoryManager;
class StaticType;
class XQGlobalVariable;
class ArgumentSpec;

class XQILLA_API VariableType
{
public:
  VariableType(unsigned p, const StaticType *t, XQGlobalVariable *g)
    : properties(p), type(t), global(g) {}
  VariableType(const ArgumentSpec *aspec);

  unsigned properties;
  const StaticType *type;
  XQGlobalVariable *global;
};

/** This is the wrapper class for the variable store, which implements the 
    lookup and scoping of simple variables. */
class XQILLA_API VariableTypeStore : public XERCES_CPP_NAMESPACE_QUALIFIER XMemory
{
public:
  /** default destructor */
  virtual ~VariableTypeStore() {};

  /** Clears all variable values and added scopes from the store */
  virtual void clear() = 0;

  /** Adds a new local scope to the store. */
  virtual void addLocalScope() = 0;
  /** Adds a new logical block scope to the store. */
  virtual void addLogicalBlockScope() = 0;
  /** Removes the top level scope from the store. To be called at the end of methods to
      implement scoping. */
  virtual void removeScope() = 0;

  /** Declares a variable in the global scope. */
  virtual void declareGlobalVar(const XMLCh* namespaceURI, const XMLCh* name,
                                const VariableType &vtype) = 0;

  /** Declare a var in the top level scope */
  virtual void declareVar(const XMLCh* namespaceURI, const XMLCh* name,
                          const VariableType &vtype) = 0;

  /** Looks up the value of a variable in the current scope, using ident as an
      qname. */
  virtual const VariableType *getVar(const XMLCh* namespaceURI, const XMLCh* name) const = 0;
};

#endif
