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

#include "../config/xqilla_config.h"
#include <xqilla/functions/FunctionBaseURI.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/Node.hpp>
#include <xqilla/items/DatatypeFactory.hpp>
#include <xqilla/exceptions/FunctionException.hpp>
#include <xqilla/ast/XQContextItem.hpp>

XERCES_CPP_NAMESPACE_USE;

const XMLCh FunctionBaseURI::name[] = {
  chLatin_b, chLatin_a, chLatin_s, 
  chLatin_e, chDash,    chLatin_u, 
  chLatin_r, chLatin_i, chNull 
};
const unsigned int FunctionBaseURI::minArgs = 0;
const unsigned int FunctionBaseURI::maxArgs = 1;

/**
 * fn:base-uri() as xs:anyURI?
 * fn:base-uri($arg as node()?) as xs:anyURI?
**/

FunctionBaseURI::FunctionBaseURI(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : XQFunction(name, "($arg as node()?) as xs:anyURI?", args, memMgr)
{
}

ASTNode* FunctionBaseURI::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  if(_args.empty()) {
    XQContextItem *ci = new (mm) XQContextItem(mm);
    ci->setLocationInfo(this);
    _args.push_back(ci);
  }

  resolveArguments(context);
  return this;
}

Sequence FunctionBaseURI::createSequence(DynamicContext* context, int flags) const
{
  Node::Ptr node = (Node*)getParamNumber(1, context)->next(context).get();
  if(node.isNull()) return Sequence(context->getMemoryManager());
  return node->dmBaseURI(context);
}
