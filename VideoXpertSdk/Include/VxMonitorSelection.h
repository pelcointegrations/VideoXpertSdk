#ifndef VxMonitorSelection_h__
#define VxMonitorSelection_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents information for a selected monitor/cell within a monitor wall.
    /// </summary>
    struct VxMonitorSelection {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxMonitorSelection"/> struct.
        /// </summary>
        VxMonitorSelection() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxMonitorSelection"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxMonitorSelection(const VxMonitorSelection& ref) {
            Utilities::StrCopySafe(this->lastModified, ref.lastModified);
            Utilities::StrCopySafe(this->owner, ref.owner);
            this->cell = ref.cell;
            this->monitor = ref.monitor;
            this->inputMode = ref.inputMode;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxMonitorSelection"/> class.
        /// </summary>
        ~VxMonitorSelection() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->lastModified);
            VxZeroArray(this->owner);
            this->cell = 0;
            this->monitor = 0;
            this->inputMode = VxCellInputMode::kUnknown;
        }

    public:
        /// <summary>
        /// The time of the last modification for this monitor selection.
        /// </summary>
        char lastModified[64];
        /// <summary>
        /// The name of the user that owns this monitor selection.
        /// </summary>
        char owner[64];
        /// <summary>
        /// The index of the selected cell within the selected monitor.
        /// </summary>
        int cell;
        /// <summary>
        /// The index of the selected monitor.
        /// </summary>
        int monitor;
        /// <summary>
        /// The input mode of the selected cell.
        /// </summary>
        VxCellInputMode::Value inputMode;
    };
}

#endif // VxMonitorSelection_h__