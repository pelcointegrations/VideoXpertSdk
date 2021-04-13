#ifndef VxLineCount_h__
#define VxLineCount_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents line counting information based on a line counting request. A line count is the number of times an
    /// identified object has crossed a configured object line counter within an interval specified in the line
    /// counting request.
    /// </summary>
    struct VxLineCount {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCount"/> struct.
        /// </summary>
        VxLineCount() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCount"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLineCount(const VxLineCount& ref) {
            Utilities::StrCopySafe(this->analyticBehaviorId, ref.analyticBehaviorId);
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            this->count = ref.count;
            this->countCorrection = ref.countCorrection;
            this->inCount = ref.inCount;
            this->inCountCorrection = ref.inCountCorrection;
            this->outCount = ref.outCount;
            this->outCountCorrection = ref.outCountCorrection;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLineCount"/> class.
        /// </summary>
        ~VxLineCount() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->analyticBehaviorId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            this->count = 0;
            this->countCorrection = 0;
            this->inCount = 0;
            this->inCountCorrection = 0;
            this->outCount = 0;
            this->outCountCorrection = 0;
        }

    public:
        /// <summary>
        /// The unique identifier of the analytic behavior this line count information is for.
        /// </summary>
        char analyticBehaviorId[64];
        /// <summary>
        /// The end time of the line count interval.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The start time of the line count interval.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The summarized line counter value for uni-directional and omni-directional counter types.
        /// </summary>
        int count;
        /// <summary>
        /// The correction value for the <see cref="count"/> of uni-directional and omni-directional counter types.
        /// </summary>
        int countCorrection;
        /// <summary>
        /// The summarized in line counter value for bi-directional counter types.
        /// </summary>
        int inCount;
        /// <summary>
        /// The correction value for the <see cref="inCount"/> of bi-directional counter types.
        /// </summary>
        int inCountCorrection;
        /// <summary>
        /// The summarized out line counter value for bi-directional counter types.
        /// </summary>
        int outCount;
        /// <summary>
        /// The correction value for the <see cref="outCount"/> of bi-directional counter types.
        /// </summary>
        int outCountCorrection;

    };
}

#endif // VxLineCount_h__
