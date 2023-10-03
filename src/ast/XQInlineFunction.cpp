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

#include <xqilla/ast/XQInlineFunction.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/functions/XQUserFunction.hpp>
#include <xqilla/context/VariableTypeStore.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/functions/FunctionSignature.hpp>

#include "../items/impl/FunctionRefImpl.hpp"

XERCES_CPP_NAMESPACE_USE;
using namespace std;

XQInlineFunction::XQInlineFunction(XQUserFunction *func, XPath2MemoryManager *mm)
  : ASTNodeImpl(INLINE_FUNCTION, mm),
    func_(func),
    prefix_(0),
    uri_(0),
    name_(0),
    type_(new (mm) ItemType(new (mm) FunctionSignature(func->getSignature(), mm), 0)),
    instance_(0)
{
}

XQInlineFunction::XQInlineFunction(XQUserFunction *func, const XMLCh *prefix, const XMLCh *uri, const XMLCh *name,
  ItemType *type, ASTNode *instance, XPath2MemoryManager *mm)
  : ASTNodeImpl(INLINE_FUNCTION, mm),
    func_(func),
    prefix_(prefix),
    uri_(uri),
    name_(name),
    type_(type),
    instance_(instance)
{
}

unsigned int XQInlineFunction::getNumArgs() const
{
  return type_->getFunctionSignature()->numArgs();
}

ASTNode *XQInlineFunction::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  func_->staticResolutionStage1(context);
  type_->staticResolution(context, this);

  instance_ = FunctionRefImpl::createInstance(func_, type_->getFunctionSignature(), mm, this);
  instance_ = instance_->staticResolution(context);

  func_->staticResolutionStage2(context);

  return this;
}

ASTNode *XQInlineFunction::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.addExceptContextFlags(instance_->getStaticAnalysis());

  // Remove the argument variables
  if(type_->getFunctionSignature()->argSpecs) {
    ArgumentSpecs::const_iterator argsIt = type_->getFunctionSignature()->argSpecs->begin();
    for(; argsIt != type_->getFunctionSignature()->argSpecs->end(); ++argsIt) {
      _src.removeVariable((*argsIt)->getURI(), (*argsIt)->getName());
    }
  }

  _src.getStaticType() = type_;

  return this;
}

Result XQInlineFunction::createResult(DynamicContext *context, int flags) const
{
  return (Item::Ptr)new FunctionRefImpl(prefix_, uri_, name_, type_->getFunctionSignature(), instance_, _src, context);
}
