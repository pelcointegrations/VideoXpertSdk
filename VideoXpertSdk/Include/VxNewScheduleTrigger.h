#ifndef VxNewScheduleTrigger_h__
#define VxNewScheduleTrigger_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxKvObject.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new schedule trigger to be created. A schedule trigger is a time range and an optional event that
    /// together act as a trigger to activate a schedule. The schedule trigger is considered active when all of its time
    /// and event attributes indicate it should be active. An active schedule trigger will perform its configured action.
    /// </summary>
    struct VxNewScheduleTrigger {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewScheduleTrigger"/> struct.
        /// </summary>
        VxNewScheduleTrigger() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewScheduleTrigger"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewScheduleTrigger(const VxNewScheduleTrigger& ref) {
            Utilities::StrCopySafe(this->eventSituationType, ref.eventSituationType);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->inactiveEventSituationType, ref.inactiveEventSituationType);
            Utilities::StrCopySafe(this->timeTableId, ref.timeTableId);
            this->postTrigger = ref.postTrigger;
            this->preTrigger = ref.preTrigger;
            this->timeout = ref.timeout;
            this->framerate = ref.framerate;
            this->action = ref.action;
            this->eventPropertySize = ref.eventPropertySize;
            this->eventProperties = nullptr;
            if (ref.eventProperties != nullptr) {
                this->eventProperties = new VxKvObject[ref.eventPropertySize];
                for(int i = 0; i < ref.eventPropertySize; i++)
                    this->eventProperties[i] = VxKvObject(ref.eventProperties[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewScheduleTrigger"/> class.
        /// </summary>
        ~VxNewScheduleTrigger() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->eventSituationType);
            VxZeroArray(this->id);
            VxZeroArray(this->inactiveEventSituationType);
            VxZeroArray(this->timeTableId);
            this->eventPropertySize = 0;
            this->postTrigger = 0;
            this->preTrigger = 0;
            this->timeout = 0;
            this->eventProperties = nullptr;
            this->framerate = VxRecordingFramerate::kUnknown;
            this->action = VxScheduleAction::kUnknown;
        }

    public:
        /// <summary>
        /// The <c>IVxEvent::situationType</c> that will activate the schedule trigger. If set, the
        /// schedule trigger is considered an "event" trigger, otherwise it is considered a "timed" trigger. If set,
        /// the schedule trigger only activates when this type of event occurs.
        /// See <see cref="inactiveEventSituationType"/> for information on when the trigger will deactivate.
        /// </summary>
        char eventSituationType[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The unique identifier of the schedule trigger. If not supplied, the system will create the identifier.
        /// </summary>
        char id[64];
        /// <summary>
        /// The <c>IVxEvent::situationType</c> of event that will cause this schedule trigger to no
        /// longer be considered active. If set, the schedule trigger event state will no longer be considered active.
        /// If not set, the schedule trigger event status will immediately be considered inactive after event occurs.
        /// NOTE: This field is ignored if <see cref="eventSituationType"/> is not set.
        /// </summary>
        char inactiveEventSituationType[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The unique identifier of a time table. If set, the schedule trigger will only be active during the time
        /// range(s) defined by this time table.
        /// </summary>
        char timeTableId[64];
        /// <summary>
        /// The size of <see cref="eventProperties"/>.
        /// </summary>
        int eventPropertySize;
        /// <summary>
        /// Amount of time, from 0 to 300 seconds, to continue to consider the schedule trigger active when it becomes
        /// inactive ("post alarm"). Defaults to 0.
        /// </summary>
        int postTrigger;
        /// <summary>
        /// Amount of time, from 0 to 30 seconds, to consider the schedule trigger active prior to when it becomes
        /// active ("pre alarm"). Defaults to 0.
        /// </summary>
        int preTrigger;
        /// <summary>
        /// Amount of time, from 1 to 300 seconds, to consider the schedule trigger active immediately after it becomes
        /// active ("duration recording"). The schedule trigger will become inactive when this time has elapsed (though
        /// the <see cref="postTrigger"/> may continue to keep it active at this point). No timeout is applied if the
        /// value is less than 1. Defaults to 0.
        /// </summary>
        int timeout;
        /// <summary>
        /// If set, the event only activates when it occurs with these properties. Ignored if no
        /// <see cref="eventSituationType"/> is set.
        /// </summary>
        VxKvObject* eventProperties;
        /// <summary>
        /// The framerate level to record at. Defaults to <see cref="VxRecordingFramerate::kNormal"/>.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// The action performed when the schedule trigger actives.
        /// </summary>
        VxScheduleAction::Value action;
    };
}

#endif // VxNewScheduleTrigger_h__
