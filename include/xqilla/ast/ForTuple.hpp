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

#ifndef FORTUPLE_HPP
#define FORTUPLE_HPP

#include <xqilla/ast/TupleNode.hpp>
#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/functions/FunctionSignature.hpp>

class ASTNode;

class XQILLA_API ForTuple : public TupleNode
{
public:
  ForTuple(TupleNode *parent, const XMLCh *varQName, const XMLCh *posQName, ASTNode *expr,
           XPath2MemoryManager *mm);
  ForTuple(TupleNode *parent, const ArgumentSpec *var, const ArgumentSpec *pos,
           ASTNode *expr, XPath2MemoryManager *mm);

  const XMLCh *getVarQName() const { return var_ ? var_->getQName() : 0; }
  const XMLCh *getVarURI() const { return var_ ? var_->getURI() : 0; }
  const XMLCh *getVarName() const { return var_ ? var_->getName() : 0; }
  const ArgumentSpec *getVar() const { return var_; }

  const XMLCh *getPosQName() const { return pos_ ? pos_->getQName() : 0; }
  const XMLCh *getPosURI() const { return pos_ ? pos_->getURI() : 0; }
  const XMLCh *getPosName() const { return pos_ ? pos_->getName() : 0; }
  const ArgumentSpec *getPos() const { return pos_; }

  ASTNode *getExpression() const { return expr_; }
  void setExpression(ASTNode *expr) { expr_ = expr; }

  virtual TupleNode *staticResolution(StaticContext *context);
  virtual TupleNode *staticTypingImpl(StaticContext *context);

  virtual TupleResult::Ptr createResult(DynamicContext* context) const;

private:
  ArgumentSpec *var_, *pos_;
  ASTNode *expr_;
};

#endif
