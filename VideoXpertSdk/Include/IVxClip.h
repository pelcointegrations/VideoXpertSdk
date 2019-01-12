#ifndef IVxClip_h__
#define IVxClip_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxSnapshotFilter.h"
#include "IVxConfiguration.h"
#include "IVxDataInterface.h"

namespace VxSdk {
    /// <summary>
    /// Represents a contiguous duration of stored media originating from a single data source.
    /// </summary>
    struct IVxClip {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the endpoint URI for snapshots.
        /// </summary>
        /// <param name="filter">The filter(s) to use to generate the snapshot endpoint.</param>
        /// <param name="filterSize">The size of <paramref name="filter"/>.</param>
        /// <param name="endpoint">The snapshots endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSnapshotEndpoint(VxSnapshotFilter* filter, int filterSize, char* endpoint, int& size) const = 0;

    public:
        /// <summary>
        /// The unique identifier of the clips data source.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The friendly name of the clips data source.
        /// </summary>
        char dataSourceName[64];
        /// <summary>
        /// The unique identifier of the data storage on which the media for this clip is stored.
        /// </summary>
        char dataStorageId[64];
        /// <summary>
        /// The end time of the clip.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The unique identifier of the data storage on which the media for this clip was originally stored. If
        /// different than dataStorageId, indicates that this clip was copied to the data storage from another data
        /// storage.
        /// </summary>
        char sourceDataStorageId[64];
        /// <summary>
        /// The start time of the clip.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The type of media contained in the clip.
        /// </summary>
        char type[64];
        /// <summary>
        /// The size of <see cref="dataInterfaces"/>.
        /// </summary>
        int dataInterfaceSize;
        /// <summary>
        /// The data interfaces available for retrieval of the stored media this clip represents.
        /// </summary>
        IVxDataInterface** dataInterfaces;
        /// <summary>
        /// The framerate of the clip.
        /// </summary>
        VxRecordingFramerate::Value framerate;
        /// <summary>
        /// The event type that triggered the recording of the clip.
        /// </summary>
        VxRecordingType::Value recordingType;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->dataSourceName);
            VxZeroArray(this->dataStorageId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->sourceDataStorageId);
            VxZeroArray(this->startTime);
            VxZeroArray(this->type);
            this->dataInterfaceSize = 0;
            this->dataInterfaces = nullptr;
            this->framerate = VxRecordingFramerate::kUnknown;
            this->recordingType = VxRecordingType::kUnknown;
        }
    };
}

#endif // IVxClip_h__
