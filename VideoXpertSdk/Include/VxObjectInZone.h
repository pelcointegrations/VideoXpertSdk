#ifndef VxObjectInZone_h__
#define VxObjectInZone_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPoint.h"

namespace VxSdk {
    /// <summary>
    /// Represents the configuration for an object in zone type of analytic behavior.
    /// </summary>
    struct VxObjectInZone {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectInZone"/> struct.
        /// </summary>
        VxObjectInZone() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectInZone"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxObjectInZone(const VxObjectInZone& ref) {
            this->verticesSize = ref.verticesSize;
            this->vertices = nullptr;
            if (ref.vertices != nullptr) {
                this->vertices = new VxPoint[ref.verticesSize];
                for (int i = 0; i < ref.verticesSize; i++)
                    this->vertices[i] = VxPoint(ref.vertices[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxObjectInZone"/> class.
        /// </summary>
        ~VxObjectInZone() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->verticesSize = 0;
            this->vertices = nullptr;
        }

    public:
        /// <summary>
        /// The size of <see cref="vertices"/>.
        /// </summary>
        int verticesSize;
        /// <summary>
        /// Ordered list of points that make up the zone. Must contain at least 3 points, which together
        /// specify the closed polygonal zone within which to look for objects of the prescribed type.
        /// </summary>
        VxPoint* vertices;
    };
}

#endif // VxObjectInZone_h__