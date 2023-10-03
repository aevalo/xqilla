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

#include <xqilla/ast/XQPartialApply.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/FunctionRef.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/runtime/ResultImpl.hpp>
#include <xqilla/runtime/ClosureResult.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/ast/XQTreatAs.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

XERCES_CPP_NAMESPACE_USE;
using namespace std;

XQPartialApply::XQPartialApply(ASTNode *expr, VectorOfASTNodes *args, XPath2MemoryManager *mm)
  : ASTNodeImpl(PARTIAL_APPLY, mm),
    expr_(expr),
    args_(args)
{
}

ASTNode *XQPartialApply::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  ItemType *itemType = new (mm) ItemType(ItemType::TEST_FUNCTION);
  itemType->setLocationInfo(this);
  SequenceType *seqType = new (mm) SequenceType(itemType, SequenceType::EXACTLY_ONE);
  seqType->setLocationInfo(this);

  expr_ = new (mm) XQTreatAs(expr_, seqType, mm);
  expr_->setLocationInfo(this);
  expr_ = expr_->staticResolution(context);

  unsigned int argCount = 0;
  if(args_) {
    for(VectorOfASTNodes::iterator i = args_->begin(); i != args_->end(); ++i) {
      if(*i != 0) {
        *i = (*i)->staticResolution(context);
        ++argCount;
      }
    }
  }

  // If no actual arguments are specified, the partial apply has no effect
  if(argCount == 0) {
    ASTNode *result = expr_;
    expr_ = 0;
    this->release();
    return result;
  }

  return this;
}

ASTNode *XQPartialApply::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.add(expr_->getStaticAnalysis());

  unsigned int argCount = 0;
  if(args_) {
    for(VectorOfASTNodes::iterator i = args_->begin(); i != args_->end(); ++i) {
      if(*i != 0) {
        _src.add((*i)->getStaticAnalysis());
        ++argCount;
      }
    }
  }

  _src.getStaticType() = StaticType::EMPTY;
  bool doneOne = false;

  const StaticType::ItemTypes &types = expr_->getStaticAnalysis().getStaticType().getTypes();
  StaticType::ItemTypes::const_iterator i = types.begin();
  for(; i != types.end(); ++i) {
    if((*i)->getItemTestType() == ItemType::TEST_FUNCTION) {
      if((*i)->getFunctionSignature()) {
        if((*i)->getFunctionSignature()->numArgs() == args_->size()) {
          FunctionSignature *newSig = new (getMemoryManager())
            FunctionSignature((*i)->getFunctionSignature(), args_, getMemoryManager());
          ItemType *type = new (getMemoryManager()) ItemType(newSig, (*i)->getDocumentCache());
          type->setLocationInfo(this);
          StaticType tmp(type, BasicMemoryManager::get());
          if(doneOne) _src.getStaticType().typeUnion(tmp);
          else { _src.getStaticType() = tmp; doneOne = true; }
        }
      } else {
        _src.getStaticType() = StaticType::FUNCTION;
        break;
      }
    } else if(ItemType::FUNCTION.isSubtypeOf(*i)) {
      _src.getStaticType() = StaticType::ITEM_STAR;
      break;
    }
  }

  return this;
}

Result XQPartialApply::createResult(DynamicContext *context, int flags) const
{
  FunctionRef::Ptr function = (FunctionRef*)expr_->createResult(context)->next(context).get();

  if(args_->size() != function->getNumArgs()) {
    XMLBuffer buf;
    buf.set(X("The function item invoked does not accept "));
    XPath2Utils::numToBuf((unsigned int)args_->size(), buf);
    buf.append(X(" arguments - found item of type "));
    function->typeToBuffer(context, buf);
    buf.append(X(" [err:XPTY0004]"));
    XQThrow(XPath2TypeMatchException, X("XQPartialApply::createResult"), buf.getRawBuffer());
  }

  int argNum = 1;
  VectorOfASTNodes::iterator i;
  for(i = args_->begin(); i != args_->end(); ++i) {
    if(*i)
      function = function->partialApply((*i)->createResult(context), argNum, context, this);
    else ++argNum;
  }

  return (Item::Ptr)function;
}
