#ifndef IVxBookmarkLock_h__
#define IVxBookmarkLock_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the lock configuration of a bookmark. An enabled lock will prevent the media it locks from being
    /// garbage collected on recorders.
    /// </summary>
    struct IVxBookmarkLock {
    public:
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
        /// Sets the endTime property.
        /// </summary>
        /// <param name="endTime">The new endTime value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEndTime(char endTime[64]) = 0;
        /// <summary>
        /// Sets the isEnabled property.
        /// </summary>
        /// <param name="isEnabled">The new isEnabled value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIsEnabled(bool isEnabled) = 0;
        /// <summary>
        /// Sets the startTime property.
        /// </summary>
        /// <param name="startTime">The new startTime value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetStartTime(char startTime[64]) = 0;

    public:
        /// <summary>
        /// Indicates whether or not the bookmark lock is enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The time at which the bookmark lock ends. Must be after startTime.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The time at which the bookmark lock begins. Must be before endTime.
        /// </summary>
        char startTime[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            isEnabled = false;
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
        }
    };
}
#endif // IVxBookmarkLock_h__
