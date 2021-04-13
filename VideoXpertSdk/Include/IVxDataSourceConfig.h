#ifndef IVxDataSourceConfig_h__
#define IVxDataSourceConfig_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "VxLimits.h"
#include "VxResolution.h"
#include "VxVideoEncodingOption.h"

namespace VxSdk {
    /// <summary>
    /// Represents the configuration of a data source.
    /// </summary>
    struct IVxDataSourceConfig {
    public:
        /// <summary>
        /// Represents a motion detection configuration.
        /// </summary>
        struct Motion {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the mode property.
            /// </summary>
            /// <param name="mode">The new mode value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMode(VxMotionMode::Value mode) = 0;
            /// <summary>
            /// Sets the sensitivity property.
            /// </summary>
            /// <param name="sensitivity">The new sensitivity value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSensitivity(int sensitivity) = 0;
            /// <summary>
            /// Sets the threshold property.
            /// </summary>
            /// <param name="threshold">The new threshold value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetThreshold(int threshold) = 0;

        public:
            /// <summary>
            /// The amount of change that needs to occur in order to qualify as motion. Higher values increase
            /// sensitivity (less change required to trigger motion).
            /// </summary>
            int sensitivity;
            /// <summary>
            /// The amount of area that needs to occur in order to qualify as motion. Higher values increase
            /// sensitivity (less area required to trigger motion).
            /// </summary>
            int threshold;
            /// <summary>
            /// The motion detection mode.
            /// </summary>
            VxMotionMode::Value mode;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->sensitivity = 0;
                this->threshold = 0;
                this->mode = VxMotionMode::kUnknown;
            }
        };

        /// <summary>
        /// Represents a configuration of PTZ for a particular video data source.
        /// </summary>
        struct Ptz {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the protocol property.
            /// </summary>
            /// <param name="protocol">The new PTZ protocol value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetProtocol(VxPtzControlProtocol::Value protocol) = 0;

        public:
            /// <summary>
            /// The protocol used by the encoder device to PTZ this channel.
            /// </summary>
            VxPtzControlProtocol::Value protocol;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->protocol = VxPtzControlProtocol::kUnknown;
            }
        };

        /// <summary>
        /// Represents a configuration of Smart Compression for a particular video data source.
        /// </summary>
        struct SmartCompression {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the denaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetDenaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the level property.
            /// </summary>
            /// <param name="level">The new Smart Compression level value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetLevel(VxSmartCompressionLevel::Value level) = 0;
            /// <summary>
            /// Sets the nonaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetNonaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the octonaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetOctonaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the primaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetPrimaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the quaternaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetQuaternaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the quinaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetQuinaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the secondaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSecondaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the senaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSenaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the septenaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSeptenaryDynamicGop(int gop) = 0;
            /// <summary>
            /// Sets the tertiaryDynamicGop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTertiaryDynamicGop(int gop) = 0;

        public:
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the denary (10th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>
            int denaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the nonary (9th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>
            int nonaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the octonary (8th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int octonaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the primary (1st) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int primaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the quaternary (4th) stream and the value is the maximum number
            /// of frames between I-frames.
            /// </summary>	 
            int quaternaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the quinary (5th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int quinaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the secondary (2nd) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary> 
            int secondaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the senary (6th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int senaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the septenary (7th) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int septenaryDynamicGop;
            /// <summary>
            /// If not 0, dynamic GOP is enabled for the tertiary (3rd) stream and the value is the maximum number of
            /// frames between I-frames.
            /// </summary>	 
            int tertiaryDynamicGop;
            /// <summary>
            /// The Smart Compression level.  Offers a trade-off between image quality and compression efficiency.
            /// When not disabled, dynamic GOP can be enabled for each stream.
            /// </summary>
            VxSmartCompressionLevel::Value level;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->denaryDynamicGop = 0;
                this->nonaryDynamicGop = 0;
                this->octonaryDynamicGop = 0;
                this->primaryDynamicGop = 0;
                this->quaternaryDynamicGop = 0;
                this->quinaryDynamicGop = 0;
                this->secondaryDynamicGop = 0;
                this->senaryDynamicGop = 0;
                this->septenaryDynamicGop = 0;
                this->tertiaryDynamicGop = 0;
                this->level = VxSmartCompressionLevel::kUnknown;
            }
        };

        /// <summary>
        /// Represents a configuration of a video encoding.
        /// </summary>
        struct VideoEncoding {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Sets the bitrate property.
            /// </summary>
            /// <param name="bitrate">The new bitrate value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetBitrate(int bitrate) = 0;
            /// <summary>
            /// Sets the format property.
            /// </summary>
            /// <param name="format">The new format value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetFormat(VxStreamFormat::Value format) = 0;
            /// <summary>
            /// Sets the framerate property.
            /// </summary>
            /// <param name="framerate">The new framerate value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetFramerate(float framerate) = 0;
            /// <summary>
            /// Sets the gop property.
            /// </summary>
            /// <param name="gop">The new gop value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetGop(int gop) = 0;
            /// <summary>
            /// Sets the multicastIp property.
            /// </summary>
            /// <param name="multicastIp">The new multicast IP value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMulticastIp(char multicastIp[64]) = 0;
            /// <summary>
            /// Sets the multicastPort property.
            /// </summary>
            /// <param name="multicastPort">The new multicast port value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMulticastPort(int multicastPort) = 0;
            /// <summary>
            /// Sets the name property.
            /// </summary>
            /// <param name="name">The new name value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetName(char name[64]) = 0;
            /// <summary>
            /// Sets the profile property.
            /// </summary>
            /// <param name="profile">The new profile value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetProfile(VxEncoderProfile::Value profile) = 0;
            /// <summary>
            /// Sets the rateControl property.
            /// </summary>
            /// <param name="rateControl">The new rate control value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetRateControl(char rateControl[64]) = 0;
            /// <summary>
            /// Sets the resolution property.
            /// </summary>
            /// <param name="resolution">The new resolution value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetResolution(VxResolution& resolution) = 0;

        public:
            /// <summary>
            /// The friendly name for this stream.
            /// </summary>	 
            char name[64];
            /// <summary>
            /// The IP used for multicast streaming.
            /// </summary>	 
            char multicastIp[64];
            /// <summary>
            /// The method used to control the bitrate of the stream.
            /// </summary>	 
            char rateControl[64];
            /// <summary>
            /// The framerate of the stream.
            /// </summary>	 
            float framerate;
            /// <summary>
            /// The bitrate of the stream (in bps).
            /// </summary>
            int bitrate;
            /// <summary>
            /// The size of <see cref="configurationOptions"/>.
            /// </summary>
            int configurationOptionsSize;
            /// <summary>
            /// The GOP size of the stream.
            /// </summary>	 
            int gop;
            /// <summary>
            /// The port used for multicast streaming.
            /// </summary> 
            int multicastPort;
            /// <summary>
            /// The encoding profile for the format.
            /// </summary>	 
            VxEncoderProfile::Value profile;
            /// <summary>
            /// A list of the valid video encoding options for each format. If the format does not contain any options
            /// you must first switch to that format to determine them.
            /// </summary>
            VxVideoEncodingOption** configurationOptions;
            /// <summary>
            /// The resolution of the stream.
            /// </summary>
            VxResolution resolution;
            /// <summary>
            /// The media stream encoding format.
            /// </summary>	 
            VxStreamFormat::Value format;
            /// <summary>
            /// The ordinal source of the stream: primary, secondary, tertiary, etc.
            /// </summary>
            VxStreamSource::Value stream;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->name);
                VxZeroArray(this->multicastIp);
                VxZeroArray(this->rateControl);
                this->framerate = 0;
                this->bitrate = 0;
                this->configurationOptionsSize = 0;
                this->gop = 0;
                this->multicastPort = 0;
                this->profile = VxEncoderProfile::kUnknown;
                this->configurationOptions = nullptr;
                this->resolution.Clear();
                this->format = VxStreamFormat::kUnknown;
                this->stream = VxStreamSource::kUnknown;
            }
        };
    };
}

#endif // IVxDataSourceConfig_h__
