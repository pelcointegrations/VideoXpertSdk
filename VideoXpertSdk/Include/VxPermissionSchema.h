#ifndef VxPermissionSchema_h__
#define VxPermissionSchema_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents static system permission information in a machine-readable manner. This indicates
    /// permission groups, hierarchy, and resource restriction information.
    /// </summary>
    struct VxPermissionSchema {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxPermissionSchema"/> struct.
        /// </summary>
        VxPermissionSchema() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxPermissionSchema"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxPermissionSchema(const VxPermissionSchema& ref) {
            this->permissionId = ref.permissionId;
            this->isGroup = ref.isGroup;
            this->permissionsSize = ref.permissionsSize;
            this->permissions = nullptr;
            if (ref.permissions != nullptr) {
                this->permissions = new VxPermissionSchema*[ref.permissionsSize];
                for(int i = 0; i < ref.permissionsSize; i++)
                    this->permissions[i] = new VxPermissionSchema(*ref.permissions[i]);
            }

            this->restrictionsSize = ref.restrictionsSize;
            this->restrictions = nullptr;
            if (ref.restrictions != nullptr) {
                this->restrictions = new VxResourceType::Value[ref.restrictionsSize];
                for (int i = 0; i < ref.restrictionsSize; i++) {
                    this->restrictions[i] = ref.restrictions[i];
                }
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxPermissionSchema"/> class.
        /// </summary>
        ~VxPermissionSchema() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isGroup = false;
            this->permissionId = VxPermissionId::kUnknown;
            this->permissionsSize = 0;
            this->restrictionsSize = 0;
            this->permissions = nullptr;
            this->restrictions = nullptr;
        }

    public:
        /// <summary>
        /// <c>true</c> if this represents a permission group; <c>false</c> indicates this is a permission.
        /// </summary>
        bool isGroup;
        /// <summary>
        /// The permission being granted by this field or field group.
        /// </summary>
        VxPermissionId::Value permissionId;
        /// <summary>
        /// Specifies the resource types that may be restricted by this permission, if any.
        /// </summary>
        VxResourceType::Value* restrictions;
        /// <summary>
        /// The size of <see cref="permissions"/>.
        /// </summary>
        int permissionsSize;
        /// <summary>
        /// The size of <see cref="restrictions"/>.
        /// </summary>
        int restrictionsSize;
        /// <summary>
        /// Recursive list of permission schema. Indicates permission hierarchy; nested items are children while
        /// containing items are parents.
        /// </summary>
        VxPermissionSchema** permissions;
    };
}

#endif // VxPermissionSchema_h__