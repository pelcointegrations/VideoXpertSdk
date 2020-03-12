#ifndef IVxTimeTable_h__
#define IVxTimeTable_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"

namespace VxSdk {
    /// <summary>
    /// Represents a named set of time ranges.
    /// </summary>
    struct IVxTimeTable {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this time table from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this time table.</returns>
        virtual VxResult::Value DeleteTimeTable() const = 0;
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
        /// Sets the end date property.
        /// </summary>
        /// <param name="endDate">The new end date value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEndDate(char endDate[64]) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the start date property.
        /// </summary>
        /// <param name="startDate">The new start date value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetStartDate(char startDate[64]) = 0;
        /// <summary>
        /// Sets active time ranges for this time table.
        /// </summary>
        /// <param name="weeklyTimeRanges">The time ranges to set for this time table.</param>
        /// <param name="weeklyTimeRangeSize">
        /// The size of <see cref="weeklyTimeRanges"/>, a value of 0 will clear out any existing time ranges.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetWeeklyTimeRanges(VxTimeRange** weeklyTimeRanges, int weeklyTimeRangeSize) = 0;

    public:
        /// <summary>
        /// The time table will will be considered inactive after this date.
        /// </summary>
        char endDate[64];
        /// <summary>
        /// The unique identifier of the time table.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the time table.
        /// </summary>
        char name[64];
        /// <summary>
        /// The time table will will be considered active after this date.
        /// </summary>
        char startDate[64];
        /// <summary>
        /// The size of <see cref="weeklyTimeRanges"/>.
        /// </summary>
        int weeklyTimeRangeSize;
        /// <summary>
        /// The active time ranges for this time table.
        /// </summary>
        VxTimeRange** weeklyTimeRanges;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->endDate);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->startDate);
            this->weeklyTimeRangeSize = 0;
            this->weeklyTimeRanges = nullptr;
        }
    };
}

#endif // IVxTimeTable_h__
