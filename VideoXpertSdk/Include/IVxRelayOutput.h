#ifndef IVxRelayOutput_h__
#define IVxRelayOutput_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a physical relay output.
    /// </summary>
    struct IVxRelayOutput {
    public:
        /// <summary>
        /// Activate this relay output.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of activating this relay output.</returns>
        virtual VxResult::Value Activate() = 0;
        /// <summary>
        /// Deactivate this relay output.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deactivating this relay output.</returns>
        virtual VxResult::Value Deactivate() = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Disable this relay output.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this relay output.</returns>
        virtual VxResult::Value Disable() = 0;
        /// <summary>
        /// Enable this relay output.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of enabling this relay output.</returns>
        virtual VxResult::Value Enable() = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this relay output.
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
        /// Indicates whether or not the relay output is enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// The friendly description of the relay output.
        /// </summary>
        char description[255];
        /// <summary>
        /// The unique identifier of the relay output.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the relay output.
        /// </summary>
        char name[64];
        /// <summary>
        /// The current state of the relay output.
        /// </summary>
        VxRelayState::Value state;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            isEnabled = false;
            VxZeroArray(this->description);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->state = VxRelayState::kUnknown;
        }
    };
}
#endif // IVxRelayOutput_h__
