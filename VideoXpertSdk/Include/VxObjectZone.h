#ifndef VxObjectZone_h__
#define VxObjectZone_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the data for an analytic object zone.
    /// </summary>
    struct VxObjectZone {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectZone"/> struct.
        /// </summary>
        VxObjectZone() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectZone"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxObjectZone(const VxObjectZone& ref) {
            this->verticesSize = ref.verticesSize;
            this->vertices = nullptr;
            if (ref.vertices != nullptr) {
                this->vertices = new VxPoint[ref.verticesSize];
                for (int i = 0; i < ref.verticesSize; i++)
                    this->vertices[i] = VxPoint(ref.vertices[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxObjectZone"/> class.
        /// </summary>
        ~VxObjectZone() {
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

#endif // VxObjectZone_h__