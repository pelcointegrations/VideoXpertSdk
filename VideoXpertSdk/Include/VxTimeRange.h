#ifndef VxTimeRange_h__
#define VxTimeRange_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a range of time, specified by three mandatory fields. If the start time is greater than the end
    /// time, the range will be inactive.
    /// </summary>
    struct VxTimeRange {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxTimeRange"/> struct.
        /// </summary>
        VxTimeRange() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxTimeRange"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxTimeRange(const VxTimeRange& ref) {
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            this->day = ref.day;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxTimeRange"/> class.
        /// </summary>
        ~VxTimeRange() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            this->day = VxDayOfWeek::kUnknown;
        }

    public:
        /// <summary>
        /// The time at which this range ends (inclusive), from 00:00:00 to 23:59:59.
        /// </summary>
        char endTime[9];
        /// <summary>
        /// The time at which this range begins (inclusive), from 00:00:00 to 23:59:59.
        /// </summary>
        char startTime[9];
        /// <summary>
        /// The day of the week that this time range applies to.
        /// </summary>
        VxDayOfWeek::Value day;
    };
}

#endif // VxTimeRange_h__