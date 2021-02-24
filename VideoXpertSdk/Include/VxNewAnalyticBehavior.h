#ifndef VxNewAnalyticBehavior_h__
#define VxNewAnalyticBehavior_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxObjectLineCounter.h"
#include "VxObjectInZone.h"
#include "VxObjectWrongWayZone.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for the creation of a new analytic behavior.
    /// </summary>
    struct VxNewAnalyticBehavior {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticBehavior"/> struct.
        /// </summary>
        VxNewAnalyticBehavior() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewAnalyticBehavior"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewAnalyticBehavior(const VxNewAnalyticBehavior& ref) {
            this->isEnabled = ref.isEnabled;
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->name, ref.name);
            this->severity = ref.severity;
            this->behaviorType = ref.behaviorType;
            this->objectType = ref.objectType;
            this->objectLineCounter = VxObjectLineCounter(ref.objectLineCounter);
            this->objectInZone = VxObjectInZone(ref.objectInZone);
            this->objectWrongWayZone = VxObjectWrongWayZone(ref.objectWrongWayZone);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewAnalyticBehavior"/> class.
        /// </summary>
        ~VxNewAnalyticBehavior() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isEnabled = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->severity = 0;
            this->behaviorType = VxAnalyticBehaviorType::kUnknown;
            this->objectType = VxAnalyticObjectType::kUnknown;
            this->objectLineCounter.Clear();
            this->objectInZone.Clear();
            this->objectWrongWayZone.Clear();
        }

    public:
        /// <summary>
        /// Indicates whether or not this analytic behavior is enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The unique identifier of the analytic behavior.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the analytic behavior.
        /// </summary>
        char name[64];
        /// <summary>
        /// The severity value for events generated from this analytic behavior, from 1 (highest) to 10 (lowest).
        /// If set, overrides the corresponding situation severity.
        /// </summary>
        int severity;
        /// <summary>
        /// The type of analytic behavior being performed.
        /// </summary>
        VxAnalyticBehaviorType::Value behaviorType;
        /// <summary>
        /// The type of object this analytic pertains to.
        /// </summary>
        VxAnalyticObjectType::Value objectType;
        /// <summary>
        /// The object zone data used to configure analytics of <see cref="behaviorType"/> is set
        /// to <see cref="VxAnalyticBehaviorType::kObjectInZone"/>.
        /// </summary>
        VxObjectInZone objectInZone;
        /// <summary>
        /// The object line counter data used when <see cref="behaviorType"/> is set to
        /// <see cref="VxAnalyticBehaviorType::kObjectLineCounter"/>.
        /// </summary>
        VxObjectLineCounter objectLineCounter;
        /// <summary>
        /// The object wrong way zone data used when <see cref="behaviorType"/> is set to
        /// <see cref="VxAnalyticBehaviorType::kObjectWrongWay"/>.
        /// </summary>
        VxObjectWrongWayZone objectWrongWayZone;
    };
}

#endif // VxNewAnalyticBehavior_h__