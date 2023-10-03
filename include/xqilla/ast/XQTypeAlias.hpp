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

#ifndef XQTYPEALIAS_HPP
#define XQTYPEALIAS_HPP

#include <xqilla/ast/LocationInfo.hpp>

#include <xercesc/framework/XMLBuffer.hpp>

class XPath2MemoryManager;
class StaticContext;
class ItemType;

class XQILLA_API XQTypeAlias : public LocationInfo
{
public:
  XQTypeAlias(const XMLCh *qname, ItemType *type, XPath2MemoryManager *mm);

  const XMLCh *getQName() const { return qname_; }
  const XMLCh *getURI() const { return uri_; }
  void setURI(const XMLCh *uri) { uri_ = uri; setURINameHash(); }
  const XMLCh *getName() const { return name_; }
  void setName(const XMLCh *name) { name_ = name; setURINameHash(); }

  const XMLCh *getURINameHash() const { return uriname_.getRawBuffer(); }

  ItemType *getType() const { return type_; }
  void setType(ItemType *t) { type_ = t; }

  bool isResolved() const { return isResolved_; }

  void resolveName(StaticContext *context);
  void staticResolution(StaticContext *context);

protected:
  void setURINameHash();

  const XMLCh *qname_, *uri_, *name_;
  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer uriname_;

  ItemType *type_;
  bool isResolved_;
};

#endif
