#ifndef IVxConfiguration_h__
#define IVxConfiguration_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "VxNewVolume.h"
#include "IVxFileRecovery.h"
#include "IVxVolume.h"
#include "VxNewUser.h"
#include "VxNetworkStorageInfo.h"

namespace VxSdk {
    struct VxSmtpInfo;
    struct VxLdapValidationCredentials;
    struct VxLimits;
    struct VxNewVolumeGroup;
    struct IVxDevice;

    /// <summary>
    /// Represents the configuration of a device.
    /// </summary>
    struct IVxConfiguration {
        struct Node;
        struct Time;

        /// <summary>
        /// Represents authorization configuration.
        /// </summary>
        struct Auth {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables password expiration for all users.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling password expiration.</returns>
            virtual VxResult::Value DisablePasswordExpiration() = 0;
            /// <summary>
            /// Enables password expiration for all users.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling password expiration.</returns>
            virtual VxResult::Value EnablePasswordExpiration() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the password on the physical host device (for the current username). If successful, device password will be set to match.
            /// </summary>
            /// <param name="newPassword">New password being requested. Must contain more than 7 characters.</param>
            /// <param name="mustChangePassword">If <c>true</c>, the password will immediately be expired the first time it is used to login.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetPassword(char newPassword[1024], bool mustChangePassword) = 0;
            /// <summary>
            /// Sets the passwordExpiration property.
            /// </summary>
            /// <param name="passwordExpiration">The amount of time, in days.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetPasswordExpiration(int passwordExpiration) = 0;
            /// <summary>
            /// Sets the user on the physical host device (creating/replacing as necessary). If successful, device username will be set to match.
            /// </summary>
            /// <param name="user">The user to set on the device.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetUser(VxNewUser& user) = 0;

        public:
            /// <summary>
            /// Indicates whether or not password expiration is enabled for all users.
            /// </summary>
            bool isPasswordExpirationEnabled;
            /// <summary>
            /// The minimum length allowed for a new user password.
            /// </summary>
            int minPasswordLength;
            /// <summary>
            /// The amount of time, in days, at which a user password will expire (from when it was last set/changed).
            /// Ignored if <see cref="isPasswordExpirationEnabled"/> is <c>false</c>.
            /// </summary>
            int passwordExpiration;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isPasswordExpirationEnabled = false;
                this->minPasswordLength = 0;
                this->passwordExpiration = 0;
            }
        };

        /// <summary>
        /// Represents bookmark configuration.
        /// </summary>
        struct Bookmark {
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
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the autoUnlock property.
            /// </summary>
            /// <param name="autoUnlock">The new auto unlock time, in days, or 0 to disable.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetAutoUnlock(int autoUnlock) = 0;
            /// <summary>
            /// Sets the retentionLimit property.
            /// </summary>
            /// <param name="retentionLimit">The new retention limit, in days.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetRetentionLimit(int retentionLimit) = 0;
            /// <summary>
            /// Sets the retentionPolicy property.
            /// </summary>
            /// <param name="retentionPolicy">The new retention policy.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetRetentionPolicy(VxBookmarkRetentionPolicy::Value retentionPolicy) = 0;

        public:
            /// <summary>
            /// Automatically unlock any locked bookmark that has a <c>IVxBookmarkLock::endTime</c> older than this
            /// number of days. A value of 0 will disable automatic unlocking.
            /// </summary>
            int autoUnlock;
            /// <summary>
            /// The retention limit, in days, for bookmark; a value of 0 will disable the limit. Any bookmark
            /// that exceeds this limit will be deleted. Ignored if the <see cref="retentionPolicy"/> is not set
            /// to <c>kDeleteAfterLimit</c>.
            /// </summary>
            int retentionLimit;
            /// <summary>
            /// Specifies if and when an old bookmark is automatically removed from the system.
            /// </summary>
            VxBookmarkRetentionPolicy::Value retentionPolicy;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->autoUnlock = 0;
                this->retentionLimit = 0;
                this->retentionPolicy = VxBookmarkRetentionPolicy::kUnknown;
            }
        };

        /// <summary>
        /// Represents cluster configuration attributes. This representation shall be identical within a
        /// cluster, regardless of the node it was retrieved from.
        /// </summary>
        struct Cluster {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables the alternative export storage location.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling the storage location.</returns>
            virtual VxResult::Value DisableExportPath() = 0;
            /// <summary>
            /// Disables the stream proxy, so camera streams are always pulled directly from the Media Gateway.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling the stream proxy.</returns>
            virtual VxResult::Value DisableStreamProxy() = 0;
            /// <summary>
            /// Enables the alternative export storage location.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling the storage location.</returns>
            virtual VxResult::Value EnableExportPath() = 0;
            /// <summary>
            /// Enables the stream proxy, which will proxy camera streams through the VxStorage that they are assigned
            /// to (if applicable).
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling the stream proxy.</returns>
            virtual VxResult::Value EnableStreamProxy() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Gets the configuration for the nodes that the cluster is composed of.
            /// </summary>
            /// <param name="nodeCollection">A <see cref="VxCollection"/> of node configurations.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetNodeConfigurations(VxCollection<IVxConfiguration::Node**>& nodeCollection) const = 0;
            /// <summary>
            /// Gets the time configuration for the cluster.
            /// </summary>
            /// <param name="timeConfig">The time configuration.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetTimeConfig(IVxConfiguration::Time*& timeConfig) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the retention limit, in days, on logged events from aggregated sources. Any aggregated events that
            /// exceed this limit shall be deleted.
            /// </summary>
            /// <param name="aggregatedEventLimit">The new aggregated event limit.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the limit.</returns>
            virtual VxResult::Value SetAggregatedEventLimit(int aggregatedEventLimit) = 0;
            /// <summary>
            /// Sets the availabilityMode property.
            /// </summary>
            /// <param name="availabilityMode">The new availability mode value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetAvailabilityMode(VxClusterAvailabilityMode::Value availabilityMode) = 0;
            /// <summary>
            /// Sets the virtual IP or hostname to use for VxCore devices.
            /// </summary>
            /// <param name="coreVirtualIp">The new virtual ip/hostname value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetCoreVirtualIp(char coreVirtualIp[256]) = 0;
            /// <summary>
            /// Sets the virtual IP or hostname to use for device discovery (if the cluster is not governed by a
            /// VideoXpert Accessory Server). The load balancer uses this address for discovery announcements
            /// and balances responses across the cluster.
            /// </summary>
            /// <param name="discoveryVirtualIp">The new virtual ip/hostname value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetDiscoveryVirtualIp(char discoveryVirtualIp[256]) = 0;
            /// <summary>
            /// Sets the UNC network path to save export media to. If set (and <see cref="isExportPathEnabled"/> is
            /// <c>true></c>), this location will be used instead of local cluster storage. If not set, local cluster
            /// storage will be used for storage of export media.
            /// </summary>
            /// <param name="exportPath">The new export path value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the path.</returns>
            virtual VxResult::Value SetExportPath(char exportPath[512]) = 0;
            /// <summary>
            /// Sets the export path password. If set (and <see cref="isExportPathEnabled"/> is <c>true></c>), this
            /// password will be used to access the network resource specified in the <see cref="exportPath"/>.
            /// </summary>
            /// <param name="exportPathPassword">The new export path password value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the password.</returns>
            virtual VxResult::Value SetExportPathPassword(char exportPathPassword[64]) = 0;
            /// <summary>
            /// Sets the export path username. If set (and <see cref="isExportPathEnabled"/> is <c>true></c>), this
            /// username will be used to access the network resource specified in the <see cref="exportPath"/>.
            /// </summary>
            /// <param name="exportPathUsername">The new export path username value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the username.</returns>
            virtual VxResult::Value SetExportPathUsername(char exportPathUsername[64]) = 0;
            /// <summary>
            /// Sets the retention limit, in days, on logged events. Any events that exceed this limit shall be deleted.
            /// </summary>
            /// <param name="localEventLimit">The new local event limit.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the limit.</returns>
            virtual VxResult::Value SetLocalEventLimit(int localEventLimit) = 0;
            /// <summary>
            /// Sets the virtual IP or hostname to use for Media Gateway devices.
            /// </summary>
            /// <param name="mediaGatewayVirtualIp">The new virtual ip/hostname value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMediaGatewayVirtualIp(char mediaGatewayVirtualIp[256]) = 0;
            /// <summary>
            /// Sets the default communication method between data sources to Media Gateways and between Media Gateways
            /// to clients.
            /// </summary>
            /// <param name="transcastMethod">The new transcast method value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTranscastMethod(VxMgTranscast::Value transcastMethod) = 0;
            /// <summary>
            /// Validate a network storage path for availability as export storage.
            /// </summary>
            /// <param name="isValid"><c>true</c> if the path is valid, otherwise <c>false</c>.</param>
            /// <param name="exportStorageInfo">The export storage path to validate.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of validating the SMTP information.</returns>
            virtual VxResult::Value ValidateExportPath(bool& isValid, VxNetworkStorageInfo& exportStorageInfo) = 0;

        public:
            /// <summary>
            /// Indicates whether or not the alternative export storage location is enabled.
            /// </summary>
            bool isExportPathEnabled;
            /// <summary>
            /// Indicates whether camera streams will be proxied through the VxStorage that they are assigned to or
            /// will always be pulled directly from the Media Gateway.
            /// </summary>
            bool isStreamProxyEnabled;
            /// <summary>
            /// The virtual IP or hostname used for VideoXpert Core devices.
            /// </summary>
            char coreVirtualIp[256];
            /// <summary>
            /// The virtual IP or hostname used for device discovery if the cluster is not governed by a VideoXpert
            /// Accessory Server. The load balancer uses this address for discovery announcements and balances
            /// responses across the cluster.
            /// </summary>
            char discoveryVirtualIp[256];;
            /// <summary>
            /// The UNC network path to save export media to.
            /// </summary>
            char exportPath[512];
            /// <summary>
            /// The username used to access the network resource at the location specified by <see cref="exportPath"/>.
            /// </summary>
            char exportPathUsername[64];
            /// <summary>
            /// The default communication method between data sources to Media Gateways and
            /// between Media Gateways to clients.
            /// </summary>
            /// <remarks>
            /// DEPRECATED: This has been replaced by <see cref="transcastMethod"/> and will be removed in the future.
            /// </remarks>
            char mediaGatewayTranscast[64];
            /// <summary>
            /// The virtual IP or hostname used for Media Gateway devices.
            /// </summary>
            char mediaGatewayVirtualIp[256];
            /// <summary>
            /// The current configuration status description.
            /// </summary>
            char statusDescription[256];
            /// <summary>
            /// The retention limit, in days, on logged events from aggregated sources. Any aggregated events that
            /// exceed this limit shall be deleted.
            /// </summary>
            int aggregatedEventLimit;
            /// <summary>
            /// The retention limit, in days, on logged events. Any events that exceed this limit shall be deleted.
            /// </summary>
            int localEventLimit;
            /// <summary>
            /// The maximum number of allowed nodes under the current license. A license is required to expand the
            /// number of nodes that can be added to this cluster beyond this number. Set to -1 if there is no limit.
            /// </summary>
            int nodeLicenseLimit;
            /// <summary>
            /// The current configuration status code.
            /// </summary>
            int statusCode;
            /// <summary>
            /// The availability mode for the cluster, which determines how the nodes in the cluster are balanced and failover.
            /// </summary>
            VxClusterAvailabilityMode::Value availabilityMode;
            /// <summary>
            /// The current configuration status of the entire cluster.
            /// </summary>
            VxConfigStatus::Value status;
            /// <summary>
            /// The default communication method between data sources to Media Gateways and
            /// between Media Gateways to clients.
            /// </summary>
            VxMgTranscast::Value transcastMethod;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isExportPathEnabled = false;
                this->isStreamProxyEnabled = false;
                VxZeroArray(this->coreVirtualIp);
                VxZeroArray(this->discoveryVirtualIp);
                VxZeroArray(this->exportPath);
                VxZeroArray(this->exportPathUsername);
                VxZeroArray(this->mediaGatewayTranscast);
                VxZeroArray(this->mediaGatewayVirtualIp);
                VxZeroArray(this->statusDescription);
                this->aggregatedEventLimit = 0;
                this->localEventLimit = 0;
                this->nodeLicenseLimit = 0;
                this->statusCode = 0;
                this->availabilityMode = VxClusterAvailabilityMode::kUnknown;
                this->status = VxConfigStatus::kUnknown;
                this->transcastMethod = VxMgTranscast::kUnknown;
            }
        };

        /// <summary>
        /// Represents event configuration.
        /// </summary>
        struct Event {
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
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the aggregatedEventLimit property.
            /// </summary>
            /// <param name="aggregatedEventLimit">The new aggregated event limit, in days.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetAggregatedEventLimit(int aggregatedEventLimit) = 0;
            /// <summary>
            /// Sets the localEventLimit property.
            /// </summary>
            /// <param name="localEventLimit">The new local event limit, in days.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetLocalEventLimit(int localEventLimit) = 0;
            /// <summary>
            /// Sets the maxEvents property.
            /// </summary>
            /// <param name="maxEvents">The new max events limit.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMaxEvents(int maxEvents) = 0;

        public:
            /// <summary>
            /// The retention limit, in days, on logged events from aggregated sources. Any aggregated events that
            /// exceed this limit shall be deleted.
            /// </summary>
            int aggregatedEventLimit;
            /// <summary>
            /// The retention limit, in days, on logged events. Any events that exceed this limit shall be deleted.
            /// </summary>
            int localEventLimit;
            /// <summary>
            /// The retention limit, in number of events, on logged events from any sources. Any events that exceed
            /// this limit shall be deleted, starting with the oldest events and giving priority to retaining high
            /// severity events.
            /// </summary>
            int maxEvents;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->aggregatedEventLimit = 0;
                this->localEventLimit = 0;
                this->maxEvents = 0;
            }
        };

        /// <summary>
        /// Represents export configuration.
        /// </summary>
        struct Export {
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
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the forceProtect property.
            /// </summary>
            /// <param name="forceProtect">The new force protect value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetForceProtect(bool forceProtect) = 0;
            /// <summary>
            /// Set a global password for all new exports. Ignored if forceProtect is <c>false</c>.
            /// </summary>
            /// <param name="password">The new global password for exports.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetProtectPassword(char password[1024]) = 0;

        public:
            /// <summary>
            /// When <c>true</c>, every new export will be created with password protection.
            /// </summary>
            bool forceProtect;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->forceProtect = false;
            }
        };

        /// <summary>
        /// Represents the LDAP configuration available.
        /// </summary>
        struct Ldap {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables LDAP username/password authentication.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling LDAP authentication.</returns>
            virtual VxResult::Value DisableLdap() = 0;
            /// <summary>
            /// Disables management of users and roles through LDAP. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling LDAP management.</returns>
            virtual VxResult::Value DisableLdapUsersAndRoles() = 0;
            /// <summary>
            /// Disables the SSL/TLS security for the LDAP server.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling the SSL/TLS security.</returns>
            virtual VxResult::Value DisableServerTls() = 0;
            /// <summary>
            /// Disables single sign-on. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling single sign-on.</returns>
            virtual VxResult::Value DisableSso() = 0;
            /// <summary>
            /// Disables two stage binding authentication. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling two stage binding authentication.</returns>
            virtual VxResult::Value DisableTwoStageBinding() = 0;
            /// <summary>
            /// Enables LDAP username/password authentication.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling LDAP authentication.</returns>
            virtual VxResult::Value EnableLdap() = 0;
            /// <summary>
            /// Enables management of users and roles through LDAP. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling LDAP management.</returns>
            virtual VxResult::Value EnableLdapUsersAndRoles() = 0;
            /// <summary>
            /// Enables the SSL/TLS security for the LDAP server.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling the SSL/TLS security.</returns>
            virtual VxResult::Value EnableServerTls() = 0;
            /// <summary>
            /// Enables single sign-on. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling single sign-on.</returns>
            virtual VxResult::Value EnableSso() = 0;
            /// <summary>
            /// Enables two stage binding authentication. 
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling two stage binding authentication.</returns>
            virtual VxResult::Value EnableTwoStageBinding() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the baseDn property.
            /// </summary>
            /// <param name="baseDn">The new base DN.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetBaseDn(char baseDn[1024]) = 0;
            /// <summary>
            /// Sets the objectClasses property.
            /// </summary>
            /// <param name="objectClasses">The new object classes.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetObjectClasses(char objectClasses[1024]) = 0;
            /// <summary>
            /// Sets the searchAttributes property.
            /// </summary>
            /// <param name="searchAttributes">The new search attributes.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSearchAttributes(char searchAttributes[1024]) = 0;
            /// <summary>
            /// Sets the searchDnAccount property.
            /// </summary>
            /// <param name="searchDnAccount">The new search DN account.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSearchDnAccount(char searchDnAccount[1024]) = 0;
            /// <summary>
            /// Sets the password for the search DN account.
            /// </summary>
            /// <param name="searchDnPassword">The search DN password.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSearchDnPassword(char searchDnPassword[64]) = 0;
            /// <summary>
            /// Sets the serverName property.
            /// </summary>
            /// <param name="serverName">The new server hostname or IP.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetServerName(char serverName[256]) = 0;
            /// <summary>
            /// Sets the serverPort property.
            /// </summary>
            /// <param name="serverPort">The new server port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetServerPort(int serverPort) = 0;
            /// <summary>
            /// Sets the ssoDomain property.
            /// </summary>
            /// <param name="ssoDomain">The new SSO domain.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSsoDomain(char ssoDomain[1024]) = 0;
            /// <summary>
            /// Sets the vxRootDn property.
            /// </summary>
            /// <param name="vxRootDn">TThe new VideoXpert root DN.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetVxRootDn(char vxRootDn[1024]) = 0;
            /// <summary>
            /// Sets the vxSystemDn property.
            /// </summary>
            /// <param name="vxSystemDn">The new VideoXpert system DN.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetVxSystemDn(char vxSystemDn[1024]) = 0;
            /// <summary>
            /// Validate the given credentials on the specified LDAP server.
            /// </summary>
            /// <param name="isValid"><c>true</c> if the config and credentials are valid, otherwise <c>false</c>.</param>
            /// <param name="ldapCredentials">The LDAP credentials to validate.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of validating the credentials.</returns>
            virtual VxResult::Value ValidateLdapCredentials(bool& isValid, VxLdapValidationCredentials& ldapCredentials) = 0;

        public:
            /// <summary>
            /// Indicates whether or not LDAP username/password authentication is enabled.
            /// </summary>
            bool isEnabled;
            /// <summary>
            /// Indicates whether or not SSL/TLS security is enabled for the LDAP server.
            /// </summary>
            bool isServerTlsEnabled;
            /// <summary>
            /// Indicates whether or not single sign-on is enabled.
            /// </summary>
            bool isSsoEnabled;
            /// <summary>
            /// Indicates whether or not two stage binding authentication is enabled.
            /// </summary>
            bool isTwoStageBindingEnabled;
            /// <summary>
            /// Indicates whether or not LDAP will be used to manage users and roles.
            /// <remarks>
            /// <c>false</c> to only use the LDAP server for authentication; the VideoXpert system will manage users and
            /// roles itself. <c>true</c> to manage user accounts and role assignments in the LDAP system. Note that
            /// permissions on roles will still be managed by the VideoXpert system.
            /// </remarks>
            /// </summary>
            bool useLdapUsersAndRoles;
            /// <summary>
            /// The location in the LDAP database that will be used to search for and authenticate user entries.
            /// </summary>
            /// <example>ou=Service Accounts, dc=Pelco, dc=org</example>
            char baseDn[1024];
            /// <summary>
            /// The LDAP object classes to search for users.
            /// </summary>
            /// <example>user, inetOrgPerson</example>
            char objectClasses[1024];
            /// <summary>
            /// The attributes against which to match the user’s identity/name.
            /// </summary>
            /// <example>cn, mail</example>
            char searchAttributes[1024];
            /// <summary>
            /// The superuser DN account in the LDAP directory to use for performing searches there.
            /// <remarks>
            /// If <see cref="isSsoEnabled"/> is <c>true</c>, this account should have write permissions on
            /// the <see cref="vxRootDn"/>. Should be supplied if <see cref="isTwoStageBindingEnabled"/> or
            /// <see cref="useLdapUsersAndRoles"/> are <c>true</c>; ignored otherwise.
            /// </remarks>
            /// </summary>
            /// <example>CN=users, DC=mycorp</example>
            char searchDnAccount[1024];
            /// <summary>
            /// The hostname or IP address of the LDAP server.
            /// </summary>
            char serverName[256];
            /// <summary>
            /// The Active Directory/Kerberos domain used for single sign-on.
            /// <remarks>Ignored if <see cref="isSsoEnabled"/> is <c>false</c>.</remarks>
            /// </summary>
            char ssoDomain[1024];
            /// <summary>
            /// The LDAP container under which VideoXpert system information for all sites is stored; this should be the
            /// same for all sites.
            /// <remarks>
            /// Should be supplied if <see cref="useLdapUsersAndRoles"/> is <c>true</c>; ignored otherwise.
            /// </remarks>
            /// </summary>
            char vxRootDn[1024];
            /// <summary>
            /// The site specific LDAP container; unique per VideoXpert site. This DN should contain the
            /// <see cref="vxRootDn"/> (which is a suffix of this full DN).
            /// <remarks>
            /// Should be supplied if <see cref="useLdapUsersAndRoles"/> is <c>true</c>; ignored otherwise.
            /// </remarks>
            /// </summary>
            char vxSystemDn[1024];
            /// <summary>
            /// Port number of the LDAP server.
            /// </summary>
            int serverPort;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isEnabled = false;
                this->isServerTlsEnabled = false;
                this->isSsoEnabled = false;
                this->isTwoStageBindingEnabled = false;
                this->useLdapUsersAndRoles = false;
                VxZeroArray(this->baseDn);
                VxZeroArray(this->objectClasses);
                VxZeroArray(this->searchAttributes);
                VxZeroArray(this->searchDnAccount);
                VxZeroArray(this->serverName);
                VxZeroArray(this->ssoDomain);
                VxZeroArray(this->vxRootDn);
                VxZeroArray(this->vxSystemDn);
                this->serverPort = 0;
            }
        };

        /// <summary>
        /// Represents a motion detection configuration.
        /// </summary>
        struct Motion {
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
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the mode property.
            /// </summary>
            /// <param name="mode">The new mode value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMode(VxMotionMode::Value mode) = 0;
            /// <summary>
            /// Sets the sensitivity property.
            /// </summary>
            /// <param name="sensitivity">The new sensitivity value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSensitivity(int sensitivity) = 0;
            /// <summary>
            /// Sets the threshold property.
            /// </summary>
            /// <param name="threshold">The new threshold value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetThreshold(int threshold) = 0;

        public:
            /// <summary>
            /// The amount of change that needs to occur in order to qualify as motion. Higher values increase
            /// sensitivity (less change required to trigger motion).
            /// </summary>
            int sensitivity;
            /// <summary>
            /// The amount of area that needs to occur in order to qualify as motion. Higher values increase
            /// sensitivity (less area required to trigger motion).
            /// </summary>
            int threshold;
            /// <summary>
            /// The motion detection mode.
            /// </summary>
            VxMotionMode::Value mode;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->sensitivity = 0;
                this->threshold = 0;
                this->mode = VxMotionMode::kUnknown;
            }
        };

        /// <summary>
        /// Represents an individual host machine (a "node") within a cluster.
        /// </summary>
        struct Node {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;

        public:
            /// <summary>
            /// Indicates whether or not this node is an arbiter.
            /// </summary>
            bool isArbiter;
            /// <summary>
            /// The host alias for the arbiter node.
            /// </summary>
            char arbiterAlias[256];
            /// <summary>
            /// The host address.
            /// </summary>
            char hostAddress[64];
            /// <summary>
            /// The port number that the arbiter node uses.
            /// </summary>
            int arbiterPort;
            /// <summary>
            /// The current configuration status of this node
            /// </summary>
            VxConfigStatus::Value status;
            /// <summary>
            /// The particular type of node this is.
            /// </summary>
            VxNodeType::Value type;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isArbiter = false;
                VxZeroArray(this->arbiterAlias);
                VxZeroArray(this->hostAddress);
                this->arbiterPort = 0;
                this->status = VxConfigStatus::kUnknown;
                this->type = VxNodeType::kUnknown;
            }
        };

        /// <summary>
        /// Represents report configuration.
        /// </summary>
        struct Report {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the maxAge property.
            /// </summary>
            /// <param name="maxAge">The new max age, in days.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMaxAge(int maxAge) = 0;
            /// <summary>
            /// Sets the storageLocation property.
            /// </summary>
            /// <param name="storageLocation">The new storage location.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetStorageLocation(VxNetworkStorageInfo& storageLocation) = 0;

        public:
            /// <summary>
            /// The retention limit, in days, for reports; a value of 0 will disable the limit. Any report that exceeds
            /// this limit will be deleted.
            /// </summary>
            int maxAge;
            /// <summary>
            /// The network storage location to save report data to (used instead of local cluster storage).
            /// </summary>
            VxNetworkStorageInfo storageLocation;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->maxAge = 0;
                this->storageLocation.Clear();
            }
        };

        /// <summary>
        /// Represents general server configuration.
        /// </summary>
        struct Server {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables hostname lookup from IP.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling reverse DNS lookup.</returns>
            virtual VxResult::Value DisableReverseDnsLookup() = 0;
            /// <summary>
            /// Enables hostname lookup from IP.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling reverse DNS lookup.</returns>
            virtual VxResult::Value EnableReverseDnsLookup() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Restarts the server; generally required after any port changes to have them take effect.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value Restart() const = 0;
            /// <summary>
            /// Sets the httpPort property.
            /// </summary>
            /// <param name="httpPort">The HTTP port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetHttpPort(int httpPort) = 0;
            /// <summary>
            /// Sets the httpsPort property.
            /// </summary>
            /// <param name="httpsPort">The HTTPS port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetHttpsPort(int httpsPort) = 0;
            /// <summary>
            /// Sets the rtspPort property.
            /// </summary>
            /// <param name="rtspPort">The RTSP port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetRtspPort(int rtspPort) = 0;

        public:
            /// <summary>
            /// Indicates whether or not hostname lookup from IP is enabled.
            /// </summary>
            bool isReverseDnsLookupEnabled;
            /// <summary>
            /// The HTTP port number.
            /// </summary>
            int httpPort;
            /// <summary>
            /// The HTTPS port number.
            /// </summary>
            int httpsPort;
            /// <summary>
            /// The RTSP port number.
            /// </summary>
            int rtspPort;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isReverseDnsLookupEnabled = false;
                this->httpPort = 0;
                this->httpsPort = 0;
                this->rtspPort = 0;
            }
        };

        /// <summary>
        /// Represents the SMTP configuration.
        /// </summary>
        struct Smtp {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables enforcing validation of the servers certificate.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling certificate validation enforcement.</returns>
            virtual VxResult::Value DisableCertValidation() = 0;
            /// <summary>
            /// Disables the use of SMTPS.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling SMTPS.</returns>
            virtual VxResult::Value DisableSmtps() = 0;
            /// <summary>
            /// Enables enforcing validation of the servers certificate.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling certificate validation enforcement.</returns>
            virtual VxResult::Value EnableCertValidation() = 0;
            /// <summary>
            /// Enables the use of SMTPS instead of SMTP.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling SMTPS.</returns>
            virtual VxResult::Value EnableSmtps() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the fromAddress property.
            /// </summary>
            /// <param name="fromAddress">The "Mail From" email address.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetFromAddress(char fromAddress[256]) = 0;
            /// <summary>
            /// Sets the host property.
            /// </summary>
            /// <param name="host">The SMTP host.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetHost(char host[256]) = 0;
            /// <summary>
            /// Sets the password for SMTP access.
            /// </summary>
            /// <param name="password">The password.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetPassword(char password[64]) = 0;
            /// <summary>
            /// Sets the smtpPort property.
            /// </summary>
            /// <param name="smtpPort">The SMTP port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSmtpPort(int smtpPort) = 0;
            /// <summary>
            /// Sets the timeout property.
            /// </summary>
            /// <param name="timeout">The timeout in milliseconds.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTimeout(int timeout) = 0;
            /// <summary>
            /// Sets the username for SMTP access.
            /// </summary>
            /// <param name="username">The username.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetUsername(char username[64]) = 0;
            /// <summary>
            /// Validate the given SMTP information by attempting to use it to send a test email.
            /// </summary>
            /// <param name="isValid"><c>true</c> if sending the test email was successful, otherwise <c>false</c>.</param>
            /// <param name="smtpInfo">The SMTP information to validate.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of validating the SMTP information.</returns>
            virtual VxResult::Value ValidateSmtpInfo(bool& isValid, VxSmtpInfo& smtpInfo) = 0;

        public:
            /// <summary>
            /// Indicates whether or not validation of the servers certificate is enforced.
            /// </summary>
            bool isValidateCertEnabled;
            /// <summary>
            /// Indicates whether SMTPS should be used instead of SMTP.
            /// </summary>
            bool useSmtps;
            /// <summary>
            /// The "Mail From" email address.
            /// </summary>
            char fromAddress[256];
            /// <summary>
            /// The SMTP host.
            /// </summary>
            char host[256];
            /// <summary>
            /// The username for SMTP access.
            /// </summary>
            char username[64];
            /// <summary>
            /// The SMTP port.
            /// </summary>
            int smtpPort;
            /// <summary>
            /// The timeout in milliseconds.
            /// </summary>
            int timeout;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isValidateCertEnabled = false;
                this->useSmtps = false;
                VxZeroArray(this->fromAddress);
                VxZeroArray(this->host);
                VxZeroArray(this->username);
                this->smtpPort = 0;
                this->timeout = 0;
            }
        };

        /// <summary>
        /// Represents the SNMP agent configuration.
        /// </summary>
        struct Snmp {
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
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the snmpPort property.
            /// </summary>
            /// <param name="snmpPort">The SNMP port.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSnmpPort(int snmpPort) = 0;
            /// <summary>
            /// Sets the v2cReadCommunityString property.
            /// </summary>
            /// <param name="v2cReadCommunityString">The SNMP v2c community string.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetV2cReadCommunityString(char v2cReadCommunityString[256]) = 0;
            /// <summary>
            /// Sets the v3ReadUsername property.
            /// </summary>
            /// <param name="v3ReadUsername">The SNMP v3 read username.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetV3ReadUsername(char v3ReadUsername[256]) = 0;
            /// <summary>
            /// Sets the SNMP v3 read auth password.
            /// </summary>
            /// <param name="password">The read auth password.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the read auth password.</returns>
            virtual VxResult::Value SetV3ReadAuthPassword(char password[64]) = 0;
            /// <summary>
            /// Sets the SNMP v3 read privacy password.
            /// </summary>
            /// <param name="password">The read privacy password.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the read privacy password.</returns>
            virtual VxResult::Value SetV3ReadPrivacyPassword(char password[64]) = 0;
            /// <summary>
            /// Sets the v3AuthProtocol property.
            /// </summary>
            /// <param name="v3AuthProtocol">The SNMP v3 authentication protocol.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetV3AuthProtocol(VxAuthProtocol::Value v3AuthProtocol) = 0;
            /// <summary>
            /// Sets the v3PrivacyProtocol property.
            /// </summary>
            /// <param name="v3PrivacyProtocol">The SNMP v3 privacy protocol.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetV3PrivacyProtocol(VxPrivacyProtocol::Value v3PrivacyProtocol) = 0;
            /// <summary>
            /// Sets the version property.
            /// </summary>
            /// <param name="version">The version of SNMP to enable; <c>kNone</c> to disable SNMP..</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetVersion(VxSnmpVersion::Value version) = 0;

        public:
            /// <summary>
            /// The SNMP v2c community string.
            /// </summary>
            char v2cReadCommunityString[256];
            /// <summary>
            /// The SNMP v3 read username.
            /// </summary>
            char v3ReadUsername[256];
            /// <summary>
            /// The port on which to provide access to SNMP.
            /// </summary>
            int snmpPort;
            /// <summary>
            /// The SNMP v3 authentication protocol.
            /// </summary>
            VxAuthProtocol::Value v3AuthProtocol;
            /// <summary>
            /// The SNMP v3 privacy protocol.
            /// </summary>
            VxPrivacyProtocol::Value v3PrivacyProtocol;
            /// <summary>
            /// Indicates which version of SNMP is enabled.
            /// </summary>
            VxSnmpVersion::Value version;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->v2cReadCommunityString);
                VxZeroArray(this->v3ReadUsername);
                this->snmpPort = 0;
                this->v3AuthProtocol = VxAuthProtocol::kUnknown;
                this->v3PrivacyProtocol = VxPrivacyProtocol::kUnknown;
                this->version = VxSnmpVersion::kUnknown;
            }
        };

        /// <summary>
        /// Represents a VxStorage-specific configuration.
        /// </summary>
        struct Storage {
        public:
            /// <summary>
            /// Creates a new volume on the VxStorage.
            /// </summary>
            /// <param name="newVolume">The new volume to be created.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value CreateVolume(VxNewVolume& newVolume) const = 0;
            /// <summary>
            /// Creates a new volume group on the VxStorage.
            /// </summary>
            /// <param name="newVolumeGroup">The new volume group to be created.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value CreateVolumeGroup(VxNewVolumeGroup& newVolumeGroup) const = 0;
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables this VxStorage as a failover unit.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this VxStorage as a failover unit.</returns>
            virtual VxResult::Value DisableFailover() = 0;
            /// <summary>
            /// Disables automatic gap filling.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling the gap filler.</returns>
            virtual VxResult::Value DisableGapFiller() = 0;
            /// <summary>
            /// Enables this VxStorage as a failover unit (it will failover the data storages on any device
            /// it's monitoring). NOTE: Failover units will not provide device assignment nor schedule management
            /// functionality; they are dedicated to failover monitoring functions.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling this VxStorage as a failover unit.</returns>
            virtual VxResult::Value EnableFailover() = 0;
            /// <summary>
            /// Enables automatic gap filling.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling the gap filler.</returns>
            virtual VxResult::Value EnableGapFiller() = 0;
            /// <summary>
            /// Gets the file recovery control and monitor resource for this VxStorage.
            /// </summary>
            /// <param name="fileRecovery">The file recovery control and monitor resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetFileRecovery(IVxFileRecovery*& fileRecovery) const = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Gets the volumes for this storage.
            /// </summary>
            /// <param name="volumeCollection">A <see cref="VxCollection"/> of volumes.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetVolumes(VxCollection<IVxVolume**>& volumeCollection) const = 0;
            /// <summary>
            /// Gets the volume groups for this storage.
            /// </summary>
            /// <param name="volumeGroupCollection">A <see cref="VxCollection"/> of volume groups.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetVolumeGroups(VxCollection<IVxVolumeGroup**>& volumeGroupCollection) const = 0;
            /// <summary>
            /// Rebuilds the database. Has no effect if the database is already rebuilding.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of rebuilding the database.
            /// </returns>
            virtual VxResult::Value RebuildDatabase() = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the maximum recording bitrate for this VxStorage when enabled as a failover unit (in Mbps).
            /// </summary>
            /// <param name="failoverMaxRecordingBitrate">The new bitrate value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetFailoverMaxRecordingBitrate(int failoverMaxRecordingBitrate) = 0;
            /// <summary>
            /// Sets the maximum number of attempts to fill a gap before giving up.
            /// </summary>
            /// <param name="gapFillerAttempts">The new attempts value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetGapFillerAttempts(int gapFillerAttempts) = 0;
            /// <summary>
            /// Sets the maximum number of concurrent downloads.
            /// </summary>
            /// <param name="gapFillerDownloads">The new gap filler downloads value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetGapFillerDownloads(int gapFillerDownloads) = 0;
            /// <summary>
            /// Sets the interval, in seconds, to reattempt to automatically fill a gap.
            /// </summary>
            /// <param name="gapFillerInterval">The new interval value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetGapFillerInterval(int gapFillerInterval) = 0;
            /// <summary>
            /// Sets the amount of time, in seconds, to allow a manual recording to be active. The manual
            /// recording will be automatically deleted after this amount of time elapses if it has not been
            /// refreshed (see: <c>IVxManualRecording::ResetExpirationTimers</c>). No timeout is
            /// applied if the value is less than 1.
            /// </summary>
            /// <param name="manualRecordingTimeout">The new timeout value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetManualRecordingTimeout(int manualRecordingTimeout) = 0;
            /// <summary>
            /// Sets the maximum outbound bitrate for this VxStorage (in Mbps).
            /// </summary>
            /// <param name="maxOutboundBitrate">The new max bitrate value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMaxOutboundBitrate(int maxOutboundBitrate) = 0;
            /// <summary>
            /// Sets the list of device IDs being monitored for failover.  If <see cref="isFailoverEnabled"/>
            /// is <c>true</c> and a failure is detected on one of these, this VxStorage will failover all devices
            /// assigned to the data storage on that device. A value of 0 will will clear any existing device IDs.
            /// </summary>
            /// <param name="deviceIds">The device IDs to monitor.</param>
            /// <param name="deviceIdsSize"> The size of <paramref name="deviceIds"/>.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetMonitoredDeviceIds(char** deviceIds, int deviceIdsSize) = 0;
            /// <summary>
            /// Sets the threshold, in hours, after which recordings older than this are eligible for pruning. Any recorded
            /// media retained longer than the threshold will be pruned as needed to free space on disk for recording.
            /// This only applies to data source having type video. A value of 0 will disable pruning (pruning may be
            /// enabled on a per data source basis still, see: IVxDataSource::pruningThreshold).
            /// </summary>
            /// <param name="pruningThreshold">The new threshold, in hours.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetPruningThreshold(int pruningThreshold) = 0;
            /// <summary>
            /// Sets the retention limit, in hours, on recorded data; a value of 0 will disable the limit. Any
            /// recorded data that exceeds this limit will be deleted.
            /// </summary>
            /// <param name="retentionLimit">The new retention limit.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetRetentionLimit(int retentionLimit) = 0;
            /// <summary>
            /// Sets the second stream to record from all assigned data sources (when scheduled to record).
            /// </summary>
            /// <param name="secondaryVideoStreamRecordingSource">The new second video stream source to record.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetSecondaryVideoStreamRecordingSource(VxStreamSource::Value secondaryVideoStreamRecordingSource) = 0;
            /// <summary>
            /// Sets the network communication transmission type preference. Note that if the preferred communication
            /// fails, this VxStorage may attempt to utilize unicast.
            /// </summary>
            /// <param name="transmissionPreference">The new transmission preference.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTransmissionPreference(VxTransmissionType::Value transmissionPreference) = 0;
            /// <summary>
            /// Sets the stream to record from all assigned data sources (when scheduled to record).
            /// </summary>
            /// <param name="videoStreamRecordingSource">The new video stream source to record.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetVideoStreamRecordingSource(VxStreamSource::Value videoStreamRecordingSource) = 0;

        public:
            /// <summary>
            /// Indicated whether or not this VxStorage is designated as a failover unit.
            /// </summary>
            bool isFailoverEnabled;
            /// <summary>
            /// Indicated whether or not automatic gap filling is enabled.
            /// </summary>
            bool isGapFillerEnabled;
            /// <summary>
            /// The network communication transmission type preference.
            /// </summary>
            /// <remarks>
            /// DEPRECATED: This has been replaced by <see cref="transmissionPreference"/> and will be removed in
            /// the future.
            /// </remarks>
            char transmissionType[64];
            /// <summary>
            /// List of device IDs belonging to this VxStorage failover group (including itself).
            /// </summary>
            char** failoverGroup;
            /// <summary>
            /// List of device IDs being monitored for failover.
            /// </summary>
            char** monitoredDeviceIds;
            /// <summary>
            /// The size of <see cref="failoverGroup"/>.
            /// </summary>
            int failoverGroupSize;
            /// <summary>
            /// The maximum recording bitrate for this VxStorage when enabled as a failover unit (in Mbps).
            /// </summary>
            int failoverMaxRecordingBitrate;
            /// <summary>
            /// The maximum number of attempts to fill a gap before giving up.
            /// </summary>
            int gapFillerAttempts;
            /// <summary>
            /// The maximum number of concurrent downloads.
            /// </summary>
            int gapFillerDownloads;
            /// <summary>
            /// The interval, in seconds, to reattempt to automatically fill a gap.
            /// </summary>
            int gapFillerInterval;
            /// <summary>
            /// The amount of time, in seconds, to allow a manual recording to be active.
            /// </summary>
            int manualRecordingTimeout;
            /// <summary>
            /// The maximum outbound bitrate for this VxStorage (in Mbps).
            /// </summary>
            int maxOutboundBitrate;
            /// <summary>
            /// The size of <see cref="monitoredDeviceIds"/>.
            /// </summary>
            int monitoredDeviceIdsSize;
            /// <summary>
            /// The threshold, in hours, after which recordings older than this are eligible for pruning. Any recorded
            /// media retained longer than the threshold will be pruned as needed to free space on disk for recording.
            /// This only applies to data source having type video. A value of 0 will disable pruning (pruning may be
            /// enabled on a per data source basis still, see: IVxDataSource::pruningThreshold).
            /// </summary>
            int pruningThreshold;
            /// <summary>
            /// The retention limit, in hours, on recorded data.
            /// </summary>
            int retentionLimit;
            /// <summary>
            /// The second stream to record from all assigned data sources (when scheduled to record).
            /// </summary>
            VxStreamSource::Value secondaryVideoStreamRecordingSource;
            /// <summary>
            /// The stream to record from for all assigned data sources (when scheduled to record).
            /// </summary>
            VxStreamSource::Value videoStreamRecordingSource;
            /// <summary>
            /// The network communication transmission type preference.
            /// </summary>
            VxTransmissionType::Value transmissionPreference;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isFailoverEnabled = false;
                this->isGapFillerEnabled = false;
                VxZeroArray(this->transmissionType);
                this->failoverGroup = nullptr;
                this->monitoredDeviceIds = nullptr;
                this->failoverGroupSize = 0;
                this->monitoredDeviceIdsSize = 0;
                this->failoverMaxRecordingBitrate = 0;
                this->gapFillerAttempts = 0;
                this->gapFillerDownloads = 0;
                this->gapFillerInterval = 0;
                this->manualRecordingTimeout = 0;
                this->maxOutboundBitrate = 0;
                this->pruningThreshold = 0;
                this->retentionLimit = 0;
                this->secondaryVideoStreamRecordingSource = VxStreamSource::kUnknown;
                this->videoStreamRecordingSource = VxStreamSource::kUnknown;
                this->transmissionPreference = VxTransmissionType::kUnknown;
            }
        };

        /// <summary>
        /// Represents thermal elevated temperature detection configuration.
        /// </summary>
        struct ThermalEtd {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables elevated temperature detection events and overlays.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling elevated temp. detection.</returns>
            virtual VxResult::Value Disable() = 0;
            /// <summary>
            /// Enables elevated temperature detection events and overlays.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling elevated temp. detection.</returns>
            virtual VxResult::Value Enable() = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the normalRangeLowerBound property.
            /// </summary>
            /// <param name="normalRangeLowerBound">The new normalRangeLowerBound value in degrees Celsius.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetNormalRangeLowerBound(float normalRangeLowerBound) = 0;
            /// <summary>
            /// Sets the normalRangeUpperBound property.
            /// </summary>
            /// <param name="normalRangeUpperBound">The new normalRangeUpperBound value in degrees Celsius.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetNormalRangeUpperBound(float normalRangeUpperBound) = 0;
            /// <summary>
            /// Sets the timeout property.
            /// </summary>
            /// <param name="timeout">The new timeout value in seconds.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTimeout(int timeout) = 0;

        public:
            /// <summary>
            /// Indicates whether or not elevated temperature detection events and overlays are enabled.
            /// </summary>
            bool isEnabled;
            /// <summary>
            /// The lower bound of the normal temperature range, in degrees Celsius; lower temperatures will be
            /// considered abnormally low.
            /// </summary>
            float normalRangeLowerBound;
            /// <summary>
            /// The upper bound of the normal temperature range, in degrees Celsius; higher temperatures will be
            /// considered elevated.
            /// </summary>
            float normalRangeUpperBound;
            /// <summary>
            /// The number of seconds before a new event is emitted for the same person in view.
            /// </summary>
            int timeout;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isEnabled = false;
                this->normalRangeLowerBound = 0.0f;
                this->normalRangeUpperBound = 0.0f;
                this->timeout = 0;
            }
        };

        /// <summary>
        /// Represents the time configuration.
        /// </summary>
        struct Time {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Gets the current internal system time.
            /// </summary>
            /// <param name="currentTime">The current internal time from the system.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetTime(char currentTime[64]) = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the list of external time servers for time synchronization.
            /// </summary>
            /// <param name="externalTimeServers">The external time server host addresses.</param>
            /// <param name="externalTimeServersSize"> The size of <paramref name="externalTimeServers"/>.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetExternalTimeServers(char** externalTimeServers, int externalTimeServersSize) = 0;
            /// <summary>
            /// Sets source where the time server information comes from.
            /// </summary>
            /// <param name="timeServerSource">The new time server source value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTimeServerSource(VxTimeServerSource::Value timeServerSource) = 0;
            /// <summary>
            /// Sets the time zone of the device, for localization purposes.
            /// </summary>
            /// <param name="timeZone">The new time zone value.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetTimeZone(char timeZone[64]) = 0;

        public:
            /// <summary>
            /// DEPRECATED
            /// <para>Indicates whether or not the external time server is enabled.</para>
            /// </summary>
            bool isTimeServerEnabled;
            /// <summary>
            /// DEPRECATED
            /// <para>The host address of the external time server.</para>
            /// </summary>
            char timeServerAddress[64];
            /// <summary>
            /// The time zone of the device, for localization purposes.
            /// </summary>
            char timeZone[64];
            /// <summary>
            /// The external time servers for time synchronization, typically using the NTP protocol.
            /// </summary>
            char** externalTimeServers;
            /// <summary>
            /// The size of <see cref="externalTimeServers"/>.
            /// </summary>
            int externalTimeServersSize;
            /// <summary>
            /// The source where the time server information comes from.
            /// </summary>
            VxTimeServerSource::Value timeServerSource;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isTimeServerEnabled = false;
                VxZeroArray(this->timeServerAddress);
                VxZeroArray(this->timeZone);
                this->externalTimeServers = nullptr;
                this->externalTimeServersSize = 0;
                this->timeServerSource = VxTimeServerSource::kUnknown;
            }
        };

        /// <summary>
        /// Represents Twilio (twilio.com) SMS account configuration.
        /// </summary>
        struct Twilio {
        public:
            /// <summary>
            /// Deletes this instance.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
            virtual VxResult::Value Delete() const = 0;
            /// <summary>
            /// Disables SMS messaging via Twilio.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of disabling SMS messaging via Twilio.</returns>
            virtual VxResult::Value Disable() = 0;
            /// <summary>
            /// Enables SMS messaging via Twilio.
            /// </summary>
            /// <returns>The <see cref="VxResult::Value">Result</see> of enabling SMS messaging via Twilio.</returns>
            virtual VxResult::Value Enable() = 0;
            /// <summary>
            /// Gets the limits related to this resource.
            /// </summary>
            /// <param name="limits">The limits related to this resource.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
            virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
            /// <summary>
            /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
            /// </summary>
            /// <returns>
            /// The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.
            /// </returns>
            virtual VxResult::Value Refresh() = 0;
            /// <summary>
            /// Sets the accountSid property.
            /// </summary>
            /// <param name="accountSid">The Twilio account SID.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetAccountSid(char accountSid[256]) = 0;
            /// <summary>
            /// Sets the Twilio account authorization token.
            /// </summary>
            /// <param name="authToken">The Twilio account authorization token.</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the authorization token.</returns>
            virtual VxResult::Value SetAuthToken(char authToken[512]) = 0;
            /// <summary>
            /// Sets the fromNumber property.
            /// </summary>
            /// <param name="fromNumber">The Twilio phone number capable of sending SMS (e.g., +15595551234).</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
            virtual VxResult::Value SetFromNumber(char fromNumber[64]) = 0;
            /// <summary>
            /// Validate the given Twilio info by attempting to use it to send a test SMS.
            /// </summary>
            /// <param name="isValid"><c>true</c> if sending the test SMS was successful, otherwise <c>false</c>.</param>
            /// <param name="accountSid">A Twilio account SID.</param>
            /// <param name="authToken">A Twilio account authorization token.</param>
            /// <param name="fromNumber">A Twilio phone number capable of sending SMS (e.g., +15595551234).</param>
            /// <param name="toNumber">A phone number capable of receiving SMS to send messages to (e.g., +15595551234).</param>
            /// <returns>The <see cref="VxResult::Value">Result</see> of validating the Twilio info.</returns>
            virtual VxResult::Value ValidateTwilioInfo(bool& isValid, const char* accountSid, const char* authToken, const char* fromNumber, const char* toNumber) = 0;

        public:
            /// <summary>
            /// Indicates whether or not SMS messaging via Twilio is enabled.
            /// </summary>
            bool isEnabled;
            /// <summary>
            /// The Twilio account SID.
            /// </summary>
            char accountSid[256];
            /// <summary>
            /// A Twilio phone number capable of sending SMS (e.g., +15595551234).
            /// </summary>
            char fromNumber[64];

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isEnabled = false;
                VxZeroArray(this->accountSid);
                VxZeroArray(this->fromNumber);
            }
        };
    };
}
#endif // IVxConfiguration_h__
