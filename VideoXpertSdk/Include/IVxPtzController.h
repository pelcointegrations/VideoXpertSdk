#ifndef IVxPtzController_h__
#define IVxPtzController_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxPattern.h"
#include "IVxPreset.h"
#include "VxCollection.h"
#include "IVxPtzLock.h"
#include "VxPtzLimits.h"

namespace VxSdk {
    /// <summary>
    /// Represents a controller for a device that has pan, tilt, and/or zoom functionality.
    /// </summary>
    struct IVxPtzController {
    public:
        /// <summary>
        /// Moves to the absolute position of the given coordinates.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum X and Y coordinate values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AbsoluteMove(int positionX, int positionY) const = 0;
        /// <summary>
        /// Moves to the absolute position of the given coordinates.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum X, Y, and Z coordinate values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <param name="positionZ">The Z coordinate absolute position (zoom).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AbsoluteMove(int positionX, int positionY, int positionZ) const = 0;
        /// <summary>
        /// Pans to the absolute position of the given coordinate.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum X coordinate values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AbsolutePan(int positionX) const = 0;
        /// <summary>
        /// Tilts to the absolute position of the given coordinate.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum Y coordinate values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AbsoluteTilt(int positionY) const = 0;
        /// <summary>
        /// Zooms to the absolute position of the given coordinates.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum Z coordinate values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="positionZ">The Z coordinate absolute position (zoom).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AbsoluteZoom(int positionZ) const = 0;
        /// <summary>
        /// Creates a new digital PTZ preset. This preset will represent the given spatial coordinates.
        /// </summary>
        /// <param name="newDigitalPtzPreset">The new digital PTZ preset.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDigitalPreset(VxNewDigitalPtzPreset& newDigitalPtzPreset) const = 0;
        /// <summary>
        /// Creates a new preset using the current PTZ spatial coordinates.
        /// </summary>
        /// <param name="index">The unique index value for the new preset.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddPreset(int index) const = 0;
        /// <summary>
        /// Continuously focuses near or far at the given speed.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum focus speed values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="focusSpeed">Focus speed. Negative values focus near, positive values focus far.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousFocusAtSpeed(int focusSpeed) const = 0;
        /// <summary>
        /// Continuously focuses near or far.
        /// </summary>
        /// <param name="nearFar">The direction to focus.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousFocus(VxFocusDirection::Value nearFar) const = 0;
        /// <summary>
        /// Continuously opens or closes the iris at the given speed.
        /// </summary>
        /// <remarks>
        /// The minimum/maximum iris speed values may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="irisSpeed">Iris speed. Negative values close the iris, positive values open the iris.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousIrisAtSpeed(int irisSpeed) const = 0;
        /// <summary>
        /// Continuously opens or closes the iris.
        /// </summary>
        /// <param name="openClose">The direction to change the iris.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousIris(VxIrisDirection::Value openClose) const = 0;
        /// <summary>
        /// Continuously moves the field of view at the given speed until stopped. 
        /// </summary>
        /// <remarks>
        /// The minimum/maximum speed values for each parameter may be retrieved using <c>GetPtzLimits</c>.
        /// </remarks>
        /// <param name="speedX">Pan speed. Negative values pan left, positive values pan right.</param>
        /// <param name="speedY">Tilt speed. Negative values tilt downward, positive values tilt upward.</param>
        /// <param name="speedZ">Zoom speed. Negative values zoom out, positive values zoom in.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousMoveAtSpeed(int speedX, int speedY, int speedZ) const = 0;
        /// <summary>
        /// Continuously moves the field of view at the given speed percentage until stopped.
        /// </summary>
        /// <param name="speedX">Pan speed percentage (-100 to +100). Negative values pan left, positive values pan right.</param>
        /// <param name="speedY">Tilt speed percentage (-100 to +100). Negative values tilt downward, positive values tilt upward.</param>
        /// <param name="inOut">The direction to zoom.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value ContinuousMove(int speedX, int speedY, VxZoomDirection::Value inOut) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes a preset from the system.
        /// </summary>
        /// <param name="preset">The <see cref="IVxPreset"/> to delete.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DeletePreset(IVxPreset& preset) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the available patterns.
        /// <para>Available filters: kModifiedSince.</para>
        /// </summary>
        /// <param name="patternCollection">A <see cref="VxCollection"/> of the associated patterns.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPatterns(VxCollection<IVxPattern**>& patternCollection) const = 0;
        /// <summary>
        /// Gets the current absolute position coordinates.
        /// </summary>
        /// <param name="positionX">The X coordinate absolute position (pan).</param>
        /// <param name="positionY">The Y coordinate absolute position (tilt).</param>
        /// <param name="positionZ">The Z coordinate absolute position (zoom).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPosition(int& positionX, int& positionY, int& positionZ) const = 0;
        /// <summary>
        /// Gets the available presets.
        /// <para>Available filters: kModifiedSince.</para>
        /// </summary>
        /// <param name="presetCollection">A <see cref="VxCollection"/> of the associated presets.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPresets(VxCollection<IVxPreset**>& presetCollection) const = 0;
        /// <summary>
        /// Gets the value limits for this PTZ controller.
        /// </summary>
        /// <param name="ptzLimits">The PTZ limits.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPtzLimits(VxPtzLimits*& ptzLimits) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxPtzLock"/> for this <see cref="IVxPtzController"/>.
        /// </summary>
        /// <param name="ptzLock">The <see cref="IVxPtzLock"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPtzLock(IVxPtzLock*& ptzLock) const = 0;
        /// <summary>
        /// Stops all PTZ actions.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value PtzStop() const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Moves the camera position relative to the current position.
        /// </summary>
        /// <param name="deltaX">
        /// The degree to pan relative to the current X position. Negative values pan left, positive values pan right.
        /// </param>
        /// <param name="deltaY">
        /// The degree to tilt relative to the current Y position. Negative values pan left, positive values pan right.
        /// </param>
        /// <param name="deltaZ">
        /// The magnification level relative to the current Z position. Negative values pan left, positive values pan
        /// right.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RelativeMove(int deltaX, int deltaY, int deltaZ) const = 0;
        /// <summary>
        /// Moves the camera position within a percentage relative to the device�s current field of view.
        /// </summary>
        /// <remarks>
        /// The rotational x and y parameters are used to move within a percentage of the current field of view of the
        /// camera. For instance, if the x parameter were 50 and the y parameter were -50, the pan/tilt would move
        /// halfway to the edge of the field of view along the x axis and halfway to the field of view along the
        /// negative y axis from its present position.
        /// </remarks>
        /// <param name="percentageX">
        /// Percentage of the current field of view of the camera (X axis). Positive values are to the right, negative
        /// values are to the left. Range: -100 to 100.
        /// </param>
        /// <param name="percentageY">
        /// Percentage of the current field of view of the camera (Y axis). Positive values are up, negative values are
        /// down. Range: -100 to 100.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RelativePercentageMove(int percentageX, int percentageY) const = 0;
        /// <summary>
        /// Moves the camera position within a percentage relative to the device�s current field of view.
        /// </summary>
        /// <remarks>
        /// The rotational x and y parameters are used to move within a percentage of the current field of view of the
        /// camera. For instance, if the x parameter were 50 and the y parameter were -50, the pan/tilt would move
        /// halfway to the edge of the field of view along the x axis and halfway to the field of view along the
        /// negative y axis from its present position.
        /// </remarks>
        /// <param name="percentageX">
        /// Percentage of the current field of view of the camera (X axis). Positive values are to the right, negative
        /// values are to the left. Range: -100 to 100.
        /// </param>
        /// <param name="percentageY">
        /// Percentage of the current field of view of the camera (Y axis). Positive values are up, negative values are
        /// down. Range: -100 to 100.
        /// </param>
        /// <param name="percentageZ">
        /// Zoom relative to the current position. It is expressed in terms of magnification * 100, such that if a user
        /// wished to zoom in 2X the current magnification, the value would be 200, 2.5X the current magnification
        /// would be 250. A negative number may not be valid if it is outside the bounds of the field of view.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RelativePercentageMove(int percentageX, int percentageY, int percentageZ) const = 0;
        /// <summary>
        /// Repositions a preset to the current PTZ spatial coordinates.
        /// </summary>
        /// <param name="preset">The <see cref="IVxPreset"/> to reposition.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value RepositionPreset(IVxPreset& preset) const = 0;
        /// <summary>
        /// Triggers a pattern.
        /// </summary>
        /// <param name="pattern">The <see cref="IVxPattern"/> to trigger.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value TriggerPattern(IVxPattern& pattern) const = 0;
        /// <summary>
        /// Triggers a preset by index.
        /// </summary>
        /// <param name="index">The index of the preset to trigger.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value TriggerPreset(int index) const = 0;
        /// <summary>
        /// Triggers a preset.
        /// </summary>
        /// <param name="preset">The <see cref="IVxPreset"/> to trigger.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value TriggerPreset(IVxPreset& preset) const = 0;
        /// <summary>
        /// Triggers a refresh of this <see cref="IVxPtzController"/> on the VideoXpert system; updating its
        /// <see cref="IVxPattern">patterns</see> and <see cref="IVxPreset">presets</see> based on the current camera
        /// configuration.
        /// </summary>
        /// <returns>
        /// The <see cref="VxResult::Value">Result</see> of refreshing the <see cref="IVxPtzController"/>.
        /// </returns>
        virtual VxResult::Value TriggerRefresh() = 0;

    public:
        /// <summary>
        /// Indicates whether the PTZ control is locked.
        /// </summary>
        bool isLocked;
        /// <summary>
        /// The time remaining (in seconds) until the PTZ lock expires.
        /// </summary>
        int lockExpireTime;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isLocked = false;
            this->lockExpireTime = 0;
        }
    };
}

#endif // IVxPtzController_h__
