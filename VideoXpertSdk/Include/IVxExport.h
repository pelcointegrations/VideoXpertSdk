#ifndef IVxExport_h__
#define IVxExport_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxExportClip.h"

namespace VxSdk {
    struct IVxExportStream;

    /// <summary>
    /// Represents an exported data set that is archived within the system.
    /// </summary>
    struct IVxExport {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this export from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the export.</returns>
        virtual VxResult::Value DeleteExport() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxExportStream"/> for this export.
        /// </summary>
        /// <param name="exportStream">The <see cref="IVxExportStream"/> for this export.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetExportStream(IVxExportStream*& exportStream) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxUser"/> that owns this export, if any.
        /// </summary>
        /// <param name="user">The <see cref="IVxUser"/> that owns this export.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetOwner(IVxUser*& user) const = 0;
        /// <summary>
        /// Gets the plain text password for this export if it's protected.
        /// <para>Note: Only available when logged in as the built-in admin user.</para>
        /// </summary>
        /// <param name="password">The plain text password for this export.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPassword(char password[64]) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Restores this export to a non-trashed state.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of restoring the export.</returns>
        virtual VxResult::Value RestoreExport() const = 0;
        /// <summary>
        /// Trashes this export. Trashed exports may be removed by the server if additional space is needed.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of trashing the export.</returns>
        virtual VxResult::Value TrashExport() const = 0;

    public:
        /// <summary>
        /// Indicates whether the export data is signed and encrypted.
        /// </summary>
        bool isProtected;
        /// <summary>
        /// Indicates whether this export has been trashed.
        /// </summary>
        bool isTrashed;
        /// <summary>
        /// The date and time at which the triggered export completed the export operation.
        /// </summary>
        char completedTime[64];
        /// <summary>
        /// The URI to the exported data. It will only be present if the exported data is completed and available for
        /// download.
        /// </summary>
        char dataUri[512];
        /// <summary>
        /// The storage path that the export data is saved to. May be empty if the servers default storage location is
        /// being used.
        /// </summary>
        char exportPath[512];
        /// <summary>
        /// The unique identifier of the export.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which the export was requested.
        /// </summary>
        char initiatedTime[64];
        /// <summary>
        /// The friendly name of the export.
        /// </summary>
        char name[64];
        /// <summary>
        /// The name of the user that has created this export, if any.
        /// </summary>
        char owner[64];
        /// <summary>
        /// The percent complete value from 0 to 100. This specifies how close the export is to completion. 0 indicates
        /// that the export has not been triggered; 100 indicates that the export is complete.
        /// </summary>
        float percentComplete;
        /// <summary>
        /// The size of <see cref="exportClips"/>.
        /// </summary>
        int exportClipSize;
        /// <summary>
        /// The file size of the exported data in kilobytes (kB).
        /// </summary>
        int fileSizeKb;
        /// <summary>
        /// The estimated time remaining, in seconds, until the export is 100 percent complete.
        /// </summary>
        int secondsRemaining;
        /// <summary>
        /// The clips associated with this export.
        /// </summary>
        IVxExportClip** exportClips;
        /// <summary>
        /// The format of the export data.
        /// </summary>
        VxExportFormat::Value format;
        /// <summary>
        /// The current status of the export.
        /// </summary>
        VxExportStatus::Value status;
        /// <summary>
        /// Optional reason for the current status of this Export; typically used to express the reason for a failure.
        /// </summary>
        VxExportStatusReason::Value statusReason;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isProtected = false;
            this->isTrashed = false;
            VxZeroArray(this->completedTime);
            VxZeroArray(this->dataUri);
            VxZeroArray(this->exportPath);
            VxZeroArray(this->id);
            VxZeroArray(this->initiatedTime);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            this->exportClipSize = 0;
            this->percentComplete = 0;
            this->fileSizeKb = 0;
            this->secondsRemaining = 0;
            this->exportClips = nullptr;
            this->format = VxExportFormat::kUnknown;
            this->status = VxExportStatus::kUnknown;
            this->statusReason = VxExportStatusReason::kUnknown;
        }
    };
}
#endif // IVxExport_h__
