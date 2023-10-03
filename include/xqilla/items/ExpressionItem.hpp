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

#ifndef _EXPRESSIONITEM_HPP
#define _EXPRESSIONITEM_HPP

#include <xqilla/items/Item.hpp>

class ASTNode;

class XQILLA_API ExpressionItem : public Item
{
public:
  typedef RefCountPointer<const ExpressionItem> Ptr;

  ExpressionItem(const ASTNode *ast) : ast_(ast) {}

  virtual Type getType() const { return EXPRESSION; }

  virtual const XMLCh *getTypeURI() const { return 0; }
  virtual const XMLCh *getTypeName() const { return 0; }

  const ASTNode *getExpression() const { return ast_; }

  virtual const XMLCh *asString(const DynamicContext *context) const;

  virtual void generateEvents(EventHandler *events, const DynamicContext *context,
                              bool preserveNS, bool preserveType) const;

  virtual void typeToBuffer(DynamicContext *context, XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buffer) const;

  virtual void *getInterface(const XMLCh *name) const { return 0; }

protected:
  const ASTNode *ast_;
};
#endif
