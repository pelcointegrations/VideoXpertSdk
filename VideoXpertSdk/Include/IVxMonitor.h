#ifndef IVxMonitor_h__
#define IVxMonitor_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "VxCollection.h"
#include "VxUtilities.h"

#include "IVxMonitorCell.h"

namespace VxSdk {
    struct IVxDevice;
    struct IVxMonitorLock;

    /// <summary>
    /// Represents a display for view data (typically video).
    /// </summary>
    struct IVxMonitor {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the layouts available for this monitor.
        /// </summary>
        /// <param name="layoutCollection">A <see cref="VxCollection"/> of the available layouts.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAvailableLayouts(VxCollection<VxCellLayout::Value*>& layoutCollection) const = 0;
        /// <summary>
        /// Gets the host device of this monitor.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the cells currently active on this monitor.
        /// </summary>
        /// <param name="cellCollection">A <see cref="VxCollection"/> of the active monitor cells.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitorCells(VxCollection<IVxMonitorCell**>& cellCollection) = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Deletes this monitor from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the monitor.</returns>
        virtual VxResult::Value RemoveMonitor() const = 0;
        /// <summary>
        /// Sets the layout property.
        /// </summary>
        /// <param name="layout">The new layout value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLayout(VxCellLayout::Value layout) = 0;
        /// <summary>
        /// Sets the maximizedCell property.
        /// </summary>
        /// <param name="cellIndex">The index of the cell to maximize; -1 to clear the current maximized cell.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMaximizedCell(int cellIndex) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the number property.
        /// </summary>
        /// <param name="number">The new number value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNumber(int number) = 0;
        /// <summary>
        /// Sets the xResolution and yResolution properties.
        /// </summary>
        /// <param name="xResolution">The new xResolution value.</param>
        /// <param name="yResolution">The new yResolution value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the properties.</returns>
        virtual VxResult::Value SetResolution(int xResolution, int yResolution) = 0;
        /// <summary>
        /// Sets the xResolution property.
        /// </summary>
        /// <param name="xResolution">The new xResolution value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetResolutionX(int xResolution) = 0;
        /// <summary>
        /// Sets the yResolution property.
        /// </summary>
        /// <param name="yResolution">The new yResolution value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetResolutionY(int yResolution) = 0;
        /// <summary>
        /// Sets the play speed of the display data. Negative values indicate reverse speeds while positive values
        /// indicate forward speeds (1 is normal speed). A value of 0 will pause the data playback.
        /// </summary>
        /// <param name="syncSpeed">The sync playback speed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetSyncSpeed(float syncSpeed) = 0;
        /// <summary>
        /// Sets the time to seek to for all synced cells on the monitor. A value of <c>nullptr</c> will set the
        /// streams to live.
        /// </summary>
        /// <param name="syncTime">The time to seek to, <c>nullptr</c> for live.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSyncTime(char syncTime[64]) = 0;

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
        /// The time at which the data should initially seek to (does not track time as the data plays).
        /// </summary>
        char syncTime[64];
        /// <summary>
        /// The wall clock time at which the data playback should begin.
        /// </summary>
        char syncTimeAnchor[64];
        /// <summary>
        /// The index of the full screen monitor cell (-1 if no cells are maximized).
        /// </summary>
        int maximizedCell;
        /// <summary>
        /// The number used to designate the monitor.
        /// </summary>
        int number;
        /// <summary>
        /// The horizontal resolution.
        /// </summary>
        int xResolution;
        /// <summary>
        /// The vertical resolution.
        /// </summary>
        int yResolution;
        /// <summary>
        /// The play speed of the display data.
        /// </summary>
        float syncSpeed;
        /// <summary>
        /// The cell grid layout.
        /// </summary>
        VxCellLayout::Value layout;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->name);
            VxZeroArray(this->syncTime);
            VxZeroArray(this->syncTimeAnchor);
            this->maximizedCell = 0;
            this->number = 0;
            this->syncSpeed = 0;
            this->xResolution = 0;
            this->yResolution = 0;
            this->layout = VxCellLayout::Value::k1x1;
        }
    };
}

#endif // IVxMonitor_h__
