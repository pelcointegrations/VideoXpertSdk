#ifndef IVxAnalyticBehavior_h__
#define IVxAnalyticBehavior_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxObjectCounter.h"
#include "VxObjectZone.h"

namespace VxSdk {

    /// <summary>
    /// Represents a specific analytic behavior for an analytic configuration.
    /// </summary>
    struct IVxAnalyticBehavior {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this analytic behavior.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the analytic behavior.</returns>
        virtual VxResult::Value DeleteAnalyticBehavior() const = 0;
        /// <summary>
        /// Disable this analytic behavior.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this analytic behavior.</returns>
        virtual VxResult::Value Disable() = 0;
        /// <summary>
        /// Enable this analytic behavior.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of enabling this analytic behavior.</returns>
        virtual VxResult::Value Enable() = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[128]) = 0;
        /// <summary>
        /// Sets the objectCounter property.
        /// </summary>
        /// <param name="objectCounter">The new objectCounter value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetObjectCounter(VxObjectCounter& objectCounter) = 0;
        /// <summary>
        /// Sets the objectType property.
        /// </summary>
        /// <param name="objectType">The new objectType value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetObjectType(VxAnalyticObjectType::Value objectType) = 0;
        /// <summary>
        /// Sets the objectZone property.
        /// </summary>
        /// <param name="objectZone">The new objectZone value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetObjectZone(VxObjectZone& objectZone) = 0;
        /// <summary>
        /// Sets the sensitivity of the analysis. Higher values increase sensitivity.
        /// </summary>
        /// <param name="sensitivity">The new sensitivity value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSensitivity(int sensitivity) = 0;
        /// <summary>
        /// Sets the severity value for events generated from this analytic behavior, from 1 (highest) to 10 (lowest).
        /// If set, overrides the corresponding situation severity.
        /// </summary>
        /// <param name="severity">The new severity value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSeverity(int severity) = 0;

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

    protected:
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
    };
}
#endif // IVxAnalyticBehavior_h__
