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

#ifndef _XQREWRITERULE_HPP
#define _XQREWRITERULE_HPP

#include <xqilla/ast/ASTNode.hpp>
#include <xqilla/items/AnyAtomicType.hpp>

class TupleImpl;

class XQILLA_API RewritePattern : public LocationInfo
{
public:
  typedef std::vector<RewritePattern*,XQillaAllocator<RewritePattern*> > Vector;

  RewritePattern(ASTNode::whichType t, XPath2MemoryManager *mm)
    : type(t), primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    value(0), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm)) {}
  RewritePattern(ASTNode::whichType t, const XMLCh *v, XPath2MemoryManager *mm)
    : type(t), primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    value(v), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm)) {}
  RewritePattern(AnyAtomicType::AtomicObjectType p, const XMLCh *v, XPath2MemoryManager *mm)
    : type(ASTNode::LITERAL), primitiveType(p),
    value(v), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm)) {}
  RewritePattern(ASTNode::whichType t, RewritePattern *c1,
    XPath2MemoryManager *mm)
    : type(t), primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    value(0), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm))
  {
    children.push_back(c1);
  }
  RewritePattern(ASTNode::whichType t, RewritePattern *c1,
    RewritePattern *c2, XPath2MemoryManager *mm)
    : type(t), primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    value(0), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm))
  {
    children.push_back(c1);
    children.push_back(c2);
  }
  RewritePattern(ASTNode::whichType t, RewritePattern *c1,
    RewritePattern *c2, RewritePattern *c3, XPath2MemoryManager *mm)
    : type(t), primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    value(0), uri(0), name(0),
    children(XQillaAllocator<RewritePattern*>(mm))
  {
    children.push_back(c1);
    children.push_back(c2);
    children.push_back(c3);
  }

  void release(XPath2MemoryManager *mm);

  RewritePattern *staticResolution(StaticContext *context);

  void typesMatched(std::vector<ASTNode::whichType> &types) const;

  bool matches(const ASTNode *ast, DynamicContext *context,
    TupleImpl *subs = 0) const;

  ASTNode::whichType type;
  AnyAtomicType::AtomicObjectType primitiveType;
  const XMLCh *value, *uri, *name;
  Vector children;
};

class XQRewriteRule;

class XQILLA_API RewriteCase
{
public:
  typedef std::vector<RewriteCase*,XQillaAllocator<RewriteCase*> > Vector;

  RewriteCase(ASTNode *r, ASTNode *w)
    : result(r), where(w) {}

  void staticResolution(StaticContext *context);
  void staticTyping(StaticContext *context, StaticTyper *styper);

  ASTNode *apply(const XQRewriteRule *rule, DynamicContext *context, const TupleImpl *subs) const;

  ASTNode *result;
  ASTNode *where;
};

class XQILLA_API XQRewriteRule : public LocationInfo
{
public:
  static const XMLCh URI[];
  static const XMLCh TypeName[];

  XQRewriteRule(const XMLCh *qname, RewritePattern *pattern,
    ASTNode *where, XPath2MemoryManager *mm)
    : qname_(qname), uri_(0), name_(0),
      pattern_(pattern), where_(where),
      cases_(XQillaAllocator<RewriteCase*>(mm))
  {}

  void addCase(RewriteCase *c) { cases_.push_back(c); }

  const XMLCh *getQName() const { return qname_; }
  const XMLCh *getURI() const { return uri_; }
  const XMLCh *getName() const { return name_; }

  RewritePattern *getPattern() const { return pattern_; }
  ASTNode *getWhere() const { return where_; }
  void setWhere(ASTNode *w) { where_ = w; }
  RewriteCase::Vector &getCases() { return cases_; }

  void staticResolution(StaticContext *context);
  void staticTyping(StaticContext *context, StaticTyper *styper);

  ASTNode *apply(const ASTNode *item, DynamicContext *context) const;

  static XQRewriteRule *parse(const XMLCh *rulestr, XPath2MemoryManager *mm,
                              const LocationInfo *info);

private:
  const XMLCh *qname_, *uri_, *name_;
  RewritePattern *pattern_;
  ASTNode *where_;
  RewriteCase::Vector cases_;

  friend class RewriteCase;
};

#endif
