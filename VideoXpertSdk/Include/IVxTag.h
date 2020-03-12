#ifndef IVxTag_h__
#define IVxTag_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxDataSource.h"

namespace VxSdk {
    /// <summary>
    /// Represents a non-hierarchical identifier typically associated with one or more resources (i.e. device or data
    /// source). A tag helps to describe a resource and allows it to be found more efficiently.
    /// </summary>
    struct IVxTag {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this tag from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the tag.</returns>
        virtual VxResult::Value DeleteTag() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the data sources associated with this tag.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources associated with this tag.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices associated with this tag.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceCollection">The devices associated with this tag.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxUser"/> that owns this tag, if any.
        /// </summary>
        /// <param name="user">The <see cref="IVxUser"/> that owns this tag.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetOwner(IVxUser*& user) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxTag"/> that is the parent this tag, if any.
        /// </summary>
        /// <param name="tag">The <see cref="IVxTag"/> that is the parent this tag.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetParent(IVxTag*& tag) const = 0;
        /// <summary>
        /// Associates a data source with this tag. If the data source is deleted, the association with this tag shall
        /// also be removed.
        /// </summary>
        /// <param name="dataSource">The data source to associate the tag with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Associates a device with this tag. If the device is deleted, the association with this tag shall also be
        /// removed.
        /// </summary>
        /// <param name="device">The device to associate the tag with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDevice& device) const = 0;
        /// <summary>
        /// Merges this tag into the given tag. All links associated with this tag will be re-associated with the given
        /// tag; this tag will then be deleted.
        /// </summary>
        /// <param name="tag">The tag to merge into.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Merge(IVxTag& tag) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the unique identifier of the tag that is the parent of this tag. Leave blank to remove the current
        /// parent tag.
        /// </summary>
        /// <param name="parentId">The unique identifier of the parent tag, if any.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the parent tag.</returns>
        virtual VxResult::Value SetParentId(char parentId[64]) = 0;
        /// <summary>
        /// Removes a data source association from this tag.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Removes a device association from this tag.
        /// </summary>
        /// <param name="device">The device to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// Indicates whether this tag is part of a folder-like hierarchy where it has a reference to a parent tag or
        /// is a top-level folder tag.
        /// </summary>
        bool isFolder;
        /// <summary>
        /// The unique identifier of the tag.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the tag.
        /// </summary>
        char name[64];
        /// <summary>
        /// The name of the user that owns the tag if private. If not present, indicates that the tag is not owned
        /// (public).
        /// </summary>
        char owner[64];
        /// <summary>
        /// The unique identifier of the parent tag if this tag is a folder tag and is not a top-level folder tag.
        /// </summary>
        char parentId[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isFolder = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->owner);
            VxZeroArray(this->parentId);
        }
    };
}

#endif // IVxTag_h__
