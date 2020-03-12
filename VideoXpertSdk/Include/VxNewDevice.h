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
            Utilities::StrCopySafe(this->host, ref.host);
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
            this->endpointsSize = ref.endpointsSize;
            this->endpoints = nullptr;
            if (ref.endpoints != nullptr) {
                this->endpoints = new char*[ref.endpointsSize];
                for (int i = 0; i < ref.endpointsSize; i++) {
                    const size_t len = strlen(ref.endpoints[i]) + 1;
                    this->endpoints[i] = new char[len];
                    Utilities::StrCopySafe(this->endpoints[i], ref.endpoints[i], len);
                }
            }
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
            VxZeroArray(this->host);
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
            this->endpointsSize = 0;
            this->endpoints = nullptr;
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
        /// Host address of the device. If set, takes precedence over the ip. The combination of host, port and
        /// type must be unique, otherwise <see cref="VxResult::kConflict"/> will be returned.
        /// <para> NOTE: One of either host or ip must be provided. </para>
        /// </summary>
        char host[256];
        /// <summary>
        /// The id of this device
        /// </summary>
        char id[64];
        /// <summary>
        /// The primary IP address of the device. Ignored if host is also provided. The combination of ip, port and
        /// type must be unique, otherwise <see cref="VxResult::kConflict"/> will be returned.
        /// <remarks>DEPRECATED. Use host instead.</remarks>
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
        /// The host port, if non-default. The combination of host, ip, port and type must be unique, otherwise
        /// <see cref="VxResult::kConflict"/> will be returned.
        /// </summary>
        int port;
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
        /// List of source URIs that the device will support. If the device type is <see cref="VxDeviceType::kGeneric"/>
        /// then at least 1 URI must be provided. The URI must be unique, otherwise <see cref="VxResult::kConflict"/>
        /// will be returned.
        /// </summary>
        char** endpoints;
        /// <summary>
        /// The size of <see cref="endpoints"/>.
        /// </summary>
        int endpointsSize;
        /// <summary>
        /// The particular type of the device.
        /// </summary>
        VxDeviceType::Value type;
    };
}

#endif // VxNewDevice_h__
