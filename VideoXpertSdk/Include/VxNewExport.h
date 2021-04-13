#ifndef VxNewExport_h__
#define VxNewExport_h__

#include "VxNewExportClip.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new export to be created.
    /// </summary>
    struct VxNewExport {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExport"/> struct.
        /// </summary>
        VxNewExport() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewExport"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewExport(const VxNewExport& ref) {
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->password, ref.password);
            this->format = ref.format;
            this->alternateLocation = VxNetworkStorageInfo(ref.alternateLocation);
            this->clipSize = ref.clipSize;
            this->clips = nullptr;
            if (ref.clips != nullptr) {
                this->clips = new VxNewExportClip[ref.clipSize];
                for(int i = 0; i < ref.clipSize; i++)
                    this->clips[i] = VxNewExportClip(ref.clips[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewExport"/> class.
        /// </summary>
        ~VxNewExport() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->name);
            VxZeroArray(this->password);
            this->format = VxExportFormat::kUnknown;
            this->clipSize = 0;
            this->clips = nullptr;
            this->alternateLocation.Clear();
        }

    public:
        /// <summary>
        /// The friendly name of the export.
        /// </summary>
        char name[64];
        /// <summary>
        /// The password for the export. If set, the export data will be signed and encrypted. This password will be
        /// required to decrypt the export data. If not set, the export data will not be signed or encrypted.
        /// </summary>
        char password[64];
        /// <summary>
        /// The size of <see cref="clips"/>.
        /// </summary>
        int clipSize;
        /// <summary>
        /// The export format to use.
        /// </summary>
        VxExportFormat::Value format;
        /// <summary>
        /// If specified, the export will be saved to this alternate network location.
        /// </summary>
        VxNetworkStorageInfo alternateLocation;
        /// <summary>
        /// The clips that shall be included in this export when triggered.
        /// </summary>
        VxNewExportClip* clips;
    };
}

#endif // VxNewExport_h__