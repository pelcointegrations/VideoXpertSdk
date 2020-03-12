#ifndef IVxMonitorCell_h__
#define IVxMonitorCell_h__

#include "VxMacros.h"
#include "VxPrimitives.h"

namespace VxSdk {
    struct IVxDevice;

    /// <summary>
    /// Represents a single viewport, hosted on a monitor, that can play media from a data source.
    /// </summary>
    struct IVxMonitorCell {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Disables the analytics overlay. 
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DisableAnalyticsOverlay() = 0;
        /// <summary>
        /// Disables the statistics overlay. 
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DisableStatisticsOverlay() = 0;
        /// <summary>
        /// Enables the analytics overlay. 
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value EnableAnalyticsOverlay() = 0;
        /// <summary>
        /// Enables the statistics overlay. 
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value EnableStatisticsOverlay() = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Adds this cell is to the monitor's sync group.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value JoinSyncGroup() = 0;
        /// <summary>
        /// Removes this cell is to the monitor's sync group.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value LeaveSyncGroup() = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the height and width of the crop bounds applied to the video.
        /// </summary>
        /// <param name="height">The height as a percentage (0-1).</param>
        /// <param name="width">The width as a percentage (0-1).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetCropBounds(float height, float width) = 0;
        /// <summary>
        /// Sets the height of the crop bounds applied to the video.
        /// </summary>
        /// <param name="height">The height as a percentage (0-1).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetCropHeight(float height) = 0;
        /// <summary>
        /// Sets the width of the crop bounds applied to the video.
        /// </summary>
        /// <param name="width">The width as a percentage (0-1).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetCropWidth(float width) = 0;
        /// <summary>
        /// Sets the data source that this cell shall display.
        /// </summary>
        /// <param name="dataSourceId">
        /// The ID of the data source to display or a <c>nullptr</c> to remove the current data source.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDataSource(char dataSourceId[MAX_UUID_LENGTH]) = 0;
        /// <summary>
        /// Sets the X, Y and Z locations of the crop bounds or immersive position.
        /// </summary>
        /// <param name="x">The x location.</param>
        /// <param name="y">The y location.</param>
        /// <param name="z">The z location.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLocation(int x, int y, int z) = 0;
        /// <summary>
        /// Sets the X location of the crop bounds or immersive position.
        /// </summary>
        /// <param name="x">The x location.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLocationX(int x) = 0;
        /// <summary>
        /// Sets the Y location of the crop bounds or immersive position.
        /// </summary>
        /// <param name="y">The y location.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLocationY(int y) = 0;
        /// <summary>
        /// Sets the Z location of the immersive position.
        /// </summary>
        /// <param name="z">The z location.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLocationZ(int z) = 0;
        /// <summary>
        /// Sets the rotation applied to the video.
        /// </summary>
        /// <param name="rotation">The rotation of the video.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetRotation(VxRotationType::Value rotation) = 0;
        /// <summary>
        /// Sets the play speed of the monitor data. Negative values indicate reverse speeds while positive values
        /// indicate forward speeds (1 is normal speed). A value of 0 will pause the data playback.
        /// </summary>
        /// <param name="speed">The playback speed.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetSpeed(float speed) = 0;
        /// <summary>
        /// Sets the time to seek to on the monitor. A value of <c>nullptr</c> will set the stream to live. If no
        /// frame is available for the given time the stream will remain unchanged.
        /// </summary>
        /// <param name="time">The time to seek to, <c>nullptr</c> for live.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetTime(char time[64]) = 0;

    public:
        /// <summary>
        /// Indicates whether or not the analytics overlay is enabled.
        /// </summary>
        bool isAnalyticsOverlayEnabled;
        /// <summary>
        /// Indicates whether or not the cell is part of the monitor's sync group.
        /// </summary>
        bool isInSync;
        /// <summary>
        /// Indicates whether or not the statistics overlay is enabled.
        /// </summary>
        bool isStatisticsOverlayEnabled;
        /// <summary>
        /// The unique identifier of the data source displayed in the cell.
        /// </summary>
        char dataSourceId[MAX_UUID_LENGTH];
        /// <summary>
        /// The time at which the data should initially seek to (does not track time as the data plays).
        /// </summary>
        char time[64];
        /// <summary>
        /// The wall clock time at which the data playback should begin.
        /// </summary>
        char timeAnchor[64];
        /// <summary>
        /// The height of the crop bounds expressed as a percentage (0-1).
        /// (e.g. 0.5 for 50% of the video frame height).
        /// </summary>
        float cropHeight;
        /// <summary>
        /// The width of the crop bounds expressed as a percentage (0-1).
        /// (e.g. 0.5 for 50% of the video frame width).
        /// </summary>
        float cropWidth;
        /// <summary>
        /// The play speed of the display data.
        /// </summary>
        float speed;
        /// <summary>
        /// The unique index of the cell based on its position within the current layout.
        /// </summary>
        int index;
        /// <summary>
        /// The X location of the crop bounds or immersive position.
        /// </summary>
        int x;
        /// <summary>
        /// The Y location of the crop bounds or immersive position.
        /// </summary>
        int y;
        /// <summary>
        /// The Z location of the immersive position.
        /// </summary>
        int z;
        /// <summary>
        /// The rotation applied to the video.
        /// </summary>
        VxRotationType::Value rotation;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isAnalyticsOverlayEnabled = false;
            this->isInSync = false;
            this->isStatisticsOverlayEnabled = false;
            VxZeroArray(this->dataSourceId);
            VxZeroArray(this->time);
            VxZeroArray(this->timeAnchor);
            this->cropHeight = 0;
            this->cropWidth = 0;
            this->speed = 0;
            this->index = 0;
            this->x = 0;
            this->y = 0;
            this->z = 0;
            this->rotation = VxRotationType::kUnknown;
        }
    };
}

#endif // IVxMonitorCell_h__
