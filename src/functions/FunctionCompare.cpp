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
#include <xqilla/functions/FunctionCompare.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/Collation.hpp>
#include <xqilla/context/impl/CodepointCollation.hpp>
#include <xqilla/exceptions/FunctionException.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/items/ATDecimalOrDerived.hpp>
#include <xqilla/items/ATAnyURIOrDerived.hpp>
#include <xqilla/items/ATStringOrDerived.hpp>
#include <xqilla/items/DatatypeFactory.hpp>
#include <xqilla/context/ItemFactory.hpp>

XERCES_CPP_NAMESPACE_USE;

const XMLCh FunctionCompare::name[] = {
  chLatin_c, chLatin_o, chLatin_m, 
  chLatin_p, chLatin_a, chLatin_r, 
  chLatin_e, chNull 
};
const unsigned int FunctionCompare::minArgs = 2;
const unsigned int FunctionCompare::maxArgs = 3;

/**
 * fn:compare($comparand1 as xs:string?, $comparand2 as xs:string?) as xs:integer?
 * fn:compare($comparand1 as xs:string?, $comparand2 as xs:string?, $collation as xs:string) as xs:integer?
**/

FunctionCompare::FunctionCompare(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : XQFunction(name, "($comparand1 as xs:string?, $comparand2 as xs:string?, $collation as xs:string) as xs:integer?", args, memMgr)
{
}

Result FunctionCompare::createResult(DynamicContext* context, int flags) const
{
  Item::Ptr str1 = getParamNumber(1,context)->next(context);
  Item::Ptr str2 = getParamNumber(2,context)->next(context);
  if(str1.isNull() || str2.isNull())
    return 0;

  Collation* collation;
  if(getNumArgs()>2) collation = context->getCollation(getParamNumber(3,context)->
    next(context)->asString(context), this);
  else collation = context->getDefaultCollation(this);

  return (Item::Ptr)context->getMemoryManager()->createInteger(collation->
    compare(str1->asString(context), str2->asString(context)));
}
