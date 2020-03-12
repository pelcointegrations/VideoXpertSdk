#ifndef VxNewVolumeGroup_h__
#define VxNewVolumeGroup_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new volume group to be created.
    /// </summary>
    struct VxNewVolumeGroup {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewVolumeGroup"/> struct.
        /// </summary>
        VxNewVolumeGroup() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewVolumeGroup"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewVolumeGroup(const VxNewVolumeGroup& ref) {
            this->isArchiveGroup = ref.isArchiveGroup;
            Utilities::StrCopySafe(this->name, ref.name);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewVolumeGroup"/> class.
        /// </summary>
        ~VxNewVolumeGroup() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isArchiveGroup = false;
            VxZeroArray(this->name);
        }

    public:
        /// <summary>
        /// Indicates whether or not this volume group is an "archive volume group", which will act as storage for the
        /// oldest available data.
        /// </summary>
        bool isArchiveGroup;
        /// <summary>
        /// The friendly name of this volume group.
        /// </summary>
        char name[64];
    };
}

#endif // VxNewVolumeGroup_h__