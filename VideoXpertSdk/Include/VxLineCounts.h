#ifndef VxLineCounts_h__
#define VxLineCounts_h__

#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxLineCount.h"

namespace VxSdk {
    /// <summary>
    /// Represents the list of line count values requested.
    /// </summary>
    struct VxLineCounts {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCounts"/> struct.
        /// </summary>
        VxLineCounts() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLineCounts"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLineCounts(const VxLineCounts& ref) {
            this->lineCountSize = ref.lineCountSize;
            this->lineCounts = nullptr;
            if (ref.lineCounts != nullptr) {
                this->lineCounts = new VxLineCount[ref.lineCountSize];
                for (int i = 0; i < ref.lineCountSize; i++)
                    this->lineCounts[i] = VxLineCount(ref.lineCounts[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLineCounts"/> class.
        /// </summary>
        ~VxLineCounts() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->lineCountSize = 0;
            this->lineCounts = nullptr;
        }

    public:
        /// <summary>
        /// The size of <see cref="lineCounts"/>.
        /// </summary>
        int lineCountSize;
        /// <summary>
        /// The list of line counts.
        /// </summary>
        VxLineCount* lineCounts;

    };
}

#endif // VxLineCounts_h__
