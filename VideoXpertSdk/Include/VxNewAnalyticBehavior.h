#ifndef VxNewAnalyticBehavior_h__
#define VxNewAnalyticBehavior_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxObjectCounter.h"
#include "VxObjectZone.h"

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
            this->sensitivity = ref.sensitivity;
            this->severity = ref.severity;
            this->behaviorType = ref.behaviorType;
            this->objectType = ref.objectType;
            this->objectCounter = VxObjectCounter(ref.objectCounter);
            this->objectZone = VxObjectZone(ref.objectZone);
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
            this->sensitivity = 0;
            this->severity = 0;
            this->behaviorType = VxAnalyticBehaviorType::kUnknown;
            this->objectType = VxAnalyticObjectType::kUnknown;
            this->objectCounter.Clear();
            this->objectZone.Clear();
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
        char name[128];
        /// <summary>
        /// The sensitivity of the analysis. Higher values increase sensitivity.
        /// </summary>
        int sensitivity;
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
        /// The object counter data used when <see cref="behaviorType"/> is set to
        /// <see cref="VxAnalyticBehaviorType::kObjectCounter"/>.
        /// </summary>
        VxObjectCounter objectCounter;
        /// <summary>
        /// The object zone data used to configure analytics of <see cref="behaviorType"/> is set
        /// to <see cref="VxAnalyticBehaviorType::kObjectInZone"/>.
        /// </summary>
        VxObjectZone objectZone;
    };
}

#endif // VxNewAnalyticBehavior_h__