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

#ifndef _V2NSUTILS_HPP
#define _V2NSUTILS_HPP

#include <xqilla/framework/XQillaExport.hpp>

#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/framework/XMLBuffer.hpp>

class XPath2MemoryManager;

class XQILLA_API XPath2NSUtils
{
public:

  /// Get the proper local name (not null if the node is DOM level 1...) 
  static const XMLCh* getLocalName(const XMLCh* name);

  ///returns the prefix part of a xs:foo string or a zero length string if no prefix
  static const XMLCh* getPrefix(const XMLCh* name, XPath2MemoryManager* memMgr);

  ///form a qualified name from a namespace and a name
  static const XMLCh* qualifyName(const XMLCh* prefix, const XMLCh* name, XPath2MemoryManager* memMgr);

  /// Returns the URI and localname combined as a single string
  static void makeURIName(const XMLCh *uri, const XMLCh *name, XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buf);
  static const XMLCh *makeURIName(const XMLCh *uri, const XMLCh *name, XPath2MemoryManager *mm);
  static void decomposeURIName(const XMLCh *uriname, XPath2MemoryManager *mm, const XMLCh *&uri, const XMLCh *&name);

  ///gets the owner element of an attribute, and the parent of any other node
  static XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *getParent(const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *node);
};

#endif

