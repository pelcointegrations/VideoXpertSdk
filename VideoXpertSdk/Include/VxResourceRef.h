#ifndef VxResourceRef_h__
#define VxResourceRef_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a reference to a resource on the VideoXpert system (i.e. a device, datasource, tag, etc.).
    /// </summary>
    struct VxResourceRef {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxResourceRef"/> struct.
        /// </summary>
        VxResourceRef() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxResourceRef"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxResourceRef(const VxResourceRef& ref) {
            Utilities::StrCopySafe(this->id, ref.id);
            this->type = ref.type;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxResourceRef"/> class.
        /// </summary>
        ~VxResourceRef() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            this->type = VxResourceType::kUnknown;
        }

    public:
        /// <summary>
        /// The unique resource identifier. This must match exactly with the unique identifier of the resource being
        /// referenced.
        /// </summary>
        char id[64];
        /// <summary>
        /// The type of resource being referenced.
        /// </summary>
        VxResourceType::Value type;
    };
}

#endif // VxResourceRef_h__