#ifndef VxObjectLineCounter_h__
#define VxObjectLineCounter_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPoint.h"

namespace VxSdk {
    /// <summary>
    /// Represents the configuration for an object line counter type of analytic behavior.
    /// </summary>
    struct VxObjectLineCounter {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectLineCounter"/> struct.
        /// </summary>
        VxObjectLineCounter() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxObjectLineCounter"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxObjectLineCounter(const VxObjectLineCounter& ref) {
            this->endPoint = VxPoint(ref.endPoint);
            this->startPoint = VxPoint(ref.startPoint);
            this->eventWindowSecs = ref.eventWindowSecs;
            this->eventsEnabled = ref.eventsEnabled;
            Utilities::StrCopySafe(this->leftCountLabel, ref.leftCountLabel);
            Utilities::StrCopySafe(this->rightCountLabel, ref.rightCountLabel);
            this->lineCounterType = ref.lineCounterType;
            this->maxCountThreshold = ref.maxCountThreshold;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxObjectLineCounter"/> class.
        /// </summary>
        ~VxObjectLineCounter() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->leftCountLabel);
            VxZeroArray(this->rightCountLabel);
            this->endPoint.Clear();
            this->startPoint.Clear();
            this->eventWindowSecs = 0;
            this->eventsEnabled = false;
            this->lineCounterType = VxLineCounterType::kUnknown;
            this->maxCountThreshold = 0;
        }

    public:
        /// <summary>
        /// If true, line counter specific events for this line counter will be enabled.
        /// </summary>
        bool eventsEnabled;
        /// <summary>
        /// Friendly name associated with a bidirectional counter’s left count.
        /// </summary>
        char leftCountLabel[64];
        /// <summary>
        /// Friendly name associated with a bidirectional counter’s right count.
        /// </summary>
        char rightCountLabel[64];
        /// <summary>
        /// Define the event’s time window for testing if the counts 
        /// maximum threshold is met within this window. For example, 
        /// if <see cref="maxCountThreshold"/> is 100 and <see cref="eventWindowSecs"/> 
        /// is 3600 then an event would be generated if 100 objects cross a 
        /// counting line over the last hour. Once the hour elapses the 
        /// event trigger’s base count is reset and the count window slides to the 
        /// next hour and starts over. Ignored if <see cref="maxCountThreshold"/> is not set.
        /// </summary>
        int eventWindowSecs;
        /// <summary>
        /// The maximum count threshold that must be met before an event is triggered. 
        /// This value is used by both the bidirectional capacity events and the 
        /// sliding window events.
        /// </summary>
        int maxCountThreshold;	
        /// <summary>
        /// Defines the type of line counter (i.e. unidirectional, bidirectional, 
        /// or omnidirectional). The type defines how the line counter increments 
        /// and maintains it’s counts.
        /// </summary>
        VxLineCounterType::Value lineCounterType;
        /// <summary>
        /// The ending coordinate for the object counting line.
        /// </summary>
        VxPoint endPoint;
        /// <summary>
        /// The starting coordinate for the object counting line.
        /// </summary>
        VxPoint startPoint;
    };
}

#endif // VxObjectLineCounter_h__