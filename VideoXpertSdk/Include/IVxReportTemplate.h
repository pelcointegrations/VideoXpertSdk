#ifndef IVxReportTemplate_h__
#define IVxReportTemplate_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxLimits.h"
#include "VxReportField.h"
#include "VxReportFilter.h"
#include "VxNetworkStorageInfo.h"

namespace VxSdk {
    /// <summary>
    /// Represents a template for an available report type that may be created.
    /// </summary>
    struct IVxReportTemplate {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this report template from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the report template.</returns>
        virtual VxResult::Value DeleteReportTemplate() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the duration property.
        /// </summary>
        /// <param name="duration">The new duration value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDuration(int duration) = 0;
        /// <summary>
        /// Sets the endTime property.
        /// </summary>
        /// <param name="endTime">The new end time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEndTime(char endTime[64]) = 0;
        /// <summary>
        /// Sets the fields property.
        /// </summary>
        /// <param name="fields">The new fields value.</param>
        /// <param name="fieldsSize">The size of <see cref="fields"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFields(VxReportField** fields, int fieldsSize) = 0;
        /// <summary>
        /// Sets the filters property.
        /// </summary>
        /// <param name="filters">The new filters value.</param>
        /// <param name="filtersSize">The size of <see cref="fields"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFilters(VxReportFilter** filters, int filtersSize) = 0;
        /// <summary>
        /// Sets the format property.
        /// </summary>
        /// <param name="format">The new format value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFormat(char format[64]) = 0;
        /// <summary>
        /// Sets the interval property.
        /// </summary>
        /// <param name="interval">The new interval value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetInterval(VxTimeInterval::Value interval) = 0;
        /// <summary>
        /// Sets the language property.
        /// </summary>
        /// <param name="language">The new language value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLanguage(VxLanguage::Value language) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the recurrence property.
        /// </summary>
        /// <param name="recurrence">The new recurrence value.</param>
        /// <param name="recurrenceSize">The size of <see cref="recurrence"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetRecurrence(VxDayOfWeek::Value* recurrence, int recurrenceSize) = 0;
        /// <summary>
        /// Sets the recurrenceTime property.
        /// </summary>
        /// <param name="recurrenceTime">The new recurrence time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetRecurrenceTime(char recurrenceTime[9]) = 0;
        /// <summary>
        /// Sets the storageLocation property.
        /// </summary>
        /// <param name="storageLocation">The new storage location.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetStorageLocation(VxNetworkStorageInfo& storageLocation) = 0;

    public:
        /// <summary>
        /// The end time at which the collected report data is limited to. If not specified, report data will be
        /// collected up to the current time at which the report is generated.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The desired format for the contents of the report.
        /// </summary>
        char format[64];
        /// <summary>
        /// The unique identifier of the report template.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the report template.
        /// </summary>
        char name[64];
        /// <summary>
        /// If present, indicates that this resource is owned by a user (it is private) and this is their username. If
        /// not present, indicates that this resource is not owned (it is public).
        /// </summary>
        char owner[64];
        /// <summary>
        /// The time at which to perform automatic report generation on given recur days, from 00:00:00 to 23:59:59.
        /// Ignored if <see cref="recurrence"/> is not set.
        /// </summary>
        char recurrenceTime[9];
        /// <summary>
        /// The duration of time, in hours, extending back from <see cref="endTime"/> to limit collected report data
        /// to. If 0, there is no limit.
        /// </summary>
        int duration;
        /// <summary>
        /// The size of <see cref="fields"/>.
        /// </summary>
        int fieldsSize;
        /// <summary>
        /// The size of <see cref="filters"/>.
        /// </summary>
        int filtersSize;
        /// <summary>
        /// The size of <see cref="recurrence"/>.
        /// </summary>
        int recurrenceSize;
        /// <summary>
        /// The days of the week to automatically generate a report from this template. Ignored if
        /// <see cref="recurrenceTime"/> is not set.
        /// </summary>
        VxDayOfWeek::Value* recurrence;
        /// <summary>
        /// The language to use when creating the report.
        /// </summary>
        VxLanguage::Value language;
        /// <summary>
        /// The network storage location to export the report data to. Ignored if <see cref="recurrence"/> is not set.
        /// </summary>
        VxNetworkStorageInfo storageLocation;
        /// <summary>
        /// The ordered list of report field available to include in the report.
        /// </summary>
        VxReportField** fields;
        /// <summary>
        /// The report filter to use to filter the contents of the report.
        /// </summary>
        VxReportFilter** filters;
        /// <summary>
        /// The type of the report that this template represents.
        /// </summary>
        VxReportType::Value type;
        /// <summary>
        /// The time interval that is used to track data in the report (days, hours, etc).
        /// </summary>
        VxTimeInterval::Value interval;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->endTime);
            VxZeroArray(this->format);;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            VxZeroArray(this->recurrenceTime);
            this->duration = 0;
            this->fieldsSize = 0;
            this->filtersSize = 0;
            this->recurrenceSize = 0;
            this->storageLocation.Clear();
            this->recurrence = nullptr;
            this->fields = nullptr;
            this->filters = nullptr;
            this->language = VxLanguage::kUnknown;
            this->type = VxReportType::kUnknown;
            this->interval = VxTimeInterval::kUnknown;
        }
    };
}
#endif // IVxReportTemplate_h__
