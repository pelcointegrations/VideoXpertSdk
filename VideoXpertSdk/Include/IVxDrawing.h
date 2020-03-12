#ifndef IVxDrawing_h__
#define IVxDrawing_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxCollection.h"

namespace VxSdk {
    struct IVxMarker;
    struct IVxResourceLock;

    /// <summary>
    /// Represents a diagrammatic representation of an area. A drawing may contain any number of markers to represent
    /// points of interest within the area.
    /// </summary>
    struct IVxDrawing {
    public:
        /// <summary>
        /// Creates a new marker.
        /// </summary>
        /// <param name="newMarker">The new marker to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddMarker(VxNewMarker& newMarker) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this drawing from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the Drawing.</returns>
        virtual VxResult::Value DeleteDrawing() const = 0;
        /// <summary>
        /// Deletes the binary drawing image data.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the Drawing.</returns>
        virtual VxResult::Value DeleteImage() = 0;
        /// <summary>
        /// Gets the binary image data, if any.
        /// </summary>
        /// <param name="endpoint">The image endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetImage(char* endpoint, int& size) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the resource lock, if any.
        /// </summary>
        /// <param name="resourceLock">The current resource lock if present.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLock(IVxResourceLock*& resourceLock) const = 0;
        /// <summary>
        /// Gets the markers contained within this drawing.
        /// <para>Available filters: kLayerName, kModifiedSince, kResourceId.</para>
        /// </summary>
        /// <param name="markerCollection">A <see cref="VxCollection"/> of the associated markers.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMarkers(VxCollection<IVxMarker**>& markerCollection) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the backgroundColor property.
        /// </summary>
        /// <param name="backgroundColor">The new background color ARGB value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBackgroundColor(unsigned int backgroundColor) = 0;
        /// <summary>
        /// Sets the cameraNumberColor property.
        /// </summary>
        /// <param name="cameraNumberColor">The new camera number color ARGB value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetCameraNumberColor(unsigned int cameraNumberColor) = 0;
        /// <summary>
        /// Sets the binary drawing image data. The maximum allowable size of the image is 128 MB.
        /// </summary>
        /// <param name="imagePath">The local path to the image file.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetImage(char* imagePath) = 0;
        /// <summary>
        /// Sets a resource lock on this drawing, owned by the current user.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetLock() const = 0;
        /// <summary>
        /// Sets the markerSize property.
        /// </summary>
        /// <param name="markerSize">The new marker size value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetMarkerSize(int markerSize) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the showCameraNumbers property.
        /// </summary>
        /// <param name="showCameraNumbers"><c>true</c> to show camera number text overlay, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetShowCameraNumbers(bool showCameraNumbers) = 0;

    public:
        /// <summary>
        /// Indicates whether the camera number text overlays should be displayed.
        /// </summary>
        bool showCameraNumbers;
        /// <summary>
        /// The unique identifier of the drawing.
        /// </summary>
        char id[64];
        /// <summary>
        /// The time since the drawing was last modified
        /// </summary>
        char lastModified[64];
        /// <summary>
        /// The mime type of the drawing
        /// </summary>
        char mimeType[64];
        /// <summary>
        /// The friendly name of the drawing.
        /// </summary>
        char name[64];
        /// <summary>
        /// An integer that defines an ARGB color for the map background.
        /// </summary>
        unsigned int backgroundColor;
        /// <summary>
        /// An integer that defines an ARGB color for the camera number text.
        /// </summary>
        unsigned int cameraNumberColor;
        /// <summary>
        /// The size, in pixels, of marker icons.
        /// </summary>
        int markerSize;
        /// <summary>
        /// The provider for the drawing.
        /// </summary>
        VxDrawingProvider::Value provider;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->showCameraNumbers = false;
            VxZeroArray(this->id);
            VxZeroArray(this->lastModified);
            VxZeroArray(this->mimeType);
            VxZeroArray(this->name);
            this->backgroundColor = 0;
            this->cameraNumberColor = 0;
            this->markerSize = 0;
            this->provider = VxDrawingProvider::kUnknown;
        }
    };
}
#endif // IVxDrawing_h__
