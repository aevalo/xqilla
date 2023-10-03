/*
 * Copyright (c) 2001, 2008,
 *     DecisionSoft Limited. All rights reserved.
 * Copyright (c) 2004, 2010,
 *     Oracle and/or its affiliates. All rights reserved.
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

#include <assert.h>

#include "../config/xqilla_config.h"

#include <xqilla/ast/StaticType.hpp>
#include <xqilla/ast/XQTypeAlias.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/utils/XStr.hpp>
#include <xqilla/framework/BasicMemoryManager.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

XERCES_CPP_NAMESPACE_USE;

const StaticType StaticType::EMPTY(BasicMemoryManager::get());
const StaticType StaticType::ITEM(&ItemType::ITEM, BasicMemoryManager::get());
const StaticType StaticType::ITEM_STAR(&ItemType::ITEM, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::FUNCTION(&ItemType::FUNCTION, BasicMemoryManager::get());
const StaticType StaticType::TUPLE(&ItemType::TUPLE, BasicMemoryManager::get());
const StaticType StaticType::ANY_ATOMIC_TYPE(&ItemType::ANY_ATOMIC_TYPE, BasicMemoryManager::get());
const StaticType StaticType::UNTYPED_ATOMIC(&ItemType::UNTYPED_ATOMIC, BasicMemoryManager::get());
const StaticType StaticType::STRING(&ItemType::STRING, BasicMemoryManager::get());
const StaticType StaticType::DECIMAL(&ItemType::DECIMAL, BasicMemoryManager::get());
const StaticType StaticType::DECIMAL_QUESTION(&ItemType::DECIMAL, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::FLOAT(&ItemType::FLOAT, BasicMemoryManager::get());
const StaticType StaticType::FLOAT_QUESTION(&ItemType::FLOAT, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::DOUBLE(&ItemType::DOUBLE, BasicMemoryManager::get());
const StaticType StaticType::DOUBLE_QUESTION(&ItemType::DOUBLE, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::QNAME(&ItemType::QNAME, BasicMemoryManager::get());
const StaticType StaticType::QNAME_QUESTION(&ItemType::QNAME, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::BOOLEAN(&ItemType::BOOLEAN, BasicMemoryManager::get());
const StaticType StaticType::BOOLEAN_QUESTION(&ItemType::BOOLEAN, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::DAY_TIME_DURATION(&ItemType::DAY_TIME_DURATION, BasicMemoryManager::get());
const StaticType StaticType::NODE(&ItemType::NODE, BasicMemoryManager::get());
const StaticType StaticType::NODE_QUESTION(&ItemType::NODE, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::NODE_STAR(&ItemType::NODE, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::DOCUMENT(&ItemType::DOCUMENT, BasicMemoryManager::get());
const StaticType StaticType::DOCUMENT_QUESTION(&ItemType::DOCUMENT, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::DOCUMENT_STAR(&ItemType::DOCUMENT, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::ELEMENT(&ItemType::ELEMENT, BasicMemoryManager::get());
const StaticType StaticType::ATTRIBUTE(&ItemType::ATTRIBUTE, BasicMemoryManager::get());
const StaticType StaticType::TEXT(&ItemType::TEXT, BasicMemoryManager::get());
const StaticType StaticType::TEXT_QUESTION(&ItemType::TEXT, 0, 1, BasicMemoryManager::get());
const StaticType StaticType::TEXT_STAR(&ItemType::TEXT, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::PI(&ItemType::PI, BasicMemoryManager::get());
const StaticType StaticType::PI_STAR(&ItemType::PI, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::COMMENT(&ItemType::COMMENT, BasicMemoryManager::get());
const StaticType StaticType::COMMENT_STAR(&ItemType::COMMENT, 0, StaticType::UNLIMITED, BasicMemoryManager::get());
const StaticType StaticType::NAMESPACE(&ItemType::NAMESPACE, BasicMemoryManager::get());

TypeFlags::Enum flagsForAtomicType(AnyAtomicType::AtomicObjectType type)
{
  switch(type) {
  case AnyAtomicType::ANY_URI: return TypeFlags::ANY_URI;
  case AnyAtomicType::BASE_64_BINARY: return TypeFlags::BASE_64_BINARY;
  case AnyAtomicType::BOOLEAN: return TypeFlags::BOOLEAN;
  case AnyAtomicType::DATE: return TypeFlags::DATE;
  case AnyAtomicType::DATE_TIME: return TypeFlags::DATE_TIME;
  case AnyAtomicType::DAY_TIME_DURATION: return TypeFlags::DAY_TIME_DURATION;
  case AnyAtomicType::DECIMAL: return TypeFlags::DECIMAL;
  case AnyAtomicType::DOUBLE: return TypeFlags::DOUBLE;
  case AnyAtomicType::DURATION: return TypeFlags::DURATION | TypeFlags::DAY_TIME_DURATION | TypeFlags::YEAR_MONTH_DURATION;
  case AnyAtomicType::FLOAT: return TypeFlags::FLOAT;
  case AnyAtomicType::G_DAY: return TypeFlags::G_DAY;
  case AnyAtomicType::G_MONTH: return TypeFlags::G_MONTH;
  case AnyAtomicType::G_MONTH_DAY: return TypeFlags::G_MONTH_DAY;
  case AnyAtomicType::G_YEAR: return TypeFlags::G_YEAR;
  case AnyAtomicType::G_YEAR_MONTH: return TypeFlags::G_YEAR_MONTH;
  case AnyAtomicType::HEX_BINARY: return TypeFlags::HEX_BINARY;
  case AnyAtomicType::NOTATION: return TypeFlags::NOTATION;
  case AnyAtomicType::QNAME: return TypeFlags::QNAME;
  case AnyAtomicType::STRING: return TypeFlags::STRING;
  case AnyAtomicType::TIME: return TypeFlags::TIME;
  case AnyAtomicType::UNTYPED_ATOMIC: return TypeFlags::UNTYPED_ATOMIC;
  case AnyAtomicType::YEAR_MONTH_DURATION: return TypeFlags::YEAR_MONTH_DURATION;
  case AnyAtomicType::NumAtomicObjectTypes: return TypeFlags::ANY_ATOMIC_TYPE;
  }

  return TypeFlags::EMPTY;
}

static inline TypeFlags::Enum flagsForItemType(const ItemType *type)
{
  switch(type->getItemTestType()) {
  case ItemType::TEST_ANYTHING:
    return TypeFlags::ITEM;
  case ItemType::TEST_SCHEMA_ELEMENT:
  case ItemType::TEST_ELEMENT:
    return TypeFlags::ELEMENT;
  case ItemType::TEST_SCHEMA_ATTRIBUTE:
  case ItemType::TEST_ATTRIBUTE:
    return TypeFlags::ATTRIBUTE;
  case ItemType::TEST_SCHEMA_DOCUMENT:
  case ItemType::TEST_DOCUMENT:
    return TypeFlags::DOCUMENT;
  case ItemType::TEST_NODE:
    return TypeFlags::NODE;
  case ItemType::TEST_PI:
    return TypeFlags::PI;
  case ItemType::TEST_COMMENT:
    return TypeFlags::COMMENT;
  case ItemType::TEST_TEXT:
    return TypeFlags::TEXT;
  case ItemType::TEST_NAMESPACE:
    return TypeFlags::NAMESPACE;
  case ItemType::TEST_ATOMIC_TYPE:
    return flagsForAtomicType(type->getPrimitiveType());
  case ItemType::TEST_FUNCTION:
    return TypeFlags::FUNCTION;
  case ItemType::TEST_TUPLE:
  case ItemType::TEST_MAP:
    return (TypeFlags::Enum)TypeFlags::TUPLE|TypeFlags::FUNCTION;
  case ItemType::TEST_EXPRESSION:
    return TypeFlags::EXPRESSION;
  }

  return TypeFlags::EMPTY;
}

bool ItemType::intersects(const ItemType *b) const
{
  if(alias_) return alias_->getType()->intersects(b);

  TypeFlags::Enum aflags = flagsForItemType(this);
  TypeFlags::Enum bflags = flagsForItemType(b);
  return (aflags & bflags) != 0;
}

static inline bool flagsIntersect(const ItemType *type, TypeFlags::Enum flags)
{
  TypeFlags::Enum tflags = flagsForItemType(type);
  return ((tflags & flags) != 0);
}

static inline bool flagsSubtype(const ItemType *type, TypeFlags::Enum flags)
{
  TypeFlags::Enum tflags = flagsForItemType(type);
  return ((tflags & flags) != 0) && (tflags & ~flags) == 0;
}

static inline void normalizedPushBack(StaticType::ItemTypes &newTypes, const ItemType *type)
{
  // Keep the StaticType normalized
  StaticType::ItemTypes::iterator i = newTypes.begin();
  while(i != newTypes.end()) {
    if(type->isSubtypeOf(*i))
      return;
    if((*i)->isSubtypeOf(type))
      newTypes.erase(i);
    else ++i;
  }
  newTypes.push_back(type);
}

static void addItemTypesFromFlags(TypeFlags::Enum tflags, StaticType::ItemTypes &newTypes)
{
#define ADD_ITEMTYPE_FOR(type) \
  if((tflags & TypeFlags::type) == TypeFlags::type) { \
    normalizedPushBack(newTypes, &ItemType::type); \
    tflags = tflags & (TypeFlags::Enum)~TypeFlags::type; \
  }

  ADD_ITEMTYPE_FOR(NODE);
  ADD_ITEMTYPE_FOR(ANY_ATOMIC_TYPE);
  ADD_ITEMTYPE_FOR(DOCUMENT);
  ADD_ITEMTYPE_FOR(ELEMENT);
  ADD_ITEMTYPE_FOR(ATTRIBUTE);
  ADD_ITEMTYPE_FOR(TEXT);
  ADD_ITEMTYPE_FOR(PI);
  ADD_ITEMTYPE_FOR(COMMENT);
  ADD_ITEMTYPE_FOR(NAMESPACE);
  ADD_ITEMTYPE_FOR(ANY_URI);
  ADD_ITEMTYPE_FOR(BASE_64_BINARY);
  ADD_ITEMTYPE_FOR(BOOLEAN);
  ADD_ITEMTYPE_FOR(DATE);
  ADD_ITEMTYPE_FOR(DATE_TIME);
  ADD_ITEMTYPE_FOR(DAY_TIME_DURATION);
  ADD_ITEMTYPE_FOR(DECIMAL);
  ADD_ITEMTYPE_FOR(DOUBLE);
  ADD_ITEMTYPE_FOR(DURATION);
  ADD_ITEMTYPE_FOR(FLOAT);
  ADD_ITEMTYPE_FOR(G_DAY);
  ADD_ITEMTYPE_FOR(G_MONTH);
  ADD_ITEMTYPE_FOR(G_MONTH_DAY);
  ADD_ITEMTYPE_FOR(G_YEAR);
  ADD_ITEMTYPE_FOR(G_YEAR_MONTH);
  ADD_ITEMTYPE_FOR(HEX_BINARY);
  ADD_ITEMTYPE_FOR(NOTATION);
  ADD_ITEMTYPE_FOR(QNAME);
  ADD_ITEMTYPE_FOR(STRING);
  ADD_ITEMTYPE_FOR(TIME);
  ADD_ITEMTYPE_FOR(UNTYPED_ATOMIC);
  ADD_ITEMTYPE_FOR(YEAR_MONTH_DURATION);
  ADD_ITEMTYPE_FOR(FUNCTION);
  ADD_ITEMTYPE_FOR(TUPLE);
  ADD_ITEMTYPE_FOR(EXPRESSION);
}

static inline bool intersectItemType(const ItemType *type, TypeFlags::Enum flags,
                                     StaticType::ItemTypes &newTypes)
{
  TypeFlags::Enum tflags = flagsForItemType(type);

  if((tflags & flags) == 0) return true;

  if((tflags & ~flags) == 0) {
    normalizedPushBack(newTypes, type);
    return false;
  }

  addItemTypesFromFlags(tflags & flags, newTypes);
  return true;
}

const unsigned int StaticType::UNLIMITED = (unsigned int)-1;

StaticType::StaticType(MemoryManager *mm)
  : types_(XQillaAllocator<const ItemType*>(mm)),
    min_(0),
    max_(0)
{
}

StaticType::StaticType(const StaticType &o, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm)
  : types_(XQillaAllocator<const ItemType*>(mm)),
    min_(0),
    max_(0)
{
  *this = o;
}

StaticType::StaticType(const ItemType *type, MemoryManager *mm)
  : types_(XQillaAllocator<const ItemType*>(mm)),
    min_(1),
    max_(1)
{
  types_.push_back(type);
}

StaticType::StaticType(const ItemType *type, unsigned int min, unsigned int max, MemoryManager *mm)
  : types_(XQillaAllocator<const ItemType*>(mm)),
    min_(min),
    max_(max)
{
  types_.push_back(type);
}

StaticType::StaticType(const SequenceType *type, MemoryManager *mm)
  : types_(XQillaAllocator<const ItemType*>(mm)),
    min_(0),
    max_(0)
{
  *this = type;
}

StaticType &StaticType::operator=(const StaticType &o)
{
  types_.clear();

  ItemTypes::const_iterator i = o.types_.begin();
  for(; i != o.types_.end(); ++i) {
    types_.push_back(*i);
  }

  min_ = o.min_;
  max_ = o.max_;

  return *this;
}

StaticType &StaticType::operator=(const ItemType *type)
{
  types_.clear();

  types_.push_back(type);

  min_ = 1;
  max_ = 1;

  return *this;
}

StaticType &StaticType::operator=(const SequenceType *type)
{
  clear();

  if(!type) {
    types_.push_back(&ItemType::ITEM);
    min_ = 0; max_ = UNLIMITED;
  } else if(type->getItemType()) {
    types_.push_back(type->getItemType());
    switch(type->getOccurrenceIndicator()) {
    case SequenceType::EXACTLY_ONE:
      min_ = 1; max_ = 1; break;
    case SequenceType::STAR:
      min_ = 0; max_ = UNLIMITED; break;
    case SequenceType::PLUS:
      min_ = 1; max_ = UNLIMITED; break;
    case SequenceType::QUESTION_MARK:
      min_ = 0; max_ = 1; break;
    }
  }

  return *this;
}

StaticType::~StaticType()
{
}

void StaticType::release()
{
#if defined(_MSC_VER) || defined(__xlC__)
  types_.~ItemTypes();
#else
  types_.~vector<const ItemType*, XQillaAllocator<const ItemType*> >();
#endif
}

void StaticType::clear()
{
  types_.clear();
  min_ = 0; max_ = 0;
}

bool StaticType::containsType(TypeFlags::Enum flags) const
{
  ItemTypes::const_iterator i = types_.begin();
  for(; i != types_.end(); ++i) {
    if(flagsIntersect(*i, flags)) return true;
  }
  return false;
}

bool StaticType::isType(TypeFlags::Enum flags) const
{
  if(max_ == 0) return flags == 0;

  ItemTypes::const_iterator i = types_.begin();
  for(; i != types_.end(); ++i) {
    if(!flagsSubtype(*i, flags)) return false;
  }
  return true;
}

bool StaticType::containsType(const StaticType &type) const
{
  // Could be more accurate by using ItemType::isSubtypeOf(),
  // but this will do for now.
  ItemTypes::const_iterator i = type.types_.begin();
  for(; i != type.types_.end(); ++i) {
    if(containsType(flagsForItemType(*i))) return true;
  }
  return false;
}

void StaticType::typeUnion(const StaticType &st)
{
  min_ = (min_ < st.min_) ? min_ : st.min_;
  max_ = (max_ > st.max_) ? max_ : st.max_;

  ItemTypes::const_iterator i = st.types_.begin();
  for(; i != st.types_.end(); ++i) {
    normalizedPushBack(types_, *i);
  }
}

void StaticType::typeConcat(const StaticType &st)
{
  min_ += st.min_;
  if(max_ == UNLIMITED || st.max_ == UNLIMITED)
    max_ = UNLIMITED;
  else max_ += st.max_;

  ItemTypes::const_iterator i = st.types_.begin();
  for(; i != st.types_.end(); ++i) {
    normalizedPushBack(types_, *i);
  }
}

bool StaticType::typeIntersect(TypeFlags::Enum st)
{
  ItemTypes newTypes(XQillaAllocator<const ItemType*>(BasicMemoryManager::get()));

  bool result = false;
  ItemTypes::iterator i = types_.begin();
  for(;i != types_.end(); ++i) {
    result = intersectItemType(*i, st, newTypes) || result;
  }

  types_ = newTypes;
  if(types_.empty() || max_ == 0)
    clear();

  return result;
}

void StaticType::typeIntersect(const StaticType &st)
{
  min_ = (min_ > st.min_) ? min_ : st.min_;
  max_ = (max_ < st.max_) ? max_ : st.max_;

  // Could be more accurate by using ItemType::isSubtypeOf(),
  // but this will do for now.
  TypeFlags::Enum flags = TypeFlags::EMPTY;
  ItemTypes::const_iterator i = st.types_.begin();
  for(; i != st.types_.end(); ++i) {
    flags = flags | flagsForItemType(*i);
  }
  typeIntersect(flags);
}

bool StaticType::typeExcept(TypeFlags::Enum flags)
{
  return typeIntersect((TypeFlags::Enum)~flags);
}

bool StaticType::substitute(TypeFlags::Enum from, const StaticType &to)
{
  if(!typeExcept(from)) return false;
  typeUnion(to);
  return true;
}

bool StaticType::substitute(TypeFlags::Enum from, const ItemType *to)
{
  StaticType tmp(to, BasicMemoryManager::get());
  return substitute(from, tmp);;
}

void StaticType::multiply(unsigned int min, unsigned int max)
{
  assert(min <= max);
  assert(min != UNLIMITED);

  min_ *= min;

  if(max == UNLIMITED || max_ == UNLIMITED)
    max_ = UNLIMITED;
  else max_ *= max;

  if(max_ == 0) clear();
}

void StaticType::setCardinality(unsigned int min, unsigned int max)
{
  assert(min <= max);
  assert(min != UNLIMITED);

  min_ = min;
  max_ = max;

  if(max_ > 0 && types_.empty()) types_.push_back(&ItemType::ITEM);
  else if(max_ == 0) clear();
}

void StaticType::typeToBuf(XMLBuffer &result) const
{
  if(types_.empty() || max_ == 0) {
    result.append(X("empty-sequence()"));
    return;
  }

  int count = 0;
  XMLBuffer buf;

  ItemTypes::const_iterator i = types_.begin();
  for(; i != types_.end(); ++i) {
    if(count++) buf.append(X(" | "));
    (*i)->toBuffer(buf, true);
  }
  
  if(count > 1) {
    result.append(X("("));
    result.append(buf.getRawBuffer());
    result.append(X(")"));
  }
  else {
    result.append(buf.getRawBuffer());
  }

  if(min_ == 0 && max_ == 1) {
    result.append(X("?"));
  }
  else if(min_ == 0 && max_ == StaticType::UNLIMITED) {
    result.append(X("*"));
  }
  else if(min_ == 1 && max_ == StaticType::UNLIMITED) {
    result.append(X("+"));
  }
  else if(min_ == 1 && max_ == 1) {
    // nothing
  }
  else {
    result.append(X("{"));

    XPath2Utils::numToBuf(min_, result);
    result.append(X(","));
    if(max_ == UNLIMITED)
      result.append(X("unlimited"));
    else XPath2Utils::numToBuf(max_, result);

    result.append(X("}"));
  }
}

TypeFlags::Enum operator|(TypeFlags::Enum a, TypeFlags::Enum b)
{
  return (TypeFlags::Enum)((uint64_t)a|(uint64_t)b);
}

TypeFlags::Enum operator&(TypeFlags::Enum a, TypeFlags::Enum b)
{
  return (TypeFlags::Enum)((uint64_t)a&(uint64_t)b);
}
