#ifndef VxLicenseSupEvent_h__
#define VxLicenseSupEvent_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a specific event that occurred for a software upgrade plan.
    /// </summary>
    struct VxLicenseSupEvent {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLicenseSupEvent"/> struct.
        /// </summary>
        VxLicenseSupEvent() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLicenseSupEvent"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLicenseSupEvent(const VxLicenseSupEvent& ref) {
            Utilities::StrCopySafe(this->expirationTime, ref.expirationTime);
			Utilities::StrCopySafe(this->time, ref.time);
			this->currentBalance = ref.currentBalance;
            this->value = ref.value;
			this->type = ref.type;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLicenseSupEvent"/> class.
        /// </summary>
        ~VxLicenseSupEvent() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->expirationTime);
			VxZeroArray(this->time);
			this->currentBalance = 0;
            this->value = 0;
            this->type = VxSupEventType::kUnknown;
        }

    public:
        /// <summary>
        /// The projected expiration of the software upgrade plan (at the time of this event).
        /// </summary>
        char expirationTime[64];
        /// <summary>
        /// The time at which this event occurred.
        /// </summary>
        char time[64];
        /// <summary>
        /// The current number of channel-years available (at the time of this event).
        /// </summary>
        float currentBalance;
        /// <summary>
        /// A numerical value that provides additional data related to the type of event this is.
        /// </summary>
        float value;
        /// <summary>
        /// The type of software upgrade plan event.
        /// </summary>
        VxSupEventType::Value type;
    };
}

#endif // VxLicenseSupEvent_h__