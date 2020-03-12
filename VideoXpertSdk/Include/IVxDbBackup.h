#ifndef IVxDbBackup_h__
#define IVxDbBackup_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a database backup.
    /// </summary>
    struct IVxDbBackup {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this backup. If the backup is in progress, it shall be halted first.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this backup.</returns>
        virtual VxResult::Value DeleteBackup() = 0;
        /// <summary>
        /// Halts the current backup operation that is in progress, if any.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of halting the backup operation.</returns>
        virtual VxResult::Value Halt() = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Restore this backup to the database.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of restoring this backup.</returns>
        virtual VxResult::Value Restore() = 0;

    public:
        /// <summary>
        /// The date and time at which this backup completed.
        /// </summary>
        char completed[64];
        /// <summary>
        /// The unique identifier of the database backup.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which this backup was initiated.
        /// </summary>
        char initiated[64];
        /// <summary>
        /// The current status of this backup.
        /// </summary>
        VxBackupStatus::Value status;
        /// <summary>
        /// The optional reason for the current status of this backup; typically used to express the reason
        /// for a failure.
        /// </summary>
        VxBackupStatusReason::Value statusReason;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->completed);
            VxZeroArray(this->id);
            VxZeroArray(this->initiated);
            this->status = VxBackupStatus::kUnknown;
            this->statusReason = VxBackupStatusReason::kUnknown;
        }
    };
}
#endif // IVxDbBackup_h__
