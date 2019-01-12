#ifndef IVxDataInterface_h__
#define IVxDataInterface_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a data interface for a data source. Clients can retrieve data from the data source using the
    /// protocol specified by this interface.
    /// </summary>
    struct IVxDataInterface {
    public:
        /// <summary>
        /// Indicates whether the interface provides a transcoded stream.
        /// </summary>
        bool isTranscoded;
        /// <summary>
        /// Indicates whether the interface provides multicast transmission.
        /// </summary>
        bool supportsMulticast;
        /// <summary>
        /// The unique identifier for a specific data encoding (based on encoding quality, framerate, and resolution).
        /// Multiple identical copies of the data may exist across the system; these will have the same dataEncodingId.
        /// This ID may be used when requesting a specific encoding to export, record, playback, etc.
        /// </summary>
        char dataEncodingId[64];
        /// <summary>
        /// The protocol-specific stream control endpoint URI.
        /// </summary>
        char dataEndpoint[512];
        /// <summary>
        /// The multicast test IP used to test transmission capabilities.
        /// </summary>
        char multicastTestIp[64];
        /// <summary>
        /// The framerate of the data.
        /// </summary>
        float framerate;
        /// <summary>
        /// Average bitrate of the stream, if available (in kbps).
        /// </summary>
        int bitrate;
        /// <summary>
        /// The size of <see cref="overlayTypes"/>.
        /// </summary>
        int overlayTypeSize;
        /// <summary>
        /// Horizontal resolution of the data.
        /// </summary>
        int xResolution;
        /// <summary>
        /// Vertical resolution of the data.
        /// </summary>
        int yResolution;
        /// <summary>
        /// The multicast test port used to test transmission capabilities.
        /// </summary>
        unsigned short multicastTestPort;
        /// <summary>
        /// The available overlays.
        /// </summary>
        VxOverlayType::Value* overlayTypes;
        /// <summary>
        /// The type of rendering required for the media data delivered by this interface. Clients can utilize this to
        /// create the correct rendering pipeline. Defaults to standard.
        /// </summary>
        VxRenderType::Value renderType;
        /// <summary>
        /// The media stream encoding format.
        /// </summary>
        VxStreamFormat::Value format;
        /// <summary>
        /// The transport protocol used by the data interface.
        /// </summary>
        VxStreamProtocol::Value protocol;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isTranscoded = false;
            this->supportsMulticast = false;
            VxZeroArray(this->dataEncodingId);
            VxZeroArray(this->dataEndpoint);
            VxZeroArray(this->multicastTestIp);
            this->framerate = 0.0f;
            this->bitrate = 0;
            this->overlayTypeSize = 0;
            this->xResolution = 0;
            this->yResolution = 0;
            this->multicastTestPort = 0;
            this->overlayTypes = nullptr;
            this->renderType = VxRenderType::kUnknown;
            this->format = VxStreamFormat::kUnknown;
            this->protocol = VxStreamProtocol::kUnknown;
        }
    };
}

#endif // IVxDataInterface_h__