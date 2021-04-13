#ifndef IVxLicenseFeature_h__
#define IVxLicenseFeature_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDevice.h"

namespace VxSdk {
    /// <summary>
    /// Represents device functionality that is enabled with a valid license.
    /// </summary>
    struct IVxLicenseFeature {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this license feature from the VideoXpert system. Available only if this is a pending license feature. 
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the license feature.</returns>
        virtual VxResult::Value DeleteLicenseFeature() const = 0;
        /// <summary>
        /// Gets the URI to the download location of the capability request.
        /// </summary>
        /// <param name="endpoint">The capability request endpoint, if available.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetCapabilityRequest(char* endpoint, int& size) const = 0;
        /// <summary>
        /// Gets the devices that have been commissioned for this feature.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceCollection">
        /// A <see cref="VxCollection"/> of the devices that have been commissioned for this feature.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetCommissionedDevices(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Applies this license feature to a device; doing so will consume an available count from the feature.
        /// </summary>
        /// <param name="device">The device to apply this license feature to.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDevice& device) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Removes this license feature from the given device, releasing it for reuse (decrements the used count).
        /// </summary>
        /// <param name="device">The device to remove this license feature from.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// Indicates whether this is a "pending" feature, which does not enable any device functionality, or
        /// a normal feature that does.
        /// </summary>
        bool isPending;
        /// <summary>
        /// The activation identifier.
        /// </summary>
        char activationId[64];
        /// <summary>
        /// The date and time at which the feature will expire.
        /// </summary>
        char expiration[64];
        /// <summary>
        /// The unique identifier of the feature.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which the feature was installed on the host.
        /// </summary>
        char installation[64];
        /// <summary>
        /// The name of the feature.
        /// </summary>
        char name[64];
        /// <summary>
        /// The feature version.
        /// </summary>
        char version[64];
        /// <summary>
        /// The allowable commisions count.
        /// </summary>
        int count;
        /// <summary>
        /// The size of <see cref="licensableDevices"/>.
        /// </summary>
        int licensableDevicesSize;
        /// <summary>
        /// The amount of the allowable count that is currently used by commissions.
        /// </summary>
        int used;
        /// <summary>
        /// The supported device types that may be licensed for use with this feature.
        /// </summary>
        VxDeviceType::Value* licensableDevices;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isPending = false;
            VxZeroArray(this->activationId);
            VxZeroArray(this->expiration);
            VxZeroArray(this->id);
            VxZeroArray(this->installation);
            VxZeroArray(this->name);
            VxZeroArray(this->version);
            this->count = 0;
            this->licensableDevicesSize = 0;
            this->used = 0;
            this->licensableDevices = nullptr;
        }
    };
}
#endif // IVxLicenseFeature_h__
