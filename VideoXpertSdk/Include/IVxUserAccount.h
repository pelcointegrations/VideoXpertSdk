#ifndef IVxUserAccount_h__
#define IVxUserAccount_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents account information for a specific user.
    /// </summary>
    struct IVxUserAccount {
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
        /// Sets the canBypassLdap property.
        /// </summary>
        /// <param name="canBypassLdap">The new canBypassLdap value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetCanBypassLdap(bool canBypassLdap) = 0;
        /// <summary>
        /// Sets the isEnabled property.
        /// </summary>
        /// <param name="isEnabled">The new isEnabled value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIsEnabled(bool isEnabled) = 0;
        /// <summary>
        /// Sets the isPasswordExpirationDisabled property.
        /// </summary>
        /// <param name="isPasswordExpirationDisabled">The new isPasswordExpirationDisabled value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIsPasswordExpirationDisabled(bool isPasswordExpirationDisabled) = 0;

    public:
        /// <summary>
        /// If <c>true</c>, the user can login to the system using local credentials instead of using the LDAP
        /// authentication.
        /// </summary>
        bool canBypassLdap;
        /// <summary>
        /// Indicates whether or not this user account is enabled. A disabled account will not be able to access the
        /// system unless the account is re-enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// Indicates whether or not password expiration is enabled for this user account. If <c>true</c>, password
        /// expiration will be disable for this account; <c>false</c> will use the global password expiration setting
        /// for this account.
        /// </summary>
        bool isPasswordExpirationDisabled;


    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->canBypassLdap = false;
            this->isEnabled = false;
            this->isPasswordExpirationDisabled = false;
        }
    };
}

#endif // IVxUserAccount_h__
