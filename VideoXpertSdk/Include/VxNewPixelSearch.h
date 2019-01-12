#ifndef VxNewPixelSearch_h__
#define VxNewPixelSearch_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxRect.h"

namespace VxSdk {
    /// <summary>
    /// Represents a square grid composed of rows and columns with zones indicating the areas of the grid to search.
    /// The grid uses a cartesian coordinate system with 0-based indices. The search results will be contained by the
    /// new <see cref="IVxPixelSearch"/> that is created.
    /// </summary>
    struct VxNewPixelSearch {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewPixelSearch"/> struct.
        /// </summary>
        VxNewPixelSearch() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxNewPixelSearch"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxNewPixelSearch(const VxNewPixelSearch& ref) {
            Utilities::StrCopySafe(this->searchEndTime, ref.searchEndTime);
            Utilities::StrCopySafe(this->searchStartTime, ref.searchStartTime);
            this->columns = ref.columns;
            this->rows = ref.rows;
            this->zoneSize = ref.zoneSize;
            this->zones = nullptr;
            if (ref.zones != nullptr) {
                this->zones = new VxRect[ref.zoneSize];
                for(int i = 0; i < ref.zoneSize; i++)
                    this->zones[i] = VxRect(ref.zones[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxNewPixelSearch"/> class.
        /// </summary>
        ~VxNewPixelSearch() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->searchEndTime);
            VxZeroArray(this->searchStartTime);
            columns = 0;
            rows = 0;
            this->zoneSize = 0;
            this->zones = nullptr;
        }

    public:
        /// <summary>
        /// The inclusive bounds to the earliest results to retrieve. Defaults to the oldest results available.
        /// </summary>
        char searchEndTime[64];
        /// <summary>
        /// The inclusive bounds to the latest results to retrieve. Defaults to the most current results available.
        /// </summary>
        char searchStartTime[64];
        /// <summary>
        /// The number of columns in the search grid (1 to 1000).
        /// </summary>
        int columns;
        /// <summary>
        /// The number of rows in the search grid (1 to 1000).
        /// </summary>
        int rows;
        /// <summary>
        /// The size of <see cref="zones"/>.
        /// </summary>
        int zoneSize;
        /// <summary>
        /// List of rectangular areas indicating the selected zones to search (0,0 to 999,999).
        /// </summary>
        VxRect* zones;
    };
}

#endif // VxNewPixelSearch_h__