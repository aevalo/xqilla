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

#include <xqilla/update/UInsertAfter.hpp>
#include <xqilla/update/UInsertAsLast.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/items/Node.hpp>
#include <xqilla/ast/XQTreatAs.hpp>
#include <xqilla/schema/SequenceType.hpp>
#include <xqilla/exceptions/StaticErrorException.hpp>
#include <xqilla/exceptions/XPath2TypeMatchException.hpp>
#include <xqilla/exceptions/ASTException.hpp>
#include <xqilla/update/PendingUpdateList.hpp>
#include <xqilla/ast/XQDOMConstructor.hpp>
#include <xqilla/utils/XPath2Utils.hpp>
#include <xqilla/exceptions/DynamicErrorException.hpp>

XERCES_CPP_NAMESPACE_USE;

UInsertAfter::UInsertAfter(ASTNode *source, ASTNode *target, XPath2MemoryManager* memMgr)
  : ASTNodeImpl(UINSERT_AFTER, memMgr),
    source_(source),
    target_(target)
{
}

static const XMLCh err_XUTY0006[] = { 'e', 'r', 'r', ':', 'X', 'U', 'T', 'Y', '0', '0', '0', '6', 0 };
static const XMLCh err_XUDY0027[] = { 'e', 'r', 'r', ':', 'X', 'U', 'D', 'Y', '0', '0', '2', '7', 0 };

ASTNode* UInsertAfter::staticResolution(StaticContext *context)
{
  XPath2MemoryManager *mm = context->getMemoryManager();

  source_ = new (mm) XQContentSequence(source_, mm);
  source_->setLocationInfo(this);
  source_ = source_->staticResolution(context);

  ItemType *itemType1 = new (mm) ItemType(ItemType::TEST_ANYTHING);
  itemType1->setLocationInfo(this);
  SequenceType *targetType1 = new (mm) SequenceType(itemType1, SequenceType::PLUS);
  targetType1->setLocationInfo(this);

  ItemType *itemType2 = new (mm) ItemType(ItemType::TEST_NODE);
  itemType2->setLocationInfo(this);
  SequenceType *targetType2 = new (mm) SequenceType(itemType2, SequenceType::EXACTLY_ONE);
  targetType2->setLocationInfo(this);

  target_ = new (mm) XQTreatAs(target_, targetType1, mm, err_XUDY0027);
  target_->setLocationInfo(this);
  target_ = target_->staticResolution(context);

  target_ = new (mm) XQTreatAs(target_, targetType2, mm, err_XUTY0006);
  target_->setLocationInfo(this);
  target_ = target_->staticResolution(context);

  return this;
}

ASTNode *UInsertAfter::staticTypingImpl(StaticContext *context)
{
  _src.clear();

  _src.add(source_->getStaticAnalysis());

  if(source_->getStaticAnalysis().isUpdating()) {
    XQThrow(StaticErrorException,X("UInsertAfter::staticTyping"),
            X("It is a static error for the source expression of an insert expression "
              "to be an updating expression [err:XUST0001]"));
  }

  _src.add(target_->getStaticAnalysis());

  if(target_->getStaticAnalysis().isUpdating()) {
    XQThrow(StaticErrorException,X("UInsertAfter::staticTyping"),
            X("It is a static error for the target expression of an insert expression "
              "to be an updating expression [err:XUST0001]"));
  }

  _src.updating(true);
  return this;
}

Result UInsertAfter::createResult(DynamicContext* context, int flags) const
{
  return 0;
}

PendingUpdateList UInsertAfter::createUpdateList(DynamicContext *context) const
{
  Node::Ptr node = (Node*)target_->createResult(context)->next(context).get();
  Node::Ptr parentNode = node->dmParent(context);

  if(node->dmNodeKind() == Node::document_string ||
     node->dmNodeKind() == Node::attribute_string ||
     node->dmNodeKind() == Node::namespace_string)
    XQThrow(XPath2TypeMatchException,X("UInsertAfter::staticTyping"),
            X("The target node of an insert after expression must be a single element, text, comment, or processing "
              "instruction node [err:XUTY0006]"));

  if(parentNode.isNull())
    XQThrow(XPath2TypeMatchException,X("UInsertAfter::staticTyping"),
            X("It is a dynamic error if the target expression of an insert after expression does "
              "not have a parent [err:XUDY0029]"));

  Sequence alist(context->getMemoryManager());
  Sequence clist(context->getMemoryManager());

  Result value = source_->createResult(context);
  Item::Ptr item;
  while((item = value->next(context)).notNull()) {
    if(((Node*)item.get())->dmNodeKind() == Node::attribute_string) {
      if(!clist.isEmpty())
        XQThrow(ASTException,X("UInsertAfter::createUpdateList"),
                X("Attribute nodes must occur before other nodes in the source expression for an insert after expression [err:XUTY0004]"));

      //    b. No attribute node in $alist may have a QName whose implied namespace binding conflicts with a namespace binding in the
      //       "namespaces" property of parent($target) [err:XUDY0023].
      ATQNameOrDerived::Ptr qname = ((Node*)item.get())->dmNodeName(context);
      if(!UInsertAsLast::checkNamespaceBinding(qname, parentNode, context, this)) {
        XMLBuffer buf;
        buf.append(X("Implied namespace binding for the insert after expression (\""));
        buf.append(qname->getPrefix());
        buf.append(X("\" -> \""));
        buf.append(qname->getURI());
        buf.append(X("\") conflicts with those already existing on the parent element of the target attribute [err:XUDY0023]"));
        XQThrow3(DynamicErrorException, X("UInsertAfter::createUpdateList"), buf.getRawBuffer(), this);
      }

      alist.addItem(item);
    }
    else
      clist.addItem(item);
  }

  PendingUpdateList result;

  if(!alist.isEmpty()) {
    // 4. If $alist is not empty and before or after is specified, the following checks are performed:
    //    a. parent($target) must be an element node [err:XUTY0022].
    if(node->dmParent(context)->dmNodeKind() == Node::document_string)
      XQThrow(XPath2TypeMatchException,X("UInsertAfter::createUpdateList"),
              X("It is a type error if an insert expression specifies the insertion of an attribute node before or after a child of a document node [err:XUDY0030]"));
    result.addUpdate(PendingUpdate(PendingUpdate::INSERT_ATTRIBUTES, node->dmParent(context), alist, this));
  }
  if(!clist.isEmpty()) {
    result.addUpdate(PendingUpdate(PendingUpdate::INSERT_AFTER, node, clist, this));
  }

  return result;
}

