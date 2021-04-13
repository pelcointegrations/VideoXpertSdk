#ifndef VxDeviceSearch_h__
#define VxDeviceSearch_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents device search helpers used for discovery.
    /// </summary>
    struct VxDeviceSearch {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxDeviceSearch"/> struct.
        /// </summary>
        VxDeviceSearch() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxDeviceSearch"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxDeviceSearch(const VxDeviceSearch& ref) {
            this->port = ref.port;
            Utilities::StrCopySafe(this->driverType, ref.driverType);
            Utilities::StrCopySafe(this->host, ref.host);
            Utilities::StrCopySafe(this->ipEndAddress, ref.ipEndAddress);
            Utilities::StrCopySafe(this->ipStartAddress, ref.ipStartAddress);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->username, ref.username);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxDeviceSearch"/> class.
        /// </summary>
        ~VxDeviceSearch() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->port = 0;
            VxZeroArray(this->driverType);
            VxZeroArray(this->host);
            VxZeroArray(this->ipEndAddress);
            VxZeroArray(this->ipStartAddress);
            VxZeroArray(this->password);
            VxZeroArray(this->username);
        }

    public:
        /// <summary>
        /// The type identifier of the driver to use for device communication.
        /// </summary>
        char driverType[MAX_UUID_LENGTH];
        /// <summary>
        /// The host address of the device. Ignored if <see cref="ipStartAddress"/> and <see cref="ipEndAddress"/> are present.
        /// </summary>
        char host[256];
        /// <summary>
        /// The IP ending address (inclusive). If present, this must be the same format as <see cref="ipStartAddress"/>
        /// and must be present if <see cref="ipStartAddress"/> is present. Address range from <see cref="ipStartAddress"/>
        /// must not exceed 1024 addresses.
        /// </summary>
        char ipEndAddress[64];
        /// <summary>
        /// The IP starting address (inclusive). If present, this must be the same format as <see cref="ipEndAddress"/>
        /// and must be present if <see cref="ipEndAddress"/> is present.
        /// </summary>
        char ipStartAddress[64];
        /// <summary>
        /// The account password to communicate with the device(s), if any.
        /// </summary>
        char password[64];
        /// <summary>
        /// The account username to communicate with the device(s), if any.
        /// </summary>
        char username[64];
        /// <summary>
        /// The device(s) port.
        /// </summary>
        int port;
    };
}

#endif // VxDeviceSearch_h__