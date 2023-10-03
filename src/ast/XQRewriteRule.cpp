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

#include <stdlib.h>

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/XQRewriteRule.hpp>
#include <xqilla/ast/XQEffectiveBooleanValue.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/XStr.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/optimizer/ASTVisitor.hpp>
#include <xqilla/utils/UTF8Str.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/ExpressionItem.hpp>
#include <xqilla/runtime/Result.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/optimizer/ASTToXML.hpp>
#include "../lexer/XQLexer.hpp"

XERCES_CPP_NAMESPACE_USE;
using namespace std;

/* http://xqilla.sourceforge.net/rewrite */
const XMLCh XQRewriteRule::URI[] =
{ 'h', 't', 't', 'p', ':', '/', '/', 'x', 'q', 'i', 'l', 'l', 'a', '.', 's', 'o', 'u', 'r', 'c', 'e', 'f', 'o', 'r', 'g', 'e', '.', 'n', 'e', 't', '/', 'r', 'e', 'w', 'r', 'i', 't', 'e', 0 };

const XMLCh XQRewriteRule::TypeName[] =
{ 'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', 0 };

class WhereExprSubstReplacer : public ASTVisitor
{
public:

  ASTNode *run(ASTNode *where, XPath2MemoryManager *mm)
  {
    mm_ = mm;
    return ASTVisitor::optimize(where);
  }

protected:
  virtual ASTNode *optimizeExprSubstitution(XQExprSubstitution *item)
  {
    ASTNode *result = new (mm_) XQTupleMember(item->getQName(), item->getURI(), item->getName(), mm_);
    result->setLocationInfo(item);
    return result;
  }

  XPath2MemoryManager *mm_;
};

void XQRewriteRule::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  if(name_ == 0) {
    uri_ = context->getUriBoundToPrefix(XPath2NSUtils::getPrefix(qname_, mm), this);
    name_ = XPath2NSUtils::getLocalName(qname_);
  }

  pattern_ = pattern_->staticResolution(context);
  if(where_) {
    where_ = new (mm) XQEffectiveBooleanValue(where_, mm);
    where_->setLocationInfo(this);
    where_ = where_->staticResolution(context);
    where_ = WhereExprSubstReplacer().run(where_, mm);
  }

  RewriteCase::Vector::iterator i = cases_.begin();
  for(; i != cases_.end(); ++i) {
    (*i)->staticResolution(context);
  }
}

void XQRewriteRule::staticTyping(StaticContext *context, StaticTyper *styper)
{
  if(where_) {
    AutoContextItemTypeReset contextTypeReset(context, StaticType::TUPLE);
    where_ = where_->staticTyping(context, styper);
  }

  RewriteCase::Vector::iterator i = cases_.begin();
  for(; i != cases_.end(); ++i) {
    (*i)->staticTyping(context, styper);
  }
}

ASTNode *XQRewriteRule::apply(const ASTNode *item, DynamicContext *context) const
{
  const XMLCh s_this[] = { 't', 'h', 'i', 's', 0 };

  // std::cerr << UTF8(item->getFile()) << ":" << item->getLine()
  //           << ":" << item->getColumn() << " trying {"
  //           << UTF8(uri_) << "}" << UTF8(name_) << std::endl;

  // Check if the pattern matches
  TupleImpl::Ptr tuple = new TupleImpl(context);
  if(!pattern_->matches(item, context, tuple.get()))
    return 0;

  // std::cerr << UTF8(item->getFile()) << ":" << item->getLine()
  //           << ":" << item->getColumn() << " pattern matches {"
  //           << UTF8(uri_) << "}" << UTF8(name_) << std::endl;

  // Add the "this" entry
  tuple->add(0, s_this, Item::Ptr(new ExpressionItem(item)), context);

  if(where_) {
    // Check the where clause
    AutoContextInfoReset ciReset(context);
    context->setContextItem(tuple);
    if(((ATBooleanOrDerived*)where_->createResult(context)->next(context).get())->isFalse())
      return 0;
  }

  // std::cerr << UTF8(item->getFile()) << ":" << item->getLine()
  //           << ":" << item->getColumn() << " rule where passes {"
  //           << UTF8(uri_) << "}" << UTF8(name_) << std::endl;

  // Loop over the cases, trying to apply them in turn
  RewriteCase::Vector::const_iterator j = cases_.begin();
  for(; j != cases_.end(); ++j) {
    ASTNode *apply = (*j)->apply(this, context, tuple.get());
    if(apply) {
      // std::cerr << UTF8(item->getFile()) << ":" << item->getLine()
      //           << ":" << item->getColumn() << " applied {"
      //           << UTF8(uri_) << "}" << UTF8(name_) << std::endl;
      // std::cerr << "Before: " << ASTToXML().print(item, context) << std::endl;
      // std::cerr << "After: " << ASTToXML().print(apply, context) << std::endl;
      return apply;
    }
  }

  return 0;
}

XQRewriteRule *XQRewriteRule::parse(const XMLCh *rulestr, XPath2MemoryManager *mm,
                                    const LocationInfo *info)
{
  XQLexer lexer(mm, _LANG_REWRITE_RULE_, info->getFile(), info->getLine(),
                info->getColumn(), rulestr);
  XQParserArgs args(&lexer);
  args._rewriteRule = true;
  XQParser::yyparse(&args);
  return args._rwrule;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void RewritePattern::release(XPath2MemoryManager *mm)
{
  Vector::iterator i = children.begin();
  for(; i != children.end(); ++i) {
    (*i)->release(mm);
  }
#if defined(_MSC_VER) && (_MSC_VER < 1300)
  children.~vector<RewritePattern*,XQillaAllocator<RewritePattern*> >();
#else
  children.~Vector();
#endif

  mm->deallocate(this);
}

RewritePattern *RewritePattern::staticResolution(StaticContext *context)
{
  static const XMLCh s_true[] = { 't', 'r', 'u', 'e', 0 };
  static const XMLCh s_false[] = { 'f', 'a', 'l', 's', 'e', 0 };
  static const XMLCh s_boolean[] = { 'b', 'o', 'o', 'l', 'e', 'a', 'n', 0 };

  switch(type) {
  case ASTNode::FUNCTION:
    if(name == 0) {
      const XMLCh *prefix = XPath2NSUtils::getPrefix(value, context->getMemoryManager());
      if(prefix == 0 || *prefix == 0) {
        uri = context->getDefaultFuncNS();
      }
      else {
        uri = context->getUriBoundToPrefix(prefix, this);
      }
      name = XPath2NSUtils::getLocalName(value);
    }
    // Convert known functions to ASTNode enumerations
    if(XPath2Utils::equals(uri, XQFunction::XMLChFunctionURI)) {
      if(XPath2Utils::equals(name, s_true)) {
        type = ASTNode::LITERAL;
        primitiveType = AnyAtomicType::BOOLEAN;
        value = s_true;
      }
      else if(XPath2Utils::equals(name, s_false)) {
        type = ASTNode::LITERAL;
        primitiveType = AnyAtomicType::BOOLEAN;
        value = s_false;
      }
      else if(XPath2Utils::equals(name, s_boolean)) {
        type = ASTNode::EBV;
      }
    }
    break;
  case ASTNode::EXPR_SUBSTITUTION:
    if(name == 0) {
      uri = context->getUriBoundToPrefix(XPath2NSUtils::getPrefix(value, context->getMemoryManager()), this);
      name = XPath2NSUtils::getLocalName(value);
    }
    break;
  default:
    break;
  }

  Vector::iterator i = children.begin();
  for(; i != children.end(); ++i) {
    (*i) = (*i)->staticResolution(context);
  }

  switch(type) {
  case ASTNode::SEQUENCE:
    if(children.size() == 1)
      return children[0];
    break;
  default:
    break;
  }

  return this;
}

void RewritePattern::typesMatched(vector<ASTNode::whichType> &types) const
{
  switch(type) {
  case ASTNode::GREATER_THAN:
  case ASTNode::LESS_THAN:
    types.push_back(ASTNode::GREATER_THAN);
    types.push_back(ASTNode::LESS_THAN);
    break;
  case ASTNode::GREATER_THAN_EQUAL:
    types.push_back(ASTNode::GREATER_THAN_EQUAL);
    types.push_back(ASTNode::LESS_THAN_EQUAL);
    break;
  case ASTNode::FUNCTION:
    types.push_back(ASTNode::FUNCTION);
    types.push_back(ASTNode::USER_FUNCTION);
    break;    
  default:
    types.push_back(type);
    break;
  }
}

bool RewritePattern::matches(const ASTNode *ast, DynamicContext *context,
                             TupleImpl *subs) const
{
  if(type == ASTNode::EXPR_SUBSTITUTION) {
    if(subs) {
      subs->add(uri, name, Item::Ptr(new ExpressionItem(ast)), context);
    }
    return true;
  }
  if(ast == 0) return false;

  switch(type) {
  case ASTNode::IF: {
    if(type != ast->getType()) return false;
    XQIf *iff = (XQIf*)ast;
    return children[0]->matches(iff->getTest(), context, subs) &&
      children[1]->matches(iff->getWhenTrue(), context, subs) &&
      children[2]->matches(iff->getWhenFalse(), context, subs);
  }
  case ASTNode::PREDICATE: {
    if(type != ast->getType()) return false;
    XQPredicate *pred = (XQPredicate*)ast;
    return children[0]->matches(pred->getExpression(), context, subs) &&
      children[1]->matches(pred->getPredicate(), context, subs);
  }
  case ASTNode::SEQUENCE: {
    if(children.empty())
      return ast->getStaticAnalysis().getStaticType().getMax() == 0;

    if(type != ast->getType()) return false;

    VectorOfASTNodes::const_iterator j = ((XQSequence*)ast)->
      getChildren().begin();
    Vector::const_iterator i = children.begin();
    for(; i != children.end(); ++i, ++j) {
      if(j == ((XQSequence*)ast)->getChildren().end() ||
         !(*i)->matches(*j, context, subs)) return false;
    }
    return j == ((XQSequence*)ast)->getChildren().end();
  }
  case ASTNode::FUNCTION: {
    if(ast->getType() != ASTNode::FUNCTION &&
       ast->getType() != ASTNode::USER_FUNCTION) return false;

    XQFunction *func = (XQFunction*)ast;
    if(!XPath2Utils::equals(uri, func->getFunctionURI()) ||
       !XPath2Utils::equals(name, func->getFunctionName()))
      return false;

    VectorOfASTNodes::const_iterator j = func->getArguments().begin();
    Vector::const_iterator i = children.begin();
    for(; i != children.end(); ++i, ++j) {
      if(j == func->getArguments().end() ||
         !(*i)->matches(*j, context, subs)) return false;
    }
    return true;
  }
  case ASTNode::OR:
  case ASTNode::AND: {
    if(type != ast->getType()) return false;

    // TBD Args in any permutation - jpcs
    VectorOfASTNodes::const_iterator j = ((XQOperator*)ast)->
      getArguments().begin();
    Vector::const_iterator i = children.begin();
    for(; i != children.end(); ++i, ++j) {
      if(j == ((XQOperator*)ast)->getArguments().end() ||
         !(*i)->matches(*j, context, subs)) return false;
    }
    return true;
  }
  case ASTNode::PLUS:
  case ASTNode::MULTIPLY:
  case ASTNode::EQUALS:
  case ASTNode::NOT_EQUALS: {
    if(type != ast->getType()) return false;
    XQOperator *op = (XQOperator*)ast;
    return (children[0]->matches(op->getArguments()[0], context, subs) &&
            children[1]->matches(op->getArguments()[1], context, subs)) ||
      (children[0]->matches(op->getArguments()[1], context, subs) &&
       children[1]->matches(op->getArguments()[0], context, subs));
  }
  case ASTNode::GREATER_THAN: {
    if(ast->getType() == ASTNode::GREATER_THAN)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[0], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[1], context, subs));
    if(ast->getType() == ASTNode::LESS_THAN)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[1], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[0], context, subs));
    return false;
  }
  case ASTNode::GREATER_THAN_EQUAL: {
    if(ast->getType() == ASTNode::GREATER_THAN_EQUAL)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[0], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[1], context, subs));
    if(ast->getType() == ASTNode::LESS_THAN_EQUAL)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[1], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[0], context, subs));
    return false;
  }
  case ASTNode::LESS_THAN: {
    if(ast->getType() == ASTNode::LESS_THAN)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[0], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[1], context, subs));
    if(ast->getType() == ASTNode::GREATER_THAN)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[1], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[0], context, subs));
    return false;
  }
  case ASTNode::LESS_THAN_EQUAL: {
    if(ast->getType() == ASTNode::LESS_THAN_EQUAL)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[0], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[1], context, subs));
    if(ast->getType() == ASTNode::GREATER_THAN_EQUAL)
      return (children[0]->matches(((XQOperator*)ast)->getArguments()[1], context, subs) &&
              children[1]->matches(((XQOperator*)ast)->getArguments()[0], context, subs));
    return false;
  }

  case ASTNode::UNARY_MINUS: {
    if(type != ast->getType()) return false;
    XQOperator *op = (XQOperator*)ast;
    return children[0]->matches(op->getArguments()[0], context, subs);
  }

  case ASTNode::MINUS:
  case ASTNode::DIVIDE:
  case ASTNode::INTEGER_DIVIDE:
  case ASTNode::MOD: {
    if(type != ast->getType()) return false;
    XQOperator *op = (XQOperator*)ast;
    return children[0]->matches(op->getArguments()[0], context, subs) &&
      children[1]->matches(op->getArguments()[1], context, subs);
  }

  case ASTNode::LITERAL: {
    Item::Ptr lit;
    if(ast->getType() == ASTNode::LITERAL) {
      if(((XQLiteral*)ast)->getItemType()->getPrimitiveType() != primitiveType)
        return false;
      lit = ast->createResult(context)->next(context);
    }
    else if(ast->getType() == ASTNode::NUMERIC_LITERAL) {
      if(((XQNumericLiteral*)ast)->getItemType()->getPrimitiveType() != primitiveType)
        return false;
      lit = ast->createResult(context)->next(context);
    }
    else if(ast->isConstant()) {
      Result result = ast->createResult(context);
      lit = result->next(context);
      if(lit.isNull() || result->next(context).notNull() || lit->getType() != Item::ATOMIC ||
         ((AnyAtomicType*)lit.get())->getPrimitiveTypeIndex() != primitiveType)
        return false;
    }
    else return false;

    AnyAtomicType::Ptr myval = context->getItemFactory()->
      createDerivedFromAtomicType(primitiveType, value, context).get();
    return myval->equals((AnyAtomicType*)lit.get(), context);
  }

  case ASTNode::EBV: {
    if(type != ast->getType()) return false;
    return children[0]->matches(((XQEffectiveBooleanValue*)ast)->getExpression(), context, subs);
  }

  default:
    return true;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void RewriteCase::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  result = result->staticResolution(context);

  if(where) {
    ASTNode *ebv = new (mm) XQEffectiveBooleanValue(where, mm);
    ebv->setLocationInfo(where);
    where = ebv;
    where = where->staticResolution(context);
    where = WhereExprSubstReplacer().run(where, mm);
  }
}

void RewriteCase::staticTyping(StaticContext *context, StaticTyper *styper)
{
  result = result->staticTyping(context, styper);

  if(where) {
    AutoContextItemTypeReset contextTypeReset(context, StaticType::TUPLE);
    where = where->staticTyping(context, styper);
  }
}

class RewriteExprSubstReplacer : public ASTVisitor
{
public:

  ASTNode *run(ASTNode *replacement, DynamicContext *context, const TupleImpl *subs)
  {
    context_ = context;
    subs_ = subs;
    return ASTVisitor::optimize(replacement);
  }

protected:
  virtual ASTNode *optimizeExprSubstitution(XQExprSubstitution *expr)
  {
    Result result(0);
    subs_->get(expr->getURI(), expr->getName(), context_, result);
    Item::Ptr item = result->next(context_);
    if(item.isNull() || item->getType() != Item::EXPRESSION) {
      XMLBuffer buf;
      buf.set(X("Substitute expression not found: {"));
      buf.append(expr->getURI());
      buf.append(X("}"));
      buf.append(expr->getName());
      XQThrow3(StaticErrorException, X("RewriteCase::apply"), buf.getRawBuffer(), expr);
    }
    return ((ExpressionItem*)item.get())->getExpression()->copy(context_);
  }

  DynamicContext *context_;
  const TupleImpl *subs_;
};

ASTNode *RewriteCase::apply(const XQRewriteRule *rule, DynamicContext *context, const TupleImpl *subs) const
{
  if(where) {
    // Check the where clause
    AutoContextInfoReset ciReset(context);
    context->setContextItem(subs);
    if(((ATBooleanOrDerived*)where->createResult(context)->
        next(context).get())->isFalse()) return 0;
  }

  ASTNode *replacement = result->copy(context);
  replacement = RewriteExprSubstReplacer().run(replacement, context, subs);

  // std::cerr << "Applying rule: {" << UTF8(rule->uri_) << "}" << UTF8(rule->name_) << std::endl;

  return replacement->staticTyping(0, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

static bool exprPatternMatch(ASTNode *patternarg, ASTNode *exprarg,
                             DynamicContext *context, TupleImpl *tuple = 0)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  const XMLCh *patternstr = patternarg->createResult(context)->next(context)->asString(context);
  AutoRelease2<RewritePattern> pattern(0, mm);

  {
    XQLexer rwlexer(mm, _LANG_REWRITE_PATTERN_, XMLUni::fgZeroLenString,
                    1, 0, patternstr);
    XQParserArgs pargs(&rwlexer);
    pargs._rewriteRule = true;
    XQParser::yyparse(&pargs);
    pattern.set(pargs._rwpattern);
  }

  pattern.set(pattern->staticResolution(context));

  Item::Ptr expr = exprarg->createResult(context)->next(context);
  return pattern->matches(((ExpressionItem*)expr.get())->getExpression(),
                          context, tuple);
}

static Result exprMatches(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  return (Item::Ptr)context->getItemFactory()->createBoolean(
    exprPatternMatch(args[0], args[1], context), context);
}

static const XMLCh exprMatchesName[] =
{ 'm', 'a', 't', 'c', 'h', 'e', 's', 0 };

static SimpleBuiltinFactory exprMatchesFactory(XQRewriteRule::URI, exprMatchesName, 2,
  "($pattern as xs:string, $e as rw:expression) as xs:boolean", exprMatches);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result exprAnalyze(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  TupleImpl::Ptr tuple = new TupleImpl(context);
  exprPatternMatch(args[0], args[1], context, tuple.get());
  return Item::Ptr(tuple.get());
}

static const XMLCh exprAnalyzeName[] =
{ 'a', 'n', 'a', 'l', 'y', 'z', 'e', 0 };

static SimpleBuiltinFactory exprAnalyzeFactory(XQRewriteRule::URI, exprAnalyzeName, 2,
  "($pattern as xs:string, $e as rw:expression) as tuple()", exprAnalyze);

