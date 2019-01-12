#ifndef IVxPreset_h__
#define IVxPreset_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a predefined point that a PTZ device can PTZ to when triggered.
    /// </summary>
    struct IVxPreset {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;

    public:
        /// <summary>
        /// Indicates whether this preset is digital.
        /// </summary>
        bool isDigital;
        /// <summary>
        /// The friendly description of the preset.
        /// </summary>
        char description[64];
        /// <summary>
        /// The friendly name of the preset.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique numerical sequence value of this preset.
        /// </summary>
        int index;
        /// <summary>
        /// The X (pan) coordinate absolute position, in degrees, relative to the (0, 0) position. The -180 position is
        /// leftmost while the 180 position is rightmost (digital presets only).
        /// </summary>
        float x;
        /// <summary>
        /// The Y (tilt) coordinate absolute position, in degrees, relative to the (0, 0) position. The -180 position
        /// is bottommost while the 180 position is topmost (digital presets only).
        /// </summary>
        float y;
        /// <summary>
        /// The Z (zoom) coordinate absolute position relative to the 0 position. The 0 position is minimum zoom while
        /// the 100 position is maximum zoom (digital presets only).
        /// </summary>
        float z;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isDigital = false;
            VxZeroArray(this->description);
            VxZeroArray(this->name);
            this->index = 0;
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }
    };
}

#endif // IVxPreset_h__
