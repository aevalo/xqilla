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

#ifndef XQFUNCTIONCALL_HPP
#define XQFUNCTIONCALL_HPP

#include <xqilla/ast/ASTNodeImpl.hpp>

class XQILLA_API XQFunctionCall : public ASTNodeImpl
{
public:
  XQFunctionCall(const XMLCh *qname, VectorOfASTNodes *args, XPath2MemoryManager *mm);
  XQFunctionCall(const XMLCh *prefix, const XMLCh *uri, const XMLCh *name, VectorOfASTNodes *args, XPath2MemoryManager *mm);

  virtual ASTNode* staticResolution(StaticContext *context);
  virtual ASTNode *staticTypingImpl(StaticContext *context);

  virtual Result createResult(DynamicContext* context, int flags=0) const;

  const XMLCh *getPrefix() const { return prefix_; }
  const XMLCh *getURI() const { return uri_; }
  const XMLCh *getName() const { return name_; }
  const VectorOfASTNodes *getArguments() const { return args_; }

private:
  const XMLCh *prefix_;
  const XMLCh *uri_;
  const XMLCh *name_;
  VectorOfASTNodes *args_;
};

#endif
