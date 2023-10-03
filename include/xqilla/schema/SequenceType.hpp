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

#ifndef _SEQUENCETYPE_HPP
#define _SEQUENCETYPE_HPP

#include <xqilla/framework/XQillaExport.hpp>

#include <xqilla/items/AnyAtomicType.hpp>
#include <xqilla/items/Node.hpp>
#include <xqilla/items/FunctionRef.hpp>
#include <xqilla/items/Tuple.hpp>
#include <xqilla/parser/QName.hpp>
#include <xqilla/runtime/Result.hpp>
#include <xqilla/runtime/ResultImpl.hpp>
#include <xqilla/utils/HashMap.hpp>

class Item;
class XPath2MemoryManager;
class SequenceType;
class FunctionSignature;
class ASTNode;
class StaticType;
class DocumentCache;
class XQTypeAlias;
class ArgumentSpec;

typedef HashMap<const XMLCh*, ArgumentSpec*> TupleMembers;

class XQILLA_API ItemType : public LocationInfo
{
public:
  static const ItemType ITEM;

  static const ItemType ANY_ATOMIC_TYPE;
  static const ItemType UNTYPED_ATOMIC;
  static const ItemType BOOLEAN;
  static const ItemType DECIMAL;
  static const ItemType FLOAT;
  static const ItemType DOUBLE;
  static const ItemType STRING;
  static const ItemType QNAME;
  static const ItemType DAY_TIME_DURATION;
  static const ItemType ANY_URI;
  static const ItemType BASE_64_BINARY;
  static const ItemType DATE;
  static const ItemType DATE_TIME;
  static const ItemType DURATION;
  static const ItemType G_DAY;
  static const ItemType G_MONTH;
  static const ItemType G_MONTH_DAY;
  static const ItemType G_YEAR;
  static const ItemType G_YEAR_MONTH;
  static const ItemType HEX_BINARY;
  static const ItemType NOTATION;
  static const ItemType TIME;
  static const ItemType YEAR_MONTH_DURATION;
  static const ItemType INTEGER;

  static const ItemType NODE;
  static const ItemType DOCUMENT;
  static const ItemType ELEMENT;
  static const ItemType ATTRIBUTE;
  static const ItemType TEXT;
  static const ItemType PI;
  static const ItemType COMMENT;
  static const ItemType NAMESPACE;

  static const ItemType FUNCTION;
  static const ItemType TUPLE;
  static const ItemType MAP;
  static const ItemType EXPRESSION;

  /**
   * The type of item that this sequence can hold.
   */
  typedef enum {
    TEST_ELEMENT,      ///< element node
    TEST_ATTRIBUTE,    ///< attribute node
    TEST_SCHEMA_ELEMENT,      ///< element node
    TEST_SCHEMA_ATTRIBUTE,    ///< attribute node
    TEST_SCHEMA_DOCUMENT,     ///< document node
    TEST_NODE,         ///< node
    TEST_PI,           ///< processing instruction node
    TEST_COMMENT,      ///< comment node
    TEST_TEXT,         ///< text node
    TEST_DOCUMENT,     ///< document node
    TEST_NAMESPACE,    ///< namespace node
    TEST_ANYTHING,     ///< any item
    TEST_ATOMIC_TYPE,  ///< the named atomic type
    TEST_FUNCTION,     ///< function
    TEST_TUPLE,        ///< tuple
    TEST_MAP,          ///< map
    TEST_EXPRESSION    ///< expression
  } ItemTestType;

  // Normal constructor
  ItemType(ItemTestType test, QualifiedName* name=NULL, QualifiedName* type=NULL);
  // Constructor for a function
  ItemType(FunctionSignature *signature, const DocumentCache *dc);
  // Constructor for a tuple
  ItemType(const TupleMembers *members, const DocumentCache *dc);
  // Constructor for a map
  ItemType(SequenceType *key, SequenceType *value, const DocumentCache *dc);

  // Constructor for static const ItemTypes
  ItemType(ItemTestType test, const DocumentCache *dc);
  // Constructor for static const atomic type ItemTypes
  ItemType(AnyAtomicType::AtomicObjectType primitiveType, bool primitive,
           const XMLCh *typeURI, const XMLCh *typeName, const DocumentCache *dc);

  ~ItemType();

  /**
   * Getter for m_nTestType
   */
  ItemTestType getItemTestType() const;
  void setItemTestType(ItemTestType t);

  bool isPrimitive() const;
  AnyAtomicType::AtomicObjectType getPrimitiveType() const;

  void setAllowNilled(bool value);
  bool getAllowNilled() const;

  const XMLCh *getTypePrefix() const;
  const XMLCh *getTypeURI() const;
  const XMLCh *getTypeName() const;
  const XMLCh *getNamePrefix() const;
  const XMLCh *getNameURI() const;
  const XMLCh *getNameName() const;

  FunctionSignature *getFunctionSignature() const;
  const TupleMembers *getTupleMembers() const;
  SequenceType *getKeyType() const;
  SequenceType *getValueType() const;
  const DocumentCache *getDocumentCache() const;

  bool matches(const Item::Ptr &toBeTested, DynamicContext* context) const;
  bool matches(const Node::Ptr &toBeTested, DynamicContext* context) const;
  bool matches(const FunctionRef::Ptr &toBeTested) const;
  bool matches(const Tuple::Ptr &tuple, DynamicContext* context) const;
  bool matches(const FunctionSignature *sig) const;

  bool isSubtypeOf(const ItemType *toBeTested, bool forStaticType = false) const;
  bool intersects(const ItemType *toBeTested) const;

  ItemType *staticResolution(StaticContext *context, const LocationInfo *location);

  void toBuffer(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buffer, bool forStaticType = false,
                bool addBrackets = false) const;

private:
  bool matchesNameType(const Item::Ptr &toBeTested, const DynamicContext* context) const;
  bool matchesSchemaElement(const Node::Ptr &toBeTested, const DynamicContext* context) const;
  bool isSubtypeOfNameType(const ItemType *toBeTested) const;

  // The type alias that gives us our real ItemType
  const XQTypeAlias *alias_;

  // The ItemTestType of this ItemType
  ItemTestType m_nTestType;

  // The primitive type of TEST_ATOMIC_TYPE
  AnyAtomicType::AtomicObjectType m_primitiveType;
  bool m_primitive;

  // The name and type to match
  const XMLCh *m_NamePrefix, *m_NameURI, *m_NameName;
  const XMLCh *m_TypePrefix, *m_TypeURI, *m_TypeName;

  // allow elements having the xsi:nil="true" attribute
  bool m_bAllowNil;

  // The signature of the required function
  FunctionSignature *signature_;

  // The tuple members
  const TupleMembers *tupleMembers_;

  // Key and value type of map
  SequenceType *key_;
  SequenceType *value_;

  const DocumentCache *dc_;
  bool staticallyResolved_;
};

class XQILLA_API SequenceType : public LocationInfo
{
public:
  static const SequenceType ANY_ATOMIC_TYPE;
  static const SequenceType ITEM_STAR;

  /**
   * Number of occurrences of the ItemType.
   * STAR specifies zero or more occurrences.
   * PLUS specifies one or more occurrences.
   * QUESTION_MARK specifies zero or one occurrence.
   */
  typedef enum 
  {
    EXACTLY_ONE=0,
    STAR=1,
    PLUS=2,
    QUESTION_MARK=3
  } OccurrenceIndicator;

  /**
   * Generic constructor.
   */
  SequenceType(ItemType* test, OccurrenceIndicator occur = EXACTLY_ONE);

  /**
   * Default constructor.
   */
  SequenceType();

  /**
   * Destructor.
   */
  virtual ~SequenceType();

  /**
   * Setter for m_nOccurrencer.
   */
  void setOccurrence(OccurrenceIndicator nOccurrence);

  /**
   * Returns a Result that will throw an XPath2TypeMatchException if
   * the toBeTested Result doesn't match this SequenceType.
   */
  bool matches(const Result &toBeTested, DynamicContext *context) const;
  Result matches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const;
  Result occurrenceMatches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const;
  Result typeMatches(const Result &toBeTested, const LocationInfo *location, const XMLCh *errorCode) const;

  Result convertFunctionArg(const Result &input, DynamicContext *context, bool xpath1Compat,
                            const LocationInfo *location, const XMLCh *errorCode);
  ASTNode *convertFunctionArg(ASTNode *arg, const StaticContext *context, bool numericFunction,
                              const LocationInfo *location);

  enum TypeMatchEnum {
    NEVER = 0,
    PROBABLY_NOT = 1,
    MAYBE = 2,
    ALWAYS = 3
  };

  struct TypeMatch
  {
    TypeMatchEnum type, cardinality;
  };

  TypeMatch matches(const StaticType &actual) const;

  /**
   * Getter for m_pItemType.
   */
  ItemType::ItemTestType getItemTestType() const;

  /**
   * Getter for m_nOccurrence.
   */
  OccurrenceIndicator getOccurrenceIndicator() const;

  const ItemType *getItemType() const;

  bool isSubtypeOf(const SequenceType *toBeTested, bool forStaticType = false) const;

  void staticResolution(StaticContext* context);

  void toBuffer(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buffer, bool forStaticType = false) const;

protected:

  // The ItemType of this SequenceType
  ItemType* m_pItemType;
  
  // The OccurrenceIndicator of this SequenceType
  OccurrenceIndicator m_nOccurrence;

  class OccurrenceMatchesResult : public ResultImpl
  {
  public:
    OccurrenceMatchesResult(const Result &parent, const SequenceType *seqType, const LocationInfo *location, const XMLCh *errorCode);

    Item::Ptr next(DynamicContext *context);
  private:
    const SequenceType *_seqType;
    Result _parent;
    const XMLCh *_errorCode;
    bool _toDo;
  };

  class TypeMatchesResult : public ResultImpl
  {
  public:
    TypeMatchesResult(const Result &parent, const SequenceType *seqType, const LocationInfo *location, const XMLCh *errorCode);

    Item::Ptr next(DynamicContext *context);
  private:
    const SequenceType *_seqType;
    Result _parent;
    const XMLCh *_errorCode;
  };
};

#endif
