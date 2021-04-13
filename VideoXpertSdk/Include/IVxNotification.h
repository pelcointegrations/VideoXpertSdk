#ifndef IVxNotification_h__
#define IVxNotification_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"

namespace VxSdk {
    struct IVxRole;

    /// <summary>
    /// Represents a particular notification configuration for a situation.
    /// </summary>
    struct IVxNotification {
    public:
        /// <summary>
        /// Adds a role to the list of roles that this notification serves.
        /// </summary>
        /// <param name="role">The role to add.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of adding the role.</returns>
        virtual VxResult::Value AddRole(IVxRole& role) const = 0;
        /// <summary>
        /// Adds a user to the list of users that this notification serves.
        /// </summary>
        /// <param name="user">The user to add.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of adding the user.</returns>
        virtual VxResult::Value AddUser(IVxUser& user) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this Notification from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the Notification.</returns>
        virtual VxResult::Value DeleteNotification() const = 0;
        /// <summary>
        /// Gets the roles that will receive this notification.
        /// <para>Available filters: kAdvancedQuery, kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="roleCollection">The roles that will receive this notification.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRoles(VxCollection<IVxRole**>& roleCollection) const = 0;
        /// <summary>
        /// Gets the users that will receive this notification.
        /// <para>Available filters: kAdvancedQuery, kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="userCollection">The users that will receive this notification.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUsers(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Removes a role from the list of roles that this notification serves.
        /// </summary>
        /// <param name="role">The role to remove.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of removing the role.</returns>
        virtual VxResult::Value RemoveRole(IVxRole& role) = 0;
        /// <summary>
        /// Removes a user from the list of users that this notification serves.
        /// </summary>
        /// <param name="user">The role to user.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of removing the user.</returns>
        virtual VxResult::Value RemoveUser(IVxUser& user) = 0;

    public:
        /// <summary>
        /// The unique identifier of the notification.
        /// </summary>
        char id[64];
        /// <summary>
        /// The ids for each role that should receive this notification.
        /// </summary>
        char** roleIds;
        /// <summary>
        /// The ids for each user that should receive this notification.
        /// </summary>
        char** userIds;
        /// <summary>
        /// The size of <see cref="roleIds"/>.
        /// </summary>
        int roleIdSize;
        /// <summary>
        /// The size of <see cref="userIds"/>.
        /// </summary>
        int userIdSize;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            this->roleIds = nullptr;
            this->userIds = nullptr;
            this->roleIdSize = 0;
            this->userIdSize = 0;
        }
    };
}
#endif // IVxNotification_h__
