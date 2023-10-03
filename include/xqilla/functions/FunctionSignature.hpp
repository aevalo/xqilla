/*
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

#ifndef FUNCTIONSIGNATURE_HPP
#define FUNCTIONSIGNATURE_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/ast/LocationInfo.hpp>
#include <xqilla/utils/HashMap.hpp>

class SequenceType;
class ASTNode;

class XQILLA_API Annotation : public LocationInfo
{
public:
  static const XMLCh XMLChPrivateLocalname[];
  static const XMLCh XMLChUpdatingLocalname[];

  Annotation(const XMLCh *qname, ASTNode *expr);
  Annotation(const XMLCh *qname, const XMLCh *uri, const XMLCh *name,
             ASTNode *expr, XPath2MemoryManager *mm);
  Annotation(const XMLCh *qname, const XMLCh *uri, const XMLCh *name,
             const XMLCh *uriname, ASTNode *expr);

  void release(XPath2MemoryManager *mm);

  const XMLCh *getURI() const { return uri_; }
  void setURI(const XMLCh *uri) { uri_ = uri; }
  const XMLCh *getName() const { return name_; }
  void setName(const XMLCh *name) { name_ = name; }
  const XMLCh *getQName() const { return qname_; }
  void setQName(const XMLCh *qname) { qname_ = qname; }

  const XMLCh *getURIName() const { return uriname_; }

  ASTNode *getExpression() const { return expr_; }
  void setExpression(ASTNode *e) { expr_ = e; }

  void staticResolution(StaticContext* context);

private:
  const XMLCh *qname_, *uri_, *name_;
  const XMLCh *uriname_;
  ASTNode *expr_;
};

typedef std::vector<Annotation*,XQillaAllocator<Annotation*> > Annotations;
typedef HashMap<const XMLCh*, Annotation*> AnnotationMap;

class XQILLA_API ArgumentSpec : public LocationInfo
{
public:
  ArgumentSpec(const XMLCh *qname, SequenceType *type, XPath2MemoryManager *memMgr);
  ArgumentSpec(const ArgumentSpec *o, XPath2MemoryManager *memMgr);

  void release();

  const XMLCh *getURI() const { return uri_; }
  void setURI(const XMLCh *uri);
  const XMLCh *getName() const { return name_; }
  void setName(const XMLCh *name);
  const XMLCh *getQName() const { return qname_; }
  void setQName(const XMLCh *qname) { qname_ = qname; }
  const XMLCh *getURIName() const { return uriname_; }
  SequenceType *getType() const { return seqType_; }
  void setType(SequenceType *type) { seqType_ = type; }

  bool isUsed() const { return used_; }
  void setNotUsed() { used_ = false; }

  unsigned getProperties() const { return properties_; }
  const StaticType &getStaticType() const { return type_; }

  unsigned getIndex() const { return index_; }
  void setIndex(unsigned i) { index_ = i; }

  void staticResolution(StaticContext* context);

private:
  const XMLCh *qname_, *uri_, *name_, *uriname_;
  bool used_;
  SequenceType *seqType_;
  unsigned properties_;
  StaticType type_;
  unsigned index_;
  XPath2MemoryManager *mm_;
};

typedef std::vector<ArgumentSpec*,XQillaAllocator<ArgumentSpec*> > ArgumentSpecs;
typedef std::vector<ASTNode*,XQillaAllocator<ASTNode*> > VectorOfASTNodes;

class XQILLA_API FunctionSignature
{
public:
  FunctionSignature(XPath2MemoryManager *mm);
  FunctionSignature(ArgumentSpecs *a, SequenceType *r, XPath2MemoryManager *mm);
  FunctionSignature(const FunctionSignature *o, XPath2MemoryManager *mm);
  FunctionSignature(const FunctionSignature *o, unsigned int skipArg, XPath2MemoryManager *mm);
  FunctionSignature(const FunctionSignature *o, const VectorOfASTNodes *args, XPath2MemoryManager *mm);

  void release();

  void staticResolution(StaticContext *context);

  size_t numArgs() const { return argSpecs ? argSpecs->size() : 0; }

  bool isPrivate() const;
  bool isUpdating() const;

  void toBuffer(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buffer, bool typeSyntax) const;

  Annotations annotations;
  AnnotationMap annotationMap;

  ArgumentSpecs *argSpecs;
  SequenceType *returnType;
  XPath2MemoryManager *memMgr;
};

#endif
