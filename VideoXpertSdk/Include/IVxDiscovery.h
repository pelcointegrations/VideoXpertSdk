#ifndef IVxDiscovery_h__
#define IVxDiscovery_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxDiscoveryRequest.h"

namespace VxSdk {
    /// <summary>
    /// Represents the current status of device discovery.
    /// </summary>
    struct IVxDiscovery {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Begins discovery and initialization.
        /// </summary>
        /// <param name="discoveryRequest">The discovery request to trigger.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value TriggerDiscovery(VxDiscoveryRequest& discoveryRequest) const = 0;

    public:
        /// <summary>
        /// Indicates whether the system is currently discovering devices.
        /// </summary>
        bool isDiscovering;
        /// <summary>
        /// <c>true</c> if currently initializing devices; <c>false</c> otherwise.
        /// </summary>
        bool isInitializing;
        /// <summary>
        /// The time when the current discovery attempt was triggered.
        /// </summary>
        char initiated[64];
        /// <summary>
        /// The number of devices that were successfully discovered in the most recent discovery attempt.
        /// </summary>
        int numDiscovered;
        /// <summary>
        /// The number of devices that failed to initialize in the most recent discovery attempt.
        /// </summary>
        int numInitializationErrors;
        /// <summary>
        /// The number of devices that were successfully initialized in the most recent discovery attempt.
        /// </summary>
        int numInitialized;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isDiscovering = false;
            this->isInitializing = false;
            VxZeroArray(this->initiated);
            this->numDiscovered = 0;
            this->numInitializationErrors = 0;
            this->numInitialized = 0;
        }
    };
}
#endif // IVxDiscovery_h__
