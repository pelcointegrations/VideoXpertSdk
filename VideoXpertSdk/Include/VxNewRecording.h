#ifndef VxNewRecording_h__
#define VxNewRecording_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request for a new recording to be generated.
    /// </summary>
    struct VxNewRecording {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewRecording"/> struct.
        /// </summary>
        VxNewRecording() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewRecording"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewRecording(const VxNewRecording& ref) {
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->endEvent, ref.endEvent);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->startTime, ref.startTime);
            this->maxRecordingTime = ref.maxRecordingTime;
            this->postRecord = ref.postRecord;
            this->preRecord = ref.preRecord;
            this->framerate = ref.framerate;
            this->recordType = ref.recordType;
            this->endEventSource = ref.endEventSource;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewRecording"/> class.
        /// </summary>
        ~VxNewRecording() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->endEvent);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->startTime);
            this->maxRecordingTime = 60;
            this->postRecord = 0;
            this->preRecord = 0;
            this->framerate = VxRecordingFramerate::kUnknown;
            this->recordType = VxRecordingType::kUnknown;
            this->endEventSource.Clear();
        }

    public:
        /// <summary>
        /// The unique identifier of the data source to record.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// If specified, the recording will automatically end when a matching event occurs.
        /// </summary>
        char endEvent[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The unique identifier of the recording.
        /// </summary>
        char id[64];
        /// <summary>
        /// Friendly name of the recording which can be used to identify recordings to stop
        /// </summary>
        char name[128];
        /// <summary>
        /// Time at which the recording should begin (may be in the recent past). The recording
        /// preRecord and maxRecordingTime will reference to this time. Defaults to the time
        /// at which the server processes the request.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// Maximum amount of time, in seconds, to record before stopping.
        /// </summary>
        int maxRecordingTime;
        /// <summary>
        /// Amount of time, in seconds, to record after the recording would otherwise be stopped.
        /// </summary>
        int postRecord;
        /// <summary>
        /// Amount of time, in seconds, to record prior to the recording start time.
        /// </summary>
        int preRecord;
        /// <summary>
        /// The framerate to record at.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// The type of this recording which will show up in the corresponding clips
        /// </summary>
        VxRecordingType::Value recordType;
        /// <summary>
        /// If specified, only events from the specified source will end the recording.
        /// </summary>
        VxResourceRef endEventSource;
    };
}

#endif // VxNewRecording_h__