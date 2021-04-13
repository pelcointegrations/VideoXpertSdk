#ifndef VxNewDigitalPtzPreset_h__
#define VxNewDigitalPtzPreset_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new digital PTZ preset.
    /// </summary>
    struct VxNewDigitalPtzPreset {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDigitalPtzPreset"/> struct.
        /// </summary>
        VxNewDigitalPtzPreset() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDigitalPtzPreset"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDigitalPtzPreset(const VxNewDigitalPtzPreset& ref) {
            Utilities::StrCopySafe(this->description, ref.description);
            Utilities::StrCopySafe(this->name, ref.name);
            this->x = ref.x;
            this->y = ref.y;
            this->z = ref.z;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDigitalPtzPreset"/> class.
        /// </summary>
        ~VxNewDigitalPtzPreset() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->description);
            VxZeroArray(this->name);
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }

    public:
        /// <summary>
        /// The friendly description for the new PTZ preset.
        /// </summary>
        char description[64];
        /// <summary>
        /// The friendly name of the PTZ preset.
        /// </summary>
        char name[64];
        /// <summary>
        /// The X (pan) coordinate absolute position, in degrees, relative to the (0,0) position. The -180 position is
        /// leftmost while the 180 position is rightmost.
        /// </summary>
        float x;
        /// <summary>
        /// The Y (tilt) coordinate absolute position, in degrees, relative to the (0,0) position The -180 position is
        /// bottommost while the 180 position is topmost.
        /// </summary>
        float y;
        /// <summary>
        /// The Z (zoom) coordinate absolute position relative to the 0 position. The 0 position is minimum zoom while
        /// the 100 position is maximum zoom.
        /// </summary>
        float z;
    };
}

#endif // VxNewDigitalPtzPreset_h__