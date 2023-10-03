/*
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

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/items/ATDateTimeOrDerived.hpp>
#include <xqilla/items/ATDateOrDerived.hpp>
#include <xqilla/items/ATTimeOrDerived.hpp>
#include <xqilla/items/ATDurationOrDerived.hpp>
#include <xqilla/runtime/Result.hpp>
#include <xqilla/context/ItemFactory.hpp>
#include <xqilla/context/DynamicContext.hpp>
#include <xqilla/functions/FuncFactory.hpp>
#include <xqilla/ast/XQFunction.hpp>
#include <xqilla/exceptions/DynamicErrorException.hpp>
#include "../utils/DateUtils.hpp"

XERCES_CPP_NAMESPACE_USE;

template<typename TYPE>
static Result yearsFrom(const VectorOfASTNodes &args, DynamicContext *context,
                        const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getYears(context);
}

static const XMLCh yearFromDateTimeName[] =
{ 'y', 'e', 'a', 'r', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory yearFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, yearFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:integer?", yearsFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh yearFromDateName[] =
{ 'y', 'e', 'a', 'r', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 0 };

static SimpleBuiltinFactory yearFromDateFactory(
  XQFunction::XMLChFunctionURI, yearFromDateName, 1,
  "($arg as xs:date?) as xs:integer?", yearsFrom<ATDateOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh yearsFromDurationName[] =
{ 'y', 'e', 'a', 'r', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory yearsFromDurationFactory(
  XQFunction::XMLChFunctionURI, yearsFromDurationName, 1,
  "($arg as xs:duration?) as xs:integer?", yearsFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result monthsFrom(const VectorOfASTNodes &args, DynamicContext *context,
                        const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getMonths(context);
}

const XMLCh monthFromDateTimeName[] =
{ 'm', 'o', 'n', 't', 'h', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory monthFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, monthFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:integer?", monthsFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh monthFromDateName[] =
{ 'm', 'o', 'n', 't', 'h', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 0 };

static SimpleBuiltinFactory monthFromDateFactory(
  XQFunction::XMLChFunctionURI, monthFromDateName, 1,
  "($arg as xs:date?) as xs:integer?", monthsFrom<ATDateOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh monthsFromDurationName[] =
{ 'm', 'o', 'n', 't', 'h', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory monthsFromDurationFactory(
  XQFunction::XMLChFunctionURI, monthsFromDurationName, 1,
  "($arg as xs:duration?) as xs:integer?", monthsFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename TYPE>
static Result daysFrom(const VectorOfASTNodes &args, DynamicContext *context,
                      const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getDays(context);
}

const XMLCh dayFromDateTimeName[] =
{ 'd', 'a', 'y', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory dayFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, dayFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:integer?", daysFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh dayFromDateName[] =
{ 'd', 'a', 'y', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 0 };

static SimpleBuiltinFactory dayFromDateFactory(
  XQFunction::XMLChFunctionURI, dayFromDateName, 1,
  "($arg as xs:date?) as xs:integer?", daysFrom<ATDateOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh daysFromDurationName[] =
{ 'd', 'a', 'y', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory daysFromDurationFactory(
  XQFunction::XMLChFunctionURI, daysFromDurationName, 1,
  "($arg as xs:duration?) as xs:integer?", daysFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result hoursFrom(const VectorOfASTNodes &args, DynamicContext *context,
                        const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getHours(context);
}

const XMLCh hoursFromDateTimeName[] =
{ 'h', 'o', 'u', 'r', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory hoursFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, hoursFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:integer?", hoursFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh hoursFromTimeName[] =
{ 'h', 'o', 'u', 'r', 's', '-', 'f', 'r', 'o', 'm', '-', 't', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory hoursFromTimeFactory(
  XQFunction::XMLChFunctionURI, hoursFromTimeName, 1,
  "($arg as xs:time?) as xs:integer?", hoursFrom<ATTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh hoursFromDurationName[] =
{ 'h', 'o', 'u', 'r', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory hoursFromDurationFactory(
  XQFunction::XMLChFunctionURI, hoursFromDurationName, 1,
  "($arg as xs:duration?) as xs:integer?", hoursFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result minutesFrom(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getMinutes(context);
}

const XMLCh minutesFromDateTimeName[] =
{ 'm', 'i', 'n', 'u', 't', 'e', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory minutesFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, minutesFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:integer?", minutesFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh minutesFromTimeName[] =
{ 'm', 'i', 'n', 'u', 't', 'e', 's', '-', 'f', 'r', 'o', 'm', '-', 't', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory minutesFromTimeFactory(
  XQFunction::XMLChFunctionURI, minutesFromTimeName, 1,
  "($arg as xs:time?) as xs:integer?", minutesFrom<ATTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh minutesFromDurationName[] =
{ 'm', 'i', 'n', 'u', 't', 'e', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory minutesFromDurationFactory(
  XQFunction::XMLChFunctionURI, minutesFromDurationName, 1,
  "($arg as xs:duration?) as xs:integer?", minutesFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result secondsFrom(const VectorOfASTNodes &args, DynamicContext *context,
                          const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getSeconds(context);
}

const XMLCh secondsFromDateTimeName[] =
{ 's', 'e', 'c', 'o', 'n', 'd', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory secondsFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, secondsFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:decimal?", secondsFrom<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh secondsFromTimeName[] =
{ 's', 'e', 'c', 'o', 'n', 'd', 's', '-', 'f', 'r', 'o', 'm', '-', 't', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory secondsFromTimeFactory(
  XQFunction::XMLChFunctionURI, secondsFromTimeName, 1,
  "($arg as xs:time?) as xs:decimal?", secondsFrom<ATTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

const XMLCh secondsFromDurationName[] =
{ 's', 'e', 'c', 'o', 'n', 'd', 's', '-', 'f', 'r', 'o', 'm', '-', 'd', 'u', 'r', 'a', 't', 'i', 'o', 'n', 0 };

static SimpleBuiltinFactory secondsFromDurationFactory(
  XQFunction::XMLChFunctionURI, secondsFromDurationName, 1,
  "($arg as xs:duration?) as xs:decimal?", secondsFrom<ATDurationOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result timezoneFrom(const VectorOfASTNodes &args, DynamicContext *context,
                           const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull() || !((TYPE*)item.get())->hasTimezone()) return 0;
  return (Item::Ptr)((TYPE*)item.get())->getTimezone()->asDayTimeDuration(context);
}

const XMLCh timezoneFromDateTimeName[] =
{ 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory timezoneFromDateTimeFactory(
  XQFunction::XMLChFunctionURI, timezoneFromDateTimeName, 1,
  "($arg as xs:dateTime?) as xs:dayTimeDuration?", timezoneFrom<ATDateTimeOrDerived>
);

const XMLCh timezoneFromDateName[] =
{ 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', '-', 'f', 'r', 'o', 'm', '-', 'd', 'a', 't', 'e', 0 };

static SimpleBuiltinFactory timezoneFromDateFactory(
  XQFunction::XMLChFunctionURI, timezoneFromDateName, 1,
  "($arg as xs:date?) as xs:dayTimeDuration?", timezoneFrom<ATDateOrDerived>
);

const XMLCh timezoneFromTimeName[] =
{ 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', '-', 'f', 'r', 'o', 'm', '-', 't', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory timezoneFromTimeFactory(
  XQFunction::XMLChFunctionURI, timezoneFromTimeName, 1,
  "($arg as xs:time?) as xs:dayTimeDuration?", timezoneFrom<ATTimeOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename TYPE>
static Result adjustToTimezone(const VectorOfASTNodes &args, DynamicContext *context,
                               const LocationInfo *info)
{
  Item::Ptr item = args[0]->createResult(context)->next(context);
  if(item.isNull()) return 0;

  Item::Ptr tz;
  if(args.size() > 1) {
    tz = args[1]->createResult(context)->next(context);
    if(tz.isNull()) return (Item::Ptr)((TYPE*)item.get())->setTimezone(0, context);
    Timezone::Ptr timezone = new Timezone((ATDurationOrDerived*)tz.get(), context);
    if(!((ATDurationOrDerived*)tz.get())->equals(timezone->asDayTimeDuration(context), context))
      XQThrow3(DynamicErrorException, X("adjustToTimezone"),
               X("Invalid timezone value [err:FODT0003]"), info);
  }
  else tz = context->getImplicitTimezone();

  return (Item::Ptr)((TYPE*)item.get())->addTimezone((ATDurationOrDerived*)tz.get(), context);
}

const XMLCh adjustDateTimeToTimezoneName[] =
{ 'a', 'd', 'j', 'u', 's', 't', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', '-', 't', 'o', '-', 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', 0 };

static SimpleBuiltinFactory adjustDateTimeToTimezoneFactory1(
  XQFunction::XMLChFunctionURI, adjustDateTimeToTimezoneName, 1,
  "($arg as xs:dateTime?) as xs:dateTime?", adjustToTimezone<ATDateTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

static SimpleBuiltinFactory adjustDateTimeToTimezoneFactory2(
  XQFunction::XMLChFunctionURI, adjustDateTimeToTimezoneName, 2,
  "($arg as xs:dateTime?, $timezone as xs:dayTimeDuration?) as xs:dateTime?",
  adjustToTimezone<ATDateTimeOrDerived>
);

const XMLCh adjustDateToTimezoneName[] =
{ 'a', 'd', 'j', 'u', 's', 't', '-', 'd', 'a', 't', 'e', '-', 't', 'o', '-', 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', 0 };

static SimpleBuiltinFactory adjustDateToTimezoneFactory1(
  XQFunction::XMLChFunctionURI, adjustDateToTimezoneName, 1,
  "($arg as xs:date?) as xs:date?", adjustToTimezone<ATDateOrDerived>,
  StaticAnalysis::TIMEZONE
);

static SimpleBuiltinFactory adjustDateToTimezoneFactory2(
  XQFunction::XMLChFunctionURI, adjustDateToTimezoneName, 2,
  "($arg as xs:date?, $timezone as xs:dayTimeDuration?) as xs:date?",
  adjustToTimezone<ATDateOrDerived>
);

const XMLCh adjustTimeToTimezoneName[] =
{ 'a', 'd', 'j', 'u', 's', 't', '-', 't', 'i', 'm', 'e', '-', 't', 'o', '-', 't', 'i', 'm', 'e', 'z', 'o', 'n', 'e', 0 };

static SimpleBuiltinFactory adjustTimeToTimezoneFactory1(
  XQFunction::XMLChFunctionURI, adjustTimeToTimezoneName, 1,
  "($arg as xs:Time?) as xs:Time?", adjustToTimezone<ATTimeOrDerived>,
  StaticAnalysis::TIMEZONE
);

static SimpleBuiltinFactory adjustTimeToTimezoneFactory2(
  XQFunction::XMLChFunctionURI, adjustTimeToTimezoneName, 2,
  "($arg as xs:Time?, $timezone as xs:dayTimeDuration?) as xs:Time?",
  adjustToTimezone<ATTimeOrDerived>
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result dateTime(const VectorOfASTNodes &args, DynamicContext *context,
                       const LocationInfo *info)
{
  ATDateOrDerived::Ptr date = (ATDateOrDerived*)args[0]->createResult(context)->next(context).get();
  if(date.isNull()) return 0;
  ATTimeOrDerived::Ptr time = (ATTimeOrDerived*)args[1]->createResult(context)->next(context).get();
  if(time.isNull()) return 0;

  Timezone::Ptr finalTZ;
  // determine the timezone of the result
  if(date->hasTimezone()) {
    finalTZ=date->getTimezone();
    if(time->hasTimezone()) {
      if(!time->getTimezone()->equals(finalTZ))
        XQThrow3(DynamicErrorException, X("dateTime"),
                 X("Both arguments to fn:dateTime have a timezone specified [err:FORG0008]"),
                 info);
    }
  }
  else if(time->hasTimezone())
    finalTZ=time->getTimezone();

  Timezone::Ptr nulltz;
  date = date->setTimezone(nulltz, context);
  time = time->setTimezone(nulltz, context);

  // convert to a xs:dateTime string
  XMLBuffer buff(64, context->getMemoryManager());
  buff.append(date->asString(context));
  buff.append(chLatin_T);
  buff.append(time->asString(context));
  if(finalTZ.notNull())
    buff.append(finalTZ->asString(context));

  return (Item::Ptr)context->getItemFactory()->createDateTime(buff.getRawBuffer(), context);
}

const XMLCh dateTimeName[] =
{ 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory dateTimeFactory(
  XQFunction::XMLChFunctionURI, dateTimeName, 2,
  "($arg1 as xs:date?, $arg2 as xs:time?) as xs:dateTime?", dateTime,
  StaticAnalysis::TIMEZONE
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result currentDateTime(const VectorOfASTNodes &args, DynamicContext *context,
                              const LocationInfo *info)
{
  return (Item::Ptr)DateUtils::getCurrentDateTime(context);
}

const XMLCh currentDateTimeName[] =
{ 'c', 'u', 'r', 'r', 'e', 'n', 't', '-', 'd', 'a', 't', 'e', 'T', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory currentDateTimeFactory(
  XQFunction::XMLChFunctionURI, currentDateTimeName, 0,
  "() as xs:dateTime", currentDateTime,
  StaticAnalysis::CURRENT_TIME
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result currentDate(const VectorOfASTNodes &args, DynamicContext *context,
                              const LocationInfo *info)
{
  return (Item::Ptr)DateUtils::getCurrentDate(context);
}

const XMLCh currentDateName[] =
{ 'c', 'u', 'r', 'r', 'e', 'n', 't', '-', 'd', 'a', 't', 'e', 0 };

static SimpleBuiltinFactory currentDateFactory(
  XQFunction::XMLChFunctionURI, currentDateName, 0,
  "() as xs:date", currentDate,
  StaticAnalysis::CURRENT_TIME
);

////////////////////////////////////////////////////////////////////////////////////////////////////

static Result currentTime(const VectorOfASTNodes &args, DynamicContext *context,
                              const LocationInfo *info)
{
  return (Item::Ptr)DateUtils::getCurrentTime(context);
}

const XMLCh currentTimeName[] =
{ 'c', 'u', 'r', 'r', 'e', 'n', 't', '-', 't', 'i', 'm', 'e', 0 };

static SimpleBuiltinFactory currentTimeFactory(
  XQFunction::XMLChFunctionURI, currentTimeName, 0,
  "() as xs:time", currentTime,
  StaticAnalysis::CURRENT_TIME
);

