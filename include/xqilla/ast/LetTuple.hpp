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

#ifndef LETTUPLE_HPP
#define LETTUPLE_HPP

#include <xqilla/ast/TupleNode.hpp>
#include <xqilla/functions/FunctionSignature.hpp>

#include <xercesc/framework/XMLBuffer.hpp>

class ASTNode;

class XQILLA_API LetTuple : public TupleNode
{
public:
  LetTuple(TupleNode *parent, const XMLCh *varQName, ASTNode *expr, XPath2MemoryManager *mm);
  LetTuple(TupleNode *parent, const XMLCh *uri, const XMLCh *name, ASTNode *expr, XPath2MemoryManager *mm);
  LetTuple(TupleNode *parent, const ArgumentSpec *var, ASTNode *expr, XPath2MemoryManager *mm);

  const XMLCh *getVarQName() const { return var_->getQName(); }
  const XMLCh *getVarURI() const { return var_->getURI(); }
  const XMLCh *getVarName() const { return var_->getName(); }
  const ArgumentSpec *getVar() const { return var_; }

  void setVarURI(const XMLCh *uri) { var_->setURI(uri); }
  void setVarName(const XMLCh *name) { var_->setName(name); }

  ASTNode *getExpression() const { return expr_; }
  void setExpression(ASTNode *expr) { expr_ = expr; }

  virtual TupleNode *staticResolution(StaticContext *context);
  virtual TupleNode *staticTypingImpl(StaticContext *context);

  virtual TupleResult::Ptr createResult(DynamicContext* context) const;

private:
  ArgumentSpec *var_;
  ASTNode *expr_;
};

#endif
