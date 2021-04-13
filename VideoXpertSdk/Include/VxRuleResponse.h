#ifndef VxRuleResponse_h__
#define VxRuleResponse_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a rule response. The response may be configured to either execute a Groovy script or generate an
    /// event in the system when triggered.
    /// </summary>
    struct VxRuleResponse {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxRuleResponse"/> struct.
        /// </summary>
        VxRuleResponse() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxRuleResponse"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxRuleResponse(const VxRuleResponse& ref) {
            this->isCustomScript = ref.isCustomScript;
            Utilities::StrCopySafe(this->situationType, ref.situationType);
            this->usedSourceEventFieldsSize = ref.usedSourceEventFieldsSize;
            this->usedSourceEventFields = nullptr;
            if (ref.usedSourceEventFields != nullptr) {
                this->usedSourceEventFields = new char* [ref.usedSourceEventFieldsSize];
                for (int i = 0; i < ref.usedSourceEventFieldsSize; i++) {
                    const size_t len = strlen(ref.usedSourceEventFields[i]) + 1;
                    this->usedSourceEventFields[i] = new char[len];
                    Utilities::StrCopySafe(this->usedSourceEventFields[i], ref.usedSourceEventFields[i], len);
                }
            }

            this->script = nullptr;
            if (ref.script != nullptr)
                this->script = _strdup(ref.script);
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxRuleResponse"/> class.
        /// </summary>
        ~VxRuleResponse() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isCustomScript = false;
            this->usedSourceEventFieldsSize = 0;
            this->script = nullptr;
            VxZeroArray(this->situationType);
            this->usedSourceEventFields = nullptr;
        }

    public:
        /// <summary>
        /// If <c>true</c>, indicates that this response is a custom script and will ignore the situationType and
        /// usedSourceEventFields fields. If <c>false</c>, indicates that this response will generate an event and
        /// will ignore the script field.
        /// </summary>
        bool isCustomScript;
        /// <summary>
        /// The Groovy script to run when the rule triggers. If this script is triggered by an event, its
        /// properties will be available in the script’s eventProperties variable.
        /// Ignored if <c>isCustomScript</c> is <c>false</c>.
        /// </summary>
        char* script;
        /// <summary>
        /// The type of the situation to generate an event for. Ignored if <c>isCustomScript</c> is <c>true</c>.
        /// </summary>
        char situationType[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// List of fields from the source event to copy to the generated event. The event time is always copied.
        /// Restricted to severity, source_device_id, properties. Ignored if <c>isCustomScript</c> is <c>true</c>.
        /// </summary>
        char** usedSourceEventFields;
        /// <summary>
        /// The size of <see cref="usedSourceEventFields"/>.
        /// </summary>
        int usedSourceEventFieldsSize;
    };
}

#endif // VxRuleResponse_h__