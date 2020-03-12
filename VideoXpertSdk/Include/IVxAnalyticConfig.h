#ifndef IVxAnalyticConfig_h__
#define IVxAnalyticConfig_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "VxPoint.h"

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
        /// Gets the configured analytic behaviors.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="analyticBehaviorCollection">A <see cref="VxCollection"/> of the analytic behaviors.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticBehaviors(VxCollection<IVxAnalyticBehavior**>& analyticBehaviorCollection) const = 0;
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
        /// Sets the coordinate system used for all analytic behavior data.
        /// </summary>
        /// <remarks>
        /// For example, if x=800 and y=600, then: (0,0) would be the pixel in the upper left corner of the camera’s
        /// field of view, (799,599) would be the pixel in the lower right corner, and (400,300) would be one of the
        /// four pixels right at the dead center.
        /// </remarks>
        /// <param name="size">The new size value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSize(VxPoint& size) = 0;

    public:
        /// <summary>
        /// The unique identifier of the analytic configuration.
        /// </summary>
        char id[64];
        /// <summary>
        /// Specifies the coordinate system used for all analytic behavior data.
        /// </summary>
        VxPoint size;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            this->size.Clear();
        }
    };
}
#endif // IVxAnalyticConfig_h__
