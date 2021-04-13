#ifndef IVxManualRecording_h__
#define IVxManualRecording_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"

namespace VxSdk {
    /// <summary>
    /// DEPRECATED: Replaced by IVxRecording.
    /// <para>
    /// Represents an instance of an active manual recording (the action, not the recorded clip). Each manual recording
    /// will cause its specified data source to be manually recorded by all data storages that the data source is
    /// assigned to. Only one manual recording per user per data source is allowed. A clip created via the application
    /// of a manual recording will have an event value of manual.
    /// </para>
    /// </summary>
    struct IVxManualRecording {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this manual recording from the VideoXpert system. If all manual recordings are deleted for a data
        /// source, manual recording will be stopped for that data source.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the manual recording.</returns>
        virtual VxResult::Value DeleteManualRecording() const = 0;
        /// <summary>
        /// Gets the data source that is being manually recorded.
        /// </summary>
        /// <param name="dataSource">The data source being manually recorded.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Resets the expiration timers in order to extend this recordings timeout.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of resetting the experation timers.</returns>
        virtual VxResult::Value ResetExpirationTimers() = 0;

    public:
        /// <summary>
        /// The unique identifier of the data source to manually record.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The unique identifier of the manual recording.
        /// </summary>
        char id[64];
        /// <summary>
        /// The name of the user that created this manual recording.
        /// </summary>
        char owner[64];
        /// <summary>
        /// The time at which this manual recording was created (not necessarily the exact time that the manual record
        /// clip starts).
        /// </summary>
        char time[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->id);
            VxZeroArray(this->owner);
            VxZeroArray(this->time);
        }
    };
}
#endif // IVxManualRecording_h__
