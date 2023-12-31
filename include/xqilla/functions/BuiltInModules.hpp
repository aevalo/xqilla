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

#ifndef _BUILTINMODULES_HPP
#define _BUILTINMODULES_HPP

#include <xqilla/utils/DelayedModule.hpp>

class StaticContext;
class XQQuery;
class XQillaNSResolver;

class XQILLA_API BuiltInModules
{
public:
  static const DelayedModule &core;
  static const DelayedModule &fn;
  static const DelayedModule &rw;
  static const DelayedModule &xqilla;

  static void addNamespaces(StaticContext *context);
  static void addNamespaces(XQillaNSResolver *resolver);
  static void addModules(XQQuery *query);
};

#endif
