#ifndef VxExportStreamClip_h__
#define VxExportStreamClip_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents streaming access to a single clip within an export.
    /// </summary>
    struct VxExportStreamClip {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxExportStreamClip"/> struct.
        /// </summary>
        VxExportStreamClip() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxExportStreamClip"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxExportStreamClip(const VxExportStreamClip& ref) {
            Utilities::StrCopySafe(this->audioDataSourceId, ref.audioDataSourceId);
            Utilities::StrCopySafe(this->audioUrl, ref.audioUrl);
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            Utilities::StrCopySafe(this->videoDataSourceId, ref.videoDataSourceId);
            Utilities::StrCopySafe(this->videoUrl, ref.videoUrl);
            this->renderType = ref.renderType;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxExportStreamClip"/> class.
        /// </summary>
        ~VxExportStreamClip() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->audioDataSourceId);
            VxZeroArray(this->audioUrl);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            VxZeroArray(this->videoDataSourceId);
            VxZeroArray(this->videoUrl);
            this->renderType = VxRenderType::kUnknown;
        }

    public:
        /// <summary>
        /// The identifier of the audio data source that the exported clip came from.
        /// </summary>
        char audioDataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The RTSP URL for streaming the audio data of the export.
        /// </summary>
        char audioUrl[1024];
        /// <summary>
        /// The time at which the export media ends.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time at which the export media begins.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The identifier of the video data source that the exported clip came from.
        /// </summary>
        char videoDataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The RTSP URL for streaming the video data of the export.
        /// </summary>
        char videoUrl[1024];
        /// <summary>
        /// The type of rendering required for the media data delivered by this interface. Clients can utilize this to
        /// create the correct rendering pipeline. 
        /// </summary>
        VxRenderType::Value renderType;
    };
}

#endif // VxExportStreamClip_h__
