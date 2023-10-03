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

#include <xqilla/ast/XQExprSubstitution.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/context/StaticContext.hpp>

XERCES_CPP_NAMESPACE_USE;

XQExprSubstitution::XQExprSubstitution(const XMLCh *qname, XPath2MemoryManager *mm)
  : ASTNodeImpl(EXPR_SUBSTITUTION, mm),
    qname_(qname),
    uri_(0),
    name_(0)
{
}

XQExprSubstitution::XQExprSubstitution(const XMLCh *qname, const XMLCh *uri,
  const XMLCh *name, XPath2MemoryManager *mm)
  : ASTNodeImpl(EXPR_SUBSTITUTION, mm),
    qname_(qname),
    uri_(uri),
    name_(name)
{
}

ASTNode *XQExprSubstitution::staticResolution(StaticContext *context) 
{
  if(name_ == 0) {
    uri_ = context->getUriBoundToPrefix(XPath2NSUtils::getPrefix(qname_, context->getMemoryManager()), this);
    name_ = XPath2NSUtils::getLocalName(qname_);
  }

  return this;
}

ASTNode *XQExprSubstitution::staticTypingImpl(StaticContext *context)
{
  _src.clear();
  _src.getStaticType() = StaticType::ITEM_STAR;
  _src.addFlags(StaticAnalysis::USED);
  return this;
}

Result XQExprSubstitution::createResult(DynamicContext* context, int flags) const
{
  // Should never happen
  return 0;
}
