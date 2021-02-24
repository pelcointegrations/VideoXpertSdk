#ifndef VxPoint_h__
#define VxPoint_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a location on a Cartesian grid.
    /// </summary>
    struct VxPoint {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxPoint"/> struct.
        /// </summary>
        VxPoint() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxPoint"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxPoint(const VxPoint& ref) {
            this->x = ref.x;
            this->y = ref.y;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxPoint"/> class.
        /// </summary>
        ~VxPoint() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            x = 0;
            y = 0;
        }

    public:
        /// <summary>
        /// The X-axis coordinate value.
        /// </summary>
        float x;
        /// <summary>
        /// The Y-axis coordinate value.
        /// </summary>
        float y;
    };
}

#endif // VxPoint_h__