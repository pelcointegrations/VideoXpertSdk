#ifndef IVxVolumeGroup_h__
#define IVxVolumeGroup_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a group of volumes that can be used together as a storage pool.
    /// </summary>
    struct IVxVolumeGroup {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Removes the volume group. This does not affect the volume within this volume group nor the contents of
        /// those volumes.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DeleteVolumeGroup() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets all possible volume relations for this volume group (both linked and non-linked). Each linked volume
        /// shall be included in the volume group while each non-linked volume shall be excluded. Note that a volume
        /// may only be linked to 1 volume group.
        /// <para>Available filters: kAdvancedQuery, kAllTags, kAllPrivateTags, kLinked.</para>
        /// </summary>
        /// <param name="resourceRelCollection">A <see cref="VxCollection"/> of related resources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetVolumeRelations(VxCollection<IVxResourceRel**>& resourceRelCollection) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the isArchiveGroup property. When <c>true</c> this as an "archive volume group" which will act as
        /// storage for the oldest available data. 
        /// </summary>
        /// <param name="isArchiveGroup"><c>true</c> to set this as an "archive volume group", otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIsArchiveGroup(bool isArchiveGroup) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;

    public:
        /// <summary>
        /// Indicates whether or not this volume group is an "archive volume group", which will act as storage for the
        /// oldest available data.
        /// </summary>
        bool isArchiveGroup;
        /// <summary>
        /// The unique identifier of the volume group.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of this volume group.
        /// </summary>
        char name[64];
        /// <summary>
        /// The size of <see cref="volumes"/>.
        /// </summary>
        int volumesSize;
        /// <summary>
        /// The volumes that constitute this volume group.
        /// </summary>
        IVxVolume** volumes;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isArchiveGroup = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->volumesSize = 0;
            this->volumes = nullptr;  
        }
    };
}

#endif // IVxVolumeGroup_h__
