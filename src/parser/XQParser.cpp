
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 20 "../src/parser/XQParser.y"


#if defined(WIN32) && !defined(__CYGWIN__)
// turn off the warnings "switch statement contains 'default' but no 'case' labels"
//                       "'yyerrlab1' : unreferenced label"
#pragma warning(disable : 4065 4102)
#endif

#include <cstdio>
#include <iostream>
#include <sstream>

#include <xqilla/utils/UTF8Str.hpp>

#include "../lexer/XQLexer.hpp"

#include <xqilla/simple-api/XQQuery.hpp>
#include <xqilla/ast/XQFunction.hpp>
#include <xqilla/ast/XQDocumentConstructor.hpp>
#include <xqilla/ast/XQElementConstructor.hpp>
#include <xqilla/ast/XQAttributeConstructor.hpp>
#include <xqilla/ast/XQNamespaceConstructor.hpp>
#include <xqilla/ast/XQPIConstructor.hpp>
#include <xqilla/ast/XQCommentConstructor.hpp>
#include <xqilla/ast/XQTextConstructor.hpp>
#include <xqilla/ast/XQQuantified.hpp>
#include <xqilla/ast/XQTypeswitch.hpp>
#include <xqilla/ast/XQValidate.hpp>
#include <xqilla/ast/XQGlobalVariable.hpp>
#include <xqilla/ast/XQTypeAlias.hpp>
#include <xqilla/ast/XQRewriteRule.hpp>
#include <xqilla/ast/XQFunctionCall.hpp>
#include <xqilla/ast/XQExprSubstitution.hpp>
#include <xqilla/ast/XQOrderingChange.hpp>
#include <xqilla/ast/XQDocumentOrder.hpp>
#include <xqilla/ast/XQReturn.hpp>
#include <xqilla/ast/XQTupleConstructor.hpp>
#include <xqilla/ast/XQTupleMember.hpp>
#include <xqilla/ast/XQNamespaceBinding.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>
#include <xercesc/dom/DOMXPathNSResolver.hpp>

#include <xqilla/ast/XQSequence.hpp>
#include <xqilla/ast/XQNav.hpp>
#include <xqilla/ast/XQStep.hpp>
#include <xqilla/ast/XQLiteral.hpp>
#include <xqilla/ast/XQVariable.hpp>
#include <xqilla/ast/XQCastAs.hpp>
#include <xqilla/ast/XQCastableAs.hpp>
#include <xqilla/ast/XQTreatAs.hpp>
#include <xqilla/ast/XQFunctionConversion.hpp>
#include <xqilla/ast/XQAnalyzeString.hpp>
#include <xqilla/ast/XQCopyOf.hpp>
#include <xqilla/ast/XQCopy.hpp>
#include <xqilla/ast/XQAtomize.hpp>
#include <xqilla/ast/ConvertFunctionArg.hpp>
#include <xqilla/ast/XQIf.hpp>
#include <xqilla/ast/XQContextItem.hpp>
#include <xqilla/ast/XQPredicate.hpp>
#include <xqilla/ast/XQApplyTemplates.hpp>
#include <xqilla/ast/XQInlineFunction.hpp>
#include <xqilla/ast/XQFunctionDeref.hpp>
#include <xqilla/ast/XQFunctionRef.hpp>
#include <xqilla/ast/XQPartialApply.hpp>
#include <xqilla/ast/XQMap.hpp>

#include <xqilla/fulltext/FTContains.hpp>
#include <xqilla/fulltext/FTOr.hpp>
#include <xqilla/fulltext/FTAnd.hpp>
#include <xqilla/fulltext/FTMildnot.hpp>
#include <xqilla/fulltext/FTUnaryNot.hpp>
#include <xqilla/fulltext/FTOrder.hpp>
#include <xqilla/fulltext/FTDistance.hpp>
#include <xqilla/fulltext/FTScope.hpp>
#include <xqilla/fulltext/FTContent.hpp>
#include <xqilla/fulltext/FTWindow.hpp>

#include <xqilla/update/UDelete.hpp>
#include <xqilla/update/URename.hpp>
#include <xqilla/update/UReplace.hpp>
#include <xqilla/update/UReplaceValueOf.hpp>
#include <xqilla/update/UInsertAsFirst.hpp>
#include <xqilla/update/UInsertAsLast.hpp>
#include <xqilla/update/UInsertInto.hpp>
#include <xqilla/update/UInsertAfter.hpp>
#include <xqilla/update/UInsertBefore.hpp>
#include <xqilla/update/UTransform.hpp>
#include <xqilla/update/UApplyUpdates.hpp>

#include <xqilla/ast/ContextTuple.hpp>
#include <xqilla/ast/ForTuple.hpp>
#include <xqilla/ast/LetTuple.hpp>
#include <xqilla/ast/WhereTuple.hpp>
#include <xqilla/ast/OrderByTuple.hpp>
#include <xqilla/ast/CountTuple.hpp>

#include <xqilla/parser/QName.hpp>

#include <xqilla/operators/Equals.hpp>
#include <xqilla/operators/GeneralComp.hpp>
#include <xqilla/operators/NotEquals.hpp>
#include <xqilla/operators/LessThan.hpp>
#include <xqilla/operators/GreaterThan.hpp>
#include <xqilla/operators/LessThanEqual.hpp>
#include <xqilla/operators/GreaterThanEqual.hpp>
#include <xqilla/operators/Plus.hpp>
#include <xqilla/operators/Minus.hpp>
#include <xqilla/operators/Multiply.hpp>
#include <xqilla/operators/Divide.hpp>
#include <xqilla/operators/IntegerDivide.hpp>
#include <xqilla/operators/Mod.hpp>
#include <xqilla/operators/UnaryMinus.hpp>
#include <xqilla/operators/NodeComparison.hpp>
#include <xqilla/operators/OrderComparison.hpp>
#include <xqilla/operators/Intersect.hpp>
#include <xqilla/operators/Except.hpp>
#include <xqilla/operators/Union.hpp>
#include <xqilla/operators/Or.hpp>
#include <xqilla/operators/And.hpp>

#include <xqilla/functions/FunctionRoot.hpp>
#include <xqilla/functions/FunctionId.hpp>
#include <xqilla/functions/XQillaFunction.hpp>
#include <xqilla/functions/BuiltInModules.hpp>

#include <xqilla/axis/NodeTest.hpp>

#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/exceptions/NamespaceLookupException.hpp>
#include <xqilla/exceptions/ContextException.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>

#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/UTF8Str.hpp>
#include "../config/xqilla_config.h"

#define YYPARSE_PARAM qp
#define YYDEBUG 1
#define YYERROR_VERBOSE

// this removes a memory leak occurring when an error is found in the query (we throw an exception from inside
// yyerror, preventing the bison-generated code from cleaning up the memory); by defining this macro we use 
// stack-based memory instead of the heap
#define YYSTACK_USE_ALLOCA  1
#if HAVE_ALLOCA_H
#include <alloca.h>
#elif defined __GNUC__
#undef alloca
#define alloca __builtin_alloca
#elif defined _AIX
#define alloca __alloca
#elif defined _MSC_VER
#include <malloc.h>
#else
#include <stddef.h>
#ifdef __cplusplus
extern "C"
#endif
void *alloca (size_t);
#endif

#define QP       ((XQParserArgs*)qp)
#define CONTEXT  (QP->_context)
#define LANGUAGE (QP->_lexer->getLanguage())
#define MEMMGR   (QP->_lexer->getMemoryManager())

#define REJECT_NOT_XQUERY(where,pos)    if(!QP->_lexer->isXQuery()) { yyerror(LANGUAGE, #where, (pos).first_line, (pos).first_column); }
#define REJECT_NOT_VERSION3(where,pos) if(!QP->_lexer->isVersion3()) { yyerror(LANGUAGE, #where, (pos).first_line, (pos).first_column); }

#define WRAP(pos,object)        (wrapForDebug((QP), (object), (pos).first_line, (pos).first_column))

#define LOCATION(pos,name) LocationInfo name(QP->_lexer->getFile(), (pos).first_line, (pos).first_column)

#define GET_NAVIGATION(pos, object) (((object)->getType() == ASTNode::NAVIGATION) ? (XQNav*)(object) : WRAP(pos, new (MEMMGR) XQNav((object), MEMMGR)))

#define PRESERVE_NS(pos, object) (QP->_lexer->getNSResolver() == 0 ? (object) : WRAP((pos), new (MEMMGR) XQNamespaceBinding(QP->_lexer->getNSResolver(), (object), MEMMGR)))

#define BIT_ORDERING_SPECIFIED                  0
#define BIT_BOUNDARY_SPECIFIED                  1
#define BIT_COLLATION_SPECIFIED                 2
#define BIT_BASEURI_SPECIFIED                   3
#define BIT_CONSTRUCTION_SPECIFIED              4
#define BIT_EMPTYORDERING_SPECIFIED             5
#define BIT_COPYNAMESPACE_SPECIFIED             6
#define BIT_DEFAULTELEMENTNAMESPACE_SPECIFIED   7
#define BIT_DEFAULTFUNCTIONNAMESPACE_SPECIFIED  8
#define BIT_DECLARE_SECOND_STEP                 9
#define BIT_REVALIDATION_SPECIFIED              10

#define CHECK_SECOND_STEP(pos, name) { \
  if(QP->_flags.get(BIT_DECLARE_SECOND_STEP)) \
    yyerror((pos), "Prolog contains " name " declaration after a variable, function or option declaration"); \
}

#define CHECK_SPECIFIED(pos, bit, name, error) { \
  if(QP->_flags.get(bit)) \
    yyerror((pos), "Prolog contains more than one " name " declaration [err:" error "]"); \
  QP->_flags.set(bit); \
}

#define SET_NAMESPACE(pos, prefix, uri) { \
  if(QP->_namespaceDecls.containsKey((prefix))) \
    yyerror((pos), "Namespace prefix has already been bound to a namespace [err:XQST0033]"); \
  QP->_namespaceDecls.put((prefix), NULL); \
  CONTEXT->setNamespaceBinding((prefix), (uri)); \
}

#undef yylex
#define yylex QP->_lexer->yylex
#undef yyerror
#define yyerror QP->_lexer->error

XERCES_CPP_NAMESPACE_USE;
using namespace std;

static const XMLCh sz1_0[] = { chDigit_1, chPeriod, chDigit_0, chNull };
static const XMLCh sz3_0[] = { chDigit_3, chPeriod, chDigit_0, chNull };
static const XMLCh option_projection[] = { 'p', 'r', 'o', 'j', 'e', 'c', 't', 'i', 'o', 'n', 0 };
static const XMLCh option_psvi[] = { 'p', 's', 'v', 'i', 0 };
static const XMLCh option_lint[] = { 'l', 'i', 'n', 't', 0 };
static const XMLCh option_extensions[] = { 'e', 'x', 't', 'e', 'n', 's', 'i', 'o', 'n', 's', 0 };
static const XMLCh option_rule[] = { 'r', 'u', 'l', 'e', 0 };
static const XMLCh var_name[] = { 'n', 'a', 'm', 'e', 0 };

static inline VectorOfASTNodes packageArgs(ASTNode *arg1Impl, ASTNode *arg2Impl, XPath2MemoryManager* memMgr)
{
  VectorOfASTNodes args=VectorOfASTNodes(2,(ASTNode*)NULL,XQillaAllocator<ASTNode*>(memMgr));
  args[0]=arg1Impl;
  args[1]=arg2Impl;

  return args;
}

static inline TupleNode *getLastAncestor(TupleNode *node)
{
  while(node->getParent()) node = const_cast<TupleNode*>(node->getParent());
  return node;
}

static inline TupleNode *setLastAncestor(TupleNode *node, TupleNode *ancestor)
{
  getLastAncestor(node)->setParent(ancestor);
  return node;
}

template<typename TYPE>
TYPE *wrapForDebug(XQParserArgs *qp, TYPE* pObjToWrap, unsigned int line, unsigned int column)
{
  if(pObjToWrap->getLine() == 0)
    pObjToWrap->setLocationInfo(QP->_lexer->getFile(), line, column);
  return pObjToWrap;
}

#define RESOLVE_QNAME(pos, qname) const XMLCh *uri, *name; resolveQName((pos), QP, (qname), uri, name)

static void resolveQName(const yyltype &pos, XQParserArgs *qp, const XMLCh *qname, const XMLCh *&uri, const XMLCh *&name)
{
  const XMLCh *prefix = XPath2NSUtils::getPrefix(qname, MEMMGR);
  name = XPath2NSUtils::getLocalName(qname);

  if(prefix == 0 || *prefix == 0) {
    uri = 0;
  }
  else {
    if(QP->_lexer->getNSResolver() == 0) {
      if(prefix == 0 || *prefix == 0)
        uri = CONTEXT->getDefaultElementAndTypeNS();
      else uri = CONTEXT->getNSResolver()->lookupNamespaceURI(prefix);
    }
    else {
      uri = QP->_lexer->getNSResolver()->lookupNamespaceURI(prefix);
    }

    if(uri == 0 || *uri == 0) {
      ostringstream oss;
      oss << "No namespace binding for prefix '" << UTF8(prefix) << "' [err:XTSE0280]";
      yyerror(pos, oss.str().c_str());
    }
  }
}

#define XSLT_VARIABLE_VALUE(pos, select, seqConstruct, seqType) variableValueXSLT((pos), QP, (select), (seqConstruct), (seqType))

static ASTNode *variableValueXSLT(const yyltype &pos, XQParserArgs *qp, ASTNode *select, XQSequence *seqConstruct, SequenceType *seqType)
{
  if(!seqConstruct->getChildren().empty()) {
    if(select != 0) return 0; // signifies an error
    
    if(seqType == 0) {
      return WRAP(pos, new (MEMMGR) XQDocumentConstructor(seqConstruct, MEMMGR));
    }

    return WRAP(pos, new (MEMMGR) XQFunctionConversion(seqConstruct, seqType, MEMMGR));
  }

  if(select != 0) {
    if(seqType == 0) return select;

    return WRAP(pos, new (MEMMGR) XQFunctionConversion(select, seqType, MEMMGR));
  }

  if(seqType == 0) {
    return WRAP(pos, new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING,
        XMLUni::fgZeroLenString, MEMMGR));
  }

  return WRAP(pos, new (MEMMGR) XQFunctionConversion(WRAP(pos, new (MEMMGR) XQSequence(MEMMGR)), seqType, MEMMGR));
}

static void DM_outputDecl(const char *type, const char *name, int size, bool privte, int line, int column, const XMLCh *body, int bodylen)
{
  XMLBuffer buf;
  printf("  {\n    DelayedModule::Decl::%s, \"%s\", %d, %s, %d, %d,\n", type, name, size,
         privte ? "true" : "false", line, column);
  printf("    \"");
  const XMLCh *ptr = body;
  const XMLCh *start = ptr;
  const XMLCh *end = body + bodylen;
  for(;ptr < end; ++ptr) {
    if(*ptr == '"') {
      if((ptr - start) == 0) buf.reset();
      else buf.set(start, ptr - start);
      printf("%s\\\"", UTF8(buf.getRawBuffer()));
      start = ptr + 1;
    }
    else if(*ptr == '\\') {
      if((ptr - start) == 0) buf.reset();
      else buf.set(start, ptr - start);
      printf("%s\\\\", UTF8(buf.getRawBuffer()));
      start = ptr + 1;
    }
    else if(*ptr == '\n') {
      if((ptr - start) == 0) buf.reset();
      else buf.set(start, ptr - start);
      printf("%s\\n\"\n    \"", UTF8(buf.getRawBuffer()));
      start = ptr + 1;
    }
  }
  buf.set(start, ptr - start);
  printf("%s\"\n", UTF8(buf.getRawBuffer()));
  printf("  },\n");
}

namespace XQParser {



/* Line 189 of yacc.c  */
#line 424 "../src/parser/XQParser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MYEOF = 0,
     _LANG_XPATH2_ = 258,
     _LANG_XQUERY_ = 259,
     _LANG_XSLT2_ = 260,
     _LANG_FUNCDECL_ = 261,
     _LANG_DELAYEDMODULE_ = 262,
     _LANG_FUNCTION_SIGNATURE_ = 263,
     _LANG_REWRITE_RULE_ = 264,
     _LANG_REWRITE_PATTERN_ = 265,
     _LANG_SEQUENCE_TYPE_ = 266,
     _LANG_CARROT_ = 267,
     _DOLLAR_ = 268,
     _COLON_EQUALS_ = 269,
     _ASTERISK_ = 270,
     _BAR_ = 271,
     _BANG_EQUALS_ = 272,
     _LESS_THAN_EQUALS_ = 273,
     _GREATER_THAN_ = 274,
     _GREATER_THAN_EQUALS_ = 275,
     _LESS_THAN_LESS_THAN_ = 276,
     _GREATER_THAN_GREATER_THAN_ = 277,
     _COLON_COLON_ = 278,
     _AT_SIGN_ = 279,
     _LSQUARE_ = 280,
     _RSQUARE_ = 281,
     _QUESTION_MARK_ = 282,
     _LESS_THAN_OP_OR_TAG_ = 283,
     _START_TAG_CLOSE_ = 284,
     _END_TAG_CLOSE_ = 285,
     _PI_START_ = 286,
     _XML_COMMENT_START_ = 287,
     _XML_COMMENT_END_ = 288,
     _SLASH_SLASH_ = 289,
     _END_TAG_OPEN_ = 290,
     _PRAGMA_OPEN_ = 291,
     _COMMA_ = 292,
     _PLUS_ = 293,
     _MINUS_ = 294,
     _SLASH_ = 295,
     _EQUALS_ = 296,
     _DOT_ = 297,
     _DOT_DOT_ = 298,
     _LPAR_ = 299,
     _RPAR_ = 300,
     _EMPTY_TAG_CLOSE_ = 301,
     _VALUE_INDICATOR_ = 302,
     _OPEN_QUOT_ = 303,
     _CLOSE_QUOT_ = 304,
     _OPEN_APOS_ = 305,
     _CLOSE_APOS_ = 306,
     _LBRACE_ = 307,
     _RBRACE_ = 308,
     _SEMICOLON_ = 309,
     _HASH_ = 310,
     _PERCENT_ = 311,
     _COLON_ = 312,
     _TILDE_ = 313,
     _MINUS_GREATER_THAN_ = 314,
     _BAR_BAR_ = 315,
     _BANG_ = 316,
     _CARROT_ = 317,
     _INTEGER_LITERAL_ = 318,
     _DECIMAL_LITERAL_ = 319,
     _DOUBLE_LITERAL_ = 320,
     _ATTRIBUTE_ = 321,
     _COMMENT_ = 322,
     _DOCUMENT_NODE_ = 323,
     _NAMESPACE_NODE_ = 324,
     _NODE_ = 325,
     _PROCESSING_INSTRUCTION_ = 326,
     _SCHEMA_ATTRIBUTE_ = 327,
     _SCHEMA_ELEMENT_ = 328,
     _TEXT_ = 329,
     _EMPTY_SEQUENCE_ = 330,
     _BOUNDARY_SPACE_ = 331,
     _FT_OPTION_ = 332,
     _BASE_URI_ = 333,
     _LAX_ = 334,
     _STRICT_ = 335,
     _IDIV_ = 336,
     _CHILD_ = 337,
     _DESCENDANT_ = 338,
     _SELF_ = 339,
     _DESCENDANT_OR_SELF_ = 340,
     _FOLLOWING_SIBLING_ = 341,
     _FOLLOWING_ = 342,
     _PARENT_ = 343,
     _ANCESTOR_ = 344,
     _PRECEDING_SIBLING_ = 345,
     _PRECEDING_ = 346,
     _ANCESTOR_OR_SELF_ = 347,
     _DOCUMENT_ = 348,
     _NOT_ = 349,
     _USING_ = 350,
     _NO_ = 351,
     _SENSITIVE_ = 352,
     _INSENSITIVE_ = 353,
     _DIACRITICS_ = 354,
     _WITHOUT_ = 355,
     _WITHOUT_C_ = 356,
     _STEMMING_ = 357,
     _THESAURUS_ = 358,
     _STOP_ = 359,
     _WILDCARDS_ = 360,
     _ENTIRE_ = 361,
     _CONTENT_ = 362,
     _WORD_ = 363,
     _TYPE_ = 364,
     _START_ = 365,
     _END_ = 366,
     _MOST_ = 367,
     _SKIP_ = 368,
     _COPY_ = 369,
     _VALUE_ = 370,
     _WHITESPACE_ = 371,
     _PI_CONTENT_ = 372,
     _XML_COMMENT_CONTENT_ = 373,
     _EQ_ = 374,
     _NE_ = 375,
     _LT_ = 376,
     _LE_ = 377,
     _GT_ = 378,
     _GE_ = 379,
     _AT_ = 380,
     _QUOT_ATTR_CONTENT_ = 381,
     _APOS_ATTR_CONTENT_ = 382,
     _WHITESPACE_ELEMENT_CONTENT_ = 383,
     _ELEMENT_CONTENT_ = 384,
     _AT_LM_ = 385,
     _ORDERED_ = 386,
     _UNORDERED_ = 387,
     _QNAME_ = 388,
     _XMLNS_QNAME_ = 389,
     _CONSTR_QNAME_ = 390,
     _STRING_LITERAL_ = 391,
     _VARIABLE_ = 392,
     _NCNAME_COLON_STAR_ = 393,
     _STAR_COLON_NCNAME_ = 394,
     _PI_TARGET_ = 395,
     _PRAGMA_CONTENT_ = 396,
     _RETURN_ = 397,
     _FOR_ = 398,
     _IN_ = 399,
     _LET_ = 400,
     _WHERE_ = 401,
     _COUNT_ = 402,
     _BY_ = 403,
     _ORDER_ = 404,
     _STABLE_ = 405,
     _ASCENDING_ = 406,
     _DESCENDING_ = 407,
     _EMPTY_ = 408,
     _GREATEST_ = 409,
     _LEAST_ = 410,
     _COLLATION_ = 411,
     _SOME_ = 412,
     _EVERY_ = 413,
     _SATISFIES_ = 414,
     _TYPESWITCH_ = 415,
     _CASE_ = 416,
     _CASE_S_ = 417,
     _AS_ = 418,
     _IF_ = 419,
     _THEN_ = 420,
     _ELSE_ = 421,
     _OR_ = 422,
     _AND_ = 423,
     _INSTANCE_ = 424,
     _OF_ = 425,
     _CASTABLE_ = 426,
     _TO_ = 427,
     _DIV_ = 428,
     _MOD_ = 429,
     _UNION_ = 430,
     _INTERSECT_ = 431,
     _EXCEPT_ = 432,
     _VALIDATE_ = 433,
     _CAST_ = 434,
     _TREAT_ = 435,
     _IS_ = 436,
     _PRESERVE_ = 437,
     _STRIP_ = 438,
     _NAMESPACE_ = 439,
     _ITEM_ = 440,
     _EXTERNAL_ = 441,
     _ENCODING_ = 442,
     _NO_PRESERVE_ = 443,
     _INHERIT_ = 444,
     _NO_INHERIT_ = 445,
     _DECLARE_ = 446,
     _CONSTRUCTION_ = 447,
     _ORDERING_ = 448,
     _DEFAULT_ = 449,
     _COPY_NAMESPACES_ = 450,
     _OPTION_ = 451,
     _XQUERY_ = 452,
     _VERSION_ = 453,
     _IMPORT_ = 454,
     _SCHEMA_ = 455,
     _MODULE_ = 456,
     _ELEMENT_ = 457,
     _FUNCTION_ = 458,
     _FUNCTION_EXT_ = 459,
     _SCORE_ = 460,
     _CONTAINS_ = 461,
     _WEIGHT_ = 462,
     _WINDOW_ = 463,
     _DISTANCE_ = 464,
     _OCCURS_ = 465,
     _TIMES_ = 466,
     _SAME_ = 467,
     _DIFFERENT_ = 468,
     _LOWERCASE_ = 469,
     _UPPERCASE_ = 470,
     _RELATIONSHIP_ = 471,
     _LEVELS_ = 472,
     _LANGUAGE_ = 473,
     _ANY_ = 474,
     _ALL_ = 475,
     _PHRASE_ = 476,
     _EXACTLY_ = 477,
     _FROM_ = 478,
     _WORDS_ = 479,
     _SENTENCES_ = 480,
     _PARAGRAPHS_ = 481,
     _SENTENCE_ = 482,
     _PARAGRAPH_ = 483,
     _REPLACE_ = 484,
     _MODIFY_ = 485,
     _FIRST_ = 486,
     _INSERT_ = 487,
     _BEFORE_ = 488,
     _AFTER_ = 489,
     _REVALIDATION_ = 490,
     _WITH_ = 491,
     _NODES_ = 492,
     _RENAME_ = 493,
     _LAST_ = 494,
     _DELETE_ = 495,
     _INTO_ = 496,
     _UPDATING_ = 497,
     _ID_ = 498,
     _KEY_ = 499,
     _TEMPLATE_ = 500,
     _MATCHES_ = 501,
     _TUPLE_ = 502,
     _MAP_ = 503,
     _NAME_ = 504,
     _CALL_ = 505,
     _APPLY_ = 506,
     _TEMPLATES_ = 507,
     _MODE_ = 508,
     _FTOR_ = 509,
     _FTAND_ = 510,
     _FTNOT_ = 511,
     _TYPE_ALIAS_ = 512,
     _XSLT_END_ELEMENT_ = 513,
     _XSLT_STYLESHEET_ = 514,
     _XSLT_TEMPLATE_ = 515,
     _XSLT_VALUE_OF_ = 516,
     _XSLT_TEXT_ = 517,
     _XSLT_APPLY_TEMPLATES_ = 518,
     _XSLT_CALL_TEMPLATE_ = 519,
     _XSLT_WITH_PARAM_ = 520,
     _XSLT_SEQUENCE_ = 521,
     _XSLT_PARAM_ = 522,
     _XSLT_FUNCTION_ = 523,
     _XSLT_CHOOSE_ = 524,
     _XSLT_WHEN_ = 525,
     _XSLT_OTHERWISE_ = 526,
     _XSLT_IF_ = 527,
     _XSLT_VARIABLE_ = 528,
     _XSLT_COMMENT_ = 529,
     _XSLT_PI_ = 530,
     _XSLT_DOCUMENT_ = 531,
     _XSLT_ATTRIBUTE_ = 532,
     _XSLT_NAMESPACE_ = 533,
     _XSLT_ELEMENT_ = 534,
     _XSLT_ANALYZE_STRING_ = 535,
     _XSLT_MATCHING_SUBSTRING_ = 536,
     _XSLT_NON_MATCHING_SUBSTRING_ = 537,
     _XSLT_COPY_OF_ = 538,
     _XSLT_COPY_ = 539,
     _XSLT_FOR_EACH_ = 540,
     _XSLT_OUTPUT_ = 541,
     _XSLT_IMPORT_SCHEMA_ = 542,
     _XSLT_TYPE_ALIAS_ = 543,
     _XSLT_VERSION_ = 544,
     _XSLT_MODE_ = 545,
     _XSLT_NAME_ = 546,
     _XSLT_DOCTYPE_PUBLIC_ = 547,
     _XSLT_DOCTYPE_SYSTEM_ = 548,
     _XSLT_ENCODING_ = 549,
     _XSLT_MEDIA_TYPE_ = 550,
     _XSLT_NORMALIZATION_FORM_ = 551,
     _XSLT_STANDALONE_ = 552,
     _XSLT_EXCLUDE_RESULT_PREFIXES_ = 553,
     _XSLT_NAMESPACE_STR_ = 554,
     _XSLT_SCHEMA_LOCATION_ = 555,
     _XSLT_TUNNEL_ = 556,
     _XSLT_REQUIRED_ = 557,
     _XSLT_OVERRIDE_ = 558,
     _XSLT_COPY_NAMESPACES_ = 559,
     _XSLT_INHERIT_NAMESPACES_ = 560,
     _XSLT_BYTE_ORDER_MARK_ = 561,
     _XSLT_ESCAPE_URI_ATTRIBUTES_ = 562,
     _XSLT_INCLUDE_CONTENT_TYPE_ = 563,
     _XSLT_INDENT_ = 564,
     _XSLT_OMIT_XML_DECLARATION_ = 565,
     _XSLT_UNDECLARE_PREFIXES_ = 566,
     _XSLT_MATCH_ = 567,
     _XSLT_AS_ = 568,
     _XSLT_SELECT_ = 569,
     _XSLT_PRIORITY_ = 570,
     _XSLT_TEST_ = 571,
     _XSLT_SEPARATOR_ = 572,
     _XSLT_NAMESPACE_A_ = 573,
     _XSLT_REGEX_ = 574,
     _XSLT_FLAGS_ = 575,
     _XSLT_METHOD_ = 576,
     _XSLT_CDATA_SECTION_ELEMENTS_ = 577,
     _XSLT_USE_CHARACTER_MAPS_ = 578,
     _XSLT_ELEMENT_NAME_ = 579,
     _XSLT_XMLNS_ATTR_ = 580,
     _XSLT_ATTR_NAME_ = 581,
     _XSLT_TEXT_NODE_ = 582,
     _XSLT_WS_TEXT_NODE_ = 583,
     _HASH_DEFAULT_ = 584,
     _HASH_ALL_ = 585,
     _HASH_CURRENT_ = 586,
     _XML_ = 587,
     _HTML_ = 588,
     _XHTML_ = 589
   };
#endif
/* Tokens.  */
#define MYEOF 0
#define _LANG_XPATH2_ 258
#define _LANG_XQUERY_ 259
#define _LANG_XSLT2_ 260
#define _LANG_FUNCDECL_ 261
#define _LANG_DELAYEDMODULE_ 262
#define _LANG_FUNCTION_SIGNATURE_ 263
#define _LANG_REWRITE_RULE_ 264
#define _LANG_REWRITE_PATTERN_ 265
#define _LANG_SEQUENCE_TYPE_ 266
#define _LANG_CARROT_ 267
#define _DOLLAR_ 268
#define _COLON_EQUALS_ 269
#define _ASTERISK_ 270
#define _BAR_ 271
#define _BANG_EQUALS_ 272
#define _LESS_THAN_EQUALS_ 273
#define _GREATER_THAN_ 274
#define _GREATER_THAN_EQUALS_ 275
#define _LESS_THAN_LESS_THAN_ 276
#define _GREATER_THAN_GREATER_THAN_ 277
#define _COLON_COLON_ 278
#define _AT_SIGN_ 279
#define _LSQUARE_ 280
#define _RSQUARE_ 281
#define _QUESTION_MARK_ 282
#define _LESS_THAN_OP_OR_TAG_ 283
#define _START_TAG_CLOSE_ 284
#define _END_TAG_CLOSE_ 285
#define _PI_START_ 286
#define _XML_COMMENT_START_ 287
#define _XML_COMMENT_END_ 288
#define _SLASH_SLASH_ 289
#define _END_TAG_OPEN_ 290
#define _PRAGMA_OPEN_ 291
#define _COMMA_ 292
#define _PLUS_ 293
#define _MINUS_ 294
#define _SLASH_ 295
#define _EQUALS_ 296
#define _DOT_ 297
#define _DOT_DOT_ 298
#define _LPAR_ 299
#define _RPAR_ 300
#define _EMPTY_TAG_CLOSE_ 301
#define _VALUE_INDICATOR_ 302
#define _OPEN_QUOT_ 303
#define _CLOSE_QUOT_ 304
#define _OPEN_APOS_ 305
#define _CLOSE_APOS_ 306
#define _LBRACE_ 307
#define _RBRACE_ 308
#define _SEMICOLON_ 309
#define _HASH_ 310
#define _PERCENT_ 311
#define _COLON_ 312
#define _TILDE_ 313
#define _MINUS_GREATER_THAN_ 314
#define _BAR_BAR_ 315
#define _BANG_ 316
#define _CARROT_ 317
#define _INTEGER_LITERAL_ 318
#define _DECIMAL_LITERAL_ 319
#define _DOUBLE_LITERAL_ 320
#define _ATTRIBUTE_ 321
#define _COMMENT_ 322
#define _DOCUMENT_NODE_ 323
#define _NAMESPACE_NODE_ 324
#define _NODE_ 325
#define _PROCESSING_INSTRUCTION_ 326
#define _SCHEMA_ATTRIBUTE_ 327
#define _SCHEMA_ELEMENT_ 328
#define _TEXT_ 329
#define _EMPTY_SEQUENCE_ 330
#define _BOUNDARY_SPACE_ 331
#define _FT_OPTION_ 332
#define _BASE_URI_ 333
#define _LAX_ 334
#define _STRICT_ 335
#define _IDIV_ 336
#define _CHILD_ 337
#define _DESCENDANT_ 338
#define _SELF_ 339
#define _DESCENDANT_OR_SELF_ 340
#define _FOLLOWING_SIBLING_ 341
#define _FOLLOWING_ 342
#define _PARENT_ 343
#define _ANCESTOR_ 344
#define _PRECEDING_SIBLING_ 345
#define _PRECEDING_ 346
#define _ANCESTOR_OR_SELF_ 347
#define _DOCUMENT_ 348
#define _NOT_ 349
#define _USING_ 350
#define _NO_ 351
#define _SENSITIVE_ 352
#define _INSENSITIVE_ 353
#define _DIACRITICS_ 354
#define _WITHOUT_ 355
#define _WITHOUT_C_ 356
#define _STEMMING_ 357
#define _THESAURUS_ 358
#define _STOP_ 359
#define _WILDCARDS_ 360
#define _ENTIRE_ 361
#define _CONTENT_ 362
#define _WORD_ 363
#define _TYPE_ 364
#define _START_ 365
#define _END_ 366
#define _MOST_ 367
#define _SKIP_ 368
#define _COPY_ 369
#define _VALUE_ 370
#define _WHITESPACE_ 371
#define _PI_CONTENT_ 372
#define _XML_COMMENT_CONTENT_ 373
#define _EQ_ 374
#define _NE_ 375
#define _LT_ 376
#define _LE_ 377
#define _GT_ 378
#define _GE_ 379
#define _AT_ 380
#define _QUOT_ATTR_CONTENT_ 381
#define _APOS_ATTR_CONTENT_ 382
#define _WHITESPACE_ELEMENT_CONTENT_ 383
#define _ELEMENT_CONTENT_ 384
#define _AT_LM_ 385
#define _ORDERED_ 386
#define _UNORDERED_ 387
#define _QNAME_ 388
#define _XMLNS_QNAME_ 389
#define _CONSTR_QNAME_ 390
#define _STRING_LITERAL_ 391
#define _VARIABLE_ 392
#define _NCNAME_COLON_STAR_ 393
#define _STAR_COLON_NCNAME_ 394
#define _PI_TARGET_ 395
#define _PRAGMA_CONTENT_ 396
#define _RETURN_ 397
#define _FOR_ 398
#define _IN_ 399
#define _LET_ 400
#define _WHERE_ 401
#define _COUNT_ 402
#define _BY_ 403
#define _ORDER_ 404
#define _STABLE_ 405
#define _ASCENDING_ 406
#define _DESCENDING_ 407
#define _EMPTY_ 408
#define _GREATEST_ 409
#define _LEAST_ 410
#define _COLLATION_ 411
#define _SOME_ 412
#define _EVERY_ 413
#define _SATISFIES_ 414
#define _TYPESWITCH_ 415
#define _CASE_ 416
#define _CASE_S_ 417
#define _AS_ 418
#define _IF_ 419
#define _THEN_ 420
#define _ELSE_ 421
#define _OR_ 422
#define _AND_ 423
#define _INSTANCE_ 424
#define _OF_ 425
#define _CASTABLE_ 426
#define _TO_ 427
#define _DIV_ 428
#define _MOD_ 429
#define _UNION_ 430
#define _INTERSECT_ 431
#define _EXCEPT_ 432
#define _VALIDATE_ 433
#define _CAST_ 434
#define _TREAT_ 435
#define _IS_ 436
#define _PRESERVE_ 437
#define _STRIP_ 438
#define _NAMESPACE_ 439
#define _ITEM_ 440
#define _EXTERNAL_ 441
#define _ENCODING_ 442
#define _NO_PRESERVE_ 443
#define _INHERIT_ 444
#define _NO_INHERIT_ 445
#define _DECLARE_ 446
#define _CONSTRUCTION_ 447
#define _ORDERING_ 448
#define _DEFAULT_ 449
#define _COPY_NAMESPACES_ 450
#define _OPTION_ 451
#define _XQUERY_ 452
#define _VERSION_ 453
#define _IMPORT_ 454
#define _SCHEMA_ 455
#define _MODULE_ 456
#define _ELEMENT_ 457
#define _FUNCTION_ 458
#define _FUNCTION_EXT_ 459
#define _SCORE_ 460
#define _CONTAINS_ 461
#define _WEIGHT_ 462
#define _WINDOW_ 463
#define _DISTANCE_ 464
#define _OCCURS_ 465
#define _TIMES_ 466
#define _SAME_ 467
#define _DIFFERENT_ 468
#define _LOWERCASE_ 469
#define _UPPERCASE_ 470
#define _RELATIONSHIP_ 471
#define _LEVELS_ 472
#define _LANGUAGE_ 473
#define _ANY_ 474
#define _ALL_ 475
#define _PHRASE_ 476
#define _EXACTLY_ 477
#define _FROM_ 478
#define _WORDS_ 479
#define _SENTENCES_ 480
#define _PARAGRAPHS_ 481
#define _SENTENCE_ 482
#define _PARAGRAPH_ 483
#define _REPLACE_ 484
#define _MODIFY_ 485
#define _FIRST_ 486
#define _INSERT_ 487
#define _BEFORE_ 488
#define _AFTER_ 489
#define _REVALIDATION_ 490
#define _WITH_ 491
#define _NODES_ 492
#define _RENAME_ 493
#define _LAST_ 494
#define _DELETE_ 495
#define _INTO_ 496
#define _UPDATING_ 497
#define _ID_ 498
#define _KEY_ 499
#define _TEMPLATE_ 500
#define _MATCHES_ 501
#define _TUPLE_ 502
#define _MAP_ 503
#define _NAME_ 504
#define _CALL_ 505
#define _APPLY_ 506
#define _TEMPLATES_ 507
#define _MODE_ 508
#define _FTOR_ 509
#define _FTAND_ 510
#define _FTNOT_ 511
#define _TYPE_ALIAS_ 512
#define _XSLT_END_ELEMENT_ 513
#define _XSLT_STYLESHEET_ 514
#define _XSLT_TEMPLATE_ 515
#define _XSLT_VALUE_OF_ 516
#define _XSLT_TEXT_ 517
#define _XSLT_APPLY_TEMPLATES_ 518
#define _XSLT_CALL_TEMPLATE_ 519
#define _XSLT_WITH_PARAM_ 520
#define _XSLT_SEQUENCE_ 521
#define _XSLT_PARAM_ 522
#define _XSLT_FUNCTION_ 523
#define _XSLT_CHOOSE_ 524
#define _XSLT_WHEN_ 525
#define _XSLT_OTHERWISE_ 526
#define _XSLT_IF_ 527
#define _XSLT_VARIABLE_ 528
#define _XSLT_COMMENT_ 529
#define _XSLT_PI_ 530
#define _XSLT_DOCUMENT_ 531
#define _XSLT_ATTRIBUTE_ 532
#define _XSLT_NAMESPACE_ 533
#define _XSLT_ELEMENT_ 534
#define _XSLT_ANALYZE_STRING_ 535
#define _XSLT_MATCHING_SUBSTRING_ 536
#define _XSLT_NON_MATCHING_SUBSTRING_ 537
#define _XSLT_COPY_OF_ 538
#define _XSLT_COPY_ 539
#define _XSLT_FOR_EACH_ 540
#define _XSLT_OUTPUT_ 541
#define _XSLT_IMPORT_SCHEMA_ 542
#define _XSLT_TYPE_ALIAS_ 543
#define _XSLT_VERSION_ 544
#define _XSLT_MODE_ 545
#define _XSLT_NAME_ 546
#define _XSLT_DOCTYPE_PUBLIC_ 547
#define _XSLT_DOCTYPE_SYSTEM_ 548
#define _XSLT_ENCODING_ 549
#define _XSLT_MEDIA_TYPE_ 550
#define _XSLT_NORMALIZATION_FORM_ 551
#define _XSLT_STANDALONE_ 552
#define _XSLT_EXCLUDE_RESULT_PREFIXES_ 553
#define _XSLT_NAMESPACE_STR_ 554
#define _XSLT_SCHEMA_LOCATION_ 555
#define _XSLT_TUNNEL_ 556
#define _XSLT_REQUIRED_ 557
#define _XSLT_OVERRIDE_ 558
#define _XSLT_COPY_NAMESPACES_ 559
#define _XSLT_INHERIT_NAMESPACES_ 560
#define _XSLT_BYTE_ORDER_MARK_ 561
#define _XSLT_ESCAPE_URI_ATTRIBUTES_ 562
#define _XSLT_INCLUDE_CONTENT_TYPE_ 563
#define _XSLT_INDENT_ 564
#define _XSLT_OMIT_XML_DECLARATION_ 565
#define _XSLT_UNDECLARE_PREFIXES_ 566
#define _XSLT_MATCH_ 567
#define _XSLT_AS_ 568
#define _XSLT_SELECT_ 569
#define _XSLT_PRIORITY_ 570
#define _XSLT_TEST_ 571
#define _XSLT_SEPARATOR_ 572
#define _XSLT_NAMESPACE_A_ 573
#define _XSLT_REGEX_ 574
#define _XSLT_FLAGS_ 575
#define _XSLT_METHOD_ 576
#define _XSLT_CDATA_SECTION_ELEMENTS_ 577
#define _XSLT_USE_CHARACTER_MAPS_ 578
#define _XSLT_ELEMENT_NAME_ 579
#define _XSLT_XMLNS_ATTR_ 580
#define _XSLT_ATTR_NAME_ 581
#define _XSLT_TEXT_NODE_ 582
#define _XSLT_WS_TEXT_NODE_ 583
#define _HASH_DEFAULT_ 584
#define _HASH_ALL_ 585
#define _HASH_CURRENT_ 586
#define _XML_ 587
#define _HTML_ 588
#define _XHTML_ 589




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 1148 "../src/parser/XQParser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  409
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  335
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  394
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1097
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1834

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   589

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    10,    14,    17,    21,    24,    27,
      30,    33,    37,    38,    40,    41,    45,    49,    53,    59,
      65,    75,    76,    78,    80,    84,    85,    88,    90,    97,
      98,   100,   101,   103,   104,   107,   116,   117,   119,   123,
     127,   134,   135,   138,   141,   144,   153,   159,   166,   168,
     173,   175,   176,   179,   182,   183,   186,   189,   192,   195,
     198,   201,   204,   209,   211,   215,   218,   222,   226,   230,
     231,   234,   237,   240,   242,   244,   246,   251,   253,   256,
     260,   263,   264,   267,   271,   273,   276,   280,   284,   287,
     290,   294,   296,   299,   303,   307,   310,   313,   317,   319,
     322,   326,   330,   333,   335,   338,   342,   345,   349,   352,
     355,   358,   361,   364,   367,   370,   373,   376,   379,   382,
     386,   389,   391,   393,   395,   397,   399,   401,   404,   407,
     409,   412,   416,   419,   421,   424,   427,   431,   435,   440,
     441,   445,   448,   449,   452,   455,   456,   459,   462,   465,
     467,   469,   471,   473,   475,   477,   479,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   505,   507,
     511,   515,   519,   521,   523,   527,   529,   533,   537,   539,
     541,   543,   544,   547,   551,   553,   556,   557,   560,   564,
     566,   569,   573,   577,   580,   583,   587,   591,   595,   600,
     602,   605,   609,   613,   614,   618,   623,   625,   629,   633,
     637,   638,   642,   643,   647,   652,   654,   657,   661,   665,
     669,   671,   675,   679,   681,   685,   689,   693,   695,   699,
     701,   705,   709,   713,   717,   721,   723,   727,   731,   735,
     737,   741,   745,   748,   750,   754,   757,   761,   763,   766,
     769,   773,   775,   779,   783,   785,   787,   789,   791,   793,
     795,   800,   807,   809,   811,   813,   815,   817,   820,   824,
     828,   832,   836,   839,   841,   845,   849,   852,   853,   858,
     861,   864,   865,   869,   874,   878,   881,   884,   887,   890,
     897,   898,   902,   906,   910,   914,   918,   922,   926,   930,
     934,   938,   940,   942,   944,   946,   948,   950,   952,   954,
     956,   958,   960,   966,   970,   974,   980,   986,   991,   995,
     999,  1003,  1009,  1015,  1021,  1023,  1025,  1027,  1029,  1034,
    1038,  1044,  1049,  1050,  1053,  1057,  1061,  1065,  1073,  1078,
    1082,  1086,  1087,  1090,  1092,  1094,  1096,  1104,  1107,  1109,
    1117,  1120,  1124,  1125,  1128,  1130,  1132,  1135,  1141,  1143,
    1147,  1151,  1153,  1157,  1161,  1163,  1167,  1169,  1171,  1173,
    1175,  1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,
    1197,  1199,  1202,  1205,  1207,  1209,  1211,  1213,  1215,  1218,
    1222,  1224,  1232,  1233,  1237,  1238,  1242,  1245,  1249,  1251,
    1257,  1263,  1266,  1270,  1274,  1279,  1283,  1285,  1289,  1295,
    1297,  1298,  1300,  1302,  1303,  1306,  1309,  1314,  1319,  1323,
    1325,  1331,  1338,  1341,  1343,  1349,  1353,  1357,  1361,  1365,
    1366,  1370,  1379,  1383,  1385,  1389,  1391,  1395,  1399,  1400,
    1405,  1409,  1413,  1417,  1421,  1425,  1429,  1433,  1437,  1441,
    1445,  1449,  1453,  1455,  1460,  1466,  1468,  1472,  1474,  1478,
    1480,  1484,  1488,  1490,  1494,  1498,  1502,  1506,  1508,  1512,
    1516,  1518,  1522,  1526,  1528,  1533,  1535,  1540,  1542,  1547,
    1549,  1554,  1556,  1559,  1562,  1564,  1566,  1568,  1570,  1575,
    1581,  1587,  1591,  1596,  1598,  1601,  1606,  1608,  1611,  1613,
    1616,  1619,  1621,  1623,  1627,  1631,  1635,  1637,  1639,  1641,
    1643,  1645,  1647,  1652,  1654,  1659,  1662,  1664,  1667,  1670,
    1673,  1676,  1679,  1682,  1685,  1688,  1691,  1693,  1696,  1698,
    1701,  1704,  1707,  1710,  1713,  1715,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1736,  1738,  1740,  1742,  1744,  1746,
    1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,
    1769,  1771,  1775,  1778,  1780,  1785,  1790,  1794,  1799,  1803,
    1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,  1825,  1836,
    1838,  1840,  1841,  1849,  1857,  1858,  1860,  1864,  1868,  1872,
    1876,  1877,  1880,  1883,  1884,  1887,  1890,  1891,  1894,  1897,
    1898,  1901,  1904,  1905,  1908,  1911,  1914,  1917,  1921,  1922,
    1924,  1928,  1930,  1933,  1935,  1937,  1939,  1941,  1943,  1945,
    1947,  1952,  1956,  1958,  1962,  1965,  1969,  1973,  1975,  1979,
    1983,  1988,  1993,  1997,  1999,  2003,  2006,  2010,  2013,  2014,
    2016,  2017,  2020,  2023,  2027,  2028,  2030,  2032,  2034,  2038,
    2040,  2042,  2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,
    2060,  2062,  2064,  2066,  2068,  2072,  2076,  2081,  2086,  2090,
    2094,  2098,  2102,  2107,  2112,  2116,  2121,  2128,  2130,  2132,
    2137,  2139,  2143,  2148,  2155,  2163,  2165,  2167,  2172,  2174,
    2176,  2178,  2180,  2182,  2186,  2187,  2190,  2191,  2194,  2198,
    2200,  2204,  2206,  2211,  2213,  2216,  2218,  2220,  2223,  2226,
    2230,  2232,  2235,  2240,  2244,  2249,  2250,  2252,  2255,  2257,
    2260,  2262,  2263,  2267,  2270,  2274,  2278,  2283,  2285,  2289,
    2293,  2296,  2299,  2302,  2305,  2308,  2310,  2312,  2314,  2316,
    2318,  2321,  2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2344,  2347,  2349,  2351,  2354,  2357,  2359,  2362,  2365,
    2368,  2374,  2380,  2383,  2384,  2388,  2391,  2396,  2401,  2408,
    2413,  2417,  2422,  2423,  2426,  2429,  2433,  2435,  2439,  2442,
    2445,  2448,  2450,  2453,  2457,  2461,  2465,  2469,  2473,  2480,
    2487,  2492,  2497,  2502,  2505,  2508,  2511,  2514,  2517,  2525,
    2531,  2537,  2544,  2548,  2550,  2555,  2557,  2559,  2561,  2563,
    2565,  2567,  2573,  2581,  2590,  2601,  2608,  2617,  2618,  2621,
    2624,  2628,  2629,  2632,  2634,  2638,  2640,  2642,  2644,  2648,
    2656,  2660,  2668,  2674,  2684,  2686,  2688,  2690,  2692,  2696,
    2702,  2704,  2706,  2710,  2715,  2719,  2724,  2726,  2728,  2734,
    2735,  2738,  2745,  2753,  2755,  2759,  2763,  2765,  2767,  2772,
    2776,  2778,  2782,  2785,  2792,  2796,  2798,  2800,  2805,  2809,
    2811,  2815,  2820,  2825,  2829,  2831,  2835,  2839,  2841,  2845,
    2851,  2853,  2855,  2861,  2864,  2865,  2868,  2872,  2881,  2883,
    2887,  2889,  2893,  2895,  2899,  2903,  2907,  2911,  2915,  2919,
    2921,  2925,  2929,  2931,  2935,  2939,  2943,  2947,  2949,  2952,
    2955,  2957,  2962,  2964,  2969,  2973,  2976,  2978,  2980,  2982,
    2984,  2985,  2987,  2989,  2993,  2995,  2998,  3000,  3002,  3004,
    3006,  3008,  3010,  3012,  3014,  3016,  3018,  3020,  3022,  3024,
    3026,  3028,  3030,  3032,  3034,  3036,  3038,  3040,  3042,  3044,
    3046,  3048,  3050,  3052,  3054,  3056,  3058,  3060,  3062,  3064,
    3066,  3068,  3070,  3072,  3074,  3076,  3078,  3080,  3082,  3084,
    3086,  3088,  3090,  3092,  3094,  3096,  3098,  3100,  3102,  3104,
    3106,  3108,  3110,  3112,  3114,  3116,  3118,  3120,  3122,  3124,
    3126,  3128,  3130,  3132,  3134,  3136,  3138,  3140,  3142,  3144,
    3146,  3148,  3150,  3152,  3154,  3156,  3158,  3160,  3162,  3164,
    3166,  3168,  3170,  3172,  3174,  3176,  3178,  3180,  3182,  3184,
    3186,  3188,  3190,  3192,  3194,  3196,  3198,  3200,  3202,  3204,
    3206,  3208,  3210,  3212,  3214,  3216,  3218,  3220,  3222,  3224,
    3226,  3228,  3230,  3232,  3234,  3236,  3238,  3240,  3242,  3244,
    3246,  3248,  3250,  3252,  3254,  3256,  3258,  3260,  3262,  3264,
    3266,  3268,  3270,  3272,  3274,  3276,  3278,  3280,  3282,  3284,
    3286,  3288,  3290,  3292,  3294,  3296,  3298,  3300,  3302,  3304,
    3306,  3308,  3310,  3312,  3314,  3316,  3318,  3320,  3322,  3324,
    3326,  3328,  3330,  3332,  3334,  3336,  3338,  3340
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     336,     0,    -1,     3,   488,    -1,     4,   337,   446,    -1,
       6,   337,   351,    -1,     5,   360,    -1,     7,   337,   354,
      -1,     8,   353,    -1,     9,   710,    -1,    10,   711,    -1,
      11,   604,    -1,    12,   337,   338,    -1,    -1,   339,    -1,
      -1,   339,   340,    54,    -1,   339,   341,    54,    -1,   339,
     342,    54,    -1,    13,   563,   603,    14,   490,    -1,   728,
     480,   481,    14,   490,    -1,    62,   343,    44,   436,   345,
      45,   481,    14,   490,    -1,    -1,   344,    -1,   682,    -1,
     344,    16,   682,    -1,    -1,    54,   485,    -1,   347,    -1,
      62,   349,    44,   348,   350,    45,    -1,    -1,   490,    -1,
      -1,   685,    -1,    -1,    54,   686,    -1,   191,   474,   203,
     728,   480,   481,   487,   352,    -1,    -1,   456,    -1,   474,
     480,   481,    -1,   447,   355,   356,    -1,   201,   184,   675,
      41,   626,   456,    -1,    -1,   356,   357,    -1,   356,   358,
      -1,   356,   359,    -1,   191,   474,   203,   728,   480,   481,
     487,   456,    -1,   191,   196,   727,   136,   456,    -1,   191,
     184,   675,    41,   626,   456,    -1,   361,    -1,   259,   362,
     363,   258,    -1,   385,    -1,    -1,   362,   289,    -1,   362,
     298,    -1,    -1,   363,   364,    -1,   363,   368,    -1,   363,
     373,    -1,   363,   375,    -1,   363,   377,    -1,   363,   383,
      -1,   363,   381,    -1,   365,   370,   388,   258,    -1,   260,
      -1,   365,   312,   436,    -1,   365,   291,    -1,   365,   315,
     367,    -1,   365,   290,   366,    -1,   365,   313,   604,    -1,
      -1,   366,   133,    -1,   366,   329,    -1,   366,   330,    -1,
      63,    -1,    64,    -1,    65,    -1,   369,   370,   388,   258,
      -1,   268,    -1,   369,   291,    -1,   369,   313,   604,    -1,
     369,   303,    -1,    -1,   370,   371,    -1,   372,   388,   258,
      -1,   267,    -1,   372,   291,    -1,   372,   314,   489,    -1,
     372,   313,   604,    -1,   372,   302,    -1,   372,   301,    -1,
     374,   388,   258,    -1,   267,    -1,   374,   291,    -1,   374,
     314,   489,    -1,   374,   313,   604,    -1,   374,   302,    -1,
     374,   301,    -1,   376,   388,   258,    -1,   273,    -1,   376,
     291,    -1,   376,   314,   489,    -1,   376,   313,   604,    -1,
     378,   258,    -1,   286,    -1,   378,   291,    -1,   378,   321,
     379,    -1,   378,   306,    -1,   378,   322,   380,    -1,   378,
     292,    -1,   378,   293,    -1,   378,   294,    -1,   378,   307,
      -1,   378,   308,    -1,   378,   309,    -1,   378,   295,    -1,
     378,   296,    -1,   378,   310,    -1,   378,   297,    -1,   378,
     311,    -1,   378,   323,   380,    -1,   378,   289,    -1,   332,
      -1,   333,    -1,   334,    -1,    74,    -1,   133,    -1,   133,
      -1,   380,   133,    -1,   382,   258,    -1,   288,    -1,   382,
     291,    -1,   382,   313,   606,    -1,   384,   258,    -1,   287,
      -1,   287,   299,    -1,   287,   300,    -1,   287,   299,   300,
      -1,   287,   300,   299,    -1,   324,   386,   388,   258,    -1,
      -1,   386,   326,   387,    -1,   386,   325,    -1,    -1,   387,
     487,    -1,   387,   126,    -1,    -1,   388,   393,    -1,   388,
     385,    -1,   388,   389,    -1,   390,    -1,   392,    -1,   394,
      -1,   398,    -1,   403,    -1,   407,    -1,   405,    -1,   416,
      -1,   418,    -1,   420,    -1,   422,    -1,   424,    -1,   426,
      -1,   428,    -1,   412,    -1,   430,    -1,   432,    -1,   434,
      -1,   391,   388,   258,    -1,   261,    -1,   391,   314,   489,
      -1,   391,   317,   387,    -1,   262,   393,   258,    -1,   327,
      -1,   328,    -1,   395,   397,   258,    -1,   263,    -1,   395,
     314,   489,    -1,   395,   290,   396,    -1,   133,    -1,   329,
      -1,   331,    -1,    -1,   397,   401,    -1,   399,   400,   258,
      -1,   264,    -1,   399,   291,    -1,    -1,   400,   401,    -1,
     402,   388,   258,    -1,   265,    -1,   402,   291,    -1,   402,
     314,   489,    -1,   402,   313,   604,    -1,   402,   301,    -1,
     404,   258,    -1,   266,   314,   489,    -1,   406,   388,   258,
      -1,   272,   316,   489,    -1,   269,   408,   411,   258,    -1,
     409,    -1,   408,   409,    -1,   410,   388,   258,    -1,   270,
     316,   489,    -1,    -1,   271,   388,   258,    -1,   413,   414,
     415,   258,    -1,   280,    -1,   413,   314,   489,    -1,   413,
     319,   387,    -1,   413,   320,   387,    -1,    -1,   281,   388,
     258,    -1,    -1,   282,   388,   258,    -1,   417,   388,   258,
     388,    -1,   273,    -1,   417,   291,    -1,   417,   314,   489,
      -1,   417,   313,   604,    -1,   419,   388,   258,    -1,   274,
      -1,   419,   314,   489,    -1,   421,   388,   258,    -1,   275,
      -1,   421,   291,   387,    -1,   421,   314,   489,    -1,   423,
     388,   258,    -1,   276,    -1,   425,   388,   258,    -1,   277,
      -1,   425,   291,   387,    -1,   425,   318,   387,    -1,   425,
     314,   489,    -1,   425,   317,   387,    -1,   427,   388,   258,
      -1,   278,    -1,   427,   291,   387,    -1,   427,   314,   489,
      -1,   429,   388,   258,    -1,   279,    -1,   429,   291,   387,
      -1,   429,   318,   387,    -1,   431,   258,    -1,   283,    -1,
     431,   314,   489,    -1,   431,   304,    -1,   433,   388,   258,
      -1,   284,    -1,   433,   304,    -1,   433,   305,    -1,   435,
     388,   258,    -1,   285,    -1,   435,   314,   489,    -1,   436,
      16,   437,    -1,   437,    -1,   442,    -1,    40,    -1,   439,
      -1,    40,    -1,    34,    -1,   243,    44,   440,    45,    -1,
     244,    44,   674,    37,   441,    45,    -1,   674,    -1,   562,
      -1,   560,    -1,   562,    -1,   443,    -1,   438,   443,    -1,
     439,    40,   443,    -1,   439,    34,   443,    -1,   442,    40,
     443,    -1,   442,    34,   443,    -1,   444,   445,    -1,   556,
      -1,    82,    23,   556,    -1,    66,    23,   556,    -1,    24,
     556,    -1,    -1,   445,    25,   489,    26,    -1,   447,   450,
      -1,   447,   451,    -1,    -1,   197,   448,   456,    -1,   197,
     448,   449,   456,    -1,   197,   449,   456,    -1,   198,   136,
      -1,   187,   136,    -1,   453,   488,    -1,   452,   453,    -1,
     201,   184,   675,    41,   626,   456,    -1,    -1,   453,   454,
     456,    -1,   453,   455,   456,    -1,   453,   457,   456,    -1,
     453,   459,   456,    -1,   453,   477,   456,    -1,   453,   479,
     456,    -1,   453,   677,   456,    -1,   453,   460,   456,    -1,
     453,   461,   456,    -1,   453,   709,   456,    -1,   458,    -1,
     467,    -1,   468,    -1,   473,    -1,   462,    -1,   463,    -1,
     661,    -1,   464,    -1,   469,    -1,   472,    -1,    54,    -1,
     191,   184,   675,    41,   626,    -1,   191,    76,   182,    -1,
     191,    76,   183,    -1,   191,   194,   202,   184,   626,    -1,
     191,   194,   203,   184,   626,    -1,   191,   196,   727,   136,
      -1,   191,    77,   644,    -1,   191,   193,   131,    -1,   191,
     193,   132,    -1,   191,   194,   149,   153,   154,    -1,   191,
     194,   149,   153,   155,    -1,   191,   195,   465,    37,   466,
      -1,   182,    -1,   188,    -1,   189,    -1,   190,    -1,   191,
     194,   156,   626,    -1,   191,    78,   626,    -1,   199,   200,
     471,   626,   470,    -1,   199,   200,   626,   470,    -1,    -1,
     125,   626,    -1,   470,    37,   626,    -1,   184,   675,    41,
      -1,   194,   202,   184,    -1,   199,   201,   184,   675,    41,
     626,   470,    -1,   199,   201,   626,   470,    -1,   191,   192,
     182,    -1,   191,   192,   183,    -1,    -1,   474,   475,    -1,
     476,    -1,   483,    -1,   242,    -1,   191,   474,   137,    13,
     563,   603,   478,    -1,    14,   490,    -1,   186,    -1,   191,
     474,   203,   728,   480,   481,   482,    -1,    44,    45,    -1,
      44,   485,    45,    -1,    -1,   163,   604,    -1,   487,    -1,
     186,    -1,    56,   727,    -1,    56,   727,    44,   484,    45,
      -1,   560,    -1,   484,    37,   560,    -1,   485,    37,   486,
      -1,   486,    -1,    13,   563,   603,    -1,    52,   489,    53,
      -1,   489,    -1,   489,    37,   490,    -1,   490,    -1,   491,
      -1,   511,    -1,   514,    -1,   520,    -1,   662,    -1,   664,
      -1,   667,    -1,   666,    -1,   668,    -1,   521,    -1,   683,
      -1,   684,    -1,   492,   142,   490,    -1,   493,    -1,   492,
     505,    -1,   492,   494,    -1,   495,    -1,   500,    -1,   493,
      -1,   503,    -1,   504,    -1,   143,   496,    -1,   496,    37,
     497,    -1,   497,    -1,    13,   563,   603,   498,   499,   144,
     490,    -1,    -1,   125,    13,   563,    -1,    -1,   205,    13,
     563,    -1,   145,   501,    -1,   501,    37,   502,    -1,   502,
      -1,    13,   563,   603,    14,   490,    -1,   205,    13,   563,
      14,   490,    -1,   146,   490,    -1,   147,    13,   563,    -1,
     149,   148,   506,    -1,   150,   149,   148,   506,    -1,   506,
      37,   507,    -1,   507,    -1,   508,   509,   510,    -1,   508,
     509,   510,   156,   626,    -1,   490,    -1,    -1,   151,    -1,
     152,    -1,    -1,   153,   154,    -1,   153,   155,    -1,   157,
     512,   159,   490,    -1,   158,   512,   159,   490,    -1,   512,
      37,   513,    -1,   513,    -1,    13,   563,   603,   144,   490,
      -1,   160,    44,   489,    45,   515,   516,    -1,   515,   517,
      -1,   517,    -1,   194,    13,   563,   142,   490,    -1,   194,
     142,   490,    -1,   518,   142,   490,    -1,   161,   519,   604,
      -1,   518,    16,   604,    -1,    -1,    13,   563,   163,    -1,
     164,    44,   489,    45,   165,   490,   166,   490,    -1,   521,
     167,   522,    -1,   522,    -1,   522,   168,   523,    -1,   523,
      -1,   525,    41,   525,    -1,   525,    17,   525,    -1,    -1,
     525,    28,   524,   525,    -1,   525,    18,   525,    -1,   525,
      19,   525,    -1,   525,    20,   525,    -1,   525,   119,   525,
      -1,   525,   120,   525,    -1,   525,   121,   525,    -1,   525,
     122,   525,    -1,   525,   123,   525,    -1,   525,   124,   525,
      -1,   525,   181,   525,    -1,   525,    21,   525,    -1,   525,
      22,   525,    -1,   525,    -1,   526,   206,    74,   627,    -1,
     526,   206,    74,   627,   660,    -1,   526,    -1,   526,    60,
     527,    -1,   527,    -1,   528,   172,   528,    -1,   528,    -1,
     528,    38,   529,    -1,   528,    39,   529,    -1,   529,    -1,
     529,    15,   530,    -1,   529,   173,   530,    -1,   529,    81,
     530,    -1,   529,   174,   530,    -1,   530,    -1,   530,    16,
     531,    -1,   530,   175,   531,    -1,   531,    -1,   531,   176,
     532,    -1,   531,   177,   532,    -1,   532,    -1,   533,   169,
     170,   604,    -1,   533,    -1,   534,   180,   163,   604,    -1,
     534,    -1,   535,   171,   163,   601,    -1,   535,    -1,   536,
     179,   163,   601,    -1,   536,    -1,    39,   536,    -1,    38,
     536,    -1,   537,    -1,   538,    -1,   543,    -1,   539,    -1,
     178,    52,   489,    53,    -1,   178,    79,    52,   489,    53,
      -1,   178,    80,    52,   489,    53,    -1,   540,    52,    53,
      -1,   540,    52,   489,    53,    -1,   541,    -1,   540,   541,
      -1,    36,   576,   727,   542,    -1,   141,    -1,   116,   141,
      -1,   544,    -1,   544,   545,    -1,    34,   545,    -1,   545,
      -1,    40,    -1,   545,    40,   546,    -1,   545,    34,   546,
      -1,   545,    61,   546,    -1,   546,    -1,   547,    -1,   559,
      -1,   548,    -1,   549,    -1,   550,    -1,   548,    25,   489,
      26,    -1,   553,    -1,   549,    25,   489,    26,    -1,   551,
     556,    -1,   552,    -1,    82,    23,    -1,    83,    23,    -1,
      66,    23,    -1,    84,    23,    -1,    85,    23,    -1,    86,
      23,    -1,    87,    23,    -1,   184,    23,    -1,    24,   556,
      -1,   556,    -1,   554,   556,    -1,   555,    -1,    88,    23,
      -1,    89,    23,    -1,    90,    23,    -1,    91,    23,    -1,
      92,    23,    -1,    43,    -1,   608,    -1,   557,    -1,   676,
      -1,   558,    -1,    15,    -1,   138,    -1,   139,    -1,   346,
      -1,   559,    25,   489,    26,    -1,   691,    -1,   560,    -1,
     562,    -1,   564,    -1,   565,    -1,   568,    -1,   571,    -1,
     566,    -1,   567,    -1,   688,    -1,   561,    -1,   674,    -1,
     671,    -1,   672,    -1,   673,    -1,    13,   563,    -1,   727,
      -1,    44,   489,    45,    -1,    44,    45,    -1,    42,    -1,
     131,    52,   489,    53,    -1,   132,    52,   489,    53,    -1,
     728,    44,    45,    -1,   728,    44,   569,    45,    -1,   569,
      37,   570,    -1,   570,    -1,   490,    -1,    27,    -1,   572,
      -1,   588,    -1,   573,    -1,   584,    -1,   586,    -1,    28,
     574,   575,   576,    46,    -1,    28,   574,   575,   576,    29,
     583,    35,   574,   576,    30,    -1,   133,    -1,   134,    -1,
      -1,   575,   116,   133,   576,    47,   576,   577,    -1,   575,
     116,   134,   576,    47,   576,   578,    -1,    -1,   116,    -1,
      48,   579,    49,    -1,    50,   581,    51,    -1,    48,   580,
      49,    -1,    50,   582,    51,    -1,    -1,   579,   487,    -1,
     579,   126,    -1,    -1,   580,   487,    -1,   580,   126,    -1,
      -1,   581,   487,    -1,   581,   127,    -1,    -1,   582,   487,
      -1,   582,   127,    -1,    -1,   583,   572,    -1,   583,   487,
      -1,   583,   129,    -1,   583,   128,    -1,    32,   585,    33,
      -1,    -1,   118,    -1,    31,   140,   587,    -1,   117,    -1,
     116,   117,    -1,   589,    -1,   590,    -1,   593,    -1,   595,
      -1,   596,    -1,   597,    -1,   598,    -1,    93,    52,   489,
      53,    -1,   202,   591,   592,    -1,   135,    -1,    52,   489,
      53,    -1,    52,    53,    -1,    52,   489,    53,    -1,    66,
     594,   592,    -1,   135,    -1,    52,   489,    53,    -1,   184,
     599,   592,    -1,    74,    52,   489,    53,    -1,    67,    52,
     489,    53,    -1,    71,   599,   600,    -1,   135,    -1,    52,
     489,    53,    -1,    52,    53,    -1,    52,   489,    53,    -1,
     607,   602,    -1,    -1,    27,    -1,    -1,   163,   604,    -1,
     606,   605,    -1,    75,    44,    45,    -1,    -1,    15,    -1,
      38,    -1,    27,    -1,   185,    44,    45,    -1,   607,    -1,
     608,    -1,   692,    -1,   697,    -1,   676,    -1,   610,    -1,
     619,    -1,   615,    -1,   621,    -1,   617,    -1,   614,    -1,
     612,    -1,   611,    -1,   613,    -1,   609,    -1,    70,    44,
      45,    -1,    68,    44,    45,    -1,    68,    44,   619,    45,
      -1,    68,    44,   621,    45,    -1,    74,    44,    45,    -1,
      67,    44,    45,    -1,    69,    44,    45,    -1,    71,    44,
      45,    -1,    71,    44,   675,    45,    -1,    71,    44,   136,
      45,    -1,    66,    44,    45,    -1,    66,    44,   616,    45,
      -1,    66,    44,   616,    37,   625,    45,    -1,   623,    -1,
      15,    -1,    72,    44,   618,    45,    -1,   623,    -1,   202,
      44,    45,    -1,   202,    44,   620,    45,    -1,   202,    44,
     620,    37,   625,    45,    -1,   202,    44,   620,    37,   625,
      27,    45,    -1,   624,    -1,    15,    -1,    73,    44,   622,
      45,    -1,   624,    -1,   676,    -1,   676,    -1,   676,    -1,
     136,    -1,   630,   629,   628,    -1,    -1,   207,   527,    -1,
      -1,   629,   641,    -1,   630,   254,   631,    -1,   631,    -1,
     631,   255,   632,    -1,   632,    -1,   632,    94,   144,   633,
      -1,   633,    -1,   256,   634,    -1,   634,    -1,   635,    -1,
     635,   644,    -1,   636,   639,    -1,    44,   627,    45,    -1,
     637,    -1,   560,   638,    -1,    52,   489,    53,   638,    -1,
     540,    52,    53,    -1,   540,    52,   627,    53,    -1,    -1,
     219,    -1,   219,   108,    -1,   220,    -1,   220,   224,    -1,
     221,    -1,    -1,   210,   640,   211,    -1,   222,   528,    -1,
     130,   155,   528,    -1,   130,   112,   528,    -1,   223,   528,
     172,   528,    -1,   131,    -1,   208,   528,   642,    -1,   209,
     640,   642,    -1,   212,   643,    -1,   213,   643,    -1,   125,
     110,    -1,   125,   111,    -1,   106,   107,    -1,   224,    -1,
     225,    -1,   226,    -1,   227,    -1,   228,    -1,    95,   645,
      -1,   644,    95,   645,    -1,   657,    -1,   658,    -1,   649,
      -1,   648,    -1,   646,    -1,   647,    -1,   652,    -1,   659,
      -1,   162,    98,    -1,   162,    97,    -1,   214,    -1,   215,
      -1,    99,    98,    -1,    99,    97,    -1,   102,    -1,    96,
     102,    -1,   103,   651,    -1,   103,   194,    -1,   103,    44,
     651,   650,    45,    -1,   103,    44,   194,   650,    45,    -1,
      96,   103,    -1,    -1,   650,    37,   651,    -1,   125,   626,
      -1,   125,   626,   216,   674,    -1,   125,   626,   640,   217,
      -1,   125,   626,   216,   674,   640,   217,    -1,   104,   224,
     654,   653,    -1,    96,   104,   224,    -1,   104,   224,   194,
     653,    -1,    -1,   653,   656,    -1,   125,   626,    -1,    44,
     655,    45,    -1,   674,    -1,   655,    37,   674,    -1,   175,
     654,    -1,   177,   654,    -1,   218,   674,    -1,   105,    -1,
      96,   105,    -1,   196,   727,   136,    -1,   101,   107,   530,
      -1,   191,   235,    80,    -1,   191,   235,    79,    -1,   191,
     235,   113,    -1,   663,   490,   163,   231,   241,   490,    -1,
     663,   490,   163,   239,   241,   490,    -1,   663,   490,   241,
     490,    -1,   663,   490,   234,   490,    -1,   663,   490,   233,
     490,    -1,   232,    70,    -1,   232,   237,    -1,   665,   490,
      -1,   240,    70,    -1,   240,   237,    -1,   229,   115,   170,
      70,   490,   236,   490,    -1,   229,    70,   490,   236,   490,
      -1,   238,    70,   490,   163,   490,    -1,   114,   669,   230,
     490,   142,   490,    -1,   669,    37,   670,    -1,   670,    -1,
      13,   563,    14,   490,    -1,    63,    -1,    64,    -1,    65,
      -1,   136,    -1,   727,    -1,   727,    -1,   191,   245,   249,
     727,   487,    -1,   191,   245,   249,   727,   679,   678,   487,
      -1,   191,   245,   249,   727,   680,   246,   436,   487,    -1,
     191,   245,   249,   727,   680,   246,   436,   679,   678,   487,
      -1,   191,   245,   680,   246,   436,   487,    -1,   191,   245,
     680,   246,   436,   679,   678,   487,    -1,    -1,   163,   604,
      -1,    44,    45,    -1,    44,   485,    45,    -1,    -1,   253,
     681,    -1,   682,    -1,   681,    37,   682,    -1,   133,    -1,
     329,    -1,   330,    -1,   250,   245,   727,    -1,   250,   245,
     727,   236,    44,   686,    45,    -1,   251,   252,   490,    -1,
     251,   252,   490,   236,    44,   686,    45,    -1,   251,   252,
     490,   253,   685,    -1,   251,   252,   490,   253,   685,   236,
      44,   686,    45,    -1,   727,    -1,   329,    -1,   331,    -1,
     687,    -1,   686,    37,   687,    -1,    13,   563,   603,    14,
     490,    -1,   689,    -1,   690,    -1,   728,    55,    63,    -1,
     204,   480,   603,   487,    -1,   559,    44,    45,    -1,   559,
      44,   569,    45,    -1,   693,    -1,   695,    -1,   694,   204,
      44,    15,    45,    -1,    -1,   694,   483,    -1,   694,   204,
      44,    45,   163,   604,    -1,   694,   204,    44,   696,    45,
     163,   604,    -1,   604,    -1,   696,    37,   604,    -1,    44,
     606,    45,    -1,   698,    -1,   701,    -1,   247,    44,   699,
      45,    -1,   247,    44,    45,    -1,   700,    -1,   699,    37,
     700,    -1,   727,   603,    -1,   248,    44,   607,    37,   604,
      45,    -1,   248,    44,    45,    -1,   702,    -1,   705,    -1,
     247,    52,   703,    53,    -1,   247,    52,    53,    -1,   704,
      -1,   703,    37,   704,    -1,   727,   603,    14,   490,    -1,
     248,    52,   706,    53,    -1,   248,    52,    53,    -1,   707,
      -1,   706,    37,   707,    -1,   490,    14,   490,    -1,   708,
      -1,   559,    24,   727,    -1,   191,   257,   727,   163,   606,
      -1,   712,    -1,   715,    -1,   727,    57,   715,   713,   714,
      -1,   712,   714,    -1,    -1,   146,   490,    -1,    59,   726,
     713,    -1,   164,    44,   715,    45,   165,   715,   166,   715,
      -1,   716,    -1,   716,   167,   717,    -1,   717,    -1,   717,
     168,   718,    -1,   718,    -1,   719,   119,   719,    -1,   719,
     120,   719,    -1,   719,   123,   719,    -1,   719,   124,   719,
      -1,   719,   121,   719,    -1,   719,   122,   719,    -1,   719,
      -1,   719,    38,   720,    -1,   719,    39,   720,    -1,   720,
      -1,   720,    15,   721,    -1,   720,   173,   721,    -1,   720,
      81,   721,    -1,   720,   174,   721,    -1,   721,    -1,    38,
     721,    -1,    39,   721,    -1,   722,    -1,   722,    25,   715,
      26,    -1,   723,    -1,   728,    44,   724,    45,    -1,    44,
     724,    45,    -1,    58,   727,    -1,    63,    -1,    64,    -1,
      65,    -1,   136,    -1,    -1,   725,    -1,   715,    -1,   725,
      37,   715,    -1,   490,    -1,    58,   727,    -1,   728,    -1,
      66,    -1,    67,    -1,    68,    -1,   202,    -1,   185,    -1,
     164,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,   160,    -1,    75,    -1,    69,    -1,   133,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,    92,    -1,    93,    -1,    94,    -1,    97,    -1,
      98,    -1,    99,    -1,   100,    -1,   102,    -1,   103,    -1,
     104,    -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,
     109,    -1,   110,    -1,   111,    -1,   112,    -1,   113,    -1,
     114,    -1,   115,    -1,   119,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   137,    -1,
     142,    -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,
     148,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   155,    -1,   156,    -1,   157,    -1,
     158,    -1,   159,    -1,   161,    -1,   163,    -1,   165,    -1,
     166,    -1,   167,    -1,   168,    -1,   169,    -1,   170,    -1,
     171,    -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,
     176,    -1,   177,    -1,   178,    -1,   179,    -1,   180,    -1,
     181,    -1,   182,    -1,   183,    -1,   184,    -1,   186,    -1,
     187,    -1,   188,    -1,   189,    -1,   190,    -1,   191,    -1,
     192,    -1,   193,    -1,   194,    -1,   195,    -1,   196,    -1,
     198,    -1,   199,    -1,   200,    -1,   203,    -1,   205,    -1,
      95,    -1,    96,    -1,   206,    -1,   207,    -1,   208,    -1,
     209,    -1,   210,    -1,   211,    -1,   212,    -1,   213,    -1,
     214,    -1,   215,    -1,   216,    -1,   217,    -1,   218,    -1,
     219,    -1,   220,    -1,   221,    -1,   222,    -1,   223,    -1,
     224,    -1,   225,    -1,   226,    -1,   227,    -1,   228,    -1,
     229,    -1,   230,    -1,   231,    -1,   232,    -1,   233,    -1,
     234,    -1,   235,    -1,   236,    -1,   237,    -1,   238,    -1,
     239,    -1,   240,    -1,   241,    -1,   242,    -1,   131,    -1,
     132,    -1,   243,    -1,   244,    -1,   245,    -1,   246,    -1,
     249,    -1,   250,    -1,   251,    -1,   252,    -1,   253,    -1,
     254,    -1,   255,    -1,   256,    -1,   247,    -1,   257,    -1,
     248,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   808,   808,   810,   811,   813,   815,   816,   818,   819,
     821,   825,   830,   838,   866,   868,   869,   870,   874,   881,
     892,   903,   907,   911,   916,   925,   928,   934,   937,   945,
     953,   958,   961,   966,   969,   979,   987,   987,   990,   999,
    1010,  1050,  1053,  1054,  1055,  1059,  1075,  1102,  1115,  1144,
    1147,  1169,  1171,  1175,  1182,  1184,  1185,  1186,  1187,  1188,
    1189,  1190,  1194,  1213,  1218,  1223,  1230,  1235,  1240,  1249,
    1252,  1258,  1263,  1270,  1270,  1270,  1273,  1286,  1291,  1298,
    1303,  1312,  1315,  1323,  1350,  1354,  1361,  1367,  1372,  1377,
    1386,  1410,  1414,  1421,  1426,  1431,  1436,  1447,  1465,  1469,
    1476,  1481,  1489,  1514,  1517,  1520,  1523,  1526,  1529,  1532,
    1535,  1538,  1541,  1544,  1547,  1550,  1553,  1556,  1559,  1562,
    1565,  1571,  1572,  1573,  1574,  1575,  1587,  1590,  1596,  1610,
    1614,  1621,  1628,  1631,  1636,  1641,  1649,  1657,  1668,  1679,
    1682,  1689,  1699,  1702,  1707,  1716,  1719,  1724,  1729,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,
    1748,  1749,  1750,  1751,  1752,  1753,  1754,  1758,  1776,  1780,
    1785,  1794,  1800,  1800,  1803,  1823,  1827,  1832,  1840,  1845,
    1849,  1857,  1860,  1868,  1881,  1885,  1896,  1899,  1907,  1925,
    1929,  1936,  1941,  1946,  1954,  1960,  1968,  1976,  1983,  1997,
    2001,  2015,  2024,  2032,  2035,  2042,  2077,  2081,  2086,  2092,
    2102,  2105,  2113,  2116,  2123,  2141,  2145,  2152,  2157,  2165,
    2183,  2187,  2195,  2217,  2221,  2228,  2236,  2245,  2253,  2291,
    2295,  2302,  2309,  2318,  2327,  2354,  2358,  2365,  2377,  2404,
    2408,  2415,  2425,  2437,  2441,  2446,  2455,  2468,  2472,  2477,
    2486,  2500,  2504,  2517,  2522,  2534,  2538,  2546,  2559,  2567,
    2580,  2587,  2601,  2601,  2604,  2604,  2626,  2630,  2634,  2652,
    2670,  2680,  2694,  2702,  2708,  2714,  2720,  2732,  2735,  2749,
    2750,  2755,  2757,  2758,  2759,  2763,  2783,  2800,  2803,  2807,
    2819,  2821,  2825,  2829,  2833,  2837,  2841,  2847,  2853,  2857,
    2861,  2875,  2876,  2877,  2878,  2879,  2880,  2881,  2882,  2886,
    2886,  2889,  2893,  2901,  2906,  2915,  2920,  2929,  3010,  3018,
    3023,  3032,  3037,  3046,  3056,  3060,  3068,  3072,  3080,  3096,
    3105,  3117,  3126,  3129,  3134,  3143,  3147,  3155,  3165,  3177,
    3182,  3192,  3195,  3202,  3202,  3206,  3218,  3225,  3229,  3237,
    3246,  3250,  3258,  3261,  3269,  3270,  3278,  3285,  3292,  3297,
    3306,  3311,  3321,  3329,  3337,  3350,  3365,  3372,  3373,  3374,
    3375,  3376,  3377,  3378,  3379,  3380,  3381,  3382,  3383,  3388,
    3432,  3433,  3446,  3453,  3453,  3456,  3456,  3456,  3461,  3468,
    3472,  3476,  3488,  3491,  3502,  3505,  3515,  3522,  3526,  3530,
    3534,  3543,  3551,  3559,  3564,  3572,  3576,  3582,  3589,  3604,
    3619,  3622,  3626,  3634,  3642,  3646,  3655,  3663,  3674,  3678,
    3682,  3693,  3700,  3709,  3713,  3717,  3725,  3743,  3748,  3758,
    3761,  3769,  3777,  3786,  3791,  3800,  3810,  3814,  3818,  3818,
    3822,  3826,  3830,  3834,  3838,  3842,  3846,  3850,  3854,  3858,
    3862,  3866,  3870,  3875,  3879,  3883,  3887,  3894,  3899,  3906,
    3911,  3915,  3919,  3924,  3928,  3932,  3936,  3940,  3945,  3949,
    3953,  3958,  3962,  3966,  3971,  3988,  3993,  3998,  4003,  4007,
    4012,  4016,  4021,  4027,  4033,  4038,  4039,  4040,  4048,  4052,
    4056,  4064,  4071,  4080,  4080,  4084,  4104,  4105,  4113,  4114,
    4120,  4141,  4145,  4159,  4165,  4178,  4182,  4186,  4186,  4190,
    4191,  4200,  4201,  4207,  4208,  4217,  4229,  4240,  4244,  4248,
    4252,  4256,  4260,  4264,  4268,  4276,  4284,  4301,  4309,  4318,
    4322,  4326,  4330,  4334,  4342,  4354,  4359,  4364,  4371,  4376,
    4383,  4390,  4402,  4403,  4407,  4413,  4414,  4415,  4416,  4417,
    4418,  4419,  4420,  4421,  4425,  4425,  4428,  4428,  4428,  4432,
    4439,  4443,  4447,  4455,  4463,  4473,  4483,  4487,  4510,  4515,
    4525,  4526,  4535,  4539,  4548,  4548,  4548,  4552,  4558,  4567,
    4567,  4572,  4575,  4584,  4595,  4595,  4600,  4604,  4611,  4615,
    4626,  4629,  4634,  4643,  4646,  4650,  4662,  4665,  4670,  4679,
    4682,  4686,  4702,  4705,  4710,  4715,  4720,  4731,  4741,  4744,
    4749,  4759,  4760,  4774,  4775,  4776,  4777,  4778,  4779,  4780,
    4785,  4793,  4801,  4805,  4813,  4817,  4826,  4833,  4837,  4847,
    4855,  4863,  4871,  4878,  4886,  4893,  4897,  4905,  4913,  4916,
    4925,  4928,  4938,  4942,  4952,  4953,  4955,  4957,  4963,  4967,
    4968,  4969,  4970,  4975,  4991,  4992,  4993,  4994,  4995,  4996,
    4997,  4998,  4999,  5000,  5005,  5013,  5017,  5024,  5035,  5043,
    5051,  5060,  5064,  5068,  5076,  5080,  5084,  5092,  5093,  5101,
    5109,  5114,  5118,  5122,  5126,  5135,  5136,  5144,  5151,  5154,
    5157,  5160,  5164,  5176,  5192,  5194,  5201,  5204,  5213,  5225,
    5230,  5242,  5247,  5251,  5256,  5261,  5266,  5267,  5276,  5281,
    5285,  5291,  5295,  5303,  5308,  5318,  5321,  5325,  5329,  5333,
    5337,  5345,  5347,  5358,  5364,  5370,  5376,  5391,  5395,  5399,
    5403,  5407,  5411,  5415,  5419,  5427,  5431,  5435,  5443,  5447,
    5455,  5456,  5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,
    5483,  5487,  5491,  5495,  5504,  5508,  5516,  5520,  5530,  5534,
    5538,  5542,  5546,  5554,  5556,  5563,  5567,  5571,  5575,  5585,
    5589,  5593,  5601,  5603,  5611,  5615,  5622,  5626,  5634,  5638,
    5646,  5654,  5658,  5666,  5673,  5681,  5686,  5691,  5703,  5707,
    5711,  5715,  5719,  5725,  5725,  5730,  5736,  5736,  5741,  5745,
    5755,  5763,  5770,  5775,  5783,  5792,  5800,  5808,  5817,  5824,
    5833,  5845,  5850,  5855,  5861,  5867,  5873,  5883,  5886,  5894,
    5898,  5906,  5910,  5918,  5923,  5932,  5936,  5940,  5948,  5952,
    5960,  5964,  5968,  5972,  5980,  5984,  5988,  5996,  6001,  6011,
    6024,  6024,  6028,  6036,  6047,  6052,  6076,  6076,  6080,  6086,
    6088,  6092,  6096,  6103,  6108,  6117,  6126,  6126,  6130,  6134,
    6141,  6147,  6157,  6165,  6170,  6176,  6176,  6180,  6188,  6195,
    6196,  6204,  6213,  6217,  6225,  6233,  6243,  6254,  6257,  6265,
    6275,  6282,  6289,  6294,  6303,  6306,  6313,  6320,  6324,  6328,
    6338,  6342,  6352,  6356,  6360,  6364,  6368,  6372,  6376,  6380,
    6384,  6388,  6392,  6396,  6400,  6404,  6408,  6412,  6416,  6420,
    6424,  6428,  6432,  6436,  6444,  6450,  6454,  6458,  6462,  6466,
    6474,  6477,  6481,  6485,  6493,  6497,  6508,  6508,  6508,  6508,
    6508,  6508,  6508,  6508,  6509,  6509,  6509,  6509,  6509,  6509,
    6510,  6514,  6514,  6514,  6514,  6514,  6514,  6514,  6514,  6514,
    6514,  6515,  6515,  6515,  6515,  6515,  6515,  6515,  6516,  6516,
    6516,  6516,  6516,  6516,  6516,  6516,  6517,  6517,  6517,  6517,
    6517,  6517,  6517,  6517,  6517,  6517,  6517,  6518,  6518,  6518,
    6518,  6518,  6518,  6518,  6518,  6518,  6518,  6518,  6518,  6519,
    6519,  6519,  6519,  6519,  6519,  6519,  6519,  6519,  6519,  6520,
    6520,  6520,  6520,  6520,  6520,  6520,  6520,  6520,  6520,  6520,
    6520,  6521,  6521,  6521,  6521,  6521,  6521,  6521,  6521,  6521,
    6521,  6521,  6521,  6522,  6522,  6522,  6522,  6522,  6522,  6522,
    6522,  6522,  6523,  6523,  6523,  6523,  6523,  6523,  6523,  6523,
    6524,  6524,  6524,  6524,  6524,  6524,  6524,  6524,  6524,  6524,
    6524,  6525,  6525,  6525,  6525,  6525,  6525,  6525,  6525,  6525,
    6526,  6526,  6526,  6526,  6526,  6526,  6526,  6526,  6526,  6526,
    6527,  6527,  6527,  6527,  6527,  6527,  6527,  6527,  6527,  6527,
    6527,  6528,  6528,  6528,  6528,  6528,  6528,  6528,  6528,  6528,
    6528,  6528,  6529,  6529,  6529,  6529,  6529,  6529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"<end of file>\"", "error", "$undefined", "\"<Language: XPath2>\"",
  "\"<Language: XQuery>\"", "\"<Language: XSLT 2.0>\"",
  "\"<Language: Function Declaration>\"", "\"<Language: Delayed Module>\"",
  "\"<Language: Function Signature>\"", "\"<Language: Rewrite Rule>\"",
  "\"<Language: Rewrite Pattern>\"", "\"<Language: SequenceType>\"",
  "\"<Language: Carrot>\"", "\"$\"", "\":=\"", "\"*\"", "\"|\"", "\"!=\"",
  "\"<=\"", "\"> (comparison operator)\"", "\">=\"", "\"<<\"", "\">>\"",
  "\"::\"", "\"@\"", "\"[\"", "\"]\"", "\"?\"", "\"<\"",
  "\"> (start tag close)\"", "\"> (end tag close)\"", "\"<?\"", "\"<!--\"",
  "\"-->\"", "\"//\"", "\"</\"", "\"(#\"", "\",\"", "\"+\"", "\"-\"",
  "\"/\"", "\"= (comparison operator)\"", "\".\"", "\"..\"", "\"(\"",
  "\")\"", "\"/>\"", "\"=\"", "\"\\\" (open)\"", "\"\\\" (close)\"",
  "\"' (open)\"", "\"' (close)\"", "\"{\"", "\"}\"", "\";\"", "\"#\"",
  "\"%\"", "\":\"", "\"~\"", "\"->\"", "\"||\"", "\"!\"", "\"^\"",
  "\"<integer literal>\"", "\"<decimal literal>\"", "\"<double literal>\"",
  "\"attribute\"", "\"comment\"", "\"document-node\"",
  "\"namespace-node\"", "\"node\"", "\"processing-instruction\"",
  "\"schema-attribute\"", "\"schema-element\"", "\"text\"",
  "\"empty-sequence\"", "\"boundary-space\"", "\"ft-option\"",
  "\"base-uri\"", "\"lax\"", "\"strict\"", "\"idiv\"", "\"child\"",
  "\"descendant\"", "\"self\"", "\"descendant-or-self\"",
  "\"following-sibling\"", "\"following\"", "\"parent\"", "\"ancestor\"",
  "\"preceding-sibling\"", "\"preceding\"", "\"ancestor-of-self\"",
  "\"document\"", "\"not\"", "\"using\"", "\"no\"", "\"sensitive\"",
  "\"insensitive\"", "\"diacritics\"", "\"without\"",
  "\"without (followed by content)\"", "\"stemming\"", "\"thesaurus\"",
  "\"stop\"", "\"wildcards\"", "\"entire\"", "\"content\"", "\"word\"",
  "\"type\"", "\"start\"", "\"end\"", "\"most\"", "\"skip\"", "\"copy\"",
  "\"value\"", "\"<whitespace>\"", "\"<processing instruction content>\"",
  "\"<xml comment content>\"", "\"eq\"", "\"ne\"", "\"lt\"", "\"le\"",
  "\"gt\"", "\"ge\"", "\"at\"", "\"<quot attribute content>\"",
  "\"<apos attribute content>\"", "\"<whitespace element content>\"",
  "\"<element content>\"", "\"at (followed by least or most)\"",
  "\"ordered\"", "\"unordered\"", "\"<qualified name>\"",
  "\"<xmlns qualified name>\"",
  "\"<computed constructor qualified name>\"", "\"<string literal>\"",
  "\"variable\"", "\"<NCName>:*\"", "\"*:<NCName>\"",
  "\"<processing instruction target>\"", "\"<pragma content>\"",
  "\"return\"", "\"for\"", "\"in\"", "\"let\"", "\"where\"", "\"count\"",
  "\"by\"", "\"order\"", "\"stable\"", "\"ascending\"", "\"descending\"",
  "\"empty\"", "\"greatest\"", "\"least\"", "\"collation\"", "\"some\"",
  "\"every\"", "\"satisfies\"", "\"typeswitch\"", "\"case\"",
  "\"case (followed by (in)sensitive)\"", "\"as\"", "\"if\"", "\"then\"",
  "\"else\"", "\"or\"", "\"and\"", "\"instance\"", "\"of\"",
  "\"castable\"", "\"to\"", "\"div\"", "\"mod\"", "\"union\"",
  "\"intersect\"", "\"except\"", "\"validate\"", "\"cast\"", "\"treat\"",
  "\"is\"", "\"preserve\"", "\"strip\"", "\"namespace\"", "\"item\"",
  "\"external\"", "\"encoding\"", "\"no-preserve\"", "\"inherit\"",
  "\"no-inherit\"", "\"declare\"", "\"construction\"", "\"ordering\"",
  "\"default\"", "\"copy-namespaces\"", "\"option\"", "\"xquery\"",
  "\"version\"", "\"import\"", "\"schema\"", "\"module\"", "\"element\"",
  "\"function\"", "\"function (XQuery 3.0)\"", "\"score\"", "\"contains\"",
  "\"weight\"", "\"window\"", "\"distance\"", "\"occurs\"", "\"times\"",
  "\"same\"", "\"different\"", "\"lowercase\"", "\"uppercase\"",
  "\"relationship\"", "\"levels\"", "\"language\"", "\"any\"", "\"all\"",
  "\"phrase\"", "\"exactly\"", "\"from\"", "\"words\"", "\"sentences\"",
  "\"paragraphs\"", "\"sentence\"", "\"paragraph\"", "\"replace\"",
  "\"modify\"", "\"first\"", "\"insert\"", "\"before\"", "\"after\"",
  "\"revalidation\"", "\"with\"", "\"nodes\"", "\"rename\"", "\"last\"",
  "\"delete\"", "\"into\"", "\"updating\"", "\"id\"", "\"key\"",
  "\"template\"", "\"matches\"", "\"tuple\"", "\"map\"", "\"name\"",
  "\"call\"", "\"apply\"", "\"templates\"", "\"mode\"", "\"ftor\"",
  "\"ftand\"", "\"ftnot\"", "\"type-alias\"", "\"<XSLT end element>\"",
  "\"<xsl:stylesheet...\"", "\"<xsl:template...\"", "\"<xsl:value-of...\"",
  "\"<xsl:text...\"", "\"<xsl:apply-templates...\"",
  "\"<xsl:call-template...\"", "\"<xsl:with-param...\"",
  "\"<xsl:sequence...\"", "\"<xsl:param...\"", "\"<xsl:function...\"",
  "\"<xsl:choose...\"", "\"<xsl:when...\"", "\"<xsl:otherwise...\"",
  "\"<xsl:if...\"", "\"<xsl:variable...\"", "\"<xsl:comment...\"",
  "\"<xsl:processing-instruction...\"", "\"<xsl:document...\"",
  "\"<xsl:attribute...\"", "\"<xsl:namespace...\"", "\"<xsl:element...\"",
  "\"<xsl:analyze-string...\"", "\"<xsl:matching-substring...\"",
  "\"<xsl:non-matching-substring...\"", "\"<xsl:copy-of...\"",
  "\"<xsl:copy...\"", "\"<xsl:for-each...\"", "\"<xsl:output...\"",
  "\"<xsl:import-schema...\"", "\"<xsl:type-alias...\"",
  "\"version='...'\"", "\"mode='...'\"", "\"name='...'\"",
  "\"doctype-public='...'\"", "\"doctype-system='...'\"",
  "\"encoding='...'\"", "\"media-type='...'\"",
  "\"normalization-form='...'\"", "\"standalone='...'\"",
  "\"exclude-result-prefixes='...'\"", "\"namespace='...' (string)\"",
  "\"schema-location='...'\"", "\"tunnel='...'\"", "\"required='...'\"",
  "\"override='...'\"", "\"copy-namespaces='...'\"",
  "\"inherit-namespaces='...'\"", "\"byte-order-mark='...'\"",
  "\"escape-uri-attributes='...'\"", "\"include-content-type='...'\"",
  "\"indent='...'\"", "\"omit-xml-declaration='...'\"",
  "\"undeclare-prefixes='...'\"", "\"match='...'\"", "\"as='...'\"",
  "\"select='...'\"", "\"priority='...'\"", "\"test='...'\"",
  "\"separator='...'\"", "\"namespace='...' (attribute value template)\"",
  "\"regex='...'\"", "\"flags='...'\"", "\"method='...'\"",
  "\"cdata-section-elements='...'\"", "\"use-character-maps='...'\"",
  "\"<XSLT element name>\"", "\"<XSLT XMLNS attr>\"",
  "\"<XSLT attr name>\"", "\"<XSLT text node>\"",
  "\"<XSLT whitespace text node>\"", "\"#default\"", "\"#all\"",
  "\"#current\"", "\"xml\"", "\"html\"", "\"xhtml\"", "$accept",
  "SelectLanguage", "XQueryNamespaces", "Carrot", "CarrotProlog",
  "CarrotVarDecl", "CarrotFuncDecl", "CarrotTemplateDecl", "CarrotModes",
  "CarrotModeList", "CarrotTemplateParams", "PrimaryExpr", "CarrotApply",
  "CarrotApplyOptionalExpr", "CarrotApplyMode", "CarrotApplyArgs",
  "Start_FunctionDecl", "FunctionDecl_MaybeSemicolon",
  "Start_FunctionSignature", "Start_DelayedModule", "DM_ModuleDecl",
  "DM_Prolog", "DM_FunctionDecl", "DM_OptionDecl", "DM_NamespaceDecl",
  "Start_XSLT", "Stylesheet_XSLT", "StylesheetAttrs_XSLT",
  "StylesheetContent_XSLT", "Template_XSLT", "TemplateAttrs_XSLT",
  "TemplateModes_XSLT", "Number_XSLT", "Function_XSLT",
  "FunctionAttrs_XSLT", "ParamList_XSLT", "Param_XSLT", "ParamAttrs_XSLT",
  "GlobalParam_XSLT", "GlobalParamAttrs_XSLT", "GlobalVariable_XSLT",
  "GlobalVariableAttrs_XSLT", "Output_XSLT", "OutputAttrs_XSLT",
  "OutputMethod_XSLT", "QNames_XSLT", "TypeAlias_XSLT",
  "TypeAliasAttrs_XSLT", "ImportSchema_XSLT", "ImportSchemaAttrs_XSLT",
  "LiteralResultElement_XSLT", "LiteralResultElementAttrs_XSLT",
  "AttrValueTemplate_XSLT", "SequenceConstructor_XSLT", "Instruction_XSLT",
  "ValueOf_XSLT", "ValueOfAttrs_XSLT", "Text_XSLT", "TextNode_XSLT",
  "ApplyTemplates_XSLT", "ApplyTemplatesAttrs_XSLT",
  "ApplyTemplatesMode_XSLT", "ApplyTemplatesContent_XSLT",
  "CallTemplate_XSLT", "CallTemplateAttrs_XSLT",
  "CallTemplateContent_XSLT", "WithParam_XSLT", "WithParamAttrs_XSLT",
  "Sequence_XSLT", "SequenceAttrs_XSLT", "If_XSLT", "IfAttrs_XSLT",
  "Choose_XSLT", "WhenList_XSLT", "When_XSLT", "WhenAttrs_XSLT",
  "Otherwise_XSLT", "AnalyzeString_XSLT", "AnalyzeStringAttrs_XSLT",
  "MatchingSubstring_XSLT", "NonMatchingSubstring_XSLT", "Variable_XSLT",
  "VariableAttrs_XSLT", "Comment_XSLT", "CommentAttrs_XSLT", "PI_XSLT",
  "PIAttrs_XSLT", "Document_XSLT", "DocumentAttrs_XSLT", "Attribute_XSLT",
  "AttributeAttrs_XSLT", "Namespace_XSLT", "NamespaceAttrs_XSLT",
  "Element_XSLT", "ElementAttrs_XSLT", "CopyOf_XSLT", "CopyOfAttrs_XSLT",
  "Copy_XSLT", "CopyAttrs_XSLT", "ForEach_XSLT", "ForEachAttrs_XSLT",
  "Pattern_XSLT", "PathPattern_XSLT", "PathPatternStart_XSLT",
  "IdKeyPattern_XSLT", "IdValue_XSLT", "KeyValue_XSLT",
  "RelativePathPattern_XSLT", "PatternStep_XSLT", "PatternAxis_XSLT",
  "PatternStepPredicateList_XSLT", "Module", "VersionDecl", "Version",
  "Encoding", "MainModule", "LibraryModule", "ModuleDecl", "Prolog",
  "Setter", "Import", "Separator", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "PreserveMode", "InheritMode",
  "DefaultCollationDecl", "BaseURIDecl", "SchemaImport",
  "ResourceLocations", "SchemaPrefix", "ModuleImport", "ConstructionDecl",
  "AnnotatedDeclAnnotations", "AnnotatedDeclAnnotation",
  "CompatibilityAnnotation", "VarDecl", "VarDeclValue", "FunctionDecl",
  "FunctionParamList", "FunctionDeclReturnType", "FunctionBody",
  "Annotation", "AnnotationArgs", "ParamList", "Param", "EnclosedExpr",
  "QueryBody", "Expr", "ExprSingle", "FLWORExpr", "FLWORTuples",
  "InitialClause", "IntermediateClause", "ForClause", "ForBindingList",
  "ForBinding", "PositionalVar", "FTScoreVar", "LetClause",
  "LetBindingList", "LetBinding", "WhereClause", "CountClause",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderExpr",
  "OrderDirection", "EmptyHandling", "QuantifiedExpr",
  "QuantifyBindingList", "QuantifyBinding", "TypeswitchExpr",
  "CaseClauseList", "DefaultCase", "CaseClause", "CaseSequenceTypeUnion",
  "CaseClauseVariable", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr",
  "$@1", "FTContainsExpr", "StringConcatExpr", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "ValueExpr", "ValidateExpr", "ExtensionExpr", "PragmaList", "Pragma",
  "PragmaContents", "PathExpr", "LeadingSlash", "RelativePathExpr",
  "StepExpr", "AxisStep", "ForwardStepPredicateList",
  "ReverseStepPredicateList", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "AbbrevReverseStep",
  "NodeTest", "NameTest", "Wildcard", "PostfixExpr", "Literal",
  "NumericLiteral", "VarRef", "VarName", "ParenthesizedExpr",
  "ContextItemExpr", "OrderedExpr", "UnorderedExpr", "FunctionCall",
  "FunctionCallArgumentList", "Argument", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemConstructorQName",
  "DirAttributeList", "OptionalWhitespace", "DirAttributeValue",
  "LiteralDirAttributeValue", "QuotAttrValueContent",
  "LiteralQuotAttrValueContent", "AposAttrValueContent",
  "LiteralAposAttrValueContent", "DirElementContent",
  "DirCommentConstructor", "DirCommentContents", "DirPIConstructor",
  "DirPIContents", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompElementName", "ContentExpr",
  "CompAttrConstructor", "CompAttrName", "CompNamespaceConstructor",
  "CompTextConstructor", "CompCommentConstructor", "CompPIConstructor",
  "CompPINCName", "CompPIConstructorContent", "SingleType",
  "SingleTypeOccurrence", "TypeDeclaration", "SequenceType",
  "OccurrenceIndicator", "ItemType", "AtomicType", "KindTest",
  "AnyKindTest", "DocumentTest", "TextTest", "CommentTest",
  "NamespaceNodeTest", "PITest", "AttributeTest", "AttribNameOrWildcard",
  "SchemaAttributeTest", "AttributeDeclaration", "ElementTest",
  "ElementNameOrWildcard", "SchemaElementTest", "ElementDeclaration",
  "AttributeName", "ElementName", "TypeName", "URILiteral", "FTSelection",
  "FTSelectionWeight", "FTPosFilters", "FTOr", "FTAnd", "FTMildnot",
  "FTUnaryNot", "FTPrimaryWithOptions", "FTPrimary", "FTWords",
  "FTExtensionSelection", "FTAnyallOption", "FTTimes", "FTRange",
  "FTPosFilter", "FTUnit", "FTBigUnit", "FTMatchOptions", "FTMatchOption",
  "FTCaseOption", "FTDiacriticsOption", "FTStemOption",
  "FTThesaurusOption", "FTThesaurusIDList", "FTThesaurusID",
  "FTStopWordOption", "FTStopWordsInclExclList", "FTStopWords",
  "FTStopWordsStringList", "FTStopWordsInclExcl", "FTLanguageOption",
  "FTWildCardOption", "FTExtensionOption", "FTIgnoreOption",
  "RevalidationDecl", "InsertExpr", "InsertExprBegin", "DeleteExpr",
  "DeleteExprBegin", "ReplaceExpr", "RenameExpr", "TransformExpr",
  "TransformBindingList", "TransformBinding", "IntegerLiteral",
  "DecimalLiteral", "DoubleLiteral", "StringLiteral", "NCName", "QName",
  "TemplateDecl", "TemplateSequenceType", "TemplateParamList",
  "TemplateDeclModesSection", "TemplateDeclModes", "TemplateDeclMode",
  "CallTemplateExpr", "ApplyTemplatesExpr", "ApplyTemplatesMode",
  "TemplateArgumentList", "TemplateArgument", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "DynamicFunctionInvocation",
  "FunctionTest", "AnyFunctionTest", "Annotations", "TypedFunctionTest",
  "FunctionTypeArguments", "ParenthesizedItemType", "TupleTest",
  "TupleTestEntryList", "TupleTestEntry", "MapTest", "TupleConstructor",
  "TupleEntryList", "TupleEntry", "MapConstructor", "MapEntryList",
  "MapEntry", "TupleMemberExpr", "TypeAlias", "RewriteRule",
  "RewritePattern", "RW_Rule", "RW_WhereCondition", "RW_Case",
  "RW_Pattern", "RW_OrExpr", "RW_AndExpr", "RW_ComparisonExpr",
  "RW_AdditiveExpr", "RW_MultiplicativeExpr", "RW_UnaryExpr",
  "RW_PostfixExpr", "RW_PrimaryExpr", "RW_OptionalCommaList",
  "RW_CommaList", "RW_Result", "QNameValue", "FunctionName", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   335,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   337,   338,   339,   339,   339,   339,   340,   341,
     342,   343,   343,   344,   344,   345,   345,   346,   347,   348,
     348,   349,   349,   350,   350,   351,   352,   352,   353,   354,
     355,   356,   356,   356,   356,   357,   358,   359,   360,   361,
     361,   362,   362,   362,   363,   363,   363,   363,   363,   363,
     363,   363,   364,   365,   365,   365,   365,   365,   365,   366,
     366,   366,   366,   367,   367,   367,   368,   369,   369,   369,
     369,   370,   370,   371,   372,   372,   372,   372,   372,   372,
     373,   374,   374,   374,   374,   374,   374,   375,   376,   376,
     376,   376,   377,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   379,   379,   379,   379,   379,   380,   380,   381,   382,
     382,   382,   383,   384,   384,   384,   384,   384,   385,   386,
     386,   386,   387,   387,   387,   388,   388,   388,   388,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   390,   391,   391,
     391,   392,   393,   393,   394,   395,   395,   395,   396,   396,
     396,   397,   397,   398,   399,   399,   400,   400,   401,   402,
     402,   402,   402,   402,   403,   404,   405,   406,   407,   408,
     408,   409,   410,   411,   411,   412,   413,   413,   413,   413,
     414,   414,   415,   415,   416,   417,   417,   417,   417,   418,
     419,   419,   420,   421,   421,   421,   422,   423,   424,   425,
     425,   425,   425,   425,   426,   427,   427,   427,   428,   429,
     429,   429,   430,   431,   431,   431,   432,   433,   433,   433,
     434,   435,   435,   436,   436,   437,   437,   437,   438,   438,
     439,   439,   440,   440,   441,   441,   442,   442,   442,   442,
     442,   442,   443,   444,   444,   444,   444,   445,   445,   446,
     446,   447,   447,   447,   447,   448,   449,   450,   451,   452,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   454,   454,   454,   454,   454,   454,   454,   454,   455,
     455,   456,   457,   458,   458,   459,   459,   460,   461,   462,
     462,   463,   463,   464,   465,   465,   466,   466,   467,   468,
     469,   469,   470,   470,   470,   471,   471,   472,   472,   473,
     473,   474,   474,   475,   475,   476,   477,   478,   478,   479,
     480,   480,   481,   481,   482,   482,   483,   483,   484,   484,
     485,   485,   486,   487,   488,   489,   489,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   491,
     492,   492,   492,   493,   493,   494,   494,   494,   495,   496,
     496,   497,   498,   498,   499,   499,   500,   501,   501,   502,
     502,   503,   504,   505,   505,   506,   506,   507,   507,   508,
     509,   509,   509,   510,   510,   510,   511,   511,   512,   512,
     513,   514,   515,   515,   516,   516,   517,   518,   518,   519,
     519,   520,   521,   521,   522,   522,   523,   523,   524,   523,
     523,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     523,   523,   523,   525,   525,   525,   526,   526,   527,   527,
     528,   528,   528,   529,   529,   529,   529,   529,   530,   530,
     530,   531,   531,   531,   532,   532,   533,   533,   534,   534,
     535,   535,   536,   536,   536,   537,   537,   537,   538,   538,
     538,   539,   539,   540,   540,   541,   542,   542,   543,   543,
     543,   543,   544,   545,   545,   545,   545,   546,   546,   547,
     547,   548,   548,   549,   549,   550,   550,   551,   551,   551,
     551,   551,   551,   551,   551,   552,   552,   553,   553,   554,
     554,   554,   554,   554,   555,   556,   556,   557,   557,   558,
     558,   558,   559,   559,   559,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   560,   560,   561,   561,   561,   562,
     563,   564,   564,   565,   566,   567,   568,   568,   569,   569,
     570,   570,   571,   571,   572,   572,   572,   573,   573,   574,
     574,   575,   575,   575,   576,   576,   577,   577,   578,   578,
     579,   579,   579,   580,   580,   580,   581,   581,   581,   582,
     582,   582,   583,   583,   583,   583,   583,   584,   585,   585,
     586,   587,   587,   588,   588,   588,   588,   588,   588,   588,
     589,   590,   591,   591,   592,   592,   593,   594,   594,   595,
     596,   597,   598,   599,   599,   600,   600,   601,   602,   602,
     603,   603,   604,   604,   605,   605,   605,   605,   606,   606,
     606,   606,   606,   607,   608,   608,   608,   608,   608,   608,
     608,   608,   608,   608,   609,   610,   610,   610,   611,   612,
     613,   614,   614,   614,   615,   615,   615,   616,   616,   617,
     618,   619,   619,   619,   619,   620,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   628,   629,   629,   630,   630,
     631,   631,   632,   632,   633,   633,   634,   634,   635,   635,
     635,   636,   636,   637,   637,   638,   638,   638,   638,   638,
     638,   639,   639,   640,   640,   640,   640,   641,   641,   641,
     641,   641,   641,   641,   641,   642,   642,   642,   643,   643,
     644,   644,   645,   645,   645,   645,   645,   645,   645,   645,
     646,   646,   646,   646,   647,   647,   648,   648,   649,   649,
     649,   649,   649,   650,   650,   651,   651,   651,   651,   652,
     652,   652,   653,   653,   654,   654,   655,   655,   656,   656,
     657,   658,   658,   659,   660,   661,   661,   661,   662,   662,
     662,   662,   662,   663,   663,   664,   665,   665,   666,   666,
     667,   668,   669,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   677,   677,   677,   677,   677,   678,   678,   679,
     679,   680,   680,   681,   681,   682,   682,   682,   683,   683,
     684,   684,   684,   684,   685,   685,   685,   686,   686,   687,
     688,   688,   689,   690,   691,   691,   692,   692,   693,   694,
     694,   695,   695,   696,   696,   697,   606,   606,   698,   698,
     699,   699,   700,   701,   701,   346,   346,   702,   702,   703,
     703,   704,   705,   705,   706,   706,   707,   559,   708,   709,
     710,   711,   712,   712,   713,   713,   714,   715,   715,   716,
     716,   717,   717,   718,   718,   718,   718,   718,   718,   718,
     719,   719,   719,   720,   720,   720,   720,   720,   721,   721,
     721,   722,   722,   723,   723,   723,   723,   723,   723,   723,
     724,   724,   725,   725,   726,   346,   727,   727,   727,   727,
     727,   727,   727,   727,   727,   727,   727,   727,   727,   727,
     727,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     3,     2,     3,     2,     2,     2,
       2,     3,     0,     1,     0,     3,     3,     3,     5,     5,
       9,     0,     1,     1,     3,     0,     2,     1,     6,     0,
       1,     0,     1,     0,     2,     8,     0,     1,     3,     3,
       6,     0,     2,     2,     2,     8,     5,     6,     1,     4,
       1,     0,     2,     2,     0,     2,     2,     2,     2,     2,
       2,     2,     4,     1,     3,     2,     3,     3,     3,     0,
       2,     2,     2,     1,     1,     1,     4,     1,     2,     3,
       2,     0,     2,     3,     1,     2,     3,     3,     2,     2,
       3,     1,     2,     3,     3,     2,     2,     3,     1,     2,
       3,     3,     2,     1,     2,     3,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     3,     2,     1,     2,     2,     3,     3,     4,     0,
       3,     2,     0,     2,     2,     0,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     3,     1,     1,     3,     1,     3,     3,     1,     1,
       1,     0,     2,     3,     1,     2,     0,     2,     3,     1,
       2,     3,     3,     2,     2,     3,     3,     3,     4,     1,
       2,     3,     3,     0,     3,     4,     1,     3,     3,     3,
       0,     3,     0,     3,     4,     1,     2,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     2,     1,     3,     2,     3,     1,     2,     2,
       3,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       4,     6,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     2,     1,     3,     3,     2,     0,     4,     2,
       2,     0,     3,     4,     3,     2,     2,     2,     2,     6,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     5,     5,     4,     3,     3,
       3,     5,     5,     5,     1,     1,     1,     1,     4,     3,
       5,     4,     0,     2,     3,     3,     3,     7,     4,     3,
       3,     0,     2,     1,     1,     1,     7,     2,     1,     7,
       2,     3,     0,     2,     1,     1,     2,     5,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     2,     3,
       1,     7,     0,     3,     0,     3,     2,     3,     1,     5,
       5,     2,     3,     3,     4,     3,     1,     3,     5,     1,
       0,     1,     1,     0,     2,     2,     4,     4,     3,     1,
       5,     6,     2,     1,     5,     3,     3,     3,     3,     0,
       3,     8,     3,     1,     3,     1,     3,     3,     0,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     5,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     2,     1,     1,     1,     1,     4,     5,
       5,     3,     4,     1,     2,     4,     1,     2,     1,     2,
       2,     1,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     4,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     2,     1,     4,     4,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     5,    10,     1,
       1,     0,     7,     7,     0,     1,     3,     3,     3,     3,
       0,     2,     2,     0,     2,     2,     0,     2,     2,     0,
       2,     2,     0,     2,     2,     2,     2,     3,     0,     1,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     3,     2,     3,     3,     1,     3,     3,
       4,     4,     3,     1,     3,     2,     3,     2,     0,     1,
       0,     2,     2,     3,     0,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     3,     4,     4,     3,     4,     6,     1,     1,     4,
       1,     3,     4,     6,     7,     1,     1,     4,     1,     1,
       1,     1,     1,     3,     0,     2,     0,     2,     3,     1,
       3,     1,     4,     1,     2,     1,     1,     2,     2,     3,
       1,     2,     4,     3,     4,     0,     1,     2,     1,     2,
       1,     0,     3,     2,     3,     3,     4,     1,     3,     3,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     1,     2,     2,     2,
       5,     5,     2,     0,     3,     2,     4,     4,     6,     4,
       3,     4,     0,     2,     2,     3,     1,     3,     2,     2,
       2,     1,     2,     3,     3,     3,     3,     3,     6,     6,
       4,     4,     4,     2,     2,     2,     2,     2,     7,     5,
       5,     6,     3,     1,     4,     1,     1,     1,     1,     1,
       1,     5,     7,     8,    10,     6,     8,     0,     2,     2,
       3,     0,     2,     1,     3,     1,     1,     1,     3,     7,
       3,     7,     5,     9,     1,     1,     1,     1,     3,     5,
       1,     1,     3,     4,     3,     4,     1,     1,     5,     0,
       2,     6,     7,     1,     3,     3,     1,     1,     4,     3,
       1,     3,     2,     6,     3,     1,     1,     4,     3,     1,
       3,     4,     4,     3,     1,     3,     3,     1,     3,     5,
       1,     1,     5,     2,     0,     2,     3,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     2,     2,
       1,     4,     1,     4,     3,     2,     1,     1,     1,     1,
       0,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    12,     0,    12,    12,   341,     0,     0,   849,
      12,     0,     0,   539,     0,     0,     0,   608,     0,   584,
       0,     0,   502,   563,   534,     0,     0,    31,   805,   806,
     807,   927,   928,   929,   940,   933,   934,   935,   936,   937,
     939,   942,   943,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
    1042,  1043,   961,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,  1081,  1082,   941,
     808,   986,   540,   541,   987,   988,   989,   990,   991,   992,
     993,   994,   995,   996,   997,   998,   999,  1000,  1001,  1002,
    1003,   938,  1004,  1005,   932,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,   931,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
     930,  1040,     0,  1041,  1044,  1045,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1083,  1084,  1085,  1086,  1095,  1097,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1096,   542,    27,     2,   364,
     366,   367,     0,   380,   383,   384,   368,   369,   370,   376,
     433,   435,   452,   455,   457,   459,   462,   467,   470,   473,
     475,   477,   479,   481,   484,   485,   487,     0,   493,   486,
     498,   501,   506,   507,   509,   510,   511,     0,   516,   513,
       0,   528,   526,   536,   538,   508,   545,   554,   546,   547,
     548,   551,   552,   549,   550,   572,   574,   575,   576,   573,
     613,   614,   615,   616,   617,   618,   619,   535,   663,   654,
     661,   660,   662,   659,   656,   658,   655,   657,   371,     0,
     372,     0,   374,   373,   375,   556,   557,   558,   555,   537,
     377,   378,   553,   840,   841,   544,   865,   866,   877,   810,
     926,   281,    51,   139,     5,    48,    50,     0,   281,     7,
       0,   927,   928,   929,   940,   933,   934,   935,   936,   937,
     948,   949,   950,   951,   952,   953,   954,   955,   956,   957,
     958,   959,   977,  1081,  1082,   988,   990,  1001,  1002,   938,
     932,  1019,  1025,   930,  1067,  1070,  1076,  1078,  1095,  1097,
    1088,  1089,     8,   880,     0,   926,     0,     0,   920,     0,
     916,   917,   918,   919,     0,     9,   881,   888,   890,   892,
     899,   902,   907,   910,   912,     0,   849,   927,   928,   934,
     937,   939,   931,   930,  1095,  1097,    10,   644,   649,   650,
     653,   651,   846,     0,   847,   652,   856,   857,    14,     1,
     559,   560,   525,   579,   580,   581,     0,   609,     0,   500,
     585,     0,   483,   482,   562,     0,   925,   835,   836,     0,
      32,   834,   519,     0,     0,   627,     0,     0,     0,     0,
       0,     0,     0,     0,   633,     0,     0,     0,     0,     0,
     517,   518,   520,   521,   522,   523,   529,   530,   531,   532,
     533,     0,     0,     0,   803,     0,     0,     0,   388,   390,
       0,     0,   396,   398,     0,     0,   419,     0,     0,     0,
       0,     0,     0,   524,     0,     0,     0,   622,     0,     0,
     640,     0,     0,   793,   794,     0,   796,   797,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     385,   382,   386,   387,   381,     0,     0,     0,     0,     0,
       0,     0,     0,   438,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     494,   499,     0,     0,     0,     0,     0,   515,   527,     0,
       0,     0,     0,   795,     0,     0,     0,     3,   290,    54,
     145,   341,     4,     6,     0,     0,   345,   342,   343,   352,
     344,     0,   883,     0,   908,   909,   922,     0,   921,   915,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   920,     0,     0,     0,
       0,     0,   645,   647,   646,   642,     0,   850,    11,    13,
     584,     0,   611,   610,   607,     0,   561,    29,   678,   674,
       0,   677,   689,     0,     0,   626,   669,     0,   665,     0,
       0,     0,     0,   670,   664,   671,     0,     0,   809,     0,
       0,   632,     0,   680,     0,   688,   690,   668,     0,     0,
       0,     0,     0,     0,     0,   640,     0,   640,     0,     0,
     640,     0,     0,     0,     0,     0,     0,     0,     0,   629,
     686,   681,     0,   685,     0,   621,     0,   350,     0,   361,
     849,     0,     0,     0,     0,   868,     0,   869,   640,   873,
       0,     0,   874,   828,   830,   365,   379,   401,     0,     0,
       0,   432,   434,   437,   440,   441,   442,   450,   451,     0,
     436,   443,   444,   445,   446,   447,   448,   449,   456,     0,
     460,   461,   458,   463,   465,   464,   466,   468,   469,   471,
     472,   849,   849,     0,     0,   491,     0,   504,   503,   505,
       0,     0,   878,     0,   571,   844,   570,     0,   569,     0,
       0,     0,     0,   566,     0,   842,     0,     0,     0,     0,
       0,   279,   280,   290,     0,    52,    53,     0,   141,   142,
       0,     0,     0,    41,   356,   849,    38,   924,   884,   884,
     914,     0,     0,   889,   891,   900,   901,   893,   894,   897,
     898,   895,   896,   903,   905,   904,   906,     0,     0,   855,
     643,   648,   859,     0,   860,   640,   864,     0,   849,     0,
      21,     0,     0,     0,     0,   585,     0,   612,     0,   496,
     495,    33,    30,     0,   675,   628,   624,     0,   631,   666,
     667,   673,   672,   634,   635,     0,   679,   687,   630,   620,
       0,   802,     0,   564,   565,   392,   389,     0,     0,   397,
       0,   418,   416,   417,     0,     0,   488,     0,     0,     0,
     682,   623,   640,     0,   351,   641,     0,   843,     0,     0,
       0,     0,   867,     0,     0,     0,   872,     0,     0,     0,
     402,   409,   403,   406,   410,     0,   439,     0,     0,     0,
       0,   715,   453,   696,   699,   701,   703,   705,   706,   721,
     710,   474,   476,   478,   638,   480,   492,   512,   514,   543,
       0,   845,     0,     0,   792,   791,   790,   567,   286,   285,
     311,     0,   282,   284,     0,   288,  1031,  1038,     0,     0,
       0,   301,     0,     0,     0,   305,   306,   308,   302,   303,
     309,   310,   304,     0,     0,   287,   307,     0,     0,    49,
      63,    91,    77,    98,   103,   133,   129,    55,    81,    56,
      81,    57,   145,    58,   145,    59,     0,    61,     0,    60,
       0,   140,   138,   168,     0,   175,   184,     0,     0,     0,
     215,   220,   223,   227,   229,   235,   239,   206,   243,   247,
     251,   172,   173,   147,   148,   149,   145,   150,   146,   151,
     181,   152,   186,   153,     0,   155,   145,   154,   163,   210,
     156,   145,   157,   145,   158,   145,   159,   145,   160,   145,
     161,   145,   162,   145,   164,     0,   165,   145,   166,   145,
       0,     0,    39,     0,   353,     0,   886,     0,   923,     0,
     911,   913,     0,   858,   862,   849,     0,     0,   853,     0,
     640,   825,   826,   827,     0,    22,    23,    15,    16,    17,
     352,   584,   584,   602,   577,   497,     0,     0,     0,   691,
     625,   636,   804,     0,     0,   394,     0,     0,     0,   429,
       0,   423,     0,     0,   489,   490,     0,   362,   360,     0,
     799,     0,   800,   870,     0,   876,   875,     0,     0,   832,
       0,   411,   412,   413,   404,     0,     0,   704,     0,   716,
     718,   720,   711,     0,   454,     0,   694,     0,     0,     0,
     707,     0,   708,   639,   637,   568,     0,     0,   283,     0,
     341,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   821,     0,     0,     0,     0,   291,   292,   293,
     294,   298,   299,   295,   296,   297,   300,   134,   135,    69,
      65,     0,   849,     0,   145,    78,    80,   849,   145,    92,
      96,    95,   849,     0,     0,    99,   849,     0,     0,   102,
     120,   104,   108,   109,   110,   114,   115,   117,   106,   111,
     112,   113,   116,   118,     0,     0,     0,   128,   130,   849,
     132,   144,   143,     0,     0,     0,   203,   199,   145,     0,
       0,   142,     0,     0,     0,     0,   185,     0,   194,     0,
     145,     0,   142,   142,   212,   216,   849,     0,     0,     0,
       0,   142,     0,     0,     0,   142,     0,   142,   142,     0,
     142,     0,     0,   142,   142,     0,   242,   245,     0,   248,
     249,     0,     0,     0,     0,     0,   341,    42,    43,    44,
       0,   358,   885,   882,     0,   861,     0,   848,   849,   849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
     837,    28,   676,   801,     0,     0,     0,   399,   400,   420,
       0,   849,     0,   421,   422,   849,     0,     0,     0,   683,
     363,     0,   871,     0,     0,     0,   405,     0,   407,   709,
     715,   713,     0,   717,   719,     0,   698,     0,     0,   727,
       0,     0,     0,     0,     0,   693,   697,   700,     0,     0,
       0,   756,     0,     0,   781,     0,     0,   752,   753,     0,
     740,   746,   747,   745,   744,   748,   742,   743,   749,     0,
       0,     0,     0,     0,   788,   789,     0,   313,   314,   318,
     692,   329,     0,   339,   340,   319,   320,     0,     0,     0,
       0,   324,   325,     0,     0,   786,   785,   787,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   332,     0,   332,
     136,   137,    67,     0,   259,   258,   927,   948,  1083,  1084,
      64,   254,     0,   257,   255,   266,   277,   273,    68,    73,
      74,    75,    66,    84,    82,   145,     0,    79,     0,    94,
      93,    90,   101,   100,    97,   124,   125,   121,   122,   123,
     105,   126,   107,   119,   131,   171,   195,     0,   145,   200,
       0,     0,   197,   169,   170,   167,   178,   179,   180,   177,
     176,   174,   189,   182,   145,   183,   187,   196,     0,   207,
     208,   209,   145,     0,   218,   217,   145,   221,   219,   224,
     225,   222,   226,   230,   232,   233,   231,   228,   236,   237,
     234,   240,   241,   238,   244,   246,   252,   250,   352,     0,
       0,     0,     0,     0,   357,     0,   863,   851,   854,   849,
       0,    25,    24,     0,   584,   584,     0,   606,   605,   604,
     603,   640,     0,   393,     0,     0,     0,   427,     0,     0,
     428,   426,     0,   684,   798,   829,   831,     0,   414,   415,
       0,   712,   714,   784,   734,   732,   733,   695,     0,     0,
     738,   739,   730,   731,   702,   757,   762,     0,   782,   755,
     754,     0,     0,   759,   758,     0,   751,   750,     0,   780,
     741,     0,     0,   723,     0,   722,     0,     0,     0,   328,
       0,     0,     0,   317,   821,   822,   823,     0,   849,     0,
       0,     0,     0,   332,     0,   331,     0,   338,    70,    71,
      72,   276,     0,     0,     0,     0,     0,   267,     0,     0,
       0,     0,   272,    85,    89,    88,   849,     0,     0,    62,
      76,   127,   202,     0,   198,   201,   190,   193,   849,     0,
       0,   211,     0,   205,   214,     0,     0,     0,     0,     0,
     359,     0,   852,    18,     0,     0,    19,     0,     0,   584,
       0,   838,   395,   391,   430,     0,   425,   431,     0,   408,
     735,   736,   737,   728,   729,   770,   763,   763,   765,     0,
       0,   772,   772,   783,   725,   724,     0,   289,   312,   321,
     322,   315,   316,   326,   327,   323,     0,   811,   817,     0,
       0,     0,   879,   640,   352,   335,   336,   330,   333,     0,
       0,   275,   274,     0,   263,   262,     0,   253,   269,   268,
     271,   270,     0,    87,    86,    83,   204,   192,   191,   188,
     213,    36,    40,     0,     0,     0,   887,    26,   352,   590,
     596,   582,   593,   599,   583,     0,     0,     0,   833,     0,
       0,     0,     0,     0,   776,   774,   771,   769,   726,   819,
       0,   849,     0,     0,   824,   815,   817,     0,     0,   334,
     332,   260,     0,     0,    35,    37,     0,    46,   352,     0,
       0,     0,     0,     0,   578,   839,   424,     0,   761,   760,
     766,   767,     0,   775,     0,     0,   773,   820,   818,   812,
       0,     0,     0,   348,   346,   355,   349,   354,   337,     0,
     264,   265,   278,    47,     0,     0,   586,   592,   591,   587,
     598,   597,   588,   595,   594,   589,   601,   600,   764,     0,
     777,   778,   779,   813,   817,   816,   347,   261,     0,    20,
     768,     0,    45,   814
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,   311,   618,   619,   821,   822,   823,  1064,  1065,
    1645,   206,   207,   831,   429,  1077,   572,  1764,   319,   573,
     783,  1042,  1267,  1268,  1269,   314,   315,   569,   777,   967,
     968,  1402,  1422,   969,   970,  1174,  1424,  1425,   971,   972,
     973,   974,   975,   976,  1440,  1442,   977,   978,   979,   980,
    1003,   570,   981,   780,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1459,  1225,  1011,  1012,  1227,  1463,  1464,  1013,  1014,
    1015,  1016,  1017,  1216,  1217,  1218,  1450,  1018,  1019,  1234,
    1473,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,
    1039,  1410,  1411,  1412,  1413,  1703,  1799,  1414,  1415,  1416,
    1612,   567,   568,   768,   769,   771,   772,   773,   774,   938,
     939,   932,   940,   941,   942,   943,   944,   945,   946,   947,
    1383,  1685,   948,   949,   950,  1595,  1396,   951,   952,  1154,
     577,   578,   953,  1794,   954,   490,   786,  1796,   580,  1270,
     688,   689,  1212,   208,   209,   210,   211,   212,   213,   511,
     214,   468,   469,  1085,  1296,   215,   472,   473,   512,   513,
     514,   892,   893,   894,  1113,  1318,   216,   475,   476,   217,
    1090,  1303,  1091,  1092,  1301,   218,   219,   220,   221,   719,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   830,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   410,   259,
     260,   261,   262,   263,   757,   758,   264,   265,   266,   415,
     620,   421,  1731,  1734,  1770,  1772,  1771,  1773,  1287,   267,
     418,   268,   623,   269,   270,   271,   488,   635,   272,   436,
     273,   274,   275,   276,   445,   651,   913,  1134,   691,   396,
     615,   397,   398,   277,   278,   279,   280,   281,   282,   283,
     284,   630,   285,   652,   286,   682,   287,   654,   631,   655,
    1078,  1371,   902,  1335,  1126,   903,   904,   905,   906,   907,
     908,   909,   910,  1122,  1132,  1363,  1336,  1663,  1552,  1130,
    1350,  1351,  1352,  1353,  1354,  1739,  1564,  1355,  1746,  1672,
    1743,  1786,  1356,  1357,  1358,  1124,   956,   288,   289,   290,
     291,   292,   293,   294,   463,   464,   295,   296,   297,   298,
     647,   299,   957,  1752,  1688,  1390,  1585,  1066,   300,   301,
     430,  1289,  1290,   302,   303,   304,   305,   401,   402,   403,
     404,  1059,   405,   406,   813,   814,   407,   306,   696,   697,
     307,   701,   702,   308,   958,   362,   375,   363,  1046,   582,
     586,   377,   378,   379,   380,   381,   382,   383,   384,   587,
     588,   788,   309,   310
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1631
static const yytype_int16 yypact[] =
{
     883,  4505, -1631,  -153, -1631, -1631, -1631,  8847,  7163,  7597,
   -1631,   123,  8847, -1631,  6214,   631,    32,   121,  5240,   169,
    4750,  4750, -1631, -1631, -1631,  3035,  8847,  2039, -1631, -1631,
   -1631,   243,   528,   275,   388,   407,    85,   446,   476,   556,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,   514,   518,   527,
     551,   604,   701,   705,   717,   722,   727,   737,   553, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   566, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,   730,   756, -1631,
   -1631, -1631, -1631, -1631, -1631,   800, -1631,    47, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   803,   803,
   -1631,   790, -1631, -1631,   794, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   422, -1631,
   -1631, -1631, -1631, -1631,   143, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
     185, -1631,   806, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,    65, -1631, -1631,
     -20, -1631, -1631, -1631, -1631, -1631,   810, -1631,    -1, -1631,
   -1631, -1631, -1631, -1631, -1631,   831,   849, -1631,   628,   663,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   870,
   -1631, -1631,   702, -1631, -1631, -1631, -1631, -1631, -1631,   689,
     750, -1631,   182,    13, -1631,    69,    51,    60,   648, -1631,
     755,   746,   779,   773, -1631, -1631, -1631,   384, -1631, -1631,
    5240,   447, -1631, -1631,   931,   934, -1631,  6214, -1631, -1631,
    6214, -1631, -1631, -1631, -1631,   520, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,  4505,
   -1631,  4505, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
      70,   765, -1631, -1631, -1631, -1631, -1631,   781,   765, -1631,
       2, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631,   905,   938, -1631,  7383,  7383,  7163,  8847,
   -1631, -1631, -1631, -1631,   952, -1631, -1631,   830,   832, -1631,
     411,    53, -1631,   973, -1631,   955,  7811,   957,   958,   959,
     960,   962,   963,   964,   965,   966, -1631,   430, -1631, -1631,
   -1631, -1631, -1631,    11, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631,   711, -1631,   978,   447,
   -1631,  8847, -1631, -1631, -1631,   626, -1631, -1631, -1631,   971,
   -1631, -1631, -1631,  6700,  4505, -1631,   967,   972,  4505,    57,
     975,   976,  8024,  4505, -1631,   970,  8847,  8847,   979,  4505,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631,  4505,  8847,    24, -1631,  4505,  4505,  8847,   981, -1631,
    8847,   999,   986, -1631,  8847,   137, -1631,   153,  4505,  4505,
    4505,   974,   977, -1631,   967,  6943,  4505, -1631,   967,   266,
     853,  4505,   855, -1631, -1631,  4505, -1631, -1631,  8655,  3280,
    8847,  4505,  4505,  4505,   800,    47,  4505,  1014,   880,   881,
   -1631, -1631, -1631, -1631, -1631,  4750,  4750,  4750,  4750,  4750,
    4750,  4750,  4750, -1631,  4750,  4750,  4750,  4750,  4750,  4750,
    4750,  4750,  4750,   961,  4750,  4750,  4750,  4750,  4750,  4750,
    4750,  4750,  4750,  4750,  4750,   861,   873,   874,   875,  3525,
   -1631,   447,  5240,  5240,  5240,  4505,  4505, -1631, -1631,  8847,
    4505,  2545,   175, -1631,  2790,   969,   318, -1631,   839,   224,
     511, -1631, -1631, -1631,   840,  8847, -1631, -1631, -1631,   879,
   -1631,  4505, -1631,  7163, -1631, -1631, -1631,   998,  1007, -1631,
    7163,  7383,  7383,  7383,  7383,  7383,  7383,  7383,  7383,  7383,
    7383,  7383,  7383,  7383,  7383,  7163,  7163,  1001,  1002,  1008,
    8237,  8450, -1631, -1631, -1631, -1631,  1012, -1631, -1631,  5485,
     936,   940, -1631, -1631, -1631,   193, -1631,  4505, -1631, -1631,
     632, -1631, -1631,   457,  3770, -1631, -1631,   505, -1631,   476,
     964,  1013,  1015, -1631, -1631, -1631,  1016,  1017, -1631,   509,
    4015, -1631,  1018, -1631,  1019, -1631, -1631, -1631,   510,   522,
    1045,   566,  4505,   564,   565,   853,   800,   853,  8847,    47,
     853,   803,  4505,  4505,   643,   654,   570,  4505,  4505, -1631,
   -1631, -1631,   655, -1631,   582, -1631,  8847, -1631,   657, -1631,
    7597,  1021,   829,   996,   906, -1631,   599, -1631,   853, -1631,
    1054,   600, -1631,   834,   154, -1631, -1631, -1631,  8847,  4505,
     923,   750, -1631, -1631, -1631, -1631, -1631, -1631, -1631,  4750,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,    75,
      51,    51,   804,    60,    60,    60,    60,   648,   648, -1631,
   -1631,  7597,  7597,  8847,  8847, -1631,   602, -1631, -1631, -1631,
     541,   544, -1631,   545, -1631, -1631, -1631,   661, -1631,   481,
    4505,  4505,  4505, -1631,   681, -1631,   939,   941,    58,  1022,
     894, -1631, -1631, -1631,  4995, -1631, -1631,   465, -1631, -1631,
     659,    15,   895, -1631,  1037,  7597, -1631, -1631,   943,   943,
   -1631,  7163,  1040,   832, -1631,    53,    53,   816,   816,   816,
     816,   816,   816, -1631, -1631, -1631, -1631,  1056,  1041, -1631,
   -1631, -1631, -1631,   684, -1631,   853, -1631,  1050,  6457,  8847,
     -74,  1036,  1042,  1043,   806,   725,   451, -1631,   950, -1631,
   -1631,  1044, -1631,  8847, -1631, -1631, -1631,   611, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,   612, -1631, -1631, -1631, -1631,
    4505, -1631,   982, -1631, -1631,   983, -1631,  1085,  1086, -1631,
     984, -1631, -1631, -1631,   942,   944, -1631,   617,   623,  8847,
   -1631, -1631,   853,  1088, -1631, -1631,  4505, -1631,  4505,  4505,
    4505,  8847, -1631,  1090,  4505,  4505, -1631,  1063,  1066,  2039,
   -1631, -1631,  1074, -1631,   719,  4505, -1631,    75,  4505,   360,
     630,   438,  1026,   860,   876,  1035, -1631, -1631,  1046,   920,
   -1631, -1631, -1631, -1631,  1089, -1631, -1631, -1631, -1631, -1631,
    4260, -1631,   898,   899, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631,  1022, -1631, -1631,  8847,   531,   716,   660,  1022,  1022,
    1022, -1631,  1022,  1022,  1022, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631,  1022,  1022, -1631, -1631,  1022,  1022, -1631,
   -1631, -1631, -1631, -1631, -1631,   568, -1631, -1631,   236, -1631,
     226, -1631,   252, -1631,   114, -1631,   826, -1631,  -127, -1631,
     884,    22, -1631, -1631,   536, -1631, -1631,   836,   882,   828,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631,   201, -1631, -1631, -1631,
      63, -1631,   854, -1631,   893, -1631, -1631, -1631, -1631,   184,
   -1631,   186, -1631,   841, -1631,   178, -1631, -1631, -1631,   120,
   -1631,   197, -1631,  -182, -1631,    81, -1631,   572, -1631,   842,
    9029,  8847,   980,   336, -1631,  4505, -1631,   905, -1631,   992,
   -1631, -1631,  8847, -1631, -1631,  7597,  1114,  1000, -1631,   694,
     853, -1631, -1631, -1631,  1117,  1146, -1631, -1631, -1631, -1631,
     879,   169,   169, -1631, -1631, -1631,  1153,  1123,  1124, -1631,
   -1631, -1631, -1631,  4505,  1160,   985,  4505,  4505,  4505,  1161,
     -51, -1631,    56,  4505, -1631, -1631,   431, -1631, -1631,   644,
   -1631,   945, -1631, -1631,  4505, -1631, -1631,  1153,  1153,   947,
    4505, -1631, -1631,  1023,  1074,  1133,   652, -1631,    52,  1072,
     987, -1631, -1631,  1077, -1631,    75,   348,    75,  1047,   268,
    1093,   -55, -1631, -1631, -1631, -1631,  4505,  4505, -1631,  1144,
     131,   660,   714,  1046,  1057,  8847,   720,   767,   172,   205,
    8847,   289,   203,  8847,    28,   200,   214, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,   892,   897, -1631,
   -1631,  5728,  7597,   723,   930, -1631, -1631,  7597,   930, -1631,
   -1631, -1631,  7597,  4505,  1140, -1631,  7597,  4505,  1286, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631,   -35,  1065,  1065, -1631, -1631,  7811,
   -1631, -1631, -1631,   948,  4505,   885,   670, -1631, -1631,  4505,
    4505, -1631,  1404,   -78,  4505,   364, -1631,   512, -1631,  1518,
   -1631,  4505, -1631, -1631,   918, -1631,  7597,  4505,  1708,  4505,
    1738, -1631,  4505,  1776,  2045, -1631,  4505, -1631, -1631,  2075,
   -1631,  4505,  2146, -1631, -1631,  2174, -1631, -1631,  4505, -1631,
   -1631,  2203,  4505,  2271,   806,  1164,   -63, -1631, -1631, -1631,
     709, -1631, -1631, -1631,  7163, -1631,  1162, -1631,  7597,  7597,
    1049,  1196,  5728,   -74,  1199,  1167,  1168,   313,  8847,  1179,
   -1631, -1631, -1631, -1631,  8847,  1204,  1075, -1631, -1631, -1631,
    8847,  7597,    64, -1631, -1631,  7597,  4505,  1052,  1175, -1631,
   -1631,  4505, -1631,   710,   712,  1177, -1631,   759,  1067, -1631,
     438, -1631,  1169, -1631, -1631,  4750,   876,  1118,   819, -1631,
    4750,  4750,   -55,   718,   718, -1631, -1631,  1035,    75,   695,
     851, -1631,    20,  1003, -1631,   857,  8847, -1631, -1631,  1092,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   268,
     188,  4750,  4750,  1020, -1631, -1631,  1057, -1631, -1631,  1093,
   -1631, -1631,  1183, -1631, -1631, -1631, -1631,  1079,  1057,  1051,
    1053, -1631, -1631,  1193,  1097, -1631, -1631, -1631,  8847,   -74,
     988,  1076,  1225,  9029,  8847,  1039,  1057,  1119,  8847,  1119,
   -1631, -1631,   -68,  6214, -1631,  1603,   293,  1219,  1201,  1202,
    1227, -1631,  5971,   591,   669, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,   319,  9030, -1631,  9058, -1631,
     870, -1631, -1631,   870, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631,  1115,  1115, -1631, -1631,   870,  4505, -1631, -1631,
     989,  9087,   870,   870,    22, -1631, -1631, -1631, -1631, -1631,
     870, -1631, -1631, -1631,   333, -1631, -1631, -1631,  9115,   870,
      22,    22, -1631,   991, -1631,   870, -1631,   870, -1631,    22,
     870, -1631, -1631,    22,   870,    22,    22, -1631,    22,   870,
   -1631,    22,    22, -1631,   870, -1631,   870, -1631,   879,  1057,
    8847,  8847,    30,   336, -1631,  1084, -1631, -1631, -1631,  7597,
    4505,   130, -1631,  4505,   169,   169,   631, -1631, -1631, -1631,
   -1631,   853,  1153, -1631,  8847,  4505,  1091, -1631,  8847,  4505,
   -1631, -1631,  4505, -1631, -1631, -1631, -1631,  1153, -1631, -1631,
    1057, -1631, -1631,    60, -1631, -1631, -1631, -1631,    43,   597,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,  1027, -1631, -1631,
   -1631,   148,  1057, -1631, -1631,    80, -1631, -1631,  1116, -1631,
   -1631,  4750,  4750,   804,   103, -1631,  1022,  1057,   821, -1631,
    1057,  1057,   788, -1631,     5,  1218, -1631,  5728,  7811,  8847,
     806,  1215,  1073,  1119,  1057,  1221,  1220,  1221, -1631, -1631,
   -1631, -1631,  6214,  6214,    77,  1092,  5728, -1631,  5971,  5971,
    5971,  5971,  1234, -1631, -1631, -1631,  7597,  4505,  9144, -1631,
   -1631, -1631,   870,  9172, -1631, -1631, -1631, -1631,  7597,  4505,
    9201, -1631,  9229, -1631,  9258,  1021,  1022,  1222,  1126,  9029,
   -1631,  7163, -1631, -1631,  1088,  1223, -1631,   753,   757,   169,
    1246, -1631, -1631, -1631, -1631,  1127, -1631, -1631,   724, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,   -47,  1092,
    1057, -1631, -1631, -1631,   804,   804,  4750, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631,   376, -1631,  1102,  1024,
     -74,    76, -1631,   853,   879, -1631, -1631,  1221, -1631,  1057,
    1057, -1631, -1631,  1229, -1631, -1631,  1239, -1631, -1631, -1631,
   -1631, -1631,  4505, -1631,   870, -1631, -1631, -1631,   870, -1631,
   -1631,  1022, -1631,  1057,  1022,   806, -1631,  1240,   879, -1631,
   -1631, -1631, -1631, -1631, -1631,  1236,  4505,  4505, -1631,   729,
     734,  1092,  1068,   738, -1631, -1631,   642,   642,   804, -1631,
     744,  7597,  1021,  5728, -1631, -1631,  1102,    48,    42, -1631,
    1119, -1631,   317,   625, -1631, -1631,  1022, -1631,   879,  1266,
     232,   295,   265,   304, -1631, -1631, -1631,  1157, -1631, -1631,
     -55, -1631,  1092, -1631,   227,   227, -1631, -1631, -1631, -1631,
      76,  1021,  4505, -1631, -1631, -1631, -1631, -1631,  1221,  1238,
   -1631, -1631, -1631, -1631,  1021,  4505, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,  1069,
   -1631, -1631, -1631, -1631,  1102, -1631, -1631, -1631,  1022, -1631,
   -1631,  1021, -1631, -1631
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1631, -1631,   786, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,   314, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,    82, -1631, -1631, -1631, -1631,
    1287, -1631,  -537,  -936, -1631, -1631, -1631, -1631,   305, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631,    72, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631,    84, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1258,  -315, -1631, -1631, -1631, -1631, -1631, -1361, -1631,
   -1631, -1631,   990, -1631,   524, -1631, -1631, -1631,   529, -1631,
   -1631,  -761, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1377, -1631, -1631, -1631,    -2,
   -1631, -1631, -1631, -1631, -1631,  -317, -1054, -1631,   900, -1631,
   -1337,   433,  -678,   530,   207,   869, -1631, -1631,  1095, -1631,
   -1631, -1631,   645, -1631, -1631, -1631, -1631,   640, -1631, -1631,
   -1631,   415,   202, -1631, -1631, -1631, -1631,  1205,   646, -1631,
   -1631, -1631,   223, -1631, -1631, -1631, -1631,   801,   805, -1631,
    -368, -1631,  -520,  -522,   445,  -505,   440,   441, -1631, -1631,
   -1631,   968, -1631, -1631, -1631,  -712,  -222, -1631, -1631, -1631,
      25,   278, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631,    33, -1631, -1631, -1631,  -708, -1631, -1541,  -422, -1631,
   -1631, -1631, -1631, -1631,   760,   399, -1631,    36, -1631,  -196,
   -1631,  -610, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631,   231, -1631, -1631,
   -1631, -1631, -1631, -1631,  1191, -1631,   583, -1631,  -642,  -663,
   -1631,  -380,  -467,    17, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631,   887, -1631,   889, -1631,   886,   844,
     461, -1056,  -855, -1631, -1631, -1631,   206,   208,    -5,   435,
   -1631, -1631, -1631,    16, -1631, -1314, -1631,  -212,     4,   198,
     -19, -1631, -1631, -1631, -1631,  -325, -1517, -1631,  -329,  -794,
   -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,   683, -1631, -1631, -1631, -1312,
    -923,     0, -1631, -1630, -1578,  -239, -1631, -1242, -1631, -1631,
     459, -1078,  -176, -1631, -1631, -1631, -1631, -1631, -1631, -1631,
   -1631, -1631, -1631, -1631, -1631,   297, -1631, -1631, -1631,   469,
   -1631, -1631,   466, -1631, -1631, -1631, -1631, -1631,   563,   307,
      23, -1631,   762,   763,   371,   400,  -313, -1631, -1631,   751,
   -1631, -1631,   306,    -7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -342
static const yytype_int16 yytable[] =
{
     365,   385,   365,   579,   320,   365,   607,   365,   933,   400,
     826,  1139,   728,   877,   732,   550,  1284,   900,  1549,   365,
     365,   901,  1597,   855,  1511,   857,   399,   875,   860,  1313,
    1314,   376,   733,   734,   735,   736,  1184,  1569,  1188,  1435,
     660,  1512,  1115,   419,  1667,   665,   489,   412,   667,  1686,
     493,  1607,   670,   584,   585,  1456,   883,   876,   575,  1061,
     470,   661,  1792,  1704,  1561,  1598,   537,   575,   601,   496,
    1222,   575,  1305,   532,   876,  1360,   541,  1528,   911,   912,
    1229,   534,   535,  1360,   575,  1238,   575,  1240,    19,  1243,
      12,  1244,  1606,  1249,   876,  1252,   897,  1255,  1436,  1397,
    1399,  1261,   638,  1263,   898,  1321,   312,   534,   535,  1253,
    1089,    19,   930,  1756,   564,    28,    29,    30,  1265,   897,
    1686,  1500,  1044,   409,  1669,   565,  1791,   898,   876,   442,
     639,  1207,   538,  1501,   602,   491,  1254,   443,    28,    29,
      30,   534,   535,  1302,   817,  1562,  1606,  1586,  1211,   713,
     714,   715,   716,   717,   718,  1058,   720,   721,   722,   723,
     724,   725,   726,   727,  1208,  1392,   483,  1361,  1362,  1741,
    1138,   313,   416,  1054,   671,  1361,  1362,  1157,  1158,  1159,
     492,  1160,  1161,  1162,  1644,   900,  1209,   900,    90,   901,
     671,   901,  1163,  1164,  1831,   443,  1165,  1166,  1306,   517,
     518,   519,   520,   521,   522,  1670,  1529,  1142,  1143,  1144,
     523,    90,  1824,    90,  1563,   616,  1697,   494,  1040,   533,
     444,  1801,  1372,   524,   539,   540,   603,   604,  1795,   485,
    1097,  1393,   425,  1639,  1793,   542,   497,   486,  1426,   417,
     365,   536,  1428,   365,   576,   766,   858,  1708,  1709,  1710,
    1711,  1457,   471,  1458,   662,  1062,  1063,   576,  1389,   640,
    1818,  1599,  1600,  1322,   872,   551,   432,  1660,  1661,  1662,
     576,  1669,   576,  1562,  1671,  1676,   914,   914,   444,   686,
     557,  1806,  1451,   558,   876,   420,   890,   433,   803,   804,
     805,   806,  1705,  1706,  1468,   434,   672,  1437,  1438,  1439,
    1571,   525,   526,   527,   528,   529,   530,  1727,   899,   828,
    1576,   687,   673,   364,  1812,  1145,  1602,   876,   411,   439,
     487,  1377,  1579,  1146,  1147,  1148,  1149,  1150,  1378,  1691,
      12,   899,   426,   431,   829,  1271,  1370,   433,   759,  1256,
    1593,    15,  1666,  1572,    16,    17,  1809,   876,  1516,  1750,
    1370,   896,  1670,  1223,  1742,  1815,   876,  1744,  1807,   385,
     385,   385,   365,   531,  1339,   876,  1151,  1340,  1385,  1386,
    1341,  1342,  1343,  1344,  1379,  1380,  1152,  1224,   435,   365,
      28,    29,    30,  1798,  1394,  1257,   400,  1381,  1153,   686,
     888,  1813,  1276,  1382,  1395,  1258,    19,  1060,  1398,    28,
      29,    30,  1387,   399,   897,  1185,   900,   889,   760,   761,
     901,  1245,   898,   900,   365,   900,   762,   901,  1281,   901,
      19,  1749,  1810,    28,    29,    30,   365,  1186,  1187,  1780,
    1345,  1816,   440,   632,  1246,   365,   549,  1247,  1248,   365,
     365,  1517,  1518,  1636,  1635,   612,   632,   656,  1754,   593,
     594,   441,  1388,    90,  1327,   365,  1389,   613,  1308,  1658,
     365,  1285,  1286,   365,  1346,  1230,  1819,   365,   614,  1241,
    1820,  1591,    90,  1328,   480,  1596,  1309,  1235,   365,  1329,
    1073,   552,  1347,  1348,  1659,   656,  1349,   553,  1250,  1618,
     446,   365,  1242,   365,   502,  1790,    90,  1074,  1231,  1236,
    1237,   481,   482,  1232,  1233,   766,  1668,  1070,   554,  1418,
     835,  1251,  1623,   775,  1427,  1220,   767,  1175,  1221,  1429,
     447,  1678,   776,  1432,  1681,  1682,  1169,  1170,  1630,  1176,
     595,   596,   597,   598,   599,   600,  1632,   450,  1698,  1177,
    1634,   451,   502,  1179,   559,   560,   502,   502,  1171,  1172,
     452,  1173,   365,  1180,  1181,  1330,  1331,  1332,   838,   502,
    1333,  1334,   843,   848,   561,  1182,  1183,   917,   365,   781,
     918,   919,   437,  1474,   453,   849,   385,  1637,   502,   462,
     438,   502,   502,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     448,   502,   502,   365,   365,   461,   789,   502,   449,  1519,
    1613,   400,   824,   792,  1745,  1507,  1508,   853,   854,   502,
    1614,  1615,  1461,   866,  1626,  1608,   900,   454,   807,  1462,
     901,  1609,  1616,  1617,  1627,   871,   881,   885,  1527,   502,
    1758,   633,  1530,  1759,  1760,   637,  1628,  1629,   502,   502,
     649,  1802,   882,   886,   502,   916,   658,  1119,  1120,  1121,
     502,   365,   502,   502,  1080,  1081,    19,  1766,   659,   833,
    1094,   626,   663,   664,  1769,   589,  1095,   834,   550,   365,
     502,   502,  1118,   365,  1454,   674,   675,   676,   864,   502,
     400,   502,   869,   684,   873,  1470,  1471,  1310,   920,   865,
     870,   365,   874,  1610,  1479,  1320,   921,   399,  1483,  1611,
    1485,  1486,   922,  1488,  1804,   679,  1491,  1492,   920,   685,
     923,  1052,  1140,   959,   455,   960,   927,   625,   456,  1053,
    1141,  1279,   961,   962,   365,   365,   365,   365,   963,  1280,
     457,   400,   400,   400,   400,   458,  1503,  1522,   648,  1522,
     459,   964,   965,   966,  1504,  1535,   746,  1536,   399,   399,
     460,  1522,   750,   751,   413,   414,  1777,   753,   411,  1738,
    1465,  1777,  -341,   411,  1778,  1782,   411,  1462,   365,  1779,
     411,   873,   465,  1783,   385,   400,  1419,  1420,  1421,  1787,
     317,   318,  1142,  1143,  1144,  1640,   408,  1555,  1556,  1557,
    1558,  1729,   399,  1730,   698,  1732,   703,  1733,   466,  1548,
    1547,   365,   365,   467,  1048,  1677,   474,  1784,   400,  1785,
    1543,  1660,  1661,  1662,   543,   544,   365,   621,   622,  1444,
     747,   748,   749,  1079,   478,   399,   778,   779,   479,  1573,
    1574,   837,   534,   535,   503,   504,  1642,   505,   506,   507,
     489,   508,   509,  -341,   593,   594,   515,   845,  1071,  1072,
    1155,  1156,   365,  1001,  1002,   752,  1521,  1167,  1168,  1079,
    1111,  1112,  1523,   500,   365,  1722,  1259,  1260,  1526,  1650,
     495,   784,   365,   498,   867,   868,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,  1367,  1368,  1375,  1376,
    1145,   499,  1373,  1374,  1647,  1648,  1687,   502,  1146,  1147,
    1148,  1149,  1150,  1538,  1539,   501,   815,   982,   516,  -341,
     983,   984,   985,   986,   545,   987,   546,   365,   988,  1545,
    1546,   989,   990,   991,   992,   993,   994,   995,   996,   997,
    1215,  1448,   998,   999,  1000,  1550,  1551,  1498,  1559,  1560,
     547,  1151,   548,  1713,  1566,  1567,   555,  1721,  -341,   556,
    1765,  1152,   566,  1767,   581,  1717,   797,   798,   799,   800,
     801,   802,   571,  1153,   411,  1679,  1680,  1683,  1684,   730,
     731,   737,   738,   313,   739,   740,  1001,  1002,   422,   423,
    1821,  1822,   411,   795,   796,   583,   590,   591,   605,   606,
     592,   433,   437,   442,   448,  1803,   608,   609,   485,   610,
     611,   624,   668,  1755,   411,   627,   690,   636,   666,   634,
     643,   644,   650,   669,   657,   693,   677,   708,   709,   678,
     710,   741,   765,  1264,   365,   729,   742,   743,   744,  1735,
     770,   782,   785,   790,   791,   365,   809,   810,   365,  1674,
    1675,  1757,   825,   811,  1800,   400,   818,   827,   839,   850,
     840,   841,   842,   846,   847,   878,   879,  1832,   884,   880,
     887,   895,   399,   876,  1789,   928,   930,   929,   934,  1041,
    1797,  1043,  1050,  1099,  1189,  1049,  1051,  1055,  1788,  1045,
    1067,  1075,  1808,  1811,  1814,  1817,  1068,  1069,  1076,  1086,
    1087,   686,  1652,  1089,  1104,  1116,  1655,  1107,  1084,  1093,
    1108,  1110,  1823,  1825,  1125,  1190,  1133,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1083,   411,  1828,  1123,  1088,  1128,
    1131,  1127,  1198,  1199,  1200,  1201,  1202,  1203,   365,  1136,
    1137,  1129,  1210,   365,  1219,  1226,   365,  1204,  1205,  1206,
    1214,  1228,  1215,  1833,  1748,  1239,  1262,  1274,   562,  1277,
     563,  1282,  1283,  1278,   365,   365,  1288,  1693,  1291,  1292,
     365,  1266,   400,  1294,  1300,   365,  1317,   400,  1319,   365,
    1323,  1311,   400,  1315,  1325,  1366,   400,   698,  1359,   399,
    1295,  1338,  1400,  1370,   399,   431,  1401,  1423,  1441,   399,
    1472,  1447,   365,   399,  1417,  1499,  1445,  1506,  1692,   400,
    1510,  1324,  1509,  1513,  1514,  1515,  1522,  1524,  1532,  1525,
    1533,  1537,  1542,  1540,  1577,  1544,   399,  1565,    90,   365,
    1582,  1575,  1578,  1583,  1587,  1580,   400,  1581,  1589,  1588,
     648,  1592,  1603,  1606,  1594,  1604,  1605,  1624,  1621,  1633,
    1641,  1665,  1673,   399,  1654,  1690,  1695,  1696,  1699,  1712,
    1736,  1700,  1724,  1723,  1502,  1751,  1774,   385,  1728,  1737,
    1753,   365,   365,  1694,  1761,   365,  1762,   873,   400,   400,
    1805,   365,  1562,  1827,  1178,  1781,  1830,   365,  1443,  1213,
     316,  1707,   931,   365,   365,   399,   399,  1505,   365,  1466,
    1449,   400,   935,   617,   955,   400,  1098,   510,   574,   859,
    1114,   856,  1316,  1304,   477,  1417,   711,   861,   399,  1135,
    1649,   712,   399,  1520,   764,   484,   641,   915,   642,   683,
    1096,  1326,   653,  1554,  1117,  1337,  1541,  1664,  1553,   365,
    1570,  1369,  1740,  1747,   851,  1689,  1651,   648,  1109,  1275,
    1103,  1106,  1047,   793,  1273,   794,     0,   808,   815,     0,
     692,     0,     0,     0,   694,     0,     0,     0,   700,     0,
     704,   705,   706,     0,     0,   707,     0,     0,     0,     0,
       0,   365,     0,     0,     0,     0,  1590,   365,     0,     0,
    1430,   365,     0,     0,  1433,     0,   365,     0,  1431,     0,
       0,   983,   984,   985,   986,   365,   987,     0,  1768,   988,
       0,     0,   989,   990,   991,   992,   993,   994,   995,   996,
     997,  1446,     0,   998,   999,  1000,  1452,  1453,     0,     0,
     756,  1460,     0,   756,     0,     0,  1601,     0,  1469,     0,
       0,     0,     0,     0,  1475,  1417,  1477,     0,     0,  1480,
     787,   648,     0,  1484,     0,     0,  1384,     0,  1489,  1391,
       0,     0,     0,     0,   313,  1494,     0,  1001,  1002,  1496,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   365,   365,     0,   832,     0,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,     0,     0,     0,     0,   365,     0,     0,
       0,   365,     0,     0,     0,     0,   399,     0,     0,     0,
       0,   852,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   862,   863,     0,  1434,     0,     0,   983,   984,   985,
     986,     0,   987,     0,     0,   988,     0,     0,   989,   990,
     991,   992,   993,   994,   995,   996,   997,     0,     0,   998,
     999,  1000,     0,     0,     0,     0,     0,     0,   891,     0,
     365,   365,   365,     0,     0,     0,     0,     0,   400,     0,
       0,     0,     0,     0,   411,   365,   365,     0,     0,   365,
     411,   365,   365,   365,   365,   399,   411,     0,     0,   365,
     313,     0,     0,  1001,  1002,     0,   400,     0,     0,  -256,
    1417,   365,     0,     0,     0,     0,     0,     0,   400,   924,
     925,   926,  1725,   399,   385,  1701,  1702,     0,     0,  1417,
       0,  1417,  1417,  1417,  1417,   399,     0,  -256,  -256,     0,
       0,     0,  1568,     0,  1622,  -256,     0,  -256,     0,     0,
       0,     0,  1455,     0,  1726,   983,   984,   985,   986,     0,
     987,     0,     0,   988,     0,     0,   989,   990,   991,   992,
     993,   994,   995,   996,   997,     0,     0,   998,   999,  1000,
       0,     0,     0,     0,  1584,     0,     0,     0,     0,     0,
     648,     0,     0,     0,   648,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1082,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,  1001,  1002,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   365,     0,   365,  1100,  1101,  1102,
       0,   400,     0,  1105,   700,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   891,     0,     0,     0,   399,     0,
       0,     0,     0,     0,     0,     0,  1467,     0,     0,   983,
     984,   985,   986,     0,   987,     0,  1417,   988,     0,   756,
     989,   990,   991,   992,   993,   994,   995,   996,   997,     0,
       0,   998,   999,  1000,     0,     0,   648,  1638,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1714,     0,     0,     0,     0,     0,
     411,     0,     0,     0,   411,     0,  1718,     0,     0,     0,
       0,     0,   313,     0,     0,  1001,  1002,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -256,     0,     0,  -256,  -256,  -256,  -256,     0,  -256,
    -256,     0,  -256,     0,     0,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,     0,     0,  -256,  -256,  -256,     0,
       0,     0,     0,  -256,  -256,   411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1272,  -256,  -256,     0,  -256,  1763,
       0,     0,     0,     0,     0,     0,     0,  -256,     0,     0,
    -256,  -256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1293,     0,     0,  1297,  1298,  1299,     0,     0,
       0,     0,  1307,     0,     0,     0,  1476,     0,     0,   983,
     984,   985,   986,  1312,   987,     0,     0,   988,     0,   891,
     989,   990,   991,   992,   993,   994,   995,   996,   997,     0,
       0,   998,   999,  1000,     0,     0,  1478,     0,     0,   983,
     984,   985,   986,     0,   987,  1364,  1365,   988,     0,     0,
     989,   990,   991,   992,   993,   994,   995,   996,   997,     0,
       0,   998,   999,  1000,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,  1481,  1001,  1002,   983,   984,   985,
     986,     0,   987,     0,     0,   988,     0,     0,   989,   990,
     991,   992,   993,   994,   995,   996,   997,     0,     0,   998,
     999,  1000,   313,     0,     0,  1001,  1002,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     313,     0,     0,  1001,  1002,   321,   322,   323,   324,   325,
     326,   327,   328,   329,    40,    41,    42,    43,    44,    45,
      46,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   342,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
     343,   344,    89,     0,     0,  1531,    91,     0,     0,     0,
    1534,    94,   345,    96,   346,    98,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   347,   348,   110,   349,
     112,     0,   113,   350,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   351,   129,   130,
     131,   132,   133,   352,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,   148,   149,
       0,   353,   151,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   354,   178,
     179,   355,   181,   182,   183,   184,   185,   356,   187,   357,
     189,   190,   191,   192,   193,   194,   358,   359,   197,   360,
     361,   200,   201,   202,   203,   204,   205,     0,     0,     0,
       0,     0,     0,  1482,     0,     0,   983,   984,   985,   986,
       0,   987,     0,     0,   988,     0,     0,   989,   990,   991,
     992,   993,   994,   995,   996,   997,     0,     0,   998,   999,
    1000,     0,     0,  1487,     0,     0,   983,   984,   985,   986,
       0,   987,     0,     0,   988,     0,     0,   989,   990,   991,
     992,   993,   994,   995,   996,   997,     0,     0,   998,   999,
    1000,     0,     0,     0,     0,     0,     0,     0,   427,   313,
     428,     0,  1001,  1002,     0,     0,     0,     0,     0,  1643,
       0,     0,  1646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1653,     0,     0,     0,  1656,   313,
       0,  1657,  1001,  1002,  1490,     0,     0,   983,   984,   985,
     986,     0,   987,     0,     0,   988,     0,     0,   989,   990,
     991,   992,   993,   994,   995,   996,   997,     0,     0,   998,
     999,  1000,  1493,     0,     0,   983,   984,   985,   986,     0,
     987,     0,     0,   988,     0,     0,   989,   990,   991,   992,
     993,   994,   995,   996,   997,     0,     0,   998,   999,  1000,
       0,  1495,     0,     0,   983,   984,   985,   986,     0,   987,
     313,     0,   988,  1001,  1002,   989,   990,   991,   992,   993,
     994,   995,   996,   997,     0,     0,   998,   999,  1000,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,  1001,  1002,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,     0,  1497,
    1001,  1002,   983,   984,   985,   986,     0,   987,     0,     0,
     988,     0,     0,   989,   990,   991,   992,   993,   994,   995,
     996,   997,     0,     0,   998,   999,  1000,     0,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,   754,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
     755,     0,     0,     0,     0,   313,     0,     0,  1001,  1002,
       0,     0,     0,    26,     0,  1775,  1776,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,  1826,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,  1829,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,   754,    15,     0,
       0,    16,    17,     0,    18,     0,    19,     0,    20,    21,
      22,     0,    23,    24,    25,   763,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,    15,     0,
       0,    16,    17,     0,    18,     0,    19,     0,    20,    21,
      22,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,   699,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   745,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,    15,     0,
       0,    16,    17,     0,    18,     0,    19,     0,    20,    21,
      22,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,   836,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,   844,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,   754,    15,     0,
       0,    16,    17,     0,    18,     0,    19,     0,    20,    21,
      22,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,    95,    96,    97,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,    15,     0,
       0,    16,    17,     0,    18,     0,    19,     0,    20,    21,
      22,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   342,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,   345,    96,   346,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   347,   348,   110,
     349,   112,     0,   113,   350,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   354,
     178,   179,   355,   181,   182,   183,   184,   185,   356,   187,
     357,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     360,   361,   200,   201,   202,   203,   204,   205,    12,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,    15,     0,     0,    16,    17,     0,    18,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    87,    88,    89,     0,
       0,    90,    91,    92,    93,     0,     0,    94,    95,    96,
      97,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   936,   142,   143,   144,
     145,   146,     0,   147,   937,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,    12,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,    15,     0,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   342,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,     0,     0,    90,    91,    92,    93,
       0,     0,    94,   345,    96,   346,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   347,   348,   110,
     349,   112,     0,   113,   350,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   351,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   354,
     178,   179,   355,   181,   182,   183,   184,   185,   356,   187,
     357,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     360,   361,   200,   201,   202,   203,   204,   205,   819,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   820,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   342,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,   343,   344,    89,     0,
       0,     0,    91,     0,     0,     0,     0,    94,   345,    96,
     346,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   347,   348,   110,     0,   112,     0,   113,     0,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   351,   129,   130,   131,   132,   133,   352,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,     0,   151,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   354,   178,   179,   355,   181,   182,
     183,   184,   185,   356,   187,   357,   189,   190,   191,   192,
     193,   194,   358,   359,   197,   360,   361,   200,   201,   202,
     203,   204,   205,    13,     0,     0,     0,     0,     0,     0,
       0,     0,  1403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1404,     0,     0,     0,     0,     0,  1405,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1406,   388,    33,    34,    35,   389,
      37,    38,   390,    40,    41,    42,    43,    44,    45,    46,
    1407,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,    59,    60,    61,    62,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   342,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,   343,
     344,    89,     0,     0,     0,    91,    92,    93,     0,     0,
      94,   345,    96,   346,    98,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   347,   348,   110,   349,   112,
       0,   113,   350,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   351,   129,   130,   131,
     132,   133,   352,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,   147,   148,   149,     0,
     393,   151,     0,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   354,   178,   179,
     355,   181,   182,   183,   184,   185,   356,   187,   357,   189,
     190,  1408,  1409,   193,   194,   358,   359,   197,   360,   361,
     200,   201,   202,   203,   204,   205,    13,     0,     0,     0,
       0,     0,     0,     0,     0,  1403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1406,   388,    33,
      34,    35,   389,    37,    38,   390,    40,    41,    42,    43,
      44,    45,    46,  1407,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   342,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,   343,   344,    89,     0,     0,     0,    91,    92,
      93,     0,     0,    94,   345,    96,   346,    98,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   347,   348,
     110,   349,   112,     0,   113,   350,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   351,
     129,   130,   131,   132,   133,   352,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     148,   149,     0,   393,   151,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     354,   178,   179,   355,   181,   182,   183,   184,   185,   356,
     187,   357,   189,   190,   191,   192,   193,   194,   358,   359,
     197,   360,   361,   200,   201,   202,   203,   204,   205,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     387,   388,    33,    34,    35,   389,    37,    38,   390,    40,
      41,    42,    43,    44,    45,    46,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   342,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,   343,   344,    89,     0,     0,
       0,    91,    92,    93,     0,     0,    94,   345,    96,   346,
      98,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   347,   348,   110,   349,   112,     0,   113,   350,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   351,   129,   130,   131,   132,   133,   352,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   147,   148,   149,     0,   393,   151,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   354,   178,   179,   355,   181,   182,   183,
     184,   185,   356,   187,   357,   189,   190,   191,   192,   193,
     194,   358,   359,   197,   360,   361,   200,   201,   202,   203,
     204,   205,  1056,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   386,  1057,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   387,   388,    33,    34,    35,   389,    37,
      38,   390,   391,    41,    42,    43,    44,    45,    46,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   342,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,   343,   344,
      89,     0,     0,     0,    91,     0,     0,     0,     0,    94,
     345,    96,   346,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   347,   348,   110,   349,   112,     0,
     113,   350,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   351,   129,   130,   131,   132,
     133,   352,   392,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,     0,   393,
     151,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   354,   178,   179,   355,
     181,   182,   183,   184,   185,   356,   187,   357,   189,   190,
     191,   192,   193,   194,   394,   395,   197,   360,   361,   200,
     201,   202,   203,   204,   205,   628,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   629,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    40,    41,    42,    43,    44,
      45,    46,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   342,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,   343,   344,    89,     0,     0,     0,    91,     0,     0,
       0,     0,    94,   345,    96,   346,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   347,   348,   110,
     349,   112,     0,   113,   350,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   351,   129,
     130,   131,   132,   133,   352,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   353,   151,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   354,
     178,   179,   355,   181,   182,   183,   184,   185,   356,   187,
     357,   189,   190,   191,   192,   193,   194,   358,   359,   197,
     360,   361,   200,   201,   202,   203,   204,   205,   680,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   681,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   321,
     322,   323,   324,   325,   326,   327,   328,   329,    40,    41,
      42,    43,    44,    45,    46,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   342,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,   343,   344,    89,     0,     0,     0,
      91,     0,     0,     0,     0,    94,   345,    96,   346,    98,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     347,   348,   110,   349,   112,     0,   113,   350,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   351,   129,   130,   131,   132,   133,   352,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   147,   148,   149,     0,   353,   151,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   354,   178,   179,   355,   181,   182,   183,   184,
     185,   356,   187,   357,   189,   190,   191,   192,   193,   194,
     358,   359,   197,   360,   361,   200,   201,   202,   203,   204,
     205,   366,   367,     0,     0,     0,     0,   368,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   369,     0,     0,     0,     0,   370,   371,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,    46,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   342,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,   343,   344,    89,     0,     0,   373,
      91,     0,     0,     0,     0,    94,   345,    96,   346,    98,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     347,   348,   110,     0,   112,     0,   113,   374,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   351,   129,   130,   131,   132,   133,   352,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   147,   148,   149,     0,     0,   151,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   354,   178,   179,   355,   181,   182,   183,   184,
     185,   356,   187,   357,   189,   190,   191,   192,   193,   194,
     358,   359,   197,   360,   361,   200,   201,   202,   203,   204,
     205,   366,   367,     0,     0,     0,     0,   368,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   369,     0,     0,     0,     0,   370,   371,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,    46,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   342,    79,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,   343,   344,    89,     0,     0,   373,
      91,     0,     0,     0,     0,    94,   345,    96,   346,    98,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     347,   348,   110,     0,   112,     0,   113,     0,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   351,   129,   130,   131,   132,   133,   352,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,   147,   148,   149,     0,     0,   151,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   354,   178,   179,   355,   181,   182,   183,   184,
     185,   356,   187,   357,   189,   190,   191,   192,   193,   194,
     358,   359,   197,   360,   361,   200,   201,   202,   203,   204,
     205,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   387,   388,    33,    34,    35,   389,    37,
      38,   390,   391,    41,    42,    43,    44,    45,    46,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   342,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,   343,   344,
      89,     0,     0,     0,    91,     0,     0,     0,     0,    94,
     345,    96,   346,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   347,   348,   110,   349,   112,     0,
     113,   350,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   351,   129,   130,   131,   132,
     133,   352,   392,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,     0,   393,
     151,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   354,   178,   179,   355,
     181,   182,   183,   184,   185,   356,   187,   357,   189,   190,
     191,   192,   193,   194,   394,   395,   197,   360,   361,   200,
     201,   202,   203,   204,   205,   386,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   387,   388,    33,
      34,    35,   389,    37,    38,   390,    40,    41,    42,    43,
      44,    45,    46,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   342,    79,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,   343,   344,    89,     0,     0,     0,    91,     0,
       0,     0,     0,    94,   345,    96,   346,    98,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   347,   348,
     110,   349,   112,     0,   113,   350,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   351,
     129,   130,   131,   132,   133,   352,   392,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     148,   149,     0,   393,   151,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     354,   178,   179,   355,   181,   182,   183,   184,   185,   356,
     187,   357,   189,   190,   191,   192,   193,   194,   394,   395,
     197,   360,   361,   200,   201,   202,   203,   204,   205,   645,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     321,   322,   323,   324,   325,   326,   327,   328,   329,    40,
      41,    42,    43,    44,    45,    46,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,    59,    60,
      61,    62,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   342,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,   343,   344,    89,     0,     0,
     646,    91,     0,     0,     0,     0,    94,   345,    96,   346,
      98,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   347,   348,   110,   349,   112,     0,   113,   350,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   351,   129,   130,   131,   132,   133,   352,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,   147,   148,   149,     0,   353,   151,     0,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   354,   178,   179,   355,   181,   182,   183,
     184,   185,   356,   187,   357,   189,   190,   191,   192,   193,
     194,   358,   359,   197,   360,   361,   200,   201,   202,   203,
     204,   205,   812,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    40,    41,    42,    43,    44,    45,    46,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   342,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,   343,   344,
      89,     0,     0,     0,    91,     0,     0,     0,     0,    94,
     345,    96,   346,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   347,   348,   110,   349,   112,     0,
     113,   350,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   351,   129,   130,   131,   132,
     133,   352,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,     0,   353,
     151,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   354,   178,   179,   355,
     181,   182,   183,   184,   185,   356,   187,   357,   189,   190,
     191,   192,   193,   194,   358,   359,   197,   360,   361,   200,
     201,   202,   203,   204,   205,   816,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    40,    41,    42,    43,    44,
      45,    46,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,    59,    60,    61,    62,    63,    64,
      65,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,   342,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
       0,   343,   344,    89,     0,     0,     0,    91,     0,     0,
       0,     0,    94,   345,    96,   346,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   347,   348,   110,
     349,   112,     0,   113,   350,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   351,   129,
     130,   131,   132,   133,   352,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,   147,   148,
     149,     0,   353,   151,     0,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   354,
     178,   179,   355,   181,   182,   183,   184,   185,   356,   187,
     357,   189,   190,   191,   192,   193,   194,   358,   359,   197,
     360,   361,   200,   201,   202,   203,   204,   205,   695,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      40,    41,    42,    43,    44,    45,    46,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    59,
      60,    61,    62,    63,    64,    65,     0,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   342,
      79,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,   343,   344,    89,     0,
       0,     0,    91,     0,     0,     0,     0,    94,   345,    96,
     346,    98,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   347,   348,   110,   349,   112,     0,   113,   350,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   351,   129,   130,   131,   132,   133,   352,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,   147,   148,   149,     0,   353,   151,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   354,   178,   179,   355,   181,   182,
     183,   184,   185,   356,   187,   357,   189,   190,   191,   192,
     193,   194,   358,   359,   197,   360,   361,   200,   201,   202,
     203,   204,   205,   321,   322,   323,   324,   325,   326,   327,
     328,   329,    40,    41,    42,    43,    44,    45,    46,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,    59,    60,    61,    62,    63,    64,    65,     0,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,   342,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,     0,   343,   344,
      89,     0,     0,     0,    91,     0,     0,     0,     0,    94,
     345,    96,   346,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   347,   348,   110,   349,   112,     0,
     113,   350,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   351,   129,   130,   131,   132,
     133,   352,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,   147,   148,   149,     0,   353,
     151,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   354,   178,   179,   355,
     181,   182,   183,   184,   185,   356,   187,   357,   189,   190,
     191,   192,   193,   194,   358,   359,   197,   360,   361,   200,
     201,   202,   203,   204,   205,    41,    42,    43,    44,    45,
      46,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,    59,    60,    61,    62,    63,    64,    65,
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   342,    79,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
     343,   344,    89,     0,     0,     0,    91,     0,     0,     0,
       0,    94,   345,    96,   346,    98,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   347,   348,   110,     0,
     112,     0,   113,     0,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   351,   129,   130,
     131,   132,   133,   352,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,   147,   148,   149,
       0,     0,   151,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   354,   178,
     179,   355,   181,   182,   183,   184,   185,   356,   187,   357,
     189,   190,   191,   192,   193,   194,   358,   359,   197,   360,
     361,   200,   201,   202,   203,   204,   205,     0,  1619,     0,
       0,   983,   984,   985,   986,     0,   987,     0,     0,   988,
       0,     0,   989,   990,   991,   992,   993,   994,   995,   996,
     997,     0,     0,   998,   999,  1000,  1620,     0,     0,   983,
     984,   985,   986,     0,   987,     0,     0,   988,     0,     0,
     989,   990,   991,   992,   993,   994,   995,   996,   997,     0,
       0,   998,   999,  1000,     0,  1625,     0,     0,   983,   984,
     985,   986,     0,   987,   313,     0,   988,  1001,  1002,   989,
     990,   991,   992,   993,   994,   995,   996,   997,     0,     0,
     998,   999,  1000,  1631,     0,     0,   983,   984,   985,   986,
       0,   987,   313,     0,   988,  1001,  1002,   989,   990,   991,
     992,   993,   994,   995,   996,   997,     0,     0,   998,   999,
    1000,     0,  1715,     0,     0,   983,   984,   985,   986,     0,
     987,   313,     0,   988,  1001,  1002,   989,   990,   991,   992,
     993,   994,   995,   996,   997,     0,     0,   998,   999,  1000,
    1716,     0,     0,   983,   984,   985,   986,     0,   987,   313,
       0,   988,  1001,  1002,   989,   990,   991,   992,   993,   994,
     995,   996,   997,     0,     0,   998,   999,  1000,     0,  1719,
       0,     0,   983,   984,   985,   986,     0,   987,   313,     0,
     988,  1001,  1002,   989,   990,   991,   992,   993,   994,   995,
     996,   997,     0,     0,   998,   999,  1000,  1720,     0,     0,
     983,   984,   985,   986,     0,   987,   313,     0,   988,  1001,
    1002,   989,   990,   991,   992,   993,   994,   995,   996,   997,
       0,     0,   998,   999,  1000,     0,     0,     0,     0,   983,
     984,   985,   986,     0,   987,   313,     0,   988,  1001,  1002,
     989,   990,   991,   992,   993,   994,   995,   996,   997,     0,
       0,   998,   999,  1000,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   313,     0,     0,  1001,  1002,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,  1001,  1002
};

static const yytype_int16 yycheck[] =
{
       7,     8,     9,   320,     6,    12,   386,    14,   769,     9,
     620,   934,   532,   691,   536,   237,  1070,   729,  1332,    26,
      27,   729,  1399,   665,  1282,   667,     9,   690,   670,  1107,
    1108,     8,   537,   538,   539,   540,   972,  1349,   974,    74,
     462,  1283,   897,    18,  1561,   467,    44,    14,   470,    44,
      70,  1412,   474,   366,   367,   133,   698,    52,    56,   133,
      13,    37,    14,  1604,    44,   133,    15,    56,    15,    70,
    1006,    56,    16,    60,    52,   130,    16,    13,   741,   742,
    1016,    38,    39,   130,    56,  1021,    56,  1023,    36,  1025,
      13,  1027,    16,  1029,    52,  1031,    44,  1033,   133,  1155,
    1156,  1037,    45,  1039,    52,    53,   259,    38,    39,   291,
     161,    36,    54,  1691,    44,    63,    64,    65,  1041,    44,
      44,   184,   785,     0,    44,    55,  1756,    52,    52,    44,
      73,   258,    81,   196,    81,    70,   318,    52,    63,    64,
      65,    38,    39,   194,   611,   125,    16,  1389,   126,   517,
     518,   519,   520,   521,   522,   818,   524,   525,   526,   527,
     528,   529,   530,   531,   291,   137,    23,   222,   223,   216,
     931,   324,   140,   815,    37,   222,   223,   938,   939,   940,
     115,   942,   943,   944,    54,   897,   313,   899,   136,   897,
      37,   899,   953,   954,  1824,    52,   957,   958,   142,    17,
      18,    19,    20,    21,    22,   125,   142,    76,    77,    78,
      28,   136,  1790,   136,   194,   204,  1593,   237,   203,   206,
     135,  1762,  1145,    41,   173,   174,   173,   174,   186,    44,
     872,   203,    25,   203,   186,   175,   237,    52,  1174,   118,
     247,   172,  1178,   250,   242,   187,   668,  1608,  1609,  1610,
    1611,   329,   205,   331,   230,   329,   330,   242,   253,   202,
    1777,   329,   330,  1118,   686,   240,    23,   224,   225,   226,
     242,    44,   242,   125,   194,   172,   743,   744,   135,    13,
     247,    49,  1218,   250,    52,   116,   708,    44,   601,   602,
     603,   604,  1604,  1605,  1230,    52,   159,   332,   333,   334,
     112,   119,   120,   121,   122,   123,   124,  1644,   256,   116,
    1366,    45,   159,     7,    49,   184,    23,    52,    12,    44,
     135,   149,  1378,   192,   193,   194,   195,   196,   156,  1587,
      13,   256,    26,    27,   141,  1043,   136,    44,   163,   258,
    1396,    28,   194,   155,    31,    32,    51,    52,    35,  1686,
     136,   719,   125,   290,  1668,    51,    52,  1669,   126,   366,
     367,   368,   369,   181,    96,    52,   235,    99,    79,    80,
     102,   103,   104,   105,   202,   203,   245,   314,   135,   386,
      63,    64,    65,  1760,   184,   304,   386,   182,   257,    13,
     236,   126,  1055,   188,   194,   314,    36,   819,   184,    63,
      64,    65,   113,   386,    44,   291,  1118,   253,   233,   234,
    1118,   291,    52,  1125,   421,  1127,   241,  1125,  1060,  1127,
      36,    45,   127,    63,    64,    65,   433,   313,   314,  1741,
     162,   127,    44,   433,   314,   442,    52,   317,   318,   446,
     447,   128,   129,  1499,  1498,    15,   446,   447,  1690,    38,
      39,    44,   249,   136,   106,   462,   253,    27,    27,  1537,
     467,  1071,  1072,   470,   196,   281,  1780,   474,    38,   291,
    1782,  1394,   136,   125,    52,  1398,    45,   291,   485,   131,
      29,    34,   214,   215,  1540,   485,   218,    40,   291,  1425,
      44,   498,   314,   500,    37,  1753,   136,    46,   314,   313,
     314,    79,    80,   319,   320,   187,  1562,   824,    61,  1172,
      53,   314,  1448,   289,  1177,   314,   198,   291,   317,  1182,
      44,  1577,   298,  1186,  1580,  1581,   290,   291,  1464,   303,
     119,   120,   121,   122,   123,   124,  1472,    23,  1594,   313,
    1476,    23,    37,   291,    24,    25,    37,    37,   312,   313,
      23,   315,   559,   301,   302,   207,   208,   209,    53,    37,
     212,   213,    53,    53,    44,   313,   314,    26,   575,   571,
      26,    26,    44,  1236,    23,    53,   583,  1500,    37,    13,
      52,    37,    37,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
      44,    37,    37,   610,   611,    52,   583,    37,    52,  1287,
     291,   611,   619,   590,  1670,  1278,  1279,    53,    53,    37,
     301,   302,   258,    53,   291,    34,  1338,    23,   605,   265,
    1338,    40,   313,   314,   301,    53,    37,    37,  1301,    37,
    1694,   434,  1305,  1699,  1700,   438,   313,   314,    37,    37,
     443,    26,    53,    53,    37,    53,   449,   219,   220,   221,
      37,   668,    37,    37,    53,    53,    36,  1723,   461,    37,
      53,    45,   465,   466,  1728,   369,    53,    45,   900,   686,
      37,    37,    52,   690,  1221,   478,   479,   480,    45,    37,
     690,    37,    37,   486,    37,  1232,  1233,    53,    37,    45,
      45,   708,    45,    34,  1241,    53,    45,   690,  1245,    40,
    1247,  1248,   231,  1250,  1768,   484,  1253,  1254,    37,   488,
     239,    37,   191,   258,    23,   260,    45,   421,    23,    45,
     199,    37,   267,   268,   741,   742,   743,   744,   273,    45,
      23,   741,   742,   743,   744,    23,    37,    37,   442,    37,
      23,   286,   287,   288,    45,    45,   549,    45,   741,   742,
      23,    37,   555,   556,   133,   134,    37,   560,   462,    45,
     258,    37,    56,   467,    45,    37,   470,   265,   785,    45,
     474,    37,    52,    45,   791,   785,    63,    64,    65,    45,
       4,     5,    76,    77,    78,  1503,    10,   102,   103,   104,
     105,    48,   785,    50,   498,    48,   500,    50,    52,  1331,
    1330,   818,   819,    13,   791,  1576,    13,   175,   818,   177,
    1325,   224,   225,   226,   176,   177,   833,   116,   117,  1209,
     552,   553,   554,   833,    44,   818,   325,   326,    44,  1361,
    1362,   634,    38,    39,   142,   143,  1509,   145,   146,   147,
      44,   149,   150,   137,    38,    39,   167,   650,   133,   134,
     200,   201,   869,   327,   328,   559,  1288,   299,   300,   869,
     151,   152,  1294,   245,   881,  1636,   304,   305,  1300,  1521,
      70,   575,   889,    52,   677,   678,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   182,   183,   131,   132,
     184,    52,   182,   183,  1514,  1515,  1584,    37,   192,   193,
     194,   195,   196,   154,   155,   252,   610,   258,   168,   203,
     261,   262,   263,   264,   169,   266,   180,   934,   269,   110,
     111,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     270,   271,   283,   284,   285,   227,   228,  1264,    97,    98,
     171,   235,   179,  1616,    97,    98,    25,  1635,   242,    25,
    1721,   245,   197,  1724,    59,  1628,   595,   596,   597,   598,
     599,   600,   191,   257,   668,   154,   155,   189,   190,   534,
     535,   541,   542,   324,   543,   544,   327,   328,    20,    21,
    1784,  1785,   686,   593,   594,    57,    44,   167,    25,    44,
     168,    44,    44,    44,    44,  1766,    44,    44,    44,    44,
      44,    33,    13,  1691,   708,    44,   163,    45,    37,    52,
      45,    45,    52,    37,    45,   170,    52,    13,   148,    52,
     149,   170,    63,  1040,  1041,    74,   163,   163,   163,  1649,
     201,   201,   163,    45,    37,  1052,    45,    45,  1055,  1571,
    1572,  1693,   116,    45,  1762,  1055,    44,   117,    45,    14,
      45,    45,    45,    45,    45,   236,    70,  1828,    14,   163,
     236,   148,  1055,    52,  1752,   136,    54,   136,   184,   184,
    1758,    44,    26,   876,   258,    45,    45,    37,  1751,   146,
      54,   141,  1770,  1771,  1772,  1773,    54,    54,    54,    14,
      14,    13,  1524,   161,    14,   898,  1528,    44,   125,   165,
      44,    37,  1790,  1791,   254,   289,    27,   291,   292,   293,
     294,   295,   296,   297,   142,   819,  1804,   101,   144,    94,
     210,   255,   306,   307,   308,   309,   310,   311,  1145,   241,
     241,    95,   258,  1150,   316,   291,  1153,   321,   322,   323,
     314,   258,   270,  1831,  1676,   314,   314,   165,   289,    45,
     291,    44,    16,   163,  1171,  1172,    13,  1589,    45,    45,
    1177,   191,  1172,    13,    13,  1182,   153,  1177,    45,  1186,
     108,   236,  1182,   236,   107,    41,  1186,   881,    95,  1172,
     205,   144,   300,   136,  1177,   889,   299,   267,   133,  1182,
     282,   316,  1209,  1186,  1171,    41,   258,    45,  1588,  1209,
      14,   224,   163,    14,    47,    47,    37,    13,   166,   144,
      45,    44,    53,   156,    41,   107,  1209,   224,   136,  1236,
      37,   211,   153,   136,   246,   184,  1236,   184,    13,   163,
     934,   202,    23,    16,   125,    44,    44,   258,   133,   258,
     166,   224,   136,  1236,   163,    37,    41,   184,    37,    25,
      14,    41,   136,    41,  1266,   163,    30,  1274,    45,   142,
     246,  1278,  1279,  1590,    45,  1282,    37,    37,  1278,  1279,
      14,  1288,   125,    45,   970,   217,   217,  1294,  1206,   984,
       3,  1606,   768,  1300,  1301,  1278,  1279,  1274,  1305,  1227,
    1216,  1301,   773,   403,   774,  1305,   873,   212,   318,   669,
     895,   666,  1110,  1090,   109,  1282,   515,   671,  1301,   920,
    1516,   516,  1305,  1287,   564,   134,   439,   744,   439,   485,
     869,  1125,   446,  1338,   899,  1127,  1320,  1549,  1334,  1346,
    1359,  1143,  1667,  1672,   661,  1584,  1522,  1041,   889,  1052,
     881,   885,   789,   591,  1047,   592,    -1,   606,  1052,    -1,
     491,    -1,    -1,    -1,   495,    -1,    -1,    -1,   499,    -1,
     501,   502,   503,    -1,    -1,   506,    -1,    -1,    -1,    -1,
      -1,  1388,    -1,    -1,    -1,    -1,  1393,  1394,    -1,    -1,
    1183,  1398,    -1,    -1,  1187,    -1,  1403,    -1,   258,    -1,
      -1,   261,   262,   263,   264,  1412,   266,    -1,  1725,   269,
      -1,    -1,   272,   273,   274,   275,   276,   277,   278,   279,
     280,  1214,    -1,   283,   284,   285,  1219,  1220,    -1,    -1,
     561,  1224,    -1,   564,    -1,    -1,  1403,    -1,  1231,    -1,
      -1,    -1,    -1,    -1,  1237,  1412,  1239,    -1,    -1,  1242,
     581,  1145,    -1,  1246,    -1,    -1,  1150,    -1,  1251,  1153,
      -1,    -1,    -1,    -1,   324,  1258,    -1,   327,   328,  1262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1500,  1501,    -1,   627,    -1,    -1,    -1,
      -1,    -1,  1509,    -1,    -1,    -1,    -1,    -1,    -1,  1509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1524,    -1,    -1,
      -1,  1528,    -1,    -1,    -1,    -1,  1509,    -1,    -1,    -1,
      -1,   662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   672,   673,    -1,   258,    -1,    -1,   261,   262,   263,
     264,    -1,   266,    -1,    -1,   269,    -1,    -1,   272,   273,
     274,   275,   276,   277,   278,   279,   280,    -1,    -1,   283,
     284,   285,    -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,
    1587,  1588,  1589,    -1,    -1,    -1,    -1,    -1,  1588,    -1,
      -1,    -1,    -1,    -1,  1288,  1602,  1603,    -1,    -1,  1606,
    1294,  1608,  1609,  1610,  1611,  1588,  1300,    -1,    -1,  1616,
     324,    -1,    -1,   327,   328,    -1,  1616,    -1,    -1,    16,
    1587,  1628,    -1,    -1,    -1,    -1,    -1,    -1,  1628,   760,
     761,   762,  1639,  1616,  1641,  1602,  1603,    -1,    -1,  1606,
      -1,  1608,  1609,  1610,  1611,  1628,    -1,    44,    45,    -1,
      -1,    -1,  1346,    -1,  1447,    52,    -1,    54,    -1,    -1,
      -1,    -1,   258,    -1,  1641,   261,   262,   263,   264,    -1,
     266,    -1,    -1,   269,    -1,    -1,   272,   273,   274,   275,
     276,   277,   278,   279,   280,    -1,    -1,   283,   284,   285,
      -1,    -1,    -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,
    1394,    -1,    -1,    -1,  1398,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   850,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,   327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1751,    -1,  1753,   878,   879,   880,
      -1,  1751,    -1,   884,   885,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   895,    -1,    -1,    -1,  1751,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,   261,
     262,   263,   264,    -1,   266,    -1,  1753,   269,    -1,   920,
     272,   273,   274,   275,   276,   277,   278,   279,   280,    -1,
      -1,   283,   284,   285,    -1,    -1,  1500,  1501,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1617,    -1,    -1,    -1,    -1,    -1,
    1524,    -1,    -1,    -1,  1528,    -1,  1629,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,   261,   262,   263,   264,    -1,   266,
     267,    -1,   269,    -1,    -1,   272,   273,   274,   275,   276,
     277,   278,   279,   280,    -1,    -1,   283,   284,   285,    -1,
      -1,    -1,    -1,   290,   291,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1045,   312,   313,    -1,   315,  1712,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
     327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1083,    -1,    -1,  1086,  1087,  1088,    -1,    -1,
      -1,    -1,  1093,    -1,    -1,    -1,   258,    -1,    -1,   261,
     262,   263,   264,  1104,   266,    -1,    -1,   269,    -1,  1110,
     272,   273,   274,   275,   276,   277,   278,   279,   280,    -1,
      -1,   283,   284,   285,    -1,    -1,   258,    -1,    -1,   261,
     262,   263,   264,    -1,   266,  1136,  1137,   269,    -1,    -1,
     272,   273,   274,   275,   276,   277,   278,   279,   280,    -1,
      -1,   283,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,   258,   327,   328,   261,   262,   263,
     264,    -1,   266,    -1,    -1,   269,    -1,    -1,   272,   273,
     274,   275,   276,   277,   278,   279,   280,    -1,    -1,   283,
     284,   285,   324,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     324,    -1,    -1,   327,   328,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,  1306,   137,    -1,    -1,    -1,
    1311,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,   198,   199,   200,
      -1,   202,   203,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,   261,   262,   263,   264,
      -1,   266,    -1,    -1,   269,    -1,    -1,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    -1,    -1,   283,   284,
     285,    -1,    -1,   258,    -1,    -1,   261,   262,   263,   264,
      -1,   266,    -1,    -1,   269,    -1,    -1,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    -1,    -1,   283,   284,
     285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   329,   324,
     331,    -1,   327,   328,    -1,    -1,    -1,    -1,    -1,  1510,
      -1,    -1,  1513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1525,    -1,    -1,    -1,  1529,   324,
      -1,  1532,   327,   328,   258,    -1,    -1,   261,   262,   263,
     264,    -1,   266,    -1,    -1,   269,    -1,    -1,   272,   273,
     274,   275,   276,   277,   278,   279,   280,    -1,    -1,   283,
     284,   285,   258,    -1,    -1,   261,   262,   263,   264,    -1,
     266,    -1,    -1,   269,    -1,    -1,   272,   273,   274,   275,
     276,   277,   278,   279,   280,    -1,    -1,   283,   284,   285,
      -1,   258,    -1,    -1,   261,   262,   263,   264,    -1,   266,
     324,    -1,   269,   327,   328,   272,   273,   274,   275,   276,
     277,   278,   279,   280,    -1,    -1,   283,   284,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,   327,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,   258,
     327,   328,   261,   262,   263,   264,    -1,   266,    -1,    -1,
     269,    -1,    -1,   272,   273,   274,   275,   276,   277,   278,
     279,   280,    -1,    -1,   283,   284,   285,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    27,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,   324,    -1,    -1,   327,   328,
      -1,    -1,    -1,    58,    -1,  1736,  1737,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,  1792,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,  1805,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    28,    -1,
      -1,    31,    32,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    34,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    32,    -1,    34,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,    -1,   161,    -1,   163,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,    -1,   203,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,   137,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      -1,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,   198,   199,   200,    -1,
     202,   203,    -1,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,   198,
     199,   200,    -1,   202,   203,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
      -1,   137,   138,   139,    -1,    -1,   142,   143,   144,   145,
     146,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,   198,   199,   200,    -1,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
     137,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,   198,   199,   200,    -1,   202,   203,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,   136,
     137,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,    -1,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,   198,   199,   200,    -1,    -1,   203,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,    -1,   119,   120,   121,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,   136,
     137,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    -1,   161,    -1,   163,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,   198,   199,   200,    -1,    -1,   203,    -1,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,   198,   199,   200,    -1,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,   198,
     199,   200,    -1,   202,   203,    -1,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,
     136,   137,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,   198,   199,   200,    -1,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,   131,   132,   133,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,    -1,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,   198,   199,   200,    -1,   202,   203,    -1,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,   198,   199,   200,    -1,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,    -1,
     161,    -1,   163,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,   198,   199,   200,
      -1,    -1,   203,    -1,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   258,    -1,
      -1,   261,   262,   263,   264,    -1,   266,    -1,    -1,   269,
      -1,    -1,   272,   273,   274,   275,   276,   277,   278,   279,
     280,    -1,    -1,   283,   284,   285,   258,    -1,    -1,   261,
     262,   263,   264,    -1,   266,    -1,    -1,   269,    -1,    -1,
     272,   273,   274,   275,   276,   277,   278,   279,   280,    -1,
      -1,   283,   284,   285,    -1,   258,    -1,    -1,   261,   262,
     263,   264,    -1,   266,   324,    -1,   269,   327,   328,   272,
     273,   274,   275,   276,   277,   278,   279,   280,    -1,    -1,
     283,   284,   285,   258,    -1,    -1,   261,   262,   263,   264,
      -1,   266,   324,    -1,   269,   327,   328,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    -1,    -1,   283,   284,
     285,    -1,   258,    -1,    -1,   261,   262,   263,   264,    -1,
     266,   324,    -1,   269,   327,   328,   272,   273,   274,   275,
     276,   277,   278,   279,   280,    -1,    -1,   283,   284,   285,
     258,    -1,    -1,   261,   262,   263,   264,    -1,   266,   324,
      -1,   269,   327,   328,   272,   273,   274,   275,   276,   277,
     278,   279,   280,    -1,    -1,   283,   284,   285,    -1,   258,
      -1,    -1,   261,   262,   263,   264,    -1,   266,   324,    -1,
     269,   327,   328,   272,   273,   274,   275,   276,   277,   278,
     279,   280,    -1,    -1,   283,   284,   285,   258,    -1,    -1,
     261,   262,   263,   264,    -1,   266,   324,    -1,   269,   327,
     328,   272,   273,   274,   275,   276,   277,   278,   279,   280,
      -1,    -1,   283,   284,   285,    -1,    -1,    -1,    -1,   261,
     262,   263,   264,    -1,   266,   324,    -1,   269,   327,   328,
     272,   273,   274,   275,   276,   277,   278,   279,   280,    -1,
      -1,   283,   284,   285,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,    -1,    -1,   327,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,    -1,    -1,   327,   328
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   336,    13,    15,    24,    28,    31,    32,    34,    36,
      38,    39,    40,    42,    43,    44,    58,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     119,   120,   121,   122,   123,   124,   125,   131,   132,   133,
     136,   137,   138,   139,   142,   143,   144,   145,   146,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   198,   199,   200,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   346,   347,   488,   489,
     490,   491,   492,   493,   495,   500,   511,   514,   520,   521,
     522,   523,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   564,
     565,   566,   567,   568,   571,   572,   573,   584,   586,   588,
     589,   590,   593,   595,   596,   597,   598,   608,   609,   610,
     611,   612,   613,   614,   615,   617,   619,   621,   662,   663,
     664,   665,   666,   667,   668,   671,   672,   673,   674,   676,
     683,   684,   688,   689,   690,   691,   702,   705,   708,   727,
     728,   337,   259,   324,   360,   361,   385,   337,   337,   353,
     474,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   114,   131,   132,   143,   145,   157,   158,   160,
     164,   178,   184,   202,   229,   232,   238,   240,   247,   248,
     250,   251,   710,   712,   727,   728,    38,    39,    44,    58,
      63,    64,    65,   136,   164,   711,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   728,    44,    66,    67,    71,
      74,    75,   185,   202,   247,   248,   604,   606,   607,   608,
     676,   692,   693,   694,   695,   697,   698,   701,   337,     0,
     563,   727,   556,   133,   134,   574,   140,   118,   585,   545,
     116,   576,   536,   536,    45,   489,   727,   329,   331,   349,
     685,   727,    23,    44,    52,   135,   594,    44,    52,    44,
      44,    44,    44,    52,   135,   599,    44,    44,    44,    52,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    52,    13,   669,   670,    52,    52,    13,   496,   497,
      13,   205,   501,   502,    13,   512,   513,   512,    44,    44,
      52,    79,    80,    23,   599,    44,    52,   135,   591,    44,
     480,    70,   115,    70,   237,    70,    70,   237,    52,    52,
     245,   252,    37,   142,   143,   145,   146,   147,   149,   150,
     493,   494,   503,   504,   505,   167,   168,    17,    18,    19,
      20,    21,    22,    28,    41,   119,   120,   121,   122,   123,
     124,   181,    60,   206,    38,    39,   172,    15,    81,   173,
     174,    16,   175,   176,   177,   169,   180,   171,   179,    52,
     541,   545,    34,    40,    61,    25,    25,   556,   556,    24,
      25,    44,   490,   490,    44,    55,   197,   446,   447,   362,
     386,   191,   351,   354,   447,    56,   242,   475,   476,   480,
     483,    59,   714,    57,   721,   721,   715,   724,   725,   727,
      44,   167,   168,    38,    39,   119,   120,   121,   122,   123,
     124,    15,    81,   173,   174,    25,    44,   606,    44,    44,
      44,    44,    15,    27,    38,   605,   204,   483,   338,   339,
     575,   116,   117,   587,    33,   727,    45,    44,    15,    45,
     616,   623,   676,   489,    52,   592,    45,   489,    45,    73,
     202,   619,   621,    45,    45,    45,   136,   675,   727,   489,
      52,   600,   618,   623,   622,   624,   676,    45,   489,   489,
     563,    37,   230,   489,   489,   563,    37,   563,    13,    37,
     563,    37,   159,   159,   489,   489,   489,    52,    52,   592,
      15,    45,   620,   624,   489,   592,    13,    45,   485,   486,
     163,   603,   490,   170,   490,    53,   703,   704,   727,    53,
     490,   706,   707,   727,   490,   490,   490,   490,    13,   148,
     149,   522,   523,   525,   525,   525,   525,   525,   525,   524,
     525,   525,   525,   525,   525,   525,   525,   525,   527,    74,
     529,   529,   528,   530,   530,   530,   530,   531,   531,   532,
     532,   170,   163,   163,   163,    53,   489,   546,   546,   546,
     489,   489,   727,   489,    27,    45,   490,   569,   570,   163,
     233,   234,   241,    45,   569,    63,   187,   198,   448,   449,
     201,   450,   451,   452,   453,   289,   298,   363,   325,   326,
     388,   474,   201,   355,   727,   163,   481,   490,   726,   715,
      45,    37,   715,   717,   718,   720,   720,   719,   719,   719,
     719,   719,   719,   721,   721,   721,   721,   715,   724,    45,
      45,    45,    45,   699,   700,   727,    45,   607,    44,    13,
      62,   340,   341,   342,   728,   116,   576,   117,   116,   141,
     542,   348,   490,    37,    45,    53,    53,   489,    53,    45,
      45,    45,    45,    53,    53,   489,    45,    45,    53,    53,
      14,   670,   490,    53,    53,   603,   497,   603,   563,   502,
     603,   513,   490,   490,    45,    45,    53,   489,   489,    37,
      45,    53,   563,    37,    45,   604,    52,   487,   236,    70,
     163,    37,    53,   603,    14,    37,    53,   236,   236,   253,
     563,   490,   506,   507,   508,   148,   525,    44,    52,   256,
     540,   560,   627,   630,   631,   632,   633,   634,   635,   636,
     637,   604,   604,   601,   607,   601,    53,    26,    26,    26,
      37,    45,   231,   239,   490,   490,   490,    45,   136,   136,
      54,   449,   456,   456,   184,   453,   191,   199,   454,   455,
     457,   458,   459,   460,   461,   462,   463,   464,   467,   468,
     469,   472,   473,   477,   479,   488,   661,   677,   709,   258,
     260,   267,   268,   273,   286,   287,   288,   364,   365,   368,
     369,   373,   374,   375,   376,   377,   378,   381,   382,   383,
     384,   387,   258,   261,   262,   263,   264,   266,   269,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   283,   284,
     285,   327,   328,   385,   389,   390,   391,   392,   393,   394,
     395,   398,   399,   403,   404,   405,   406,   407,   412,   413,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     203,   184,   356,    44,   604,   146,   713,   713,   715,    45,
      26,    45,    37,    45,   603,    37,    15,    45,   604,   696,
     563,   133,   329,   330,   343,   344,   682,    54,    54,    54,
     480,   133,   134,    29,    46,   141,    54,   350,   625,   676,
      53,    53,   490,   142,   125,   498,    14,    14,   144,   161,
     515,   517,   518,   165,    53,    53,   625,   603,   486,   489,
     490,   490,   490,   704,    14,   490,   707,    44,    44,   685,
      37,   151,   152,   509,   506,   627,   489,   634,    52,   219,
     220,   221,   638,   101,   660,   254,   629,   255,    94,    95,
     644,   210,   639,    27,   602,   570,   241,   241,   456,   675,
     191,   199,    76,    77,    78,   184,   192,   193,   194,   195,
     196,   235,   245,   257,   474,   200,   201,   456,   456,   456,
     456,   456,   456,   456,   456,   456,   456,   299,   300,   290,
     291,   312,   313,   315,   370,   291,   303,   313,   370,   291,
     301,   302,   313,   314,   388,   291,   313,   314,   388,   258,
     289,   291,   292,   293,   294,   295,   296,   297,   306,   307,
     308,   309,   310,   311,   321,   322,   323,   258,   291,   313,
     258,   126,   487,   393,   314,   270,   408,   409,   410,   316,
     314,   317,   388,   290,   314,   397,   291,   400,   258,   388,
     281,   314,   319,   320,   414,   291,   313,   314,   388,   314,
     388,   291,   314,   388,   388,   291,   314,   317,   318,   388,
     291,   314,   388,   291,   318,   388,   258,   304,   314,   304,
     305,   388,   314,   388,   728,   675,   191,   357,   358,   359,
     484,   560,   490,   714,   165,   700,   604,    45,   163,    37,
      45,   603,    44,    16,   481,   576,   576,   583,    13,   686,
     687,    45,    45,   490,    13,   205,   499,   490,   490,   490,
      13,   519,   194,   516,   517,    16,   142,   490,    27,    45,
      53,   236,   490,   686,   686,   236,   507,   153,   510,    45,
      53,    53,   627,   108,   224,   107,   631,   106,   125,   131,
     207,   208,   209,   212,   213,   628,   641,   632,   144,    96,
      99,   102,   103,   104,   105,   162,   196,   214,   215,   218,
     645,   646,   647,   648,   649,   652,   657,   658,   659,    95,
     130,   222,   223,   640,   490,   490,    41,   182,   183,   644,
     136,   626,   675,   182,   183,   131,   132,   149,   156,   202,
     203,   182,   188,   465,   727,    79,    80,   113,   249,   253,
     680,   727,   137,   203,   184,   194,   471,   626,   184,   626,
     300,   299,   366,    24,    34,    40,    66,    82,   243,   244,
     436,   437,   438,   439,   442,   443,   444,   556,   604,    63,
      64,    65,   367,   267,   371,   372,   388,   604,   388,   604,
     489,   258,   604,   489,   258,    74,   133,   332,   333,   334,
     379,   133,   380,   380,   606,   258,   489,   316,   271,   409,
     411,   388,   489,   489,   387,   258,   133,   329,   331,   396,
     489,   258,   265,   401,   402,   258,   401,   258,   388,   489,
     387,   387,   282,   415,   604,   489,   258,   489,   258,   387,
     489,   258,   258,   387,   489,   387,   387,   258,   387,   489,
     258,   387,   387,   258,   489,   258,   489,   258,   480,    41,
     184,   196,   474,    37,    45,   715,    45,   604,   604,   163,
      14,   436,   682,    14,    47,    47,    35,   128,   129,   487,
     572,   563,    37,   563,    13,   144,   563,   604,    13,   142,
     604,   490,   166,    45,   490,    45,    45,    44,   154,   155,
     156,   638,    53,   530,   107,   110,   111,   527,   528,   640,
     227,   228,   643,   643,   633,   102,   103,   104,   105,    97,
      98,    44,   125,   194,   651,   224,    97,    98,   727,   674,
     645,   112,   155,   528,   528,   211,   626,    41,   153,   626,
     184,   184,    37,   136,   727,   681,   682,   246,   163,    13,
     728,   675,   202,   626,   125,   470,   675,   470,   133,   329,
     330,   556,    23,    23,    44,    44,    16,   443,    34,    40,
      34,    40,   445,   291,   301,   302,   313,   314,   388,   258,
     258,   133,   489,   388,   258,   258,   291,   301,   313,   314,
     388,   258,   388,   258,   388,   481,   626,   675,   727,   203,
     560,   166,   604,   490,    54,   345,   490,   576,   576,   574,
     603,   687,   563,   490,   163,   563,   490,   490,   686,   626,
     224,   225,   226,   642,   642,   224,   194,   651,   626,    44,
     125,   194,   654,   136,   528,   528,   172,   456,   626,   154,
     155,   626,   626,   189,   190,   466,    44,   487,   679,   680,
      37,   436,   606,   563,   480,    41,   184,   470,   626,    37,
      41,   556,   556,   440,   562,   674,   674,   437,   443,   443,
     443,   443,    25,   604,   489,   258,   258,   604,   489,   258,
     258,   487,   456,    41,   136,   728,   715,   485,    45,    48,
      50,   577,    48,    50,   578,   576,    14,   142,    45,   650,
     650,   216,   640,   655,   674,   626,   653,   653,   528,    45,
     485,   163,   678,   246,   682,   487,   679,   603,   481,   626,
     626,    45,    37,   489,   352,   456,   626,   456,   480,   481,
     579,   581,   580,   582,    30,   490,   490,    37,    45,    45,
     674,   217,    37,    45,   175,   177,   656,    45,   604,   487,
     436,   678,    14,   186,   478,   186,   482,   487,   470,   441,
     560,   562,    26,   456,   481,    14,    49,   126,   487,    51,
     127,   487,    49,   126,   487,    51,   127,   487,   651,   640,
     674,   654,   654,   487,   679,   487,   490,    45,   487,   490,
     217,   678,   456,   487
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:

/* Line 1455 of yacc.c  */
#line 822 "../src/parser/XQParser.y"
    {
    QP->_seqType = (yyvsp[(2) - (2)].sequenceType);
  }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 830 "../src/parser/XQParser.y"
    {
    BuiltInModules::addNamespaces(CONTEXT);
  }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 839 "../src/parser/XQParser.y"
    {
    SequenceType *optionalString =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) SequenceType((ItemType*)&ItemType::ANY_ATOMIC_TYPE, SequenceType::QUESTION_MARK));

    XQGlobalVariable *nameVar =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQGlobalVariable(0, optionalString,
                                             WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQSequence(MEMMGR)), MEMMGR, /*isParam*/true));
    nameVar->setVariableURI(XQillaFunction::XMLChFunctionURI);
    nameVar->setVariableLocalName(var_name);

    QP->_query->addVariable(nameVar);

    ASTNode *nameVarRef1 = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQVariable(XQillaFunction::XMLChFunctionURI, var_name, MEMMGR));
    XQCallTemplate *call = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQCallTemplate(nameVarRef1, 0, MEMMGR));

    ASTNode *ci = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQContextItem(MEMMGR));
    ASTNode *apply = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQApplyTemplates(ci, 0, 0, MEMMGR));

    VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    args->push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQVariable(XQillaFunction::XMLChFunctionURI, var_name, MEMMGR)));
    ASTNode *exists = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                                           MEMMGR->getPooledString("exists"), args, MEMMGR));

    QP->_query->setQueryBody(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQIf(exists, call, apply, MEMMGR)));
  }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 875 "../src/parser/XQParser.y"
    {
    QP->_query->addVariable(WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQGlobalVariable((yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].sequenceType), (yyvsp[(5) - (5)].astNode), MEMMGR)));
  }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 882 "../src/parser/XQParser.y"
    {
    FunctionSignature *sig = new (MEMMGR) FunctionSignature(MEMMGR);
    sig->argSpecs = (yyvsp[(2) - (5)].argSpecs);
    sig->returnType = (yyvsp[(3) - (5)].sequenceType);
    XQUserFunction* decl=WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQUserFunction((yyvsp[(1) - (5)].str), sig, (yyvsp[(5) - (5)].astNode), true, MEMMGR));
    QP->_query->addFunction(decl);
  }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 893 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature((yyvsp[(5) - (9)].argSpecs), (yyvsp[(7) - (9)].sequenceType), MEMMGR);
    XQUserFunction* decl=WRAP((yylsp[(1) - (9)]), new (MEMMGR) XQUserFunction(0, (yyvsp[(4) - (9)].itemList), signature, (yyvsp[(9) - (9)].astNode), MEMMGR));
    decl->setModeList((yyvsp[(2) - (9)].modeList));
    QP->_query->addFunction(decl);
  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 903 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
    (yyval.modeList)->push_back(WRAP((yyloc), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT)));
  }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 912 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
    (yyval.modeList)->push_back((yyvsp[(1) - (1)].mode));
  }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 917 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].modeList)->push_back((yyvsp[(3) - (3)].mode));
    (yyval.modeList) = (yyvsp[(1) - (3)].modeList);
  }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 925 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = 0;
  }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 929 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = (yyvsp[(2) - (2)].argSpecs);
  }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 938 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) XQApplyTemplates((yyvsp[(4) - (6)].astNode), (yyvsp[(5) - (6)].templateArgs), (yyvsp[(2) - (6)].mode), MEMMGR));
  }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 945 "../src/parser/XQParser.y"
    {
    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setTypeWildcard();
    nt->setNameWildcard();
    nt->setNamespaceWildcard();

    (yyval.astNode) = WRAP((yyloc), new (MEMMGR) XQStep(Node::CHILD, nt, MEMMGR));
  }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 958 "../src/parser/XQParser.y"
    {
    (yyval.mode) = 0;
  }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 966 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = 0;
  }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 970 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = (yyvsp[(2) - (2)].templateArgs);
  }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 980 "../src/parser/XQParser.y"
    {
    (yyvsp[(2) - (8)].signature)->argSpecs = (yyvsp[(5) - (8)].argSpecs);
    (yyvsp[(2) - (8)].signature)->returnType = (yyvsp[(6) - (8)].sequenceType);
    QP->_function = WRAP((yylsp[(1) - (8)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (8)].str), (yyvsp[(2) - (8)].signature), (yyvsp[(7) - (8)].astNode), true, MEMMGR));
  }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 991 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].signature)->argSpecs = (yyvsp[(2) - (3)].argSpecs);
    (yyvsp[(1) - (3)].signature)->returnType = (yyvsp[(3) - (3)].sequenceType);
    QP->_signature = (yyvsp[(1) - (3)].signature);
  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1000 "../src/parser/XQParser.y"
    {
    printf("  { DelayedModule::Decl::NONE, 0, 0, 0, 0, 0 }\n};\n\n");

    UTF8Str module(QP->_moduleName);
    printf("static const DelayedModule %s_module = { %s_file, %s_prefix, %s_uri, %s_declarations };\n",
           module.str(), module.str(), module.str(), module.str(), module.str());
  }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1011 "../src/parser/XQParser.y"
    {
    SET_NAMESPACE((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));

    QP->_moduleName = (yyvsp[(3) - (6)].str);

    UTF8Str module(QP->_moduleName);
    UTF8Str file(QP->_lexer->getFile());

    printf("// Auto-generated by compile-delayed-module from %s\n", file.str());
    printf("// DO NOT EDIT\n\n");

    printf("// %s\n", file.str());
    printf("static const XMLCh %s_file[] = { ", module.str());
    const XMLCh *ptr = QP->_lexer->getFile();
    for(; *ptr != 0; ++ptr) {
      printf("%d, ", *ptr);
    }
    printf("0 };\n\n");

    printf("// %s\n", UTF8((yyvsp[(3) - (6)].str)));
    printf("static const XMLCh %s_prefix[] = { ", module.str());
    ptr = (yyvsp[(3) - (6)].str);
    for(; *ptr != 0; ++ptr) {
      printf("%d, ", *ptr);
    }
    printf("0 };\n\n");

    printf("// %s\n", UTF8((yyvsp[(5) - (6)].str)));
    printf("static const XMLCh %s_uri[] = { ", module.str());
    ptr = (yyvsp[(5) - (6)].str);
    for(; *ptr != 0; ++ptr) {
      printf("%d, ", *ptr);
    }
    printf("0 };\n\n");
  }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1050 "../src/parser/XQParser.y"
    {
    printf("static const DelayedModule::Decl %s_declarations[] = {\n", UTF8(QP->_moduleName));
  }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1060 "../src/parser/XQParser.y"
    {
    XMLBuffer buf;

    // Call staticResolution on the function signature, to resolve the annotation names
    (yyvsp[(2) - (8)].signature)->staticResolution(CONTEXT);

    const XMLCh *localname = XPath2NSUtils::getLocalName((yyvsp[(4) - (8)].str));
    DM_outputDecl("FUNCTION", UTF8(localname), (int)((yyvsp[(5) - (8)].argSpecs) ? (yyvsp[(5) - (8)].argSpecs)->size() : 0),
                  (yyvsp[(2) - (8)].signature)->isPrivate(), (yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column,
                  ((XQLexer*)QP->_lexer)->getQueryString() + (yylsp[(1) - (8)]).first_offset,
                  (yylsp[(8) - (8)]).last_offset - (yylsp[(1) - (8)]).first_offset);
  }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1076 "../src/parser/XQParser.y"
    {
    // validate the QName
    QualifiedName qName((yyvsp[(3) - (5)].str));
    const XMLCh* prefix = qName.getPrefix();
    if(prefix == 0 || *prefix == 0)
      yyerror((yylsp[(3) - (5)]), "The option name must have a prefix [err:XPST0081]");

    const XMLCh *uri = 0;
    try {
      LOCATION((yylsp[(3) - (5)]), loc);
      uri = CONTEXT->getUriBoundToPrefix(prefix, &loc);
    }
    catch(NamespaceLookupException&) {
      yyerror((yylsp[(3) - (5)]), "The option name is using an undefined namespace prefix [err:XPST0081]");
    }

    if(XPath2Utils::equals(uri, XQRewriteRule::URI)) {
      if(XPath2Utils::equals(qName.getName(), option_rule)) {
        DM_outputDecl("REWRITE_RULE", "", 0, false, (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column + 1,
                      (yyvsp[(4) - (5)].str), XPath2Utils::intStrlen((yyvsp[(4) - (5)].str)));
      }
    }
  }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1103 "../src/parser/XQParser.y"
    {
    SET_NAMESPACE((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
    DM_outputDecl("NAMESPACE", UTF8((yyvsp[(3) - (6)].str)), 0, false, (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column,
                  (yyvsp[(5) - (6)].str), XPath2Utils::intStrlen((yyvsp[(5) - (6)].str)));
  }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1116 "../src/parser/XQParser.y"
    {
    SequenceType *optionalString =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) SequenceType((ItemType*)&ItemType::ANY_ATOMIC_TYPE, SequenceType::QUESTION_MARK));

    XQGlobalVariable *nameVar =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQGlobalVariable(0, optionalString,
                                             WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQSequence(MEMMGR)), MEMMGR, /*isParam*/true));
    nameVar->setVariableURI(XQillaFunction::XMLChFunctionURI);
    nameVar->setVariableLocalName(var_name);

    QP->_query->addVariable(nameVar);

    ASTNode *nameVarRef1 = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQVariable(XQillaFunction::XMLChFunctionURI, var_name, MEMMGR));
    XQCallTemplate *call = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQCallTemplate(nameVarRef1, 0, MEMMGR));

    ASTNode *ci = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQContextItem(MEMMGR));
    ASTNode *apply = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQApplyTemplates(ci, 0, 0, MEMMGR));

    VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    args->push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQVariable(XQillaFunction::XMLChFunctionURI, var_name, MEMMGR)));
    ASTNode *exists = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                                           MEMMGR->getPooledString("exists"), args, MEMMGR));

    QP->_query->setQueryBody(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQIf(exists, call, apply, MEMMGR)));
  }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1145 "../src/parser/XQParser.y"
    {
  }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1148 "../src/parser/XQParser.y"
    {
    // TBD Check for xsl:version attr - jpcs
    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setNodeType(Node::document_string);
    nt->setNameWildcard();
    nt->setNamespaceWildcard();

    VectorOfASTNodes *pattern = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    pattern->push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(Node::SELF, nt, MEMMGR)));

    XQUserFunction::ModeList *modelist = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
    modelist->push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT)));

    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    XQUserFunction *func = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction(0, pattern, signature, (yyvsp[(1) - (1)].astNode), MEMMGR));
    func->setModeList(modelist);

    QP->_query->addFunction(func);
  }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1172 "../src/parser/XQParser.y"
    {
    // TBD Check the value - jpcs
  }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1176 "../src/parser/XQParser.y"
    {
    // TBD implement exclude-result-prefixes - jpcs
  }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1195 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (4)].functDecl)->getName() == 0 && (yyvsp[(1) - (4)].functDecl)->getPattern() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:template declaration does not have either a {}name or {}match attribute, or both [err:XTSE0500]");
    }

    if((yyvsp[(1) - (4)].functDecl)->getPattern() != 0 && (yyvsp[(1) - (4)].functDecl)->getModeList() == 0) {
      XQUserFunction::ModeList *modelist = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
      modelist->push_back(WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT)));
      (yyvsp[(1) - (4)].functDecl)->setModeList(modelist);
    }

    (yyvsp[(1) - (4)].functDecl)->getSignature()->argSpecs = (yyvsp[(2) - (4)].argSpecs);
    (yyvsp[(1) - (4)].functDecl)->setFunctionBody((yyvsp[(3) - (4)].parenExpr));
    QP->_query->addFunction((yyvsp[(1) - (4)].functDecl));
  }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1214 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction(0, 0, signature, 0, MEMMGR));
  }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1219 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (3)].functDecl);
    (yyval.functDecl)->setPattern((yyvsp[(3) - (3)].itemList));
  }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1224 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (2)].functDecl);
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyval.functDecl)->setURI(uri);
    (yyval.functDecl)->setName(name);
  }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1231 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (3)].functDecl);
    // TBD priority - jpcs
  }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1236 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (3)].functDecl);
    (yyval.functDecl)->setModeList((yyvsp[(3) - (3)].modeList));
  }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1241 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (3)].functDecl);
    (yyval.functDecl)->getSignature()->returnType = (yyvsp[(3) - (3)].sequenceType);
  }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1249 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
  }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1253 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyvsp[(1) - (2)].modeList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQUserFunction::Mode(uri, name)));
    (yyval.modeList) = (yyvsp[(1) - (2)].modeList);
  }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1259 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (2)].modeList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT)));
    (yyval.modeList) = (yyvsp[(1) - (2)].modeList);
  }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1264 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (2)].modeList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::ALL)));
    (yyval.modeList) = (yyvsp[(1) - (2)].modeList);
  }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1274 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (4)].functDecl)->getName() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:function declaration does not have a {}name attribute");
    }

    (yyvsp[(1) - (4)].functDecl)->getSignature()->argSpecs = (yyvsp[(2) - (4)].argSpecs);
    (yyvsp[(1) - (4)].functDecl)->setFunctionBody((yyvsp[(3) - (4)].parenExpr));
    QP->_query->addFunction((yyvsp[(1) - (4)].functDecl));
  }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1287 "../src/parser/XQParser.y"
    {    
    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction(0, signature, 0, true, MEMMGR));
  }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1292 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (2)].functDecl);
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyval.functDecl)->setURI(uri);
    (yyval.functDecl)->setName(name);
  }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1299 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (3)].functDecl);
    (yyval.functDecl)->getSignature()->returnType = (yyvsp[(3) - (3)].sequenceType);
  }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1304 "../src/parser/XQParser.y"
    {
    (yyval.functDecl) = (yyvsp[(1) - (2)].functDecl);
    // TBD override - jpcs
  }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1312 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = new (MEMMGR) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(MEMMGR));
  }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1316 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = (yyvsp[(1) - (2)].argSpecs);
    (yyval.argSpecs)->push_back((yyvsp[(2) - (2)].argSpec));
  }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1324 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (3)].argSpec);

    if((yyval.argSpec)->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:param instruction does not have a {}name attribute");
    }

    if((yyval.argSpec)->getType() == 0) {
      (yyval.argSpec)->setType(WRAP((yylsp[(1) - (3)]), new (MEMMGR) SequenceType(WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_ANYTHING)), SequenceType::STAR)));
    }

    // TBD default parameter values - jpcs

/*     if(!$2->getChildren().empty()) { */
/*       if($$->value != 0) { */
/*         yyerror(@1, "The xsl:with-param instruction has both a select attribute and a sequence constructor [err:XTSE0870]"); */
/*       } */
/*       $$->value = $2; */
/*     } */
/*     else if($$->value == 0) { */
/*       yyerror(@1, "The xsl:with-param instruction has neither a select attribute nor a sequence constructor [err:XTSE0870]"); */
/*     } */
  }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1351 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) ArgumentSpec(0, 0, MEMMGR));
  }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1355 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (2)].argSpec);
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyval.argSpec)->setURI(uri);
    (yyval.argSpec)->setName(name);
  }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1362 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (3)].argSpec);
    // TBD default parameter values - jpcs
/*     $$->value = PRESERVE_NS(@2, $3); */
  }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1368 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (3)].argSpec);
    (yyval.argSpec)->setType((yyvsp[(3) - (3)].sequenceType));
  }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1373 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (2)].argSpec);
    // TBD required - jpcs
  }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1378 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = (yyvsp[(1) - (2)].argSpec);
    // TBD tunnel parameters - jpcs
  }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1387 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].globalVar)->isRequired()) {
      if((yyvsp[(1) - (3)].globalVar)->getVariableExpr() != 0 || !(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
        yyerror((yylsp[(1) - (3)]), "A required xsl:param declaration must be empty and must not specify a {}select attribute");
      }
    }
    else {
      (yyvsp[(1) - (3)].globalVar)->setVariableExpr(XSLT_VARIABLE_VALUE((yylsp[(1) - (3)]), (ASTNode*)(yyvsp[(1) - (3)].globalVar)->getVariableExpr(), (yyvsp[(2) - (3)].parenExpr), (SequenceType*)(yyvsp[(1) - (3)].globalVar)->getSequenceType()));

      if((yyvsp[(1) - (3)].globalVar)->getVariableExpr() == 0) {
        yyerror((yylsp[(1) - (3)]), "The xsl:param declaration has both a select attribute and a sequence constructor [err:XTSE0620]");
      }
    }

    if((yyvsp[(1) - (3)].globalVar)->getVariableLocalName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:param declaration does not have a {}name attribute");
    }

    QP->_query->addVariable((yyvsp[(1) - (3)].globalVar));
  }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1411 "../src/parser/XQParser.y"
    {
    (yyval.globalVar) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQGlobalVariable(0, 0, 0, MEMMGR, /*isParam*/true));
  }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1415 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyvsp[(1) - (2)].globalVar)->setVariableURI(uri);
    (yyvsp[(1) - (2)].globalVar)->setVariableLocalName(name);
    (yyval.globalVar) = (yyvsp[(1) - (2)].globalVar);
  }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1422 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].globalVar)->setVariableExpr(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
    (yyval.globalVar) = (yyvsp[(1) - (3)].globalVar);
  }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1427 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].globalVar)->setSequenceType((yyvsp[(3) - (3)].sequenceType));
    (yyval.globalVar) = (yyvsp[(1) - (3)].globalVar);
  }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1432 "../src/parser/XQParser.y"
    {
    (yyval.globalVar) = (yyvsp[(1) - (2)].globalVar);
    (yyval.globalVar)->setRequired((yyvsp[(2) - (2)].boolean));
  }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1437 "../src/parser/XQParser.y"
    {
    (yyval.globalVar) = (yyvsp[(1) - (2)].globalVar);
    if((yyvsp[(2) - (2)].boolean)) {
      yyerror((yylsp[(2) - (2)]), "An xsl:param declaration cannot have a {}tunnel attribute with a value of \"yes\"");
    }
  }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1448 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].globalVar)->setVariableExpr(XSLT_VARIABLE_VALUE((yylsp[(1) - (3)]), (ASTNode*)(yyvsp[(1) - (3)].globalVar)->getVariableExpr(), (yyvsp[(2) - (3)].parenExpr), (SequenceType*)(yyvsp[(1) - (3)].globalVar)->getSequenceType()));
    (yyvsp[(1) - (3)].globalVar)->setSequenceType(0);

    if((yyvsp[(1) - (3)].globalVar)->getVariableExpr() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:variable declaration has both a select attribute and a sequence constructor [err:XTSE0620]");
    }

    if((yyvsp[(1) - (3)].globalVar)->getVariableLocalName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:variable declaration does not have a {}name attribute");
    }

    QP->_query->addVariable((yyvsp[(1) - (3)].globalVar));
  }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1466 "../src/parser/XQParser.y"
    {
    (yyval.globalVar) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQGlobalVariable(0, 0, 0, MEMMGR));
  }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1470 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyvsp[(1) - (2)].globalVar)->setVariableURI(uri);
    (yyvsp[(1) - (2)].globalVar)->setVariableLocalName(name);
    (yyval.globalVar) = (yyvsp[(1) - (2)].globalVar);
  }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1477 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].globalVar)->setVariableExpr(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
    (yyval.globalVar) = (yyvsp[(1) - (3)].globalVar);
  }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1482 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].globalVar)->setSequenceType((yyvsp[(3) - (3)].sequenceType));
    (yyval.globalVar) = (yyvsp[(1) - (3)].globalVar);
  }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1490 "../src/parser/XQParser.y"
    {
    // TBD Add the output to the static context - jpcs
  }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1515 "../src/parser/XQParser.y"
    {
  }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1518 "../src/parser/XQParser.y"
    {
  }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1521 "../src/parser/XQParser.y"
    {
  }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1524 "../src/parser/XQParser.y"
    {
  }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1527 "../src/parser/XQParser.y"
    {
  }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1530 "../src/parser/XQParser.y"
    {
  }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1533 "../src/parser/XQParser.y"
    {
  }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1536 "../src/parser/XQParser.y"
    {
  }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1539 "../src/parser/XQParser.y"
    {
  }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1542 "../src/parser/XQParser.y"
    {
  }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1545 "../src/parser/XQParser.y"
    {
  }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1548 "../src/parser/XQParser.y"
    {
  }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1551 "../src/parser/XQParser.y"
    {
  }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1554 "../src/parser/XQParser.y"
    {
  }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1557 "../src/parser/XQParser.y"
    {
  }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1560 "../src/parser/XQParser.y"
    {
  }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1563 "../src/parser/XQParser.y"
    {
  }
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1566 "../src/parser/XQParser.y"
    {
  }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1576 "../src/parser/XQParser.y"
    {
//     $$ = $1;
    const XMLCh *p = (yyvsp[(1) - (1)].str);
    while(*p && *p != ':') ++p;
    if(*p == 0) {
      yyerror((yylsp[(1) - (1)]), "The method for the xsl:output declaration does not have a prefix");
    }
  }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1588 "../src/parser/XQParser.y"
    {
  }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1591 "../src/parser/XQParser.y"
    {
  }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1597 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (2)].alias)->getName() == 0) {
      yyerror((yylsp[(1) - (2)]), "The xsl:type-alias declaration does not have a {}name attribute");
    }
    if((yyvsp[(1) - (2)].alias)->getType() == 0) {
      yyerror((yylsp[(1) - (2)]), "The xsl:type-alias declaration does not have an {}as attribute");
    }

    QP->_query->addTypeAlias((yyvsp[(1) - (2)].alias));
  }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1611 "../src/parser/XQParser.y"
    {
    (yyval.alias) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQTypeAlias(0, 0, MEMMGR));
  }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1615 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyvsp[(1) - (2)].alias)->setURI(uri);
    (yyvsp[(1) - (2)].alias)->setName(name);
    (yyval.alias) = (yyvsp[(1) - (2)].alias);
  }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1622 "../src/parser/XQParser.y"
    {
    (yyval.alias) = (yyvsp[(1) - (3)].alias);
    (yyval.alias)->setType((yyvsp[(3) - (3)].itemType));
  }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1632 "../src/parser/XQParser.y"
    {
    LOCATION((yylsp[(1) - (1)]), loc);
    CONTEXT->addSchemaLocation(XMLUni::fgZeroLenString, 0, &loc);
  }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1637 "../src/parser/XQParser.y"
    {
    LOCATION((yylsp[(1) - (2)]), loc);
    CONTEXT->addSchemaLocation((yyvsp[(2) - (2)].str), 0, &loc);
  }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1642 "../src/parser/XQParser.y"
    {
    VectorOfStrings schemaLoc(XQillaAllocator<const XMLCh*>(MEMMGR));
    schemaLoc.push_back((yyvsp[(2) - (2)].str));

    LOCATION((yylsp[(1) - (2)]), loc);
    CONTEXT->addSchemaLocation(XMLUni::fgZeroLenString, &schemaLoc, &loc);
  }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1650 "../src/parser/XQParser.y"
    {
    VectorOfStrings schemaLoc(XQillaAllocator<const XMLCh*>(MEMMGR));
    schemaLoc.push_back((yyvsp[(3) - (3)].str));

    LOCATION((yylsp[(1) - (3)]), loc);
    CONTEXT->addSchemaLocation((yyvsp[(2) - (3)].str), &schemaLoc, &loc);
  }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1658 "../src/parser/XQParser.y"
    {
    VectorOfStrings schemaLoc(XQillaAllocator<const XMLCh*>(MEMMGR));
    schemaLoc.push_back((yyvsp[(2) - (3)].str));

    LOCATION((yylsp[(1) - (3)]), loc);
    CONTEXT->addSchemaLocation((yyvsp[(3) - (3)].str), &schemaLoc, &loc);
  }
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1669 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    *children = (yyvsp[(3) - (4)].parenExpr)->getChildren();

    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQElementConstructor((yyvsp[(1) - (4)].astNode), (yyvsp[(2) - (4)].itemList), children, MEMMGR));
  }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1679 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR)); 
  }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1683 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (3)].itemList);

    ASTNode *attrItem = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQAttributeConstructor((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].itemList), MEMMGR));
    (yyval.itemList)->push_back(attrItem);
  }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1690 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->insert((yyval.itemList)->begin(), (yyvsp[(2) - (2)].astNode));
  }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1699 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1703 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(PRESERVE_NS((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].astNode)));
  }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1708 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1716 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = WRAP((yyloc), new (MEMMGR) XQSequence(MEMMGR));
  }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1720 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = (yyvsp[(1) - (2)].parenExpr);
    (yyval.parenExpr)->addItem(WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQTextConstructor((yyvsp[(2) - (2)].astNode), MEMMGR)));
  }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1725 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = (yyvsp[(1) - (2)].parenExpr);
    (yyval.parenExpr)->addItem((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1730 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = (yyvsp[(1) - (2)].parenExpr);
    (yyval.parenExpr)->addItem((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1759 "../src/parser/XQParser.y"
    {
    XQTextConstructor *text = (XQTextConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = text;

    if(!(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
      if(text->getValue() != 0) {
        yyerror((yylsp[(1) - (3)]), "The xsl:value-of instruction has both a select attribute and a sequence constructor [err:XTSE0870]");
      }
      text->setValue((yyvsp[(2) - (3)].parenExpr));
    }
    else if(text->getValue() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:value-of instruction has neither a select attribute nor a sequence constructor [err:XTSE0870]");
    }
  }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1777 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQTextConstructor(0, MEMMGR));
  }
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1781 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQTextConstructor*)(yyval.astNode))->setValue(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1786 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    // TBD separator - jpcs
/*     ((XQTextConstructor*)$$)->setValue(PRESERVE_NS(@2, $3)); */
  }
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1795 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQTextConstructor((yyvsp[(2) - (3)].astNode), MEMMGR));
  }
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1804 "../src/parser/XQParser.y"
    {
    // TBD xsl:sort - jpcs
    XQApplyTemplates *apply = (XQApplyTemplates*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = apply;

    apply->setArguments((yyvsp[(2) - (3)].templateArgs));

    if(apply->getExpression() == 0) {
      NodeTest *nt = new (MEMMGR) NodeTest();
      nt->setTypeWildcard();
      nt->setNameWildcard();
      nt->setNamespaceWildcard();

      apply->setExpression(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQStep(Node::CHILD, nt, MEMMGR)));
    }
  }
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1824 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQApplyTemplates(0, 0, 0, MEMMGR));
  }
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1828 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQApplyTemplates*)(yyval.astNode))->setExpression(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1833 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQApplyTemplates*)(yyval.astNode))->setMode((yyvsp[(3) - (3)].mode));
  }
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1841 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].str));
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(uri, name));
  }
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1846 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT));
  }
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1850 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::CURRENT));
  }
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1857 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = new (MEMMGR) TemplateArguments(XQillaAllocator<XQTemplateArgument*>(MEMMGR));
  }
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1861 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = (yyvsp[(1) - (2)].templateArgs);
    (yyval.templateArgs)->push_back((yyvsp[(2) - (2)].templateArg));
  }
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1869 "../src/parser/XQParser.y"
    {
    XQCallTemplate *call = (XQCallTemplate*)(yyvsp[(1) - (3)].astNode);
    call->setArguments((yyvsp[(2) - (3)].templateArgs));
    (yyval.astNode) = call;

    if(call->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:call-template instruction does not have a {}name attribute");
    }
  }
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1882 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQCallTemplate((const XMLCh*)0, 0, MEMMGR));
  }
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1886 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    ((XQCallTemplate*)(yyval.astNode))->setURI(uri);
    ((XQCallTemplate*)(yyval.astNode))->setName(name);
  }
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1896 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = new (MEMMGR) TemplateArguments(XQillaAllocator<XQTemplateArgument*>(MEMMGR));
  }
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1900 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = (yyvsp[(1) - (2)].templateArgs);
    (yyval.templateArgs)->push_back((yyvsp[(2) - (2)].templateArg));
  }
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1908 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = (yyvsp[(1) - (3)].templateArg);

    if((yyval.templateArg)->name == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:with-param instruction does not have a {}name attribute");
    }

    (yyvsp[(1) - (3)].templateArg)->value = XSLT_VARIABLE_VALUE((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].templateArg)->value, (yyvsp[(2) - (3)].parenExpr), (yyvsp[(1) - (3)].templateArg)->seqType);
    (yyvsp[(1) - (3)].templateArg)->seqType = 0;

    if((yyvsp[(1) - (3)].templateArg)->value == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:with-param instruction has both a select attribute and a sequence constructor [err:XTSE0870]");
    }
  }
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1926 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQTemplateArgument(0, 0, MEMMGR));
  }
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1930 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = (yyvsp[(1) - (2)].templateArg);
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyval.templateArg)->uri = uri;
    (yyval.templateArg)->name = name;
  }
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1937 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = (yyvsp[(1) - (3)].templateArg);
    (yyval.templateArg)->value = PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode));
  }
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1942 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = (yyvsp[(1) - (3)].templateArg);
    (yyval.templateArg)->seqType = (yyvsp[(3) - (3)].sequenceType);
  }
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1947 "../src/parser/XQParser.y"
    {
    (yyval.templateArg) = (yyvsp[(1) - (2)].templateArg);
    // TBD tunnel parameters - jpcs
  }
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1955 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
  }
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1961 "../src/parser/XQParser.y"
    {
    // TBD xsl:fallback - jpcs
    (yyval.astNode) = PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode));
  }
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1969 "../src/parser/XQParser.y"
    {
    ASTNode *empty = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQSequence(MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQIf((yyvsp[(1) - (3)].astNode), (yyvsp[(2) - (3)].parenExpr), empty, MEMMGR));
  }
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1977 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode));
  }
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1984 "../src/parser/XQParser.y"
    {
    XQIf *iff = (XQIf*)(yyvsp[(2) - (4)].astNode);
    while(iff->getWhenFalse() != 0) {
      iff = (XQIf*)iff->getWhenFalse();
    }

    iff->setWhenFalse((yyvsp[(3) - (4)].astNode));

    (yyval.astNode) = (yyvsp[(2) - (4)].astNode);
  }
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1998 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (1)].astNode);
  }
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 2002 "../src/parser/XQParser.y"
    {
    XQIf *iff = (XQIf*)(yyvsp[(1) - (2)].astNode);
    while(iff->getWhenFalse() != 0) {
      iff = (XQIf*)iff->getWhenFalse();
    }

    iff->setWhenFalse((yyvsp[(2) - (2)].astNode));

    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
  }
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 2016 "../src/parser/XQParser.y"
    {
    XQIf *iff = (XQIf*)(yyvsp[(1) - (3)].astNode);
    iff->setWhenTrue((yyvsp[(2) - (3)].parenExpr));
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
  }
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 2025 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQIf(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)), 0, 0, MEMMGR));
  }
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 2032 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yyloc), new (MEMMGR) XQSequence(MEMMGR));
  }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 2036 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].parenExpr);
  }
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 2043 "../src/parser/XQParser.y"
    {
    // TBD xsl:fallback - jpcs

    XQAnalyzeString *as = (XQAnalyzeString*)(yyval.astNode);
    (yyval.astNode) = (yyvsp[(1) - (4)].astNode);

    if(as->getExpression() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:analyze-string instruction does not have a {}select attribute");
    }

    if(as->getRegex() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:analyze-string instruction does not have a {}regex attribute");
    }

    if((yyvsp[(2) - (4)].astNode) == 0) {
      if((yyvsp[(3) - (4)].astNode) == 0) {
        yyerror((yylsp[(1) - (4)]), "The xsl:analyze-string instruction doesn't contain an xsl:matching-substring or xsl:non-matching-substring child [err:XTSE1130]");
      }

      as->setMatch(WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQSequence(MEMMGR)));
    }
    else {
      as->setMatch((yyvsp[(2) - (4)].astNode));
    }
    if((yyvsp[(3) - (4)].astNode) == 0) {
      as->setNonMatch(WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQSequence(MEMMGR)));
    }
    else {
      as->setNonMatch((yyvsp[(3) - (4)].astNode));
    }
  }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 2078 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yyloc), new (MEMMGR) XQAnalyzeString(MEMMGR));
  }
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 2082 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQAnalyzeString*)(yyval.astNode))->setExpression(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 2087 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQAnalyzeString*)(yyval.astNode))->setRegex(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 2093 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQAnalyzeString*)(yyval.astNode))->setFlags(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 2102 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = 0;
  }
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 2106 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].parenExpr);
  }
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 2113 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = 0;
  }
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 2117 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].parenExpr);
  }
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 2124 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (4)].letTuple)->setExpression(XSLT_VARIABLE_VALUE((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].letTuple)->getExpression(), (yyvsp[(2) - (4)].parenExpr), (yyvsp[(1) - (4)].letTuple)->getVar()->getType()));
    const_cast<ArgumentSpec*>((yyvsp[(1) - (4)].letTuple)->getVar())->setType(0);

    if((yyvsp[(1) - (4)].letTuple)->getExpression() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:variable instruction has both a select attribute and a sequence constructor [err:XTSE0620]");
    }

    if((yyvsp[(1) - (4)].letTuple)->getVarName() == 0) {
      yyerror((yylsp[(1) - (4)]), "The xsl:variable instruction does not have a {}name attribute");
    }

    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQReturn((yyvsp[(1) - (4)].letTuple), (yyvsp[(4) - (4)].parenExpr), MEMMGR));
  }
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 2142 "../src/parser/XQParser.y"
    {
    (yyval.letTuple) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) LetTuple(WRAP((yylsp[(1) - (1)]), new (MEMMGR) ContextTuple(MEMMGR)), (XMLCh*)0, 0, MEMMGR));
  }
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 2146 "../src/parser/XQParser.y"
    {
    RESOLVE_QNAME((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].str));
    (yyvsp[(1) - (2)].letTuple)->setVarURI(uri);
    (yyvsp[(1) - (2)].letTuple)->setVarName(name);
    (yyval.letTuple) = (yyvsp[(1) - (2)].letTuple);
  }
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 2153 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].letTuple)->setExpression((yyvsp[(3) - (3)].astNode));
    (yyval.letTuple) = (yyvsp[(1) - (3)].letTuple);
  }
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 2158 "../src/parser/XQParser.y"
    {
    const_cast<ArgumentSpec*>((yyvsp[(1) - (3)].letTuple)->getVar())->setType((yyvsp[(3) - (3)].sequenceType));
    (yyval.letTuple) = (yyvsp[(1) - (3)].letTuple);
  }
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 2166 "../src/parser/XQParser.y"
    {
    XQCommentConstructor *comment = (XQCommentConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = comment;

    if(!(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
      if(comment->getValue() != 0) {
        yyerror((yylsp[(1) - (3)]), "The xsl:comment instruction has both a select attribute and a sequence constructor [err:XTSE0940]");
      }
      comment->setValue((yyvsp[(2) - (3)].parenExpr));
    }
    else if(comment->getValue() == 0) {
      comment->setValue(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQSequence(MEMMGR)));
    }
  }
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 2184 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQCommentConstructor(0, MEMMGR, /*xslt*/true));
  }
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 2188 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQCommentConstructor*)(yyval.astNode))->setValue(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 2196 "../src/parser/XQParser.y"
    {
    XQPIConstructor *pi = (XQPIConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = pi;

    if(pi->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:processing-instruction instruction does not have a {}name attribute");
    }

    if(!(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
      if(pi->getValue() != 0) {
        yyerror((yylsp[(1) - (3)]), "The xsl:processing-instruction instruction has both a select attribute and a sequence constructor [err:XTSE0880]");
      }
      pi->setValue((yyvsp[(2) - (3)].parenExpr));
    }
    else if(pi->getValue() == 0) {
      pi->setValue(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQSequence(MEMMGR)));
    }
  }
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 2218 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQPIConstructor(0, 0, MEMMGR, /*xslt*/true));
  }
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 2222 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQPIConstructor*)(yyval.astNode))->setName(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 2229 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQPIConstructor*)(yyval.astNode))->setValue(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 2237 "../src/parser/XQParser.y"
    {
    XQDocumentConstructor *doc = (XQDocumentConstructor*)(yyvsp[(1) - (3)].astNode);
    doc->setValue((yyvsp[(2) - (3)].parenExpr));
    (yyval.astNode) = doc;
  }
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 2246 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQDocumentConstructor(0, MEMMGR));
  }
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 2254 "../src/parser/XQParser.y"
    {
    XQAttributeConstructor *attr = (XQAttributeConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = attr;

    if(attr->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:attribute instruction does not have a {}name attribute");
    }

    if(attr->namespaceExpr != 0) {
      // Use fn:QName() to assign the correct URI
      VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      args->push_back(attr->namespaceExpr);
      args->push_back(const_cast<ASTNode*>(attr->getName()));
      ASTNode *name = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
          MEMMGR->getPooledString("QName"), args, MEMMGR));
      attr->setName(name);
      attr->namespaceExpr = 0;
    }

    if(!(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
      if(attr->getChildren() != 0 && !attr->getChildren()->empty()) {
        yyerror((yylsp[(1) - (3)]), "The xsl:attribute instruction has both a select attribute and a sequence constructor [err:XTSE0840]");
      }

      VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      *children = (yyvsp[(2) - (3)].parenExpr)->getChildren();
      attr->setChildren(children);
    }
    else if(attr->getChildren() == 0) {
      VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      children->push_back(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQSequence(MEMMGR)));
      attr->setChildren(children);
    }
  }
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 2292 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQAttributeConstructor(0, 0, MEMMGR));
  }
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 2296 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQAttributeConstructor*)(yyval.astNode))->setName(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 2303 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQAttributeConstructor*)(yyval.astNode))->namespaceExpr = PRESERVE_NS((yylsp[(2) - (3)]), content);
  }
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 2310 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    children->push_back(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));

    ((XQAttributeConstructor*)(yyval.astNode))->setChildren(children);
  }
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 2319 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    // TBD separator - jpcs
/*     ((XQAttributeConstructor*)$$)->setChildren(children); */
  }
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 2328 "../src/parser/XQParser.y"
    {
    XQNamespaceConstructor *ns = (XQNamespaceConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = ns;

    if(ns->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:namespace instruction does not have a {}name attribute");
    }

    if(!(yyvsp[(2) - (3)].parenExpr)->getChildren().empty()) {
      if(ns->getChildren() != 0 && !ns->getChildren()->empty()) {
        yyerror((yylsp[(1) - (3)]), "The xsl:namespace instruction has both a select attribute and a sequence constructor [err:XTSE0840]");
      }

      VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      *children = (yyvsp[(2) - (3)].parenExpr)->getChildren();
      ns->setChildren(children);
    }
    else if(ns->getChildren() == 0) {
      VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      children->push_back(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQSequence(MEMMGR)));
      ns->setChildren(children);
    }
  }
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 2355 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQNamespaceConstructor(0, 0, MEMMGR));
  }
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 2359 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQNamespaceConstructor*)(yyval.astNode))->setName(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 2366 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    children->push_back(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));

    ((XQNamespaceConstructor*)(yyval.astNode))->setChildren(children);
  }
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 2378 "../src/parser/XQParser.y"
    {
    XQElementConstructor *elem = (XQElementConstructor*)(yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = elem;

    if(elem->getName() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:element instruction does not have a {}name attribute");
    }

    if(elem->namespaceExpr != 0) {
      // Use fn:QName() to assign the correct URI
      VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
      args->push_back(elem->namespaceExpr);
      args->push_back(const_cast<ASTNode*>(elem->getName()));
      ASTNode *name = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
          MEMMGR->getPooledString("QName"), args, MEMMGR));
      elem->setName(name);
      elem->namespaceExpr = 0;
    }

    VectorOfASTNodes *children = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    *children = (yyvsp[(2) - (3)].parenExpr)->getChildren();
    elem->setChildren(children);
  }
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 2405 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQElementConstructor(0, 0, 0, MEMMGR));
  }
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 2409 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQElementConstructor*)(yyval.astNode))->setName(PRESERVE_NS((yylsp[(2) - (3)]), content));
  }
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 2416 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);

    ASTNode *content = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQSimpleContent((yyvsp[(3) - (3)].itemList), MEMMGR));
    ((XQElementConstructor*)(yyval.astNode))->namespaceExpr = PRESERVE_NS((yylsp[(2) - (3)]), content);
  }
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 2426 "../src/parser/XQParser.y"
    {
    XQCopyOf *as = (XQCopyOf*)(yyval.astNode);
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);

    if(as->getExpression() == 0) {
      yyerror((yylsp[(1) - (2)]), "The xsl:copy-of instruction does not have a {}select attribute");
    }
  }
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 2438 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yyloc), new (MEMMGR) XQCopyOf(MEMMGR));
  }
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 2442 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQCopyOf*)(yyval.astNode))->setExpression(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 2447 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
    ((XQCopyOf*)(yyval.astNode))->setCopyNamespaces((yyvsp[(2) - (2)].boolean));
  }
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 2456 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    XQCopy *as = (XQCopy*)(yyval.astNode);

    XQContextItem *ci = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQContextItem(MEMMGR));
    as->setExpression(ci);

    as->setChildren((yyvsp[(2) - (3)].parenExpr)->getChildren());
  }
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 2469 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yyloc), new (MEMMGR) XQCopy(MEMMGR));
  }
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 2473 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
    ((XQCopy*)(yyval.astNode))->setCopyNamespaces((yyvsp[(2) - (2)].boolean));
  }
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 2478 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (2)].astNode);
    ((XQCopy*)(yyval.astNode))->setInheritNamespaces((yyvsp[(2) - (2)].boolean));
  }
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 2487 "../src/parser/XQParser.y"
    {
    // TBD xsl:sort - jpcs
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    XQMap *map = (XQMap*)(yyval.astNode);
    map->setArg2((yyvsp[(2) - (3)].parenExpr));

    if(map->getArg1() == 0) {
      yyerror((yylsp[(1) - (3)]), "The xsl:for-each instruction does not have a {}select attribute");
    }
  }
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 2501 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQMap(0, 0, MEMMGR));
  }
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 2505 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    ((XQMap*)(yyval.astNode))->setArg1(PRESERVE_NS((yylsp[(2) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 2518 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (3)].itemList);
    (yyval.itemList)->push_back(PRESERVE_NS((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 2523 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    (yyval.itemList)->push_back(PRESERVE_NS((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].astNode)));
  }
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 2535 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (1)].astNode);
  }
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 2539 "../src/parser/XQParser.y"
    {
    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setNodeType(Node::document_string);
    nt->setNameWildcard();
    nt->setNamespaceWildcard();
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(Node::SELF, nt, MEMMGR));
  }
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 2547 "../src/parser/XQParser.y"
    {
    // . intersect id("a")

    VectorOfASTNodes oargs(XQillaAllocator<ASTNode*>(MEMMGR));
    oargs.push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQContextItem(MEMMGR)));
    oargs.push_back((yyvsp[(1) - (1)].astNode));

    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) Intersect(oargs, MEMMGR));
  }
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 2560 "../src/parser/XQParser.y"
    {
    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setNodeType(Node::document_string);
    nt->setNameWildcard();
    nt->setNamespaceWildcard();
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(Node::PARENT, nt, MEMMGR));
  }
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 2568 "../src/parser/XQParser.y"
    {
    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setNodeType(Node::document_string);
    nt->setNameWildcard();
    nt->setNamespaceWildcard();
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(Node::ANCESTOR, nt, MEMMGR));
  }
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 2581 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes fargs(XQillaAllocator<ASTNode*>(MEMMGR));
    fargs.push_back((yyvsp[(3) - (4)].astNode));

    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) FunctionId(fargs, MEMMGR));
  }
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 2588 "../src/parser/XQParser.y"
    {
//     VectorOfASTNodes fargs(XQillaAllocator<ASTNode*>(MEMMGR));
//     fargs.push_back($3);
//     fargs.push_back($5);

//     $$ = WRAP(@1, new (MEMMGR) FunctionKey(fargs, MEMMGR));

    // TBD key() - jpcs
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) XQContextItem(MEMMGR));
  }
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 2627 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(1) - (1)].astNode);
  }
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 2631 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQPredicate((yyvsp[(2) - (2)].astNode), (yyvsp[(1) - (2)].astNode), MEMMGR));
  }
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 2635 "../src/parser/XQParser.y"
    {
    // id("a")/foo -> self::foo[parent::node() intersect id("a")]

    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setTypeWildcard();
    nt->setNameWildcard();
    nt->setNamespaceWildcard();
    XQStep *step = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQStep(Node::PARENT, nt, MEMMGR));

    VectorOfASTNodes oargs(XQillaAllocator<ASTNode*>(MEMMGR));
    oargs.push_back(step);
    oargs.push_back((yyvsp[(1) - (3)].astNode));

    Intersect *intersect = WRAP((yylsp[(1) - (3)]), new (MEMMGR) Intersect(oargs, MEMMGR));

    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQPredicate((yyvsp[(3) - (3)].astNode), intersect, MEMMGR));
  }
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 2653 "../src/parser/XQParser.y"
    {
    // id("a")/foo -> self::foo[ancestor::node() intersect id("a")]

    NodeTest *nt = new (MEMMGR) NodeTest();
    nt->setTypeWildcard();
    nt->setNameWildcard();
    nt->setNamespaceWildcard();
    XQStep *step = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQStep(Node::ANCESTOR, nt, MEMMGR));

    VectorOfASTNodes oargs(XQillaAllocator<ASTNode*>(MEMMGR));
    oargs.push_back(step);
    oargs.push_back((yyvsp[(1) - (3)].astNode));

    Intersect *intersect = WRAP((yylsp[(1) - (3)]), new (MEMMGR) Intersect(oargs, MEMMGR));

    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQPredicate((yyvsp[(3) - (3)].astNode), intersect, MEMMGR));
  }
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 2671 "../src/parser/XQParser.y"
    {
    ASTNode *step = (yyvsp[(1) - (3)].astNode);
    while(step->getType() == ASTNode::PREDICATE)
      step = (ASTNode*)((XQPredicate*)step)->getExpression();

    ((XQStep*)step)->setAxis(Node::PARENT);

    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQPredicate((yyvsp[(3) - (3)].astNode), (yyvsp[(1) - (3)].astNode), MEMMGR));
  }
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 2681 "../src/parser/XQParser.y"
    {
    ASTNode *step = (yyvsp[(1) - (3)].astNode);
    while(step->getType() == ASTNode::PREDICATE)
      step = (ASTNode*)((XQPredicate*)step)->getExpression();

    ((XQStep*)step)->setAxis(Node::ANCESTOR);

    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQPredicate((yyvsp[(3) - (3)].astNode), (yyvsp[(1) - (3)].astNode), MEMMGR));
  }
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 2695 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = XQPredicate::addPredicates(WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQStep(Node::SELF, (yyvsp[(1) - (2)].nodeTest), MEMMGR)), (yyvsp[(2) - (2)].predicates));
  }
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 2703 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(1) - (1)].nodeTest)->isNodeTypeSet())
      (yyvsp[(1) - (1)].nodeTest)->setNodeType(Node::element_string);
    (yyval.nodeTest) = (yyvsp[(1) - (1)].nodeTest);
  }
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 2709 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(3) - (3)].nodeTest)->isNodeTypeSet())
      (yyvsp[(3) - (3)].nodeTest)->setNodeType(Node::element_string);
    (yyval.nodeTest) = (yyvsp[(3) - (3)].nodeTest);
  }
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 2715 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(3) - (3)].nodeTest)->isNodeTypeSet())
      (yyvsp[(3) - (3)].nodeTest)->setNodeType(Node::attribute_string);
    (yyval.nodeTest) = (yyvsp[(3) - (3)].nodeTest);
  }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 2721 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(2) - (2)].nodeTest)->isNodeTypeSet())
      (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::attribute_string);
    (yyval.nodeTest) = (yyvsp[(2) - (2)].nodeTest);
  }
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 2732 "../src/parser/XQParser.y"
    {
    (yyval.predicates) = new (MEMMGR) VectorOfPredicates(MEMMGR);
  }
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 2736 "../src/parser/XQParser.y"
    {
    XQPredicate *pred = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPredicate((yyvsp[(3) - (4)].astNode), MEMMGR));
    (yyvsp[(1) - (4)].predicates)->push_back(pred);
    (yyval.predicates) = (yyvsp[(1) - (4)].predicates); 
  }
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 2764 "../src/parser/XQParser.y"
    {
    // TBD Set the language correctly on the context - jpcs
    if(XPath2Utils::equals((yyvsp[(2) - (2)].str),sz1_0)) {
      QP->_lexer->setVersion3(false);
      QP->_query->setVersion3(false);
    }
    else if(XPath2Utils::equals((yyvsp[(2) - (2)].str),sz3_0)) {
      if(!QP->_lexer->isVersion3()) {
        yyerror((yylsp[(1) - (2)]), "This XQuery processor is not configured to support XQuery 3.0 [err:XQST0031]");
      }
      QP->_lexer->setVersion3(true);
      QP->_query->setVersion3(true);
    }
    else
      yyerror((yylsp[(1) - (2)]), "This XQuery processor only supports version 1.0 and 3.0 [err:XQST0031]");
  }
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 2784 "../src/parser/XQParser.y"
    {
    XMLCh *encName = (yyvsp[(2) - (2)].str);
    if((*encName < chLatin_A || *encName > chLatin_Z) && (*encName < chLatin_a || *encName > chLatin_z))
      yyerror((yylsp[(1) - (2)]), "The specified encoding does not conform to the definition of EncName [err:XQST0087]");

    for(++encName; *encName; ++encName) {
      if((*encName < chLatin_A || *encName > chLatin_Z) &&
         (*encName < chLatin_a || *encName > chLatin_z) &&
         (*encName < chDigit_0 || *encName > chDigit_9) &&
         *encName != chPeriod && *encName != chDash)
        yyerror((yylsp[(1) - (2)]), "The specified encoding does not conform to the definition of EncName [err:XQST0087]");
    }
  }
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 2808 "../src/parser/XQParser.y"
    {
    if(*(yyvsp[(5) - (6)].str) == 0)
      yyerror((yylsp[(5) - (6)]), "The literal that specifies the namespace of a module must not be of zero length [err:XQST0088]");
    QP->_query->setIsLibraryModule();
    QP->_query->setModuleTargetNamespace((yyvsp[(5) - (6)].str));
    SET_NAMESPACE((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
  }
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 2822 "../src/parser/XQParser.y"
    {
    CHECK_SECOND_STEP((yylsp[(2) - (3)]), "a setter");
  }
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2826 "../src/parser/XQParser.y"
    {
    CHECK_SECOND_STEP((yylsp[(2) - (3)]), "an import");
  }
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2830 "../src/parser/XQParser.y"
    {
    CHECK_SECOND_STEP((yylsp[(2) - (3)]), "a namespace");
  }
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2834 "../src/parser/XQParser.y"
    {
    CHECK_SECOND_STEP((yylsp[(2) - (3)]), "a default namespace");
  }
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2838 "../src/parser/XQParser.y"
    {
    QP->_flags.set(BIT_DECLARE_SECOND_STEP);
  }
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2842 "../src/parser/XQParser.y"
    {
    QP->_flags.set(BIT_DECLARE_SECOND_STEP);
    XQUserFunction* decl=(yyvsp[(2) - (3)].functDecl);
    QP->_query->addFunction(decl);
  }
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2848 "../src/parser/XQParser.y"
    {
    QP->_flags.set(BIT_DECLARE_SECOND_STEP);
    XQUserFunction* decl=(yyvsp[(2) - (3)].functDecl);
    QP->_query->addFunction(decl);
  }
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2854 "../src/parser/XQParser.y"
    {
    QP->_flags.set(BIT_DECLARE_SECOND_STEP);
  }
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2858 "../src/parser/XQParser.y"
    {
    CHECK_SECOND_STEP((yylsp[(2) - (3)]), "an ftoption declaration");
  }
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2862 "../src/parser/XQParser.y"
    {
    QP->_flags.set(BIT_DECLARE_SECOND_STEP);
  }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2894 "../src/parser/XQParser.y"
    {
    SET_NAMESPACE((yylsp[(3) - (5)]), (yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].str));
  }
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2902 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_BOUNDARY_SPECIFIED, "boundary space", "XQST0068");
    CONTEXT->setPreserveBoundarySpace(true);
  }
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2907 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_BOUNDARY_SPECIFIED, "boundary space", "XQST0068");
    CONTEXT->setPreserveBoundarySpace(false);
  }
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 2916 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (5)]), BIT_DEFAULTELEMENTNAMESPACE_SPECIFIED, "default element namespace", "XQST0066");
    CONTEXT->setDefaultElementAndTypeNS((yyvsp[(5) - (5)].str));
  }
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2921 "../src/parser/XQParser.y"
    { 
    CHECK_SPECIFIED((yylsp[(1) - (5)]), BIT_DEFAULTFUNCTIONNAMESPACE_SPECIFIED, "default function namespace", "XQST0066");
    CONTEXT->setDefaultFuncNS((yyvsp[(5) - (5)].str));
  }
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 2930 "../src/parser/XQParser.y"
    {
    // validate the QName
    QualifiedName qName((yyvsp[(3) - (4)].str));
    const XMLCh* prefix = qName.getPrefix();
    if(prefix == 0 || *prefix == 0)
      yyerror((yylsp[(3) - (4)]), "The option name must have a prefix [err:XPST0081]");

    const XMLCh *uri = 0;
    try {
      LOCATION((yylsp[(3) - (4)]), loc);
      uri = CONTEXT->getUriBoundToPrefix(prefix, &loc);
    }
    catch(NamespaceLookupException&) {
      yyerror((yylsp[(3) - (4)]), "The option name is using an undefined namespace prefix [err:XPST0081]");
    }

    if(XPath2Utils::equals(uri, XQillaFunction::XMLChFunctionURI)) {
      if(XPath2Utils::equals(qName.getName(), option_projection)) {
        if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_TRUE)) {
          CONTEXT->setProjection(true);
        }
        else if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_FALSE)) {
          CONTEXT->setProjection(false);
        }
        else {
          yyerror((yylsp[(4) - (4)]), "Unknown value for option xqilla:projection. Should be 'true' or 'false' [err:XQILLA]");
        }
      }
      else if(XPath2Utils::equals(qName.getName(), option_psvi)) {
        if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_TRUE)) {
          CONTEXT->getDocumentCache()->setDoPSVI(true);
        }
        else if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_FALSE)) {
          CONTEXT->getDocumentCache()->setDoPSVI(false);
        }
        else {
          yyerror((yylsp[(4) - (4)]), "Unknown value for option xqilla:psvi. Should be 'true' or 'false' [err:XQILLA]");
        }
      }
      else if(XPath2Utils::equals(qName.getName(), option_lint)) {
        if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_TRUE)) {
          CONTEXT->setDoLintWarnings(true);
        }
        else if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_FALSE)) {
          CONTEXT->setDoLintWarnings(false);
        }
        else {
          yyerror((yylsp[(4) - (4)]), "Unknown value for option xqilla:lint. Should be 'true' or 'false' [err:XQILLA]");
        }
      }
      else if(XPath2Utils::equals(qName.getName(), option_extensions)) {
        if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_TRUE)) {
          QP->_lexer->setEnableExtensions(true);
        }
        else if(XPath2Utils::equals((yyvsp[(4) - (4)].str), SchemaSymbols::fgATTVAL_FALSE)) {
          QP->_lexer->setEnableExtensions(false);
        }
        else {
          yyerror((yylsp[(4) - (4)]), "Unknown value for option xqilla:extensions. Should be 'true' or 'false' [err:XQILLA]");
        }
      }
      else {
        yyerror((yylsp[(3) - (4)]), "Unknown option name in the xqilla namespace [err:XQILLA]");
      }
    }
    else if(XPath2Utils::equals(uri, XQRewriteRule::URI)) {
      if(XPath2Utils::equals(qName.getName(), option_rule)) {
        LOCATION((yylsp[(4) - (4)]), loc);
        loc.setLocationInfo(loc.getFile(), loc.getLine(), loc.getColumn() + 1);
        QP->_query->addRewriteRule(XQRewriteRule::parse((yyvsp[(4) - (4)].str), MEMMGR, &loc));
      }
      else {
        yyerror((yylsp[(3) - (4)]), "Unknown option name in the xqilla rewrite namespace [err:XQILLA]");
      }
    }
  }
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 3011 "../src/parser/XQParser.y"
    {
    // TBD FTOptionDecl
  }
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 3019 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_ORDERING_SPECIFIED, "ordering mode", "XQST0065");
    CONTEXT->setNodeSetOrdering(StaticContext::ORDERING_ORDERED);
  }
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 3024 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_ORDERING_SPECIFIED, "ordering mode", "XQST0065");
    CONTEXT->setNodeSetOrdering(StaticContext::ORDERING_UNORDERED);
  }
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 3033 "../src/parser/XQParser.y"
    { 
    CHECK_SPECIFIED((yylsp[(1) - (5)]), BIT_EMPTYORDERING_SPECIFIED, "empty ordering mode", "XQST0069");
    CONTEXT->setDefaultFLWOROrderingMode(StaticContext::FLWOR_ORDER_EMPTY_GREATEST);
  }
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 3038 "../src/parser/XQParser.y"
    { 
    CHECK_SPECIFIED((yylsp[(1) - (5)]), BIT_EMPTYORDERING_SPECIFIED, "empty ordering mode", "XQST0069");
    CONTEXT->setDefaultFLWOROrderingMode(StaticContext::FLWOR_ORDER_EMPTY_LEAST);
  }
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 3047 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (5)]), BIT_COPYNAMESPACE_SPECIFIED, "copy namespace", "XQST0055");
    CONTEXT->setPreserveNamespaces((yyvsp[(3) - (5)].boolean));
    CONTEXT->setInheritNamespaces((yyvsp[(5) - (5)].boolean));
  }
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 3057 "../src/parser/XQParser.y"
    {
    (yyval.boolean) = true;
  }
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 3061 "../src/parser/XQParser.y"
    {
    (yyval.boolean) = false;
  }
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 3069 "../src/parser/XQParser.y"
    {
    (yyval.boolean) = true;
  }
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 3073 "../src/parser/XQParser.y"
    {
    (yyval.boolean) = false;
  }
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 3081 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (4)]), BIT_COLLATION_SPECIFIED, "default collation", "XQST0038");
    try {
      LOCATION((yylsp[(4) - (4)]), loc);
      CONTEXT->getCollation((yyvsp[(4) - (4)].str), &loc);
    }
    catch(ContextException&) {
      yyerror((yylsp[(4) - (4)]), "The specified collation does not exist [err:XQST0038]");
    }
    CONTEXT->setDefaultCollation((yyvsp[(4) - (4)].str));
  }
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 3097 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_BASEURI_SPECIFIED, "base URI", "XQST0032");
    CONTEXT->setBaseURI((yyvsp[(3) - (3)].str));
  }
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 3106 "../src/parser/XQParser.y"
    {
    if(XPath2Utils::equals((yyvsp[(3) - (5)].str), XMLUni::fgZeroLenString))
      CONTEXT->setDefaultElementAndTypeNS((yyvsp[(4) - (5)].str));
    else if(XPath2Utils::equals((yyvsp[(4) - (5)].str), XMLUni::fgZeroLenString))
      yyerror((yylsp[(1) - (5)]), "A schema that has no target namespace cannot be bound to a non-empty prefix [err:XQST0057]");
    else {
      SET_NAMESPACE((yylsp[(3) - (5)]), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str));
    }
    LOCATION((yylsp[(1) - (5)]), loc);
    CONTEXT->addSchemaLocation((yyvsp[(4) - (5)].str), (yyvsp[(5) - (5)].stringList), &loc);
  }
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 3118 "../src/parser/XQParser.y"
    {
    LOCATION((yylsp[(1) - (4)]), loc);
    CONTEXT->addSchemaLocation((yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].stringList), &loc);
  }
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 3126 "../src/parser/XQParser.y"
    {
    (yyval.stringList) = NULL;
  }
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 3130 "../src/parser/XQParser.y"
    {
    (yyval.stringList) = new (MEMMGR) VectorOfStrings(XQillaAllocator<const XMLCh*>(MEMMGR));
    (yyval.stringList)->push_back((yyvsp[(2) - (2)].str));
  }
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 3135 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].stringList)->push_back((yyvsp[(3) - (3)].str));
    (yyval.stringList) = (yyvsp[(1) - (3)].stringList);
  }
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 3144 "../src/parser/XQParser.y"
    {
    (yyval.str) = (yyvsp[(2) - (3)].str);
  }
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 3148 "../src/parser/XQParser.y"
    {
    (yyval.str) = (XMLCh*)XMLUni::fgZeroLenString;
  }
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 3156 "../src/parser/XQParser.y"
    {
    if(XMLString::stringLen((yyvsp[(6) - (7)].str))==0)
      yyerror((yylsp[(6) - (7)]), "The literal that specifies the target namespace in a module import must not be of zero length [err:XQST0088]");

    SET_NAMESPACE((yylsp[(4) - (7)]), (yyvsp[(4) - (7)].str), (yyvsp[(6) - (7)].str));

    LOCATION((yylsp[(1) - (7)]), loc);
    QP->_query->importModule((yyvsp[(6) - (7)].str), (yyvsp[(7) - (7)].stringList), &loc);
  }
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 3166 "../src/parser/XQParser.y"
    {
    if(XMLString::stringLen((yyvsp[(3) - (4)].str))==0)
      yyerror((yylsp[(3) - (4)]), "The literal that specifies the target namespace in a module import must not be of zero length [err:XQST0088]");

    LOCATION((yylsp[(1) - (4)]), loc);
    QP->_query->importModule((yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].stringList), &loc);
  }
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 3178 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_CONSTRUCTION_SPECIFIED, "construction mode", "XQST0067");
    CONTEXT->setConstructionMode(StaticContext::CONSTRUCTION_MODE_PRESERVE);
  }
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 3183 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_CONSTRUCTION_SPECIFIED, "construction mode", "XQST0067");
    CONTEXT->setConstructionMode(StaticContext::CONSTRUCTION_MODE_STRIP);
  }
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 3192 "../src/parser/XQParser.y"
    {
    (yyval.signature) = new (MEMMGR) FunctionSignature(MEMMGR);
  }
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 3196 "../src/parser/XQParser.y"
    {
    (yyval.signature) = (yyvsp[(1) - (2)].signature);
    (yyval.signature)->annotations.push_back((yyvsp[(2) - (2)].annotation));
  }
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 3207 "../src/parser/XQParser.y"
    {
    ASTNode *trueExpr =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                           MEMMGR->getPooledString("true"), 0, MEMMGR));
    (yyval.annotation) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) Annotation(0, XQFunction::XMLChFunctionURI, (yyvsp[(1) - (1)].str), trueExpr, MEMMGR));
  }
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 3219 "../src/parser/XQParser.y"
    {
    QP->_query->addVariable(WRAP((yylsp[(1) - (7)]), new (MEMMGR) XQGlobalVariable((yyvsp[(5) - (7)].str), (yyvsp[(6) - (7)].sequenceType), (yyvsp[(7) - (7)].astNode), MEMMGR)));
  }
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 3226 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (2)].astNode);
  }
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 3230 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = NULL;
  }
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 3238 "../src/parser/XQParser.y"
    {
    (yyvsp[(2) - (7)].signature)->argSpecs = (yyvsp[(5) - (7)].argSpecs);
    (yyvsp[(2) - (7)].signature)->returnType = (yyvsp[(6) - (7)].sequenceType);
    (yyval.functDecl) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (7)].str), (yyvsp[(2) - (7)].signature), (yyvsp[(7) - (7)].astNode), true, MEMMGR));
  }
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 3247 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = NULL;
  }
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 3251 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = (yyvsp[(2) - (3)].argSpecs);
  }
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 3258 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = 0;
  }
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 3262 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = (yyvsp[(2) - (2)].sequenceType);
  }
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 3271 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = 0;
  }
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 3279 "../src/parser/XQParser.y"
    {
    ASTNode *trueExpr =
      WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                           MEMMGR->getPooledString("true"), 0, MEMMGR));
    (yyval.annotation) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) Annotation((yyvsp[(2) - (2)].str), trueExpr));
  }
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 3286 "../src/parser/XQParser.y"
    {
    (yyval.annotation) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) Annotation((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].parenExpr)));
  }
    break;

  case 358:

/* Line 1455 of yacc.c  */
#line 3293 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQSequence(MEMMGR));
    (yyval.parenExpr)->addItem((yyvsp[(1) - (1)].astNode));
  }
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 3298 "../src/parser/XQParser.y"
    {
    (yyval.parenExpr) = (yyvsp[(1) - (3)].parenExpr);
    (yyval.parenExpr)->addItem((yyvsp[(3) - (3)].astNode));
  }
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 3307 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].argSpecs)->push_back((yyvsp[(3) - (3)].argSpec));
    (yyval.argSpecs) = (yyvsp[(1) - (3)].argSpecs);
  }
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 3312 "../src/parser/XQParser.y"
    {
    ArgumentSpecs* paramList = new (MEMMGR) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(MEMMGR));
    paramList->push_back((yyvsp[(1) - (1)].argSpec));
    (yyval.argSpecs) = paramList;
  }
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 3322 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ArgumentSpec((yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].sequenceType), MEMMGR));
  }
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 3330 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
    }
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 3338 "../src/parser/XQParser.y"
    {
    if(QP->_lexer->isUpdate()) {
      QP->_query->setQueryBody(WRAP((yylsp[(1) - (1)]), new (MEMMGR) UApplyUpdates((yyvsp[(1) - (1)].astNode), MEMMGR)));
    }
    else {
      QP->_query->setQueryBody((yyvsp[(1) - (1)].astNode));
    }
  }
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 3351 "../src/parser/XQParser.y"
    {
      ASTNode* prevExpr=(yyvsp[(1) - (3)].astNode);
      if(prevExpr->getType()==ASTNode::SEQUENCE)
      {
        ((XQSequence *)prevExpr)->addItem((yyvsp[(3) - (3)].astNode));
        (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
      }
      else {
        XQSequence *dis = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQSequence(MEMMGR));
        dis->addItem((yyvsp[(1) - (3)].astNode));
        dis->addItem((yyvsp[(3) - (3)].astNode));
        (yyval.astNode) = dis;
      }
    }
    break;

  case 379:

/* Line 1455 of yacc.c  */
#line 3389 "../src/parser/XQParser.y"
    {
      // Add a ContextTuple at the start
      TupleNode *tuples = setLastAncestor((yyvsp[(1) - (3)].tupleNode), WRAP((yylsp[(1) - (3)]), new (MEMMGR) ContextTuple(MEMMGR)));

      // Check the correct clause order for XQuery 1.0
      // FLWORExpr ::= (ForClause |  LetClause)+ WhereClause? OrderByClause? "return" ExprSingle
      if(!QP->_lexer->isVersion3()) {
        const TupleNode *where = 0;
        const TupleNode *forlet = 0;
        const TupleNode *node = tuples;
        while(node) {
          switch(node->getType()) {
          case TupleNode::ORDER_BY:
            if(where)
              XQThrow3(StaticErrorException, X("XQParser"), X("Where clause after order by clause [err:XPST0003]"), where);
            else if(forlet)
              XQThrow3(StaticErrorException, X("XQParser"), X("For or let clause after order by clause [err:XPST0003]"), forlet);
            break;
          case TupleNode::WHERE:
            if(where)
              XQThrow3(StaticErrorException, X("XQParser"), X("Duplicate where clause [err:XPST0003]"), where);
            else if(forlet)
              XQThrow3(StaticErrorException, X("XQParser"), X("For or let clause after where clause [err:XPST0003]"), forlet);
            where = node;
            break;
          case TupleNode::FOR:
          case TupleNode::LET:
            forlet = node;
            break;
          default:
            break;
          }

          node = node->getParent();
        }
      }

      // Add the return expression
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQReturn(tuples, (yyvsp[(3) - (3)].astNode), MEMMGR));
    }
    break;

  case 381:

/* Line 1455 of yacc.c  */
#line 3434 "../src/parser/XQParser.y"
    {
    // Order by has a special check here, because a single OrderByClause can result
    // in multiple OrderByTuple objects.
    const TupleNode *node = (yyvsp[(1) - (2)].tupleNode);
    while(node) {
      if(node->getType() == TupleNode::ORDER_BY)
        XQThrow3(StaticErrorException, X("XQParser"), X("Duplicate order by clause [err:XPST0003]"), (yyvsp[(2) - (2)].tupleNode));
      node = node->getParent();
    }

    (yyval.tupleNode) = setLastAncestor((yyvsp[(2) - (2)].tupleNode), (yyvsp[(1) - (2)].tupleNode));
  }
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 3447 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = setLastAncestor((yyvsp[(2) - (2)].tupleNode), (yyvsp[(1) - (2)].tupleNode));
  }
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 3462 "../src/parser/XQParser.y"
    {
      (yyval.tupleNode) = (yyvsp[(2) - (2)].tupleNode);
    }
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 3469 "../src/parser/XQParser.y"
    {
      (yyval.tupleNode) = setLastAncestor((yyvsp[(3) - (3)].tupleNode), (yyvsp[(1) - (3)].tupleNode));
    }
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 3477 "../src/parser/XQParser.y"
    {
    // the SequenceType has been specified for each item of the sequence, but we can only apply to the
    // sequence itself, so allow it to match multiple matches
    (yyvsp[(3) - (7)].sequenceType)->setOccurrence(SequenceType::STAR);
    (yyval.tupleNode) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) ForTuple(0, (yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].str), WRAP((yylsp[(3) - (7)]), new (MEMMGR) XQTreatAs((yyvsp[(7) - (7)].astNode), (yyvsp[(3) - (7)].sequenceType), MEMMGR)), MEMMGR));
  }
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 3488 "../src/parser/XQParser.y"
    {
    (yyval.str) = NULL;
  }
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 3492 "../src/parser/XQParser.y"
    { 
    REJECT_NOT_XQUERY(PositionalVar, (yylsp[(1) - (3)]));

    (yyval.str) = (yyvsp[(3) - (3)].str); 
  }
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 3502 "../src/parser/XQParser.y"
    {
    (yyval.str) = NULL;
  }
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 3506 "../src/parser/XQParser.y"
    {
    (yyval.str) = (yyvsp[(3) - (3)].str);
  }
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 3516 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = (yyvsp[(2) - (2)].tupleNode);
  }
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 3523 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = setLastAncestor((yyvsp[(3) - (3)].tupleNode), (yyvsp[(1) - (3)].tupleNode));
  }
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 3531 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) LetTuple(0, (yyvsp[(2) - (5)].str), WRAP((yylsp[(3) - (5)]), new (MEMMGR) XQTreatAs((yyvsp[(5) - (5)].astNode), (yyvsp[(3) - (5)].sequenceType), MEMMGR)), MEMMGR));
  }
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 3535 "../src/parser/XQParser.y"
    {
    ASTNode *literal = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::INTEGER, X("0"), MEMMGR));
    (yyval.tupleNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) LetTuple(0, (yyvsp[(3) - (5)].str), literal, MEMMGR));
  }
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 3544 "../src/parser/XQParser.y"
    { 
    (yyval.tupleNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) WhereTuple(0, (yyvsp[(2) - (2)].astNode), MEMMGR));
  }
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 3552 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) CountTuple(0, (yyvsp[(3) - (3)].str), MEMMGR));
  }
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 3560 "../src/parser/XQParser.y"
    {
    ((OrderByTuple*)getLastAncestor((yyvsp[(3) - (3)].tupleNode)))->setUnstable();
    (yyval.tupleNode) = (yyvsp[(3) - (3)].tupleNode);
  }
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 3565 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = (yyvsp[(4) - (4)].tupleNode);
  }
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 3573 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = setLastAncestor((yyvsp[(1) - (3)].tupleNode), (yyvsp[(3) - (3)].tupleNode));
  }
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 3583 "../src/parser/XQParser.y"
    {
    LOCATION((yylsp[(1) - (3)]), loc);
    Collation *collation = CONTEXT->getDefaultCollation(&loc);
    
    (yyval.tupleNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) OrderByTuple(0, (yyvsp[(1) - (3)].astNode), OrderByTuple::STABLE | (yyvsp[(2) - (3)].orderByModifier) | (yyvsp[(3) - (3)].orderByModifier), collation, MEMMGR));
  }
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 3590 "../src/parser/XQParser.y"
    {
    try {
      LOCATION((yylsp[(4) - (5)]), loc);
      Collation *collation = CONTEXT->getCollation((yyvsp[(5) - (5)].str), &loc);

      (yyval.tupleNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) OrderByTuple(0, (yyvsp[(1) - (5)].astNode), OrderByTuple::STABLE | (yyvsp[(2) - (5)].orderByModifier) | (yyvsp[(3) - (5)].orderByModifier), collation, MEMMGR));
    }
    catch(ContextException&) {
      yyerror((yylsp[(4) - (5)]), "The specified collation does not exist [err:XQST0076]");
    }
  }
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 3605 "../src/parser/XQParser.y"
    {
    SequenceType *zero_or_one = WRAP((yylsp[(1) - (1)]), new (MEMMGR)
      SequenceType((ItemType*)&ItemType::ITEM, SequenceType::QUESTION_MARK));

    (yyval.astNode) = (yyvsp[(1) - (1)].astNode);
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQAtomize((yyval.astNode), MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQPromoteUntyped((yyval.astNode), (ItemType*)&ItemType::STRING, MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQTreatAs((yyval.astNode), zero_or_one, MEMMGR));
  }
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 3619 "../src/parser/XQParser.y"
    {
    (yyval.orderByModifier) = OrderByTuple::ASCENDING;
  }
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 3623 "../src/parser/XQParser.y"
    {
    (yyval.orderByModifier) = OrderByTuple::ASCENDING;
  }
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 3627 "../src/parser/XQParser.y"
    {
    (yyval.orderByModifier) = OrderByTuple::DESCENDING;
  }
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 3634 "../src/parser/XQParser.y"
    {
    switch(CONTEXT->getDefaultFLWOROrderingMode()) {
    case StaticContext::FLWOR_ORDER_EMPTY_LEAST:
      (yyval.orderByModifier) = OrderByTuple::EMPTY_LEAST; break;
    case StaticContext::FLWOR_ORDER_EMPTY_GREATEST:
      (yyval.orderByModifier) = OrderByTuple::EMPTY_GREATEST; break;
    }
  }
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 3643 "../src/parser/XQParser.y"
    {
    (yyval.orderByModifier) = OrderByTuple::EMPTY_GREATEST;
  }
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 3647 "../src/parser/XQParser.y"
    {
    (yyval.orderByModifier) = OrderByTuple::EMPTY_LEAST;
  }
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 3656 "../src/parser/XQParser.y"
    {
    // Add a ContextTuple at the start
    TupleNode *tmp = setLastAncestor((yyvsp[(2) - (4)].tupleNode), WRAP((yylsp[(1) - (4)]), new (MEMMGR) ContextTuple(MEMMGR)));

    // Add the return expression
    (yyval.astNode) = WRAP((yylsp[(3) - (4)]), new (MEMMGR) XQQuantified(XQQuantified::SOME, tmp, (yyvsp[(4) - (4)].astNode), MEMMGR));
  }
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 3664 "../src/parser/XQParser.y"
    {
    // Add a ContextTuple at the start
    TupleNode *tmp = setLastAncestor((yyvsp[(2) - (4)].tupleNode), WRAP((yylsp[(1) - (4)]), new (MEMMGR) ContextTuple(MEMMGR)));

    // Add the return expression
    (yyval.astNode) = WRAP((yylsp[(3) - (4)]), new (MEMMGR) XQQuantified(XQQuantified::EVERY, tmp, (yyvsp[(4) - (4)].astNode), MEMMGR));
  }
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 3675 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = setLastAncestor((yyvsp[(3) - (3)].tupleNode), (yyvsp[(1) - (3)].tupleNode));
  }
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 3683 "../src/parser/XQParser.y"
    {
    // the SequenceType has been specified for each item of the sequence, but we can only apply to the
    // sequence itself, so allow it to match multiple matches
    (yyvsp[(3) - (5)].sequenceType)->setOccurrence(SequenceType::STAR);
    (yyval.tupleNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) ForTuple(0, (yyvsp[(2) - (5)].str), 0, WRAP((yylsp[(3) - (5)]), new (MEMMGR) XQTreatAs((yyvsp[(5) - (5)].astNode), (yyvsp[(3) - (5)].sequenceType), MEMMGR)), MEMMGR));
  }
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 3694 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) XQTypeswitch( WRAP((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].astNode)), (yyvsp[(5) - (6)].caseClauses), (yyvsp[(6) - (6)].caseClause), MEMMGR));
  }
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 3701 "../src/parser/XQParser.y"
    {
    XQTypeswitch::Cases::iterator it = (yyvsp[(2) - (2)].caseClauses)->begin();
    for(; it != (yyvsp[(2) - (2)].caseClauses)->end(); ++it) {
      (yyvsp[(1) - (2)].caseClauses)->push_back(*it);
    }

    (yyval.caseClauses) = (yyvsp[(1) - (2)].caseClauses);
  }
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 3714 "../src/parser/XQParser.y"
    {
    (yyval.caseClause) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQTypeswitch::Case((yyvsp[(3) - (5)].str), NULL, (yyvsp[(5) - (5)].astNode)));
  }
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 3718 "../src/parser/XQParser.y"
    {
    (yyval.caseClause) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQTypeswitch::Case(NULL, NULL, (yyvsp[(3) - (3)].astNode)));
  }
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 3726 "../src/parser/XQParser.y"
    {
    // TBD Don't copy the expression when unions of SequenceTypes are implemented - jpcs
    XQTypeswitch::Cases::iterator it = (yyvsp[(1) - (3)].caseClauses)->begin();
    if(it != (yyvsp[(1) - (3)].caseClauses)->end()) {
      (*it)->setExpression((yyvsp[(3) - (3)].astNode));

      for(++it; it != (yyvsp[(1) - (3)].caseClauses)->end(); ++it) {
        (*it)->setExpression((yyvsp[(3) - (3)].astNode)->copy(CONTEXT));
      }
    }

    (yyval.caseClauses) = (yyvsp[(1) - (3)].caseClauses);
  }
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 3744 "../src/parser/XQParser.y"
    {
    (yyval.caseClauses) = new (MEMMGR) XQTypeswitch::Cases(XQillaAllocator<XQTypeswitch::Case*>(MEMMGR));
    (yyval.caseClauses)->push_back(WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQTypeswitch::Case((yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].sequenceType), 0)));
  }
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 3749 "../src/parser/XQParser.y"
    {
    REJECT_NOT_VERSION3(SequenceTypeUnion, (yylsp[(2) - (3)]));
    (yyvsp[(1) - (3)].caseClauses)->push_back(WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQTypeswitch::Case((yyvsp[(1) - (3)].caseClauses)->back()->getQName(), (yyvsp[(3) - (3)].sequenceType), 0)));
    (yyval.caseClauses) = (yyvsp[(1) - (3)].caseClauses);
  }
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 3758 "../src/parser/XQParser.y"
    {
    (yyval.str) = 0;
  }
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 3762 "../src/parser/XQParser.y"
    {
    (yyval.str) = (yyvsp[(2) - (3)].str);
  }
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 3770 "../src/parser/XQParser.y"
    { 
    (yyval.astNode) = WRAP((yylsp[(1) - (8)]), new (MEMMGR) XQIf((yyvsp[(3) - (8)].astNode), (yyvsp[(6) - (8)].astNode), (yyvsp[(8) - (8)].astNode), MEMMGR));
  }
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 3778 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].astNode)->getType() == ASTNode::OR) {
      ((Or*)(yyvsp[(1) - (3)].astNode))->addArgument((yyvsp[(3) - (3)].astNode));
      (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    }
    else
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Or(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR), MEMMGR));
  }
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 3792 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].astNode)->getType()==ASTNode::AND) {
      ((And*)(yyvsp[(1) - (3)].astNode))->addArgument((yyvsp[(3) - (3)].astNode));
      (yyval.astNode) = (yyvsp[(1) - (3)].astNode);
    }
    else
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) And(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR), MEMMGR));
  }
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 3811 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GeneralComp(GeneralComp::EQUAL,packageArgs((yyvsp[(1) - (3)].astNode),(yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 3815 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GeneralComp(GeneralComp::NOT_EQUAL,packageArgs((yyvsp[(1) - (3)].astNode),(yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 3818 "../src/parser/XQParser.y"
    { /* Careful! */ QP->_lexer->undoLessThan(); }
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 3819 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) GeneralComp(GeneralComp::LESS_THAN,packageArgs((yyvsp[(1) - (4)].astNode),(yyvsp[(4) - (4)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 3823 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GeneralComp(GeneralComp::LESS_THAN_EQUAL,packageArgs((yyvsp[(1) - (3)].astNode),(yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 3827 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GeneralComp(GeneralComp::GREATER_THAN,packageArgs((yyvsp[(1) - (3)].astNode),(yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 3831 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GeneralComp(GeneralComp::GREATER_THAN_EQUAL,packageArgs((yyvsp[(1) - (3)].astNode),(yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 443:

/* Line 1455 of yacc.c  */
#line 3835 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Equals(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 444:

/* Line 1455 of yacc.c  */
#line 3839 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) NotEquals(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 3843 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) LessThan(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 3847 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) LessThanEqual(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 3851 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GreaterThan(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 3855 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) GreaterThanEqual(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 3859 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) NodeComparison(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR), MEMMGR));
  }
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 3863 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) OrderComparison(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR), true, MEMMGR));
  }
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 3867 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) OrderComparison(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR), false,MEMMGR));
  }
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 3876 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) FTContains((yyvsp[(1) - (4)].astNode), (yyvsp[(4) - (4)].ftselection), NULL, MEMMGR));
  }
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 3880 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (5)]), new (MEMMGR) FTContains((yyvsp[(1) - (5)].astNode), (yyvsp[(4) - (5)].ftselection), (yyvsp[(5) - (5)].astNode), MEMMGR));
  }
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 3888 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    args->push_back((yyvsp[(1) - (3)].astNode));
    args->push_back((yyvsp[(3) - (3)].astNode));
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQFunctionCall(0, BuiltInModules::fn.uri, MEMMGR->getPooledString("concat"), args, MEMMGR));
  }
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 3900 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    args->push_back((yyvsp[(1) - (3)].astNode));
    args->push_back((yyvsp[(3) - (3)].astNode));
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQFunctionCall(0, BuiltInModules::core.uri, MEMMGR->getPooledString("to"), args, MEMMGR));
  }
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 3912 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Plus(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 3916 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Minus(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 3925 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Multiply(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 3929 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Divide(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 3933 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) IntegerDivide(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 3937 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Mod(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
  }
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 3946 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Union(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
    }
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 3950 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Union(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
    }
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 3959 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Intersect(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
    }
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 3963 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) Except(packageArgs((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR),MEMMGR));
    }
    break;

  case 474:

/* Line 1455 of yacc.c  */
#line 3972 "../src/parser/XQParser.y"
    {
    ASTNode *falseExpr =
      WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                           MEMMGR->getPooledString("false"), 0, MEMMGR));
    XQTypeswitch::Case *defcase =
      WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQTypeswitch::Case(NULL, NULL, falseExpr));

    ASTNode *trueExpr =
      WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
                                           MEMMGR->getPooledString("true"), 0, MEMMGR));
    XQTypeswitch::Cases *cases = new (MEMMGR)
      XQTypeswitch::Cases(XQillaAllocator<XQTypeswitch::Case*>(MEMMGR));
    cases->push_back(WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQTypeswitch::Case(NULL, (yyvsp[(4) - (4)].sequenceType), trueExpr)));

    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQTypeswitch((yyvsp[(1) - (4)].astNode), cases, defcase, MEMMGR));
  }
    break;

  case 476:

/* Line 1455 of yacc.c  */
#line 3994 "../src/parser/XQParser.y"
    {
    XQTreatAs* treatAs = new (MEMMGR) XQTreatAs((yyvsp[(1) - (4)].astNode),(yyvsp[(4) - (4)].sequenceType),MEMMGR, XQTreatAs::err_XPDY0050);
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), treatAs);
  }
    break;

  case 478:

/* Line 1455 of yacc.c  */
#line 4004 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQCastableAs((yyvsp[(1) - (4)].astNode),(yyvsp[(4) - (4)].sequenceType),MEMMGR));
  }
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 4013 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQCastAs((yyvsp[(1) - (4)].astNode),(yyvsp[(4) - (4)].sequenceType),MEMMGR));
  }
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 4022 "../src/parser/XQParser.y"
    {
      VectorOfASTNodes args(XQillaAllocator<ASTNode*>(MEMMGR));
      args.push_back((yyvsp[(2) - (2)].astNode));
      (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) UnaryMinus(/*positive*/false, args, MEMMGR));
    }
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 4028 "../src/parser/XQParser.y"
    {
      VectorOfASTNodes args(XQillaAllocator<ASTNode*>(MEMMGR));
      args.push_back((yyvsp[(2) - (2)].astNode));
      (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) UnaryMinus(/*positive*/true, args, MEMMGR));
    }
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 4049 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQValidate((yyvsp[(3) - (4)].astNode),DocumentCache::VALIDATION_STRICT,MEMMGR));
    }
    break;

  case 489:

/* Line 1455 of yacc.c  */
#line 4053 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQValidate((yyvsp[(4) - (5)].astNode),DocumentCache::VALIDATION_LAX,MEMMGR));
    }
    break;

  case 490:

/* Line 1455 of yacc.c  */
#line 4057 "../src/parser/XQParser.y"
    {
      (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQValidate((yyvsp[(4) - (5)].astNode),DocumentCache::VALIDATION_STRICT,MEMMGR));
    }
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 4065 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(ExtensionExpr, (yylsp[(1) - (3)]));

    // we don't support any pragma
    yyerror((yylsp[(1) - (3)]), "This pragma is not recognized, and no alternative expression is specified [err:XQST0079]");
  }
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 4072 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(ExtensionExpr, (yylsp[(1) - (4)]));

    // we don't support any pragma
    (yyval.astNode) = (yyvsp[(3) - (4)].astNode);
  }
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 4085 "../src/parser/XQParser.y"
    {
        // validate the QName
        QualifiedName qName((yyvsp[(3) - (4)].str));
        const XMLCh* prefix=qName.getPrefix();
        if(prefix == NULL || *prefix == 0)
          yyerror((yylsp[(3) - (4)]), "The pragma name must have a prefix [err:XPST0081]");

        try {
          LOCATION((yylsp[(3) - (4)]), loc);
          CONTEXT->getUriBoundToPrefix(prefix, &loc);
        }
        catch(NamespaceLookupException&) {
          yyerror((yylsp[(3) - (4)]), "The pragma name is using an undefined namespace prefix [err:XPST0081]");
        }
      }
    break;

  case 497:

/* Line 1455 of yacc.c  */
#line 4106 "../src/parser/XQParser.y"
    {
    (yyval.str) = (yyvsp[(2) - (2)].str);
  }
    break;

  case 499:

/* Line 1455 of yacc.c  */
#line 4115 "../src/parser/XQParser.y"
    {
    XQNav *nav = GET_NAVIGATION((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].astNode));
    nav->addStep((yyvsp[(2) - (2)].astNode));
    (yyval.astNode) = nav;
  }
    break;

  case 500:

/* Line 1455 of yacc.c  */
#line 4121 "../src/parser/XQParser.y"
    {
    XQNav *nav = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQNav(MEMMGR));

    VectorOfASTNodes args(XQillaAllocator<ASTNode*>(MEMMGR));
    FunctionRoot *root = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FunctionRoot(args, MEMMGR));

    SequenceType *documentNode = WRAP((yylsp[(1) - (2)]), new (MEMMGR)
      SequenceType(WRAP((yylsp[(1) - (2)]), new (MEMMGR) ItemType(ItemType::TEST_DOCUMENT))));

    nav->addStep(WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQTreatAs(root, documentNode, MEMMGR)));

    NodeTest *step = new (MEMMGR) NodeTest();
    step->setTypeWildcard();
    step->setNameWildcard();
    step->setNamespaceWildcard();
    nav->addStep(WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQStep(Node::DESCENDANT_OR_SELF, step, MEMMGR)));

    nav->addStep((yyvsp[(2) - (2)].astNode));
    (yyval.astNode) = nav;
  }
    break;

  case 502:

/* Line 1455 of yacc.c  */
#line 4146 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes args(XQillaAllocator<ASTNode*>(MEMMGR));
    FunctionRoot *root = WRAP((yylsp[(1) - (1)]), new (MEMMGR) FunctionRoot(args, MEMMGR));

    SequenceType *documentNode = WRAP((yylsp[(1) - (1)]), new (MEMMGR)
      SequenceType(WRAP((yylsp[(1) - (1)]), new (MEMMGR) ItemType(ItemType::TEST_DOCUMENT))));

    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQTreatAs(root, documentNode, MEMMGR));
  }
    break;

  case 503:

/* Line 1455 of yacc.c  */
#line 4160 "../src/parser/XQParser.y"
    {
    XQNav *nav = GET_NAVIGATION((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].astNode));
    nav->addStep((yyvsp[(3) - (3)].astNode));
    (yyval.astNode) = nav;
  }
    break;

  case 504:

/* Line 1455 of yacc.c  */
#line 4166 "../src/parser/XQParser.y"
    {
    XQNav *nav = GET_NAVIGATION((yylsp[(1) - (3)]), (yyvsp[(1) - (3)].astNode));

    NodeTest *step = new (MEMMGR) NodeTest();
    step->setTypeWildcard();
    step->setNameWildcard();
    step->setNamespaceWildcard();
    nav->addStep(WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQStep(Node::DESCENDANT_OR_SELF, step, MEMMGR)));
    nav->addStep((yyvsp[(3) - (3)].astNode));

    (yyval.astNode) = nav;
  }
    break;

  case 505:

/* Line 1455 of yacc.c  */
#line 4179 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQMap((yyvsp[(1) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR));
  }
    break;

  case 510:

/* Line 1455 of yacc.c  */
#line 4192 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQDocumentOrder((yyvsp[(1) - (1)].astNode), MEMMGR));
  }
    break;

  case 512:

/* Line 1455 of yacc.c  */
#line 4202 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPredicate((yyvsp[(1) - (4)].astNode), (yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 514:

/* Line 1455 of yacc.c  */
#line 4209 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPredicate((yyvsp[(1) - (4)].astNode), (yyvsp[(3) - (4)].astNode), /*reverse*/true, MEMMGR));
  }
    break;

  case 515:

/* Line 1455 of yacc.c  */
#line 4218 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(2) - (2)].nodeTest)->isNodeTypeSet()) {
      switch((yyvsp[(1) - (2)].axis)) {
      case Node::NAMESPACE: (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::namespace_string); break;
      case Node::ATTRIBUTE: (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::attribute_string); break;
      default: (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::element_string); break;
      }
    }

    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQStep((yyvsp[(1) - (2)].axis),(yyvsp[(2) - (2)].nodeTest),MEMMGR));
  }
    break;

  case 517:

/* Line 1455 of yacc.c  */
#line 4241 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::CHILD;
  }
    break;

  case 518:

/* Line 1455 of yacc.c  */
#line 4245 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::DESCENDANT;
  }
    break;

  case 519:

/* Line 1455 of yacc.c  */
#line 4249 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::ATTRIBUTE;
  }
    break;

  case 520:

/* Line 1455 of yacc.c  */
#line 4253 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::SELF;
  }
    break;

  case 521:

/* Line 1455 of yacc.c  */
#line 4257 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::DESCENDANT_OR_SELF;
  }
    break;

  case 522:

/* Line 1455 of yacc.c  */
#line 4261 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::FOLLOWING_SIBLING;
  }
    break;

  case 523:

/* Line 1455 of yacc.c  */
#line 4265 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::FOLLOWING;
  }
    break;

  case 524:

/* Line 1455 of yacc.c  */
#line 4269 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::NAMESPACE;
  }
    break;

  case 525:

/* Line 1455 of yacc.c  */
#line 4277 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(2) - (2)].nodeTest)->isNodeTypeSet()) {
      (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::attribute_string);
    }

    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQStep(Node::ATTRIBUTE, (yyvsp[(2) - (2)].nodeTest), MEMMGR));
  }
    break;

  case 526:

/* Line 1455 of yacc.c  */
#line 4285 "../src/parser/XQParser.y"
    {
    Node::Axis axis = Node::CHILD;
    ItemType *itemtype = (yyvsp[(1) - (1)].nodeTest)->getItemType();
    if(itemtype != 0 && itemtype->getItemTestType() == ItemType::TEST_ATTRIBUTE) {
      axis = Node::ATTRIBUTE;
    }
    else if(!(yyvsp[(1) - (1)].nodeTest)->isNodeTypeSet()) {
      (yyvsp[(1) - (1)].nodeTest)->setNodeType(Node::element_string);
    }

    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(axis, (yyvsp[(1) - (1)].nodeTest), MEMMGR));
  }
    break;

  case 527:

/* Line 1455 of yacc.c  */
#line 4302 "../src/parser/XQParser.y"
    {
    if(!(yyvsp[(2) - (2)].nodeTest)->isNodeTypeSet()) {
      (yyvsp[(2) - (2)].nodeTest)->setNodeType(Node::element_string);
    }

    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQStep((yyvsp[(1) - (2)].axis), (yyvsp[(2) - (2)].nodeTest), MEMMGR));
  }
    break;

  case 529:

/* Line 1455 of yacc.c  */
#line 4319 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::PARENT;
  }
    break;

  case 530:

/* Line 1455 of yacc.c  */
#line 4323 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::ANCESTOR;
  }
    break;

  case 531:

/* Line 1455 of yacc.c  */
#line 4327 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::PRECEDING_SIBLING;
  }
    break;

  case 532:

/* Line 1455 of yacc.c  */
#line 4331 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::PRECEDING;
  }
    break;

  case 533:

/* Line 1455 of yacc.c  */
#line 4335 "../src/parser/XQParser.y"
    {
    (yyval.axis) = Node::ANCESTOR_OR_SELF;
  }
    break;

  case 534:

/* Line 1455 of yacc.c  */
#line 4343 "../src/parser/XQParser.y"
    {
    NodeTest *step = new (MEMMGR) NodeTest();
    step->setNameWildcard();
    step->setNamespaceWildcard();
    step->setTypeWildcard();
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQStep(Node::PARENT, step, MEMMGR));
  }
    break;

  case 535:

/* Line 1455 of yacc.c  */
#line 4355 "../src/parser/XQParser.y"
    {
    (yyval.nodeTest) = new (MEMMGR) NodeTest();
    (yyval.nodeTest)->setItemType((yyvsp[(1) - (1)].itemType));
  }
    break;

  case 537:

/* Line 1455 of yacc.c  */
#line 4365 "../src/parser/XQParser.y"
    {
    NodeTest *step = new (MEMMGR) NodeTest();
    step->setNodePrefix((yyvsp[(1) - (1)].qName)->getPrefix());
    step->setNodeName((yyvsp[(1) - (1)].qName)->getName());
    (yyval.nodeTest) = step;
  }
    break;

  case 539:

/* Line 1455 of yacc.c  */
#line 4377 "../src/parser/XQParser.y"
    {
    NodeTest *step = new (MEMMGR) NodeTest();
    step->setNameWildcard();
    step->setNamespaceWildcard();
    (yyval.nodeTest) = step;
  }
    break;

  case 540:

/* Line 1455 of yacc.c  */
#line 4384 "../src/parser/XQParser.y"
    {
    NodeTest *step = new (MEMMGR) NodeTest();
    step->setNodePrefix((yyvsp[(1) - (1)].str));
    step->setNameWildcard();
    (yyval.nodeTest) = step;
  }
    break;

  case 541:

/* Line 1455 of yacc.c  */
#line 4391 "../src/parser/XQParser.y"
    {
    NodeTest *step = new (MEMMGR) NodeTest();
    step->setNodeName((yyvsp[(1) - (1)].str));
    step->setNamespaceWildcard();
    (yyval.nodeTest) = step;
  }
    break;

  case 543:

/* Line 1455 of yacc.c  */
#line 4404 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPredicate((yyvsp[(1) - (4)].astNode), (yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 4433 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQVariable((yyvsp[(2) - (2)].str), MEMMGR));
  }
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 4444 "../src/parser/XQParser.y"
    { 
    (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
  }
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 4448 "../src/parser/XQParser.y"
    { 
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQSequence(MEMMGR));
  }
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 4456 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQContextItem(MEMMGR));
  }
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 4464 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(OrderedExpr, (yylsp[(1) - (4)]));

    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQOrderingChange(StaticContext::ORDERING_ORDERED, (yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 4474 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(UnorderedExpr, (yylsp[(1) - (4)]));

    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQOrderingChange(StaticContext::ORDERING_UNORDERED, (yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 4484 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionCall((yyvsp[(1) - (3)].str), NULL, MEMMGR));
  }
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 4488 "../src/parser/XQParser.y"
    {
    bool partial = false;
    VectorOfASTNodes::iterator i;
    for(i = (yyvsp[(3) - (4)].itemList)->begin(); i != (yyvsp[(3) - (4)].itemList)->end(); ++i) {
      if(*i == 0) {
        partial = true;
        break;
      }
    }

    if(partial) {
      // This is a partial function application
      XQFunctionRef *ref = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQFunctionRef((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].itemList)->size(), MEMMGR));
      (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPartialApply(ref, (yyvsp[(3) - (4)].itemList), MEMMGR));
    }
    else {
      (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQFunctionCall((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].itemList), MEMMGR));
    }
  }
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 4511 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].itemList)->push_back((yyvsp[(3) - (3)].astNode));
    (yyval.itemList) = (yyvsp[(1) - (3)].itemList);
  }
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 4516 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    (yyval.itemList)->push_back((yyvsp[(1) - (1)].astNode));
  }
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 4527 "../src/parser/XQParser.y"
    {
    REJECT_NOT_VERSION3(Argument, (yylsp[(1) - (1)]));
    (yyval.astNode) = 0;
  }
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 4536 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(Constructor, (yylsp[(1) - (1)]));
  }
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 4540 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(Constructor, (yylsp[(1) - (1)]));
  }
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 4553 "../src/parser/XQParser.y"
    { 
    VectorOfASTNodes* content = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    ASTNode *name = WRAP((yylsp[(2) - (5)]), new (MEMMGR) XQDirectName((yyvsp[(2) - (5)].str), /*useDefaultNamespace*/true, MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQElementConstructor(name, (yyvsp[(3) - (5)].itemList), content, MEMMGR));
  }
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 4559 "../src/parser/XQParser.y"
    { 
    if(!XPath2Utils::equals((yyvsp[(2) - (10)].str), (yyvsp[(8) - (10)].str)))
      yyerror((yylsp[(7) - (10)]), "Close tag does not match open tag");
    ASTNode *name = WRAP((yylsp[(2) - (10)]), new (MEMMGR) XQDirectName((yyvsp[(2) - (10)].str), /*useDefaultNamespace*/true, MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (10)]), new (MEMMGR) XQElementConstructor(name, (yyvsp[(3) - (10)].itemList), (yyvsp[(6) - (10)].itemList), MEMMGR));
  }
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 4572 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 4576 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (7)].itemList);

    ASTNode *name = WRAP((yylsp[(3) - (7)]), new (MEMMGR) XQDirectName((yyvsp[(3) - (7)].str), /*useDefaultNamespace*/false, MEMMGR));
    ASTNode *attrItem = WRAP((yylsp[(3) - (7)]), new (MEMMGR) XQAttributeConstructor(name, (yyvsp[(7) - (7)].itemList),MEMMGR));

    (yyval.itemList)->push_back(attrItem);
  }
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 4585 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (7)].itemList);

    ASTNode *name = WRAP((yylsp[(3) - (7)]), new (MEMMGR) XQDirectName((yyvsp[(3) - (7)].str), /*useDefaultNamespace*/false, MEMMGR));
    ASTNode *attrItem = WRAP((yylsp[(3) - (7)]), new (MEMMGR) XQAttributeConstructor(name, (yyvsp[(7) - (7)].itemList),MEMMGR));

    (yyval.itemList)->insert((yyval.itemList)->begin(), attrItem);
  }
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 4601 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = (yyvsp[(2) - (3)].itemList);
  }
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 4605 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = (yyvsp[(2) - (3)].itemList);
  }
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 4612 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = (yyvsp[(2) - (3)].itemList);
  }
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 4616 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = (yyvsp[(2) - (3)].itemList);
  }
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 4626 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 4630 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 4635 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 4643 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 4647 "../src/parser/XQParser.y"
    {
    yyerror((yylsp[(2) - (2)]), "Namespace URI of a namespace declaration must be a literal [err:XQST0022]");
  }
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 4651 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 4662 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 4666 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 4671 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 4679 "../src/parser/XQParser.y"
    { 
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 4683 "../src/parser/XQParser.y"
    {
    yyerror((yylsp[(2) - (2)]), "Namespace URI of a namespace declaration must be a literal [err:XQST0022]");
  }
    break;

  case 601:

/* Line 1455 of yacc.c  */
#line 4687 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 602:

/* Line 1455 of yacc.c  */
#line 4702 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR)); 
  }
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 4706 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 4711 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back((yyvsp[(2) - (2)].astNode));
  }
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 4716 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
  }
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 4721 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = (yyvsp[(1) - (2)].itemList);
    if(CONTEXT->getPreserveBoundarySpace()) {
      (yyval.itemList)->push_back(WRAP((yylsp[(2) - (2)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (2)].str), MEMMGR)));
    }
  }
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 4732 "../src/parser/XQParser.y"
    {
    ASTNode *value = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (3)].str), MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQCommentConstructor(value, MEMMGR));
  }
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 4741 "../src/parser/XQParser.y"
    {
    (yyval.str) = (XMLCh*)XMLUni::fgZeroLenString;
  }
    break;

  case 610:

/* Line 1455 of yacc.c  */
#line 4750 "../src/parser/XQParser.y"
    {
    ASTNode *value = WRAP((yylsp[(3) - (3)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(3) - (3)].str), MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQPIConstructor(WRAP((yylsp[(2) - (3)]), new (MEMMGR)
          XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(2) - (3)].str), MEMMGR)), value, MEMMGR));
  }
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 4761 "../src/parser/XQParser.y"
    {
    (yyval.str) = (yyvsp[(2) - (2)].str);
  }
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 4786 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQDocumentConstructor((yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 4794 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes* empty = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQElementConstructor((yyvsp[(2) - (3)].astNode), empty, (yyvsp[(3) - (3)].itemList), MEMMGR));
  }
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 4802 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQDirectName((yyvsp[(1) - (1)].str), /*useDefaultNamespace*/true, MEMMGR));
  }
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 4806 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
  }
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 4814 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
  }
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 4818 "../src/parser/XQParser.y"
    {
    (yyval.itemList) = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    (yyval.itemList)->push_back((yyvsp[(2) - (3)].astNode));
  }
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 4827 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQAttributeConstructor((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].itemList), MEMMGR));
  }
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 4834 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQDirectName((yyvsp[(1) - (1)].str), /*useDefaultNamespace*/false, MEMMGR));
  }
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 4838 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
  }
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 4848 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQNamespaceConstructor((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].itemList), MEMMGR));
  }
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 4856 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQTextConstructor((yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 631:

/* Line 1455 of yacc.c  */
#line 4864 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQCommentConstructor((yyvsp[(3) - (4)].astNode), MEMMGR));
  }
    break;

  case 632:

/* Line 1455 of yacc.c  */
#line 4872 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQPIConstructor((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].astNode), MEMMGR));
  }
    break;

  case 633:

/* Line 1455 of yacc.c  */
#line 4879 "../src/parser/XQParser.y"
    {
    // Check for a colon
    for(XMLCh *tmp = (yyvsp[(1) - (1)].str); *tmp; ++tmp)
      if(*tmp == ':') yyerror((yylsp[(1) - (1)]), "Expecting an NCName, found a QName");

    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 634:

/* Line 1455 of yacc.c  */
#line 4887 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
  }
    break;

  case 635:

/* Line 1455 of yacc.c  */
#line 4894 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQSequence(MEMMGR));
  }
    break;

  case 636:

/* Line 1455 of yacc.c  */
#line 4898 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (3)].astNode);
  }
    break;

  case 637:

/* Line 1455 of yacc.c  */
#line 4906 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) SequenceType((yyvsp[(1) - (2)].itemType), (yyvsp[(2) - (2)].occurrence)));
  }
    break;

  case 638:

/* Line 1455 of yacc.c  */
#line 4913 "../src/parser/XQParser.y"
    {
    (yyval.occurrence) = SequenceType::EXACTLY_ONE;
  }
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 4917 "../src/parser/XQParser.y"
    {
    (yyval.occurrence) = SequenceType::QUESTION_MARK;
  }
    break;

  case 640:

/* Line 1455 of yacc.c  */
#line 4925 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = WRAP((yyloc), new (MEMMGR) SequenceType(WRAP((yyloc), new (MEMMGR) ItemType(ItemType::TEST_ANYTHING)), SequenceType::STAR));
  }
    break;

  case 641:

/* Line 1455 of yacc.c  */
#line 4929 "../src/parser/XQParser.y"
    {
    REJECT_NOT_XQUERY(TypeDeclaration, (yylsp[(1) - (2)]));

    (yyval.sequenceType) = (yyvsp[(2) - (2)].sequenceType);
  }
    break;

  case 642:

/* Line 1455 of yacc.c  */
#line 4939 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) SequenceType((yyvsp[(1) - (2)].itemType), (yyvsp[(2) - (2)].occurrence)));
  }
    break;

  case 643:

/* Line 1455 of yacc.c  */
#line 4943 "../src/parser/XQParser.y"
    { 
    (yyval.sequenceType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) SequenceType()); 
  }
    break;

  case 644:

/* Line 1455 of yacc.c  */
#line 4952 "../src/parser/XQParser.y"
    { (yyval.occurrence) = SequenceType::EXACTLY_ONE; }
    break;

  case 645:

/* Line 1455 of yacc.c  */
#line 4954 "../src/parser/XQParser.y"
    { (yyval.occurrence) = SequenceType::STAR; }
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 4956 "../src/parser/XQParser.y"
    { (yyval.occurrence) = SequenceType::PLUS; }
    break;

  case 647:

/* Line 1455 of yacc.c  */
#line 4958 "../src/parser/XQParser.y"
    { (yyval.occurrence) = SequenceType::QUESTION_MARK; }
    break;

  case 648:

/* Line 1455 of yacc.c  */
#line 4964 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_ANYTHING));
  }
    break;

  case 653:

/* Line 1455 of yacc.c  */
#line 4976 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) ItemType(ItemType::TEST_ATOMIC_TYPE, NULL, (yyvsp[(1) - (1)].qName)));
  }
    break;

  case 664:

/* Line 1455 of yacc.c  */
#line 5006 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_NODE));
  }
    break;

  case 665:

/* Line 1455 of yacc.c  */
#line 5014 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_DOCUMENT));
  }
    break;

  case 666:

/* Line 1455 of yacc.c  */
#line 5018 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = (yyvsp[(3) - (4)].itemType);
    (yyval.itemType)->setItemTestType(ItemType::TEST_DOCUMENT);
    LOCATION((yylsp[(1) - (4)]), loc);
    (yyval.itemType)->setLocationInfo(&loc);
  }
    break;

  case 667:

/* Line 1455 of yacc.c  */
#line 5025 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = (yyvsp[(3) - (4)].itemType);
    (yyval.itemType)->setItemTestType(ItemType::TEST_SCHEMA_DOCUMENT);
    LOCATION((yylsp[(1) - (4)]), loc);
    (yyval.itemType)->setLocationInfo(&loc);
  }
    break;

  case 668:

/* Line 1455 of yacc.c  */
#line 5036 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_TEXT));
  }
    break;

  case 669:

/* Line 1455 of yacc.c  */
#line 5044 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_COMMENT));
  }
    break;

  case 670:

/* Line 1455 of yacc.c  */
#line 5052 "../src/parser/XQParser.y"
    {
    REJECT_NOT_VERSION3(NamespaceNodeTest, (yylsp[(1) - (3)]));
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_NAMESPACE));
  }
    break;

  case 671:

/* Line 1455 of yacc.c  */
#line 5061 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_PI));
  }
    break;

  case 672:

/* Line 1455 of yacc.c  */
#line 5065 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_PI, new (MEMMGR) QualifiedName((yyvsp[(3) - (4)].str), MEMMGR)));
  }
    break;

  case 673:

/* Line 1455 of yacc.c  */
#line 5069 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_PI, new (MEMMGR) QualifiedName((yyvsp[(3) - (4)].str), MEMMGR)));
  }
    break;

  case 674:

/* Line 1455 of yacc.c  */
#line 5077 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_ATTRIBUTE));
  }
    break;

  case 675:

/* Line 1455 of yacc.c  */
#line 5081 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_ATTRIBUTE,(yyvsp[(3) - (4)].qName)));
  }
    break;

  case 676:

/* Line 1455 of yacc.c  */
#line 5085 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) ItemType(ItemType::TEST_ATTRIBUTE,(yyvsp[(3) - (6)].qName),(yyvsp[(5) - (6)].qName)));
  }
    break;

  case 678:

/* Line 1455 of yacc.c  */
#line 5094 "../src/parser/XQParser.y"
    {
    (yyval.qName) = NULL;
  }
    break;

  case 679:

/* Line 1455 of yacc.c  */
#line 5102 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_SCHEMA_ATTRIBUTE,(yyvsp[(3) - (4)].qName)));
  }
    break;

  case 681:

/* Line 1455 of yacc.c  */
#line 5115 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_ELEMENT));
  }
    break;

  case 682:

/* Line 1455 of yacc.c  */
#line 5119 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_ELEMENT,(yyvsp[(3) - (4)].qName)));
  }
    break;

  case 683:

/* Line 1455 of yacc.c  */
#line 5123 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) ItemType(ItemType::TEST_ELEMENT,(yyvsp[(3) - (6)].qName),(yyvsp[(5) - (6)].qName)));
  }
    break;

  case 684:

/* Line 1455 of yacc.c  */
#line 5127 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) ItemType(ItemType::TEST_ELEMENT,(yyvsp[(3) - (7)].qName),(yyvsp[(5) - (7)].qName)));
    (yyval.itemType)->setAllowNilled(true);
  }
    break;

  case 686:

/* Line 1455 of yacc.c  */
#line 5137 "../src/parser/XQParser.y"
    {
    (yyval.qName) = NULL;
  }
    break;

  case 687:

/* Line 1455 of yacc.c  */
#line 5145 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType(ItemType::TEST_SCHEMA_ELEMENT,(yyvsp[(3) - (4)].qName)));
  }
    break;

  case 692:

/* Line 1455 of yacc.c  */
#line 5165 "../src/parser/XQParser.y"
    {
    // the string must be whitespace-normalized
    XMLString::collapseWS((yyvsp[(1) - (1)].str), MEMMGR);
    if((yyvsp[(1) - (1)].str) && *(yyvsp[(1) - (1)].str) && !XPath2Utils::isValidURI((yyvsp[(1) - (1)].str), MEMMGR))
      yyerror((yylsp[(1) - (1)]), "The URI literal is not valid [err:XQST0046]");
    (yyval.str) = (yyvsp[(1) - (1)].str);
  }
    break;

  case 693:

/* Line 1455 of yacc.c  */
#line 5177 "../src/parser/XQParser.y"
    {
    // TBD weight
    (yyval.ftselection) = (yyvsp[(1) - (3)].ftselection);

    for(VectorOfFTOptions::iterator i = (yyvsp[(2) - (3)].ftoptionlist)->begin();
        i != (yyvsp[(2) - (3)].ftoptionlist)->end(); ++i) {
      (*i)->setArgument((yyval.ftselection));
      (yyval.ftselection) = *i;
    }
/*     delete $2; */
  }
    break;

  case 694:

/* Line 1455 of yacc.c  */
#line 5192 "../src/parser/XQParser.y"
    {
}
    break;

  case 695:

/* Line 1455 of yacc.c  */
#line 5195 "../src/parser/XQParser.y"
    {
}
    break;

  case 696:

/* Line 1455 of yacc.c  */
#line 5201 "../src/parser/XQParser.y"
    {
  (yyval.ftoptionlist) = new (MEMMGR) VectorOfFTOptions(XQillaAllocator<FTOption*>(MEMMGR));
}
    break;

  case 697:

/* Line 1455 of yacc.c  */
#line 5205 "../src/parser/XQParser.y"
    {
  if((yyvsp[(2) - (2)].ftoption) != NULL) (yyvsp[(1) - (2)].ftoptionlist)->push_back((yyvsp[(2) - (2)].ftoption));
  (yyval.ftoptionlist) = (yyvsp[(1) - (2)].ftoptionlist);
}
    break;

  case 698:

/* Line 1455 of yacc.c  */
#line 5215 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].ftselection)->getType() == FTSelection::OR) {
      FTOr *op = (FTOr*)(yyvsp[(1) - (3)].ftselection);
      op->addArg((yyvsp[(3) - (3)].ftselection));
      (yyval.ftselection) = op;
    }
    else {
      (yyval.ftselection) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) FTOr((yyvsp[(1) - (3)].ftselection), (yyvsp[(3) - (3)].ftselection), MEMMGR));
    }
  }
    break;

  case 700:

/* Line 1455 of yacc.c  */
#line 5232 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].ftselection)->getType() == FTSelection::AND) {
      FTAnd *op = (FTAnd*)(yyvsp[(1) - (3)].ftselection);
      op->addArg((yyvsp[(3) - (3)].ftselection));
      (yyval.ftselection) = op;
    }
    else {
      (yyval.ftselection) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) FTAnd((yyvsp[(1) - (3)].ftselection), (yyvsp[(3) - (3)].ftselection), MEMMGR));
    }
  }
    break;

  case 702:

/* Line 1455 of yacc.c  */
#line 5248 "../src/parser/XQParser.y"
    {
    (yyval.ftselection) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) FTMildnot((yyvsp[(1) - (4)].ftselection), (yyvsp[(4) - (4)].ftselection), MEMMGR));
  }
    break;

  case 704:

/* Line 1455 of yacc.c  */
#line 5258 "../src/parser/XQParser.y"
    {
    (yyval.ftselection) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTUnaryNot((yyvsp[(2) - (2)].ftselection), MEMMGR));
  }
    break;

  case 707:

/* Line 1455 of yacc.c  */
#line 5268 "../src/parser/XQParser.y"
    {
  // TBD match options
  (yyval.ftselection) = (yyvsp[(1) - (2)].ftselection);
}
    break;

  case 708:

/* Line 1455 of yacc.c  */
#line 5277 "../src/parser/XQParser.y"
    {
  // TBD FTTimes
  (yyval.ftselection) = (yyvsp[(1) - (2)].ftselection);
}
    break;

  case 709:

/* Line 1455 of yacc.c  */
#line 5282 "../src/parser/XQParser.y"
    {
  (yyval.ftselection) = (yyvsp[(2) - (3)].ftselection);
}
    break;

  case 711:

/* Line 1455 of yacc.c  */
#line 5292 "../src/parser/XQParser.y"
    {
    (yyval.ftselection) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTWords((yyvsp[(1) - (2)].astNode), (yyvsp[(2) - (2)].ftanyalloption), MEMMGR));
  }
    break;

  case 712:

/* Line 1455 of yacc.c  */
#line 5296 "../src/parser/XQParser.y"
    {
    (yyval.ftselection) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) FTWords((yyvsp[(2) - (4)].astNode), (yyvsp[(4) - (4)].ftanyalloption), MEMMGR));
  }
    break;

  case 713:

/* Line 1455 of yacc.c  */
#line 5304 "../src/parser/XQParser.y"
    {
  // we don't support any pragma
  yyerror((yylsp[(1) - (3)]), "This pragma is not recognized, and no alternative expression is specified [err:XQST0079]");
}
    break;

  case 714:

/* Line 1455 of yacc.c  */
#line 5309 "../src/parser/XQParser.y"
    {
  // we don't support any pragma
  (yyval.ftselection) = (yyvsp[(3) - (4)].ftselection);
}
    break;

  case 715:

/* Line 1455 of yacc.c  */
#line 5318 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::ANY;
  }
    break;

  case 716:

/* Line 1455 of yacc.c  */
#line 5322 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::ANY;
  }
    break;

  case 717:

/* Line 1455 of yacc.c  */
#line 5326 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::ANY_WORD;
  }
    break;

  case 718:

/* Line 1455 of yacc.c  */
#line 5330 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::ALL;
  }
    break;

  case 719:

/* Line 1455 of yacc.c  */
#line 5334 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::ALL_WORDS;
  }
    break;

  case 720:

/* Line 1455 of yacc.c  */
#line 5338 "../src/parser/XQParser.y"
    {
    (yyval.ftanyalloption) = FTWords::PHRASE;
  }
    break;

  case 722:

/* Line 1455 of yacc.c  */
#line 5348 "../src/parser/XQParser.y"
    {
  yyerror((yylsp[(1) - (3)]), "The FTTimes operator is not supported. [err:FTST0005]");
}
    break;

  case 723:

/* Line 1455 of yacc.c  */
#line 5359 "../src/parser/XQParser.y"
    {
    (yyval.ftrange).type = FTRange::EXACTLY;
    (yyval.ftrange).arg1 = (yyvsp[(2) - (2)].astNode);
    (yyval.ftrange).arg2 = 0;
  }
    break;

  case 724:

/* Line 1455 of yacc.c  */
#line 5365 "../src/parser/XQParser.y"
    {
    (yyval.ftrange).type = FTRange::AT_LEAST;
    (yyval.ftrange).arg1 = (yyvsp[(3) - (3)].astNode);
    (yyval.ftrange).arg2 = 0;
  }
    break;

  case 725:

/* Line 1455 of yacc.c  */
#line 5371 "../src/parser/XQParser.y"
    {
    (yyval.ftrange).type = FTRange::AT_MOST;
    (yyval.ftrange).arg1 = (yyvsp[(3) - (3)].astNode);
    (yyval.ftrange).arg2 = 0;
  }
    break;

  case 726:

/* Line 1455 of yacc.c  */
#line 5377 "../src/parser/XQParser.y"
    {
    (yyval.ftrange).type = FTRange::FROM_TO;
    (yyval.ftrange).arg1 = (yyvsp[(2) - (4)].astNode);
    (yyval.ftrange).arg2 = (yyvsp[(4) - (4)].astNode);
  }
    break;

  case 727:

/* Line 1455 of yacc.c  */
#line 5392 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) FTOrder(MEMMGR));
  }
    break;

  case 728:

/* Line 1455 of yacc.c  */
#line 5396 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) FTWindow((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].ftunit), MEMMGR));
  }
    break;

  case 729:

/* Line 1455 of yacc.c  */
#line 5400 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) FTDistance((yyvsp[(2) - (3)].ftrange), (yyvsp[(3) - (3)].ftunit), MEMMGR));
  }
    break;

  case 730:

/* Line 1455 of yacc.c  */
#line 5404 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTScope(FTScope::SAME, (yyvsp[(2) - (2)].ftunit), MEMMGR));
  }
    break;

  case 731:

/* Line 1455 of yacc.c  */
#line 5408 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTScope(FTScope::DIFFERENT, (yyvsp[(2) - (2)].ftunit), MEMMGR));
  }
    break;

  case 732:

/* Line 1455 of yacc.c  */
#line 5412 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTContent(FTContent::AT_START, MEMMGR));
  }
    break;

  case 733:

/* Line 1455 of yacc.c  */
#line 5416 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTContent(FTContent::AT_END, MEMMGR));
  }
    break;

  case 734:

/* Line 1455 of yacc.c  */
#line 5420 "../src/parser/XQParser.y"
    {
    (yyval.ftoption) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) FTContent(FTContent::ENTIRE_CONTENT, MEMMGR));
  }
    break;

  case 735:

/* Line 1455 of yacc.c  */
#line 5428 "../src/parser/XQParser.y"
    {
    (yyval.ftunit) = FTOption::WORDS;
  }
    break;

  case 736:

/* Line 1455 of yacc.c  */
#line 5432 "../src/parser/XQParser.y"
    {
    (yyval.ftunit) = FTOption::SENTENCES;
  }
    break;

  case 737:

/* Line 1455 of yacc.c  */
#line 5436 "../src/parser/XQParser.y"
    {
    (yyval.ftunit) = FTOption::PARAGRAPHS;
  }
    break;

  case 738:

/* Line 1455 of yacc.c  */
#line 5444 "../src/parser/XQParser.y"
    {
    (yyval.ftunit) = FTOption::SENTENCES;
  }
    break;

  case 739:

/* Line 1455 of yacc.c  */
#line 5448 "../src/parser/XQParser.y"
    {
    (yyval.ftunit) = FTOption::PARAGRAPHS;
  }
    break;

  case 750:

/* Line 1455 of yacc.c  */
#line 5484 "../src/parser/XQParser.y"
    {
    CONTEXT->setFTCase(StaticContext::CASE_INSENSITIVE);
  }
    break;

  case 751:

/* Line 1455 of yacc.c  */
#line 5488 "../src/parser/XQParser.y"
    {
    CONTEXT->setFTCase(StaticContext::CASE_SENSITIVE);
  }
    break;

  case 752:

/* Line 1455 of yacc.c  */
#line 5492 "../src/parser/XQParser.y"
    {
    CONTEXT->setFTCase(StaticContext::LOWERCASE);
  }
    break;

  case 753:

/* Line 1455 of yacc.c  */
#line 5496 "../src/parser/XQParser.y"
    {
    CONTEXT->setFTCase(StaticContext::UPPERCASE);
  }
    break;

  case 754:

/* Line 1455 of yacc.c  */
#line 5505 "../src/parser/XQParser.y"
    {
    std::cerr << "diacritics insensitive" << std::endl;
  }
    break;

  case 755:

/* Line 1455 of yacc.c  */
#line 5509 "../src/parser/XQParser.y"
    {
    std::cerr << "diacritics sensitive" << std::endl;
  }
    break;

  case 756:

/* Line 1455 of yacc.c  */
#line 5517 "../src/parser/XQParser.y"
    {
    std::cerr << "using stemming" << std::endl;
  }
    break;

  case 757:

/* Line 1455 of yacc.c  */
#line 5521 "../src/parser/XQParser.y"
    {
    std::cerr << "no stemming" << std::endl;
  }
    break;

  case 758:

/* Line 1455 of yacc.c  */
#line 5531 "../src/parser/XQParser.y"
    {
    std::cerr << "using thesaurus" << std::endl;
  }
    break;

  case 759:

/* Line 1455 of yacc.c  */
#line 5535 "../src/parser/XQParser.y"
    {
    std::cerr << "using thesaurus default" << std::endl;
  }
    break;

  case 760:

/* Line 1455 of yacc.c  */
#line 5539 "../src/parser/XQParser.y"
    {
    std::cerr << "using thesaurus ()" << std::endl;
  }
    break;

  case 761:

/* Line 1455 of yacc.c  */
#line 5543 "../src/parser/XQParser.y"
    {
    std::cerr << "using thesaurus (default)" << std::endl;
  }
    break;

  case 762:

/* Line 1455 of yacc.c  */
#line 5547 "../src/parser/XQParser.y"
    {
    std::cerr << "no thesaurus" << std::endl;
  }
    break;

  case 763:

/* Line 1455 of yacc.c  */
#line 5554 "../src/parser/XQParser.y"
    {
  }
    break;

  case 764:

/* Line 1455 of yacc.c  */
#line 5557 "../src/parser/XQParser.y"
    {
  }
    break;

  case 765:

/* Line 1455 of yacc.c  */
#line 5564 "../src/parser/XQParser.y"
    {
    std::cerr << "at StringLiteral" << std::endl;
  }
    break;

  case 766:

/* Line 1455 of yacc.c  */
#line 5568 "../src/parser/XQParser.y"
    {
    std::cerr << "at StringLiteral relationship StringLiteral" << std::endl;
  }
    break;

  case 767:

/* Line 1455 of yacc.c  */
#line 5572 "../src/parser/XQParser.y"
    {
    std::cerr << "at StringLiteral levels" << std::endl;
  }
    break;

  case 768:

/* Line 1455 of yacc.c  */
#line 5576 "../src/parser/XQParser.y"
    {
    std::cerr << "at StringLiteral relationship StringLiteral levels" << std::endl;
  }
    break;

  case 769:

/* Line 1455 of yacc.c  */
#line 5586 "../src/parser/XQParser.y"
    {
    yyerror((yylsp[(1) - (4)]), "FTStopWordOption is not supported. [err:FTST0006]");
  }
    break;

  case 770:

/* Line 1455 of yacc.c  */
#line 5590 "../src/parser/XQParser.y"
    {
    yyerror((yylsp[(1) - (3)]), "FTStopWordOption is not supported. [err:FTST0006]");
  }
    break;

  case 771:

/* Line 1455 of yacc.c  */
#line 5594 "../src/parser/XQParser.y"
    {
    yyerror((yylsp[(1) - (4)]), "FTStopWordOption is not supported. [err:FTST0006]");
  }
    break;

  case 772:

/* Line 1455 of yacc.c  */
#line 5601 "../src/parser/XQParser.y"
    {
  }
    break;

  case 773:

/* Line 1455 of yacc.c  */
#line 5604 "../src/parser/XQParser.y"
    {
  }
    break;

  case 774:

/* Line 1455 of yacc.c  */
#line 5612 "../src/parser/XQParser.y"
    {
    std::cerr << "at URILiteral" << std::endl;
  }
    break;

  case 775:

/* Line 1455 of yacc.c  */
#line 5616 "../src/parser/XQParser.y"
    {
    std::cerr << "()" << std::endl;
  }
    break;

  case 776:

/* Line 1455 of yacc.c  */
#line 5623 "../src/parser/XQParser.y"
    {
    std::cerr << "StringLiteral" << std::endl;
  }
    break;

  case 777:

/* Line 1455 of yacc.c  */
#line 5627 "../src/parser/XQParser.y"
    {
    std::cerr << ", StringLiteral" << std::endl;
  }
    break;

  case 778:

/* Line 1455 of yacc.c  */
#line 5635 "../src/parser/XQParser.y"
    {
    std::cerr << "union" << std::endl;
  }
    break;

  case 779:

/* Line 1455 of yacc.c  */
#line 5639 "../src/parser/XQParser.y"
    {
    std::cerr << "except" << std::endl;
  }
    break;

  case 780:

/* Line 1455 of yacc.c  */
#line 5647 "../src/parser/XQParser.y"
    {
    std::cerr << "language StringLiteral" << std::endl;
  }
    break;

  case 781:

/* Line 1455 of yacc.c  */
#line 5655 "../src/parser/XQParser.y"
    {
    std::cerr << "using wildcards" << std::endl;
  }
    break;

  case 782:

/* Line 1455 of yacc.c  */
#line 5659 "../src/parser/XQParser.y"
    {
    std::cerr << "no wildcards" << std::endl;
  }
    break;

  case 783:

/* Line 1455 of yacc.c  */
#line 5667 "../src/parser/XQParser.y"
    {
}
    break;

  case 784:

/* Line 1455 of yacc.c  */
#line 5674 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(3) - (3)].astNode);
  }
    break;

  case 785:

/* Line 1455 of yacc.c  */
#line 5682 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_REVALIDATION_SPECIFIED, "revalidation", "XUST0003");
    CONTEXT->setRevalidationMode(DocumentCache::VALIDATION_STRICT);
  }
    break;

  case 786:

/* Line 1455 of yacc.c  */
#line 5687 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_REVALIDATION_SPECIFIED, "revalidation", "XUST0003");
    CONTEXT->setRevalidationMode(DocumentCache::VALIDATION_LAX);
  }
    break;

  case 787:

/* Line 1455 of yacc.c  */
#line 5692 "../src/parser/XQParser.y"
    {
    CHECK_SPECIFIED((yylsp[(1) - (3)]), BIT_REVALIDATION_SPECIFIED, "revalidation", "XUST0003");
    CONTEXT->setRevalidationMode(DocumentCache::VALIDATION_SKIP);
  }
    break;

  case 788:

/* Line 1455 of yacc.c  */
#line 5704 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) UInsertAsFirst((yyvsp[(2) - (6)].astNode), (yyvsp[(6) - (6)].astNode), MEMMGR));
  }
    break;

  case 789:

/* Line 1455 of yacc.c  */
#line 5708 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) UInsertAsLast((yyvsp[(2) - (6)].astNode), (yyvsp[(6) - (6)].astNode), MEMMGR));
  }
    break;

  case 790:

/* Line 1455 of yacc.c  */
#line 5712 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) UInsertInto((yyvsp[(2) - (4)].astNode), (yyvsp[(4) - (4)].astNode), MEMMGR));
  }
    break;

  case 791:

/* Line 1455 of yacc.c  */
#line 5716 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) UInsertAfter((yyvsp[(2) - (4)].astNode), (yyvsp[(4) - (4)].astNode), MEMMGR));
  }
    break;

  case 792:

/* Line 1455 of yacc.c  */
#line 5720 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) UInsertBefore((yyvsp[(2) - (4)].astNode), (yyvsp[(4) - (4)].astNode), MEMMGR));
  }
    break;

  case 795:

/* Line 1455 of yacc.c  */
#line 5731 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) UDelete((yyvsp[(2) - (2)].astNode), MEMMGR));
  }
    break;

  case 798:

/* Line 1455 of yacc.c  */
#line 5742 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) UReplaceValueOf((yyvsp[(5) - (7)].astNode), (yyvsp[(7) - (7)].astNode), MEMMGR));
  }
    break;

  case 799:

/* Line 1455 of yacc.c  */
#line 5746 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) UReplace((yyvsp[(3) - (5)].astNode), (yyvsp[(5) - (5)].astNode), MEMMGR));
  }
    break;

  case 800:

/* Line 1455 of yacc.c  */
#line 5756 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) URename((yyvsp[(3) - (5)].astNode), (yyvsp[(5) - (5)].astNode), MEMMGR));
  }
    break;

  case 801:

/* Line 1455 of yacc.c  */
#line 5764 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) UTransform((yyvsp[(2) - (6)].copyBindingList), (yyvsp[(4) - (6)].astNode), (yyvsp[(6) - (6)].astNode), MEMMGR));
  }
    break;

  case 802:

/* Line 1455 of yacc.c  */
#line 5771 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].copyBindingList)->push_back((yyvsp[(3) - (3)].copyBinding));
    (yyval.copyBindingList) = (yyvsp[(1) - (3)].copyBindingList);
  }
    break;

  case 803:

/* Line 1455 of yacc.c  */
#line 5776 "../src/parser/XQParser.y"
    {
    (yyval.copyBindingList) = new (MEMMGR) VectorOfCopyBinding(XQillaAllocator<CopyBinding*>(MEMMGR));
    (yyval.copyBindingList)->push_back((yyvsp[(1) - (1)].copyBinding));
  }
    break;

  case 804:

/* Line 1455 of yacc.c  */
#line 5784 "../src/parser/XQParser.y"
    {
    (yyval.copyBinding) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) CopyBinding(MEMMGR, (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].astNode)));
  }
    break;

  case 805:

/* Line 1455 of yacc.c  */
#line 5793 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::INTEGER, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 806:

/* Line 1455 of yacc.c  */
#line 5801 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::DECIMAL, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 807:

/* Line 1455 of yacc.c  */
#line 5809 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::DOUBLE, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 808:

/* Line 1455 of yacc.c  */
#line 5818 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQLiteral((ItemType*)&ItemType::STRING, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 809:

/* Line 1455 of yacc.c  */
#line 5825 "../src/parser/XQParser.y"
    {
    // Check for a colon
    for(XMLCh *tmp = (yyvsp[(1) - (1)].str); *tmp; ++tmp)
      if(*tmp == ':') yyerror((yylsp[(1) - (1)]), "Expecting an NCName, found a QName");
  }
    break;

  case 810:

/* Line 1455 of yacc.c  */
#line 5834 "../src/parser/XQParser.y"
    {
    (yyval.qName) = new (MEMMGR) QualifiedName((yyvsp[(1) - (1)].str),MEMMGR);
  }
    break;

  case 811:

/* Line 1455 of yacc.c  */
#line 5846 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (5)].str), 0, signature, (yyvsp[(5) - (5)].astNode), MEMMGR));
  }
    break;

  case 812:

/* Line 1455 of yacc.c  */
#line 5851 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature((yyvsp[(5) - (7)].argSpecs), (yyvsp[(6) - (7)].sequenceType), MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (7)].str), 0, signature, (yyvsp[(7) - (7)].astNode), MEMMGR));
  }
    break;

  case 813:

/* Line 1455 of yacc.c  */
#line 5856 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (8)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (8)].str), (yyvsp[(7) - (8)].itemList), signature, (yyvsp[(8) - (8)].astNode), MEMMGR));
    (yyval.functDecl)->setModeList((yyvsp[(5) - (8)].modeList));
  }
    break;

  case 814:

/* Line 1455 of yacc.c  */
#line 5862 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature((yyvsp[(8) - (10)].argSpecs), (yyvsp[(9) - (10)].sequenceType), MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (10)]), new (MEMMGR) XQUserFunction((yyvsp[(4) - (10)].str), (yyvsp[(7) - (10)].itemList), signature, (yyvsp[(10) - (10)].astNode), MEMMGR));
    (yyval.functDecl)->setModeList((yyvsp[(5) - (10)].modeList));
  }
    break;

  case 815:

/* Line 1455 of yacc.c  */
#line 5868 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature(MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) XQUserFunction(0, (yyvsp[(5) - (6)].itemList), signature, (yyvsp[(6) - (6)].astNode), MEMMGR));
    (yyval.functDecl)->setModeList((yyvsp[(3) - (6)].modeList));
  }
    break;

  case 816:

/* Line 1455 of yacc.c  */
#line 5874 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature((yyvsp[(6) - (8)].argSpecs), (yyvsp[(7) - (8)].sequenceType), MEMMGR);
    (yyval.functDecl) = WRAP((yylsp[(1) - (8)]), new (MEMMGR) XQUserFunction(0, (yyvsp[(5) - (8)].itemList), signature, (yyvsp[(8) - (8)].astNode), MEMMGR));
    (yyval.functDecl)->setModeList((yyvsp[(3) - (8)].modeList));
  }
    break;

  case 817:

/* Line 1455 of yacc.c  */
#line 5883 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = 0;
  }
    break;

  case 818:

/* Line 1455 of yacc.c  */
#line 5887 "../src/parser/XQParser.y"
    {
    (yyval.sequenceType) = (yyvsp[(2) - (2)].sequenceType);
  }
    break;

  case 819:

/* Line 1455 of yacc.c  */
#line 5895 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = 0;
  }
    break;

  case 820:

/* Line 1455 of yacc.c  */
#line 5899 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = (yyvsp[(2) - (3)].argSpecs);
  }
    break;

  case 821:

/* Line 1455 of yacc.c  */
#line 5906 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
    (yyval.modeList)->push_back(WRAP((yyloc), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT)));
  }
    break;

  case 822:

/* Line 1455 of yacc.c  */
#line 5911 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = (yyvsp[(2) - (2)].modeList);
  }
    break;

  case 823:

/* Line 1455 of yacc.c  */
#line 5919 "../src/parser/XQParser.y"
    {
    (yyval.modeList) = new (MEMMGR) XQUserFunction::ModeList(XQillaAllocator<XQUserFunction::Mode*>(MEMMGR));
    (yyval.modeList)->push_back((yyvsp[(1) - (1)].mode));
  }
    break;

  case 824:

/* Line 1455 of yacc.c  */
#line 5924 "../src/parser/XQParser.y"
    {
    (yyvsp[(1) - (3)].modeList)->push_back((yyvsp[(3) - (3)].mode));
    (yyval.modeList) = (yyvsp[(1) - (3)].modeList);
  }
    break;

  case 825:

/* Line 1455 of yacc.c  */
#line 5933 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode((yyvsp[(1) - (1)].str)));
  }
    break;

  case 826:

/* Line 1455 of yacc.c  */
#line 5937 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT));
  }
    break;

  case 827:

/* Line 1455 of yacc.c  */
#line 5941 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::ALL));
  }
    break;

  case 828:

/* Line 1455 of yacc.c  */
#line 5949 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQCallTemplate((yyvsp[(3) - (3)].str), 0, MEMMGR));
  }
    break;

  case 829:

/* Line 1455 of yacc.c  */
#line 5953 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) XQCallTemplate((yyvsp[(3) - (7)].str), (yyvsp[(6) - (7)].templateArgs), MEMMGR));
  }
    break;

  case 830:

/* Line 1455 of yacc.c  */
#line 5961 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQApplyTemplates((yyvsp[(3) - (3)].astNode), 0, 0, MEMMGR));
  }
    break;

  case 831:

/* Line 1455 of yacc.c  */
#line 5965 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) XQApplyTemplates((yyvsp[(3) - (7)].astNode), (yyvsp[(6) - (7)].templateArgs), 0, MEMMGR));
  }
    break;

  case 832:

/* Line 1455 of yacc.c  */
#line 5969 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQApplyTemplates((yyvsp[(3) - (5)].astNode), 0, (yyvsp[(5) - (5)].mode), MEMMGR));
  }
    break;

  case 833:

/* Line 1455 of yacc.c  */
#line 5973 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (9)]), new (MEMMGR) XQApplyTemplates((yyvsp[(3) - (9)].astNode), (yyvsp[(8) - (9)].templateArgs), (yyvsp[(5) - (9)].mode), MEMMGR));
  }
    break;

  case 834:

/* Line 1455 of yacc.c  */
#line 5981 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode((yyvsp[(1) - (1)].str)));
  }
    break;

  case 835:

/* Line 1455 of yacc.c  */
#line 5985 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::DEFAULT));
  }
    break;

  case 836:

/* Line 1455 of yacc.c  */
#line 5989 "../src/parser/XQParser.y"
    {
    (yyval.mode) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQUserFunction::Mode(XQUserFunction::Mode::CURRENT));
  }
    break;

  case 837:

/* Line 1455 of yacc.c  */
#line 5997 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = new (MEMMGR) TemplateArguments(XQillaAllocator<XQTemplateArgument*>(MEMMGR));
    (yyval.templateArgs)->push_back((yyvsp[(1) - (1)].templateArg));
  }
    break;

  case 838:

/* Line 1455 of yacc.c  */
#line 6002 "../src/parser/XQParser.y"
    {
    (yyval.templateArgs) = (yyvsp[(1) - (3)].templateArgs);
    (yyval.templateArgs)->push_back((yyvsp[(3) - (3)].templateArg));
  }
    break;

  case 839:

/* Line 1455 of yacc.c  */
#line 6012 "../src/parser/XQParser.y"
    {
    if((yyvsp[(3) - (5)].sequenceType) != 0)
      (yyvsp[(5) - (5)].astNode) = (yyvsp[(3) - (5)].sequenceType)->convertFunctionArg((yyvsp[(5) - (5)].astNode), CONTEXT, /*numericfunction*/false, (yyvsp[(3) - (5)].sequenceType));
    (yyval.templateArg) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQTemplateArgument((yyvsp[(2) - (5)].str), (yyvsp[(5) - (5)].astNode), MEMMGR));
  }
    break;

  case 842:

/* Line 1455 of yacc.c  */
#line 6029 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionRef((yyvsp[(1) - (3)].str), atoi(UTF8((yyvsp[(3) - (3)].str))), MEMMGR));
  }
    break;

  case 843:

/* Line 1455 of yacc.c  */
#line 6037 "../src/parser/XQParser.y"
    {
    FunctionSignature *signature = new (MEMMGR) FunctionSignature((yyvsp[(2) - (4)].argSpecs), (yyvsp[(3) - (4)].sequenceType), MEMMGR);
    XQUserFunction *func = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQUserFunction(0, signature, (yyvsp[(4) - (4)].astNode), false, MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQInlineFunction(func, MEMMGR));
  }
    break;

  case 844:

/* Line 1455 of yacc.c  */
#line 6048 "../src/parser/XQParser.y"
    {
    REJECT_NOT_VERSION3(DynamicFunctionInvocation, (yylsp[(1) - (3)]));
    (yyval.astNode) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) XQFunctionDeref((yyvsp[(1) - (3)].astNode), new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR)), MEMMGR));
  }
    break;

  case 845:

/* Line 1455 of yacc.c  */
#line 6053 "../src/parser/XQParser.y"
    {
    REJECT_NOT_VERSION3(DynamicFunctionInvocation, (yylsp[(1) - (4)]));

    bool partial = false;
    VectorOfASTNodes::iterator i;
    for(i = (yyvsp[(3) - (4)].itemList)->begin(); i != (yyvsp[(3) - (4)].itemList)->end(); ++i) {
      if(*i == 0) {
        partial = true;
        break;
      }
    }

    if(partial) {
      // This is a partial function application
      (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQPartialApply((yyvsp[(1) - (4)].astNode), (yyvsp[(3) - (4)].itemList), MEMMGR));
    }
    else {
      (yyval.astNode) = WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQFunctionDeref((yyvsp[(1) - (4)].astNode), (yyvsp[(3) - (4)].itemList), MEMMGR));
    }
  }
    break;

  case 848:

/* Line 1455 of yacc.c  */
#line 6081 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) ItemType(ItemType::TEST_FUNCTION));
  }
    break;

  case 851:

/* Line 1455 of yacc.c  */
#line 6093 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) ItemType(new (MEMMGR) FunctionSignature(0, (yyvsp[(6) - (6)].sequenceType), MEMMGR), 0));
  }
    break;

  case 852:

/* Line 1455 of yacc.c  */
#line 6097 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (7)]), new (MEMMGR) ItemType(new (MEMMGR) FunctionSignature((yyvsp[(4) - (7)].argSpecs), (yyvsp[(7) - (7)].sequenceType), MEMMGR), 0));
  }
    break;

  case 853:

/* Line 1455 of yacc.c  */
#line 6104 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = new (MEMMGR) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(MEMMGR));
    (yyval.argSpecs)->push_back(WRAP((yylsp[(1) - (1)]), new (MEMMGR) ArgumentSpec(0, (yyvsp[(1) - (1)].sequenceType), MEMMGR)));
  }
    break;

  case 854:

/* Line 1455 of yacc.c  */
#line 6109 "../src/parser/XQParser.y"
    {
    (yyval.argSpecs) = (yyvsp[(1) - (3)].argSpecs);
    (yyval.argSpecs)->push_back(WRAP((yylsp[(1) - (3)]), new (MEMMGR) ArgumentSpec(0, (yyvsp[(3) - (3)].sequenceType), MEMMGR)));
  }
    break;

  case 855:

/* Line 1455 of yacc.c  */
#line 6118 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = (yyvsp[(2) - (3)].itemType);
  }
    break;

  case 858:

/* Line 1455 of yacc.c  */
#line 6131 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) ItemType((yyvsp[(3) - (4)].tupleMembers), 0));
  }
    break;

  case 859:

/* Line 1455 of yacc.c  */
#line 6135 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_TUPLE));
  }
    break;

  case 860:

/* Line 1455 of yacc.c  */
#line 6142 "../src/parser/XQParser.y"
    {
    (yyval.tupleMembers) = new (MEMMGR) TupleMembers(true, MEMMGR);
    (yyvsp[(1) - (1)].argSpec)->setIndex(0);
    (yyval.tupleMembers)->add(0, (yyvsp[(1) - (1)].argSpec));
  }
    break;

  case 861:

/* Line 1455 of yacc.c  */
#line 6148 "../src/parser/XQParser.y"
    {
    (yyval.tupleMembers) = (yyvsp[(1) - (3)].tupleMembers);
    (yyvsp[(3) - (3)].argSpec)->setIndex((yyval.tupleMembers)->size());
    (yyval.tupleMembers)->add(0, (yyvsp[(3) - (3)].argSpec));
  }
    break;

  case 862:

/* Line 1455 of yacc.c  */
#line 6158 "../src/parser/XQParser.y"
    {
    (yyval.argSpec) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) ArgumentSpec((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].sequenceType), MEMMGR));
  }
    break;

  case 863:

/* Line 1455 of yacc.c  */
#line 6166 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (6)]), new (MEMMGR) ItemType(WRAP((yylsp[(3) - (6)]), new (MEMMGR)
          SequenceType((yyvsp[(3) - (6)].itemType), SequenceType::EXACTLY_ONE)), (yyvsp[(5) - (6)].sequenceType), 0));
  }
    break;

  case 864:

/* Line 1455 of yacc.c  */
#line 6171 "../src/parser/XQParser.y"
    {
    (yyval.itemType) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) ItemType(ItemType::TEST_MAP));
  }
    break;

  case 867:

/* Line 1455 of yacc.c  */
#line 6181 "../src/parser/XQParser.y"
    {
    // Add a ContextTuple at the start
    TupleNode *tuples = setLastAncestor((yyvsp[(3) - (4)].tupleNode), WRAP((yylsp[(1) - (4)]), new (MEMMGR) ContextTuple(MEMMGR)));

    // Add the tuple constructor expression
    (yyval.astNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) XQTupleConstructor(tuples, MEMMGR));
  }
    break;

  case 868:

/* Line 1455 of yacc.c  */
#line 6189 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQTupleConstructor(WRAP((yylsp[(1) - (3)]), new (MEMMGR) ContextTuple(MEMMGR)), MEMMGR));
  }
    break;

  case 870:

/* Line 1455 of yacc.c  */
#line 6197 "../src/parser/XQParser.y"
    {
    (yyval.tupleNode) = setLastAncestor((yyvsp[(3) - (3)].tupleNode), (yyvsp[(1) - (3)].tupleNode));
  }
    break;

  case 871:

/* Line 1455 of yacc.c  */
#line 6205 "../src/parser/XQParser.y"
    {
    // TBD LetTuple doesn't give us the correct in-scope vars for the initializer - jpcs
    (yyval.tupleNode) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) LetTuple(0, (yyvsp[(1) - (4)].str), WRAP((yylsp[(2) - (4)]), new (MEMMGR) XQTreatAs((yyvsp[(4) - (4)].astNode), (yyvsp[(2) - (4)].sequenceType), MEMMGR)), MEMMGR));
  }
    break;

  case 872:

/* Line 1455 of yacc.c  */
#line 6214 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(3) - (4)].astNode);
  }
    break;

  case 873:

/* Line 1455 of yacc.c  */
#line 6218 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
        MEMMGR->getPooledString("empty-map"), 0, MEMMGR));
  }
    break;

  case 874:

/* Line 1455 of yacc.c  */
#line 6226 "../src/parser/XQParser.y"
    {
    XQFunctionCall *func = (XQFunctionCall*)(yyvsp[(1) - (1)].astNode);
    const_cast<VectorOfASTNodes&>(*func->getArguments())[0] =
      WRAP((yylsp[(1) - (1)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
          MEMMGR->getPooledString("empty-map"), 0, MEMMGR));
    (yyval.astNode) = func;
  }
    break;

  case 875:

/* Line 1455 of yacc.c  */
#line 6234 "../src/parser/XQParser.y"
    {
    XQFunctionCall *func = (XQFunctionCall*)(yyvsp[(3) - (3)].astNode);
    const_cast<VectorOfASTNodes&>(*func->getArguments())[0] = (yyvsp[(1) - (3)].astNode);
    (yyval.astNode) = func;
  }
    break;

  case 876:

/* Line 1455 of yacc.c  */
#line 6244 "../src/parser/XQParser.y"
    {
    VectorOfASTNodes *args = new (MEMMGR) VectorOfASTNodes(XQillaAllocator<ASTNode*>(MEMMGR));
    args->push_back(0);
    args->push_back((yyvsp[(1) - (3)].astNode));
    args->push_back((yyvsp[(3) - (3)].astNode));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQFunctionCall(0, XQFunction::XMLChFunctionURI,
        MEMMGR->getPooledString("map-put"), args, MEMMGR));
  }
    break;

  case 878:

/* Line 1455 of yacc.c  */
#line 6258 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQTupleMember((yyvsp[(3) - (3)].str), MEMMGR));
    (yyval.astNode) = WRAP((yylsp[(1) - (3)]), new (MEMMGR) XQMap((yyvsp[(1) - (3)].astNode), (yyval.astNode), MEMMGR));
  }
    break;

  case 879:

/* Line 1455 of yacc.c  */
#line 6266 "../src/parser/XQParser.y"
    {
    QP->_query->addTypeAlias(WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQTypeAlias((yyvsp[(3) - (5)].str), (yyvsp[(5) - (5)].itemType), MEMMGR)));
  }
    break;

  case 880:

/* Line 1455 of yacc.c  */
#line 6276 "../src/parser/XQParser.y"
    {
    QP->_rwrule = (yyvsp[(1) - (1)].rwrule);
  }
    break;

  case 881:

/* Line 1455 of yacc.c  */
#line 6283 "../src/parser/XQParser.y"
    {
    QP->_rwpattern = (yyvsp[(1) - (1)].rwpattern);
  }
    break;

  case 882:

/* Line 1455 of yacc.c  */
#line 6290 "../src/parser/XQParser.y"
    {
    (yyval.rwrule) = WRAP((yylsp[(1) - (5)]), new (MEMMGR) XQRewriteRule((yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].rwpattern), (yyvsp[(4) - (5)].astNode), MEMMGR));
    (yyval.rwrule)->addCase((yyvsp[(5) - (5)].rwcase));
  }
    break;

  case 883:

/* Line 1455 of yacc.c  */
#line 6295 "../src/parser/XQParser.y"
    {
    (yyval.rwrule) = (yyvsp[(1) - (2)].rwrule);
    (yyval.rwrule)->addCase((yyvsp[(2) - (2)].rwcase));
  }
    break;

  case 884:

/* Line 1455 of yacc.c  */
#line 6303 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = 0;
  }
    break;

  case 885:

/* Line 1455 of yacc.c  */
#line 6307 "../src/parser/XQParser.y"
    {
    (yyval.astNode) = (yyvsp[(2) - (2)].astNode);
  }
    break;

  case 886:

/* Line 1455 of yacc.c  */
#line 6314 "../src/parser/XQParser.y"
    {
    (yyval.rwcase) = new (MEMMGR) RewriteCase((yyvsp[(2) - (3)].astNode), (yyvsp[(3) - (3)].astNode));
  }
    break;

  case 887:

/* Line 1455 of yacc.c  */
#line 6321 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (8)]), new (MEMMGR) RewritePattern(ASTNode::IF, (yyvsp[(3) - (8)].rwpattern), (yyvsp[(6) - (8)].rwpattern), (yyvsp[(8) - (8)].rwpattern), MEMMGR));
  }
    break;

  case 889:

/* Line 1455 of yacc.c  */
#line 6329 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].rwpattern)->type == ASTNode::OR) {
      (yyval.rwpattern) = (yyvsp[(1) - (3)].rwpattern);
      (yyval.rwpattern)->children.push_back((yyvsp[(3) - (3)].rwpattern));
    }
    else {
      (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::OR, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
    }
  }
    break;

  case 891:

/* Line 1455 of yacc.c  */
#line 6343 "../src/parser/XQParser.y"
    {
    if((yyvsp[(1) - (3)].rwpattern)->type == ASTNode::AND) {
      (yyval.rwpattern) = (yyvsp[(1) - (3)].rwpattern);
      (yyval.rwpattern)->children.push_back((yyvsp[(3) - (3)].rwpattern));
    }
    else {
      (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::AND, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
    }
  }
    break;

  case 893:

/* Line 1455 of yacc.c  */
#line 6357 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::EQUALS, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 894:

/* Line 1455 of yacc.c  */
#line 6361 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::NOT_EQUALS, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 895:

/* Line 1455 of yacc.c  */
#line 6365 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::GREATER_THAN, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 896:

/* Line 1455 of yacc.c  */
#line 6369 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::GREATER_THAN_EQUAL, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 897:

/* Line 1455 of yacc.c  */
#line 6373 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::LESS_THAN, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 898:

/* Line 1455 of yacc.c  */
#line 6377 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::LESS_THAN_EQUAL, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 900:

/* Line 1455 of yacc.c  */
#line 6385 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::PLUS, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 901:

/* Line 1455 of yacc.c  */
#line 6389 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::MINUS, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 903:

/* Line 1455 of yacc.c  */
#line 6397 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::MULTIPLY, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 904:

/* Line 1455 of yacc.c  */
#line 6401 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::DIVIDE, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 905:

/* Line 1455 of yacc.c  */
#line 6405 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::INTEGER_DIVIDE, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 906:

/* Line 1455 of yacc.c  */
#line 6409 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(2) - (3)]), new (MEMMGR) RewritePattern(ASTNode::MOD, (yyvsp[(1) - (3)].rwpattern), (yyvsp[(3) - (3)].rwpattern), MEMMGR));
  }
    break;

  case 908:

/* Line 1455 of yacc.c  */
#line 6417 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = (yyvsp[(2) - (2)].rwpattern);
  }
    break;

  case 909:

/* Line 1455 of yacc.c  */
#line 6421 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) RewritePattern(ASTNode::UNARY_MINUS, (yyvsp[(2) - (2)].rwpattern), MEMMGR));
  }
    break;

  case 911:

/* Line 1455 of yacc.c  */
#line 6429 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (4)]), new (MEMMGR) RewritePattern(ASTNode::PREDICATE, (yyvsp[(1) - (4)].rwpattern), (yyvsp[(3) - (4)].rwpattern), MEMMGR));
  }
    break;

  case 913:

/* Line 1455 of yacc.c  */
#line 6437 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = (yyvsp[(3) - (4)].rwpattern);
    (yyval.rwpattern)->type = ASTNode::FUNCTION;
    (yyval.rwpattern)->value = (yyvsp[(1) - (4)].str);
    LOCATION((yylsp[(1) - (4)]), loc);
    (yyval.rwpattern)->setLocationInfo(&loc);
  }
    break;

  case 914:

/* Line 1455 of yacc.c  */
#line 6445 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = (yyvsp[(2) - (3)].rwpattern);
    LOCATION((yylsp[(1) - (3)]), loc);
    (yyval.rwpattern)->setLocationInfo(&loc);
  }
    break;

  case 915:

/* Line 1455 of yacc.c  */
#line 6451 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) RewritePattern(ASTNode::EXPR_SUBSTITUTION, (yyvsp[(2) - (2)].str), MEMMGR));
  }
    break;

  case 916:

/* Line 1455 of yacc.c  */
#line 6455 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) RewritePattern(AnyAtomicType::DECIMAL, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 917:

/* Line 1455 of yacc.c  */
#line 6459 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) RewritePattern(AnyAtomicType::DECIMAL, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 918:

/* Line 1455 of yacc.c  */
#line 6463 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) RewritePattern(AnyAtomicType::DOUBLE, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 919:

/* Line 1455 of yacc.c  */
#line 6467 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) RewritePattern(AnyAtomicType::STRING, (yyvsp[(1) - (1)].str), MEMMGR));
  }
    break;

  case 920:

/* Line 1455 of yacc.c  */
#line 6474 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yyloc), new (MEMMGR) RewritePattern(ASTNode::SEQUENCE, MEMMGR));
  }
    break;

  case 922:

/* Line 1455 of yacc.c  */
#line 6482 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = WRAP((yylsp[(1) - (1)]), new (MEMMGR) RewritePattern(ASTNode::SEQUENCE, (yyvsp[(1) - (1)].rwpattern), MEMMGR));
  }
    break;

  case 923:

/* Line 1455 of yacc.c  */
#line 6486 "../src/parser/XQParser.y"
    {
    (yyval.rwpattern) = (yyvsp[(1) - (3)].rwpattern);
    (yyval.rwpattern)->children.push_back((yyvsp[(3) - (3)].rwpattern));
  }
    break;

  case 925:

/* Line 1455 of yacc.c  */
#line 6498 "../src/parser/XQParser.y"
    {
    if(!QP->_rewriteRule)
      yyerror((yylsp[(1) - (2)]), "Expression substitutions are only allowed in rewrite rules");
    (yyval.astNode) = WRAP((yylsp[(1) - (2)]), new (MEMMGR) XQExprSubstitution((yyvsp[(2) - (2)].str), MEMMGR));
  }
    break;



/* Line 1455 of yacc.c  */
#line 13317 "../src/parser/XQParser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 6535 "../src/parser/XQParser.y"


}  // namespace XQParser


