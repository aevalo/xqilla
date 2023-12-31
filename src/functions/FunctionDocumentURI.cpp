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
#include <xqilla/functions/FunctionDocumentURI.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/Node.hpp>

const XMLCh FunctionDocumentURI::name[] = { 
  XERCES_CPP_NAMESPACE_QUALIFIER chLatin_d, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_o, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_c, 
  XERCES_CPP_NAMESPACE_QUALIFIER chLatin_u, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_m, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_e, 
  XERCES_CPP_NAMESPACE_QUALIFIER chLatin_n, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_t, XERCES_CPP_NAMESPACE_QUALIFIER chDash, 
  XERCES_CPP_NAMESPACE_QUALIFIER chLatin_u, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_r, XERCES_CPP_NAMESPACE_QUALIFIER chLatin_i, 
  XERCES_CPP_NAMESPACE_QUALIFIER chNull 
};
const unsigned int FunctionDocumentURI::minArgs = 1;
const unsigned int FunctionDocumentURI::maxArgs = 1;

/*
 * fn:document-uri($arg as node()?) as xs:anyURI?
 */

FunctionDocumentURI::FunctionDocumentURI(const VectorOfASTNodes  &args, XPath2MemoryManager* memMgr)
  : XQFunction(name, "($arg as node()?) as xs:anyURI?", args, memMgr)
{
}

Sequence FunctionDocumentURI::createSequence(DynamicContext* context, int flags) const
{
  Item::Ptr arg = getParamNumber(1,context)->next(context);
  if(arg.isNull())
    return Sequence(context->getMemoryManager());
  return ((Node*)arg.get())->dmDocumentURI(context);
}
