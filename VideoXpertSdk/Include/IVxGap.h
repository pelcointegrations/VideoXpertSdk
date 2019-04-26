#ifndef IVxGap_h__
#define IVxGap_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"
#include "IVxBookmarkLock.h"

namespace VxSdk {
    /// <summary>
    /// Represents a span of time that a clip should exist for a particular data source on a particular data storage
    /// but for some reason the clip does not exist. Not all instances of gaps may be detectable by the system and thus
    ///  may not be reported.
    /// </summary>
    struct IVxGap {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the data source associated with this gap.
        /// </summary>
        /// <param name="dataSource">The associated data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Gets the data storage with the gap.
        /// </summary>
        /// <param name="dataStorage">The data storage with the gap.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorage(IVxDataStorage*& dataStorage) const = 0;

    public:
        /// <summary>
        /// The unique identifier of the gapped data source.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The unique identifier of the data storage with the gap.
        /// </summary>
        char dataStorageId[64];
        /// <summary>
        /// The end time of the gap.
        /// </summary>
        char endTime[64];
        /// <summary>
        /// The start time of the gap.
        /// </summary>
        char startTime[64];
        /// <summary>
        /// The size of <see cref="reasonData"/>.
        /// </summary>
        int reasonDataSize;
        /// <summary>
        /// The reason for this gap.
        /// </summary>
        VxGapReason::Value reason;
        /// <summary>
        /// Optional additional reason data.
        /// </summary>
        VxKvObject** reasonData;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->dataStorageId);
            VxZeroArray(this->endTime);
            VxZeroArray(this->startTime);
            this->reasonDataSize = 0;
            this->reason = VxGapReason::kUnknown;
            this->reasonData = nullptr;
        }
    };
}
#endif // IVxGap_h__
