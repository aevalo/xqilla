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

#include <xqilla/debug/DebugHookDecorator.hpp>
#include <xqilla/context/DynamicContext.hpp>

DebugHookDecorator::DebugHookDecorator(DynamicContext *context, Optimizer *parent)
  : ASTVisitor(parent),
    mm_(context->getMemoryManager())
{
}

ASTNode *DebugHookDecorator::optimize(ASTNode *item)
{
  return new (mm_) ASTDebugHook(ASTVisitor::optimize(item), mm_);
}

TupleNode *DebugHookDecorator::optimizeTupleNode(TupleNode *item)
{
  return new (mm_) TupleDebugHook(ASTVisitor::optimizeTupleNode(item), mm_);
}

