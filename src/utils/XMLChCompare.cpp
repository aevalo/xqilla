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
#include <xqilla/utils/XMLChCompare.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xercesc/util/XMLString.hpp>

bool QNameSort::operator() (const std::pair<XMLCh*, XMLCh *> lhs, const std::pair<XMLCh*, XMLCh *> rhs) const {
    return XPath2Utils::equals(lhs.first, rhs.first) ? XERCES_CPP_NAMESPACE_QUALIFIER XMLString::compareString(lhs.second, rhs.second) < 0: XERCES_CPP_NAMESPACE_QUALIFIER XMLString::compareString(lhs.first, rhs.first) < 0;
}

bool XMLChSort::operator() (const XMLCh* lhs, const XMLCh* rhs) const {
    return XERCES_CPP_NAMESPACE_QUALIFIER XMLString::compareString(lhs, rhs) < 0;
}
