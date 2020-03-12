#ifndef IVxFileRecovery_h__
#define IVxFileRecovery_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a file recovery controller/monitoring resource for a recorder.
    /// </summary>
    struct IVxFileRecovery {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Halts any file recovery in process.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of halting the file recovery process.</returns>
        virtual VxResult::Value Halt() = 0;
        /// <summary>
        /// Refreshes this objects values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Triggers a file recovery.
        /// </summary>
        /// <param name="volumeId">The unique identifier of the volume to recover files from.</param>
        /// <param name="startTime">The start time; files created before this time will not be recovered.</param>
        /// <param name="endTime">The end time; files created after this time will not be recovered.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of triggering the file recovery.</returns>
        virtual VxResult::Value Trigger(const char* volumeId, const char* startTime, const char* endTime) = 0;

    public:
        /// <summary>
        /// The message about the current status of the file recovery, if any.
        /// </summary>
        char statusMessage[512];
        /// <summary>
        /// The number of files recovered.
        /// </summary>
        int filesRecovered;
        /// <summary>
        /// The current status of the file recovery.
        /// </summary>
        VxFileRecoveryStatus::Value status;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->statusMessage);
            this->filesRecovered = 0;
            this->status = VxFileRecoveryStatus::kUnknown;
        }
    };
}
#endif // IVxFileRecovery_h__
