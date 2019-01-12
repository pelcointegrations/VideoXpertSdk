#ifndef VxPhoneNumber_h__
#define VxPhoneNumber_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a telephone number for a user.
    /// </summary>
    struct VxPhoneNumber {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxPhoneNumber"/> struct.
        /// </summary>
        VxPhoneNumber() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxPhoneNumber"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxPhoneNumber(const VxPhoneNumber& ref) {
            Utilities::StrCopySafe(this->number, ref.number);
            this->type = ref.type;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxPhoneNumber"/> class.
        /// </summary>
        ~VxPhoneNumber() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->number);
            this->type = VxPhoneType::kOther;
        }

    public:
        /// <summary>
        /// The phone number.
        /// </summary>
        char number[64];
        /// <summary>
        /// The type of phone number.
        /// </summary>
        VxPhoneType::Value type;
    };
}

#endif // VxPhoneNumber_h__
