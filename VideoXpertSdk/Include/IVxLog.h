#ifndef IVxLog_h__
#define IVxLog_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a log file or set of log files.
    /// </summary>
    struct IVxLog {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this log from the device.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this log.</returns>
        virtual VxResult::Value DeleteLog() const = 0;
        /// <summary>
        /// Gets the URI to the download location of the actual log data. May be presented in whatever format is
        /// suitable to the server. This endpoint will only be present if the log data is complete and available for
        /// download.
        /// </summary>
        /// <param name="endpoint">The log endpoint, if available.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLogEndpoint(char* endpoint, int& size) = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;

    public:
        /// <summary>
        /// The date and time at which the log was completed.
        /// </summary>
        char completed[64];
        /// <summary>
        /// The unique identifier of the log.
        /// </summary>
        char id[64];
        /// <summary>
        /// The date and time at which the log was requested.
        /// </summary>
        char initiated[64];
    };
}
#endif // IVxLog_h__
