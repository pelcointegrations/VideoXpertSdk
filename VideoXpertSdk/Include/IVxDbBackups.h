#ifndef IVxDbBackups_h__
#define IVxDbBackups_h__

#include "VxPrimitives.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a collection of database backups and provides database backup and control.
    /// </summary>
    struct IVxDbBackups {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the current collection of database backups.
        /// <para>Available filters: None.</para>
        /// </summary>
        /// <param name="dbBackupCollection">A <see cref="VxCollection"/> of the associated database backups.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDatabaseBackups(VxCollection<IVxDbBackup**>& dbBackupCollection) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Sets the number of days between automatic database backups.
        /// </summary>
        /// <param name="backupInterval">The backup interval; a value of 0 will disable automatic database backups.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBackupInterval(int backupInterval) = 0;
        /// <summary>
        /// Sets the UNC network path to use for alternate backup storage (instead of the server default location).
        /// </summary>
        /// <param name="backupPath">The new backup path value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the path.</returns>
        virtual VxResult::Value SetBackupPath(char backupPath[512]) = 0;
        /// <summary>
        /// Sets the backup path password. If set, this password will be used to access the network resource specified
        /// in the <see cref="backupPath"/>.
        /// </summary>
        /// <param name="backupPathPassword">The new backup path password value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the password.</returns>
        virtual VxResult::Value SetBackupPathPassword(char backupPathPassword[64]) = 0;
        /// <summary>
        /// Sets the backup path username. If set, this username will be used to access the network resource specified
        /// in the <see cref="backupPath"/>.
        /// </summary>
        /// <param name="backupPathUsername">The new backup path username value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the username.</returns>
        virtual VxResult::Value SetBackupPathUsername(char backupPathUsername[64]) = 0;
        /// <summary>
        /// Sets the time at which daily automatic database backups will begin.
        /// </summary>
        /// <param name="backupTime">The time to perform daily backups, from 00:00:00 to 23:59:59.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBackupTime(char backupTime[9]) = 0;
        /// <summary>
        /// Sets the maximum number of backups to keep in the backup directory before overwriting the oldest.
        /// </summary>
        /// <param name="maxBackupsToKeep">The maximum number of backups to keep.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMaxBackupsToKeep(int maxBackupsToKeep) = 0;
        /// <summary>
        /// Initiate a new unscheduled database backup.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of triggering a new database backup.</returns>
        virtual VxResult::Value TriggerBackup() = 0;
        /// <summary>
        /// Gets a value indicating whether a network storage path is available and valid as a backup storage.
        /// </summary>
        /// <param name="isValid"><c>true</c> if the path is valid, otherwise <c>false</c>.</param>
        /// <param name="backupPath">The UNC network storage path.</param>
        /// <param name="backupPathUsername">The username for access to the backup path, if any.</param>
        /// <param name="backupPathPassword">The password for access to the backup path, if any.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of validating the path.</returns>
        virtual VxResult::Value ValidateBackupPath(bool& isValid, const char* backupPath, const char* backupPathUsername, const char* backupPathPassword) = 0;

    public:
        /// <summary>
        /// The time at which daily automatic database backups will begin, from 00:00:00 to 23:59:59.
        /// </summary>
        char backupTime[9];
        /// <summary>
        /// The optional UNC network path to use for alternate backup storage (instead of the server default location).
        /// </summary>
        char backupPath[512];
        /// <summary>
        /// The username used to access the backup storage location path.
        /// </summary>
        char backupPathUsername[64];
        /// <summary>
        /// The number of days between automatic database backups.
        /// </summary>
        int backupInterval;
        /// <summary>
        /// The maximum number of backups to keep in the backup directory before overwriting the oldest.
        /// </summary>
        int maxBackupsToKeep;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->backupTime);
            VxZeroArray(this->backupPath);
            VxZeroArray(this->backupPathUsername);
            this->backupInterval = 0;
            this->maxBackupsToKeep = 0;
        }
    };
}

#endif // IVxDbBackups_h__
