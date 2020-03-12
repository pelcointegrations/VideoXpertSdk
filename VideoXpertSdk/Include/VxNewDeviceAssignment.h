#ifndef VxNewDeviceAssignment_h__
#define VxNewDeviceAssignment_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new device assignment to be created.
    /// </summary>
    struct VxNewDeviceAssignment {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDeviceAssignment"/> struct.
        /// </summary>
        VxNewDeviceAssignment() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewDeviceAssignment"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewDeviceAssignment(const VxNewDeviceAssignment& ref) {
            Utilities::StrCopySafe(this->deviceId, ref.deviceId);
            Utilities::StrCopySafe(this->volumeGroupId, ref.volumeGroupId);
            this->dataSourceIdSize = ref.dataSourceIdSize;
            this->dataSourceIds = nullptr;
            if (ref.dataSourceIds != nullptr) {
                this->dataSourceIds = new char*[ref.dataSourceIdSize];
                for (int i = 0; i < ref.dataSourceIdSize; i++) {
                    const size_t len = strlen(ref.dataSourceIds[i]) + 1;
                    this->dataSourceIds[i] = new char[len];
                    Utilities::StrCopySafe(this->dataSourceIds[i], ref.dataSourceIds[i], len);
                }
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewDeviceAssignment"/> class.
        /// </summary>
        ~VxNewDeviceAssignment() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->deviceId);
            VxZeroArray(this->volumeGroupId);
            this->dataSourceIdSize = 0;
            this->dataSourceIds = nullptr;
        }

    public:
        /// <summary>
        /// The unique identifier of the device to assign.
        /// </summary>
        char deviceId[64];
        /// <summary>
        /// The unique identifier of the volume group to use for this device. If not provided, a volume group will be
        /// selected automatically.
        /// </summary>
        char volumeGroupId[64];
        /// <summary>
        /// The data sources to assign.
        /// </summary>
        char** dataSourceIds;
        /// <summary>
        /// The size of <see cref="dataSourceIds"/>.
        /// </summary>
        int dataSourceIdSize;
    };
}

#endif // VxNewDeviceAssignment_h__