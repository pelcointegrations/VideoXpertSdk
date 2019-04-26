#ifndef VxNewExportClip_h__
#define VxNewExportClip_h__

#include "IVxDataSource.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a clip that will be exported as part of a new export.
    /// </summary>
    struct VxNewExportClip {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExportClip"/> struct.
        /// </summary>
        VxNewExportClip() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExportClip"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewExportClip(const VxNewExportClip& ref) {
            Utilities::StrCopySafe(this->dataEncodingId, ref.dataEncodingId);
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewExportClip"/> class.
        /// </summary>
        ~VxNewExportClip() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataEncodingId);
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
        }

    public:
        /// <summary>
        /// The specific data encoding to export (quality, framerate, and resolution). This can be obtained from the
        /// desired data interface of the clip. If not specified, the server shall select the data encoding.
        /// </summary>
        char dataEncodingId[64];
        /// <summary>
        /// The unique identifier of the data source.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The time at which the clip ends.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time at which the clip begins.
        /// </summary>
        char startTime[64];
    };
}

#endif // VxNewExportClip_h__
