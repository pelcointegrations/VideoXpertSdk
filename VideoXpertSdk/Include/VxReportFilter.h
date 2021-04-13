#ifndef VxReportFilter_h__
#define VxReportFilter_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a filter within a report.
    /// </summary>
    struct VxReportFilter {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxReportFilter"/> struct.
        /// </summary>
        VxReportFilter() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxReportFilter"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxReportFilter(const VxReportFilter& ref) {
            this->type = ref.type;
            this->filterIdSize = ref.filterIdSize;
            this->filterIds = nullptr;
            if (ref.filterIds != nullptr) {
                this->filterIds = new char* [ref.filterIdSize];
                for (int i = 0; i < ref.filterIdSize; i++) {
                    const size_t len = strlen(ref.filterIds[i]) + 1;
                    this->filterIds[i] = new char[len];
                    Utilities::StrCopySafe(this->filterIds[i], ref.filterIds[i], len);
                }
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxReportFilter"/> class.
        /// </summary>
        ~VxReportFilter() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
			this->type = VxReportFilterType::kUnknown;
            this->filterIdSize = 0;
            this->filterIds = nullptr;
        }

    public:
        /// <summary>
        /// List of unique identifiers to filter by (based on type). For instance, if the type is a data source, this
        /// will be the list of data source IDs to limit the report contents to.
        /// </summary>
        char** filterIds;
		/// <summary>
        /// The size of <see cref="filterIds"/>.
        /// </summary>
        int filterIdSize;
        /// <summary>
        /// The resource type to filter by in the report.
        /// </summary>
        VxReportFilterType::Value type;
    };
}

#endif // VxReportFilter_h__