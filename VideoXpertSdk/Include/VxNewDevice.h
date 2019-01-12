#ifndef VxNewDevice_h__
#define VxNewDevice_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new device to be created.
    /// </summary>
    struct VxNewDevice {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDevice"/> struct.
        /// </summary>
        VxNewDevice() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDevice"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDevice(const VxNewDevice& ref) {
            this->shouldAutoCommission = ref.shouldAutoCommission;
            Utilities::StrCopySafe(this->driverType, ref.driverType);
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->ip, ref.ip);
            Utilities::StrCopySafe(this->model, ref.model);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->serial, ref.serial);
            Utilities::StrCopySafe(this->username, ref.username);
            Utilities::StrCopySafe(this->vendor, ref.vendor);
            Utilities::StrCopySafe(this->version, ref.version);
            this->port = ref.port;
            this->type = ref.type;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDevice"/> class.
        /// </summary>
        ~VxNewDevice() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            shouldAutoCommission = false;
            VxZeroArray(this->driverType);
            VxZeroArray(this->id);
            VxZeroArray(this->ip);
            VxZeroArray(this->model);
            VxZeroArray(this->name);
            VxZeroArray(this->password);
            VxZeroArray(this->serial);
            VxZeroArray(this->username);
            VxZeroArray(this->vendor);
            VxZeroArray(this->version);
            this->port = 0;
            type = VxDeviceType::kUnknown;
        }

    public:
        /// <summary>
        /// <c>true</c> to have this device automatically commissioned when created.
        /// </summary>
        bool shouldAutoCommission;
        /// <summary>
        /// The type identifier of the driver to use for the device when assigning it to a data storage.
        /// </summary>
        char driverType[64];
        /// <summary>
        /// The id of this device
        /// </summary>
        char id[64];
        /// <summary>
        /// The primary IP address. The IP address must be unique for this type of device.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The device model name, if any.
        /// </summary>
        char model[64];
        /// <summary>
        /// The friendly name of the device.
        /// </summary>
        char name[64];
        /// <summary>
        /// The account password used to communicate with the device, if any.
        /// </summary>
        char password[64];
        /// <summary>
        /// The serial number of the device, if any.
        /// </summary>
        char serial[64];
        /// <summary>
        /// The account username used to communicate with the device, if any.
        /// </summary>
        char username[64];
        /// <summary>
        /// The device vendor, if any.
        /// </summary>
        char vendor[64];
        /// <summary>
        /// The current version of software running on the device, if any.
        /// </summary>
        char version[64];
        /// <summary>
        /// The host port, if non-default.
        /// </summary>
        int port;
        /// <summary>
        /// The particular type of the device.
        /// </summary>
        VxDeviceType::Value type;
    };
}

#endif // VxNewDevice_h__
