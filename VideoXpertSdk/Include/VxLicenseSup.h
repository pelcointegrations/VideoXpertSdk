#ifndef VxLicenseSup_h__
#define VxLicenseSup_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxLicenseSupEvent.h"

namespace VxSdk {
    /// <summary>
    /// Represents software upgrade plan licensing information.
    /// </summary>
    struct VxLicenseSup {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLicenseSup"/> struct.
        /// </summary>
        VxLicenseSup() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLicenseSup"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLicenseSup(const VxLicenseSup& ref) {
            Utilities::StrCopySafe(this->expirationTime, ref.expirationTime);
            this->catchUpCount = ref.catchUpCount;
            this->extensionYearCount = ref.extensionYearCount;
			this->currentBalance = ref.currentBalance;
            this->eventsSize = ref.eventsSize;
            this->events = nullptr;
            if (ref.events != nullptr) {
                this->events = new VxLicenseSupEvent[ref.eventsSize];
                for(int i = 0; i < ref.eventsSize; i++)
                    this->events[i] = VxLicenseSupEvent(ref.events[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLicenseSup"/> class.
        /// </summary>
        ~VxLicenseSup() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->expirationTime);
            this->catchUpCount = 0;
            this->extensionYearCount = 0;
			this->currentBalance = 0;
            this->eventsSize = 0;
            this->events = nullptr;
        }

    public:
        /// <summary>
        /// The expiration time of the software upgrade plan.
        /// </summary>
        char expirationTime[64];
        /// <summary>
        /// The number of channel-years needed to bring the software upgrade plan license up-to-date today.
        /// </summary>
        int catchUpCount;
		/// <summary>
        /// The size of <see cref="events"/>.
        /// </summary>
        int eventsSize;
        /// <summary>
        /// The number of channel-years needed to extend the software upgrade plan license for 1 year.
        /// </summary>
        int extensionYearCount;
        /// <summary>
        /// The current number of channel-years remaining.
        /// </summary>
        float currentBalance;
        /// <summary>
        /// List of events that are related to this license software upgrade plan; an audit trail.
        /// </summary>
        VxLicenseSupEvent* events;
    };
}

#endif // VxLicenseSup_h__