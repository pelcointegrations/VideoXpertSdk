#ifndef VxNewBookmark_h__
#define VxNewBookmark_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new bookmark to be created.
    /// </summary>
    struct VxNewBookmark {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewBookmark"/> struct.
        /// </summary>
        VxNewBookmark() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewBookmark"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewBookmark(const VxNewBookmark& ref) {
            isLocked = ref.isLocked;
            Utilities::StrCopySafe(this->dataSourceId, ref.dataSourceId);
            Utilities::StrCopySafe(this->description, ref.description);
            Utilities::StrCopySafe(this->groupId, ref.groupId);
            Utilities::StrCopySafe(this->lockEndTime, ref.lockEndTime);
            Utilities::StrCopySafe(this->lockStartTime, ref.lockStartTime);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->time, ref.time);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewBookmark"/> class.
        /// </summary>
        ~VxNewBookmark() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            isLocked = false;
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->description);
            VxZeroArray(this->groupId);
            VxZeroArray(this->lockEndTime);
            VxZeroArray(this->lockStartTime);
            VxZeroArray(this->name);
            VxZeroArray(this->time);
        }

    public:
        /// <summary>
        /// Indicates whether this bookmark will be locked, which will prevent the media it locks from being garbage
        /// collected on recorders.
        /// </summary>
        bool isLocked;
        /// <summary>
        /// The unique identifier of the data source to associate with the bookmark.
        /// </summary>
        char dataSourceId[64];
        /// <summary>
        /// The friendly description of the bookmark.
        /// </summary>
        char description[255];
        /// <summary>
        /// The unique identifier of the associated bookmark group. Typically used to identify related bookmarks (such
        /// as those bookmarking the same time on audio and video).
        /// </summary>
        char groupId[64];
        /// <summary>
        /// The end time of the media to lock.
        /// </summary>
        char lockEndTime[64];
        /// <summary>
        /// The start time of the media to lock.
        /// </summary>
        char lockStartTime[64];
        /// <summary>
        /// The friendly name of the bookmark.
        /// </summary>
        char name[64];
        /// <summary>
        /// The time at which the point of interest occurred.
        /// </summary>
        char time[64];
    };
}

#endif // VxNewBookmark_h__