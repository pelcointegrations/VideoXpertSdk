#ifndef VxNewManualRecording_h__
#define VxNewManualRecording_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// DEPRECATED: Replaced by VxNewRecording.
    /// <para>
    /// Represents a request for a new manual recording to be generated.
    /// </para>
    /// </summary>
    struct VxNewManualRecording {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewManualRecording"/> struct.
        /// </summary>
        VxNewManualRecording() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewManualRecording"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewManualRecording(const VxNewManualRecording& ref) {
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            this->postRecord = ref.postRecord;
            this->preRecord = ref.preRecord;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewManualRecording"/> class.
        /// </summary>
        ~VxNewManualRecording() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            this->postRecord = 0;
            this->preRecord = 0;
        }

    public:
        /// <summary>
        /// The unique identifier of the data source to manually record.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The amount of time, from 0 to 30 seconds, to record after the manual recording is stopped.
        /// </summary>
        int postRecord;
        /// <summary>
        /// The amount of time, from 0 to 30 seconds, to record prior to the manual recording start time.
        /// </summary>
        int preRecord;
    };
}

#endif // VxNewManualRecording_h__