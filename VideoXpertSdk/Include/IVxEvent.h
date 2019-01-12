#ifndef IVxEvent_h__
#define IVxEvent_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    struct IVxSituation;

    /// <summary>
    /// Represents an instance of a particular situation that has occurred.
    /// </summary>
    struct IVxEvent {
    public:
        /// <summary>
        /// Acknowledges the event.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Acknowledge() const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the device that the event was generated on.
        /// </summary>
        /// <param name="device">The generator device.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetGeneratorDevice(IVxDevice*& device) const = 0;
        /// <summary>
        /// Gets the situation that this event represents.
        /// </summary>
        /// <param name="situation">The situation of the event.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSituation(IVxSituation*& situation) const = 0;
        /// <summary>
        /// Gets the device that the situation occurred on.
        /// </summary>
        /// <param name="device">The source device.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSourceDevice(IVxDevice*& device) const = 0;
        /// <summary>
        /// Gets the user that was the cause of the situation.
        /// </summary>
        /// <param name="user">The user that caused the situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUser(IVxUser*& user) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Silences the event for a given amount of time.
        /// </summary>
        /// <param name="wakeup">The delay, in seconds, to apply prior to the event being brought to
        /// the user’s attention.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Silence(int wakeup) const = 0;

    public:
        /// <summary>
        /// Indicates whether the event is in its initial generated state (its ackState has not been updated).
        /// </summary>
        bool isInitial;
        /// <summary>
        /// Indicates whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        bool shouldAudiblyNotify;
        /// <summary>
        /// The identifier of the client that set the current ackState, if any.
        /// </summary>
        char ackClientId[64];
        /// <summary>
        /// The friendly name of the client that set the current * ackState, if any.
        /// </summary>
        char ackClientName[256];
        /// <summary>
        /// The time at which the current <see cref="ackState"/> was set.
        /// </summary>
        char ackTime[256];
        /// <summary>
        /// The user that set the current <see cref="ackState"/>, if any.
        /// </summary>
        char ackUser[256];
        /// <summary>
        /// The unique identifier of the device that created and injected this
        /// event into the system.
        /// </summary>
        char generatorDeviceId[64];
        /// <summary>
        /// The friendly name of the generator device, if any.
        /// </summary>
        char generatorDeviceName[256];
        /// <summary>
        /// The unique identifier created by the device that generated the event.
        /// </summary>
        char id[64];
        /// <summary>
        /// The name of the situation that led to the generation of this event.
        /// </summary>
        char situationName[256];
        /// <summary>
        /// The type of the situation that led to the generation of this event.
        /// </summary>
        char situationType[128];
        /// <summary>
        /// The client identifier of the client that was the cause of the situation, if any.
        /// </summary>
        char sourceClientId[64];
        /// <summary>
        /// The unique identifier of the device that the situation occurred on.
        /// </summary>
        char sourceDeviceId[64];
        /// <summary>
        /// The friendly name of the source device.
        /// </summary>
        char sourceDeviceName[256];
        /// <summary>
        /// The name of the user that was the cause of the situation, if any.
        /// </summary>
        char sourceUserName[64];
        /// <summary>
        /// The time at which the situation occurred.
        /// </summary>
        char time[64];
        /// <summary>
        /// The size of <see cref="properties"/>.
        /// </summary>
        int propertySize;
        /// <summary>
        /// The delay, in seconds, prior to bringing the event to the users attention; typically used for silencing the
        /// event.
        /// </summary>
        int wakeup;
        /// <summary>
        /// The severity of the event, from 1 (highest) to 10 (lowest).
        /// </summary>
        unsigned short severity;
        /// <summary>
        /// The current acknowledgement state of the event.
        /// </summary>
        VxAckState::Value ackState;
        /// <summary>
        /// Optional additional information related to the event.
        /// </summary>
        VxKvObject** properties;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isInitial = false;
            this->shouldAudiblyNotify = false;
            VxZeroArray(this->ackClientId);
            VxZeroArray(this->ackClientName);
            VxZeroArray(this->ackTime);
            VxZeroArray(this->ackUser);
            VxZeroArray(this->generatorDeviceId);
            VxZeroArray(this->generatorDeviceName);
            VxZeroArray(this->id);
            VxZeroArray(this->situationName);
            VxZeroArray(this->situationType);
            VxZeroArray(this->sourceClientId);
            VxZeroArray(this->sourceDeviceId);
            VxZeroArray(this->sourceDeviceName);
            VxZeroArray(this->sourceUserName);
            VxZeroArray(this->time);
            this->propertySize = 0;
            this->wakeup = 0;
            this->severity = 0;
            this->ackState = VxAckState::kUnknown;
            this->properties = nullptr;
        }
    };

    typedef void(*VxEventCallback)(IVxEvent*);
}

#endif // IVxEvent_h__
