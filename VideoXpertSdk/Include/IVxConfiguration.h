#ifndef IVxConfiguration_h__
#define IVxConfiguration_h__

#include "VxPrimitives.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the configuration of a device.
    /// </summary>
    struct IVxConfiguration {
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

        public:
            /// <summary>
            /// Indicates whether or not the external time server is enabled.
            /// </summary>
            bool isTimeServerEnabled;
            /// <summary>
            /// The host address of the external time server.
            /// </summary>
            char timeServerAddress[64];

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isTimeServerEnabled = false;
                VxZeroArray(this->timeServerAddress);
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
            /// The host address.
            /// </summary>
            char hostAddress[64];
            /// <summary>
            /// The current configuration status of this node
            /// </summary>
            VxConfigStatus::Value status;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->hostAddress);
                this->status = VxConfigStatus::kUnknown;
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

        public:
            /// <summary>
            /// The virtual IP or hostname used for VideoXpert Core devices.
            /// </summary>
            char coreVirtualIp[64];
            /// <summary>
            /// The default communication method between data sources to Media Gateways and
            /// between Media Gateways to clients.
            /// </summary>
            char mediaGatewayTranscast[64];
            /// <summary>
            /// The virtual IP or hostname used for Media Gateway devices.
            /// </summary>
            char mediaGatewayVirtualIp[64];
            /// <summary>
            /// The current configuration status description.
            /// </summary>
            char statusDescription[256];
            /// <summary>
            /// The current configuration status code.
            /// </summary>
            int statusCode;
            /// <summary>
            /// The current configuration status of the entire cluster.
            /// </summary>
            VxConfigStatus::Value status;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->coreVirtualIp);
                VxZeroArray(this->mediaGatewayTranscast);
                VxZeroArray(this->mediaGatewayVirtualIp);
                VxZeroArray(this->statusDescription);
                this->statusCode = 0;
                this->status = VxConfigStatus::kUnknown;
            }
        };

        /// <summary>
        /// Represents a VxStorage-specific configuration.
        /// </summary>
        struct Storage {
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
            /// The network communication transmission type preference.
            /// </summary>
            char transmissionType[64];
            /// <summary>
            /// The retention limit, in hours, on recorded data.
            /// </summary>
            int retentionLimit;

        protected:
            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->transmissionType);
                this->retentionLimit = 0;
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

        public:
            /// <summary>
            /// The amount of change that needs to occur in order to qualify as motion. Higher values increase
            /// sensitivity (less change required to trigger motion).
            /// </summary>
            int sensitivity;
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
                this->mode = VxMotionMode::kUnknown;
            }
        };
    };
}
#endif // IVxConfiguration_h__
