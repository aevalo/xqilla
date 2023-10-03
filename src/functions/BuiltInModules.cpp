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
#include <xqilla/functions/BuiltInModules.hpp>
#include <xqilla/functions/XQUserFunction.hpp>
#include <xqilla/functions/FunctionError.hpp>
#include <xqilla/context/StaticContext.hpp>
#include <xqilla/simple-api/XQQuery.hpp>
#include <xqilla/dom-api/XQillaNSResolver.hpp>

#include <xercesc/validators/schema/SchemaSymbols.hpp>

#include "CoreModule.hpp"
#include "FnModule.hpp"
#include "RwModule.hpp"
#include "XQillaModule.hpp"

XERCES_CPP_NAMESPACE_USE;

const DelayedModule &BuiltInModules::core = core_module;
const DelayedModule &BuiltInModules::fn = fn_module;
const DelayedModule &BuiltInModules::rw = rw_module;
const DelayedModule &BuiltInModules::xqilla = xqilla_module;

static const XMLCh XMLChXS[]    = { chLatin_x, chLatin_s, chNull };
static const XMLCh XMLChXSI[]   = { chLatin_x, chLatin_s, chLatin_i, chNull };
static const XMLCh XMLChLOCAL[] = { chLatin_l, chLatin_o, chLatin_c, chLatin_a, chLatin_l, chNull };
static const XMLCh XMLChERR[]   = { chLatin_e, chLatin_r, chLatin_r, chNull };

void BuiltInModules::addNamespaces(StaticContext *context)
{
  context->setNamespaceBinding(XMLChXS, SchemaSymbols::fgURI_SCHEMAFORSCHEMA);
  context->setNamespaceBinding(XMLChXSI, SchemaSymbols::fgURI_XSI);
  context->setNamespaceBinding(fn.prefix, fn.uri);
  context->setNamespaceBinding(XMLChLOCAL, XQUserFunction::XMLChXQueryLocalFunctionsURI);
  context->setNamespaceBinding(XMLChERR, FunctionError::XMLChXQueryErrorURI);
  context->setNamespaceBinding(xqilla.prefix, xqilla.uri);
}

void BuiltInModules::addNamespaces(XQillaNSResolver *resolver)
{
  resolver->addNamespaceBinding(XMLChXS, SchemaSymbols::fgURI_SCHEMAFORSCHEMA);
  resolver->addNamespaceBinding(XMLChXSI, SchemaSymbols::fgURI_XSI);
  resolver->addNamespaceBinding(fn.prefix, fn.uri);
  resolver->addNamespaceBinding(XMLChLOCAL, XQUserFunction::XMLChXQueryLocalFunctionsURI);
  resolver->addNamespaceBinding(XMLChERR, FunctionError::XMLChXQueryErrorURI);
  resolver->addNamespaceBinding(xqilla.prefix, xqilla.uri);
}

void BuiltInModules::addModules(XQQuery *query)
{
  fn.importModuleInto(query);
  if(!XPath2Utils::equals(query->getModuleTargetNamespace(), fn.uri)) {
    rw.importModuleInto(query);
    if(!XPath2Utils::equals(query->getModuleTargetNamespace(), rw.uri)) {
      core.importModuleInto(query);
      if(!XPath2Utils::equals(query->getModuleTargetNamespace(), core.uri)) {
        xqilla.importModuleInto(query);
      }
    }
  }
}
