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

#include <xqilla/debug/TupleDebugHook.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/debug/DebugListener.hpp>
#include <xqilla/debug/StackFrame.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/exceptions/XQException.hpp>
#include <xqilla/optimizer/ASTToXML.hpp>
#include <xqilla/simple-api/XQillaConfiguration.hpp>

XERCES_CPP_NAMESPACE_USE;

TupleDebugHook::TupleDebugHook(TupleNode *parent, XPath2MemoryManager *mm)
  : TupleNode(DEBUG_HOOK, parent, mm)
{
  setLocationInfo(parent);
}

TupleNode *TupleDebugHook::staticResolution(StaticContext *context)
{
  parent_ = parent_->staticResolution(context);
  return this;
}

TupleNode *TupleDebugHook::staticTypingImpl(StaticContext *context)
{
  src_.clear();
  src_.copy(parent_->getStaticAnalysis());
  return this;
}

class TupleStackFrame : public StackFrame {
public:
  TupleStackFrame(const TupleNode *ast, DynamicContext *context)
    : StackFrame(ast, context) {}

  const ASTNode *getASTNode() const { return 0; }
  const TupleNode *getTupleNode() const { return (TupleNode*)location_; }
  virtual std::string getQueryPlan() const
  {
    AutoDelete<ASTToXML> a2x(context_->getConfiguration()->createASTToXML());
    return a2x->print(getTupleNode(), context_);
  }
};

class TupleDebugHookResult : public TupleResult
{
public:
  TupleDebugHookResult(const TupleNode *expr, DynamicContext *context)
    : TupleResult(expr),
      context_(context),
      frame_(expr, context),
      parent_(0)
  {
    DebugListener *dl = context->getDebugListener();

    AutoStackFrameReset reset(context, &frame_);
    if(dl) dl->start(&frame_, context);
    try {
      parent_ = expr->createResult(context);
    }
    catch(XQException &ex) {
      if(dl) dl->error(ex, &frame_, context);
    }
  }

  ~TupleDebugHookResult()
  {
    parent_ = 0;

    DebugListener *dl = context_->getDebugListener();

    AutoStackFrameReset reset(context_, &frame_);
    if(dl) dl->end(&frame_, context_);
  }
  
  virtual Result getVar(const XMLCh *namespaceURI, const XMLCh *name) const
  {
    return parent_->getVar(namespaceURI, name);
  }

  virtual void getInScopeVariables(std::vector<std::pair<const XMLCh*, const XMLCh*> > &variables) const
  {
    parent_->getInScopeVariables(variables);
  }

  virtual bool next(DynamicContext *context)
  {
    DebugListener *dl = context->getDebugListener();

    AutoStackFrameReset reset(context, &frame_);
    if(dl) dl->enter(&frame_, context);
    try {
      bool result = parent_->next(context);
      if(dl) dl->exit(&frame_, context);
      return result;
    }
    catch(XQException &ex) {
      if(dl) dl->error(ex, &frame_, context);
    }
    return false;
  }

  virtual void createTuple(DynamicContext *context, size_t capacity, TupleImpl::Ptr &result) const
  {
    parent_->createTuple(context, capacity, result);
  }

private:
  DynamicContext *context_;
  TupleStackFrame frame_;
  TupleResult::Ptr parent_;
};

TupleResult::Ptr TupleDebugHook::createResult(DynamicContext* context) const
{
  return new TupleDebugHookResult(parent_, context);
}

