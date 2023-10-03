/*
 * Copyright (c) 2004-2008
 *     Oracle. All rights reserved.
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
 *
 * $Id$
 */

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/ast/XQFunction.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/XStr.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/context/StaticContext.hpp>

XERCES_CPP_NAMESPACE_USE;
using namespace std;

FunctionSignature::FunctionSignature(XPath2MemoryManager *m)
  : annotations(XQillaAllocator<Annotation*>(m)),
    annotationMap(3, true, m),
    argSpecs(0),
    returnType(0),
    memMgr(m)
{
}

FunctionSignature::FunctionSignature(ArgumentSpecs *a, SequenceType *r, XPath2MemoryManager *mm)
  : annotations(XQillaAllocator<Annotation*>(mm)),
    annotationMap(3, true, mm),
    argSpecs(a),
    returnType(r),
    memMgr(mm)
{
}

FunctionSignature::FunctionSignature(const FunctionSignature *o, XPath2MemoryManager *mm)
  : annotations(XQillaAllocator<Annotation*>(mm)),
    annotationMap(3, true, mm),
    argSpecs(0),
    returnType(o->returnType),
    memMgr(mm)
{
  Annotations::const_iterator ait;
  for(ait = o->annotations.begin(); ait != o->annotations.end(); ++ait) {
    Annotation *newAnnotation = new (mm) Annotation((*ait)->getQName(), (*ait)->getURI(),
      (*ait)->getName(), (*ait)->getURIName(), (*ait)->getExpression());
    newAnnotation->setLocationInfo(*ait);
    annotations.push_back(newAnnotation);
    if(newAnnotation->getName() != 0) {
      annotationMap.put(newAnnotation->getURIName(), newAnnotation);
    }
  }

  if(o->argSpecs) {
    argSpecs = new (mm) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(mm));

    ArgumentSpecs::const_iterator argIt = o->argSpecs->begin();
    for(; argIt != o->argSpecs->end(); ++argIt) {
      argSpecs->push_back(new (mm) ArgumentSpec(*argIt, mm));
    }
  }
}   

FunctionSignature::FunctionSignature(const FunctionSignature *o, unsigned int skipArg, XPath2MemoryManager *mm)
  : annotations(XQillaAllocator<Annotation*>(mm)),
    annotationMap(3, true, mm),
    argSpecs(0),
    returnType(o->returnType),
    memMgr(mm)
{
  Annotations::const_iterator ait;
  for(ait = o->annotations.begin(); ait != o->annotations.end(); ++ait) {
    Annotation *newAnnotation = new (mm) Annotation((*ait)->getQName(), (*ait)->getURI(),
      (*ait)->getName(), (*ait)->getURIName(), (*ait)->getExpression());
    newAnnotation->setLocationInfo(*ait);
    annotations.push_back(newAnnotation);
    if(newAnnotation->getName() != 0) {
      annotationMap.put(newAnnotation->getURIName(), newAnnotation);
    }
  }

  if(o->argSpecs) {
    argSpecs = new (mm) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(mm));

    unsigned int count = 0;
    ArgumentSpecs::const_iterator argIt = o->argSpecs->begin();
    for(; argIt != o->argSpecs->end(); ++argIt, ++count) {
      if(count != skipArg)
        argSpecs->push_back(new (mm) ArgumentSpec(*argIt, mm));
    }
  }
}

FunctionSignature::FunctionSignature(const FunctionSignature *o, const VectorOfASTNodes *args,
                                     XPath2MemoryManager *mm)
  : annotations(XQillaAllocator<Annotation*>(mm)),
    annotationMap(3, true, mm),
    argSpecs(0),
    returnType(o->returnType),
    memMgr(mm)
{
  Annotations::const_iterator ait;
  for(ait = o->annotations.begin(); ait != o->annotations.end(); ++ait) {
    Annotation *newAnnotation = new (mm) Annotation((*ait)->getQName(), (*ait)->getURI(),
      (*ait)->getName(), (*ait)->getURIName(), (*ait)->getExpression());
    newAnnotation->setLocationInfo(*ait);
    annotations.push_back(newAnnotation);
    if(newAnnotation->getName() != 0) {
      annotationMap.put(newAnnotation->getURIName(), newAnnotation);
    }
  }

  assert(o->numArgs() == args->size());

  if(o->argSpecs) {
    argSpecs = new (mm) ArgumentSpecs(XQillaAllocator<ArgumentSpec*>(mm));

    VectorOfASTNodes::const_iterator i = args->begin();
    ArgumentSpecs::const_iterator argIt = o->argSpecs->begin();
    for(; argIt != o->argSpecs->end() && i != args->end(); ++argIt, ++i) {
      if((*i) == 0)
        argSpecs->push_back(new (mm) ArgumentSpec(*argIt, mm));
    }
  }
}

void FunctionSignature::release()
{
  Annotations::iterator ait;
  for(ait = annotations.begin(); ait != annotations.end(); ++ait) {
    (*ait)->release(memMgr);
  }

  if(argSpecs) {
    ArgumentSpecs::iterator argIt = argSpecs->begin();
    for(; argIt != argSpecs->end(); ++argIt) {
      (*argIt)->release();
    }
#if defined(_MSC_VER) && (_MSC_VER < 1300)
    argSpecs->~vector<ArgumentSpec*,XQillaAllocator<ArgumentSpec*> >();
#else
    argSpecs->~ArgumentSpecs();
#endif
    memMgr->deallocate(argSpecs);
  }

  memMgr->deallocate(this);
}

void FunctionSignature::staticResolution(StaticContext *context)
{
  // Resolve annotation names
  Annotations::iterator ait;
  for(ait = annotations.begin(); ait != annotations.end(); ++ait) {
    (*ait)->staticResolution(context);
  }
  // Check for duplicate annotations
  annotationMap.removeAll();
  for(ait = annotations.begin(); ait != annotations.end(); ++ait) {
    if(annotationMap.contains((*ait)->getURIName())) {
      XMLBuffer buf;
      buf.append(X("Two annotations have the same expanded QName '"));
      buf.append(X("{"));
      buf.append((*ait)->getURI());
      buf.append(X("}"));
      buf.append((*ait)->getName());
      buf.append(X("' [err:TBD]"));
      XQThrow3(StaticErrorException, X("FunctionSignature::staticResolution"), buf.getRawBuffer(), *ait);
    }

    annotationMap.put((*ait)->getURIName(), *ait);
  }

  // Resolve the parameter names
  if(argSpecs) {
    ArgumentSpecs::iterator it;
    for(it = argSpecs->begin(); it != argSpecs->end (); ++it) {
      (*it)->staticResolution(context);
    }
    // check for duplicate parameters
    it = argSpecs->begin();
    if(it != argSpecs->end() &&(*it)->getName() != 0) {
      for(; argSpecs->size() > 1 && it != argSpecs->end()-1; ++it) {
        for(ArgumentSpecs::iterator it2 = it+1; it2 != argSpecs->end (); ++it2) {
          if(XPath2Utils::equals((*it)->getURI(),(*it2)->getURI()) && 
             XPath2Utils::equals((*it)->getName(),(*it2)->getName())) {
            XMLBuffer buf;
            buf.append(X("Two parameters have the same expanded QName '"));
            buf.append(X("{"));
            buf.append((*it)->getURI());
            buf.append(X("}"));
            buf.append((*it)->getName());
            buf.append(X("' [err:XQST0039]"));
            XQThrow3(StaticErrorException, X("FunctionSignature::staticResolution"), buf.getRawBuffer(), *it2);
          }
        }
      }
    }
  }

  if(returnType) {
    returnType->staticResolution(context);
  }
}

void FunctionSignature::toBuffer(XMLBuffer &buffer, bool typeSyntax) const
{
  buffer.append(X("function("));

  if(argSpecs) {
    bool doneOne = false;
    for(ArgumentSpecs::const_iterator i = argSpecs->begin();
        i != argSpecs->end(); ++i) {
      if(doneOne) buffer.append(X(", "));
      doneOne = true;

      if(!typeSyntax && ((*i)->getQName() || (*i)->getName())) {
        buffer.append('$');
        if((*i)->getQName()) {
          buffer.append((*i)->getQName());
        }
        else {
          if((*i)->getURI()) {
            buffer.append('{');
            buffer.append((*i)->getURI());
            buffer.append('}');
          }
          buffer.append((*i)->getName());
        }
        buffer.append(X(" as "));
      }

      (*i)->getType()->toBuffer(buffer);
    }
  }
  buffer.append(X(") as "));
  if(returnType)
    returnType->toBuffer(buffer);
  else buffer.append(X("item()*"));
}

bool FunctionSignature::isPrivate() const
{
  XMLBuffer buf;
  XPath2NSUtils::makeURIName(XQFunction::XMLChFunctionURI, Annotation::XMLChPrivateLocalname, buf);
  return annotationMap.contains(buf.getRawBuffer());
}

bool FunctionSignature::isUpdating() const
{
  XMLBuffer buf;
  XPath2NSUtils::makeURIName(XQFunction::XMLChFunctionURI, Annotation::XMLChUpdatingLocalname, buf);
  return annotationMap.contains(buf.getRawBuffer());
}

////////////////////////////////////////////////////////////////////////////////////////////////////

ArgumentSpec::ArgumentSpec(const XMLCh *qname, SequenceType *type, XPath2MemoryManager *memMgr)
  : qname_(memMgr->getPooledString(qname)),
    uri_(0),
    name_(0),
    uriname_(0),
    used_(true),
    seqType_(type),
    properties_(0),
    type_(memMgr),
    index_(0),
    mm_(memMgr)
{
  setLocationInfo(type);
}

ArgumentSpec::ArgumentSpec(const ArgumentSpec *o, XPath2MemoryManager *memMgr)
  : qname_(o->qname_),
    uri_(o->uri_),
    name_(o->name_),
    uriname_(o->uriname_),
    used_(o->used_),
    seqType_(o->seqType_),
    properties_(0),
    type_(o->type_, memMgr),
    index_(o->index_),
    mm_(memMgr)
{
  setLocationInfo(o);
}

void ArgumentSpec::release()
{
  type_.release();
  mm_->deallocate(this);
}

void ArgumentSpec::setURI(const XMLCh *uri)
{
  uri_ = uri;
  uriname_ = XPath2NSUtils::makeURIName(uri_, name_, mm_);
}

void ArgumentSpec::setName(const XMLCh *name)
{
  name_ = name;
  uriname_ = XPath2NSUtils::makeURIName(uri_, name_, mm_);
}

void ArgumentSpec::staticResolution(StaticContext* context)
{
  if(qname_ != 0 && name_ == 0) {
    uri_ = context->getUriBoundToPrefix(XPath2NSUtils::getPrefix(qname_, context->getMemoryManager()), this);
    name_ = XPath2NSUtils::getLocalName(qname_);
  }
  if(name_ && uriname_ == 0) {
    uriname_ = XPath2NSUtils::makeURIName(uri_, name_, context->getMemoryManager());
  }

  if(seqType_) {
    seqType_->staticResolution(context);
    type_ = seqType_;

    if(seqType_->getOccurrenceIndicator() == SequenceType::EXACTLY_ONE ||
       seqType_->getOccurrenceIndicator() == SequenceType::QUESTION_MARK) {
      properties_ = StaticAnalysis::DOCORDER | StaticAnalysis::GROUPED |
        StaticAnalysis::PEER | StaticAnalysis::SUBTREE | StaticAnalysis::SAMEDOC |
        StaticAnalysis::ONENODE | StaticAnalysis::SELF;
    }
  } else {
    type_ = StaticType::ITEM_STAR;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const XMLCh Annotation::XMLChPrivateLocalname[] = { 'p', 'r', 'i', 'v', 'a', 't', 'e', 0 };
const XMLCh Annotation::XMLChUpdatingLocalname[] = { 'u', 'p', 'd', 'a', 't', 'i', 'n', 'g', 0 };

Annotation::Annotation(const XMLCh *qname, ASTNode *expr)
  : qname_(qname),
    uri_(0),
    name_(0),
    uriname_(0),
    expr_(expr)
{
}

Annotation::Annotation(const XMLCh *qname, const XMLCh *uri, const XMLCh *name,
                       ASTNode *expr, XPath2MemoryManager *mm)
  : qname_(qname),
    uri_(uri),
    name_(name),
    uriname_(XPath2NSUtils::makeURIName(uri, name, mm)),
    expr_(expr)
{
}

Annotation::Annotation(const XMLCh *qname, const XMLCh *uri, const XMLCh *name,
                       const XMLCh *uriname, ASTNode *expr)
  : qname_(qname),
    uri_(uri),
    name_(name),
    uriname_(uriname),
    expr_(expr)
{
}

void Annotation::release(XPath2MemoryManager *mm)
{
  expr_->release();
  mm->deallocate(this);
}

void Annotation::staticResolution(StaticContext* context)
{
  if(qname_ != 0 && name_ == 0) {
    const XMLCh *prefix = XPath2NSUtils::getPrefix(qname_, context->getMemoryManager());
    name_ = XPath2NSUtils::getLocalName(qname_);

    if(prefix == 0 || *prefix == 0) {
      uri_ = context->getDefaultFuncNS();
    }
    else {
      uri_ = context->getUriBoundToPrefix(prefix, this);
    }

    uriname_ = XPath2NSUtils::makeURIName(uri_, name_, context->getMemoryManager());
  }
}

