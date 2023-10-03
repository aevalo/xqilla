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

#ifndef _STATICANALYSIS_HPP
#define _STATICANALYSIS_HPP

#include <string>

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/StaticType.hpp>
#include <xqilla/utils/HashMap.hpp>

class XPath2MemoryManager;

/**
 * Records access to various parts of the context during static resolution.
 */
class XQILLA_API StaticAnalysis
{
public:
  class XQILLA_API VarEntry
  {
  public:
    VarEntry() : uri(0), name(0) {}
    VarEntry(const XMLCh *u, const XMLCh *n) : uri(u), name(n) {}
    const XMLCh *uri, *name;
  };
  typedef HashMap<const XMLCh*,VarEntry>::iterator VarIterator;

  StaticAnalysis(XPath2MemoryManager* memMgr);
  StaticAnalysis(const StaticAnalysis &o, XPath2MemoryManager* memMgr);

  void copy(const StaticAnalysis &o);
  void release();

  /// Clears all the information in this StaticAnalysis
  void clear();
  void clearExceptType();

  enum Flags {
    CONTEXT_ITEM          = 1 << 0,
    CONTEXT_POSITION      = 1 << 1,
    CONTEXT_SIZE          = 1 << 2,
    CURRENT_TIME          = 1 << 3,
    TIMEZONE              = 1 << 4,
    AVAILABLE_DOCUMENTS   = 1 << 5,
    AVAILABLE_COLLECTIONS = 1 << 6,
    FORCE_NO_FOLDING      = 1 << 7,
    CREATIVE              = 1 << 8,
    UPDATING              = 1 << 9,
    VACUOUS               = 1 << 10,

    CONTEXT_FLAGS = (CONTEXT_ITEM | CONTEXT_POSITION | CONTEXT_SIZE),
    DOCS_OR_COLLECTIONS = (AVAILABLE_DOCUMENTS | AVAILABLE_COLLECTIONS),
    USED_EXCEPT_CONTEXT = (CURRENT_TIME | TIMEZONE | DOCS_OR_COLLECTIONS | FORCE_NO_FOLDING | CREATIVE),
    USED = (USED_EXCEPT_CONTEXT | CONTEXT_FLAGS)
  };

  unsigned getFlags() const { return _flags; }
  void addFlags(unsigned flags) { _flags |= flags; }
  void removeFlags(unsigned flags) { _flags &= ~flags; }

  /** Overrides all the other flags, and never allows this sub-expression
      to be constant folded. */
  void forceNoFolding(bool value);
  bool isNoFoldingForced() const;

  void contextItemUsed(bool value);
  void contextPositionUsed(bool value);
  void contextSizeUsed(bool value);
  bool isContextItemUsed() const;
  bool isContextPositionUsed() const;
  bool isContextSizeUsed() const;
  /** Returns true if any of the context item flags have been used */
  bool areContextFlagsUsed() const;

  void currentTimeUsed(bool value);
  void implicitTimezoneUsed(bool value);

  void availableDocumentsUsed(bool value);
  void availableCollectionsUsed(bool value);
  bool areDocsOrCollectionsUsed() const;

  void variableUsed(const XMLCh *namespaceURI, const XMLCh *name);
  bool removeVariable(const XMLCh *namespaceURI, const XMLCh *name);
  bool isVariableUsed(const XMLCh *namespaceURI, const XMLCh *name) const;
  bool isVariableUsed() const;
  void variablesUsed(VarIterator &begin, VarIterator &end) const;

  /** Sets the members of this StaticAnalysis from the given StaticAnalysis */
  void add(const StaticAnalysis &o);
  void addExceptContextFlags(const StaticAnalysis &o);
  void addExceptVariable(const XMLCh *namespaceURI, const XMLCh *name, const StaticAnalysis &o);

  /** Returns true if flags are set, or variables have been used */
  bool isUsed() const;
  bool isUsedExceptContextFlags() const;

  void creative(bool value);
  bool isCreative() const;

  void updating(bool value);
  bool isUpdating() const;
  void possiblyUpdating(bool value);
  bool isPossiblyUpdating() const;

  /**
   * Properties that allow optimisation regarding sorting or not.
   * The values are OR'd as flags, so they must be distinct bits
   */
  enum Properties {
    DOCORDER     = 0x001, ///< Results are returned in document order
    PEER         = 0x002, ///< Results do not appear in the descendants of other results
    SUBTREE      = 0x004, ///< Results are members of the set of descendants of the context node
    GROUPED      = 0x008, ///< Results are grouped by the document they come from
    SAMEDOC      = 0x010, ///< Results are from the same document as the context node
    ONENODE      = 0x020, ///< Only ever returns one node
    SELF         = 0x040  ///< Only ever returns the context node
  };

  unsigned int getProperties() const;
  void setProperties(unsigned int props);

  const StaticType &getStaticType() const;
  StaticType &getStaticType();

  std::string toString() const;

private:
  StaticAnalysis(const StaticAnalysis &o);
  StaticAnalysis &operator=(const StaticAnalysis &o);

  unsigned _flags;
  unsigned _properties;
  StaticType _staticType;

  HashMap<const XMLCh*,VarEntry> _dynamicVariables;

  XPath2MemoryManager *_memMgr;
};

#endif
