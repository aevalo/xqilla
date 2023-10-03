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

#include "../config/xqilla_config.h"
#include <xqilla/items/ExpressionItem.hpp>
#include <xqilla/events/EventSerializer.hpp>
#include <xqilla/events/NSFixupFilter.hpp>
#include <xqilla/optimizer/ASTToXML.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/utils/XStr.hpp>
#include "../lexer/XQLexer.hpp"

#include <xercesc/framework/MemBufFormatTarget.hpp>

XERCES_CPP_NAMESPACE_USE;

void ExpressionItem::generateEvents(EventHandler *events, const DynamicContext *context,
                                    bool preserveNS, bool preserveType) const
{
  ASTToXML().run(ast_, events, context);
}

const XMLCh *ExpressionItem::asString(const DynamicContext *context) const
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  MemBufFormatTarget mbuf(1023, mm);
  EventSerializer writer((char*)"UTF-16", (char*)"1.1", &mbuf, mm);
  NSFixupFilter nsfilter(&writer, mm);

  generateEvents(&nsfilter, context, false, false);

  return mm->getPooledString((const XMLCh*)mbuf.getRawBuffer());
}

void ExpressionItem::typeToBuffer(DynamicContext *context, XMLBuffer &buffer) const
{
  buffer.append(X("rw:expression"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result exprIsConstant(const VectorOfASTNodes &args, DynamicContext *context,
                             const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  return (Item::Ptr)context->getItemFactory()->createBoolean(((ExpressionItem*)item.get())->
    getExpression()->isConstant(), context);
}

static const XMLCh exprIsConstantName[] =
{ 'i', 's', '-', 'c', 'o', 'n', 's', 't', 'a', 'n', 't', 0 };

static SimpleBuiltinFactory exprIsConstantFactory(XQRewriteRule::URI, exprIsConstantName, 1,
  "($arg as rw:expression) as xs:boolean", exprIsConstant);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result exprUsesFocus(const VectorOfASTNodes &args, DynamicContext *context,
                            const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  return (Item::Ptr)context->getItemFactory()->createBoolean(((ExpressionItem*)item.get())->
    getExpression()->getStaticAnalysis().areContextFlagsUsed(), context);
}

static const XMLCh exprUsesFocusName[] =
{ 'u', 's', 'e', 's', '-', 'f', 'o', 'c', 'u', 's', 0 };

static SimpleBuiltinFactory exprUsesFocusFactory(XQRewriteRule::URI, exprUsesFocusName, 1,
  "($arg as rw:expression) as xs:boolean", exprUsesFocus);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result expression(const VectorOfASTNodes &args, DynamicContext *context,
                         const LocationInfo *info)
{
  return Item::Ptr(new ExpressionItem(args[0]));
}

static const XMLCh expressionName[] =
{ 'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory expressionFactory(XQRewriteRule::URI, expressionName, 1,
  "($arg as item()*) as rw:expression", expression);

////////////////////////////////////////////////////////////////////////////////////////////////////

static SequenceType::TypeMatch exprSequenceTypeMatches(ASTNode *exprArg, ASTNode *typeArg,
  DynamicContext *context, const LocationInfo *info)
{
  Item::Ptr typeStr = typeArg->createResult(context)->next(context);

  // TBD release the SequenceType object - jpcs
  SequenceType *seqType;
  {
    XQLexer lexer(context->getMemoryManager(), _LANG_SEQUENCE_TYPE_,
                  XMLUni::fgZeroLenString, 1, 0, typeStr->asString(context));
    XQParserArgs args(&lexer);
    XQParser::yyparse(&args);
    seqType = args._seqType;
  }

  seqType->staticResolution(context);

  Item::Ptr item = exprArg->createResult(context)->next(context);
  return seqType->matches(((ExpressionItem*)item.get())->
    getExpression()->getStaticAnalysis().getStaticType());
}

static Result exprSubtype(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  SequenceType::TypeMatch match = exprSequenceTypeMatches(args[0], args[1], context, info);
  return (Item::Ptr)context->getItemFactory()->createBoolean(
    match.type == SequenceType::ALWAYS && match.cardinality == SequenceType::ALWAYS, context);
}

static const XMLCh exprSubtypeName[] =
{ 's', 'u', 'b', 't', 'y', 'p', 'e', 0 };

static SimpleBuiltinFactory exprSubtypeFactory(XQRewriteRule::URI, exprSubtypeName, 2,
  "($e as rw:expression, $type as xs:string) as xs:boolean", exprSubtype, 0,
  SimpleBuiltinFactory::NAMESPACE_SENSITIVE);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result exprNeverSubtype(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  SequenceType::TypeMatch match = exprSequenceTypeMatches(args[0], args[1], context, info);
  return (Item::Ptr)context->getItemFactory()->createBoolean(
    match.type == SequenceType::NEVER || match.cardinality == SequenceType::NEVER, context);
}

static const XMLCh exprNeverSubtypeName[] =
{ 'n', 'e', 'v', 'e', 'r', '-', 's', 'u', 'b', 't', 'y', 'p', 'e', 0 };

static SimpleBuiltinFactory exprNeverSubtypeFactory(XQRewriteRule::URI, exprNeverSubtypeName, 2,
  "($e as rw:expression, $type as xs:string) as xs:boolean", exprNeverSubtype, 0,
  SimpleBuiltinFactory::NAMESPACE_SENSITIVE);

