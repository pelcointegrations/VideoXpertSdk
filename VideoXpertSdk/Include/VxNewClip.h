#ifndef VxNewClip_h__
#define VxNewClip_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents request to create a new clip on a data storage using data from another data storage. The new clip
    /// will have the same <see cref="VxRecordingType::Value">recording type</see> as the data it is based on,
    /// defaulting to kTimed. Typically this is used to save data from a camera supporting edge storage to a recorder.
    /// </summary>
    struct VxNewClip {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewClip"/> struct.
        /// </summary>
        VxNewClip() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewClip"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewClip(const VxNewClip& ref) {
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->dataStorageId, ref.dataStorageId);
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewClip"/> class.
        /// </summary>
        ~VxNewClip() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->dataStorageId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
        }

    public:
        /// <summary>
        /// The unique identifier of the data source that generated the desired data.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The unique identifier of the data storage to retrieve the data from. The host device type must be
        /// <see cref="VxDeviceType::Value::kCamera"/> (it must be a camera supporting edge storage).
        /// </summary>
        char dataStorageId[64];
        /// <summary>
        /// The time at which to end the clip.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time at which to begin the clip.
        /// </summary>
        char startTime[64];
    };
}

#endif // VxNewClip_h__
