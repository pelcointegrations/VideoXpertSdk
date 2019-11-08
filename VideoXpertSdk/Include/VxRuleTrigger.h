#ifndef VxRuleTrigger_h__
#define VxRuleTrigger_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxResourceRef.h"

namespace VxSdk {
    /// <summary>
    /// Represents a condition in a rule that, if <c>true</c>, causes the rule to run its script (if triggered during
    /// an active time of the rule).
    /// </summary>
    struct VxRuleTrigger {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxRuleTrigger"/> struct.
        /// </summary>
        VxRuleTrigger() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxRuleTrigger"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxRuleTrigger(const VxRuleTrigger& ref) {
            Utilities::StrCopySafe(this->situationType, ref.situationType);
            this->sourceRefSize = ref.sourceRefSize;
            this->sourceRef = nullptr;
            if (ref.sourceRef != nullptr) {
                this->sourceRef = new VxResourceRef[ref.sourceRefSize];
                for(int i = 0; i < ref.sourceRefSize; i++)
                    this->sourceRef[i] = VxResourceRef(ref.sourceRef[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxRuleTrigger"/> class.
        /// </summary>
        ~VxRuleTrigger() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->situationType);
            this->sourceRefSize = 0;
            this->sourceRef = nullptr;
        }

    public:
        /// <summary>
        /// The situation type. This trigger will be checked each time this type of situation occurs. If empty, this
        /// trigger will always be inactive.
        /// </summary>
        char situationType[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The size of <see cref="sourceRef"/>.
        /// </summary>
        int sourceRefSize;
        /// <summary>
        /// The resource reference that this trigger is associated with. Limited to one resource only. If empty, no
        /// source filter will be applied (all sources are valid).
        /// <para>
        /// Supported resources are limited to the following resource types: kDataSource, kDevice, kDataStorage, and
        /// kTag. This trigger will evaluate to <c>true</c> only if its event source matches one of these sources. If
        /// the type is a device, this will match against the events source device id. If the type is a data source,
        /// this will match against the service_property_id value within the event properties. Finally, if a source is
        /// a tag, this will match against the tag applied to the situations service type.
        /// </para>
        /// </summary>
        VxResourceRef* sourceRef;
    };
}

#endif // VxRuleTrigger_h__