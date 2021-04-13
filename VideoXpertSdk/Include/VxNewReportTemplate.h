#ifndef VxNewReportTemplate_h__
#define VxNewReportTemplate_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxReportField.h"
#include "VxReportFilter.h"
#include "VxNetworkStorageInfo.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new report template to be created.
    /// </summary>
    struct VxNewReportTemplate {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewReportTemplate"/> struct.
        /// </summary>
        VxNewReportTemplate() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewReportTemplate"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewReportTemplate(const VxNewReportTemplate& ref) {
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->format, ref.format);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->recurrenceTime, ref.recurrenceTime);
            this->duration = ref.duration;
            this->storageLocation = VxNetworkStorageInfo(ref.storageLocation);
            this->language = ref.language;
            this->type = ref.type;
            this->interval = ref.interval;

            this->fieldsSize = ref.fieldsSize;
            this->fields = nullptr;
            if (ref.fields != nullptr) {
                this->fields = new VxReportField*[ref.fieldsSize];
                for (int i = 0; i < ref.fieldsSize; i++)
                    this->fields[i] = new VxReportField(*ref.fields[i]);
            }

            this->filtersSize = ref.filtersSize;
            this->filters = nullptr;
            if (ref.filters != nullptr) {
                this->filters = new VxReportFilter*[ref.filtersSize];
                for (int i = 0; i < ref.filtersSize; i++)
                    this->filters[i] = new VxReportFilter(*ref.filters[i]);
            }

            this->recurrenceSize = ref.recurrenceSize;
            this->recurrence = nullptr;
            if (ref.recurrence != nullptr) {
                this->recurrence = new VxDayOfWeek::Value[ref.recurrenceSize];
                for (int i = 0; i < ref.recurrenceSize; i++)
                    this->recurrence[i] = ref.recurrence[i];
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewReportTemplate"/> class.
        /// </summary>
        ~VxNewReportTemplate() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->endTime);
            VxZeroArray(this->format);;
            VxZeroArray(this->name);
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
        /// The friendly name of the report template.
        /// </summary>
        char name[64];
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
    };
}

#endif // VxNewReportTemplate_h__