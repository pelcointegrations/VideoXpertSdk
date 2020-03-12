#ifndef IVxDeviceAssignment_h__
#define IVxDeviceAssignment_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDriver.h"

namespace VxSdk {
    struct IVxDataStorage;

    /// <summary>
    /// Represents a device assignment on a data storage.
    /// </summary>
    struct IVxDeviceAssignment {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the data sources assigned by this device assignment.
        /// <para>
        /// Available filters: kAdvancedQuery, kAllTags, kCapturing, kCommissioned, kEnabled, kEncoding, kHasFolderTags,
        /// kId, kIp, kManualRecording, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.
        /// </para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the associated data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDataStorage"/> that this device assignment is for.
        /// </summary>
        /// <param name="dataStorage">The <see cref="IVxDataStorage"/> for this device assignment.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorage(IVxDataStorage*& dataStorage) const = 0;
        /// <summary>
        /// Gets the assigned <see cref="IVxDevice"/>.
        /// </summary>
        /// <param name="device">The assigned <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDevice(IVxDevice*& device) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the unique identifier of the volume group to use for this device. If not provided, a volume group will
        /// be selected automatically.
        /// </summary>
        /// <param name="volumeGroupId">The unique identifier.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetVolumeGroupId(char volumeGroupId[64]) = 0;

    public:
        /// <summary>
        /// The unique identifier of the device assignment.
        /// </summary>
        char id[64];

        /// <summary>
        /// The unique identifier of the volume group to use for this device.
        /// </summary>
        char volumeGroupId[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->volumeGroupId);
        }
    };
}

#endif // IVxDeviceAssignment_h__
