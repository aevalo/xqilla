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
#include "DescendantAxis.hpp"
#include <xercesc/dom/DOMNode.hpp>
#include <xqilla/items/Node.hpp>

DescendantAxis::DescendantAxis(const LocationInfo *info, const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *contextNode, const Node *nodeObj,
       const NodeTest *nodeTest, const AxisNodeFactory &factory)
  : Axis(info, contextNode, nodeObj, nodeTest, factory),
    descendant_(0)
{
}

const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *DescendantAxis::nextNode(DynamicContext *context)
{
  if(toDo_) {
    // initialise
    toDo_ = false;
    descendant_ = getFirstChild(contextNode_);
  }
  else if(descendant_ != 0) {
    const XERCES_CPP_NAMESPACE_QUALIFIER DOMNode *result = getFirstChild(descendant_);

    while(result == 0) {
      result = getNextSibling(descendant_);
      if(result == 0) {
        descendant_ = getParent(descendant_);
        if(descendant_ == contextNode_) break;
      }
    }

    descendant_ = result;
  }

  return descendant_;
}

