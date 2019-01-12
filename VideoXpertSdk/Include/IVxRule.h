#ifndef IVxRule_h__
#define IVxRule_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxTimeTable.h"
#include "VxRuleTrigger.h"

namespace VxSdk {
    /// <summary>
    /// Represents a set of rule triggers that, when any occur during times when the rule is active, cause a script to
    /// run. A rule can be read as follows: "If enabled, when any specified triggers occur during specified times, run
    /// the associated script."
    /// </summary>
    struct IVxRule {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this rule from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the rule.</returns>
        virtual VxResult::Value DeleteRule() const = 0;
        /// <summary>
        /// Disable this rule.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this rule.</returns>
        virtual VxResult::Value Disable() = 0;
        /// <summary>
        /// Enable this rule.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of enabling this rule.</returns>
        virtual VxResult::Value Enable() = 0;
        /// <summary>
        /// Gets the script to run when this rule is triggered.
        /// </summary>
        /// <param name="script">The script data.</param>
        /// <param name="size">The size of <paramref name="script"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetScript(char* script, int& size) const = 0;
        /// <summary>
        /// Gets the time tables used by this rule.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="timeTableCollection">A <see cref="VxCollection"/> of time tables used by this rule.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTimeTables(VxCollection<IVxTimeTable**>& timeTableCollection) const = 0;
        /// <summary>
        /// Halt the script that this rule is running, if any. This has no effect if the script is not currently
        /// running.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of enabling thisdata source.</returns>
        virtual VxResult::Value HaltScript() = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the script to run when this rule is triggered.
        /// </summary>
        /// <param name="script">The new script value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the script.</returns>
        virtual VxResult::Value SetScript(char* script) = 0;
        /// <summary>
        /// Sets the timeTableIds property.
        /// </summary>
        /// <param name="timeTableIds">The new timeTableIds value.</param>
        /// <param name="timeTableIdSize">The size of <see cref="timeTableIds"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTimeTables(char** timeTableIds, int timeTableIdSize) = 0;
        /// <summary>
        /// Sets the triggers property.
        /// </summary>
        /// <param name="triggers">The new triggers value.</param>
        /// <param name="triggerSize">The size of <see cref="triggers"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTriggers(VxRuleTrigger** triggers, int triggerSize) = 0;

    public:
        /// <summary>
        /// Indicates whether or not this rule is enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The unique identifier of the rule.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the rule.
        /// </summary>
        char name[64];
        /// <summary>
        /// The unique identifiers of the time tables used by this rule. This rule will only automatically run its
        /// script if a trigger occurs during the times contained by the time tables specified here. If empty, no
        /// active time ranges are available for this rule (it must be manually triggered). If null, no time filters
        /// will be applied (the new rule is always active).
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
        VxRuleTrigger** triggers;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isEnabled = false;
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->timeTableIds = nullptr;
            this->timeTableIdSize = 0;
            this->triggerSize = 0;
            this->triggers = nullptr;
        }
    };
}
#endif // IVxRule_h__
