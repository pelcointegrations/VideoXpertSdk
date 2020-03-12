#ifndef VxNewMember_h__
#define VxNewMember_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a request to add a new member system.
    /// </summary>
    struct VxNewMember {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMember"/> struct.
        /// </summary>
        VxNewMember() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewMember"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewMember(const VxNewMember& ref) {         
            Utilities::StrCopySafe(this->host, ref.host);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->username, ref.username);
			this->bandwidth = ref.bandwidth;
			this->port = ref.port;
			this->rtspCapability = ref.rtspCapability;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewMember"/> class.
        /// </summary>
        ~VxNewMember() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->host);
            VxZeroArray(this->password);
            VxZeroArray(this->username);
            this->bandwidth = 0;
            this->port = 0;
            this->rtspCapability = VxRtspCapability::kUnknown;
        }

    public:
        /// <summary>
        /// The host address of the system.
        /// </summary>
        char host[256];
        /// <summary>
        /// Password for access to the member.
        /// </summary>
        char password[64];
        /// <summary>
        /// Username for access to the member.
        /// </summary>
        char username[64];
        /// <summary>
        /// Bandwidth available between the aggregator system and the member system (in kbps).
        /// </summary>
        int bandwidth;
        /// <summary>
        /// The host port of the system.
        /// </summary>
        int port;
        /// <summary>
        /// The network streaming capabilities that the member shall expose to its clients (via data interfaces).
        /// </summary>
        VxRtspCapability::Value rtspCapability;
    };
}

#endif // VxNewMember_h__