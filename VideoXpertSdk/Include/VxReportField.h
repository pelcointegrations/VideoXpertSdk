#ifndef VxReportField_h__
#define VxReportField_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a field or field group within a report.
    /// </summary>
    struct VxReportField {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxReportField"/> struct.
        /// </summary>
        VxReportField() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxReportField"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxReportField(const VxReportField& ref) {
            Utilities::StrCopySafe(this->name, ref.name);
            this->type = ref.type;
            this->isEnabled = ref.isEnabled;
            this->subfieldSize = ref.subfieldSize;
            this->subfields = nullptr;
            if (ref.subfields != nullptr) {
                this->subfields = new VxReportField[ref.subfieldSize];
                for(int i = 0; i < ref.subfieldSize; i++)
                    this->subfields[i] = VxReportField(ref.subfields[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxReportField"/> class.
        /// </summary>
        ~VxReportField() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isEnabled = false;
            VxZeroArray(this->name);
            this->type = VxReportFieldType::kUnknown;
            this->subfieldSize = 0;
            this->subfields = nullptr;
        }

    public:
        /// <summary>
        /// <c>true</c> to include this field in the report; <c>false</c> to omit it.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The friendly name of this field or field group.
        /// </summary>
        char name[64];
        /// <summary>
        /// The report field type of this field or field group.
        /// </summary>
        VxReportFieldType::Value type;
        /// <summary>
        /// The size of <see cref="subfields"/>.
        /// </summary>
        int subfieldSize;
        /// <summary>
        /// The list of report field subfields. If set, indicates that this is a field group.
        /// </summary>
        VxReportField* subfields;
    };
}

#endif // VxReportField_h__