#ifndef VxNewAnalyticSession_h__
#define VxNewAnalyticSession_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for the creation of a new analytic session.
    /// </summary>
    struct VxNewAnalyticSession {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticSession"/> struct.
        /// </summary>
        VxNewAnalyticSession() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticSession"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewAnalyticSession(const VxNewAnalyticSession& ref) {
            Utilities::StrCopySafe(this->dataEncodingId, ref.dataEncodingId);
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->deviceId, ref.deviceId);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->source, ref.source);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewAnalyticSession"/> class.
        /// </summary>
        ~VxNewAnalyticSession() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataEncodingId);
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->deviceId);
            VxZeroArray(this->id);
            VxZeroArray(this->source);
        }

    public:
        /// <summary>
        /// The unique identifier specifying which data encoding to use as a source. This value can be used instead
        /// of <see cref="source"/> to determine which stream to use.
        /// </summary>
        char dataEncodingId[64];
        /// <summary>
        /// The unique identifier of the video data source for this analytic session. The source URI should be pointing
        /// to an RTSP stream on this DataSource.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The unique identifier of the Device hosting this analytic session. The device must be of
        /// type <see cref="VxDeviceType::kAnalyticServer"/>.
        /// </summary>
        char deviceId[64];
        /// <summary>
        /// The unique identifier of the analytic session. The server will generate this value if not supplied.
        /// </summary>
        char id[64];
        /// <summary>
        /// The RTSP URI to use as the source for the analytic session. This value can be used instead
        /// of <see cref="dataEncodingId"/> to determine which stream to use. This value takes priority over
        /// the <see cref="dataEncodingId"/> if both values are provided. Note: This field is required when sending
        /// to a <see cref="VxDeviceType::kAnalyticServer"/>.
        /// </summary>
        char source[1024];
    };
}

#endif // VxNewAnalyticSession_h__