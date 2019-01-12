#ifndef VxNewUser_h__
#define VxNewUser_h__

#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxPhoneNumber.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new user to be created.
    /// </summary>
    struct VxNewUser {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        VxNewUser() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewUser(const VxNewUser& ref) {
            this->mustChangePassword = ref.mustChangePassword;
            Utilities::StrCopySafe(this->domain, ref.domain);
            Utilities::StrCopySafe(this->email, ref.email);
            Utilities::StrCopySafe(this->employeeId, ref.employeeId);
            Utilities::StrCopySafe(this->firstName, ref.firstName);
            Utilities::StrCopySafe(this->lastName, ref.lastName);
            Utilities::StrCopySafe(this->name, ref.name);
            Utilities::StrCopySafe(this->note, ref.note);
            Utilities::StrCopySafe(this->password, ref.password);
            this->phoneNumberSize = ref.phoneNumberSize;
            this->phoneNumbers = nullptr;
            if (ref.phoneNumbers != nullptr) {
                this->phoneNumbers = new VxPhoneNumber[ref.phoneNumberSize];
                for(int i = 0; i < ref.phoneNumberSize; i++)
                    this->phoneNumbers[i] = VxPhoneNumber(ref.phoneNumbers[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewUser"/> struct.
        /// </summary>
        ~VxNewUser() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->mustChangePassword = false;
            VxZeroArray(this->domain);
            VxZeroArray(this->email);
            VxZeroArray(this->employeeId);
            VxZeroArray(this->firstName);
            VxZeroArray(this->lastName);
            VxZeroArray(this->name);
            VxZeroArray(this->note);
            VxZeroArray(this->password);
            this->phoneNumberSize = 0;
            this->phoneNumbers = nullptr;
        }

    public:
        /// <summary>
        /// If <c>true</c>, the new user will be forced to change their password the first time they log in.
        /// </summary>
        bool mustChangePassword;
        /// <summary>
        /// The network domain for the user. Defaults to LOCAL.
        /// </summary>
        char domain[64];
        /// <summary>
        /// The email address of the user.
        /// </summary>
        char email[256];
        /// <summary>
        /// The employee identifier associated with the user.
        /// </summary>
        char employeeId[64];
        /// <summary>
        /// The first name of user.
        /// </summary>
        char firstName[64];
        /// <summary>
        /// The last name of user.
        /// </summary>
        char lastName[64];
        /// <summary>
        /// The unique name of the user that this resource is representing.
        /// </summary>
        char name[64];
        /// <summary>
        /// Supplemental information about the user.
        /// </summary>
        char note[1024];
        /// <summary>
        /// The password to associate with the user. Must contain more than 7 characters.
        /// </summary>
        char password[64];
        /// <summary>
        /// The size of <see cref="phoneNumbers"/>.
        /// </summary>
        int phoneNumberSize;
        /// <summary>
        /// The telephone number(s) for the user.
        /// </summary>
        VxPhoneNumber* phoneNumbers;
    };
}

#endif // VxNewUser_h__