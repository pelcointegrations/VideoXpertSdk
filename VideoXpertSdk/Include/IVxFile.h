#ifndef IVxFile_h__
#define IVxFile_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a file (e.g. camera firmware).
    /// </summary>
    struct IVxFile {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this file from the system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this file.</returns>
        virtual VxResult::Value DeleteFile() const = 0;
        /// <summary>
        /// Gets the URI to the download location of the actual file data.
        /// </summary>
        /// <param name="endpoint">The file endpoint, if available.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetFileEndpoint(char* endpoint, int& size) = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// The filename of the associated file data.
        /// </summary>
        char filename[256];
        /// <summary>
        /// The unique identifier of the file.
        /// </summary>
        char id[64];
    };
}
#endif // IVxFile_h__
