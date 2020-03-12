#ifndef IVxAccessPoint_h__
#define IVxAccessPoint_h__

#include "IVxResourceRel.h"
#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxDevice;

    /// <summary>
    /// Represents an access control service (e.g. a door control or badge reader), typically hosted by an access
    /// controller <see cref="IVxDevice"/>.
    /// </summary>
    struct IVxAccessPoint {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this access point.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets all possible resource relations for this access point (both linked and non-linked). Each linked
        /// resource shall be considered to be related to this access point.
        /// <para>Available filters: kAdvancedQuery, kAllTags, kAllPrivateTags, kLinked.</para>
        /// </summary>
        /// <param name="resourceRelCollection">A <see cref="VxCollection"/> of related resources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRelations(VxCollection<IVxResourceRel**>& resourceRelCollection) const = 0;
        /// <summary>
        /// Locks the access point for the given amount of time (in seconds).
        /// </summary>
        /// <param name="seconds">The lock time (in seconds). If 0, stay locked indefinitely.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this access point.</returns>
        virtual VxResult::Value Lock(int seconds) = 0;
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
        virtual VxResult::Value SetName(char name[128]) = 0;
        /// <summary>
        /// Sets the type property.
        /// </summary>
        /// <param name="type">The new type value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetType(VxAccessPointType::Value type) = 0;
        /// <summary>
        /// Unlocks the access point for the given amount of time (in seconds).
        /// </summary>
        /// <param name="seconds">The unlock time (in seconds). If 0, stay unlocked indefinitely.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this access point.</returns>
        virtual VxResult::Value Unlock(int seconds) = 0;

    public:
        /// <summary>
        /// The unique identifier of the access point.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the access point.
        /// </summary>
        char name[128];
        /// <summary>
        /// The size of <see cref="status"/>.
        /// </summary>
        int statusSize;
        /// <summary>
        /// The particular type of the access point.
        /// </summary>
        VxAccessPointType::Value type;
        /// <summary>
        /// A list of the current access point statuses.
        /// </summary>
        VxAccessStatus::Value* status;
        /// <summary>
        /// The current operational state of the access point.
        /// </summary>
        VxDeviceState::Value state;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            statusSize = 0;
            this->type = VxAccessPointType::kUnknown;
            this->status = nullptr;
            this->state = VxDeviceState::kUnknown;
        }
    };
}
#endif // IVxAccessPoint_h__
