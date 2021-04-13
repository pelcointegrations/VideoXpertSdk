#ifndef VxLineCountingRequest_h__
#define VxLineCountingRequest_h__

#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPrimitives.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for line count values.
    /// </summary>
    struct VxLineCountingRequest {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCountingRequest"/> struct.
        /// </summary>
        VxLineCountingRequest() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCountingRequest"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLineCountingRequest(const VxLineCountingRequest& ref) {
            this->interval = ref.interval;
            Utilities::StrCopySafe(this->endTime, ref.endTime);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            this->analyticBehaviorIdSize = ref.analyticBehaviorIdSize;
            this->analyticBehaviorIds = nullptr;
            if (ref.analyticBehaviorIds != nullptr) {
                this->analyticBehaviorIds = new char* [ref.analyticBehaviorIdSize];
                for (int i = 0; i < ref.analyticBehaviorIdSize; i++) {
                    const size_t len = strlen(ref.analyticBehaviorIds[i]) + 1;
                    this->analyticBehaviorIds[i] = new char[len];
                    Utilities::StrCopySafe(this->analyticBehaviorIds[i], ref.analyticBehaviorIds[i], len);
                }
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLineCountingRequest"/> class.
        /// </summary>
        ~VxLineCountingRequest() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->analyticBehaviorIdSize = 0;
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime)
            this->analyticBehaviorIds = nullptr;
            this->interval = VxTimeInterval::kUnknown;;
        }

    public:
        /// <summary>
        /// The list of unique identifiers of the analytic behaviors to report line counters for.
        /// </summary>
        char** analyticBehaviorIds;
        /// <summary>
        /// The end time of the line count interval. If not specified, the current time will be used.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The start time of the line count interval.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The size of <see cref="analyticBehaviorIds"/>.
        /// </summary>
        int analyticBehaviorIdSize;
        /// <summary>
        /// The summarization interval to use for the counter values.
        /// </summary>
        VxTimeInterval::Value interval;
    };
}

#endif // VxLineCountingRequest_h__
