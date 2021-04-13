#ifndef VxVideoEncodingOption_h__
#define VxVideoEncodingOption_h__

#include "VxPrimitives.h"

namespace VxSdk {
    /// <summary>
    /// Represents the valid video encoding options/limits for the specified format.
    /// </summary>
    struct VxVideoEncodingOption {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxVideoEncodingOption"/> struct.
        /// </summary>
        VxVideoEncodingOption() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxVideoEncodingOption"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxVideoEncodingOption(const VxVideoEncodingOption& ref) {
            this->format = ref.format;
            this->hasOptions = ref.hasOptions;
            this->maxBitrate = ref.maxBitrate;
            this->minBitrate = ref.minBitrate;
            this->maxGop = ref.maxGop;
            this->minGop = ref.minGop;
            this->frameratesSize = ref.frameratesSize;
            this->profilesSize = ref.profilesSize;
            this->rateControlsSize = ref.rateControlsSize;
            this->resolutionsSize = ref.resolutionsSize;
            this->framerates = nullptr;
            if (ref.framerates != nullptr) {
                this->framerates = new float[ref.frameratesSize];
                for (int i = 0; i < ref.frameratesSize; i++)
                    this->framerates[i] = ref.framerates[i];
            }

            this->profiles = nullptr;
            if (ref.profiles != nullptr) {
                this->profiles = new VxEncoderProfile::Value[ref.profilesSize];
                for (int i = 0; i < ref.profilesSize; i++)
                    this->profiles[i] = ref.profiles[i];
            }
           
            this->rateControls = nullptr;
            if (ref.rateControls != nullptr) {
                this->rateControls = new char* [ref.rateControlsSize];
                for (int i = 0; i < ref.rateControlsSize; i++) {
                    const size_t len = strlen(ref.rateControls[i]) + 1;
                    this->rateControls[i] = new char[len];
                    Utilities::StrCopySafe(this->rateControls[i], ref.rateControls[i], len);
                }
            }

            this->resolutions = nullptr;
            if (ref.resolutions != nullptr) {
                this->resolutions = new VxResolution[ref.resolutionsSize];
                for (int i = 0; i < ref.resolutionsSize; i++)
                    this->resolutions[i] = VxResolution(ref.resolutions[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxVideoEncodingOption"/> class.
        /// </summary>
        ~VxVideoEncodingOption() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->hasOptions = false;
            this->framerates = nullptr;
            this->frameratesSize = 0;
            this->maxBitrate = 0;
            this->maxGop = 0;
            this->minBitrate = 0;
            this->minGop = 0;
            this->profilesSize = 0;
            this->resolutionsSize = 0;
            this->profiles = nullptr;
            this->rateControlsSize = 0;
            this->rateControls = nullptr;
            this->resolutions = nullptr;
            this->format = VxStreamFormat::kUnknown;
        }

    public:
        /// <summary>
        /// Indicates whether there are any video encoding options available. If <c>true</c> you must first switch to
        /// the <see cref="format"/> to determine them.
        /// </summary>
        bool hasOptions;
        /// <summary>
        /// The list of available methods that control the bitrate of the stream.
        /// </summary>
        char** rateControls;
        /// <summary>
        /// The list of valid framerates.
        /// </summary>	 
        float* framerates;
        /// <summary>
        /// The size of <see cref="framerates"/>.
        /// </summary>
        int frameratesSize;
        /// <summary>
        /// The maximum bitrate that can be set for the stream (in bps).
        /// </summary>
        int maxBitrate;
        /// <summary>
        /// The maximum GOP size that can be set for the stream.
        /// </summary>	 
        int maxGop;
        /// <summary>
        /// The minimum bitrate that can be set for the stream (in bps).
        /// </summary>
        int minBitrate;
        /// <summary>
        /// The minimum GOP size that can be set for the stream.
        /// </summary>	 
        int minGop;
        /// <summary>
        /// The size of <see cref="profiles"/>.
        /// </summary>
        int profilesSize;
        /// <summary>
        /// The size of <see cref="rateControls"/>.
        /// </summary>
        int rateControlsSize;
        /// <summary>
        /// The size of <see cref="resolutions"/>.
        /// </summary>
        int resolutionsSize;
        /// <summary>
        /// The list of encoding profiles that are available for the stream.
        /// </summary>	 
        VxEncoderProfile::Value* profiles;
        /// <summary>
        /// The list of resolutions that are available for the stream.
        /// </summary>
        VxResolution* resolutions;
        /// <summary>
        /// The media stream encoding format that these options/limits apply to.
        /// </summary>
        VxStreamFormat::Value format;
    };
}

#endif // VxVideoEncodingOption_h__