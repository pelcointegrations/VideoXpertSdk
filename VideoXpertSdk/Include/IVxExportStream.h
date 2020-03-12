#ifndef IVxExportStream_h__
#define IVxExportStream_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents streaming access information for an export resource.
    /// </summary>
    struct IVxExportStream {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Halts any pending stream preparation. May only be performed when the export stream is being prepared.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of halting the export stream preparation.</returns>
        virtual VxResult::Value Halt() const = 0;
        /// <summary>
        /// Begins or re-starts preparation for streaming. May only be performed when the export stream needs
        /// preparation or has failed.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of preparing the export stream.</returns>
        virtual VxResult::Value Prepare() const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// This specifies how close stream preparation is to completion, where 100 indicates that stream is ready for
        /// streaming. This will only be populated when the status is preparing, failed, or ready. In a failed
        /// state, this represents how much progress was made (if any) prior to the failure.
        /// </summary>
        float percentComplete;
        /// <summary>
        /// The size of <see cref="exportStreamClips"/>.
        /// </summary>
        int exportStreamClipSize;
        /// <summary>
        /// Estimated time remaining, in seconds, until the export is 100% ready to be streamed. This will only be
        /// populated when the status is preparing or ready.
        /// </summary>
        int secondsRemaining;
        /// <summary>
        /// The export stream clips, which provide streaming playback information for each export clip.
        /// </summary>
        VxExportStreamClip** exportStreamClips;
        /// <summary>
        /// The current status of the export stream.
        /// </summary>
        VxExportStreamStatus::Value status;
        /// <summary>
        /// Optional reason for the current status of this export stream.
        /// </summary>
        VxExportStreamStatusReason::Value statusReason;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->exportStreamClips = 0;
            this->percentComplete = 0;
            this->secondsRemaining = 0;
            this->exportStreamClips = nullptr;
            this->status = VxExportStreamStatus::kUnknown;
            this->statusReason = VxExportStreamStatusReason::kUnknown;
        }
    };
}
#endif // IVxExportStream_h__
