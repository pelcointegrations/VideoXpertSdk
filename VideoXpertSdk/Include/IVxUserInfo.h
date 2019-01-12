#ifndef IVxUserInfo_h__
#define IVxUserInfo_h__

#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPhoneNumber.h"

namespace VxSdk {
    /// <summary>
    /// Represents general information about a user.
    /// </summary>
    struct IVxUserInfo {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;

    public:
        /// <summary>
        /// The employee identifier associated with the user.
        /// </summary>
        char employeeId[64];
        /// <summary>
        /// The first name of the user.
        /// </summary>
        char firstName[64];
        /// <summary>
        /// The last name of the user.
        /// </summary>
        char lastName[64];
        /// <summary>
        /// Gets the friendly name, within the domain, of the user.
        /// </summary>
        char name[64];
        /// <summary>
        /// Supplemental information about the user.
        /// </summary>
        char note[1024];
        /// <summary>
        /// The size of <see cref="phoneNumbers"/>.
        /// </summary>
        int phoneNumberSize;
        /// <summary>
        /// The telephone number(s) for the user.
        /// </summary>
        VxPhoneNumber** phoneNumbers;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->employeeId);
            VxZeroArray(this->firstName);
            VxZeroArray(this->lastName);
            VxZeroArray(this->name);
            VxZeroArray(this->note);
            this->phoneNumberSize = 0;
            this->phoneNumbers = nullptr;
        }
    };
}

#endif // IVxUserInfo_h__
