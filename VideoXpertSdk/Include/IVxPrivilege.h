#ifndef IVxPrivilege_h__
#define IVxPrivilege_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"

namespace VxSdk {
    struct IVxUser;

    /// <summary>
    /// Represents a specific permission that is given to a role.
    /// </summary>
    struct IVxPrivilege {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Removes this privilege from the associated role.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this privilege.</returns>
        virtual VxResult::Value DeletePrivilege() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the data sources associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceCollection">The devices associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the drawings associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="drawingCollection">The drawings associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDrawing**>& drawingCollection) const = 0;
        /// <summary>
        /// Gets the relay outputs associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="relayOutputCollection">The relay outputs associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxRelayOutput**>& relayOutputCollection) const = 0;
        /// <summary>
        /// Gets the users associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="userCollection">The users associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Gets the relative priority for the privilege.
        /// </summary>
        /// <param name="priority">The priority level for the privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPriority(int& priority) const = 0;
        /// <summary>
        /// Gets the restriction level for this privilege.
        /// </summary>
        /// <param name="isRestricted"><c>true</c> if restricted, <c>false</c> if not.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRestricted(bool& isRestricted) const = 0;
        /// <summary>
        /// Gets the data sources not associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources not associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUnLinked(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices not associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceCollection">The devices not associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUnLinked(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the drawings not associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="drawingCollection">The drawings not associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUnLinked(VxCollection<IVxDrawing**>& drawingCollection) const = 0;
        /// <summary>
        /// Gets the relay outputs not associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="relayOutputCollection">The relay outputs not associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUnLinked(VxCollection<IVxRelayOutput**>& relayOutputCollection) const = 0;
        /// <summary>
        /// Gets the users not associated with this privilege.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="userCollection">The users not associated with this privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUnLinked(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Associates a data source with this privilege. If the data source is deleted, the association with this
        /// privilege shall also be removed.
        /// </summary>
        /// <param name="dataSource">The data source to associate the privilege with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Associates a device with this privilege. If the device is deleted, the association with this privilege
        /// shall also be removed.
        /// </summary>
        /// <param name="device">The device to associate the privilege with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDevice& device) const = 0;
        /// <summary>
        /// Associates a drawing with this privilege. If the drawing is deleted, the association with this privilege
        /// shall also be removed.
        /// </summary>
        /// <param name="drawing">The drawing to associate the privilege with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDrawing& drawing) const = 0;
        /// <summary>
        /// Associates a relay output with this privilege. If the relay output is deleted, the association with this
        /// privilege shall also be removed.
        /// </summary>
        /// <param name="relayOutput">The relay output to associate the privilege with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxRelayOutput& relayOutput) const = 0;
        /// <summary>
        /// Associates a user with this privilege. If the user is deleted, the association with
        /// this privilege shall also be removed.
        /// </summary>
        /// <param name="user">The user to associate the privilege with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxUser& user) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets whether the privilege is excluded from the associated resources.
        /// </summary>
        /// <param name="excludeRestricted">
        /// <c>true</c> to exclude this privilege from associated resources, otherwise <c>false</c>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetExcludeRestricted(bool excludeRestricted) = 0;
        /// <summary>
        /// Sets the relative priority for the privilege, from 1 to 250. Smaller numbers have higher priority than
        /// larger numbers (e.g. 1 is the highest priority).
        /// </summary>
        /// <param name="priority">The priority level for the privilege.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetPriority(int priority) const = 0;
        /// <summary>
        /// Sets the restriction level for this privilege to the associated resources.
        /// </summary>
        /// <param name="isRestricted"><c>true</c> if restricted, <c>false</c> if not.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetRestricted(bool isRestricted) const = 0;
        /// <summary>
        /// Removes a data source association from this privilege.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Removes a device association from this privilege.
        /// </summary>
        /// <param name="device">The device to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDevice& device) const = 0;
        /// <summary>
        /// Removes a drawing association from this privilege.
        /// </summary>
        /// <param name="drawing">The drawing to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDrawing& drawing) const = 0;
        /// <summary>
        /// Removes a relay output association from this privilege.
        /// </summary>
        /// <param name="relayOutput">The relay output to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxRelayOutput& relayOutput) const = 0;
        /// <summary>
        /// Removes a user association from this privilege.
        /// </summary>
        /// <param name="user">The user to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxUser& user) const = 0;

    public:
        /// <summary>
        /// Indicates whether the privilege is excluded from the associated resources.
        /// </summary>
        bool excludeRestricted;
        /// <summary>
        /// The unique identifier of the privilege.
        /// </summary>
        char id[64];
        /// <summary>
        /// The permission being granted by this privilege.
        /// </summary>
        VxPermissionId::Value permissionId;
        /// <summary>
        /// The resource type supported by this privilege, if any.
        /// </summary>
        VxResourceType::Value resourceType;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->excludeRestricted = false;
            VxZeroArray(this->id);
            this->permissionId = VxPermissionId::kUnknown;
            this->resourceType = VxResourceType::kUnknown;
        }
    };
}

#endif // IVxPrivilege_h__
