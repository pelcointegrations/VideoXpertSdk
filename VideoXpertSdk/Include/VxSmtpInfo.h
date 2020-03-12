#ifndef VxSmtpInfo_h__
#define VxSmtpInfo_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents the SMTP information needed to send an email.
    /// </summary>
    struct VxSmtpInfo {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxSmtpInfo"/> struct.
        /// </summary>
        VxSmtpInfo() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxSmtpInfo"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxSmtpInfo(const VxSmtpInfo& ref) {
            this->useSmtps = ref.useSmtps;
            Utilities::StrCopySafe(this->fromAddress, ref.fromAddress);
            Utilities::StrCopySafe(this->host, ref.host);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->toAddress, ref.toAddress);
            Utilities::StrCopySafe(this->username, ref.username);
            this->smtpPort = ref.smtpPort;
            this->timeout = ref.timeout;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxSmtpInfo"/> class.
        /// </summary>
        ~VxSmtpInfo() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->useSmtps = false;
            VxZeroArray(this->fromAddress);
            VxZeroArray(this->host);
            VxZeroArray(this->password);
            VxZeroArray(this->toAddress);
            VxZeroArray(this->username);
            this->smtpPort = 0;
            this->timeout = 0;
        }

    public:
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
        /// The password for SMTP access.
        /// </summary>
        char password[64];
        /// <summary>
        /// The "Mail To" email address.
        /// </summary>
        char toAddress[256];
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
    };
}

#endif // VxSmtpInfo_h__
