#ifndef IVxRecording_h__
#define IVxRecording_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"

namespace VxSdk {
    /// <summary>
    /// Represents an instance of an active recording (the action, not the recorded clip). Each recording will
    /// cause its specified data source to be recorded by all data storages that the data source is assigned to.
    /// </summary>
    struct IVxRecording {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this  recording from the VideoXpert system. If all recordings are deleted for a data
        /// source,  recording will be stopped for that data source.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the recording.</returns>
        virtual VxResult::Value DeleteRecording() const = 0;
        /// <summary>
        /// Gets the data source that will be recorded.
        /// </summary>
        /// <param name="dataSource">The data source that will be recorded.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;

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
        /// If specified, only events from the specified source will end the recording.
        /// </summary>
        char endEventSourceId[64];
        /// <summary>
        /// The unique identifier of the recording.
        /// </summary>
        char id[64];
        /// <summary>
        /// Friendly name of the recording which can be used to identify recordings to stop.
        /// </summary>
        char name[128];
        /// <summary>
        /// The name of the user that created this recording.
        /// </summary>
        char owner[64];
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
        /// The type of this recording which will show up in the corresponding clips.
        /// </summary>
        VxRecordingType::Value recordType;
        /// <summary>
        /// If specified, the resource type of <see cref="endEventSourceId"/>.
        /// </summary>
        VxResourceType::Value endEventSourceType;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->endEvent);
            VxZeroArray(this->endEventSourceId);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            VxZeroArray(this->startTime);
            maxRecordingTime = 0;
            postRecord = 0;
            preRecord = 0;
            framerate = VxRecordingFramerate::kUnknown;
            recordType = VxRecordingType::kUnknown;
            endEventSourceType = VxResourceType::kUnknown;
        }
    };
}
#endif // IVxRecording_h__
