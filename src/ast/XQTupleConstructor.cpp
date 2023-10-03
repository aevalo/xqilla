/*
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

#include <xqilla/ast/XQTupleConstructor.hpp>
#include <xqilla/ast/TupleNode.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/optimizer/ASTVisitor.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/runtime/ClosureResult.hpp>

XQTupleConstructor::XQTupleConstructor(TupleNode *parent, XPath2MemoryManager *mm)
  : ASTNodeImpl(TUPLE_CONSTRUCTOR, mm),
    parent_(parent)
{
}

ASTNode *XQTupleConstructor::staticResolution(StaticContext *context)
{
  parent_ = parent_->staticResolution(context);

  return this;
}

ASTNode *XQTupleConstructor::staticTypingImpl(StaticContext *context)
{
  _src.clear();
  _src.copy(parent_->getStaticAnalysis());
  return this;
}

class TupleConstructorResult : public ResultImpl
{
public:
  TupleConstructorResult(const XQTupleConstructor *ast, const TupleResult::Ptr parent)
    : ResultImpl(ast),
      parent_(parent)
  {
  }

  virtual Item::Ptr next(DynamicContext *context)
  {
    if(!parent_->next(context)) {
      parent_ = 0;
      return 0;
    }
    return parent_->getTuple(context);
  }

private:
  TupleResult::Ptr parent_;
};

Result XQTupleConstructor::createResult(DynamicContext* context, int flags) const
{
  return ClosureResult::create(getStaticAnalysis(), context,
    new TupleConstructorResult(this, parent_->createResult(context)));
}
