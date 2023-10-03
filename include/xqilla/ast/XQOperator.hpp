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

#ifndef _XQOPERATOR_HPP
#define _XQOPERATOR_HPP

#include <xqilla/ast/ASTNodeImpl.hpp>

class XQILLA_API XQOperator : public ASTNodeImpl
{
public:
  XQOperator(whichType type, const XMLCh *opName, const VectorOfASTNodes &args, XPath2MemoryManager* memMgr);

  /** used to manipulate arguments */
  void addArgument(ASTNode *arg);
  void removeArgument(unsigned int index);
  ASTNode *getArgument(unsigned int index) const;
  void setArgument(unsigned int index, ASTNode *arg);

  /** returns the number of parameters passed into the operator */
  unsigned int getNumArgs() const;

  virtual const XMLCh* getOperatorName() const { return _opName; }
  const VectorOfASTNodes &getArguments() const;

  static bool isInstance(ASTNode *ast);
  
protected:
  VectorOfASTNodes _args;
  const XMLCh *_opName;
};

#endif
