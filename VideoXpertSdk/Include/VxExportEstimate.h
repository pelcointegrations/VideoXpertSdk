#ifndef VxExportEstimate_h__
#define VxExportEstimate_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents an estimate for an export.
    /// </summary>
    struct VxExportEstimate {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxExportEstimate"/> struct.
        /// </summary>
        VxExportEstimate() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxExportEstimate"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxExportEstimate(const VxExportEstimate& ref) {
            this->isTooLarge = ref.isTooLarge;
            this->size = ref.size;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxExportEstimate"/> class.
        /// </summary>
        ~VxExportEstimate() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isTooLarge = false;
            this->size = 0;
        }

    public:
        /// <summary>
        /// If <c>true</c>, indicates that the server was unable to estimate the entire request because it was too
        /// large and the <see cref="size"/> value is a minimum amount and not the actual estimate.
        /// </summary>
        bool isTooLarge;
        /// <summary>
        /// The estimated file size of the exported media in kilobytes (KB); will be 0 if unknown or unavailable.
        /// </summary>
        int size;
    };
}

#endif // VxExportEstimate_h__