#ifndef VxNewReport_h__
#define VxNewReport_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request to generate a new report.
    /// </summary>
    struct VxNewReport {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewReport"/> struct.
        /// </summary>
        VxNewReport() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewReport"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewReport(const VxNewReport& ref) {
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->templateId, ref.templateId);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewReport"/> class.
        /// </summary>
        ~VxNewReport() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->name);
            VxZeroArray(this->templateId);
        }

    public:
        /// <summary>
        /// The friendly name of the new report. If not specified, the name of the report template will be used.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique identifier of the <see cref="IVxReportTemplate"/> to use to generate the new report.
        /// </summary>
        char templateId[64];
    };
}

#endif // VxNewReport_h__
