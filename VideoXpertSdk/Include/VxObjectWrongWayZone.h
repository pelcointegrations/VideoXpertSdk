#ifndef VxObjectWrongWayZone_h__
#define VxObjectWrongWayZone_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPoint.h"
#include "VxVector.h"

namespace VxSdk {
    /// <summary>
    /// Represents the configuration for an object wrong way type analytic behavior. Wrong-way zones
    /// generate events for all objects that are traveling opposite of a defined correct direction.
    /// </summary>
    struct VxObjectWrongWayZone {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectWrongWayZone"/> struct.
        /// </summary>
        VxObjectWrongWayZone() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectWrongWayZone"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxObjectWrongWayZone(const VxObjectWrongWayZone& ref) {
            this->minTriggerAngle = ref.minTriggerAngle;
            this->vector = VxVector(ref.vector);
            this->zoneSize = ref.zoneSize;
            this->zone = nullptr;
            if (ref.zone != nullptr) {
                this->zone = new VxPoint[ref.zoneSize];
                for (int i = 0; i < ref.zoneSize; i++)
                    this->zone[i] = VxPoint(ref.zone[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxObjectWrongWayZone"/> class.
        /// </summary>
        ~VxObjectWrongWayZone() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->minTriggerAngle = 110;
            this->vector.Clear();
            this->zoneSize = 0;
            this->zone = nullptr;
        }

    public:
        /// <summary>
        /// Defines the minimum angle between a detected object’s trajectory vector and the wrong-way
        /// zone’s vector. Any object that is traveling at an angle >= the minimum from the reference
        /// vector will be considered heading in the wrong-direction.
        /// </summary>
        int minTriggerAngle;
        /// <summary>
        /// The size of <see cref="zone"/>.
        /// </summary>
        int zoneSize;
        /// <summary>
        /// Defines the wrong-way zone’s vector. The vector points in the direction that indicates the
        /// correct direction of flow. An objects heading opposite the vector are considered to be heading
        /// in the wrong direction.
        /// </summary>
        VxVector vector;
        /// <summary>
        /// Ordered list of points that make up the wrong-way zone. The zone is defined as an simple convex
        /// quadrilateral. Do NOT repeat the starting vertex at the end of the list–it is implicitly included.
        /// </summary>
        VxPoint* zone;
    };
}

#endif // VxObjectWrongWayZone_h__