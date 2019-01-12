#ifndef IVxScheduleTrigger_h__
#define IVxScheduleTrigger_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxTimeTable;

    /// <summary>
    /// Represents a schedule trigger. A schedule trigger is a time range and an optional event that together act as a
    /// trigger to activate a schedule and cause it to perform its configured action.
    /// </summary>
    struct IVxScheduleTrigger {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this schedule trigger from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the schedule trigger.</returns>
        virtual VxResult::Value DeleteScheduleTrigger() const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the event properties that must be present to activate the schedule trigger.
        /// </summary>
        /// <param name="eventProperties">The event properties.</param>
        /// <param name="eventPropertySize">The size of <see cref="eventProperties"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEventProperties(VxKvObject* eventProperties, int eventPropertySize) = 0;
        /// <summary>
        /// Sets the <see cref="IVxEvent::situationType">type</see> of events that will activate the schedule trigger.
        /// </summary>
        /// <param name="eventSituationType">The event situation type.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEventSituationType(char eventSituationType[128]) = 0;
        /// <summary>
        /// Sets the framerate level to record at.
        /// </summary>
        /// <param name="framerate">The framerate level.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFramerate(VxRecordingFramerate::Value framerate) = 0;
        /// <summary>
        /// Sets the amount of time to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm").
        /// </summary>
        /// <param name="postTrigger">The post trigger time in seconds, from 0 to 300.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPostTrigger(int postTrigger) = 0;
        /// <summary>
        /// Sets the amount of time to consider the schedule trigger active prior to when it becomes active
        /// ("pre alarm").
        /// </summary>
        /// <param name="preTrigger">The pre trigger time in seconds, from 0 to 30.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPreTrigger(int preTrigger) = 0;
        /// <summary>
        /// Sets the amount of time to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording").
        /// </summary>
        /// <param name="timeout">The timeout time in seconds, from 0 to 300.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTimeout(int timeout) = 0;
        /// <summary>
        /// Sets the time table unique identifier for this schedule trigger. If set, the schedule trigger will only
        /// be active during the time range(s) defined by this time table.
        /// </summary>
        /// <param name="timeTableId">The time table unique identifier.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTimeTableId(char timeTableId[64]) = 0;


    public:
        /// <summary>
        /// The <see cref="IVxEvent::situationType">type</see> of event that will activate this trigger, if any.
        /// </summary>
        char eventSituationType[128];
        /// <summary>
        /// The unique identifier of the schedule trigger.
        /// </summary>
        char id[64];
        /// <summary>
        /// The unique identifier of the associated time table, if any.
        /// </summary>
        char timeTableId[64];
        /// <summary>
        /// The size of <see cref="eventProperties"/>.
        /// </summary>
        int eventPropertySize;
        /// <summary>
        /// Amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes
        /// inactive (post-alarm).
        /// </summary>
        int postTrigger;
        /// <summary>
        /// Amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes
        /// active (pre-alarm).
        /// </summary>
        int preTrigger;
        /// <summary>
        /// Amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes
        /// active (duration).
        /// </summary>
        int timeout;
        /// <summary>
        /// If set, the event only activates when it occurs with these <see cref="IVxEvent::properties"/>. Ignored if
        /// no event is set.
        /// </summary>
        VxKvObject** eventProperties;
        /// <summary>
        /// The framerate level to record at.
        /// </summary>
        VxRecordingFramerate::Value framerate;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->eventSituationType);
            VxZeroArray(this->id);
            VxZeroArray(this->timeTableId);
            this->eventPropertySize = 0;
            this->postTrigger = 0;
            this->preTrigger = 0;
            this->timeout = 0;
            this->eventProperties = nullptr;
            this->framerate = VxRecordingFramerate::kUnknown;
        }
    };
}

#endif // IVxScheduleTrigger_h__
