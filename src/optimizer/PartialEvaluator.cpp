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

#include <xqilla/optimizer/PartialEvaluator.hpp>
#include <xqilla/optimizer/ASTReleaser.hpp>
#include <xqilla/framework/XPath2MemoryManager.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/context/ContextHelpers.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/ast/XQSequence.hpp>
#include <xqilla/exceptions/XQException.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/functions/FunctionCount.hpp>
#include <xqilla/functions/FunctionEmpty.hpp>
#include <xqilla/functions/FunctionFunctionArity.hpp>
#include <xqilla/functions/XQillaFunction.hpp>

#include <xqilla/operators/Plus.hpp>
#include <xqilla/operators/Minus.hpp>
#include <xqilla/operators/Multiply.hpp>
#include <xqilla/operators/Divide.hpp>
#include <xqilla/operators/IntegerDivide.hpp>
#include <xqilla/operators/Mod.hpp>
#include <xqilla/operators/UnaryMinus.hpp>
#include <xqilla/operators/And.hpp>
#include <xqilla/operators/Or.hpp>

#include "../items/impl/FunctionRefImpl.hpp"

#include <set>
#include <map>

XERCES_CPP_NAMESPACE_USE;
using namespace std;

#define FUNCTION_SIZE_RATIO 2
#define BODY_SIZE_RATIO 6

#ifdef _MSC_VER
#include <BaseTsd.h>
#define ssize_t SSIZE_T
#endif

PartialEvaluator::PartialEvaluator(DynamicContext *context, Optimizer *parent)
  : ASTVisitor(parent),
    rules_(0),
    context_(context),
    functionInlineLimit_(0),
    sizeLimit_(0),
    redoTyping_(false)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Remove unused user-defined functions

class FunctionReferenceFinder : public ASTVisitor
{
public:
  const set<XQUserFunction*> &find(XQQuery *query)
  {
    functions_.clear();
    newFunctions_.clear();
    optimize(query);

    set<XQUserFunction*>::iterator i = newFunctions_.begin();
    while(i != newFunctions_.end()) {
      XQUserFunction *uf = *i;

      if(uf->getFunctionBody())
        optimize((ASTNode*)uf->getFunctionBody());

      newFunctions_.erase(uf);
      i = newFunctions_.begin();
    }

    return functions_;
  }

protected:
  using ASTVisitor::optimize;

  virtual void optimize(XQQuery *query)
  {
    if(query->isModuleCacheOwned()) {
      ImportedModules &modules = const_cast<ImportedModules&>(query->getModuleCache()->ordered_);
      for(ImportedModules::iterator it2 = modules.begin(); it2 != modules.end(); ++it2) {
        optimize(*it2);
      }
    }

    GlobalVariables &vars = const_cast<GlobalVariables&>(query->getVariables());
    for(GlobalVariables::iterator it = vars.begin(); it != vars.end(); ++it) {
      (*it) = optimizeGlobalVar(*it);
    }

    // Don't look inside XQUserFunctions
    // But do add all templates to the list of used functions
    UserFunctions &funcs = const_cast<UserFunctions&>(query->getFunctions());
    for(UserFunctions::iterator i2 = funcs.begin(); i2 != funcs.end(); ++i2) {
      if((*i2)->isTemplate() && functions_.insert(*i2).second) {
        newFunctions_.insert(*i2);
        *i2 = optimizeFunctionDef(*i2);
      }
    }

    if(query->getQueryBody() != 0) {
      query->setQueryBody(optimize(query->getQueryBody()));
    }
  }

  virtual ASTNode *optimizeUserFunction(XQUserFunctionInstance *item)
  {
    if(functions_.insert(const_cast<XQUserFunction*>(item->getFunctionDefinition())).second) {
      newFunctions_.insert(const_cast<XQUserFunction*>(item->getFunctionDefinition()));
    }

    return ASTVisitor::optimizeUserFunction(item);
  }

  set<XQUserFunction*> functions_;
  set<XQUserFunction*> newFunctions_;
};

static void removeUnusedFunctions(XQQuery *query, const set<XQUserFunction*> &foundFunctions,
                                  XPath2MemoryManager *mm)
{
    UserFunctions newFuncs = UserFunctions(XQillaAllocator<XQUserFunction*>(mm));
    UserFunctions *funcs = const_cast<UserFunctions*>(&query->getFunctions());
    UserFunctions::iterator funcIt;
    for(funcIt = funcs->begin(); funcIt != funcs->end(); ++funcIt) {
      if(foundFunctions.find(*funcIt) != foundFunctions.end()) {
        newFuncs.push_back(*funcIt);
      }
      else {
        if((*funcIt)->getFunctionBody()) {
          const_cast<ASTNode*>((*funcIt)->getFunctionBody())->release();
        }
        // TBD Free patterns, template instance
        // TBD Remove function from function table! - jpcs
      }
    }
    *funcs = newFuncs;

    if(query->isModuleCacheOwned()) {
      ImportedModules &modules = const_cast<ImportedModules&>(query->getModuleCache()->ordered_);
      for(ImportedModules::iterator it2 = modules.begin(); it2 != modules.end(); ++it2) {
        removeUnusedFunctions(*it2, foundFunctions, mm);
      }
    }
}

class ASTCounter : public ASTVisitor
{
public:

  size_t count(const XQQuery *query)
  {
    count_ = 0;
    ASTVisitor::optimize(const_cast<XQQuery*>(query));
    return count_;
  }

  size_t count(const ASTNode *item)
  {
    count_ = 0;
    optimize(const_cast<ASTNode*>(item));
    return count_;
  }

protected:
  virtual ASTNode *optimize(ASTNode *item)
  {
    if(item == 0) return 0;
    ++count_;
    return ASTVisitor::optimize(item);
  }

  virtual TupleNode *optimizeTupleNode(TupleNode *item)
  {
    if(item == 0) return 0;
    ++count_;
    return ASTVisitor::optimizeTupleNode(item);
  }

  size_t count_;
};

typedef HashMap<int, XQRewriteRule*> RulesMap;
typedef HashMap<XQQuery*, XQQuery*> SeenModuleSet;

static void addRewriteRules(XQQuery *module, RulesMap &rulesMap, SeenModuleSet &modulesSeen)
{
  if(modulesSeen.contains(module)) return;
  modulesSeen.put(module, module);

  RewriteRules &rules = const_cast<RewriteRules&>(module->getRewriteRules());
  for(RewriteRules::iterator it3 = rules.begin(); it3 != rules.end(); ++it3) {
    vector<ASTNode::whichType> types;
    (*it3)->getPattern()->typesMatched(types);
    for(vector<ASTNode::whichType>::iterator i = types.begin(); i != types.end(); ++i) {
      rulesMap.add(*i, *it3);
    }
  }

  ImportedModules &modules = const_cast<ImportedModules&>(module->getImportedModules());
  for(ImportedModules::iterator it2 = modules.begin(); it2 != modules.end(); ++it2) {
    addRewriteRules(*it2, rulesMap, modulesSeen);
  }
}

void PartialEvaluator::optimize(XQQuery *query)
{
  AutoReset<RulesMap*> reset(rules_);

  redoTyping_ = false;

  // Construct the rewrite rules map for this module
  RulesMap rules(true, context_->getMemoryManager());
  {
    SeenModuleSet modulesSeen(true, context_->getMemoryManager());
    addRewriteRules(query, rules, modulesSeen);
  }
  rules_ = &rules;

  if(query->getQueryBody() == 0) {
    ASTVisitor::optimize(query);
    return;
  }

  // Calculate a size limit on the partially evaluated AST
  sizeLimit_ = ASTCounter().count(query) * BODY_SIZE_RATIO;

  // Also limit the recursive depth we're willing to evaluate to
  // TBD Implement a breadth first function inlining algorithm - jpcs
  functionInlineLimit_ = 100;

  // Perform partial evaluation
  ASTVisitor::optimize(query);

  // Find and remove all the unused user defined functions
  removeUnusedFunctions(query, FunctionReferenceFinder().find(query),
                        context_->getMemoryManager());
}

XQRewriteRule *PartialEvaluator::optimizeRewriteRule(XQRewriteRule *item)
{
  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constant fold

bool PartialEvaluator::checkSizeLimit(const ASTNode *oldAST, const ASTNode *newAST)
{
  size_t oldSize = ASTCounter().count(oldAST);
  size_t newSize = ASTCounter().count(newAST);
  if((sizeLimit_ + oldSize) < newSize)
    return false;
  sizeLimit_ += oldSize;
  sizeLimit_ -= newSize;
  return true;
}

ASTNode *PartialEvaluator::optimize(ASTNode *item)
{
  // Apply rewrite rules
  if(rules_) {
    RulesMap::iterator i = rules_->find(item->getType());
    for(; i != rules_->end(); ++i) {
      ASTNode *apply = i.getValue()->apply(item, context_);
      if(apply) {
        redoTyping_ = true;
        apply = optimize(apply);
        item->release();
        return apply;
      }
    }
  }

  bool retype;
  {
    AutoReset<bool> reset(redoTyping_);
    redoTyping_ = false;

    item = ASTVisitor::optimize(item);

    retype = redoTyping_;
  }

  if(retype) {
    item = item->staticTypingImpl(0);
    redoTyping_ = true;
  }

  // Constant fold
  switch(item->getType()) {
  case ASTNode::SEQUENCE:
  case ASTNode::LITERAL:
  case ASTNode::NUMERIC_LITERAL:
  case ASTNode::QNAME_LITERAL:
    break;
  default:
    if(!item->getStaticAnalysis().isUsed() &&
       !item->getStaticAnalysis().getStaticType().isType(TypeFlags::NODE) &&
       !item->getStaticAnalysis().getStaticType().isType(TypeFlags::FUNCTION)) {
      XPath2MemoryManager* mm = context_->getMemoryManager();

      try {
        ASTNode *newBlock = 0;
        {
          Result result = item->createResult(context_);
          newBlock = XQSequence::constantFold(result, context_, mm, item);
        }

        context_->clearDynamicContext();

        if(newBlock != 0) {
          if(checkSizeLimit(item, newBlock)) {
            item->release();
            return newBlock->staticResolution(context_)->staticTypingImpl(context_);
          }
          else {
            newBlock->release();
            return item;
          }
        }
      }
      catch(XQException &ex) {
        // Constant folding failed
      }
    }
    break;
  }

  // Apply rewrite rules
  if(rules_) {
    RulesMap::iterator i = rules_->find(item->getType());
    for(; i != rules_->end(); ++i) {
      ASTNode *apply = i.getValue()->apply(item, context_);
      if(apply) {
        redoTyping_ = true;
        apply = optimize(apply);
        item->release();
        return apply;
      }
    }
  }

  return item;
}

ASTNode *PartialEvaluator::optimizeNamespaceBinding(XQNamespaceBinding *item)
{
  // Make sure the correct namespaces are in scope for sub-expressions that are constant folded
  AutoNsScopeReset jan(context_, item->getNamespaces());

  if(context_) {
    const XMLCh *defaultElementNS = context_->getMemoryManager()->
      getPooledString(item->getNamespaces()->lookupNamespaceURI(XMLUni::fgZeroLenString));
    context_->setDefaultElementAndTypeNS(defaultElementNS);
  }

  item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));
  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Inline user-defined functions

// Base class that tracks variable scope
class VariableScopeTracker : public ASTVisitor
{
public:
  VariableScopeTracker()
    : uri_(0),
      name_(0),
      required_(0),
      active_(false),
      inScope_(true)
  {
  }

protected:
  ASTNode *run(const XMLCh *uri, const XMLCh *name, ASTNode *expr, const StaticAnalysis *required = 0)
  {
    uri_ = uri;
    name_ = name;
    required_ = required;
    active_ = true;
    inScope_ = true;

    return optimize(expr);
  }

  virtual TupleNode *optimizeForTuple(ForTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));
    item->setExpression(optimize(item->getExpression()));

    if(required_ && required_->isVariableUsed(item->getVarURI(), item->getVarName()))
      inScope_ = false;

    if(XPath2Utils::equals(uri_, item->getVarURI()) &&
       XPath2Utils::equals(name_, item->getVarName()))
      active_ = false;

    if(required_ && required_->isVariableUsed(item->getPosURI(), item->getPosName()))
      inScope_ = false;

    if(XPath2Utils::equals(uri_, item->getPosURI()) &&
       XPath2Utils::equals(name_, item->getPosName()))
      active_ = false;

    return item;
  }

  virtual TupleNode *optimizeLetTuple(LetTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));
    item->setExpression(optimize(item->getExpression()));

    if(required_ && required_->isVariableUsed(item->getVarURI(), item->getVarName()))
      inScope_ = false;

    if(XPath2Utils::equals(uri_, item->getVarURI()) &&
       XPath2Utils::equals(name_, item->getVarName()))
      active_ = false;

    return item;
  }

  virtual TupleNode *optimizeCountTuple(CountTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    if(required_ && required_->isVariableUsed(item->getVarURI(), item->getVarName()))
      inScope_ = false;

    if(XPath2Utils::equals(uri_, item->getVarURI()) &&
       XPath2Utils::equals(name_, item->getVarName()))
      active_ = false;

    return item;
  }

  virtual ASTNode *optimizeReturn(XQReturn *item)
  {
    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);
    return ASTVisitor::optimizeReturn(item);
  }

  virtual ASTNode *optimizeMap(XQMap *item)
  {
    item->setArg1(optimize(item->getArg1()));

    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);

    if(item->getName()) {
      if(required_ && required_->isVariableUsed(item->getURI(), item->getName()))
        inScope_ = false;

      if(XPath2Utils::equals(uri_, item->getURI()) &&
         XPath2Utils::equals(name_, item->getName()))
        active_ = false;
    }
    else {
      if(required_ && required_->areContextFlagsUsed())
        inScope_ = false;

      if(name_ == 0)
        active_ = false;
    }

    item->setArg2(optimize(item->getArg2()));
    return item;
  }

  virtual ASTNode *optimizeTypeswitch(XQTypeswitch *item)
  {
    item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));

    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);

    XQTypeswitch::Cases *clauses = const_cast<XQTypeswitch::Cases *>(item->getCases());
    for(XQTypeswitch::Cases::iterator i = clauses->begin(); i != clauses->end(); ++i) {
      reset.reset();
      reset2.reset();

      if((*i)->isVariableUsed()) {
        if(required_ && required_->isVariableUsed((*i)->getURI(), (*i)->getName()))
          inScope_ = false;

        if(XPath2Utils::equals(uri_, (*i)->getURI()) &&
           XPath2Utils::equals(name_, (*i)->getName()))
          active_ = false;
      }

      (*i)->setExpression(optimize((*i)->getExpression()));
    }

    reset.reset();
    reset2.reset();

    if(item->getDefaultCase()->isVariableUsed()) {
      if(required_ && required_->isVariableUsed(item->getDefaultCase()->getURI(), item->getDefaultCase()->getName()))
        inScope_ = false;

      if(XPath2Utils::equals(uri_, item->getDefaultCase()->getURI()) &&
         XPath2Utils::equals(name_, item->getDefaultCase()->getName()))
        active_ = false;
    }

    const_cast<XQTypeswitch::Case *>(item->getDefaultCase())->
      setExpression(optimize(item->getDefaultCase()->getExpression()));

    return item;
  }

  virtual ASTNode *optimizeNav(XQNav *item)
  {
    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);

    XQNav::Steps &args = const_cast<XQNav::Steps &>(item->getSteps());
    for(XQNav::Steps::iterator i = args.begin(); i != args.end(); ++i) {
      i->step = optimize(i->step);

      if(required_ && required_->areContextFlagsUsed())
        inScope_ = false;

      if(name_ == 0)
        active_ = false;
    }
    return item;
  }

  virtual ASTNode *optimizePredicate(XQPredicate *item)
  {
    item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));

    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);
    if(required_ && required_->areContextFlagsUsed())
      inScope_ = false;
    if(name_ == 0)
      active_ = false;

    item->setPredicate(optimize(const_cast<ASTNode *>(item->getPredicate())));
    return item;
  }

  virtual ASTNode *optimizeAnalyzeString(XQAnalyzeString *item)
  {
    item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));
    item->setRegex(optimize(const_cast<ASTNode *>(item->getRegex())));
    if(item->getFlags())
      item->setFlags(optimize(const_cast<ASTNode *>(item->getFlags())));

    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);
    if(required_ && required_->areContextFlagsUsed())
      inScope_ = false;
    if(name_ == 0)
      active_ = false;

    item->setMatch(optimize(const_cast<ASTNode *>(item->getMatch())));
    item->setNonMatch(optimize(const_cast<ASTNode *>(item->getNonMatch())));
    return item;
  }

  virtual ASTNode *optimizeUTransform(UTransform *item)
  {
    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);

    VectorOfCopyBinding *bindings = const_cast<VectorOfCopyBinding*>(item->getBindings());
    for(VectorOfCopyBinding::iterator i = bindings->begin(); i != bindings->end(); ++i) {
      (*i)->expr_ = optimize((*i)->expr_);

      if(required_ && required_->isVariableUsed((*i)->uri_, (*i)->name_))
        inScope_ = false;

      if(XPath2Utils::equals(uri_, (*i)->uri_) &&
         XPath2Utils::equals(name_, (*i)->name_))
        active_ = false;
    }

    item->setModifyExpr(optimize(const_cast<ASTNode *>(item->getModifyExpr())));
    item->setReturnExpr(optimize(const_cast<ASTNode *>(item->getReturnExpr())));

    return item;
  }

  virtual ASTNode *optimizeFunctionCoercion(XQFunctionCoercion *item)
  {
    item->setExpression(optimize(item->getExpression()));

    if(item->getFuncConvert()) {
      AutoReset<bool> reset(active_);
      AutoReset<bool> reset2(inScope_);

      if(required_ && required_->isVariableUsed(0, XQFunctionCoercion::funcVarName))
        inScope_ = false;

      if(XPath2Utils::equals(uri_, 0) &&
         XPath2Utils::equals(name_, XQFunctionCoercion::funcVarName))
        active_ = false;

      item->setFuncConvert(optimize(item->getFuncConvert()));
    }

    return item;
  }

  virtual ASTNode *optimizeInlineFunction(XQInlineFunction *item)
  {
    if(item->getUserFunction())
      item->setUserFunction(optimizeFunctionDef(item->getUserFunction()));

    AutoReset<bool> reset(active_);
    AutoReset<bool> reset2(inScope_);

    if(item->getItemType()->getFunctionSignature()->argSpecs) {
      ArgumentSpecs::const_iterator argsIt = item->getItemType()->getFunctionSignature()->argSpecs->begin();
      for(; argsIt != item->getItemType()->getFunctionSignature()->argSpecs->end(); ++argsIt) {
        if(required_ && required_->isVariableUsed((*argsIt)->getURI(), (*argsIt)->getName()))
          inScope_ = false;

        if(XPath2Utils::equals(uri_, (*argsIt)->getURI()) &&
           XPath2Utils::equals(name_, (*argsIt)->getName()))
          active_ = false;
      }
    }

    item->setInstance(optimize(item->getInstance()));

    return item;
  }

  virtual XQUserFunction *optimizeFunctionDef(XQUserFunction *item)
  {
    if(item->getFunctionBody()) {
      AutoReset<bool> reset(active_);
      AutoReset<bool> reset2(inScope_);

      const ArgumentSpecs *params = item->getSignature()->argSpecs;
      if(params) {
        for(ArgumentSpecs::const_iterator it = params->begin();
            it != params->end(); ++it) {

          if(required_ && required_->isVariableUsed((*it)->getURI(), (*it)->getName()))
            inScope_ = false;

          if(XPath2Utils::equals(uri_, (*it)->getURI()) &&
             XPath2Utils::equals(name_, (*it)->getName()))
            active_ = false;
        }
      }

      item->setFunctionBody(optimize(const_cast<ASTNode*>(item->getFunctionBody())));
    }
    return item;
  }

  const XMLCh *uri_, *name_;
  const StaticAnalysis *required_;
  bool active_, inScope_;
};

class InlineVar : public VariableScopeTracker
{
public:
  InlineVar()
    : let_(0),
      removeLet_(false),
      dummyRun_(true),
      varValue_(0),
      context_(0),
      successful_(false),
      doesSomething_(false),
      count_(0)
  {
  }

  ASTNode *run(const XMLCh *uri, const XMLCh *name, const ASTNode *varValue, ASTNode *expr, DynamicContext *context)
  {
    let_ = 0;
    varValue_ = varValue;
    context_ = context;
    removeLet_ = false;
    dummyRun_ = false;

    return VariableScopeTracker::run(uri, name, expr, &varValue->getStaticAnalysis());
  }

  bool inlineLet(XQReturn *ret, LetTuple *let, DynamicContext *context, size_t &sizeLimit)
  {
    let_ = let;
    context_ = context;
    varValue_ = let->getExpression();

    // Do a dummy run, to see if we would be 100% successful
    dummyRun_ = true;
    successful_ = true;
    doesSomething_ = false;
    count_ = 0;
    VariableScopeTracker::run(let->getVarURI(), let->getVarName(), ret, &let->getExpression()->getStaticAnalysis());

    if(!doesSomething_) return false;

    removeLet_ = successful_;

    if(let->getExpression()->getStaticAnalysis().isVariableUsed(let->getVarURI(), let->getVarName())) {
      // The LetTuple expression uses a variable with the same name as the LetTuple itself.
      // We can only inline it if the inline will be 100% successful, and we can remove the
      // LetTuple itself.
      if(!removeLet_) return false;
    }

    if(removeLet_)
      count_ -= ASTCounter().count(let->getExpression()) + 1;

    // Check that we won't exceed the size limit
    if(count_ > 0 && (size_t)count_ > sizeLimit) return false;

    sizeLimit -= count_;

    // Perform the actual substitution
    dummyRun_ = false;
    VariableScopeTracker::run(let->getVarURI(), let->getVarName(), ret, &let->getExpression()->getStaticAnalysis());

    if(removeLet_) {
      let->setParent(0);
      let->release();
    }

    return true;
  }

protected:

  virtual TupleNode *optimizeLetTuple(LetTuple *item)
  {
    if(item != let_)
      return VariableScopeTracker::optimizeLetTuple(item);

    if(!dummyRun_ && removeLet_) {
      // Remove the LetTuple itself - we checked this was ok to do in inlineLet() above
      return item->getParent();
    }

    return item;
  }

  virtual ASTNode *optimizeVariable(XQVariable *item)
  {
    if(active_ &&
       XPath2Utils::equals(item->getName(), name_) &&
       XPath2Utils::equals(item->getURI(), uri_)) {
      if(inScope_) {
        if(dummyRun_) {
          // Mock up the extra size required to make this change
          count_ -= 1;
          count_ += ASTCounter().count(varValue_);
          doesSomething_ = true;
        }
        else {
          item->release();
          return varValue_->copy(context_);
        }
      }
      else {
        successful_ = false;
      }
    }
    return item;
  }

  LetTuple *let_;
  bool removeLet_;
  bool dummyRun_;

  const ASTNode *varValue_;
  DynamicContext *context_;

  bool successful_;
  bool doesSomething_;
  ssize_t count_;
};

XQUserFunction *PartialEvaluator::optimizeFunctionDef(XQUserFunction *item)
{
  AutoReset<size_t> reset(sizeLimit_);
  // TBD Maybe make this related to the number of times the function is called as well? - jpcs
  sizeLimit_ = ASTCounter().count(item->getFunctionBody()) * FUNCTION_SIZE_RATIO;
  return ASTVisitor::optimizeFunctionDef(item);
}

ASTNode *PartialEvaluator::inlineFunction(const XQUserFunctionInstance *item, DynamicContext *context)
{
  const XQUserFunction *funcDef = item->getFunctionDefinition();

  XPath2MemoryManager *mm = context->getMemoryManager();
  TupleNode *tuple = new (mm) ContextTuple(mm);
  tuple->setLocationInfo(item);

  ASTNode *bodyCopy = funcDef->getFunctionBody()->copy(context);
  InlineVar inliner;

  if(!item->getArguments().empty()) {
    ArgumentSpecs::const_iterator defIt = funcDef->getSignature()->argSpecs->begin();
    VectorOfASTNodes::const_iterator argIt = item->getArguments().begin();
    for(; defIt != funcDef->getSignature()->argSpecs->end() && argIt != item->getArguments().end(); ++defIt, ++argIt) {
      // Rename the variable to avoid naming conflicts
      const XMLCh *newName = context->allocateTempVarName((*defIt)->getName());

      tuple = new (mm) LetTuple(tuple, (*defIt)->getURI(), newName, (*argIt)->copy(context), mm);
      tuple->setLocationInfo(item);

      AutoRelease<ASTNode> newVar(new (mm) XQVariable((*defIt)->getURI(), newName, mm));
      newVar->setLocationInfo(*argIt);
      StaticAnalysis &varSrc = const_cast<StaticAnalysis&>(newVar->getStaticAnalysis());
      varSrc.getStaticType() = (*argIt)->getStaticAnalysis().getStaticType();
      varSrc.setProperties((*argIt)->getStaticAnalysis().getProperties() & ~(StaticAnalysis::SUBTREE|StaticAnalysis::SAMEDOC));
      varSrc.variableUsed((*defIt)->getURI(), newName);

      bodyCopy = inliner.run((*defIt)->getURI(), (*defIt)->getName(), newVar, bodyCopy, context);
    }
  }

  ASTNode *result = new (mm) XQReturn(tuple, bodyCopy, mm);
  result->setLocationInfo(item);
  const_cast<StaticAnalysis&>(result->getStaticAnalysis()).copy(funcDef->getBodyStaticAnalysis());

  if(!item->getArguments().empty()) {
    VectorOfASTNodes::const_iterator argIt = item->getArguments().begin();
    for(; argIt != item->getArguments().end(); ++argIt) {
      const_cast<StaticAnalysis&>(result->getStaticAnalysis()).add((*argIt)->getStaticAnalysis());
    }
  }

  return result;
}

static const XMLCh s_inline[] = { 'i', 'n', 'l', 'i', 'n', 'e', 0 };
static const XMLCh s_inline_if_constant[] = { 'i', 'n', 'l', 'i', 'n', 'e', '-', 'i', 'f', '-',
  'c', 'o', 'n', 's', 't', 'a', 'n', 't', 0 };

ASTNode *PartialEvaluator::optimizeUserFunction(XQUserFunctionInstance *item)
{
  VectorOfASTNodes &args = const_cast<VectorOfASTNodes &>(item->getArguments());
  VectorOfASTNodes::iterator i;
  for(i = args.begin(); i != args.end(); ++i) {
    *i = optimize(*i);
  }

  const XQUserFunction *funcDef = item->getFunctionDefinition();

  // TBD Maybe make this dependant on the number of times the function is called in the query as well? - jpcs
  if(funcDef->getFunctionBody()) {
    // %inline annotation
    XMLBuffer buf;
    XPath2NSUtils::makeURIName(XQillaFunction::XMLChFunctionURI, s_inline, buf);
    if(funcDef->getSignature()->annotationMap.contains(buf.getRawBuffer())) {
      // std::cerr << "%inline - " << UTF8(funcDef->getURIName()) << "#" << args.size() << "\n";
      ASTNode *result = inlineFunction(item, context_);
      redoTyping_ = true;
      result = optimize(result->staticTyping(0, 0));
      item->release();
      return result;
    }

    // %inline-if-constant(arg1, ....) annotation
    buf.reset();
    XPath2NSUtils::makeURIName(XQillaFunction::XMLChFunctionURI, s_inline_if_constant, buf);
    Annotation* const *annotation = funcDef->getSignature()->annotationMap.get(buf.getRawBuffer());
    if(annotation && funcDef->getSignature()->argSpecs) {
      bool constantArgs = true;
      Result result = (*annotation)->getExpression()->createResult(context_);
      Item::Ptr value;
      while(constantArgs && (value = result->next(context_)).notNull()) {
        value = ((AnyAtomicType*)value.get())->castAs(AnyAtomicType::QNAME, context_);
        ArgumentSpecs::const_iterator specIt = funcDef->getSignature()->argSpecs->begin();
        for(i = args.begin(); i != args.end(); ++i, ++specIt) {
          if(XPath2Utils::equals((*specIt)->getName(), ((ATQNameOrDerived*)value.get())->getName()) &&
             XPath2Utils::equals((*specIt)->getURI(), ((ATQNameOrDerived*)value.get())->getURI())) {
            constantArgs = constantArgs && (*i)->isConstant();
            break;
          }
        }
        if(i == args.end()) constantArgs = false;
      }
      if(constantArgs) {
        // std::cerr << "%inline-if-constant - " << UTF8(funcDef->getURIName()) << "#" << args.size() << "\n";
        ASTNode *result = inlineFunction(item, context_);
        redoTyping_ = true;
        result = optimize(result->staticTyping(0, 0));
        item->release();
        return result;
      }
    }

    if(functionInlineLimit_ > 0 && !funcDef->isRecursive()) {
      AutoReset<size_t> reset(functionInlineLimit_);
      --functionInlineLimit_;

      ASTNode *result = inlineFunction(item, context_);

      if(checkSizeLimit(item, result)) {
        redoTyping_ = true;
        result = optimize(result->staticTyping(0, 0));
        item->release();
        return result;
      }
      else {
        result->release();
        return item;
      }
    }
  }

  return item;
}

ASTNode *PartialEvaluator::optimizeInlineFunction(XQInlineFunction *item)
{
  if(item->getUserFunction() && item->getInstance()->getType() == ASTNode::USER_FUNCTION) {
    ASTNode *result = inlineFunction((XQUserFunctionInstance*)item->getInstance(), context_);
    ASTReleaser().release(item->getUserFunction());
    item->getInstance()->release();
    item->setUserFunction(0);
    redoTyping_ = true;
    item->setInstance(result->staticTyping(0, 0));
  }
  item->setInstance(optimize(item->getInstance()));
  return item;
}

ASTNode *PartialEvaluator::optimizeFunctionDeref(XQFunctionDeref *item)
{
  ASTVisitor::optimizeFunctionDeref(item);

  if(item->getExpression()->getType() != ASTNode::INLINE_FUNCTION || functionInlineLimit_ <= 0)
    return item;

  XQInlineFunction *func = (XQInlineFunction*)item->getExpression();

  VectorOfASTNodes *args = const_cast<VectorOfASTNodes*>(item->getArguments());
  size_t numGiven = args ? args->size() : 0;
  if(func->getNumArgs() != numGiven)
    return item;

  AutoReset<size_t> reset(functionInlineLimit_);
  --functionInlineLimit_;

  XPath2MemoryManager *mm = context_->getMemoryManager();
  TupleNode *tuple = new (mm) ContextTuple(mm);
  tuple->setLocationInfo(item);

  ASTNode *bodyCopy = func->getInstance()->copy(context_);
  InlineVar inliner;

  if(args && func->getItemType()->getFunctionSignature()->argSpecs) {
    ArgumentSpecs::const_iterator specIt = func->getItemType()->getFunctionSignature()->argSpecs->begin();
    for(VectorOfASTNodes::iterator argIt = args->begin(); argIt != args->end(); ++argIt, ++specIt) {
      // Rename the variable to avoid naming conflicts
      const XMLCh *newName = context_->allocateTempVarName(X("inline_arg"));

      tuple = new (mm) LetTuple(tuple, 0, newName, (*argIt)->copy(context_), mm);
      tuple->setLocationInfo(item);

      AutoRelease<ASTNode> newVar(new (mm) XQVariable(0, newName, mm));
      newVar->setLocationInfo(*argIt);
      StaticAnalysis &varSrc = const_cast<StaticAnalysis&>(newVar->getStaticAnalysis());
      varSrc.getStaticType() = (*argIt)->getStaticAnalysis().getStaticType();
      varSrc.setProperties((*argIt)->getStaticAnalysis().getProperties() & ~(StaticAnalysis::SUBTREE|StaticAnalysis::SAMEDOC));
      varSrc.variableUsed(0, newName);

      bodyCopy = inliner.run((*specIt)->getURI(), (*specIt)->getName(), newVar, bodyCopy, context_);
    }
  }

  ASTNode *result = new (mm) XQReturn(tuple, bodyCopy, mm);
  result->setLocationInfo(item);

  if(checkSizeLimit(item, result)) {
    redoTyping_ = true;
    result = optimize(result->staticTyping(0, 0));
    item->release();
    return result;
  }
  else {
    result->release();
    return item;
  }
}

ASTNode *PartialEvaluator::optimizePartialApply(XQPartialApply *item)
{
  ASTVisitor::optimizePartialApply(item);

  if(item->getExpression()->getType() != ASTNode::INLINE_FUNCTION || functionInlineLimit_ <= 0)
    return item;

  XQInlineFunction *func = (XQInlineFunction*)item->getExpression();

  VectorOfASTNodes *args = const_cast<VectorOfASTNodes*>(item->getArguments());
  size_t numGiven = args ? args->size() : 0;
  if(func->getNumArgs() != numGiven)
    return item;

  AutoReset<size_t> reset(functionInlineLimit_);
  --functionInlineLimit_;

  XPath2MemoryManager *mm = context_->getMemoryManager();
  TupleNode *tuple = new (mm) ContextTuple(mm);
  tuple->setLocationInfo(item);

  ASTNode *bodyCopy = func->getInstance()->copy(context_);
  InlineVar inliner;

  FunctionSignature *signature = new (mm) FunctionSignature(func->getItemType()->getFunctionSignature(), mm);

  if(args && signature->argSpecs) {
    ArgumentSpecs::iterator specIt = signature->argSpecs->begin();
    for(VectorOfASTNodes::iterator argIt = args->begin(); argIt != args->end(); ++argIt) {
      if(*argIt == 0) {
        ++specIt;
        continue;
      }

      // Rename the variable to avoid naming conflicts
      const XMLCh *newName = context_->allocateTempVarName(X("inline_arg"));

      tuple = new (mm) LetTuple(tuple, 0, newName, (*argIt)->copy(context_), mm);
      tuple->setLocationInfo(item);

      AutoRelease<ASTNode> newVar(new (mm) XQVariable(0, newName, mm));
      newVar->setLocationInfo(*argIt);
      StaticAnalysis &varSrc = const_cast<StaticAnalysis&>(newVar->getStaticAnalysis());
      varSrc.getStaticType() = (*argIt)->getStaticAnalysis().getStaticType();
      varSrc.setProperties((*argIt)->getStaticAnalysis().getProperties() & ~(StaticAnalysis::SUBTREE|StaticAnalysis::SAMEDOC));
      varSrc.variableUsed(0, newName);

      bodyCopy = inliner.run((*specIt)->getURI(), (*specIt)->getName(), newVar, bodyCopy, context_);

      specIt = signature->argSpecs->erase(specIt);
    }
  }

  ASTNode *ret = new (mm) XQReturn(tuple, bodyCopy, mm);
  ret->setLocationInfo(item);

  ASTNode *result = new (mm) XQInlineFunction(0, func->getPrefix(), func->getURI(), func->getName(),
    new (mm) ItemType(signature, context_->getDocumentCache()), ret, mm);
  result->setLocationInfo(item);

  if(checkSizeLimit(item, result)) {
    redoTyping_ = true;
    result = optimize(result->staticTyping(0, 0));
    item->release();
    return result;
  }
  else {
    result->release();
    return item;
  }
}

static inline FunctionSignature *findSignature(ASTNode *expr)
{
  FunctionSignature *signature = 0;

  switch(expr->getType()) {
  case ASTNode::INLINE_FUNCTION: {
    signature = ((XQInlineFunction*)expr)->getItemType()->getFunctionSignature();
    break;
  }
  case ASTNode::FUNCTION_COERCION: {
    XQFunctionCoercion *coercion = (XQFunctionCoercion*)expr;
    if(coercion->getFuncConvert()->getType() == ASTNode::INLINE_FUNCTION)
      signature = ((XQInlineFunction*)coercion->getFuncConvert())->getItemType()->getFunctionSignature();
    break;
  }
  default: break;
  }

  return signature;
}

ASTNode *PartialEvaluator::optimizeFunctionCoercion(XQFunctionCoercion *item)
{
  ASTVisitor::optimizeFunctionCoercion(item);

  FunctionSignature *signature = findSignature(item->getExpression());
  if(signature && item->getSequenceType()->getItemType()->matches(signature)) {
    ASTNode *result = item->getExpression();
    item->setExpression(0);
    sizeLimit_ += ASTCounter().count(item);
    item->release();
    return result;
  }

  if(item->getExpression()->getType() != ASTNode::INLINE_FUNCTION || functionInlineLimit_ <= 0)
    return item;

  XQInlineFunction *func = (XQInlineFunction*)item->getExpression();

  AutoReset<size_t> reset(functionInlineLimit_);
  --functionInlineLimit_;

  ASTNode *result = item->getFuncConvert()->copy(context_);
  result = InlineVar().run(0, XQFunctionCoercion::funcVarName, func->copy(context_), result, context_);

  if(checkSizeLimit(item, result)) {
    redoTyping_ = true;
    result = optimize(result->staticTyping(0, 0));
    item->release();
    return result;
  }
  else {
    result->release();
    return item;
  }
}

ASTNode *PartialEvaluator::optimizeTreatAs(XQTreatAs *item)
{
  ASTVisitor::optimizeTreatAs(item);

  const ItemType *itemType = item->getSequenceType()->getItemType();
  if(!itemType) return item;

  FunctionSignature *signature = findSignature(item->getExpression());
  if(signature && itemType->matches(signature)) {
    ASTNode *result = item->getExpression();
    item->setExpression(0);
    sizeLimit_ += ASTCounter().count(item);
    item->release();
    return result;
  }

  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Inline variables

static inline unsigned int umultiply(unsigned int a, unsigned int b)
{
  return (a == 0 || b == 0) ? 0 :
    (a == StaticType::UNLIMITED || b == StaticType::UNLIMITED) ? StaticType::UNLIMITED :
    a * b;
}

static inline unsigned int uadd(unsigned int a, unsigned int b)
{
  return (a == StaticType::UNLIMITED || b == StaticType::UNLIMITED) ? StaticType::UNLIMITED :
    a + b;
}

class CountVarUse : public VariableScopeTracker
{
public:
  CountVarUse()
    : count_(0)
  {
  }

  unsigned int run(const XMLCh *uri, const XMLCh *name, const ASTNode *expr)
  {
    count_ = 0;
    VariableScopeTracker::run(uri, name, (ASTNode*)expr);
    return count_;
  }

protected:
  virtual ASTNode *optimizeNav(XQNav *item)
  {
    unsigned int factor = 1;

    XQNav::Steps &args = const_cast<XQNav::Steps &>(item->getSteps());
    for(XQNav::Steps::iterator i = args.begin(); i != args.end(); ++i) {
      unsigned int tcount = count_;
      count_ = 0;

      i->step = optimize(i->step);

      count_ = uadd(tcount, umultiply(count_, factor));
      factor = umultiply(factor, i->step->getStaticAnalysis()
                         .getStaticType().getMax());
    }
    return item;
  }

  virtual ASTNode *optimizePredicate(XQPredicate *item)
  {
    item->setExpression(optimize(const_cast<ASTNode *>(item->getExpression())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setPredicate(optimize(const_cast<ASTNode *>(item->getPredicate())));

    count_ = uadd(tcount, umultiply(count_, item->getExpression()->
                                    getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual ASTNode *optimizeMap(XQMap *item)
  {
    item->setArg1(optimize(item->getArg1()));

    unsigned int tcount = count_;
    count_ = 0;

    item->setArg2(optimize(item->getArg2()));

    count_ = uadd(tcount, umultiply(count_, item->getArg1()->
                                    getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual TupleNode *optimizeForTuple(ForTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual TupleNode *optimizeLetTuple(LetTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual TupleNode *optimizeCountTuple(CountTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual TupleNode *optimizeWhereTuple(WhereTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual TupleNode *optimizeOrderByTuple(OrderByTuple *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual ASTNode *optimizeReturn(XQReturn *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual ASTNode *optimizeTupleConstructor(XQTupleConstructor *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));
    return item;
  }

  virtual ASTNode *optimizeQuantified(XQQuantified *item)
  {
    item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

    unsigned int tcount = count_;
    count_ = 0;

    item->setExpression(optimize(item->getExpression()));

    count_ = uadd(tcount, umultiply(count_, item->getParent()->getStaticAnalysis().getStaticType().getMax()));

    return item;
  }

  virtual ASTNode *optimizeVariable(XQVariable *item)
  {
    if(active_ &&
       XPath2Utils::equals(item->getName(), name_) &&
       XPath2Utils::equals(item->getURI(), uri_)) {
      count_ = uadd(count_, 1);
    }
    return item;
  }

  unsigned int count_;
};

static void countLetUsage(ASTNode *expr, map<LetTuple*, unsigned int> &toCount, unsigned int factor)
{
  CountVarUse counter;
  map<LetTuple*, unsigned int>::iterator j = toCount.begin();
  for(; j != toCount.end(); ++j) {
    unsigned int ecount = counter.run(j->first->getVarURI(), j->first->getVarName(), expr);
    j->second = uadd(j->second, umultiply(factor, ecount));
  }
}

static void findLetsToInline(TupleNode *ancestor, vector<LetTuple*> &toInline, map<LetTuple*, unsigned int> &toCount)
{
  if(ancestor == 0) return;

  switch(ancestor->getType()) {
  case TupleNode::LET: {
    findLetsToInline(ancestor->getParent(), toInline, toCount);

    LetTuple *f = (LetTuple*)ancestor;

    countLetUsage(f->getExpression(), toCount,
                  ancestor->getParent()->getStaticAnalysis().getStaticType().getMax());

    if(f->getExpression()->isConstant() ||
       f->getExpression()->getType() == ASTNode::VARIABLE ||
       f->getExpression()->getType() == ASTNode::CONTEXT_ITEM) {
      toInline.push_back(f);
    }
    else {
      toCount[f] = 0;
    }
    break;
  }
  case TupleNode::WHERE:
    findLetsToInline(ancestor->getParent(), toInline, toCount);
    countLetUsage(((WhereTuple*)ancestor)->getExpression(), toCount,
                  ancestor->getParent()->getStaticAnalysis().getStaticType().getMax());
    break;
  case TupleNode::ORDER_BY:
    findLetsToInline(ancestor->getParent(), toInline, toCount);
    countLetUsage(((OrderByTuple*)ancestor)->getExpression(), toCount,
                  ancestor->getParent()->getStaticAnalysis().getStaticType().getMax());
    break;
  case TupleNode::FOR:
    findLetsToInline(ancestor->getParent(), toInline, toCount);
    countLetUsage(((ForTuple*)ancestor)->getExpression(), toCount,
                  ancestor->getParent()->getStaticAnalysis().getStaticType().getMax());
    break;
  case TupleNode::COUNT:
    findLetsToInline(ancestor->getParent(), toInline, toCount);
    break;
  case TupleNode::CONTEXT_TUPLE:
  case TupleNode::DEBUG_HOOK:
    break;
  }
}

static ASTNode *inlineLets(XQReturn *item, DynamicContext *context, size_t &sizeLimit, bool &success)
{
  map<LetTuple*, unsigned int> toCount;
  vector<LetTuple*> toInline;
  findLetsToInline(const_cast<TupleNode*>(item->getParent()), toInline, toCount);
  countLetUsage(item->getExpression(), toCount,
                item->getParent()->getStaticAnalysis().getStaticType().getMax());

  InlineVar inliner;
  vector<LetTuple*>::iterator i = toInline.begin();
  for(; i != toInline.end(); ++i) {
    success = inliner.inlineLet(item, *i, context, sizeLimit) || success;
  }

  map<LetTuple*, unsigned int>::iterator j = toCount.begin();
  for(; j != toCount.end(); ++j) {
    if(j->second != StaticType::UNLIMITED && j->second <= 1) {
      success = inliner.inlineLet(item, j->first, context, sizeLimit) || success;
    }
  }

  return item->staticTyping(0, 0);
}

ASTNode *PartialEvaluator::optimizeReturn(XQReturn *item)
{
  bool success = false;
  ASTNode *result = inlineLets(item, context_, sizeLimit_, success);
  if(success || result != item) {
    redoTyping_ = true;
    return optimize(result);
  }

  result = ASTVisitor::optimizeReturn(item);
  if(result != item) return result;

  // Combine nested FLWORs
  if(item->getExpression()->getType() == ASTNode::RETURN) {
    XQReturn *otherReturn = (XQReturn*)item->getExpression();;

    // We can't combine if the nested tuple uses an "order by"
    TupleNode *parent = otherReturn->getParent();
    while(parent) {
      if(parent->getType() == TupleNode::ORDER_BY)
        break;
      parent = parent->getParent();
    }

    if(parent == 0) {
      // Combine the FLWORs
      TupleNode *prev = 0;
      parent = otherReturn->getParent();
      while(parent->getType() != TupleNode::CONTEXT_TUPLE) {
        prev = parent;
        parent = parent->getParent();
      }
      if(prev) prev->setParent(item->getParent());
      item->setParent(0);
      item->setExpression(0);
      sizeLimit_ += ASTCounter().count(item);
      item->release();
      item = otherReturn;
    }
  }

  success = false;
  result = inlineLets(item, context_, sizeLimit_, success);
  if(success || result != item) {
    redoTyping_ = true;
    return optimize(result);
  }

  if(item->getParent()->getType() == TupleNode::CONTEXT_TUPLE) {
    result = item->getExpression();
    item->setExpression(0);
    sizeLimit_ += ASTCounter().count(item);
    item->release();
    return result;
  }

  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Make decisions early

ASTNode *PartialEvaluator::optimizeQuantified(XQQuantified *item)
{
  item->setParent(optimizeTupleNode(const_cast<TupleNode*>(item->getParent())));

  if(item->getParent()->getStaticAnalysis().getStaticType().getMax() == 0) {
    ASTNode *result = XQLiteral::create(item->getQuantifierType() == XQQuantified::EVERY, context_->getMemoryManager(), item)
      ->staticResolution(context_);
    sizeLimit_ += ASTCounter().count(item);
    sizeLimit_ -= ASTCounter().count(result);
    item->release();
    return result;
  }

  item->setExpression(optimize(item->getExpression()));

  if(item->getExpression()->isConstant() &&
     item->getParent()->getStaticAnalysis().getStaticType().getMin() != 0) {
      bool value = item->getExpression()->boolResult(context_);
    ASTNode *result = XQLiteral::create(value, context_->getMemoryManager(), item)
      ->staticResolution(context_);
    sizeLimit_ += ASTCounter().count(item);
    sizeLimit_ -= ASTCounter().count(result);
    item->release();
    return result;
  }

  return item;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Folding based on static type

ASTNode *PartialEvaluator::optimizeFunction(XQFunction *item)
{
  ASTNode *result = ASTVisitor::optimizeFunction(item);
  if(result != item) return result;

  const XMLCh *uri = item->getFunctionURI();
  const XMLCh *name = item->getFunctionName();

  if(uri == XQFunction::XMLChFunctionURI) {

    if(name == FunctionCount::name ||
       name == FunctionFunctionArity::name ||
       name == FunctionEmpty::name) {
      result = item->staticTypingImpl(context_);
      if(result != item) {
        redoTyping_ = true;
        result = optimize(result->staticTyping(0, 0));
      }
      return result;
    }

  }

  return item;
}

ASTNode *PartialEvaluator::optimizeTypeswitch(XQTypeswitch *item)
{
  ASTNode *result = ASTVisitor::optimizeTypeswitch(item);
  if(result != item) return result;

  result = item->staticTypingImpl(context_);
  if(result != item) {
    redoTyping_ = true;
    result = optimize(result->staticTyping(0, 0));
  }
  return result;
}

// Other things to constant fold:
//
// XQMap
// global variables
// 
//
// XQNav
// casts, conversions, atomize
//
