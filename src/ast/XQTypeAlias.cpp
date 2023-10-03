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

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/XQTypeAlias.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/schema/SequenceType.hpp>

#if defined(XERCES_HAS_CPP_NAMESPACE)
XERCES_CPP_NAMESPACE_USE
#endif

XQTypeAlias::XQTypeAlias(const XMLCh *qname, ItemType *type, XPath2MemoryManager *mm)
  : qname_(qname),
    uri_(0),
    name_(0),
    uriname_(1023, mm),
    type_(type),
    isResolved_(false)
{
}

void XQTypeAlias::resolveName(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  if(name_ == 0) {
    const XMLCh *prefix = XPath2NSUtils::getPrefix(qname_, mm);
    if(prefix && *prefix)
      uri_ = context->getUriBoundToPrefix(prefix, this);
    else
      uri_ = context->getDefaultElementAndTypeNS();
    name_ = XPath2NSUtils::getLocalName(qname_);
    setURINameHash();
  }
}

void XQTypeAlias::staticResolution(StaticContext *context)
{
  type_ = type_->staticResolution(context, this);
  isResolved_ = true;
}

void XQTypeAlias::setURINameHash()
{
  uriname_.set(name_);
  uriname_.append(':');
  uriname_.append(uri_);
}
