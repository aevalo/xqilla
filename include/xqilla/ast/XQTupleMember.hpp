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

#ifndef _XQTUPLEMEMBER_HPP
#define _XQTUPLEMEMBER_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/ASTNodeImpl.hpp>

#include <xercesc/framework/XMLBuffer.hpp>

class XQILLA_API XQTupleMember : public ASTNodeImpl
{
public:
  XQTupleMember(const XMLCh *qname, XPath2MemoryManager* memMgr);
  XQTupleMember(const XMLCh *qname, const XMLCh *uri, const XMLCh *name, XPath2MemoryManager* memMgr);

  const XMLCh *getQName() const { return qname_; }
  const XMLCh *getURI() const { return uri_; }
  void setURI(const XMLCh *uri) { uri_ = uri; }
  const XMLCh *getName() const { return name_; }
  void setName(const XMLCh *name) { name_ = name; }

  virtual ASTNode *staticResolution(StaticContext *context);
  virtual ASTNode *staticTypingImpl(StaticContext *context);
  virtual Result createResult(DynamicContext* context, int flags=0) const;
  virtual Result iterateResult(const Result &contextItems, DynamicContext* context) const;

private:
  const XMLCh *qname_, *uri_, *name_;
};

#endif
