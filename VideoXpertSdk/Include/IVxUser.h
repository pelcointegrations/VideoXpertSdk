#ifndef IVxUser_h__
#define IVxUser_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "IVxDataObject.h"
#include "IVxTag.h"
#include "IVxRole.h"

namespace VxSdk {
    /// <summary>
    /// Represents information about a system user.
    /// </summary>
    struct IVxUser {
    public:
        /// <summary>
        /// Adds a role to this user.
        /// </summary>
        /// <param name="role">The role to add the user to.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddToRole(IVxRole& role) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this user from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this user.</returns>
        virtual VxResult::Value DeleteUser() const = 0;
        /// <summary>
        /// Gets the account state of the user.
        /// </summary>
        /// <param name="isEnabled"><c>true</c> if the user account is enabled, <c>false</c> if disabled.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAccountState(bool& isEnabled) const = 0;
        /// <summary>
        /// Gets the data objects associated with this user.
        /// <para>Available filters: kClientType, kModifiedSince, kOwned, kOwner.</para>
        /// </summary>
        /// <param name="dataObjectCollection">
        /// A <see cref="VxCollection"/> of data objects associated with this user.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataObjects(VxCollection<IVxDataObject**>& dataObjectCollection) const = 0;
        /// <summary>
        /// Gets the roles associated with this user.
        /// <para>Available filters: kAdvancedQuery, kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="roleCollection">The roles associated with this user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRoles(VxCollection<IVxRole**>& roleCollection) const = 0;
        /// <summary>
        /// Gets all private tags owned by this user and all public tags. Other user’s private tags will not be
        /// returned regardless of permissions.
        /// <para>
        /// Available filters: kAdvancedQuery, kFolder, kId, kModifiedSince, kName, kOwned, kOwner, kParentId,
        /// kResourceId, kResourceType.
        /// </para>
        /// </summary>
        /// <param name="tagCollection">A <see cref="VxCollection"/> of tags available to the user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTags(VxCollection<IVxTag**>& tagCollection) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Removes a role from this user.
        /// </summary>
        /// <param name="role">The role to remove the user from.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RemoveFromRole(IVxRole& role) const = 0;
        /// <summary>
        /// Sets the account state of the user. A disabled account will not be able to access the system.
        /// </summary>
        /// <param name="isEnabled"><c>true</c> to enable the user account, <c>false</c> to disable.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetAccountState(bool isEnabled) const = 0;
        /// <summary>
        /// Sets the domain property.
        /// </summary>
        /// <param name="domain">The new domain value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDomain(char domain[64]) = 0;
        /// <summary>
        /// Sets the email property.
        /// </summary>
        /// <param name="email">The new email value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEmail(char email[256]) = 0;
        /// <summary>
        /// Sets the employee id property.
        /// </summary>
        /// <param name="employeeId">The new employee id value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEmployeeId(char employeeId[64]) = 0;
        /// <summary>
        /// Sets the first name property.
        /// </summary>
        /// <param name="firstName">The new first name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetFirstName(char firstName[64]) = 0;
        /// <summary>
        /// Sets the last name property.
        /// </summary>
        /// <param name="lastName">The new last name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLastName(char lastName[64]) = 0;
        /// <summary>
        /// Sets the note property.
        /// </summary>
        /// <param name="note">The new note value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNote(char note[1024]) = 0;
        /// <summary>
        /// Sets a new password for the user.
        /// </summary>
        /// <param name="newPassword">
        /// The new password to set for this user. Must contain more than 7 characters.
        /// </param>
        /// <param name="mustChangePassword">
        /// If <c>true</c>, the password will immediately be expired the first time it is used to login.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetPassword(char newPassword[64], bool mustChangePassword) const = 0;
        /// <summary>
        /// Sets the telephone number(s) for this user. Maximum of 16 numbers.
        /// </summary>
        /// <param name="phoneNumbers">The phone numbers.</param>
        /// <param name="phoneNumberSize">
        /// The size of <see cref="phoneNumbers"/>, a value of 0 will clear out any existing phone numbers.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPhoneNumbers(VxPhoneNumber** phoneNumbers, int phoneNumberSize) = 0;

    public:
        /// <summary>
        /// The network domain for this user.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The email address of the user.
        /// </summary>
        char email[256];
        /// <summary>
        /// The employee identifier associated with the user.
        /// </summary>
        char employeeId[64];
        /// <summary>
        /// The first name of user.
        /// </summary>
        char firstName[64];
        /// <summary>
        /// The unique identifier of the user.
        /// </summary>
        char id[64];
        /// <summary>
        /// The last name of user.
        /// </summary>
        char lastName[64];
        /// <summary>
        /// The unique name, within the domain, of the user.
        /// </summary>
        char name[64];
        /// <summary>
        /// Supplemental information about the user.
        /// </summary>
        char note[1024];
        /// <summary>
        /// The time at which the user’s password will expire.
        /// </summary>
        char passwordExpiration[64];
        /// <summary>
        /// The size of <see cref="phoneNumbers"/>.
        /// </summary>
        int phoneNumberSize;
        /// <summary>
        /// The telephone number(s) for the user.
        /// </summary>
        VxPhoneNumber** phoneNumbers;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->domain);
            VxZeroArray(this->email);
            VxZeroArray(this->employeeId);
            VxZeroArray(this->firstName);
            VxZeroArray(this->id);
            VxZeroArray(this->lastName);
            VxZeroArray(this->name);
            VxZeroArray(this->note);
            VxZeroArray(this->passwordExpiration);
            this->phoneNumberSize = 0;
            this->phoneNumbers = nullptr;
        }
    };
}

#endif // IVxUser_h__
