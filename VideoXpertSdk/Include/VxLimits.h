#ifndef VxLimits_h__
#define VxLimits_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a map of limits related to a resource.
    /// <remarks>
    /// A resource will supply a limit for any field that is supported but does not have a valid value available.
    /// The presence of a limit indicates that the associated field is supported, regardless of whether the field
    /// is present in the resource representation or not.
    /// </remarks>
    /// </summary>
    struct VxLimits {
        /// <summary>
        /// Represents the valid values for a boolean field.
        /// </summary>
        struct Boolean {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Boolean"/> struct.
            /// </summary>
            Boolean() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Boolean"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Boolean(const Boolean& ref) {
                this->defaultValue = ref.defaultValue;
                this->hasDefaultValue = ref.hasDefaultValue;
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
                this->optionsSize = ref.optionsSize;
                this->options = nullptr;
                if (ref.options != nullptr) {
                    this->options = new bool[ref.optionsSize];
                    for (int i = 0; i < ref.optionsSize; i++) {
                        this->options[i] = ref.options[i];
                    }
                }
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Boolean"/> class.
            /// </summary>
            ~Boolean() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->defaultValue = false;
                this->hasDefaultValue = false;
                this->options = nullptr;
                VxZeroArray(this->fieldName);
                this->optionsSize = 0;
            }

        public:
            /// <summary>
            /// The field’s default value.
            /// </summary>
            bool defaultValue;
            /// <summary>
            /// <c>true</c> if a <see cref="defaultValue"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasDefaultValue;
            /// <summary>
            /// A list of valid values that may be applied to the field.
            /// If no values are present, this indicates that the field is currently read-only.
            /// </summary>
            bool* options;
            /// <summary>
            /// The name of the field that this boolean limit applies to.
            /// </summary>
            char fieldName[128];
            /// <summary>
            /// The size of <see cref="options"/>.
            /// </summary>
            int optionsSize;
        };

        /// <summary>
        /// Represents the valid values for a numeric float field.
        /// </summary>
        struct Float {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Float"/> struct.
            /// </summary>
            Float() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Float"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Float(const Float& ref) {
                this->hasDefaultValue = ref.hasDefaultValue;
                this->hasMax = ref.hasMax;
                this->hasMin = ref.hasMin;
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
                this->defaultValue = ref.defaultValue;
                this->max = ref.max;
                this->min = ref.min;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Float"/> class.
            /// </summary>
            ~Float() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->hasDefaultValue = false;
                this->hasMax = false;
                this->hasMin = false;
                VxZeroArray(this->fieldName);
                this->defaultValue = 0;
                this->max = 0;
                this->min = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if a <see cref="defaultValue"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasDefaultValue;
            /// <summary>
            /// <c>true</c> if a <see cref="max"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMax;
            /// <summary>
            /// <c>true</c> if a <see cref="min"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMin;
            /// <summary>
            /// The name of the field that this float limit applies to.
            /// </summary>
            char fieldName[128];
            /// <summary>
            /// The field’s default value.
            /// </summary>
            float defaultValue;
            /// <summary>
            /// The field’s maximum valid value.
            /// </summary>
            float max;
            /// <summary>
            /// The field’s minimum valid value.
            /// </summary>
            float min;
        };

        /// <summary>
        /// Represents the valid values for a numeric integer field.
        /// </summary>
        struct Integer {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Integer"/> struct.
            /// </summary>
            Integer() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Integer"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Integer(const Integer& ref) {
                this->hasDefaultValue = ref.hasDefaultValue;
                this->hasMax = ref.hasMax;
                this->hasMin = ref.hasMin;
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
                this->defaultValue = ref.defaultValue;
                this->max = ref.max;
                this->min = ref.min;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Integer"/> class.
            /// </summary>
            ~Integer() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->hasDefaultValue = false;
                this->hasMax = false;
                this->hasMin = false;
                VxZeroArray(this->fieldName);
                this->defaultValue = 0;
                this->max = 0;
                this->min = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if a <see cref="defaultValue"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasDefaultValue;
            /// <summary>
            /// <c>true</c> if a <see cref="max"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMax;
            /// <summary>
            /// <c>true</c> if a <see cref="min"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMin;
            /// <summary>
            /// The name of the field that this integer limit applies to.
            /// </summary>
            char fieldName[128];
            /// <summary>
            /// The field’s default value.
            /// </summary>
            int defaultValue;
            /// <summary>
            /// The field’s maximum valid value.
            /// </summary>
            int max;
            /// <summary>
            /// The field’s minimum valid value.
            /// </summary>
            int min;
        };

        /// <summary>
        /// Represents the valid values for an array field. 
        /// </summary>
        struct List {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="List"/> struct.
            /// </summary>
            List() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="List"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            List(const List& ref) {
                this->hasMaxItems = ref.hasMaxItems;
                this->hasMinItems = ref.hasMinItems;
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
                this->maxItems = ref.maxItems;
                this->minItems = ref.minItems;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="List"/> class.
            /// </summary>
            ~List() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->hasMaxItems = false;
                this->hasMinItems = false;
                VxZeroArray(this->fieldName);
                this->maxItems = 0;
                this->minItems = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if a <see cref="maxItems"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMaxItems;
            /// <summary>
            /// <c>true</c> if a <see cref="minItems"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasMinItems;
            /// <summary>
            /// The name of the field that this list limit applies to.
            /// </summary>
            char fieldName[128];
            /// <summary>
            /// The maximum number of items that may appear in the list.
            /// </summary>
            int maxItems;
            /// <summary>
            /// The minimum number of items that may appear in the list.
            /// </summary>
            int minItems;
        };

        /// <summary>
        /// Represents the valid values for an object field. 
        /// </summary>
        struct Object {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Object"/> struct.
            /// </summary>
            Object() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Object"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Object(const Object& ref) {
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Object"/> class.
            /// </summary>
            ~Object() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->fieldName);
            }

        public:
            /// <summary>
            /// The name of the field that this object limit applies to.
            /// </summary>
            char fieldName[128];
        };

        /// <summary>
        /// Represents the valid values for a string field. 
        /// </summary>
        struct String {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="String"/> struct.
            /// </summary>
            String() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="String"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            String(const String& ref) {
                this->hasDefaultValue = ref.hasDefaultValue;
                Utilities::StrCopySafe(this->defaultValue, ref.defaultValue);
                Utilities::StrCopySafe(this->fieldName, ref.fieldName);
                this->optionsSize = ref.optionsSize;
                this->options = nullptr;
                if (ref.options != nullptr) {
                    this->options = new char* [ref.optionsSize];
                    for (int i = 0; i < ref.optionsSize; i++) {
                        const size_t len = strlen(ref.options[i]) + 1;
                        this->options[i] = new char[len];
                        Utilities::StrCopySafe(this->options[i], ref.options[i], len);
                    }
                }
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="String"/> class.
            /// </summary>
            ~String() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->hasDefaultValue = false;
                VxZeroArray(this->defaultValue);
                VxZeroArray(this->fieldName);
                this->options = nullptr;
                this->optionsSize = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if a <see cref="defaultValue"/> has been set, otherwise <c>false</c>.
            /// </summary>
            bool hasDefaultValue;
            /// <summary>
            /// The field’s default value.
            /// </summary>
            char defaultValue[128];
            /// <summary>
            /// The name of the field that this string limit applies to.
            /// </summary>
            char fieldName[128];
            /// <summary>
            /// A list of valid values that may be applied to the field.
            /// If no values are present, this indicates that the field is currently read-only.
            /// </summary>
            char** options;
            /// <summary>
            /// The size of <see cref="options"/>.
            /// </summary>
            int optionsSize;
        };

    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLimits"/> struct.
        /// </summary>
        VxLimits() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLimits"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLimits(const VxLimits& ref) {
            this->booleanLimitsSize = ref.booleanLimitsSize;
            this->floatLimitsSize = ref.floatLimitsSize;
            this->integerLimitsSize = ref.integerLimitsSize;
            this->listLimitsSize = ref.listLimitsSize;
            this->objectLimitsSize = ref.objectLimitsSize;
            this->stringLimitsSize = ref.stringLimitsSize;
            this->booleanLimits = ref.booleanLimits;
            this->floatLimits = ref.floatLimits;
            this->integerLimits = ref.integerLimits;
            this->listLimits = ref.listLimits;
            this->objectLimits = ref.objectLimits;
            this->stringLimits = ref.stringLimits;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLimits"/> class.
        /// </summary>
        ~VxLimits() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->booleanLimitsSize = 0;
            this->floatLimitsSize = 0;
            this->integerLimitsSize = 0;
            this->listLimitsSize = 0;
            this->objectLimitsSize = 0;
            this->stringLimitsSize = 0;
            this->booleanLimits = nullptr;
            this->floatLimits = nullptr;
            this->integerLimits = nullptr;
            this->listLimits = nullptr;
            this->objectLimits = nullptr;
            this->stringLimits = nullptr;
        }

    public:
        /// <summary>
        /// The size of <see cref="booleanLimits"/>.
        /// </summary>
        int booleanLimitsSize;
        /// <summary>
        /// The size of <see cref="floatLimits"/>.
        /// </summary>
        int floatLimitsSize;
        /// <summary>
        /// The size of <see cref="integerLimits"/>.
        /// </summary>
        int integerLimitsSize;
        /// <summary>
        /// The size of <see cref="listLimits"/>.
        /// </summary>
        int listLimitsSize;
        /// <summary>
        /// The size of <see cref="objectLimits"/>.
        /// </summary>
        int objectLimitsSize;
        /// <summary>
        /// The size of <see cref="stringLimits"/>.
        /// </summary>
        int stringLimitsSize;
        /// <summary>
        /// The collection of boolean limits.
        /// </summary>
        Boolean* booleanLimits;
        /// <summary>
        /// The collection of float limits.
        /// </summary>
        Float* floatLimits;
        /// <summary>
        /// The collection of integer limits.
        /// </summary>
        Integer* integerLimits;
        /// <summary>
        /// The collection of list limits.
        /// </summary>
        List* listLimits;
        /// <summary>
        /// The collection of object limits.
        /// </summary>
        Object* objectLimits;
        /// <summary>
        /// The collection of string limits.
        /// </summary>
        String* stringLimits;

    };
}

#endif // VxLimits_h__
