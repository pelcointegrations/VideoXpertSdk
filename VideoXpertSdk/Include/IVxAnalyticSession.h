#ifndef IVxAnalyticSession_h__
#define IVxAnalyticSession_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxAnalyticConfig.h"

namespace VxSdk {
    struct IVxDataSource;
    struct IVxDevice;

    /// <summary>
    /// Represents an analytic session for a single video data source on an analytic server.
    /// </summary>
    struct IVxAnalyticSession {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Delete this analytic session.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the analytic session.</returns>
        virtual VxResult::Value DeleteAnalyticSession() const = 0;
        /// <summary>
        /// Gets the <see cref="IVxAnalyticConfig"/> for this session.
        /// </summary>
        /// <param name="analyticConfig">The <see cref="IVxAnalyticConfig"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticConfig(IVxAnalyticConfig*& analyticConfig) const = 0;
        /// <summary>
        /// Gets the the associated video <see cref="IVxDataSource"/>.
        /// </summary>
        /// <param name="dataSource">The associated video <see cref="IVxDataSource"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSource(IVxDataSource*& dataSource) const = 0;
        /// <summary>
        /// Gets the the associated host <see cref="IVxDevice"/>.
        /// </summary>
        /// <param name="hostDevice">The associated host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the unique identifier specifying which data encoding to use as a source. This value can be used instead
        /// of <see cref="source"/> to determine which stream to use.
        /// </summary>
        /// <param name="dataEncodingId">The new dataEncodingId value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDataEncodingId(char dataEncodingId[64]) = 0;
        /// <summary>
        /// Sets the RTSP URI to use as the source for the analytic session.
        /// </summary>
        /// <param name="source">The new source URI value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSource(char source[1024]) = 0;

    public:
        /// <summary>
        /// The unique identifier specifying which data encoding to use as a source.
        /// </summary>
        char dataEncodingId[64];
        /// <summary>
        /// The unique identifier of the analytic session.
        /// </summary>
        char id[64];
        /// <summary>
        /// The RTSP URI to use as the source for the analytic session.
        /// </summary>
        char source[1024];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->dataEncodingId);
            VxZeroArray(this->id);
            VxZeroArray(this->source);
        }
    };
}
#endif // IVxAnalyticSession_h__
