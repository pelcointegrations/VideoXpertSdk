#ifndef VxNewTag_h__
#define VxNewTag_h__

#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new tag to be created.
    /// </summary>
    struct VxNewTag {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewTag"/> struct.
        /// </summary>
        VxNewTag() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewTag"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewTag(const VxNewTag& ref) {
            this->isFolder = ref.isFolder;
            this->isPublic = ref.isPublic;
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->parentId, ref.parentId);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewTag"/> class.
        /// </summary>
        ~VxNewTag() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isFolder = false;
            this->isPublic = true;
            VxZeroArray(this->name);
            VxZeroArray(this->parentId);
        }

    public:
        /// <summary>
        /// Indicates whether the new tag will be a folder tag.
        /// </summary>
        bool isFolder;
        /// <summary>
        /// Indicates whether the new tag will not be owned (public) or will be owned by the user submitting the
        /// request (private). Not applicable if this is a folder tag.
        /// </summary>
        bool isPublic;
        /// <summary>
        /// The unique friendly name of the tag.
        /// </summary>
        /// <remarks>Commas are invalid characters for this field and MUST NOT be used.</remarks>
        char name[64];
        /// <summary>
        /// The unique identifier of the tag that is the parent of this tag. If this is provided on a non-folder tag,
        /// it will be ignored.
        /// </summary>
        char parentId[64];
    };
}

#endif // VxNewTag_h__
