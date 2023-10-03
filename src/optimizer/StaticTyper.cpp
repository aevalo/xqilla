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

#include <xqilla/optimizer/StaticTyper.hpp>
#include <xqilla/ast/ASTNode.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/simple-api/XQQuery.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/context/VariableTypeStore.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/fulltext/FTSelection.hpp>
#include <xqilla/fulltext/DefaultTokenizer.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

#include "../items/impl/FunctionRefImpl.hpp"

#include <xercesc/validators/schema/SchemaSymbols.hpp>

XERCES_CPP_NAMESPACE_USE;

ASTNode *StaticTyper::run(ASTNode *item, StaticContext *context)
{
  AutoReset<StaticContext*> autoReset(context_);
  context_ = context;
  return optimize(item);
}

void StaticTyper::optimize(XQQuery *query)
{
  assert(context_ == query->getStaticContext());

  query->staticTyping(this);
}

XQUserFunction *StaticTyper::optimizeFunctionDef(XQUserFunction *item)
{
  item->staticTypingOnce(context_, this);
  return item;
}

ASTNode *StaticTyper::optimize(ASTNode *item)
{
  ASTNode *result = ASTVisitor::optimize(item);
  if(result != item) return optimize(result);

  return item->staticTypingImpl(context_);
}

#define SUBSTITUTE(item, name) {\
    ASTNode *result = item->get ## name (); \
    item->set ##name (0); \
    item->release(); \
    return result; \
}

ASTNode *StaticTyper::optimizePredicate(XQPredicate *item)
{
  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));

  StaticType ciType(BasicMemoryManager::get());
  ciType = item->getExpression()->getStaticAnalysis().getStaticType();
  ciType.setCardinality(1, 1);
  AutoContextItemTypeReset contextTypeReset(context_, ciType);

  item->setPredicate(optimize(const_cast<ASTNode *>(item->getPredicate())));

  return item;
}

ASTNode *StaticTyper::optimizeAnalyzeString(XQAnalyzeString *item)
{
  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));
  item->setRegex(optimize(const_cast<ASTNode *>(item->getRegex())));
  if(item->getFlags())
	  item->setFlags(optimize(const_cast<ASTNode *>(item->getFlags())));

  StaticType ciType(BasicMemoryManager::get());
  ciType = StaticType::STRING;
  AutoContextItemTypeReset contextTypeReset(context_, ciType);

  item->setMatch(optimize(const_cast<ASTNode *>(item->getMatch())));
  item->setNonMatch(optimize(const_cast<ASTNode *>(item->getNonMatch())));
  return item;
}

ASTNode *StaticTyper::optimizeNav(XQNav *item)
{
  AutoContextItemTypeReset contextTypeReset(context_);
  StaticType ciType(BasicMemoryManager::get());

  XQNav::Steps &args = const_cast<XQNav::Steps &>(item->getSteps());
  for(XQNav::Steps::iterator i = args.begin(); i != args.end(); ++i) {
    i->step = optimize(i->step);

    if(context_) {
      ciType = i->step->getStaticAnalysis().getStaticType();
      ciType.setCardinality(1, 1);
      context_->setContextItemType(ciType);
    }
  }

  return item;
}

ASTNode *StaticTyper::optimizeMap(XQMap *item)
{
  item->setArg1(optimize(item->getArg1()));

  AutoContextItemTypeReset contextTypeReset(context_);
  VariableTypeStore* varStore = context_ ? context_->getVariableTypeStore() : 0;

  if(context_) {
    StaticType &varType = item->getVarType();

    varType = item->getArg1()->getStaticAnalysis().getStaticType();
    varType.setCardinality(1, 1);

    if(item->getName() == 0) {
      context_->setContextItemType(varType);
    } else {
      varStore->addLogicalBlockScope();
      VariableType vtype(StaticAnalysis::DOCORDER | StaticAnalysis::GROUPED | StaticAnalysis::PEER | StaticAnalysis::SUBTREE |
                         StaticAnalysis::SAMEDOC | StaticAnalysis::ONENODE | StaticAnalysis::SELF,
                         &varType, 0);
      varStore->declareVar(item->getURI(), item->getName(), vtype);
    }
  }

  item->setArg2(optimize(item->getArg2()));

  if(context_ && item->getName() != 0) {
    varStore->removeScope();
  }

  return item;
}

ASTNode *StaticTyper::optimizeUTransform(UTransform *item)
{
  VariableTypeStore* varStore = context_ ? context_->getVariableTypeStore() : 0;

  VectorOfCopyBinding *bindings = const_cast<VectorOfCopyBinding*>(item->getBindings());
  for(VectorOfCopyBinding::iterator i = bindings->begin(); i != bindings->end(); ++i) {
    (*i)->expr_ = optimize((*i)->expr_);
    (*i)->type_ = (*i)->expr_->getStaticAnalysis().getStaticType();

    // Declare the variable binding
    if(context_) {
      varStore->addLogicalBlockScope();
      varStore->declareVar((*i)->uri_, (*i)->name_,
                           VariableType((*i)->expr_->getStaticAnalysis().getProperties(),
                                        &(*i)->type_, 0));
    }
  }

  item->setModifyExpr(optimize(const_cast<ASTNode *>(item->getModifyExpr())));
  item->setReturnExpr(optimize(const_cast<ASTNode *>(item->getReturnExpr())));

  if(context_) {
    VectorOfCopyBinding::reverse_iterator rend = bindings->rend();
    for(VectorOfCopyBinding::reverse_iterator it = bindings->rbegin(); it != rend; ++it) {
      // Remove our variable binding and the scope we added
      varStore->removeScope();
    }
  }

  return item;
}

static inline void tupleInScope(const TupleNode *item, StaticContext *context)
{
  const StaticType &pType = item->getStaticAnalysis().getStaticType();
  assert(pType.getTypes().size() == 1);

  const ItemType *pItemType = pType.getTypes()[0];
  assert(pItemType->getItemTestType() == ItemType::TEST_TUPLE);

  VariableTypeStore *varStore = context->getVariableTypeStore();
  varStore->addLogicalBlockScope();

  TupleMembers *pMembers = const_cast<TupleMembers*>(pItemType->getTupleMembers());
  if(pMembers) {
    TupleMembers::iterator i = pMembers->begin();
    for(; i != pMembers->end(); ++i) {
      varStore->declareVar(i.getValue()->getURI(), i.getValue()->getName(), i.getValue());
    }
  }
}

ASTNode *StaticTyper::optimizeQuantified(XQQuantified *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

ASTNode *StaticTyper::optimizeReturn(XQReturn *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

void StaticTyper::optimizeCase(const StaticAnalysis &var_src, XQTypeswitch::Case *item)
{
  StaticType caseType(BasicMemoryManager::get());
  if(context_ && item->isVariableUsed()) {
    VariableTypeStore* varStore = context_->getVariableTypeStore();

    caseType = var_src.getStaticType();
    unsigned props = var_src.getProperties();

    if(item->getSequenceType() != 0) {
      StaticType ctype(item->getSequenceType(), BasicMemoryManager::get());
      caseType.typeIntersect(ctype);
    }

    varStore->addLogicalBlockScope();
    varStore->declareVar(item->getURI(), item->getName(), VariableType(props, &caseType, 0));
  }

  item->setExpression(optimize(item->getExpression()));

  if(context_ && item->isVariableUsed()) {
    context_->getVariableTypeStore()->removeScope();
  }
}

ASTNode *StaticTyper::optimizeTypeswitch(XQTypeswitch *item)
{
  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));

  XQTypeswitch::Cases *clauses = const_cast<XQTypeswitch::Cases *>(item->getCases());
  for(XQTypeswitch::Cases::iterator i = clauses->begin(); i != clauses->end(); ++i) {
    optimizeCase(item->getExpression()->getStaticAnalysis(), *i);
  }

  optimizeCase(item->getExpression()->getStaticAnalysis(),
               const_cast<XQTypeswitch::Case *>(item->getDefaultCase()));

  return item;
}

ASTNode *StaticTyper::optimizeFunctionCoercion(XQFunctionCoercion *item)
{
  item->setExpression(optimize(item->getExpression()));

  if(item->getFuncConvert()) {
    if(context_) {
      // Could do better on the static type
      VariableTypeStore *varStore = context_->getVariableTypeStore();
      varStore->addLogicalBlockScope();
      varStore->declareVar(0, XQFunctionCoercion::funcVarName,
                           VariableType(0, &StaticType::FUNCTION, 0));
    }

    {
      AutoMessageListenerReset reset(context_); // Turn off warnings
      item->setFuncConvert(optimize(item->getFuncConvert()));
    }

    if(context_)
      context_->getVariableTypeStore()->removeScope();
  }

  return item;
}

ASTNode *StaticTyper::optimizeNamespaceBinding(XQNamespaceBinding *item)
{
  AutoNsScopeReset jan(context_, item->getNamespaces());

  if(context_) {
    const XMLCh *defaultElementNS = context_->getMemoryManager()->
      getPooledString(item->getNamespaces()->lookupNamespaceURI(XMLUni::fgZeroLenString));
    context_->setDefaultElementAndTypeNS(defaultElementNS);
  }

  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));
  return item;
}

ASTNode *StaticTyper::optimizeInlineFunction(XQInlineFunction *item)
{
  if(item->getUserFunction())
    item->getUserFunction()->staticTyping(context_, this);

  if(context_) {
    VariableTypeStore *varStore = context_->getVariableTypeStore();
    varStore->addLogicalBlockScope();

    if(item->getItemType()->getFunctionSignature()->argSpecs) {
      ArgumentSpecs::const_iterator argsIt = item->getItemType()->getFunctionSignature()->argSpecs->begin();
      for(; argsIt != item->getItemType()->getFunctionSignature()->argSpecs->end(); ++argsIt) {
        varStore->declareVar((*argsIt)->getURI(), (*argsIt)->getName(),
                             VariableType(0, &StaticType::ITEM_STAR, 0));
      }
    }
  }

  {
    // The context item is not defined
    AutoContextItemTypeReset contextTypeReset(context_, StaticType::EMPTY);
    // Turn off warnings
    AutoMessageListenerReset reset(context_);
    item->setInstance(optimize(item->getInstance()));
  }

  if(context_)
    context_->getVariableTypeStore()->removeScope();

  return item;
}

ASTNode *StaticTyper::optimizeEffectiveBooleanValue(XQEffectiveBooleanValue *item)
{
  AutoNodeSetOrderingReset orderReset(context_);
  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));
  return item;
}

ASTNode *StaticTyper::optimizeVariable(XQVariable *item)
{
  if(!context_) return item;

  const VariableType *vtype = context_->getVariableTypeStore()->getVar(item->getURI(), item->getName());
  if(vtype && vtype->global) {
    // See if this is a global variable from one of the imported modules,
    // and if so make sure it's static typed first
    XQQuery *module = context_->getModule()->findModuleForVariable(item->getURI(), item->getName());
    if(module == context_->getModule()) {
      if(globalsUsed_) globalsUsed_->push_back(vtype->global);
    }
    else if(module) {
      AutoReset<StaticContext*> autoReset(context_);
      module->staticTypingOnce(this);
    }
  }
  return item;
}

ASTNode *StaticTyper::optimizeUserFunction(XQUserFunctionInstance *item)
{
  ASTNode *result = ASTVisitor::optimizeUserFunction(item);
  if(result != item || !context_) return result;

  // See if this is a function from one of the imported modules,
  // and if so make sure it's static typed first
  XQQuery *module = context_->getModule()->
    findModuleForFunction(item->getFunctionURI(), item->getFunctionName(), item->getArguments().size());
  if(module && module != context_->getModule()) {
    AutoReset<StaticContext*> autoReset(context_);
    module->staticTypingOnce(this);
  }
  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

ASTNode *StaticTyper::optimizeFTContains(FTContains *item)
{
  item->setArgument(optimize(item->getArgument()));
  item->setSelection(optimizeFTSelection(item->getSelection()));

  if(context_) {
    AutoDelete<DynamicContext> dContext(context_->createDynamicContext());
    dContext->setMemoryManager(context_->getMemoryManager());

    DefaultTokenizer tokenizer;
    FTContext ftcontext(&tokenizer, 0, dContext);
    item->setSelection(item->getSelection()->optimize(&ftcontext));
  }

  if(item->getIgnore())
    item->setIgnore(optimize(item->getIgnore()));
  return item;
}

FTSelection *StaticTyper::optimizeFTSelection(FTSelection *selection)
{
  FTSelection *result = ASTVisitor::optimizeFTSelection(selection);
  if(result != selection) return result;

  return selection->staticTypingImpl(context_);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

TupleNode *StaticTyper::optimizeTupleNode(TupleNode *item)
{
  TupleNode *result = ASTVisitor::optimizeTupleNode(item);
  if(result != item) return result;
  return item->staticTypingImpl(context_);
}

TupleNode *StaticTyper::optimizeForTuple(ForTuple *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

TupleNode *StaticTyper::optimizeLetTuple(LetTuple *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

TupleNode *StaticTyper::optimizeWhereTuple(WhereTuple *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

TupleNode *StaticTyper::optimizeOrderByTuple(OrderByTuple *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  AutoNodeSetOrderingReset orderReset(context_, (item->getModifiers() & OrderByTuple::UNSTABLE) == 0 ?
                                      StaticContext::ORDERING_ORDERED : StaticContext::ORDERING_UNORDERED);
  if(context_) tupleInScope(item->getParent(), context_);
  item->setExpression(optimize(item->getExpression()));
  if(context_) context_->getVariableTypeStore()->removeScope();

  return item;
}

