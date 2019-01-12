#ifndef VxRect_h__
#define VxRect_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents rectangular integer coordinates indicated by a combination of left, top, width, and height values.
    /// </summary>
    struct VxRect {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxRect"/> struct.
        /// </summary>
        VxRect() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxRect"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxRect(const VxRect& ref) {
            this->height = ref.height;
            this->left = ref.left;
            this->top = ref.top;
            this->width = ref.width;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxRect"/> class.
        /// </summary>
        ~VxRect() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            height = 0;
            left = 0;
            top = 0;
            width = 0;
        }

    public:
        /// <summary>
        /// The height value.
        /// </summary>
        int height;
        /// <summary>
        /// The left value.
        /// </summary>
        int left;
        /// <summary>
        /// The top value.
        /// </summary>
        int top;
        /// <summary>
        /// The width value.
        /// </summary>
        int width;
    };
}

#endif // VxRect_h__