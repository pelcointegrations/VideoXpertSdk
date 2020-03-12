#ifndef IVxVolume_h__
#define IVxVolume_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxVolumeGroup;

    /// <summary>
    /// Represents a storage volume.
    /// </summary>
    struct IVxVolume {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this volume from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the volume.</returns>
        virtual VxResult::Value DeleteVolume() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxVolumeGroup"/> that this volume is in, if any.
        /// </summary>
        /// <param name="volumeGroup">The volume group if present, otherwise <c>nullptr</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetVolumeGroup(IVxVolumeGroup*& volumeGroup) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the buffer property.
        /// </summary>
        /// <param name="buffer">The new buffer percentage value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBuffer(float buffer) = 0;
        /// <summary>
        /// Sets the domain property.
        /// </summary>
        /// <param name="domain">The new domain value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDomain(char domain[64]) = 0;
        /// <summary>
        /// Sets the isBandwidthReserved property.
        /// </summary>
        /// <param name="isBandwidthReserved"><c>true</c> to share bandwidth with data streams, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIsBandwidthReserved(bool isBandwidthReserved) = 0;
        /// <summary>
        /// Sets the password used to access to the network path. Note: Ignored if the <see cref="path"/> is not a UNC path.
        /// </summary>
        /// <param name="password">The password value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPassword(char password[64]) = 0;
        /// <summary>
        /// Sets the path property.
        /// </summary>
        /// <param name="path">The new path value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPath(char path[512]) = 0;
        /// <summary>
        /// Sets the username property.
        /// </summary>
        /// <param name="username">The new username value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetUsername(char username[64]) = 0;

    public:
        /// <summary>
        /// Indicates whether or not this is a NAS volume that shares bandwidth with data streams (bandwidth will be
        /// reserved for NAS operations).
        /// </summary>
        bool isBandwidthReserved;
        /// <summary>
        /// Indicates whether or not the storage is online and available.
        /// </summary>
        bool isOnline;
        /// <summary>
        /// The domain for the volume network path. Note: Ignored if the <see cref="path"/> is not a UNC path.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The unique identifier of the volume.
        /// </summary>
        char id[64];
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
        /// <summary>
        /// The total amount of storage present (in MB).
        /// </summary>
        int total;
        /// <summary>
        /// The amount of storage in use (in MB).
        /// </summary>
        int used;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isBandwidthReserved = false;
            this->isOnline = false;
            VxZeroArray(this->domain);
            VxZeroArray(this->id);
            VxZeroArray(this->path);
            VxZeroArray(this->username);
            this->buffer = 0;
            this->total = 0;
            this->used = 0;
        }
    };
}
#endif // IVxVolume_h__
