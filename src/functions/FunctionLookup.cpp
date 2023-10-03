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
#include <xqilla/functions/FunctionLookup.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/functions/ExternalFunction.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/framework/XPath2MemoryManagerImpl.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>

XERCES_CPP_NAMESPACE_USE

FunctionLookup *FunctionLookup::g_globalFunctionTable = 0;
XPath2MemoryManager *FunctionLookup::g_memMgr = 0;

FunctionLookup::FunctionLookup(XPath2MemoryManager* memMgr)
  : _funcTable(193, true, memMgr),
    _exFuncTable(7, true, memMgr)
{
}

FunctionLookup::~FunctionLookup()
{
}

void FunctionLookup::insertFunction(const FuncFactory *func)
{
  // Use similar algorithm to lookup in order to detect overlaps
  // in argument numbers
  //
  // Walk the matches for the primary key (name) looking for overlaps:
  //   ensure func->max < min OR func->min > max
  //
  size_t hash = _funcTable.getHash(func->getURIName());
  FuncMap::iterator iterator = _funcTable.find(func->getURIName(), hash);
  FuncMap::iterator end = _funcTable.end();
  for(; iterator != end; ++iterator) {
    if ((func->getMaxArgs() < iterator.getValue()->getMinArgs()) ||
      (func->getMinArgs() > iterator.getValue()->getMaxArgs()))
      continue;
    // overlap -- throw exception
    XMLBuffer buf;
    buf.set(X("Multiple functions have the same expanded QName and number of arguments {"));
    buf.append(func->getURI());
    buf.append(X("}"));
    buf.append(func->getName());
    buf.append(X("#"));
    if(func->getMinArgs() >= iterator.getValue()->getMinArgs() &&
      func->getMinArgs() <= iterator.getValue()->getMaxArgs())
      XPath2Utils::numToBuf((unsigned int)func->getMinArgs(), buf);
    else
      XPath2Utils::numToBuf((unsigned int)iterator.getValue()->getMinArgs(), buf);
    buf.append(X(" [err:XQST0034]."));
    XQThrow2(StaticErrorException,X("FunctionLookup::insertFunction"), buf.getRawBuffer());
  }
  // Ok to add function
  _funcTable.add(func->getURIName(), hash, func);
}

void FunctionLookup::removeFunction(const FuncFactory *func)
{
  FuncMap::iterator iterator = _funcTable.find(func->getURIName());
  for(; iterator != _funcTable.end(); ++iterator) {
    if ((func->getMaxArgs() == iterator.getValue()->getMinArgs()) &&
      (func->getMinArgs() == iterator.getValue()->getMaxArgs())) {
      _funcTable.remove(iterator);
      break;
    }
  }
}

ASTNode* FunctionLookup::lookUpFunction(const XMLCh* URI, const XMLCh* fname,
                                        const VectorOfASTNodes &args, XPath2MemoryManager* memMgr) const
{
  if (this != g_globalFunctionTable) {
    ASTNode *ret = g_globalFunctionTable->lookUpFunction(
                                                         URI, fname, args, memMgr);
    if (ret)
      return ret;
  }

  //
  // Walk the matches for the primary key (name) looking for matches
  // based on allowable parameters
  //
  XMLBuffer key;
  XPath2NSUtils::makeURIName(URI, fname, key);
  FuncMap::iterator iterator = const_cast<FuncMap&>(_funcTable).find(key.getRawBuffer());
  FuncMap::iterator end = const_cast<FuncMap&>(_funcTable).end();
  size_t nargs = args.size();
  for(; iterator != end; ++iterator) {
    if (iterator.getValue()->getMinArgs() <= nargs &&
      iterator.getValue()->getMaxArgs() >= nargs)
      return iterator.getValue()->createInstance(args, memMgr);
  }
  return 0;
}

//
// external functions are hashed on name+uri (primary) and numargs (secondary)
//
void FunctionLookup::insertExternalFunction(const ExternalFunction *func)
{
  _exFuncTable.add(func->getURINameHash(), func);
}

const ExternalFunction *FunctionLookup::lookUpExternalFunction(
  const XMLCh* URI, const XMLCh* fname, size_t numArgs) const
{
  XMLBuffer key;
  XPath2NSUtils::makeURIName(URI, fname, key);
  ExFuncMap::iterator iterator = const_cast<ExFuncMap&>(_exFuncTable).find(key.getRawBuffer());
  ExFuncMap::iterator end = const_cast<ExFuncMap&>(_exFuncTable).end();
  for(; iterator != end; ++iterator) {
    if (iterator.getValue()->getNumberOfArguments() == numArgs)
      return iterator.getValue();
  }
  return 0;
}

void FunctionLookup::copyExternalFunctionsTo(DynamicContext *context) const
{
  ExFuncMap::iterator iterator = const_cast<ExFuncMap&>(_exFuncTable).begin();
  ExFuncMap::iterator end = const_cast<ExFuncMap&>(_exFuncTable).end();
  for(; iterator != end; ++iterator) {
    context->addExternalFunction(iterator.getValue());
  }
}

/*
 * Global initialization and access
 */
static void initGlobalTable(FunctionLookup *t, XPath2MemoryManager *memMgr);

// static
void FunctionLookup::initialize()
{
  /* global table is allocated via the memory manager, so
     no need to delete it at this time
     if (g_globalFunctionTable)
     delete g_globalFunctionTable;
  */
  if (g_memMgr)
    delete g_memMgr;
  g_memMgr = new XPath2MemoryManagerImpl();
  g_globalFunctionTable = new (g_memMgr) FunctionLookup(g_memMgr);
  initGlobalTable(g_globalFunctionTable, g_memMgr);
}

// static
void FunctionLookup::terminate()
{
  if (g_memMgr) {
    delete g_memMgr;
    g_memMgr = 0;
    g_globalFunctionTable = 0;
  }
  /* no need to delete this -- memMgr cleans up
     if (g_globalFunctionTable) {
     delete g_globalFunctionTable;
     g_globalFunctionTable = 0;
     }
  */
}

// static
void FunctionLookup::insertGlobalFunction(const FuncFactory *func)
{
  g_globalFunctionTable->insertFunction(func);
}

// static
void FunctionLookup::insertGlobalExternalFunction(const ExternalFunction *func)
{
  g_globalFunctionTable->insertExternalFunction(func);
}

// static
ASTNode* FunctionLookup::lookUpGlobalFunction(
                                              const XMLCh* URI, const XMLCh* fname,
                                              const VectorOfASTNodes &args,
                                              XPath2MemoryManager* memMgr,
                                              const FunctionLookup *contextTable)
{
  if(contextTable)
    return contextTable->lookUpFunction(URI, fname, args, memMgr);
  return g_globalFunctionTable->lookUpFunction(URI, fname, args, memMgr);
}

// static
const ExternalFunction *FunctionLookup::lookUpGlobalExternalFunction(
  const XMLCh* URI, const XMLCh* fname, size_t numArgs,
  const FunctionLookup *contextTable)
{
  const ExternalFunction *ef =
    g_globalFunctionTable->lookUpExternalFunction(
      URI, fname, numArgs);
  if (!ef && contextTable)
    ef = contextTable->lookUpExternalFunction(
      URI, fname, numArgs);
  return ef;
}

#include "FuncFactoryTemplate.hpp"
#include <xqilla/functions/FunctionBaseURI.hpp>
#include <xqilla/functions/FunctionCollection.hpp>
#include <xqilla/functions/FunctionCompare.hpp>
#include <xqilla/functions/FunctionConcat.hpp>
#include <xqilla/functions/FunctionContains.hpp>
#include <xqilla/functions/FunctionCount.hpp>
#include <xqilla/functions/FunctionDefaultCollation.hpp>
#include <xqilla/functions/FunctionDistinctValues.hpp>
#include <xqilla/functions/FunctionDoc.hpp>
#include <xqilla/functions/FunctionDocument.hpp>
#include <xqilla/functions/FunctionDocAvailable.hpp>
#include <xqilla/functions/FunctionDocumentURI.hpp>
#include <xqilla/functions/FunctionEmpty.hpp>
#include <xqilla/functions/FunctionEndsWith.hpp>
#include <xqilla/functions/FunctionError.hpp>
#include <xqilla/functions/FunctionId.hpp>
#include <xqilla/functions/FunctionIdref.hpp>
#include <xqilla/functions/FunctionImplicitTimezone.hpp>
#include <xqilla/functions/FunctionLang.hpp>
#include <xqilla/functions/FunctionLast.hpp>
#include <xqilla/functions/FunctionLocalname.hpp>
#include <xqilla/functions/FunctionLowerCase.hpp>
#include <xqilla/functions/FunctionMatches.hpp>
#include <xqilla/functions/FunctionName.hpp>
#include <xqilla/functions/FunctionNamespaceUri.hpp>
#include <xqilla/functions/FunctionNilled.hpp>
#include <xqilla/functions/FunctionNodeName.hpp>
#include <xqilla/functions/FunctionNormalizeSpace.hpp>
#include <xqilla/functions/FunctionNormalizeUnicode.hpp>
#include <xqilla/functions/FunctionNot.hpp>
#include <xqilla/functions/FunctionNumber.hpp>
#include <xqilla/functions/FunctionPosition.hpp>
#include <xqilla/functions/FunctionReplace.hpp>
#include <xqilla/functions/FunctionResolveURI.hpp>
#include <xqilla/functions/FunctionRoot.hpp>
#include <xqilla/functions/FunctionStartsWith.hpp>
#include <xqilla/functions/FunctionStaticBaseURI.hpp>
#include <xqilla/functions/FunctionString.hpp>
#include <xqilla/functions/FunctionStringLength.hpp>
#include <xqilla/functions/FunctionStringToCodepoints.hpp>
#include <xqilla/functions/FunctionCodepointsToString.hpp>
#include <xqilla/functions/FunctionSubstring.hpp>
#include <xqilla/functions/FunctionTokenize.hpp>
#include <xqilla/functions/FunctionTrace.hpp>
#include <xqilla/functions/FunctionUnordered.hpp>
#include <xqilla/functions/FunctionUpperCase.hpp>
#include <xqilla/functions/FunctionHead.hpp>
#include <xqilla/functions/FunctionTail.hpp>
// Updates
#include <xqilla/update/FunctionPut.hpp>
// XSLT 2.0 functions
#include <xqilla/functions/FunctionUnparsedText.hpp>
#include <xqilla/functions/FunctionRegexGroup.hpp>
// XQilla extension functions
#include <xqilla/functions/FunctionParseXML.hpp>
#include <xqilla/functions/FunctionParseHTML.hpp>
#include <xqilla/functions/FunctionTime.hpp>
#include <xqilla/functions/FunctionAnalyzeString.hpp>
#include <xqilla/functions/FunctionCaseFold.hpp>
#include <xqilla/functions/FunctionWords.hpp>
#include <xqilla/functions/FunctionSentences.hpp>
#include <xqilla/functions/FunctionExplain.hpp>
// Higher Order Functions extension functions
#include <xqilla/functions/FunctionFunctionArity.hpp>
#include <xqilla/functions/FunctionFunctionName.hpp>

void FunctionLookup::insertUpdateFunctions(XPath2MemoryManager *memMgr)
{
  // Update functions
  //   fn:put
  insertFunction(new (memMgr) FuncFactoryTemplate<FunctionPut>(memMgr));
}

static void initGlobalTable(FunctionLookup *t, XPath2MemoryManager *memMgr)
{
  // From the XPath2 Function & Operators list

  // Accessors:
  //   fn:node-name
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNodeName>(memMgr));
  //   fn:nilled
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNilled>(memMgr));
  //   fn:string
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionString>(memMgr));
  //   fn:base-uri
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionBaseURI>(memMgr));
  //   fn:document-uri
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDocumentURI>(memMgr));


  // Debug Functions:
  //   fn:error
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionError>(memMgr));
  //   fn:trace
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionTrace>(memMgr));

  // Functions on strings
  //   fn:codepoints-to-string
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionCodepointsToString>(memMgr));
  //   fn:string-to-codepoints
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionStringToCodepoints>(memMgr));
  //   fn:compare
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionCompare>(memMgr));
  //   fn:concat
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionConcat>(memMgr));
  //   fn:substring
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionSubstring>(memMgr));
  //   fn:string-length
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionStringLength>(memMgr));
  //   fn:normalize-space
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNormalizeSpace>(memMgr));
  //   fn:normalize-unicode
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNormalizeUnicode>(memMgr));
  //   fn:upper-case
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionUpperCase>(memMgr));
  //   fn:lower-case
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionLowerCase>(memMgr));
  //   fn:contains
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionContains>(memMgr));
  //   fn:starts-with
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionStartsWith>(memMgr));
  //   fn:ends-with
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionEndsWith>(memMgr));

  //   fn:matches
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionMatches>(memMgr));
  //   fn:replace
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionReplace>(memMgr));
  //   fn:tokenize
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionTokenize>(memMgr));

  // Functions on boolean values
  //   fn:not
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNot>(memMgr));

  // Functions on anyURI values
  //   fn:resolve-URI
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionResolveURI>(memMgr));

  // Functions on nodes
  //   fn:name
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionName>(memMgr));
  //   fn:local-name
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionLocalname>(memMgr));
  //   fn:namespace-uri
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNamespaceUri>(memMgr));
  //   fn:number
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionNumber>(memMgr));
  //   fn:lang
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionLang>(memMgr));
  //   fn:root
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionRoot>(memMgr));

  // Functions on sequences
  //   fn:empty
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionEmpty>(memMgr));
  //   fn:distinct-values
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDistinctValues>(memMgr));
  //   fn:unordered
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionUnordered>(memMgr));
  //   fn:head
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionHead>(memMgr));
  //   fn:tail
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionTail>(memMgr));
  
  //   fn:count
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionCount>(memMgr));

  //   fn:id
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionId>(memMgr));
  //   fn:idref
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionIdref>(memMgr));
  //   fn:doc
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDoc>(memMgr));
  //   fn:doc-available
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDocAvailable>(memMgr));
  //   fn:collection
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionCollection>(memMgr));
  
  // Context functions
  //   fn:position
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionPosition>(memMgr));
  //   fn:last
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionLast>(memMgr));
  //   fn:implicit-timezone
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionImplicitTimezone>(memMgr));
  //   fn:default-collation
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDefaultCollation>(memMgr));
  //   fn:static-base-uri
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionStaticBaseURI>(memMgr));

  // XSLT 2.0 functions
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionUnparsedText>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionRegexGroup>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDocument>(memMgr));

  // XQilla extension functions
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionParseXML>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionTime>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionXQillaAnalyzeString>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionCaseFold>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionWords>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionSentences>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionExplain>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionDrop>(memMgr));

#ifdef HAVE_LIBTIDY
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionParseHTML>(memMgr));
#endif

  // Higher Order Functions extension functions
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionFunctionArity>(memMgr));
  t->insertFunction(new (memMgr) FuncFactoryTemplate<FunctionFunctionName>(memMgr));

  try {
    const SimpleBuiltinFactory *sbf = SimpleBuiltinFactory::getAll();
    while(sbf) {
      t->insertFunction(sbf);
      sbf = sbf->getNext();
    }
  } catch(StaticErrorException &e) {
    e.printDebug(X("initGlobalTable"));
    throw;
  }
}
