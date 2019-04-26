#ifndef IVxBookmark_h__
#define IVxBookmark_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"
#include "IVxBookmarkLock.h"

namespace VxSdk {
    /// <summary>
    /// Represents a point in time of interest with reference to a particular data source.
    /// </summary>
    struct IVxBookmark {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this bookmark from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the bookmark.</returns>
        virtual VxResult::Value DeleteBookmark() const = 0;
        /// <summary>
        /// Gets the data source associated with this bookmark.
        /// </summary>
        /// <param name="dataSource">The associated data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Gets the lock configuration for this bookmark.
        /// </summary>
        /// <param name="bookmarkLock">The lock configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLock(IVxBookmarkLock*& bookmarkLock) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the description property.
        /// </summary>
        /// <param name="description">The new description value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDescription(char description[255]) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;

    public:
        /// <summary>
        /// The unique identifier of the associated data source.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The friendly description of the bookmark.
        /// </summary>
        char description[255];
        /// <summary>
        /// The unique identifier of the associated bookmark group (if any).
        /// </summary>
        char groupId[64];
        /// <summary>
        /// The unique identifier of the bookmark.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the bookmark.
        /// </summary>
        char name[64];
        /// <summary>
        /// The time at which the point of interest occurred.
        /// </summary>
        char time[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->description);
            VxZeroArray(this->groupId);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->time);
        }
    };
}
#endif // IVxBookmark_h__
