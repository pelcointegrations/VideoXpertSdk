#ifndef VxInternalEvent_h__
#define VxInternalEvent_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxKvObject.h"

namespace VxSdk {
    /// <summary>
    /// Represents an internal event generated by the VxSDK.
    /// </summary>
    struct VxInternalEvent {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxInternalEvent"/> struct.
        /// </summary>
        VxInternalEvent() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxInternalEvent"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxInternalEvent(const VxInternalEvent& ref) {
            Utilities::StrCopySafe(this->id, ref.id);
            Utilities::StrCopySafe(this->systemId, ref.systemId);
            this->eventType = ref.eventType;
            this->propertySize = ref.propertySize;
            this->properties = nullptr;
            if (ref.properties != nullptr) {
                this->properties = new VxKvObject[ref.propertySize];
                for(int i = 0; i < ref.propertySize; i++)
                    this->properties[i] = VxKvObject(ref.properties[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxInternalEvent"/> class.
        /// </summary>
        ~VxInternalEvent() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->id);
            VxZeroArray(this->systemId);
            this->eventType = VxInternalEventType::kUnknown;
            this->propertySize = 0;
            this->properties = nullptr;
        }

    public:
        /// <summary>
        /// The unique identifier of the event.
        /// </summary>
        char id[64];
        /// <summary>
        /// The unique identifier of the system that generated this event.
        /// </summary>
        char systemId[64];
        /// <summary>
        /// The internal event type.
        /// </summary>
        VxInternalEventType::Value eventType;
        /// <summary>
        /// The size of <see cref="properties"/>.
        /// </summary>
        int propertySize;
        /// <summary>
        /// Optional additional information related to the event.
        /// </summary>
        VxKvObject* properties;
    };

    typedef void(*VxInternalEventCallback)(VxInternalEvent*);
}

#endif // VxInternalEvent_h__
