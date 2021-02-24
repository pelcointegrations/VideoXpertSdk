#ifndef VxNewAnalyticConfig_h__
#define VxNewAnalyticConfig_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxResolution.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for the creation of a new analytic config.
    /// </summary>
    struct VxNewAnalyticConfig {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticConfig"/> struct.
        /// </summary>
        VxNewAnalyticConfig() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticConfig"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewAnalyticConfig(const VxNewAnalyticConfig& ref) {
            Utilities::StrCopySafe(this->ptzPresetName, ref.ptzPresetName);
            this->minConfidence = ref.minConfidence;
            this->size = VxResolution(ref.size);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewAnalyticConfig"/> class.
        /// </summary>
        ~VxNewAnalyticConfig() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->ptzPresetName);
            this->minConfidence = 0.5;
            this->size.Clear();
        }

    public:
        /// <summary>
        /// Specifies the name of the PTZ preset that this configuration relates to. 
        /// PTZ cameras supporting analytics can only be configured on PTZ presets.
        /// </summary>
        char ptzPresetName[64];
        /// <summary>
        /// Defines the minimum confidence filtering value for detected objects in a video
        /// scene. Objects that have a detected confidence value less than the minimum will
        /// not be processed by the associated list of analytic behaviors.
        /// </summary>
        float minConfidence;
        /// <summary>
        /// Specifies the resolution of the grid used for all analytic behaviors. The origin
        /// for the grid is the upper left corner.
        /// </summary>
        VxResolution size;
    };
}

#endif // VxNewAnalyticConfig_h__