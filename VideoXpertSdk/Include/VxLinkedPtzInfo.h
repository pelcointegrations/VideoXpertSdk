#ifndef VxLinkedPtzInfo_h__
#define VxLinkedPtzInfo_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents linked PTZ information.
    /// </summary>
    struct VxLinkedPtzInfo {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLinkedPtzInfo"/> struct.
        /// </summary>
        VxLinkedPtzInfo() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLinkedPtzInfo"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLinkedPtzInfo(const VxLinkedPtzInfo& ref) {
            Utilities::StrCopySafe(this->ip, ref.ip);
            Utilities::StrCopySafe(this->name, ref.name);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLinkedPtzInfo"/> class.
        /// </summary>
        ~VxLinkedPtzInfo() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->ip);
            VxZeroArray(this->name);
        }

    public:
        /// <summary>
        /// The IP of the tracking data source.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The name of the tracking data source.
        /// </summary>
        char name[64];
    };
}

#endif // VxLinkedPtzInfo_h__