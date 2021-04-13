#ifndef VxDiscoveryRequest_h__
#define VxDiscoveryRequest_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxDeviceSearch.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request to discover new devices.
    /// </summary>
    struct VxDiscoveryRequest {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxDiscoveryRequest"/> struct.
        /// </summary>
        VxDiscoveryRequest() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxDiscoveryRequest"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxDiscoveryRequest(const VxDiscoveryRequest& ref) {
            extend = ref.extend;
            this->searchAtSize = ref.searchAtSize;
            this->searchAt = nullptr;
            if (ref.searchAt != nullptr) {
                this->searchAt = new VxDeviceSearch * [ref.searchAtSize];
                for (int i = 0; i < ref.searchAtSize; i++)
                    this->searchAt[i] = new VxDeviceSearch(*ref.searchAt[i]);
            }

            this->protocolsSize = ref.protocolsSize;
            this->protocols = nullptr;
            if (ref.protocols != nullptr) {
                this->protocols = new VxDiscoveryProtocol::Value[ref.protocolsSize];
                for (int i = 0; i < ref.protocolsSize; i++)
                    this->protocols[i] = ref.protocols[i];
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxDiscoveryRequest"/> class.
        /// </summary>
        ~VxDiscoveryRequest() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->extend = false;
            this->protocolsSize = 0;
            this->searchAtSize = 0;
            this->searchAt = nullptr;
            this->protocols = nullptr;
        }

    public:
        /// <summary>
        /// <c>true</c> to extend the previous discovery; this will maintain the existing initiated and number
        /// counters. Defaults to <c>true</c> if discovery was initiated is within the past 12 hours. <c>false</c> will
        /// begin a new discovery (new initiated and reset number counters). Ignored if discovery is currently in
        /// progress (discovery is always extended in this case).
        /// </summary>
        bool extend;
        /// <summary>
        /// The size of <see cref="protocols"/>.
        /// </summary>
        int protocolsSize;
        /// <summary>
        /// The size of <see cref="searchAt"/>.
        /// </summary>
        int searchAtSize;
        /// <summary>
        /// The specific devices to discover.
        /// </summary>
        VxDeviceSearch** searchAt;
        /// <summary>
        /// The protocols to use for the discovery; if omitted, all available protocols are used.
        /// </summary>
        VxDiscoveryProtocol::Value* protocols;
    };
}

#endif // VxDiscoveryRequest_h__