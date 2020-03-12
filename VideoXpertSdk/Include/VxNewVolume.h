#ifndef VxNewVolume_h__
#define VxNewVolume_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new volume to be created.
    /// </summary>
    struct VxNewVolume {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewVolume"/> struct.
        /// </summary>
        VxNewVolume() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewVolume"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewVolume(const VxNewVolume& ref) {
            this->isBandwidthReserved = ref.isBandwidthReserved;
            Utilities::StrCopySafe(this->domain, ref.domain);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->path, ref.path);
            Utilities::StrCopySafe(this->username, ref.username);
            this->buffer = ref.buffer;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewVolume"/> class.
        /// </summary>
        ~VxNewVolume() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isBandwidthReserved = false;
            VxZeroArray(this->domain);
            VxZeroArray(this->password);
            VxZeroArray(this->path);
            VxZeroArray(this->username);
            this->buffer = 0;
        }

    public:
        /// <summary>
        /// Indicates whether or not this is a NAS volume that shares bandwidth with data streams (bandwidth will be
        /// reserved for NAS operations).
        /// </summary>
        bool isBandwidthReserved;
        /// <summary>
        /// The domain for the volume network path. Note: Ignored if the <see cref="path"/> is not a UNC path.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The password for access to the network path. Note: Ignored if the <see cref="path"/> is not a UNC path.
        /// </summary>
        char password[64];
        /// <summary>
        /// The fully qualified Windows directory path.
        /// </summary>
        char path[512];
        /// <summary>
        /// The username for access to the network path. Note: Ignored if the <see cref="path"/> is not a UNC path.
        /// </summary>
        char username[64];
        /// <summary>
        /// The percentage of the volume to keep free.
        /// </summary>
        float buffer;
    };
}

#endif // VxNewVolume_h__