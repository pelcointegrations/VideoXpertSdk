#ifndef VxResolution_h__
#define VxResolution_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a resolution in pixels.
    /// </summary>
    struct VxResolution {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxResolution"/> struct.
        /// </summary>
        VxResolution() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxResolution"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxResolution(const VxResolution& ref) {
            this->height = ref.height;
            this->width = ref.width;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxResolution"/> class.
        /// </summary>
        ~VxResolution() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            height = 0;
            width = 0;
        }

    public:
        /// <summary>
        /// The height in pixels.
        /// </summary>
        int height;
        /// <summary>
        /// The width in pixels.
        /// </summary>
        int width;
    };
}

#endif // VxResolution_h__