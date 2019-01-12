#ifndef VxMonitorPosition_h__
#define VxMonitorPosition_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxRect.h"

namespace VxSdk {
    /// <summary>
    /// Represents a monitor position that describes where a monitor resides in a coordinate plane (specifically the
    /// IV quadrant of a Cartesian plane where 0,0 is the top left point).
    /// </summary>
    struct VxMonitorPosition {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxMonitorPosition"/> struct.
        /// </summary>
        VxMonitorPosition() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxMonitorPosition"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxMonitorPosition(const VxMonitorPosition& ref) {
            Utilities::StrCopySafe(this->monitorId, ref.monitorId);
            this->position = VxRect(ref.position);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxMonitorPosition"/> class.
        /// </summary>
        ~VxMonitorPosition() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->monitorId);
            this->position.Clear();
        }

    public:
        /// <summary>
        /// The unique identifier of the monitor that this position represents.
        /// </summary>
        char monitorId[64];
        /// <summary>
        /// The position and size of the monitor.
        /// </summary>
        VxRect position;
    };
}

#endif // VxMonitorPosition_h__