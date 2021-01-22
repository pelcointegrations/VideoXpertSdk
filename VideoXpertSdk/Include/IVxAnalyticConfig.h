#ifndef IVxAnalyticConfig_h__
#define IVxAnalyticConfig_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "VxResolution.h"

namespace VxSdk {
    struct IVxAnalyticBehavior;

    /// <summary>
    /// Represents a specific analytic configuration for a data source.
    /// </summary>
    struct IVxAnalyticConfig {
    public:
        /// <summary>
        /// Creates a new analytic behavior.
        /// </summary>
        /// <param name="newAnalyticBehavior">The new analytic behavior to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddAnalyticBehavior(VxNewAnalyticBehavior& newAnalyticBehavior) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the minConfidence property.
        /// </summary>
        /// <param name="minConfidence">The new minConfidence value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMinConfidence(float minConfidence) = 0;
        /// <summary>
        /// Sets the ptzPresetName property.
        /// </summary>
        /// <param name="ptzPresetName">The new ptzPresetName value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPtzPresetName(char ptzPresetName[64]) = 0;
        /// <summary>
        /// Sets the size property.
        /// </summary>
        /// <param name="size">The new size value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSize(VxResolution& size) = 0;

    public:
        /// <summary>
        /// The unique identifier of the analytic configuration.
        /// </summary>
        char id[64];
        /// <summary>
        /// Specifies the name of the PtzPreset that this configuration relates to. 
        /// PTZ cameras supporting analytics can only be configured on PTZ presets.
        /// </summary>
        char ptzPresetName[64];
        /// <summary>
        /// Defines the minimum confidence filtering value for detected objects 
        /// in a video scene. Minimum confidence is defined as percentage of confidence 
        /// represented as a decimal. For example, 0.0 = 0%, and 1.0 = 100%. Objects that 
        /// have a detected confidence value less than the minimum will not be processed 
        /// by the associated list of AnalyticBehavior.
        /// </summary>
        float minConfidence;
        /// <summary>
        /// The size of <see cref="analyticBehaviors"/>.
        /// </summary>
        int analyticBehaviorSize;
        /// <summary>
        /// The associated analytic behaviors for this config.
        /// </summary>
        IVxAnalyticBehavior** analyticBehaviors;
        /// <summary>
        /// Specifies the resolution of the grid used for all AnalyticBehavior data.
        /// </summary>
        VxResolution size;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->ptzPresetName);
            this->size.Clear();
            this->minConfidence = 0;
            this->analyticBehaviorSize = 0;
            this->analyticBehaviors = nullptr;
        }
    };
}
#endif // IVxAnalyticConfig_h__
