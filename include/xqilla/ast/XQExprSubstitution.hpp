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

#ifndef XQEXPRSUBSTITUTION_HPP
#define XQEXPRSUBSTITUTION_HPP

#include <xqilla/ast/ASTNodeImpl.hpp>

class XQILLA_API XQExprSubstitution : public ASTNodeImpl
{
public:
  XQExprSubstitution(const XMLCh *qname, XPath2MemoryManager *mm);
  XQExprSubstitution(const XMLCh *qname, const XMLCh *uri, const XMLCh *name,
                     XPath2MemoryManager *mm);

  virtual ASTNode *staticResolution(StaticContext *context);
  virtual ASTNode *staticTypingImpl(StaticContext *context);

  virtual Result createResult(DynamicContext* context, int flags=0) const;

  const XMLCh *getQName() const { return qname_; }
  const XMLCh *getURI() const { return uri_; }
  const XMLCh *getName() const { return name_; }

private:
  const XMLCh *qname_;
  const XMLCh *uri_;
  const XMLCh *name_;
};

#endif
