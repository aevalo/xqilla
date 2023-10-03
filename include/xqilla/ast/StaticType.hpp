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

#ifndef _STATICTYPE_HPP
#define _STATICTYPE_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/items/AnyAtomicType.hpp>
#include <xqilla/framework/XPath2MemoryManager.hpp>
#include <xqilla/schema/SequenceType.hpp>

#include <xercesc/framework/XMLBuffer.hpp>
#include <xercesc/util/XMemory.hpp>

struct XQILLA_API TypeFlags
{
  /**
   * Flags that determine what item types are returned from an expression
   */
  enum Enum {
    DOCUMENT            = 0x000000001,
    ELEMENT             = 0x000000002,
    ATTRIBUTE           = 0x000000004,
    TEXT                = 0x000000008,
    PI                  = 0x000000010,
    COMMENT             = 0x000000020,
    NAMESPACE           = 0x000000040,

    ANY_URI             = 0x000000100,
    BASE_64_BINARY      = 0x000000200,
    BOOLEAN             = 0x000000400,
    DATE                = 0x000000800,
    DATE_TIME           = 0x000001000,
    DAY_TIME_DURATION   = 0x000002000,
    DECIMAL             = 0x000004000,
    DOUBLE              = 0x000008000,
    DURATION            = 0x000010000,
    FLOAT               = 0x000020000,
    G_DAY               = 0x000040000,
    G_MONTH             = 0x000080000,
    G_MONTH_DAY         = 0x000100000,
    G_YEAR              = 0x000200000,
    G_YEAR_MONTH        = 0x000400000,
    HEX_BINARY          = 0x000800000,
    NOTATION            = 0x001000000,
    QNAME               = 0x002000000,
    STRING              = 0x004000000,
    TIME                = 0x008000000,
    UNTYPED_ATOMIC      = 0x010000000,
    YEAR_MONTH_DURATION = 0x020000000,

    FUNCTION            = 0x040000000,
    TUPLE               = 0x080000000,
    EXPRESSION          = 0x000000080,

    NODE                = (DOCUMENT | ELEMENT | ATTRIBUTE | TEXT | PI | COMMENT |
                           NAMESPACE),

    NUMERIC             = (DECIMAL | FLOAT | DOUBLE),

    TIMEZONE            = (DATE | DATE_TIME | G_DAY | G_MONTH | G_MONTH_DAY |
                           G_YEAR | G_YEAR_MONTH | TIME),

    TYPED_ATOMIC        = (NUMERIC | TIMEZONE | ANY_URI | BASE_64_BINARY |
                           BOOLEAN | DAY_TIME_DURATION | DURATION | HEX_BINARY |
                           NOTATION | QNAME | STRING | YEAR_MONTH_DURATION),

    ANY_ATOMIC_TYPE     = (TYPED_ATOMIC | UNTYPED_ATOMIC),

    ITEM                = (NODE | ANY_ATOMIC_TYPE | FUNCTION | TUPLE | EXPRESSION),

    EMPTY               = 0
  };
};

XQILLA_API TypeFlags::Enum operator|(TypeFlags::Enum a, TypeFlags::Enum b);
XQILLA_API TypeFlags::Enum operator&(TypeFlags::Enum a, TypeFlags::Enum b);

/**
 * Class that represents the static type of an expression
 */
class XQILLA_API StaticType : public XERCES_CPP_NAMESPACE_QUALIFIER XMemory {
public:
  static const StaticType EMPTY;

  static const StaticType ITEM;
  static const StaticType ITEM_STAR;
  static const StaticType FUNCTION;
  static const StaticType TUPLE;

  static const StaticType ANY_ATOMIC_TYPE;
  static const StaticType UNTYPED_ATOMIC;
  static const StaticType STRING;
  static const StaticType DECIMAL;
  static const StaticType DECIMAL_QUESTION;
  static const StaticType FLOAT;
  static const StaticType FLOAT_QUESTION;
  static const StaticType DOUBLE;
  static const StaticType DOUBLE_QUESTION;
  static const StaticType QNAME;
  static const StaticType QNAME_QUESTION;
  static const StaticType BOOLEAN;
  static const StaticType BOOLEAN_QUESTION;
  static const StaticType DAY_TIME_DURATION;

  static const StaticType NODE;
  static const StaticType NODE_QUESTION;
  static const StaticType NODE_STAR;
  static const StaticType DOCUMENT;
  static const StaticType DOCUMENT_QUESTION;
  static const StaticType DOCUMENT_STAR;
  static const StaticType ELEMENT;
  static const StaticType ATTRIBUTE;
  static const StaticType TEXT;
  static const StaticType TEXT_QUESTION;
  static const StaticType TEXT_STAR;
  static const StaticType PI;
  static const StaticType PI_STAR;
  static const StaticType COMMENT;
  static const StaticType COMMENT_STAR;
  static const StaticType NAMESPACE;

  typedef std::vector<const ItemType*, XQillaAllocator<const ItemType*> > ItemTypes;

  static const unsigned int UNLIMITED;

  /// Constructor for an empty type
  StaticType(XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm);
  /// "Copy" constructor
  StaticType(const StaticType &o, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm);
  // Constructor for single type
  StaticType(const ItemType *type, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm);
  // Constructor for a range of types
  StaticType(const ItemType *type, unsigned int min, unsigned int max, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm);
  // Constructor from a SequenceType
  StaticType(const SequenceType *type, XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager *mm);

  StaticType &operator=(const StaticType &o);
  StaticType &operator=(const ItemType *type);
  StaticType &operator=(const SequenceType *type);
  ~StaticType();

  void release();
  void clear();

  void typeUnion(const StaticType &st);
  void typeConcat(const StaticType &st);
  bool typeIntersect(TypeFlags::Enum st);
  void typeIntersect(const StaticType &st);
  bool typeExcept(TypeFlags::Enum st);

  bool substitute(TypeFlags::Enum from, const StaticType &to);
  bool substitute(TypeFlags::Enum from, const ItemType *to);

  void multiply(unsigned int min, unsigned int max);
  void setCardinality(unsigned int min, unsigned int max);

  bool containsType(const StaticType &type) const;
  bool containsType(TypeFlags::Enum flags) const;
  bool isType(TypeFlags::Enum type) const;

  const ItemTypes &getTypes() const { return types_; }
  unsigned int getMin() const { return min_; }
  unsigned int getMax() const { return max_; }

  void typeToBuf(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &buf) const;

private:
  StaticType(const StaticType &o); // No copy constructor

  ItemTypes types_;
  unsigned int min_;
  unsigned int max_;
};

#endif
