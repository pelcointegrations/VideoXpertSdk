#ifndef VxVector_h__
#define VxVector_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a starting coordinate and the angle from the horizontal axis the vector is pointing.
    /// </summary>
    struct VxVector {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxVector"/> struct.
        /// </summary>
        VxVector() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxVector"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxVector(const VxVector& ref) {
			this->angle = ref.angle;
            this->x = ref.x;
            this->y = ref.y;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxVector"/> class.
        /// </summary>
        ~VxVector() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
			angle = 0;
            x = 0;
            y = 0;
        }

    public:
		/// <summary>
		/// The direction as a counter-clockwise angle, in degrees, from the horizontal axis.
		/// </summary>
		int angle;
        /// <summary>
        /// Starting x-axis coordinate value.
        /// </summary>
        float x;
        /// <summary>
        /// Starting y-axis coordinate value.
        /// </summary>
        float y;
    };
}

#endif // VxVector_h__