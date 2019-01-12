#ifndef IVxAlarmInput_h__
#define IVxAlarmInput_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxDevice;

    /// <summary>
    /// Represents a physical alarm input.
    /// </summary>
    struct IVxAlarmInput {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this alarm input.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the description property.
        /// </summary>
        /// <param name="description">The new description value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDescription(char description[255]) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;

    public:
        /// <summary>
        /// The friendly description of the alarm input.
        /// </summary>
        char description[255];
        /// <summary>
        /// The unique identifier of the alarm input.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the alarm input.
        /// </summary>
        char name[64];
        /// <summary>
        /// The current state of the alarm input.
        /// </summary>
        VxAlarmState::Value state;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->description);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->state = VxAlarmState::kUnknown;
        }
    };
}
#endif // IVxAlarmInput_h__
