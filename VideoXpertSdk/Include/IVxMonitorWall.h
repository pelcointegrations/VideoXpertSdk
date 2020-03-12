#ifndef IVxMonitorWall_h__
#define IVxMonitorWall_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "VxUtilities.h"
#include "VxMonitorPosition.h"
#include "VxMonitorSelection.h"
#include "IVxMonitor.h"

namespace VxSdk {
    /// <summary>
    /// Represents a group of monitors.
    /// </summary>
    struct IVxMonitorWall {
    public:
        /// <summary>
        /// Clears the current monitor selection from this monitor wall.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ClearMonitorSelection() = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this monitor wall from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the monitor wall.</returns>
        virtual VxResult::Value DeleteMonitorWall() const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the monitors associated with this monitor wall.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kNumber.</para>
        /// </summary>
        /// <param name="monitorCollection">A <see cref="VxCollection"/> of the associated monitors.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitors(VxCollection<IVxMonitor**>& monitorCollection) = 0;
        /// <summary>
        /// Gets the monitor selections associated with this monitor wall.
        /// <para>Available filters: None.</para>
        /// </summary>
        /// <param name="monitorSelectionCollection">A <see cref="VxCollection"/> of the associated monitor selections.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitorSelections(VxCollection<VxMonitorSelection**>& monitorSelectionCollection) = 0;
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
        /// Sets the monitor positions for this monitor wall.
        /// </summary>
        /// <param name="monitorPositions">The monitor positions.</param>
        /// <param name="monitorPositionsSize">The size of <see cref="monitorPositions"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMonitorPositions(VxMonitorPosition* monitorPositions, int monitorPositionsSize) = 0;
        /// <summary>
        /// Updates the monitor/cell selection (for this user) on the monitor wall.
        /// <para>
        /// Note that each user can independently select a different monitor/cell for remote-control of a monitor wall.
        /// </para>
        /// </summary>
        /// <param name="cellIndex">Index of the monitor cell to select within the monitor (1-based). If 0, the current monitor cell selection (if any) will be cleared.</param>
        /// <param name="monitorIndex">Index of the monitor to select within a monitor wall (1-based). If 0, the current monitor selection (if any) will be cleared.</param>
        /// <param name="inputMode">Input mode for the selected monitor cell. If <see cref="VxCellInputMode::Value::kUnknown"/>, the current input mode will be used.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetMonitorSelection(int cellIndex, int monitorIndex, VxCellInputMode::Value inputMode) = 0;

    public:
        /// <summary>
        /// The unique identifier of the monitor.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of this monitor.
        /// </summary>
        char name[64];
        /// <summary>
        /// The size of <see cref="monitorPositions"/>.
        /// </summary>
        int monitorPositionsSize;
        /// <summary>
        /// The monitor positions for this monitor wall.
        /// </summary>
        VxMonitorPosition* monitorPositions;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            this->monitorPositionsSize = 0;
            this->monitorPositions = nullptr;
        }
    };
}

#endif // IVxMonitorWall_h__
