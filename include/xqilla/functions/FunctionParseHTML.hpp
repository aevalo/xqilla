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

#ifndef _FUNCTIONPARSEHTML_HPP
#define _FUNCTIONPARSEHTML_HPP

#include <xqilla/functions/XQillaFunction.hpp>

class QueryPathNode;

class XQILLA_API FunctionParseHTML : public XQillaFunction
{
public:
  static const XMLCh name[];
  static const unsigned int minArgs;
  static const unsigned int maxArgs;

  FunctionParseHTML(const VectorOfASTNodes &args, XPath2MemoryManager *memMgr);
  
  virtual ASTNode *staticTypingImpl(StaticContext *context);

  Sequence createSequence(DynamicContext* context, int flags=0) const;

  QueryPathNode *getQueryPathTree() const { return queryPathTree_; }
  void setQueryPathTree(QueryPathNode *q) { queryPathTree_ = q; }

  static void parseHTML(const XMLCh *html, EventHandler *handler,
                        DynamicContext *context, const LocationInfo *location);

private:
  QueryPathNode *queryPathTree_;
};

#endif
