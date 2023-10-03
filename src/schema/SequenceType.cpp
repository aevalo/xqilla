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

#include "../config/xqilla_config.h"
#include <assert.h>
#include <sstream>

#include <xqilla/schema/SequenceType.hpp>

#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/schema/DocumentCache.hpp>
#include <xqilla/framework/XPath2MemoryManager.hpp>
#include <xqilla/parser/QName.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/exceptions/XPath2ErrorException.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/exceptions/XPath2TypeCastException.hpp>
#include <xqilla/items/ATStringOrDerived.hpp>
#include <xqilla/items/ATDoubleOrDerived.hpp>
#include <xqilla/items/ATUntypedAtomic.hpp>
#include <xqilla/items/Node.hpp>
#include <xqilla/items/FunctionRef.hpp>
#include <xqilla/functions/FunctionString.hpp>
#include <xqilla/functions/FunctionNumber.hpp>
#include <xqilla/functions/FunctionHead.hpp>
#include <xqilla/functions/FunctionSignature.hpp>
#include <xqilla/items/DatatypeFactory.hpp>
#include <xqilla/ast/XQAtomize.hpp>
#include <xqilla/ast/XQTreatAs.hpp>
#include <xqilla/ast/ConvertFunctionArg.hpp>
#include <xqilla/ast/XQFunctionCoercion.hpp>
#include <xqilla/schema/DocumentCacheImpl.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>
#include <xqilla/ast/XQTypeAlias.hpp>
#include <xqilla/ast/XQRewriteRule.hpp>

#include <xercesc/validators/schema/SchemaAttDef.hpp>
#include <xercesc/validators/schema/SchemaElementDecl.hpp>

#if defined(XERCES_HAS_CPP_NAMESPACE)
XERCES_CPP_NAMESPACE_USE
#endif

static const DocumentCache *staticDocumentCache()
{
  static const DocumentCacheImpl dc(BasicMemoryManager::get());
  return &dc;
}

const ItemType ItemType::ITEM(ItemType::TEST_ANYTHING, staticDocumentCache());

const ItemType ItemType::ANY_ATOMIC_TYPE(ItemType::TEST_ATOMIC_TYPE, staticDocumentCache());
const ItemType ItemType::UNTYPED_ATOMIC(AnyAtomicType::UNTYPED_ATOMIC, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, ATUntypedAtomic::fgDT_UNTYPEDATOMIC, staticDocumentCache());
const ItemType ItemType::BOOLEAN(AnyAtomicType::BOOLEAN, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_BOOLEAN, staticDocumentCache());
const ItemType ItemType::DECIMAL(AnyAtomicType::DECIMAL, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DECIMAL, staticDocumentCache());
const ItemType ItemType::FLOAT(AnyAtomicType::FLOAT, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_FLOAT, staticDocumentCache());
const ItemType ItemType::DOUBLE(AnyAtomicType::DOUBLE, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DOUBLE, staticDocumentCache());
const ItemType ItemType::STRING(AnyAtomicType::STRING, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_STRING, staticDocumentCache());
const ItemType ItemType::QNAME(AnyAtomicType::QNAME, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_QNAME, staticDocumentCache());
const ItemType ItemType::DAY_TIME_DURATION(AnyAtomicType::DAY_TIME_DURATION, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, ATDurationOrDerived::fgDT_DAYTIMEDURATION, staticDocumentCache());
const ItemType ItemType::ANY_URI(AnyAtomicType::ANY_URI, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_ANYURI, staticDocumentCache());
const ItemType ItemType::BASE_64_BINARY(AnyAtomicType::BASE_64_BINARY, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_BASE64BINARY, staticDocumentCache());
const ItemType ItemType::DATE(AnyAtomicType::DATE, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DATE, staticDocumentCache());
const ItemType ItemType::DATE_TIME(AnyAtomicType::DATE_TIME, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DATETIME, staticDocumentCache());
const ItemType ItemType::DURATION(AnyAtomicType::DURATION, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DURATION, staticDocumentCache());
const ItemType ItemType::G_DAY(AnyAtomicType::G_DAY, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_DAY, staticDocumentCache());
const ItemType ItemType::G_MONTH(AnyAtomicType::G_MONTH, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_MONTH, staticDocumentCache());
const ItemType ItemType::G_MONTH_DAY(AnyAtomicType::G_MONTH_DAY, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_MONTHDAY, staticDocumentCache());
const ItemType ItemType::G_YEAR(AnyAtomicType::G_YEAR, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_YEAR, staticDocumentCache());
const ItemType ItemType::G_YEAR_MONTH(AnyAtomicType::G_YEAR_MONTH, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_YEARMONTH, staticDocumentCache());
const ItemType ItemType::HEX_BINARY(AnyAtomicType::HEX_BINARY, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_HEXBINARY, staticDocumentCache());
const ItemType ItemType::NOTATION(AnyAtomicType::NOTATION, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgELT_NOTATION, staticDocumentCache());
const ItemType ItemType::TIME(AnyAtomicType::TIME, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_TIME, staticDocumentCache());
const ItemType ItemType::YEAR_MONTH_DURATION(AnyAtomicType::YEAR_MONTH_DURATION, true, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, ATDurationOrDerived::fgDT_YEARMONTHDURATION, staticDocumentCache());
const ItemType ItemType::INTEGER(AnyAtomicType::DECIMAL, false, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, SchemaSymbols::fgDT_INTEGER, staticDocumentCache());

const ItemType ItemType::NODE(ItemType::TEST_NODE, staticDocumentCache());
const ItemType ItemType::DOCUMENT(ItemType::TEST_DOCUMENT, staticDocumentCache());
const ItemType ItemType::ELEMENT(ItemType::TEST_ELEMENT, staticDocumentCache());
const ItemType ItemType::ATTRIBUTE(ItemType::TEST_ATTRIBUTE, staticDocumentCache());
const ItemType ItemType::TEXT(ItemType::TEST_TEXT, staticDocumentCache());
const ItemType ItemType::PI(ItemType::TEST_PI, staticDocumentCache());
const ItemType ItemType::COMMENT(ItemType::TEST_COMMENT, staticDocumentCache());
const ItemType ItemType::NAMESPACE(ItemType::TEST_NAMESPACE, staticDocumentCache());

const ItemType ItemType::FUNCTION(ItemType::TEST_FUNCTION, staticDocumentCache());
const ItemType ItemType::TUPLE(ItemType::TEST_TUPLE, staticDocumentCache());
const ItemType ItemType::MAP(ItemType::TEST_MAP, staticDocumentCache());
const ItemType ItemType::EXPRESSION(ItemType::TEST_EXPRESSION, staticDocumentCache());

const SequenceType SequenceType::ANY_ATOMIC_TYPE((ItemType*)&ItemType::ANY_ATOMIC_TYPE);
const SequenceType SequenceType::ITEM_STAR((ItemType*)&ItemType::ITEM, SequenceType::STAR);

SequenceType::SequenceType(ItemType* test, OccurrenceIndicator occur)
  : m_pItemType(test),
    m_nOccurrence(occur)
{
}

SequenceType::SequenceType()
  : m_pItemType(0),
    m_nOccurrence(EXACTLY_ONE)
{
}

SequenceType::~SequenceType()
{
}

Result SequenceType::occurrenceMatches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const
{
  return new OccurrenceMatchesResult(toBeTested, this, location, errorCode);
}

Result SequenceType::typeMatches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const
{
  return new TypeMatchesResult(toBeTested, this, location, errorCode);
}

Result SequenceType::matches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const
{
  return typeMatches(occurrenceMatches(toBeTested, location, errorCode), location, errorCode);
}

bool SequenceType::matches(const Result &toBeTested, DynamicContext *context) const
{
  if(m_nOccurrence == STAR && m_pItemType && m_pItemType->getItemTestType() == ItemType::TEST_ANYTHING)
    return true;

  Result result(toBeTested);

  // First item
  Item::Ptr item = result->next(context);
  if(item.isNull())
    return m_pItemType == 0 || m_nOccurrence == STAR || m_nOccurrence == QUESTION_MARK;
  if(m_pItemType == 0 || !m_pItemType->matches(item, context)) return false;

  // Second item
  item = result->next(context);
  if(item.isNull()) return true;
  if(m_nOccurrence == EXACTLY_ONE || m_nOccurrence == QUESTION_MARK)
    return false;
  if(!m_pItemType->matches(item, context)) return false;

  // The rest of the sequence
  while((item = result->next(context)).notNull())
    if(!m_pItemType->matches(item, context)) return false;
  return true;
}

SequenceType::TypeMatch SequenceType::matches(const StaticType &actual) const
{
  TypeMatch result = { ALWAYS, ALWAYS };

  unsigned int min = 0, max = 0;

  if(m_pItemType) {
    switch(m_nOccurrence) {
    case SequenceType::EXACTLY_ONE:
      min = 1; max = 1; break;
    case SequenceType::STAR:
      min = 0; max = StaticType::UNLIMITED; break;
    case SequenceType::PLUS:
      min = 1; max = StaticType::UNLIMITED; break;
    case SequenceType::QUESTION_MARK:
      min = 0; max = 1; break;
    }
  }

  if(min > actual.getMax() ||
     max < actual.getMin()) {
    result.cardinality = NEVER;
  }
  else if(min > actual.getMin() ||
          max < actual.getMax()) {
    // if(actual.getMax() != StaticType::UNLIMITED)
    //   result.cardinality = PROBABLY_NOT;
    // else
      result.cardinality = MAYBE;
  }

  if(m_pItemType == 0) {
    result.type = (actual.getMax() == 0 ? ALWAYS : (actual.getMin() == 0 ? MAYBE : NEVER));
    return result;
  }

  bool foundMatch = false;
  StaticType::ItemTypes::const_iterator i = actual.getTypes().begin();
  for(; i != actual.getTypes().end(); ++i) {
    if((*i)->isSubtypeOf(m_pItemType, /*forStaticType*/true)) {
      // Good to go
      foundMatch = true;
    }
    else if((*i)->intersects(m_pItemType)) {
      foundMatch = true;
      result.type = MAYBE;
    }
    else {
      result.type = MAYBE;
    }
  }

  if(!foundMatch)
    result.type = (min > 0 || actual.getMin() > 0) ? NEVER : PROBABLY_NOT;

  return result;
}

ItemType::ItemTestType SequenceType::getItemTestType() const {

  return m_pItemType->getItemTestType();
}

SequenceType::OccurrenceIndicator SequenceType::getOccurrenceIndicator() const {

  return m_nOccurrence;
}

void SequenceType::setOccurrence(SequenceType::OccurrenceIndicator nOccurrence)
{
  m_nOccurrence=nOccurrence;
}

void SequenceType::staticResolution(StaticContext* context)
{
  if(m_pItemType)
    m_pItemType = m_pItemType->staticResolution(context, this);
}

ItemType *ItemType::staticResolution(StaticContext *context, const LocationInfo *location)
{
  // Prefix resolution should only happen once
  // (since SequenceType objects can be multiple times in the AST)
  if(staticallyResolved_) return this;
  staticallyResolved_ = true;

  dc_ = context->getDocumentCache();

  if(m_TypeName && m_TypeURI == 0) {
    // an empty prefix means the default element and type namespace
    if(m_TypePrefix == 0 || *m_TypePrefix == 0) {
      m_TypeURI = context->getDefaultElementAndTypeNS();
    }
    else {
      m_TypeURI = context->getUriBoundToPrefix(m_TypePrefix, location);
    }
  }
  
  if(m_NameName && m_NameURI == 0) {
    // if we are testing for an attribute, an empty prefix means empty namespace; if we are testing an element, it means 
    // the default element and type namespace
    if(m_NamePrefix == 0 || *m_NamePrefix == 0) {
      if(m_nTestType == TEST_ELEMENT || m_nTestType == TEST_SCHEMA_ELEMENT ||
         m_nTestType == TEST_DOCUMENT || m_nTestType == TEST_SCHEMA_DOCUMENT)
        m_NameURI = context->getDefaultElementAndTypeNS();
    } else {
      m_NameURI = context->getUriBoundToPrefix(m_NamePrefix, location);
    }
  }

  if(m_TypeName) {
    if(m_nTestType == ItemType::TEST_EXPRESSION) {
      // skip
    }
    else if(m_nTestType == ItemType::TEST_ATOMIC_TYPE) {
      // Check if this is actually a type alias
      alias_ = context->getTypeAlias(m_TypeURI, m_TypeName);
      // if(alias_) return alias_->isResolved() ? alias_->getType() : this;
      if(alias_) return this;

      // Check if this is actually an expression SequenceType
      if(XPath2Utils::equals(m_TypeURI, XQRewriteRule::URI) &&
         XPath2Utils::equals(m_TypeName, XQRewriteRule::TypeName)) {
        m_nTestType = TEST_EXPRESSION;
        return this;
      }

      if((XPath2Utils::equals(m_TypeName, AnyAtomicType::fgDT_ANYATOMICTYPE) ||
          XPath2Utils::equals(m_TypeName, SchemaSymbols::fgDT_ANYSIMPLETYPE)) &&
         XPath2Utils::equals(m_TypeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
        m_TypePrefix = m_TypeURI = m_TypeName = 0;
        m_primitiveType = AnyAtomicType::NumAtomicObjectTypes;
        m_primitive = false;
      } else {
        m_primitiveType = context->getItemFactory()->getPrimitiveTypeIndex(m_TypeURI, m_TypeName, m_primitive);
      }
    }
    else if(XPath2Utils::equals(m_TypeName, SchemaSymbols::fgATTVAL_ANYTYPE) &&
            XPath2Utils::equals(m_TypeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
      // xs:anyType is the same as a type wildcard
      m_TypePrefix = m_TypeURI = m_TypeName = 0;
    }
    else if(!context->getDocumentCache()->isTypeDefined(m_TypeURI, m_TypeName)) {
      XMLBuffer msg;
      msg.set(X("Type {"));
      msg.append(m_TypeURI);
      msg.append(X("}"));
      msg.append(m_TypeName);
      msg.append(X(" is not defined [err:XPTY0004]"));
      XQThrow3(XPath2ErrorException,X("ItemType::matchesNameType"), msg.getRawBuffer(), location);
    }
  }

  switch(m_nTestType) {
  case TEST_SCHEMA_DOCUMENT:
  case TEST_SCHEMA_ELEMENT: {
    // retrieve the type of the element name
    SchemaElementDecl *elemDecl = context->getDocumentCache()->getElementDecl(m_NameURI, m_NameName);
    if(elemDecl == NULL) {
      XMLBuffer msg;
      msg.set(X("Element {"));
      msg.append(m_NameURI);
      msg.append(X("}"));
      msg.append(m_NameName);
      msg.append(X(" is not defined as a global element [err:XPST0081]"));
      XQThrow3(StaticErrorException,X("ItemType::staticResolution"), msg.getRawBuffer(), location);
    }
    break;
  }
  case TEST_SCHEMA_ATTRIBUTE: {
    // retrieve the type of the attribute name
    SchemaAttDef *attrDecl = context->getDocumentCache()->getAttributeDecl(m_NameURI, m_NameName);
    if(attrDecl == NULL) {
      XMLBuffer msg;
      msg.set(X("Attribute {"));
      msg.append(m_NameURI);
      msg.append(X("}"));
      msg.append(m_NameName);
      msg.append(X(" is not defined as a global attribute [err:XPST0081]"));
      XQThrow3(StaticErrorException,X("ItemType::staticResolution"), msg.getRawBuffer(), location);
    }
    break;
  }
  default: break;
  }

  if(signature_)
    signature_->staticResolution(context);

  if(tupleMembers_) {
    // Re-create the TupleMembers hash, this time hashing under the uriname of the member
    TupleMembers newMembers(tupleMembers_->size(), false, context->getMemoryManager());
    TupleMembers::iterator i = const_cast<TupleMembers*>(tupleMembers_)->begin();
    for(; i != const_cast<TupleMembers*>(tupleMembers_)->end(); ++i) {
      i.getValue()->staticResolution(context);
      newMembers.put(i.getValue()->getURIName(), i.getValue());
    }
    const_cast<TupleMembers*>(tupleMembers_)->swap(newMembers);
  }

  if(key_)
    key_->staticResolution(context);
  if(value_)
    value_->staticResolution(context);

  return this;
}

ItemType::ItemType(ItemTestType test, QualifiedName* name, QualifiedName* type)
  : alias_(0),
    m_nTestType(test),
    m_primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    m_primitive(false),
    m_NamePrefix(name ? name->getPrefix() : 0),
    m_NameURI(0),
    m_NameName(name ? name->getName() : 0),
    m_TypePrefix(type ? type->getPrefix() : 0),
    m_TypeURI(0),
    m_TypeName(type ? type->getName() : 0),
    m_bAllowNil(false),
    signature_(0),
    tupleMembers_(0),
    key_(0),
    value_(0),
    dc_(0),
    staticallyResolved_(false)
{
}

ItemType::ItemType(ItemTestType test, const DocumentCache *dc)
  : alias_(0),
    m_nTestType(test),
    m_primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    m_primitive(false),
    m_NamePrefix(0),
    m_NameURI(0),
    m_NameName(0),
    m_TypePrefix(0),
    m_TypeURI(0),
    m_TypeName(0),
    m_bAllowNil(false),
    signature_(0),
    tupleMembers_(0),
    key_(0),
    value_(0),
    dc_(dc),
    staticallyResolved_(dc != 0)
{
}

ItemType::ItemType(AnyAtomicType::AtomicObjectType primitiveType, bool primitive,
  const XMLCh *typeURI, const XMLCh *typeName, const DocumentCache *dc)
  : alias_(0),
    m_nTestType(TEST_ATOMIC_TYPE),
    m_primitiveType(primitiveType),
    m_primitive(primitive),
    m_NamePrefix(0),
    m_NameURI(0),
    m_NameName(0),
    m_TypePrefix(0),
    m_TypeURI(typeURI),
    m_TypeName(typeName),
    m_bAllowNil(false),
    signature_(0),
    tupleMembers_(0),
    key_(0),
    value_(0),
    dc_(dc),
    staticallyResolved_(primitiveType != AnyAtomicType::NumAtomicObjectTypes && dc != 0)
{
}

ItemType::ItemType(FunctionSignature *sig, const DocumentCache *dc)
  : alias_(0),
    m_nTestType(TEST_FUNCTION),
    m_primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    m_primitive(false),
    m_NamePrefix(0),
    m_NameURI(0),
    m_NameName(0),
    m_TypePrefix(0),
    m_TypeURI(0),
    m_TypeName(0),
    m_bAllowNil(false),
    signature_(sig),
    tupleMembers_(0),
    key_(0),
    value_(0),
    dc_(dc),
    staticallyResolved_(dc != 0)
{
}

ItemType::ItemType(const TupleMembers *members, const DocumentCache *dc)
  : alias_(0),
    m_nTestType(TEST_TUPLE),
    m_primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    m_primitive(false),
    m_NamePrefix(0),
    m_NameURI(0),
    m_NameName(0),
    m_TypePrefix(0),
    m_TypeURI(0),
    m_TypeName(0),
    m_bAllowNil(false),
    signature_(0),
    tupleMembers_(members),
    key_(0),
    value_(0),
    dc_(dc),
    staticallyResolved_(dc != 0)
{
}

ItemType::ItemType(SequenceType *key, SequenceType *value, const DocumentCache *dc)
  : alias_(0),
    m_nTestType(TEST_MAP),
    m_primitiveType(AnyAtomicType::NumAtomicObjectTypes),
    m_primitive(false),
    m_NamePrefix(0),
    m_NameURI(0),
    m_NameName(0),
    m_TypePrefix(0),
    m_TypeURI(0),
    m_TypeName(0),
    m_bAllowNil(false),
    signature_(0),
    tupleMembers_(0),
    key_(key),
    value_(value),
    dc_(dc),
    staticallyResolved_(dc != 0)
{
}

ItemType::~ItemType()
{
  if(signature_) signature_->release();
}

ItemType::ItemTestType ItemType::getItemTestType() const
{
  return alias_ ? alias_->getType()->getItemTestType() : m_nTestType;
}

void ItemType::setItemTestType(ItemTestType t)
{
  m_nTestType = t;
}

void ItemType::setAllowNilled(bool value)
{
  m_bAllowNil=value;
}

bool ItemType::getAllowNilled() const
{
  return alias_ ? alias_->getType()->getAllowNilled() : m_bAllowNil;
}

FunctionSignature *ItemType::getFunctionSignature() const
{
  return alias_ ? alias_->getType()->getFunctionSignature() : signature_;
}

const TupleMembers *ItemType::getTupleMembers() const
{
  return alias_ ? alias_->getType()->getTupleMembers() : tupleMembers_;
}

SequenceType *ItemType::getKeyType() const
{
  return alias_ ? alias_->getType()->getKeyType() : key_;
}

SequenceType *ItemType::getValueType() const
{
  return alias_ ? alias_->getType()->getValueType() : value_;
}

const DocumentCache *ItemType::getDocumentCache() const
{
  return alias_ ? alias_->getType()->getDocumentCache() : dc_;
}

bool ItemType::isPrimitive() const
{
  return alias_ ? alias_->getType()->isPrimitive() : m_primitive;
}
AnyAtomicType::AtomicObjectType ItemType::getPrimitiveType() const
{
  return alias_ ? alias_->getType()->getPrimitiveType() : m_primitiveType;
}

const XMLCh *ItemType::getTypePrefix() const
{
  return alias_ ? alias_->getType()->getTypePrefix() : m_TypePrefix;
}

const XMLCh *ItemType::getTypeURI() const
{
  return alias_ ? alias_->getType()->getTypeURI() : m_TypeURI;
}

const XMLCh *ItemType::getTypeName() const
{
  return alias_ ? alias_->getType()->getTypeName() : m_TypeName;
}

const XMLCh *ItemType::getNamePrefix() const
{
  return alias_ ? alias_->getType()->getNamePrefix() : m_NamePrefix;
}

const XMLCh *ItemType::getNameURI() const
{
  return alias_ ? alias_->getType()->getNameURI() : m_NameURI;
}

const XMLCh *ItemType::getNameName() const
{
  return alias_ ? alias_->getType()->getNameName() : m_NameName;
}

void SequenceType::toBuffer(XMLBuffer &buffer, bool forStaticType) const
{
  if(this == 0) {
    buffer.append(X("item()*"));
  } else if(m_pItemType == 0) {
    buffer.append(X("empty-sequence()"));
  }
  else {
    m_pItemType->toBuffer(buffer, forStaticType, m_nOccurrence != EXACTLY_ONE);

    switch(m_nOccurrence) {
    case EXACTLY_ONE: break;
    case STAR: buffer.append('*'); break;
    case PLUS: buffer.append('+'); break;
    case QUESTION_MARK: buffer.append('?'); break;
    }
  }
}

inline void outputPrefixOrURI(const XMLCh *prefix, const XMLCh *uri, XMLBuffer &buffer)
{
  if(prefix != 0) {
    buffer.append(prefix);
    buffer.append(':');
  }
  else if(XPath2Utils::equals(uri, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
    buffer.append(X("xs:"));
  }
  else if(uri != 0) {
    buffer.append('{');
    buffer.append(uri);
    buffer.append('}');
  }
}

void ItemType::toBuffer(XMLBuffer &buffer, bool forStaticType, bool addBrackets) const
{
  static const XMLCh XMLChXS[] = { chLatin_x, chLatin_s, chNull };

  switch(m_nTestType) {
  case TEST_ANYTHING: {
    buffer.append(X("item()"));
    break;
  }
  case TEST_EXPRESSION:
  case TEST_ATOMIC_TYPE: {
    if(m_TypeName) {
      outputPrefixOrURI(m_TypePrefix, m_TypeURI, buffer);
      buffer.append(m_TypeName);
    } else {
      outputPrefixOrURI(XMLChXS, SchemaSymbols::fgURI_SCHEMAFORSCHEMA, buffer);
      buffer.append(AnyAtomicType::fgDT_ANYATOMICTYPE);
    }
    break;
  }
  case TEST_SCHEMA_DOCUMENT:
  case TEST_DOCUMENT: {
    buffer.append(X("document-node("));

    if(m_NameName != NULL || m_TypeName != NULL) {

      if(m_nTestType == TEST_DOCUMENT)
        buffer.append(X("element("));
      else
        buffer.append(X("schema-element("));

      if(m_NameName != NULL) {
        outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
        buffer.append(m_NameName);
      }

      if(m_TypeName != NULL) {
        if(m_NameName == NULL) {
          buffer.append('*');
        }
        buffer.append(X(", "));
        outputPrefixOrURI(m_TypePrefix, m_TypeURI, buffer);
        buffer.append(m_TypeName);
      }

      buffer.append(')');
    }

    buffer.append(')');
    break;
  }
  case TEST_ELEMENT: {
    buffer.append(X("element("));

    if(m_NameName != NULL) {
      outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
      buffer.append(m_NameName);
    }

    if(m_TypeName != NULL) {
      if(m_NameName == NULL) {
        buffer.append('*');
      }
      buffer.append(X(", "));
      outputPrefixOrURI(m_TypePrefix, m_TypeURI, buffer);
      buffer.append(m_TypeName);
    }

    buffer.append(')');
    break;
  }
  case TEST_ATTRIBUTE: {
    buffer.append(X("attribute("));

    if(m_NameName != NULL) {
      outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
      buffer.append(m_NameName);
    }

    if(m_TypeName != NULL) {
      if(m_NameName == NULL) {
        buffer.append('*');
      }
      buffer.append(X(", "));
      outputPrefixOrURI(m_TypePrefix, m_TypeURI, buffer);
      buffer.append(m_TypeName);
    }

    buffer.append(')');
    break;
  }
  case TEST_PI: {
    buffer.append(X("processing-instruction("));

    if(m_NameName != NULL) {
      outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
      buffer.append(m_NameName);
    }

    buffer.append(')');
    break;
  }
  case TEST_SCHEMA_ELEMENT: {
    buffer.append(X("schema-element("));

    if(m_NameName != NULL) {
      outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
      buffer.append(m_NameName);
    }

    buffer.append(')');
    break;
  }
  case TEST_SCHEMA_ATTRIBUTE: {
    buffer.append(X("schema-attribute("));

    if(m_NameName != NULL) {
      outputPrefixOrURI(m_NamePrefix, m_NameURI, buffer);
      buffer.append(m_NameName);
    }

    buffer.append(')');
    break;
  }
  case TEST_COMMENT: {
    buffer.append(X("comment()"));
    break;
  }
  case TEST_TEXT: {
    buffer.append(X("text()"));
    break;
  }
  case TEST_NAMESPACE: {
    buffer.append(X("namespace-node()"));
    break;
  }
  case TEST_NODE: {
    buffer.append(X("node()"));
    break;
  }
  case TEST_FUNCTION: {
    if(signature_ == 0) {
      buffer.append(X("function(*)"));
    }
    else {
      addBrackets = addBrackets && signature_->returnType->getOccurrenceIndicator() == SequenceType::EXACTLY_ONE;
      if(addBrackets) buffer.append('(');
      signature_->toBuffer(buffer, /*typeSyntax*/true);
      if(addBrackets) buffer.append(')');
    }
    break;
  }
  case TEST_TUPLE: {
    buffer.append(X("tuple("));

    bool doneOne = false;
    if(tupleMembers_) {
      TupleMembers::iterator i = const_cast<TupleMembers*>(tupleMembers_)->begin();
      for(; i != const_cast<TupleMembers*>(tupleMembers_)->end(); ++i) {
        if(doneOne) buffer.append(',');
        doneOne = true;

        if(i.getValue()->getQName()) {
          buffer.append(i.getValue()->getQName());
        } else {
          if(i.getValue()->getURI()) {
            buffer.append('{');
            buffer.append(i.getValue()->getURI());
            buffer.append('}');
          }
          buffer.append(i.getValue()->getName());
        }

        buffer.append(X(" as "));
        if(forStaticType)
          i.getValue()->getStaticType().typeToBuf(buffer);
        else
          i.getValue()->getType()->toBuffer(buffer);
      }
    }
    buffer.append(')');
    break;
  }
  case TEST_MAP: {
    buffer.append(X("map("));
    if(key_) {
      key_->toBuffer(buffer, forStaticType);
      buffer.append(',');
      value_->toBuffer(buffer, forStaticType);
    }
    buffer.append(')');
    break;
  }
  }
}

bool ItemType::matchesNameType(const Item::Ptr &toBeTested, const DynamicContext* context) const
{
  // Check name constraint
  if(m_NameName) {
    if(toBeTested->getType() == Item::NODE) {
      ATQNameOrDerived::Ptr name = ((const Node*)(const Item*)toBeTested)->dmNodeName(context);
      if(name.isNull()) return false;

      // Match node name
      if(!(XPath2Utils::equals(m_NameName, ((const ATQNameOrDerived*)name.get())->getName())))
        return false;

      // Match node uri
      if(!(XPath2Utils::equals(m_NameURI, ((const ATQNameOrDerived*)name.get())->getURI())))
        return false;
    }
    else return false;
  }

  //A named atomic type matches a value if the dynamic type of the
  //value is the same as the named atomic type or is derived from the
  //named atomic type by restriction. For example, the ItemType
  //xs:decimal matches the value 12.34 (a decimal literal); it also
  //matches a value whose dynamic type is shoesize, if shoesize is an
  //atomic type derived from xs:decimal.

  if(m_TypeName) {
    if(toBeTested->getType() == Item::ATOMIC) {
      return m_primitiveType == ((AnyAtomicType*)toBeTested.get())->getPrimitiveTypeIndex() &&
        ((AnyAtomicType*)toBeTested.get())->isInstanceOfType(m_TypeURI, m_TypeName, context);
    } else if (toBeTested->getType() == Item::NODE) {
      return ((Node*)toBeTested.get())->hasInstanceOfType(m_TypeURI, m_TypeName, context);
    }
    return false;
  }

  return true;
}

bool ItemType::matchesSchemaElement(const Node::Ptr &toBeTested, const DynamicContext* context) const
{
  // retrieve the type of the element name
  assert(m_NameName!=NULL);
  const XMLCh* elementNS=m_NameURI;
  const XMLCh* elementName=m_NameName;
  SchemaElementDecl *elemDecl=context->getDocumentCache()->getElementDecl(elementNS, elementName);
  assert(elemDecl != NULL);

  // 1. The name of the candidate node matches the specified ElementName or matches the name of an element in a 
  //    substitution group headed by an element named ElementName.
  ATQNameOrDerived::Ptr name = toBeTested->dmNodeName(context);
  if(name.isNull()) return false;
  const XMLCh *node_uri = ((const ATQNameOrDerived*)name.get())->getURI();
  const XMLCh *node_name = ((const ATQNameOrDerived*)name.get())->getName();

  if(!(XPath2Utils::equals(elementName, node_name)) ||
     !(XPath2Utils::equals(elementNS, node_uri)))
  {
    // the node doesn't match the ElementName; check if it is in its substitution group
    SchemaElementDecl* thisElemDecl=context->getDocumentCache()->getElementDecl(node_uri, node_name);
    if(thisElemDecl==NULL) // the node to be tested has no type info
      return false;

    SchemaElementDecl* rootElemDecl=thisElemDecl->getSubstitutionGroupElem();
    bool foundIt=false;
    while (rootElemDecl)
    {
      if (XPath2Utils::equals(rootElemDecl->getBaseName(), elementName) &&
          XPath2Utils::equals(context->getDocumentCache()->getSchemaUri(rootElemDecl->getURI()), elementNS))
      {
        foundIt = true;
        break;
      }

      rootElemDecl = rootElemDecl->getSubstitutionGroupElem();
    }
    if(!foundIt)
      return false;
  }

  // 2. derives-from(AT, ET) is true, where AT is the type of the candidate node and ET is the type declared for 
  //    element ElementName in the in-scope element declarations.
  ComplexTypeInfo* pTypeInfo=elemDecl->getComplexTypeInfo();
  if(pTypeInfo && !toBeTested->hasInstanceOfType(pTypeInfo->getTypeUri(), pTypeInfo->getTypeLocalName(), context))
    return false;

  // 3. Either the nilled property of the candidate node is false, or the element declaration for ElementName in 
  //    the in-scope element declarations is nillable.
  if(toBeTested->dmNilled(context).get()->isTrue() &&
     !(elemDecl->getMiscFlags() & SchemaSymbols::XSD_NILLABLE))
    return false;
      
  return true;
}

bool ItemType::matches(const Node::Ptr &toBeTested, DynamicContext* context) const
{
  if(alias_) return alias_->getType()->matches(toBeTested, context);

  switch(m_nTestType) {
    case TEST_ELEMENT:
    {
      if(toBeTested->dmNodeKind() != Node::element_string)
        return false;

      if(!matchesNameType(toBeTested, context))
        return false;

      // if the element has xsi:nil="true", m_bAllowNil MUST be true
      if(toBeTested->dmNilled(context)->isTrue() && !m_bAllowNil)
        return false;

      return true;
    }

    case TEST_ATTRIBUTE:
    {
      if(toBeTested->dmNodeKind() != Node::attribute_string)
        return false;
      if(!matchesNameType(toBeTested, context))
        return false;
      return true;
    }

    case TEST_SCHEMA_ELEMENT:
    {
      if(toBeTested->dmNodeKind() != Node::element_string)
        return false;

      return matchesSchemaElement(toBeTested, context);
    }

    case TEST_SCHEMA_ATTRIBUTE:
    {
      if(toBeTested->dmNodeKind() != Node::attribute_string)
        return false;

      // retrieve the type of the attribute name
      assert(m_NameName!=NULL);
      const XMLCh* attributeNS=m_NameURI;
      const XMLCh* attributeName=m_NameName;
      SchemaAttDef* attrDecl=context->getDocumentCache()->getAttributeDecl(attributeNS, attributeName);
      assert(attrDecl != NULL);

      // 1. The name of the candidate node matches the specified AttributeName
      ATQNameOrDerived::Ptr name = toBeTested->dmNodeName(context);
      if(name.isNull()) return false;
      const XMLCh *node_uri = ((const ATQNameOrDerived*)name.get())->getURI();
      const XMLCh *node_name = ((const ATQNameOrDerived*)name.get())->getName();

      if(!(XPath2Utils::equals(attributeName, node_name)) ||
         !(XPath2Utils::equals(attributeNS, node_uri)))
        return false;

      // 2. derives-from(AT, ET) is true, where AT is the type of the candidate node and ET is the type declared 
      //    for attribute AttributeName in the in-scope attribute declarations.
      DatatypeValidator* pDV=attrDecl->getDatatypeValidator();
      if(pDV && !toBeTested->hasInstanceOfType(pDV->getTypeUri(), pDV->getTypeLocalName(), context))
        return false;

      return true;
    }

    case TEST_PI:
    {
      if(toBeTested->dmNodeKind() != Node::processing_instruction_string)
        return false;
      if(!matchesNameType(toBeTested, context))
        return false;
      return true;
    }

    case TEST_COMMENT:
    {
      return (toBeTested->dmNodeKind() == Node::comment_string);
    }

    case TEST_TEXT:
    {
      return (toBeTested->dmNodeKind() == Node::text_string);
    }

    case TEST_NAMESPACE:
    {
      return (toBeTested->dmNodeKind() == Node::namespace_string);
    }

    case TEST_SCHEMA_DOCUMENT:
    case TEST_DOCUMENT:
    {
        if(toBeTested->dmNodeKind() != Node::document_string)
          return false;

        if(m_NameName == NULL && m_TypeName == NULL)
          return true;

        // if we have a constraint on name/type, they apply to the document element
        Result children = toBeTested->dmChildren(context, 0);
        Node::Ptr docElement;
        while((docElement = children->next(context)).notNull() &&
              docElement->dmNodeKind() != Node::element_string) {}

        if(docElement.isNull()) return false;

        if(m_nTestType == TEST_DOCUMENT)
          return matchesNameType(docElement, context);
        else
          return matchesSchemaElement(docElement, context);
    }

    case TEST_NODE:
    case TEST_ANYTHING:
    {
      return true;
    }

    case TEST_EXPRESSION:
    case TEST_ATOMIC_TYPE:
    case TEST_FUNCTION:
    case TEST_TUPLE:
    case TEST_MAP:
    {
        return false;
    }

  }
  return true;
}

bool ItemType::matches(const FunctionRef::Ptr &toBeTested) const
{
  return matches(toBeTested->getSignature());
}

bool ItemType::matches(const FunctionSignature *sig) const
{
  if(alias_) return alias_->getType()->matches(sig);

  switch(m_nTestType) {
    case TEST_ELEMENT:
    case TEST_ATTRIBUTE:
    case TEST_SCHEMA_ELEMENT:
    case TEST_SCHEMA_ATTRIBUTE:
    case TEST_NODE:
    case TEST_PI:
    case TEST_COMMENT:
    case TEST_TEXT:
    case TEST_DOCUMENT:
    case TEST_SCHEMA_DOCUMENT:
    case TEST_NAMESPACE:
    case TEST_EXPRESSION:
    case TEST_ATOMIC_TYPE:
    case TEST_TUPLE:
    case TEST_MAP:
    {
      return false;
    }
    
    case TEST_ANYTHING:
    {
      return true;
    }

    case TEST_FUNCTION:
    {
      // function(*) matches any function item.
      if(signature_ == 0) return true;

      // A TypedFunctionTest matches an item if it is a function item, and the function
      // item's type signature is a subtype of the TypedFunctionTest.
      if(sig->numArgs() != signature_->numArgs()) return false;

      if(sig->argSpecs && signature_->argSpecs) {
        ArgumentSpecs::const_iterator aa_i = sig->argSpecs->begin();
        ArgumentSpecs::const_iterator ba_i = signature_->argSpecs->begin();
        for(; aa_i != sig->argSpecs->end() && ba_i != signature_->argSpecs->end(); ++aa_i, ++ba_i) {
          if(!(*ba_i)->getType()->isSubtypeOf((*aa_i)->getType())) return false;
        }
      }

      return sig->returnType->isSubtypeOf(signature_->returnType);
    }
  }
  return true;
}

static const XMLCh s_key[] = { 'k', 'e', 'y', 0 };
static const XMLCh s_value[] = { 'v', 'a', 'l', 'u', 'e', 0 };

bool ItemType::matches(const Tuple::Ptr &tuple, DynamicContext* context) const
{
  if(alias_) return alias_->getType()->matches(tuple, context);

  switch(m_nTestType) {
    case TEST_ELEMENT:
    case TEST_ATTRIBUTE:
    case TEST_SCHEMA_ELEMENT:
    case TEST_SCHEMA_ATTRIBUTE:
    case TEST_NODE:
    case TEST_PI:
    case TEST_COMMENT:
    case TEST_TEXT:
    case TEST_DOCUMENT:
    case TEST_SCHEMA_DOCUMENT:
    case TEST_NAMESPACE:
    case TEST_ATOMIC_TYPE:
    {
      return false;
    }
    
    case TEST_ANYTHING:
    {
      return true;
    }

    case TEST_FUNCTION:
    case TEST_EXPRESSION:
    {
      if(signature_ == 0) return true;
      if(signature_->numArgs() != 1) return false;
      return matches(tuple->getSignature());
    }

    case TEST_MAP:
    {
      if(key_ == 0) return true;

      Item::Ptr key = context->getItemFactory()->createString(s_key, context);
      Item::Ptr value = context->getItemFactory()->createString(s_value, context);

      Result entries = tuple->entries(this);
      Item::Ptr item;
      while((item = entries->next(context)).notNull()) {
        if(!key_->matches(((Tuple*)item.get())->get(key), context) ||
           !value_->matches(((Tuple*)item.get())->get(value), context))
          return false;
      }
      return true;
    }
    case TEST_TUPLE:
    {
      if(tupleMembers_ == 0) return true;

      TupleMembers::iterator i = const_cast<TupleMembers*>(tupleMembers_)->begin();
      for(; i != const_cast<TupleMembers*>(tupleMembers_)->end(); ++i) {
        Result value(0);
        tuple->get(i.getValue()->getURI(), i.getValue()->getName(), context, value);
        if(!i.getValue()->getType()->matches(value, context))
          return false;
      }

      return true;
    }
  }
  return true;
}

bool ItemType::matches(const Item::Ptr &toBeTested, DynamicContext* context) const
{
  switch(toBeTested->getType()) {
  case Item::NODE:
     return matches((Node::Ptr)toBeTested, context);
  case Item::FUNCTION:
     return matches((FunctionRef::Ptr)toBeTested);
  case Item::TUPLE:
    return matches((Tuple::Ptr)toBeTested, context);
  case Item::EXPRESSION:
    if(!alias_)
      return m_nTestType == TEST_EXPRESSION;
    break;
  case Item::ATOMIC:
    break;
  }
     
  if(alias_) return alias_->getType()->matches(toBeTested, context);

  switch(m_nTestType) {
    case TEST_ELEMENT:
    case TEST_ATTRIBUTE:
    case TEST_SCHEMA_ELEMENT:
    case TEST_SCHEMA_ATTRIBUTE:
    case TEST_NODE:
    case TEST_PI:
    case TEST_COMMENT:
    case TEST_TEXT:
    case TEST_DOCUMENT:
    case TEST_SCHEMA_DOCUMENT:
    case TEST_NAMESPACE:
    case TEST_FUNCTION:
    case TEST_TUPLE:
    case TEST_MAP:
    {
      return false;
    }
    
    case TEST_ANYTHING:
    {
      return true;
    }

    case TEST_EXPRESSION:
    {
      return toBeTested->getType() == Item::EXPRESSION;
    }

    case TEST_ATOMIC_TYPE:
    {
      if(toBeTested->getType() != Item::ATOMIC) return false;
      if(m_TypeName == 0) return true;
      return matchesNameType(toBeTested, context);
    }
  }
  return true;
}

bool SequenceType::isSubtypeOf(const SequenceType *b, bool forStaticType) const
{
  const SequenceType *a = this;

  if(b == 0) return true;

  if(a == 0)
    return b->m_nOccurrence == SequenceType::STAR && b->m_pItemType &&
      b->m_pItemType->getItemTestType() == ItemType::TEST_ANYTHING;

  if(b->m_pItemType == 0)
    return a->m_pItemType == 0;
  if(a->m_pItemType == 0)
    return b->m_nOccurrence == QUESTION_MARK || b->m_nOccurrence == STAR;

  switch(b->m_nOccurrence) {
  case EXACTLY_ONE:
    if(a->m_nOccurrence != EXACTLY_ONE) return false;
    break;
  case PLUS:
    if(a->m_nOccurrence != EXACTLY_ONE && a->m_nOccurrence != PLUS) return false;
    break;
  case QUESTION_MARK:
    if(a->m_nOccurrence != QUESTION_MARK && a->m_nOccurrence != EXACTLY_ONE) return false;
    break;
  case STAR:
    break;
  }

  return a->m_pItemType->isSubtypeOf(b->m_pItemType, forStaticType);
}

bool ItemType::isSubtypeOfNameType(const ItemType *b) const
{
  const ItemType *a = this;

  if(b->m_NameName) {
    if(a->m_NameName == 0) return false;
    if(!XPath2Utils::equals(a->m_NameName, b->m_NameName) ||
       !XPath2Utils::equals(a->m_NameURI, b->m_NameURI))
      return false;
  }

  if(b->m_TypeName) {
    if(a->m_TypeName == 0) return false;
    if(!b->dc_->isTypeOrDerivedFromType(a->m_TypeURI, a->m_TypeName, b->m_TypeURI, b->m_TypeName))
      return false;
  }

  return true;
}

bool ItemType::isSubtypeOf(const ItemType *b, bool forStaticType) const
{
  const ItemType *a = this;
  while(a->alias_) a = a->alias_->getType();
  while(b->alias_) b = b->alias_->getType();

  switch(b->m_nTestType) {

  case TEST_ATOMIC_TYPE: {
    // Ai and Bi are AtomicTypes, and derives-from(Ai, Bi) returns true.
    if(a->m_nTestType != TEST_ATOMIC_TYPE) return false;
    if(a->m_primitiveType != b->m_primitiveType) {
      if((b->m_primitiveType != AnyAtomicType::DURATION ||
        (a->m_primitiveType != AnyAtomicType::DAY_TIME_DURATION &&
         b->m_primitiveType != AnyAtomicType::YEAR_MONTH_DURATION)))
        return false;
    } else {
      if(b->m_primitive) return true;
      if(a->m_primitive) return false;
    }
    return a->isSubtypeOfNameType(b);
  }

  case TEST_ANYTHING: {
    // Bi is item().
    return true;
  }

  case TEST_EXPRESSION: {
    return a->m_nTestType == TEST_EXPRESSION;
  }

  case TEST_NODE: {
    // Bi is node(), and Ai is a KindTest.
    switch(a->m_nTestType) {
    case TEST_ELEMENT:
    case TEST_ATTRIBUTE:
    case TEST_SCHEMA_ELEMENT:
    case TEST_SCHEMA_ATTRIBUTE:
    case TEST_NODE:
    case TEST_PI:
    case TEST_COMMENT:
    case TEST_TEXT:
    case TEST_DOCUMENT:
    case TEST_SCHEMA_DOCUMENT:
      return true;
    default:
      return false;
    }
  }

  case TEST_TEXT: {
    // Bi is text() and Ai is also text().
    return a->m_nTestType == TEST_TEXT;
  }

  case TEST_COMMENT: {
    // Bi is comment() and Ai is also comment().
    return a->m_nTestType == TEST_COMMENT;
  }

  case TEST_NAMESPACE: {
    // Bi is namespace-node() and Ai is also namespace-node().
    return a->m_nTestType == TEST_NAMESPACE;
  }

  case TEST_PI: {
    // Bi is processing-instruction() and Ai is either processing-instruction() or processing-instruction(N) for any name N..
    // Bi is processing-instruction(Bn), and Ai is also processing-instruction(Bn).
    if(a->m_nTestType != TEST_PI) return false;
    return a->isSubtypeOfNameType(b);
  }

  case TEST_DOCUMENT:
    // Bi is document-node() and Ai is either document-node() or document-node(E) for any ElementTest E.
    // Bi is document-node(Be) and Ai is document-node(Ae), and subtype-itemtype(Ae, Be).
  case TEST_ELEMENT: {
    // Bi is either element() or element(*), and Ai is an ElementTest.
    // Bi is either element(Bn) or element(Bn, xs:anyType), and Ai is either element(Bn), or element(Bn, T) for any type T.
    // Bi is element(Bn, Bt), Ai is element(Bn, At), and derives-from(At, Bt) returns true.
    // Bi is element(Bn, Bt?), Ai is either element(Bn, At), or element(Bn, At?), and derives-from(At, Bt) returns true.
    // Bi is element(*, Bt), Ai is either element(*, At), or element(N, At) for any name N, and derives-from(At, Bt) returns true.
    // Bi is element(*, Bt?), Ai is either element(*, At), element(*, At?), element(N, At), or element(N, At?) for any name N, and derives-from(At, Bt) returns true.
    if(a->m_nTestType != b->m_nTestType) return false;
    if(!a->isSubtypeOfNameType(b)) return false;
    return !a->m_bAllowNil || b->m_bAllowNil;
  }

  case TEST_SCHEMA_DOCUMENT:
    // Bi is document-node() and Ai is either document-node() or document-node(E) for any ElementTest E.
    // Bi is document-node(Be) and Ai is document-node(Ae), and subtype-itemtype(Ae, Be).
  case TEST_SCHEMA_ELEMENT: {
    // Bi is schema-element(Bn), Ai is schema-element(An), and either the expanded QName An equals the expanded QName Bn or
    // the element declaration named An is in the substitution group of the element declaration named Bn.
    if(a->m_nTestType != b->m_nTestType) return false;
    if(a->isSubtypeOfNameType(b)) return true;

    // Check substitution groups
    SchemaElementDecl* aElemDecl = a->dc_->getElementDecl(a->m_NameURI, a->m_NameName);
    while(aElemDecl) {
      if(XPath2Utils::equals(aElemDecl->getBaseName(), b->m_NameName) &&
         XPath2Utils::equals(a->dc_->getSchemaUri(aElemDecl->getURI()), b->m_NameURI))
        return true;
      aElemDecl = aElemDecl->getSubstitutionGroupElem();
    }
    return false;
  }

  case TEST_ATTRIBUTE: {
    // Bi is either attribute() or attribute(*), and Ai is an AttributeTest.
    // Bi is either attribute(Bn) or attribute(Bn, xs:anyType), and Ai is either attribute(Bn), or attribute(Bn, T) for any type T.
    // Bi is attribute(Bn, Bt), Ai is attribute(Bn, At), and derives-from(At, Bt) returns true.
    // Bi is attribute(*, Bt), Ai is either attribute(*, At), or attribute(N, At) for any name N, and derives-from(At, Bt) returns true.
    if(a->m_nTestType != TEST_ATTRIBUTE) return false;
    if(!a->isSubtypeOfNameType(b)) return false;
    return true;
  }

  case TEST_SCHEMA_ATTRIBUTE: {
    // Bi is schema-attribute(Bn) and Ai is also schema-attribute(Bn).
    if(a->m_nTestType != TEST_SCHEMA_ATTRIBUTE) return false;
    return a->isSubtypeOfNameType(b);
  }

  case TEST_FUNCTION: {
    if(a->m_nTestType == TEST_MAP || a->m_nTestType == TEST_TUPLE) {
      if(b->signature_ == 0) return true;
      if(b->signature_->numArgs() != 1) return false;
      if(!(*b->signature_->argSpecs)[0]->getType()->
        isSubtypeOf(&SequenceType::ANY_ATOMIC_TYPE)) return false;
      return SequenceType::ITEM_STAR.isSubtypeOf(b->signature_->returnType);
    }

    // Bi is function(*), and Ai is a FunctionTest.
    if(a->m_nTestType != TEST_FUNCTION) return false;
    if(b->signature_ == 0) return true;
    if(a->signature_ == 0) return false;

    // Bi is function(Ba_1, Ba_2, ... Ba_N) as Br, Ai is function(Aa_1, Aa_2, ... Aa_M) as Ar, N (arity of Bi) equals M (arity of Ai),
    // subtype(Ar, Br), and for values of I between 1 and N, subtype(Ba_I, Aa_I).
    if(a->signature_->numArgs() != b->signature_->numArgs()) return false;

    if(a->signature_->numArgs() != 0) {
      ArgumentSpecs::const_iterator aa_i = a->signature_->argSpecs->begin();
      ArgumentSpecs::const_iterator ba_i = b->signature_->argSpecs->begin();
      for(; aa_i != a->signature_->argSpecs->end() && ba_i != b->signature_->argSpecs->end(); ++aa_i, ++ba_i) {
        if(!(*ba_i)->getType()->isSubtypeOf((*aa_i)->getType())) return false;
      }
    }

    return a->signature_->returnType->isSubtypeOf(b->signature_->returnType);
  }

  case TEST_TUPLE: {
    // Bi is tuple(), and Ai is a MapTest
    if(a->m_nTestType == TEST_MAP) return b->tupleMembers_ == 0;
    if(a->m_nTestType != TEST_TUPLE) return false;

    // Bi is tuple(), and Ai is a TupleTest
    if(b->tupleMembers_ == 0) return true;

    // Bi is tuple(Bn_1 as Bt_1, ... Bn_N as Bt_N), Ai is tuple(An_1 as At_1, ... An_M as At_M)
    // and for I between 1 and N, subtype(type(Ai, Bn_I), type(Bi, Bn_I))
    // where type(T, N) return the type of the member name N from the TupleTest T, or item()* if not specified
    TupleMembers::iterator i = const_cast<TupleMembers*>(b->tupleMembers_)->begin();
    for(; i != const_cast<TupleMembers*>(b->tupleMembers_)->end(); ++i) {
      ArgumentSpec* const *spec = a->tupleMembers_ == 0 ? 0 : a->tupleMembers_->get(i.getKey());
      if(forStaticType) {
        const StaticType &a_type = spec == 0 ? StaticType::ITEM_STAR : (*spec)->getStaticType();
        SequenceType::TypeMatch match = i.getValue()->getType()->matches(a_type);
        if(match.type != SequenceType::ALWAYS || match.cardinality != SequenceType::ALWAYS)
          return false;
      } else {
        const SequenceType *a_type = spec == 0 ? &SequenceType::ITEM_STAR : (*spec)->getType();
        if(!a_type->isSubtypeOf(i.getValue()->getType())) return false;
      }
    }
    return true;
  }
  case TEST_MAP: {
    // Bi is map(), and Ai is a TupleTest
    if(a->m_nTestType == TEST_TUPLE) return b->key_ == 0;
    if(a->m_nTestType != TEST_MAP) return false;

    // Bi is map(), and Ai is a MapTest
    if(b->key_ == 0) return true;

    // Bi is map(Bk, Bv), Ai is map(), subtype(xs:anyAtomicType, Bk), and subtype(item()*, Bv)
    if(a->key_ == 0)
      return SequenceType::ANY_ATOMIC_TYPE.isSubtypeOf(b->key_, forStaticType) &&
        SequenceType::ITEM_STAR.isSubtypeOf(b->value_, forStaticType);

    // Bi is map(Bk, Bv), Ai is map(Ak, Av), subtype(Ak, Bk), and subtype(Av, Bv)
    return a->key_->isSubtypeOf(b->key_, forStaticType) &&
      a->value_->isSubtypeOf(b->value_, forStaticType);
  }
  }
  return true;
}

Result SequenceType::convertFunctionArg(const Result &input, DynamicContext *context, bool xpath1Compat,
                                        const LocationInfo *location, const XMLCh *errorCode)
{
  // From XPath2 Spec, Section 3.1.5 (http://www.w3.org/TR/xpath20/#id-function-calls)

  // The function conversion rules are used to convert an argument value to its expected type; that is, to the
  // declared type of the function parameter. The expected type is expressed as a SequenceType. The function
  // conversion rules are applied to a given value as follows:

  Result result(input);

  if(m_pItemType!=NULL)
  {
    ItemType::ItemTestType testType = getItemTestType();
    // FS says we atomize first if the sequence type is atomic, and I think that's sensible - jpcs
    if(testType == ItemType::TEST_ATOMIC_TYPE) {
      result = new AtomizeResult(location, result);
    }

    // If XPath 1.0 compatibility mode is true and an argument is not of the expected type, then the following
    // conversions are applied sequentially to the argument value V:
    if(xpath1Compat) {
      if(m_nOccurrence == SequenceType::EXACTLY_ONE || m_nOccurrence == SequenceType::QUESTION_MARK) {
        // 1. If the expected type calls for a single item or optional single item (examples: xs:string,
        //    xs:string?, xdt:untypedAtomic, xdt:untypedAtomic?, node(), node()?, item(), item()?), then the
        //    value V is effectively replaced by V[1].
        Item::Ptr item = result->next(context);

        if(testType == ItemType::TEST_ATOMIC_TYPE) {
          const XMLCh* typeURI = m_pItemType->getTypeURI();
          const XMLCh* typeName = m_pItemType->getTypeName();

          // 2. If the expected type is xs:string or xs:string?, then the value V is effectively replaced by
          //    fn:string(V).
          if(XPath2Utils::equals(typeName, SchemaSymbols::fgDT_STRING) &&
             XPath2Utils::equals(typeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
            item = FunctionString::string_item(item, context);
          }

          // 3. If the expected type is xs:double or xs:double?, then the value V is effectively replaced by
          //    fn:number(V).
          else if(XPath2Utils::equals(typeName, SchemaSymbols::fgDT_DOUBLE) &&
                  XPath2Utils::equals(typeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
            item = FunctionNumber::number(item, context, this);
          }
        }

        result = item;
      }
    }
    // If the expected type is a sequence of an atomic type (possibly with an occurrence indicator *, +, or ?),
    // the following conversions are applied:
    else if(testType == ItemType::TEST_ATOMIC_TYPE && m_pItemType->getTypeName() != 0) {
      const XMLCh *uri = m_pItemType->getTypeURI();
      const XMLCh *name = m_pItemType->getTypeName();
      bool isPrimitive = m_pItemType->isPrimitive();
      AnyAtomicType::AtomicObjectType typeIndex = m_pItemType->getPrimitiveType();;

      result = new PromoteUntypedResult(location, result, isPrimitive, typeIndex, uri, name);

      if(XPath2Utils::equals(uri, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
        if(XPath2Utils::equals(name, SchemaSymbols::fgDT_DOUBLE) ||
           XPath2Utils::equals(name, SchemaSymbols::fgDT_FLOAT)) {
          result = new PromoteNumericResult(location, result, typeIndex);
        }

        if(XPath2Utils::equals(name, SchemaSymbols::fgDT_STRING)) {
          result = new PromoteAnyURIResult(location, result);
        }
      }
    }
  }
  // If, after the above conversions, the resulting value does not match the expected type according to the
  // rules for SequenceType Matching, a type error is raised. [err:XPTY0004] Note that the rules for
  // SequenceType Matching permit a value of a derived type to be substituted for a value of its base type.
  return matches(result, location, errorCode);
}

ASTNode *SequenceType::convertFunctionArg(ASTNode *arg, const StaticContext *context, bool numericFunction,
                                          const LocationInfo *location)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  // From XPath2 Spec, Section 3.1.5 (http://www.w3.org/TR/xpath20/#id-function-calls)

  // The function conversion rules are used to convert an argument value to its expected type; that is, to the
  // declared type of the function parameter. The expected type is expressed as a SequenceType. The function
  // conversion rules are applied to a given value as follows:

  if(m_pItemType!=NULL)
  {
    ItemType::ItemTestType testType = getItemTestType();

    // If XPath 1.0 compatibility mode is true and an argument is not of the expected type, then the following
    // conversions are applied sequentially to the argument value V:
    if(context->getXPath1CompatibilityMode()) {
      if(m_nOccurrence == SequenceType::EXACTLY_ONE || m_nOccurrence == SequenceType::QUESTION_MARK) {
        // 1. If the expected type calls for a single item or optional single item (examples: xs:string,
        //    xs:string?, xdt:untypedAtomic, xdt:untypedAtomic?, node(), node()?, item(), item()?), then the
        //    value V is effectively replaced by V[1].
        VectorOfASTNodes headargs = VectorOfASTNodes(XQillaAllocator<ASTNode*>(mm));
        headargs.push_back(arg);
        arg = new (mm) FunctionHead(headargs, mm);
        arg->setLocationInfo(location);

        if(testType == ItemType::TEST_ATOMIC_TYPE) {
          const XMLCh *typeURI = m_pItemType->getTypeURI();
          const XMLCh *typeName = m_pItemType->getTypeName();

          // 2. If the expected type is xs:string or xs:string?, then the value V is effectively replaced by
          //    fn:string(V).
          if(XPath2Utils::equals(typeName, SchemaSymbols::fgDT_STRING) &&
             XPath2Utils::equals(typeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
            VectorOfASTNodes stringargs = VectorOfASTNodes(XQillaAllocator<ASTNode*>(mm));
            stringargs.push_back(arg);
            arg = new (mm) FunctionString(stringargs, mm);
            arg->setLocationInfo(location);
          }

          // 3. If the expected type is xs:double or xs:double?, then the value V is effectively replaced by
          //    fn:number(V).
          else if(XPath2Utils::equals(typeName, SchemaSymbols::fgDT_DOUBLE) &&
                  XPath2Utils::equals(typeURI, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {
            VectorOfASTNodes numberargs = VectorOfASTNodes(XQillaAllocator<ASTNode*>(mm));
            numberargs.push_back(arg);
            arg = new (mm) FunctionNumber(numberargs, mm);
            arg->setLocationInfo(location);
          }
        }
      }
    }
    // If the expected type is a sequence of an atomic type (possibly with an occurrence indicator *, +, or ?),
    // the following conversions are applied:
    if(testType == ItemType::TEST_ATOMIC_TYPE) {
      arg = new (mm) XQAtomize(arg, mm);
      arg->setLocationInfo(location);

      if(numericFunction && m_pItemType->getTypeName() == 0) {
        arg = new (mm) XQPromoteUntyped(arg, (ItemType*)&ItemType::DOUBLE, mm);
        arg->setLocationInfo(location);
      }
      else {
        arg = new (mm) XQPromoteUntyped(arg, m_pItemType, mm);
        arg->setLocationInfo(location);
      }

      arg = new (mm) XQPromoteNumeric(arg, m_pItemType, mm);
      arg->setLocationInfo(location);
      arg = new (mm) XQPromoteAnyURI(arg, m_pItemType, mm);
      arg->setLocationInfo(location);
    }
    else if(testType == ItemType::TEST_FUNCTION && m_pItemType->getFunctionSignature() != 0) {
      arg = new (mm) XQFunctionCoercion(arg, this, mm);
    }
  }
  // If, after the above conversions, the resulting value does not match the expected type according to the
  // rules for SequenceType Matching, a type error is raised. [err:XPTY0004] Note that the rules for
  // SequenceType Matching permit a value of a derived type to be substituted for a value of its base type.
  arg = new (mm) XQTreatAs(arg, this, mm);
  arg->setLocationInfo(location);

  return arg;
}

const ItemType *SequenceType::getItemType() const {
  return m_pItemType;
}

////////////////////////////////////////
// OccurrenceMatchesResult
////////////////////////////////////////

SequenceType::OccurrenceMatchesResult::OccurrenceMatchesResult(const Result &parent, const SequenceType *seqType, const LocationInfo *location, const XMLCh *errorCode)
  : ResultImpl(location),
    _seqType(seqType),
    _parent(parent),
    _errorCode(errorCode),
    _toDo(true)
{
}

Item::Ptr SequenceType::OccurrenceMatchesResult::next(DynamicContext *context)
{
  Item::Ptr item = _parent->next(context);

  // "SequenceType matching between a given value and a given SequenceType is performed as follows:
  //  If the SequenceType is empty, the match succeeds only if the value is an empty sequence."
  if(_seqType->getItemType() == NULL && item.notNull()) {
    XMLBuffer buf;
    buf.set(X("Sequence does not match type "));
    _seqType->toBuffer(buf);
    buf.append(X(" - the sequence contains items ["));
    buf.append(X(" ["));
    buf.append(_errorCode);
    buf.append(X("]"));
    XQThrow(XPath2TypeMatchException, X("SequenceType::OccurrenceMatchesResult::next"), buf.getRawBuffer());
  }
  // "If the SequenceType contains an ItemType and an OccurrenceIndicator, the match succeeds only if 
  //  the number of items in the value matches the OccurrenceIndicator and each of these items matches the ItemType. "
  if(_seqType->getItemType() &&
     (_seqType->getOccurrenceIndicator() == PLUS || _seqType->getOccurrenceIndicator() == EXACTLY_ONE) &&
     item.isNull()) {
    XMLBuffer buf;
    buf.set(X("Sequence does not match type "));
    _seqType->toBuffer(buf);
    buf.append(X(" - the sequence does not contain items ["));
    buf.append(_errorCode);
    buf.append(X("]"));
    XQThrow(XPath2TypeMatchException, X("SequenceType::OccurrenceMatchesResult::next"), buf.getRawBuffer());
  }

  // "If the SequenceType is an ItemType with no OccurrenceIndicator, the match succeeds only if 
  //  the value contains precisely one item and that item matches the ItemType "
  if(_seqType->getItemType() &&
     (_seqType->getOccurrenceIndicator() == EXACTLY_ONE || _seqType->getOccurrenceIndicator() == QUESTION_MARK) &&
     item.notNull()) {
    // Do the tests on the number of items up front,
    // since often functions that cast to a single or
    // optional item only call next once. - jpcs

    Item::Ptr second = _parent->next(context);

    if(second.isNull()) {
      _parent = 0;
    }
    else {
      XMLBuffer buf;
      buf.set(X("Sequence does not match type "));
      _seqType->toBuffer(buf);
      buf.append(X(" - the sequence contains more than one item ["));
      buf.append(_errorCode);
      buf.append(X("]"));
      XQThrow(XPath2TypeMatchException, X("SequenceType::OccurrenceMatchesResult::next"), buf.getRawBuffer());
    }
  }

  if(item.isNull()) {
    *resultPointer_ = 0;
  }
  else {
    *resultPointer_ = _parent;
  }

  return item;
}

////////////////////////////////////////
// TypeMatchesResult
////////////////////////////////////////

SequenceType::TypeMatchesResult::TypeMatchesResult(const Result &parent, const SequenceType *seqType, const LocationInfo *location, const XMLCh *errorCode)
  : ResultImpl(location),
    _seqType(seqType),
    _parent(parent),
    _errorCode(errorCode)
{
}

Item::Ptr SequenceType::TypeMatchesResult::next(DynamicContext *context)
{
  Item::Ptr item = _parent->next(context);
  if(item.isNull()) {
    _parent = 0;
  }
  else if(!_seqType->getItemType()->matches(item, context)) {
    XMLBuffer buf;
    buf.set(X("Sequence does not match type "));
    _seqType->toBuffer(buf);
    buf.append(X(" - found item of type "));
    item->typeToBuffer(context, buf);
    buf.append(X(" ["));
    buf.append(_errorCode);
    buf.append(X("]"));
    XQThrow(XPath2TypeMatchException, X("SequenceType::MatchesResult::next"), buf.getRawBuffer());
  }

  return item;
}

