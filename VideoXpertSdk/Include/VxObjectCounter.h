#ifndef VxObjectCounter_h__
#define VxObjectCounter_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPoint.h"

namespace VxSdk {
    /// <summary>
    /// Represents the data for an analytic object counter.
    /// </summary>
    struct VxObjectCounter {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectCounter"/> struct.
        /// </summary>
        VxObjectCounter() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectCounter"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxObjectCounter(const VxObjectCounter& ref) {
            this->intersectionArea = ref.intersectionArea;
            this->endPoint = VxPoint(ref.endPoint);
            this->startPoint = VxPoint(ref.startPoint);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxObjectCounter"/> class.
        /// </summary>
        ~VxObjectCounter() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->intersectionArea = VxIntersectionArea::kUnknown;
            this->endPoint.Clear();
            this->startPoint.Clear();
        }

    public:
        /// <summary>
        /// Associates this object counter with a specific area of an intersection.
        /// </summary>
        VxIntersectionArea::Value intersectionArea;
        /// <summary>
        /// The ending coordinate for the object counting line.
        /// </summary>
        VxPoint endPoint;
        /// <summary>
        /// The starting coordinate for the object counting line.
        /// </summary>
        VxPoint startPoint;
    };
}

#endif // VxObjectCounter_h__