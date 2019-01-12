#ifndef VxPtzLimits_h__
#define VxPtzLimits_h__

namespace VxSdk {
    /// <summary>
    /// Represents the value limits for a PTZ controller.
    /// </summary>
    struct VxPtzLimits {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxPtzLimits"/> struct.
        /// </summary>
        VxPtzLimits() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxPtzLimits"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxPtzLimits(const VxPtzLimits& ref) {
            this->minPositionY = ref.minPositionY;
            this->maxPositionY = ref.maxPositionY;
            this->maxPositionZ = ref.maxPositionZ;
            this->minSpeedX = ref.minSpeedX;
            this->maxSpeedX = ref.maxSpeedX;
            this->minSpeedY = ref.minSpeedY;
            this->maxSpeedY = ref.maxSpeedY;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxPtzLimits"/> class.
        /// </summary>
        ~VxPtzLimits() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->minPositionY = 0;
            this->maxPositionY = 0;
            this->maxPositionZ = 0;
            this->minSpeedX = 0;
            this->maxSpeedX = 0;
            this->minSpeedY = 0;
            this->maxSpeedY = 0;
        }

    public:
        /// <summary>
        /// The Y coordinate minimum limit.
        /// </summary>
        int minPositionY;
        /// <summary>
        /// The Y coordinate maximum limit.
        /// </summary>
        int maxPositionY;
        /// <summary>
        /// The Z coordinate maximum limit.
        /// </summary>
        int maxPositionZ;
        /// <summary>
        /// The pan speed minimum limit.
        /// </summary>
        int minSpeedX;
        /// <summary>
        /// The pan speed maximum limit.
        /// </summary>
        int maxSpeedX;
        /// <summary>
        /// The tilt speed minimum limit.
        /// </summary>
        int minSpeedY;
        /// <summary>
        /// The tilt speed maximum limit.
        /// </summary>
        int maxSpeedY;
    };
}

#endif // VxPtzLimits_h__
