#ifndef VxNewNotification_h__
#define VxNewNotification_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new notification configuration for a situation.
    /// </summary>
    struct VxNewNotification {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewNotification"/> struct.
        /// </summary>
        VxNewNotification() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewNotification"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewNotification(const VxNewNotification& ref) {
            this->roleIdSize = ref.roleIdSize;
            this->roleIds = nullptr;
            if (ref.roleIds != nullptr) {
                this->roleIds = new char*[ref.roleIdSize];
                for (int i = 0; i < ref.roleIdSize; i++) {
                    const size_t len = strlen(ref.roleIds[i]) + 1;
                    this->roleIds[i] = new char[len];
                    Utilities::StrCopySafe(this->roleIds[i], ref.roleIds[i], len);
                }
            }

            this->userIdSize = ref.userIdSize;
            this->userIds = nullptr;
            if (ref.userIds != nullptr) {
                this->userIds = new char* [ref.userIdSize];
                for (int i = 0; i < ref.userIdSize; i++) {
                    const size_t len = strlen(ref.userIds[i]) + 1;
                    this->userIds[i] = new char[len];
                    Utilities::StrCopySafe(this->userIds[i], ref.userIds[i], len);
                }
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewNotification"/> class.
        /// </summary>
        ~VxNewNotification() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->roleIds = nullptr;
            this->userIds = nullptr;
            this->roleIdSize = 0;
            this->userIdSize = 0;
        }

    public:
        /// <summary>
        /// The ids for each role that should receive this notification.
        /// </summary>
        char** roleIds;
        /// <summary>
        /// The ids for each user that should receive this notification.
        /// </summary>
        char** userIds;
        /// <summary>
        /// The size of <see cref="roleIds"/>.
        /// </summary>
        int roleIdSize;
        /// <summary>
        /// The size of <see cref="userIds"/>.
        /// </summary>
        int userIdSize;
    };
}

#endif // VxNewNotification_h__