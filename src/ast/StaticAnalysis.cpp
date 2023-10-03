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
#include <sstream>

#include <xqilla/ast/StaticAnalysis.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/utils/XPath2NSUtils.hpp>
#include <xqilla/utils/UTF8Str.hpp>

XERCES_CPP_NAMESPACE_USE;
using namespace std;

StaticAnalysis::StaticAnalysis(XPath2MemoryManager* memMgr)
  : _flags(0),
    _properties(0),
    _staticType(memMgr),
    _dynamicVariables(true, memMgr),
    _memMgr(memMgr)
{
}

StaticAnalysis::StaticAnalysis(const StaticAnalysis &o, XPath2MemoryManager* memMgr)
  : _flags(0),
    _properties(0),
    _staticType(memMgr),
    _dynamicVariables(true, memMgr),
    _memMgr(memMgr)
{
  copy(o);
}

void StaticAnalysis::copy(const StaticAnalysis &o)
{
  add(o);
  _properties = o._properties;
  _staticType = o._staticType;
}

void StaticAnalysis::release()
{
  _staticType.release();
  _dynamicVariables.release();
}

void StaticAnalysis::clear()
{
  clearExceptType();
  _staticType.clear();
}

void StaticAnalysis::clearExceptType()
{
  _flags = 0;
  _properties = 0;
  _dynamicVariables.removeAll();
}

#define GET(flags, bit) (((flags) & (bit)) != 0)
#define SET(flags, bit, value) (flags) = ((flags) & ~(bit)) | ((value) ? (bit) : 0)

void StaticAnalysis::contextItemUsed(bool value)
{
  SET(_flags, CONTEXT_ITEM, value);
}

void StaticAnalysis::contextPositionUsed(bool value)
{
  SET(_flags, CONTEXT_POSITION, value);
}

void StaticAnalysis::contextSizeUsed(bool value)
{
  SET(_flags, CONTEXT_SIZE, value);
}

bool StaticAnalysis::isContextItemUsed() const
{
  return GET(_flags, CONTEXT_ITEM);
}

bool StaticAnalysis::isContextPositionUsed() const
{
  return GET(_flags, CONTEXT_POSITION);
}

bool StaticAnalysis::isContextSizeUsed() const
{
  return GET(_flags, CONTEXT_SIZE);
}

/** Returns true if any of the context item flags have been used */
bool StaticAnalysis::areContextFlagsUsed() const
{
  return GET(_flags, CONTEXT_FLAGS);
}

void StaticAnalysis::currentTimeUsed(bool value)
{
  SET(_flags, CURRENT_TIME, value);
}

void StaticAnalysis::implicitTimezoneUsed(bool value)
{
  SET(_flags, TIMEZONE, value);
}

void StaticAnalysis::availableDocumentsUsed(bool value)
{
  SET(_flags, AVAILABLE_DOCUMENTS, value);
}

void StaticAnalysis::availableCollectionsUsed(bool value)
{
  SET(_flags, AVAILABLE_COLLECTIONS, value);
}

bool StaticAnalysis::areDocsOrCollectionsUsed() const
{
  return GET(_flags, DOCS_OR_COLLECTIONS);
}

void StaticAnalysis::forceNoFolding(bool value)
{
  SET(_flags, FORCE_NO_FOLDING, value);
}

bool StaticAnalysis::isNoFoldingForced() const
{
  return GET(_flags, FORCE_NO_FOLDING);
}

void StaticAnalysis::variableUsed(const XMLCh *namespaceURI, const XMLCh *name)
{
  _dynamicVariables.put(XPath2NSUtils::makeURIName(namespaceURI, name, _memMgr),
                        VarEntry(namespaceURI, name));
}

void StaticAnalysis::variablesUsed(VarIterator &begin, VarIterator &end) const
{
  begin = const_cast<StaticAnalysis*>(this)->_dynamicVariables.begin();
  end = const_cast<StaticAnalysis*>(this)->_dynamicVariables.end();
}

bool StaticAnalysis::removeVariable(const XMLCh *namespaceURI, const XMLCh *name)
{
  VarIterator i = _dynamicVariables.find(XPath2NSUtils::makeURIName(namespaceURI, name, _memMgr));
  if(i != _dynamicVariables.end()) {
    _dynamicVariables.remove(i);
    return true;
  }
  return false;
}

bool StaticAnalysis::isVariableUsed(const XMLCh *namespaceURI, const XMLCh *name) const
{
  return _dynamicVariables.contains(XPath2NSUtils::makeURIName(namespaceURI, name, _memMgr));
}

bool StaticAnalysis::isVariableUsed() const
{
  return !_dynamicVariables.isEmpty();
}

/** Sets the members of this StaticAnalysis from the given StaticAnalysis */
void StaticAnalysis::add(const StaticAnalysis &o)
{
  // Don't copy VACUOUS
  _flags |= (o._flags & ~VACUOUS);
  _dynamicVariables.putAll(o._dynamicVariables);
}

void StaticAnalysis::addExceptContextFlags(const StaticAnalysis &o)
{
  // Don't copy VACUOUS
  _flags |= (o._flags & ~(CONTEXT_FLAGS | VACUOUS));
  _dynamicVariables.putAll(o._dynamicVariables);
}

void StaticAnalysis::addExceptVariable(const XMLCh *namespaceURI, const XMLCh *name, const StaticAnalysis &o)
{
  const XMLCh *uriname = XPath2NSUtils::makeURIName(namespaceURI, name, _memMgr);
  bool remove = !_dynamicVariables.contains(uriname);

  // Don't copy VACUOUS
  _flags |= (o._flags & ~VACUOUS);
  _dynamicVariables.putAll(o._dynamicVariables);

  if(remove) _dynamicVariables.remove(uriname);
}

/** Returns true if flags are set, or variables have been used */
bool StaticAnalysis::isUsed() const
{
  return GET(_flags, USED) || isVariableUsed();
}

bool StaticAnalysis::isUsedExceptContextFlags() const
{
  return GET(_flags, USED_EXCEPT_CONTEXT) || isVariableUsed();
}

void StaticAnalysis::creative(bool value)
{
  SET(_flags, CREATIVE, value);
}

bool StaticAnalysis::isCreative() const
{
  return GET(_flags, CREATIVE);
}

void StaticAnalysis::updating(bool value)
{
  SET(_flags, UPDATING, value);
}

bool StaticAnalysis::isUpdating() const
{
  return GET(_flags, UPDATING);
}

void StaticAnalysis::possiblyUpdating(bool value)
{
  SET(_flags, VACUOUS, value);
}

bool StaticAnalysis::isPossiblyUpdating() const
{
  return GET(_flags, VACUOUS);
}

unsigned int StaticAnalysis::getProperties() const
{
	return _properties;
}

void StaticAnalysis::setProperties(unsigned int props)
{
	_properties = props;
}

const StaticType &StaticAnalysis::getStaticType() const
{
	return _staticType;
}

StaticType &StaticAnalysis::getStaticType()
{
	return _staticType;
}

std::string StaticAnalysis::toString() const
{
  std::ostringstream s;

  s << "Context Item:          " << (GET(_flags, CONTEXT_ITEM) ? "true" : "false") << std::endl;
  s << "Context Position:      " << (GET(_flags, CONTEXT_POSITION) ? "true" : "false") << std::endl;
  s << "Context Size:          " << (GET(_flags, CONTEXT_SIZE) ? "true" : "false") << std::endl;
  s << "Current Time:          " << (GET(_flags, CURRENT_TIME) ? "true" : "false") << std::endl;
  s << "Implicit Timezone:     " << (GET(_flags, TIMEZONE) ? "true" : "false") << std::endl;
  s << "Available Documents:   " << (GET(_flags, AVAILABLE_DOCUMENTS) ? "true" : "false") << std::endl;
  s << "Available Collections: " << (GET(_flags, AVAILABLE_COLLECTIONS) ? "true" : "false") << std::endl;
  s << "Force No Folding:      " << (GET(_flags, FORCE_NO_FOLDING) ? "true" : "false") << std::endl;
  s << "Creative:              " << (GET(_flags, CREATIVE) ? "true" : "false") << std::endl;
  s << "Updating:              " << (GET(_flags, UPDATING) ? "true" : "false") << std::endl;
  s << "Possibly Updating:     " << (GET(_flags, VACUOUS) ? "true" : "false") << std::endl;

  s << "Variables Used:        [";
  bool first = true;
  VarIterator i = const_cast<StaticAnalysis*>(this)->_dynamicVariables.begin();
  VarIterator end = const_cast<StaticAnalysis*>(this)->_dynamicVariables.end();
  for(; i != end; ++i) {
    if(first) {
      first = false;
    }
    else {
      s << ", ";
    }
    s << "{" << UTF8(i.getValue().uri) << "}" << UTF8(i.getValue().name);
  }
  s << "]" << std::endl;


  XMLBuffer buf;
  _staticType.typeToBuf(buf);
  s << "Static Type:           " << UTF8(buf.getRawBuffer()) << std::endl;

  return s.str();
}

