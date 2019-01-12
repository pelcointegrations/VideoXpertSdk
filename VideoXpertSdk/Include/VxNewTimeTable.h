#ifndef VxNewTimeTable_h__
#define VxNewTimeTable_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxTimeRange.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new time table to be created.
    /// </summary>
    struct VxNewTimeTable {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewTimeTable"/> struct.
        /// </summary>
        VxNewTimeTable() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewTimeTable"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewTimeTable(const VxNewTimeTable& ref) {
            Utilities::StrCopySafe(this->endDate, ref.endDate);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->startDate, ref.startDate);
            this->weeklyTimeRangeSize = ref.weeklyTimeRangeSize;
            this->weeklyTimeRanges = nullptr;
            if (ref.weeklyTimeRanges != nullptr) {
                this->weeklyTimeRanges = new VxTimeRange[ref.weeklyTimeRangeSize];
                for(int i = 0; i < ref.weeklyTimeRangeSize; i++)
                    this->weeklyTimeRanges[i] = VxTimeRange(ref.weeklyTimeRanges[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewTimeTable"/> struct.
        /// </summary>
        ~VxNewTimeTable() {
            Clear();
        }

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

    public:
        /// <summary>
        /// The time table will be considered inactive after this date.
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
        /// The time table will be considered active after this date.
        /// </summary>
        char startDate[64];
        /// <summary>
        /// The size of <see cref="weeklyTimeRanges"/>.
        /// </summary>
        int weeklyTimeRangeSize;
        /// <summary>
        /// The active time ranges for this time table.
        /// </summary>
        VxTimeRange* weeklyTimeRanges;
    };
}

#endif // VxNewTimeTable_h__
