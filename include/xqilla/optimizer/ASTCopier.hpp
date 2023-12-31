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

#ifndef _ASTCOPIER_HPP
#define _ASTCOPIER_HPP

#include <xqilla/optimizer/ASTVisitor.hpp>

class XQILLA_API ASTCopier : public ASTVisitor
{
public:
  ASTCopier();

  ASTNode *copy(const ASTNode *item, DynamicContext *context);
  TupleNode *copy(const TupleNode *item, DynamicContext *context);

protected:
  ALL_ASTVISITOR_METHODS();

  DynamicContext *context_;
  XPath2MemoryManager *mm_;
};

#endif
