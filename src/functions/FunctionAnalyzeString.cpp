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
#include <xqilla/functions/FunctionAnalyzeString.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/exceptions/FunctionException.hpp>
#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/ast/XQAnalyzeString.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/items/FunctionRef.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>
#include <xqilla/events/SequenceBuilder.hpp>
#include <xqilla/runtime/ClosureResult.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

#include <set>

using namespace std;
XERCES_CPP_NAMESPACE_USE;

struct AnalyzeRegion
{
  AnalyzeRegion(int s, int e, int g)
    : start(s), end(e), group(g) {}

  int start, end, group;

  bool operator<(const AnalyzeRegion &o) const
  {
    if(start != o.start) return start < o.start;
    if(end != o.end) return end > o.end;
    return group < o.group;
  }
};

static const XMLCh s_analyze_string_result[] = { 'a', 'n', 'a', 'l', 'y', 'z', 'e', '-', 's', 't', 'r', 'i',
                                                 'n', 'g', '-', 'r', 'e', 's', 'u', 'l', 't', 0 };
static const XMLCh s_non_match[] = { 'n', 'o', 'n', '-', 'm', 'a', 't', 'c', 'h', 0 };
static const XMLCh s_match[] = { 'm', 'a', 't', 'c', 'h', 0 };
static const XMLCh s_group[] = { 'g', 'r', 'o', 'u', 'p', 0 };
static const XMLCh s_nr[] = { 'n', 'r', 0 };

static int analyze_string_events(const XMLCh *input, int start, set<AnalyzeRegion>::iterator &it,
                                 const set<AnalyzeRegion>::iterator &end, EventHandler *handler)
{
  const AnalyzeRegion &region = *it;

  const XMLCh *name;
  switch(region.group) {
  case -1: name = s_non_match; break;
  case 0: name = s_match; break;
  default: name = s_group; break;
  }

  if(start < region.start)
    handler->textEvent(input + start, region.start - start);

  handler->startElementEvent(0, XQFunction::XMLChFunctionURI, name);
  if(region.group > 0) {
    XMLBuffer buf;
    XPath2Utils::numToBuf(region.group, buf);
    handler->attributeEvent(0, 0, s_nr, buf.getRawBuffer(), 0, 0);
  }

  start = region.start;
  ++it;
  while(it != end && it->start < region.end) {
    start = analyze_string_events(input, start, it, end, handler);
  }

  if(start < region.end)
    handler->textEvent(input + start, region.end - start);

  handler->endElementEvent(0, XQFunction::XMLChFunctionURI, name, 0, 0);

  return region.end;
}

static Result analyze_string(const VectorOfASTNodes &args, DynamicContext *context,
                             const LocationInfo *info)
{
  Item::Ptr inputItem = args[0]->createResult(context)->next(context);
  if(inputItem.isNull()) return 0;
  const XMLCh *input = inputItem->asString(context);
  const XMLCh *pattern = args[1]->createResult(context)->next(context)->asString(context);
  const XMLCh *flags = args.size() == 2 ? XMLUni::fgZeroLenString :
    args[2]->createResult(context)->next(context)->asString(context);

  XPath2MemoryManager *mm = context->getMemoryManager();
  RefVectorOf<Match> matches(10, true);
  AnalyzeStringResult::getMatches(input, pattern, flags, mm, info, matches);

  set<AnalyzeRegion> regions;
  int tokStart = 0;
  unsigned int i = 0;
  for(; i < matches.size(); ++i) {
    Match *match = matches.elementAt(i);
    for(int j = 0; j < match->getNoGroups(); ++j) {
      int matchStart = match->getStartPos(j);
      int matchEnd = match->getEndPos(j);
      if(matchStart < 0) continue;
      if(j == 0 && tokStart < matchStart)
        regions.insert(AnalyzeRegion(tokStart, matchStart, -1));
      regions.insert(AnalyzeRegion(matchStart, matchEnd, j));
      if(matchEnd > tokStart) tokStart = matchEnd;
    }
  }
  int length = (int)XMLString::stringLen(input);
  if(tokStart < (int)length)
    regions.insert(AnalyzeRegion(tokStart, length, -1));

  AutoDelete<SequenceBuilder> builder(context->createSequenceBuilder());
  builder->startElementEvent(0, XQFunction::XMLChFunctionURI, s_analyze_string_result);

  int start = 0;
  set<AnalyzeRegion>::iterator it = regions.begin();
  set<AnalyzeRegion>::iterator end = regions.end();
  while(it != end) {
    start = analyze_string_events(input, start, it, end, builder.get());
  }

  builder->endElementEvent(0, XQFunction::XMLChFunctionURI, s_analyze_string_result, 0, 0);
  builder->endEvent();
  return builder->getSequence();
}

static SimpleBuiltinFactory analyzeStringFactory(
  XQFunction::XMLChFunctionURI, FunctionXQillaAnalyzeString::name, 2,
  "($input as xs:string?, $pattern as xs:string, $flags as xs:string) "
  "as element(fn:analyze-string-result)", analyze_string,
  StaticAnalysis::CREATIVE
);

static SimpleBuiltinFactory analyzeStringFactory2(
  XQFunction::XMLChFunctionURI, FunctionXQillaAnalyzeString::name, 3,
  "($input as xs:string?, $pattern as xs:string, $flags as xs:string) "
  "as element(fn:analyze-string-result)", analyze_string,
  StaticAnalysis::CREATIVE
);

////////////////////////////////////////////////////////////////////////////////////////////////////

const XMLCh FunctionXQillaAnalyzeString::name[] = {
  chLatin_a, chLatin_n, chLatin_a, chLatin_l, chLatin_y, chLatin_z, chLatin_e, chDash, chLatin_s, chLatin_t, chLatin_r, chLatin_i, chLatin_n, chLatin_g, chNull 
};
const unsigned int FunctionXQillaAnalyzeString::minArgs = 3;
const unsigned int FunctionXQillaAnalyzeString::maxArgs = 4;

/**
 * xqilla:analyze-string($input as xs:string?, $pattern as xs:string,
 *   $action as function(xs:string, xs:boolean) as item()*) as item()*
 * xqilla:analyze-string($input as xs:string?, $pattern as xs:string,
 *   $action as function(xs:string, xs:boolean) as item()*, $flags as xs:string) as item()*
 */
FunctionXQillaAnalyzeString::FunctionXQillaAnalyzeString(const VectorOfASTNodes &args, XPath2MemoryManager* memMgr)
  : XQillaFunction(name, "($input as xs:string?, $pattern as xs:string, "
                   "$action as function(xs:string, xs:boolean) as item()*, $flags as xs:string) as item()*", args, memMgr)
{
}

ASTNode *FunctionXQillaAnalyzeString::staticTypingImpl(StaticContext *context)
{
  _src.clearExceptType();
  _src.setProperties(0);
  calculateSRCForArguments(context);

  // TBD Precompile the regex - jpcs

  _src.getStaticType() = StaticType::EMPTY;

  const StaticType::ItemTypes &types = _args[2]->getStaticAnalysis().getStaticType().getTypes();
  StaticType::ItemTypes::const_iterator i = types.begin();
  for(; i != types.end(); ++i) {
    if((*i)->getItemTestType() == ItemType::TEST_FUNCTION) {
      if((*i)->getFunctionSignature()) {
        if((*i)->getFunctionSignature()->numArgs() == 2) {
          StaticType tmp((*i)->getFunctionSignature()->returnType, BasicMemoryManager::get());
          _src.getStaticType().typeUnion(tmp);
        }
      } else {
        _src.getStaticType() = StaticType::ITEM_STAR;
        break;
      }
    }
  }

  _src.getStaticType().setCardinality(0, StaticType::UNLIMITED);

  return this;
}

class FunctionXQillaAnalyzeStringResult : public AnalyzeStringResult
{
public:
  FunctionXQillaAnalyzeStringResult(const FunctionXQillaAnalyzeString *ast)
    : AnalyzeStringResult(ast),
      ast_(ast),
      func_(0)
  {
  }

  const XMLCh *getInput(DynamicContext *context)
  {
    return ast_->getParamNumber(1, context)->next(context)->asString(context);
  }

  const XMLCh *getPattern(DynamicContext *context)
  {
    return ast_->getParamNumber(2, context)->next(context)->asString(context);
  }

  const XMLCh *getFlags(DynamicContext *context)
  {
    if(ast_->getNumArgs() == 4)
      return ast_->getParamNumber(4, context)->next(context)->asString(context);
    return XMLUni::fgZeroLenString;
  }

  Result getMatchResult(const XMLCh *matchString, size_t matchPos,
                        size_t numberOfMatches, bool match, DynamicContext *context)
  {
    if(func_.isNull())
      func_ = (FunctionRef*)ast_->getParamNumber(3, context)->next(context).get();

    VectorOfResults args;
    args.push_back(Result(context->getItemFactory()->createString(matchString, context)));
    args.push_back(Result(context->getItemFactory()->createBoolean(match, context)));

    return func_->execute(args, context, this);
  }

private:
  const FunctionXQillaAnalyzeString *ast_;
  FunctionRef::Ptr func_;
};

Result FunctionXQillaAnalyzeString::createResult(DynamicContext* context, int flags) const
{
  return ClosureResult::create(getStaticAnalysis(), context, new FunctionXQillaAnalyzeStringResult(this));
}
