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
            this->hasLimitPositionX = ref.hasLimitPositionX;
            this->hasLimitPositionY = ref.hasLimitPositionY;
            this->hasLimitPositionZ = ref.hasLimitPositionZ;
            this->hasLimitSpeedFocus = ref.hasLimitSpeedFocus;
            this->hasLimitSpeedIris = ref.hasLimitSpeedIris;
            this->hasLimitSpeedX = ref.hasLimitSpeedX;
            this->hasLimitSpeedY = ref.hasLimitSpeedY;
            this->hasLimitSpeedZ = ref.hasLimitSpeedZ;
            this->maxPositionX = ref.maxPositionX;
            this->maxPositionY = ref.maxPositionY;
            this->maxPositionZ = ref.maxPositionZ;
            this->maxSpeedFocus = ref.maxSpeedFocus;
            this->maxSpeedIris = ref.maxSpeedIris;
            this->maxSpeedX = ref.maxSpeedX;
            this->maxSpeedY = ref.maxSpeedY;
            this->maxSpeedZ = ref.maxSpeedZ;
            this->minPositionX = ref.minPositionX;
            this->minPositionY = ref.minPositionY;
            this->minPositionZ = ref.minPositionZ;
            this->minSpeedFocus = ref.minSpeedFocus;
            this->minSpeedIris = ref.minSpeedIris;
            this->minSpeedX = ref.minSpeedX;
            this->minSpeedY = ref.minSpeedY;
            this->minSpeedZ = ref.minSpeedZ;
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
            this->hasLimitPositionX = false;
            this->hasLimitPositionY = false;
            this->hasLimitPositionZ = false;
            this->hasLimitSpeedFocus = false;
            this->hasLimitSpeedIris = false;
            this->hasLimitSpeedX = false;
            this->hasLimitSpeedY = false;
            this->hasLimitSpeedZ = false;
            this->maxPositionX = 0;
            this->maxPositionY = 0;
            this->maxPositionZ = 0;
            this->maxSpeedFocus = 0;
            this->maxSpeedIris = 0;
            this->maxSpeedX = 0;
            this->maxSpeedY = 0;
            this->maxSpeedZ = 0;
            this->minPositionX = 0;
            this->minPositionY = 0;
            this->minPositionZ = 0;
            this->minSpeedFocus = 0;
            this->minSpeedIris = 0;
            this->minSpeedX = 0;
            this->minSpeedY = 0;
            this->minSpeedZ = 0;
        }

    public:
        /// <summary>
        /// Indicates whether the X coordinate limits are available.
        /// </summary>
        bool hasLimitPositionX;
        /// <summary>
        /// Indicates whether the Y coordinate limits are available.
        /// </summary>
        bool hasLimitPositionY;
        /// <summary>
        /// Indicates whether the Z coordinate limits are available.
        /// </summary>
        bool hasLimitPositionZ;
        /// <summary>
        /// Indicates whether the focus speed limits are available.
        /// </summary>
        bool hasLimitSpeedFocus;
        /// <summary>
        /// Indicates whether the iris speed limits are available.
        /// </summary>
        bool hasLimitSpeedIris;
        /// <summary>
        /// Indicates whether the X speed limits are available.
        /// </summary>
        bool hasLimitSpeedX;
        /// <summary>
        /// Indicates whether the Y speed limits are available.
        /// </summary>
        bool hasLimitSpeedY;
        /// <summary>
        /// Indicates whether the Z speed limits are available.
        /// </summary>
        bool hasLimitSpeedZ;
        /// <summary>
        /// The X coordinate maximum limit.
        /// </summary>
        int maxPositionX;
        /// <summary>
        /// The Y coordinate maximum limit.
        /// </summary>
        int maxPositionY;
        /// <summary>
        /// The Z coordinate maximum limit.
        /// </summary>
        int maxPositionZ;
        /// <summary>
        /// The focus speed maximum limit.
        /// </summary>
        int maxSpeedFocus;
        /// <summary>
        /// The iris speed maximum limit.
        /// </summary>
        int maxSpeedIris;
        /// <summary>
        /// The pan speed maximum limit.
        /// </summary>
        int maxSpeedX;
        /// <summary>
        /// The tilt speed maximum limit.
        /// </summary>
        int maxSpeedY;
        /// <summary>
        /// The zoom speed maximum limit.
        /// </summary>
        int maxSpeedZ;
        /// <summary>
        /// The X coordinate minimum limit.
        /// </summary>
        int minPositionX;
        /// <summary>
        /// The Y coordinate minimum limit.
        /// </summary>
        int minPositionY;
        /// <summary>
        /// The Z coordinate minimum limit.
        /// </summary>
        int minPositionZ;
        /// <summary>
        /// The focus speed minimum limit.
        /// </summary>
        int minSpeedFocus;
        /// <summary>
        /// The iris speed minimum limit.
        /// </summary>
        int minSpeedIris;
        /// <summary>
        /// The pan speed minimum limit.
        /// </summary>
        int minSpeedX;
        /// <summary>
        /// The tilt speed minimum limit.
        /// </summary>
        int minSpeedY;
        /// <summary>
        /// The zoom speed minimum limit.
        /// </summary>
        int minSpeedZ;
    };
}

#endif // VxPtzLimits_h__
