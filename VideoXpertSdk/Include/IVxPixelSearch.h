#ifndef IVxPixelSearch_h__
#define IVxPixelSearch_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxClip.h"

namespace VxSdk {
    /// <summary>
    /// Represents the results of a pixel search.
    /// </summary>
    struct IVxPixelSearch {
    public:
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes this set of pixel search results.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the pixel search.</returns>
        virtual VxResult::Value DeletePixelSearch() const = 0;
        /// <summary>
        /// Gets the clips that were found as a result of the pixel search. New clips may continue to be available
        /// while the search is in progress.
        /// <para>
        /// Available filters: kDataSourceId, kEndTime, kEvent, kFramerate, kSearchEndTime, kSearchStartTime,
        /// kStartTime.
        /// </para>
        /// </summary>
        /// <param name="clipCollection">A <see cref="VxCollection"/> of the clips found by the pixel search.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetClips(VxCollection<IVxClip**>& clipCollection) const = 0;
        /// <summary>
        /// Gets the current status of the pixel search.
        /// </summary>
        /// <param name="status">The current status of the pixel search.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSearchStatus(VxSearchStatus::Value& status) const = 0;
    };
}
#endif // IVxPixelSearch_h__
