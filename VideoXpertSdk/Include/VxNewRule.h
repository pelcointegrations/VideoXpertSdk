#ifndef VxNewRule_h__
#define VxNewRule_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxRuleTrigger.h"

namespace VxSdk {
    /// <summary>
    /// Represents a new rule to be created.
    /// </summary>
    struct VxNewRule {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewRule"/> struct.
        /// </summary>
        VxNewRule() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewRule"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewRule(const VxNewRule& ref) {
            this->isEnabled = ref.isEnabled;
            Utilities::StrCopySafe(this->name, ref.name);
            this->script = ref.script;
            this->timeTableIdSize = ref.timeTableIdSize;
            this->timeTableIds = nullptr;
            if (ref.timeTableIds != nullptr) {
                this->timeTableIds = new char*[ref.timeTableIdSize];
                for (int i = 0; i < ref.timeTableIdSize; i++) {
                    const size_t len = strlen(ref.timeTableIds[i]) + 1;
                    this->timeTableIds[i] = new char[len];
                    Utilities::StrCopySafe(this->timeTableIds[i], ref.timeTableIds[i], len);
                }
            }

            this->triggerSize = ref.triggerSize;
            this->triggers = nullptr;
            if (ref.triggers != nullptr) {
                this->triggers = new VxRuleTrigger[ref.triggerSize];
                for(int i = 0; i < ref.triggerSize; i++)
                    this->triggers[i] = VxRuleTrigger(ref.triggers[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewRule"/> class.
        /// </summary>
        ~VxNewRule() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isEnabled = false;
            VxZeroArray(this->name);
            this->script = nullptr;
            this->timeTableIds = nullptr;
            this->timeTableIdSize = 0;
            this->triggerSize = 0;
            this->triggers = nullptr;
        }

    public:
        /// <summary>
        /// Indicates whether or not this rule is enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The friendly name of the rule.
        /// </summary>
        char name[64];
        /// <summary>
        /// The script to run when the rule is triggered.
        /// </summary>
        char* script;
        /// <summary>
        /// The unique identifiers of the time tables that will be associated with this rule. The rule will only
        /// automatically run its script if a trigger occurs during the times contained by the time tables specified
        /// here. If empty, no active time ranges are available for this rule (it must be manually triggered). If null,
        /// no time filters will be applied (the new rule is always active).
        /// </summary>
        char** timeTableIds;
        /// <summary>
        /// The size of <see cref="timeTableIds"/>.
        /// </summary>
        int timeTableIdSize;
        /// <summary>
        /// The size of <see cref="triggers"/>.
        /// </summary>
        int triggerSize;
        /// <summary>
        /// The triggers that, when any activate, cause the rule to run its script. If empty or null, this rule must be
        /// manually triggered.
        /// </summary>
        VxRuleTrigger* triggers;
    };
}

#endif // VxNewRule_h__