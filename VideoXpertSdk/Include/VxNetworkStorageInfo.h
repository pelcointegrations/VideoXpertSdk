#ifndef VxNetworkStorageInfo_h__
#define VxNetworkStorageInfo_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents information about a network storage resource.
    /// </summary>
    struct VxNetworkStorageInfo {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNetworkStorageInfo"/> struct.
        /// </summary>
        VxNetworkStorageInfo() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNetworkStorageInfo"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNetworkStorageInfo(const VxNetworkStorageInfo& ref) {
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->path, ref.path);
            Utilities::StrCopySafe(this->username, ref.username);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNetworkStorageInfo"/> class.
        /// </summary>
        ~VxNetworkStorageInfo() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->password);
            VxZeroArray(this->path);
            VxZeroArray(this->username);
        }

    public:
        /// <summary>
        /// The password for access to the resource.
        /// </summary>
        char password[1024];
        /// <summary>
        /// The UNC network path of the resource.
        /// </summary>
        char path[1024];
        /// <summary>
        /// The username for access to the resource.
        /// </summary>
        char username[1024];
    };
}

#endif //VxNetworkStorageInfo_h__