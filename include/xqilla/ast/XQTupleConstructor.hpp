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

#ifndef XQTUPLECONSTRUCTOR_HPP
#define XQTUPLECONSTRUCTOR_HPP

#include <xqilla/ast/ASTNodeImpl.hpp>

class TupleNode;

class XQILLA_API XQTupleConstructor : public ASTNodeImpl
{
public:
  XQTupleConstructor(TupleNode *parent, XPath2MemoryManager *mm);

  TupleNode *getParent() const { return parent_; }
  void setParent(TupleNode *parent) { parent_ = parent; }

  virtual ASTNode *staticResolution(StaticContext *context);
  virtual ASTNode *staticTypingImpl(StaticContext *context);

  virtual Result createResult(DynamicContext* context, int flags=0) const;

private:
  TupleNode *parent_;
};

#endif
