#ifndef IVxReport_h__
#define IVxReport_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxReportTemplate.h"

namespace VxSdk {
    /// <summary>
    /// Represents a generated (or generating) system report.
    /// </summary>
    struct IVxReport {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this report from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the report.</returns>
        virtual VxResult::Value DeleteReport() const = 0;
        /// <summary>
        /// Gets the URI to the download location of the actual report data. This endpoint will only be present if the
        /// report has been successfully generated and is available for download.
        /// </summary>
        /// <param name="endpoint">The report endpoint, if available.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetReportEndpoint(char* endpoint, int& size) = 0;
        /// <summary>
        /// Gets the <see cref="IVxReportTemplate"/> that this report was generated from.
        /// </summary>
        /// <param name="reportTemplate">The <see cref="IVxReportTemplate"/> that this report was generated from.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetReportTemplate(IVxReportTemplate*& reportTemplate) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// The format of the contents of the report.
        /// </summary>
        char format[64];
        /// <summary>
        /// The unique identifier of the report.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the report.
        /// </summary>
        char name[64];
        /// <summary>
        /// If present, indicates that this resource is owned by a user (it is private) and this is their username. If
        /// not present, indicates that this resource is not owned (it is public).
        /// </summary>
        char owner[64];
        /// <summary>
        /// The time at which the report was generated.
        /// </summary>
        char time[64];
        /// <summary>
        /// The current generation status of this report.
        /// </summary>
        VxReportStatus::Value status;
        /// <summary>
        /// The optional reason for the current generation status of this report; typically used to express the reason
        /// for a failure.
        /// </summary>
        VxReportStatusReason::Value statusReason;
        /// <summary>
        /// The type of this report.
        /// </summary>
        VxReportType::Value type;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->format);;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            VxZeroArray(this->time);
            this->status = VxReportStatus::kUnknown;
            this->statusReason = VxReportStatusReason::kUnknown;
            this->type = VxReportType::kUnknown;
        }
    };
}
#endif // IVxReport_h__
