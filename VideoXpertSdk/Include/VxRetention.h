#ifndef VxRetention_h__
#define VxRetention_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxResourceRef.h"

namespace VxSdk {
    /// <summary>
    /// Represents retention information for a referenced resource.
    /// </summary>
    struct VxRetention {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxRetention"/> struct.
        /// </summary>
        VxRetention() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxRetention"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxRetention(const VxRetention& ref) {
            Utilities::StrCopySafe(this->oldestRecording, ref.oldestRecording);
            this->resourceRef = ref.resourceRef;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxRetention"/> class.
        /// </summary>
        ~VxRetention() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->oldestRecording);
            this->resourceRef.Clear();
        }

    public:
        /// <summary>
        /// The time of the oldest recording for the resource.
        /// </summary>
        char oldestRecording[64];
        /// <summary>
        /// The reference to the resource.
        /// </summary>
        VxResourceRef resourceRef;
    };
}

#endif // VxRetention_h__