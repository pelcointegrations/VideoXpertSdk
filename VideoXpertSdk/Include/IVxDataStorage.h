#ifndef IVxDataStorage_h__
#define IVxDataStorage_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxNewDeviceAssignment.h"
#include "IVxDevice.h"
#include "IVxDeviceAssignment.h"
#include "IVxDriver.h"
#include "VxRetention.h"

namespace VxSdk {
    struct VxNewClip;

    /// <summary>
    /// Represents a data storage provider in the system (e.g. NSM5200 storage pool or VideoXpert Storage) hosted by a
    /// system device. The data storage can be directed to store media produced by a device by assigning the device to
    /// it.
    /// </summary>
    struct IVxDataStorage {
    public:
        /// <summary>
        /// Save the data specified in the new clip to this data storage. Once saved, the data will be represented as a
        /// new clip (not immediately available). Data that is already saved will not be retrieved again. If there is
        /// overlap with data that is already saved, only the new data will be saved.
        /// </summary>
        /// <param name="newClip">The new clip to add to the data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddClip(VxNewClip& newClip) const = 0;
        /// <summary>
        /// Assign a device to this data storage to be managed and recorded based on its configuration.
        /// </summary>
        /// <param name="newDeviceAssignment">The device assignment to add to the data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AssignDevice(VxNewDeviceAssignment& newDeviceAssignment) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the data sources assigned to this data storage.
        /// <para>
        /// Available filters: kAdvancedQuery, kAllTags, kCapturing, kCommissioned, kEnabled, kEncoding, kHasFolderTags,
        /// kId, kIp, kManualRecording, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.
        /// </para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the assigned data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices assigned to this data storage.
        /// <para>Available filters: kDataSourceId, kDataStorageId, kDeviceId, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceAssignmentCollection">A <see cref="VxCollection"/> of the assigned devices.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDeviceAssignments(VxCollection<IVxDeviceAssignment**>& deviceAssignmentCollection) const = 0;
        /// <summary>
        /// Gets the host device of this data storage.
        /// </summary>
        /// <param name="hostDevice">The host device of this data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the resource retention information for this data storage.
        /// <para>Available filters: kId, kResourceId.</para>
        /// </summary>
        /// <param name="retentionCollection">A <see cref="VxCollection"/> of retention information.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRetentions(VxCollection<VxRetention**>& retentionCollection) const = 0;
        /// <summary>
        /// Gets the storage configuration.
        /// </summary>
        /// <param name="storageConfig">The storage configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetStorageConfiguration(IVxConfiguration::Storage*& storageConfig) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Unassign a device from this data storage.
        /// </summary>
        /// <param name="device">The device to remove from the data storage.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnassignDevice(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// Indicates whether the data storage is configured as a failover unit.
        /// </summary>
        bool isFailover;
        /// <summary>
        /// The unique identifier of the data storage.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the data storage.
        /// </summary>
        char name[64];
        /// <summary>
        /// The data storage type.
        /// </summary>
        VxDataStorageType::Value type;

    public:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isFailover = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->type = VxDataStorageType::kUnknown;
        }
    };
}

#endif // IVxDataStorage_h__