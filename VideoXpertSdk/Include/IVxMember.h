#ifndef IVxMember_h__
#define IVxMember_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a member system.
    /// </summary>
    struct IVxMember {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
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
        /// Removes the member system; it will no longer be aggregated.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of removing the member system.</returns>
        virtual VxResult::Value RemoveMember() const = 0;
        /// <summary>
        /// Sets the bandwidth property.
        /// </summary>
        /// <param name="bandwidth">The new bandwidth value in kbps.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBandwidth(int bandwidth) = 0;
        /// <summary>
        /// Sets the host property.
        /// </summary>
        /// <param name="host">The new host value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetHost(char host[256]) = 0;
        /// <summary>
        /// Sets the administrator account password used to communicate with this member.
        /// </summary>
        /// <param name="password">The account password.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the password.</returns>
        virtual VxResult::Value SetPassword(char password[64]) = 0;
        /// <summary>
        /// Sets the hostPort property.
        /// </summary>
        /// <param name="hostPort">The new hostPort value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetHostPort(int hostPort) = 0;
        /// <summary>
        /// Sets the rtspCapability property.
        /// </summary>
        /// <param name="rtspCapability">The new rtspCapability value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetRtspCapability(VxRtspCapability::Value rtspCapability) = 0;
        /// <summary>
        /// Sets the administrator account username used to communicate with this member.
        /// </summary>
        /// <param name="username">The account username.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the username.</returns>
        virtual VxResult::Value SetUsername(char username[64]) = 0;
        /// <summary>
        /// Triggers a refresh of this member system; ensures that the aggregating system is in sync with the
        /// member system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing the member system.</returns>
        virtual VxResult::Value TriggerRefresh() = 0;

    public:
        /// <summary>
        /// The host address.
        /// </summary>
        char host[256];
        /// <summary>
        /// The unique system identifier of the member system.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name for the member system. This value comes from the <c>IVxSystem</c> name field,
        /// containing the system’s friendly name. This is not an alias for the system.
        /// </summary>
        char name[64];
        /// <summary>
        /// The administrator account username used to communicate with this member.
        /// </summary>
        char username[64];
        /// <summary>
        /// Bandwidth available between the aggregator system and the member system (in kbps).
        /// </summary>
        int bandwidth;
        /// <summary>
        /// The host port.
        /// </summary>
        int hostPort;
        /// <summary>
        /// The current operational state.
        /// </summary>
        VxMemberState::Value state;
        /// <summary>
        /// The network streaming capabilities that this member shall expose to its clients (via data interfaces).
        /// </summary>
        VxRtspCapability::Value rtspCapability;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->host);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->username);
            this->bandwidth = 0;
            this->hostPort = 0;
            this->state = VxMemberState::kUnknown;
            this->rtspCapability = VxRtspCapability::kUnknown;
        }
    };
}
#endif // IVxMember_h__
