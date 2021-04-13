#ifndef IVxSituation_h__
#define IVxSituation_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents a particular situation configuration that specifies how corresponding events shall be generated and
    /// handled when the situation is detected.
    /// </summary>
    struct IVxSituation {
    public:
        /// <summary>
        /// Creates a new notification.
        /// </summary>
        /// <param name="newNotification">The new notification to be added.</param>
        /// <param name="notificationItem">
        /// <c>nullptr</c> if it fails, else the new <see cref="IVxNotification"/>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddNotification(VxNewNotification& newNotification, IVxNotification*& notificationItem) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Deletes the custom audio file.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the custom audio file.</returns>
        virtual VxResult::Value DeleteAudioFile() = 0;
        /// <summary>
        /// Deletes this situation from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting the situation.</returns>
        virtual VxResult::Value DeleteSituation() const = 0;
        /// <summary>
        /// Gets the custom audio file, if any.
        /// </summary>
        /// <param name="endpoint">The audio file endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAudioFile(char* endpoint, int& size) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the data sources associated with this situation.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="dataSourceCollection">The data sources associated with this situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the devices associated with this situation.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceCollection">The devices associated with this situation.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLinks(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the notifications associated with this situation.
        /// <para>Available filters: kModifiedSince.</para>
        /// </summary>
        /// <param name="notificationCollection">
        /// A <see cref="VxCollection"/> of notifications associated with this situation.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetNotifications(VxCollection<IVxNotification**>& notificationCollection) const = 0;
        /// <summary>
        /// Associates a data source with this situation.
        /// </summary>
        /// <param name="dataSource">The data source to associate the situation with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Associates a device with this situation.
        /// </summary>
        /// <param name="device">The device to associate the situation with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Link(IVxDevice& device) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        /// <param name="isAckNeeded"><c>true</c> to set initial state to AckNeeded, <c>false</c> for NoAckNeeded.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAckNeeded(bool isAckNeeded) = 0;
        /// <summary>
        /// Sets the audible loop delay property.
        /// </summary>
        /// <param name="audibleLoopDelay">The audible loop delay value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudibleLoopDelay(int audibleLoopDelay) = 0;
        /// <summary>
        /// Sets the audible play count property.
        /// </summary>
        /// <param name="audiblePlayCount">The audible play count value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudiblePlayCount(int audiblePlayCount) = 0;
        /// <summary>
        /// Sets whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        /// <param name="shouldAudiblyNotify"><c>true</c> to audibly notify, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAudiblyNotify(bool shouldAudiblyNotify) = 0;
        /// <summary>
        /// Sets the custom audio file used by clients for audible notifications. The maximum allowable size
        /// of the file is 5 MB.
        /// </summary>
        /// <param name="audioFilePath">The local path to the audio file.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value SetAudioFile(char* audioFilePath) = 0;
        /// <summary>
        /// Sets the auto acknowledge time property.
        /// </summary>
        /// <param name="autoAcknowledgeTime">The auto acknowledge time value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetAutoAcknowledgeTime(int autoAcknowledgeTime) = 0;
        /// <summary>
        /// Sets whether the notification banner on clients should be expanded by default.
        /// </summary>
        /// <param name="shouldExpandBanner"><c>true</c> to expand banner, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetExpandBanner(bool shouldExpandBanner) = 0;
        /// <summary>
        /// Sets whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        /// <param name="shouldLog"><c>true</c> to log events, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetLog(bool shouldLog) = 0;
        /// <summary>
        /// Sets whether an event generated from the situation will generate notifications.
        /// </summary>
        /// <param name="shouldNotify"><c>true</c> to send notifications, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNotify(bool shouldNotify) = 0;
        /// <summary>
        /// Sets whether clients should display a popup notification banner when receiving events of this type.
        /// </summary>
        /// <param name="shouldPopupBanner"><c>true</c> to popup the banner, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPopupBanner(bool shouldPopupBanner) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[MAX_SITUATION_NAME_LENGTH]) = 0;
        /// <summary>
        /// Sets the severity property.
        /// </summary>
        /// <param name="severity">The new severity value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSeverity(int severity) = 0;
        /// <summary>
        /// Sets the snooze intervals for a generated event.
        /// </summary>
        /// <param name="snoozeIntervals">The snooze intervals, in seconds.</param>
        /// <param name="snoozeIntervalSize">The size of <see cref="snoozeIntervals"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetSnoozeIntervals(int* snoozeIntervals, int snoozeIntervalSize) = 0;
        /// <summary>
        /// Removes a data source association from this situation.
        /// </summary>
        /// <param name="dataSource">The data source to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDataSource& dataSource) const = 0;
        /// <summary>
        /// Removes a device association from this situation.
        /// </summary>
        /// <param name="device">The device to remove association with.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value UnLink(IVxDevice& device) const = 0;

    public:
        /// <summary>
        /// Indicates whether the generated events shall have an initial state of AckNeeded or NoAckNeeded.
        /// </summary>
        bool isAckNeeded;
        /// <summary>
        /// Indicates whether a notification sound should play on supporting clients when an event is received.
        /// </summary>
        bool shouldAudiblyNotify;
        /// <summary>
        /// Indicates whether the notification banner on clients should be expanded by default.
        /// </summary>
        bool shouldExpandBanner;
        /// <summary>
        /// Indicates whether events generated from this situation shall be persisted or immediately be discarded.
        /// </summary>
        bool shouldLog;
        /// <summary>
        /// Indicates whether an event generated from the situation shall generate notifications.
        /// </summary>
        bool shouldNotify;
        /// <summary>
        /// Indicates whether clients should display a popup notification banner when receiving events of this type.
        /// </summary>
        bool shouldPopupBanner;
        /// <summary>
        /// The friendly name of the situation.
        /// </summary>
        char name[MAX_SITUATION_NAME_LENGTH];
        /// <summary>
        /// The name of the key in the properties map corresponding to the service identifier for the source of this
        /// situation, if any.
        /// </summary>
        char servicePropertyId[64];
        /// <summary>
        /// Specifies the resource type of the service corresponding to the source of this situation, if any.
        /// </summary>
        char serviceType[64];
        /// <summary>
        /// The unique identifier of the source device.
        /// </summary>
        char sourceDeviceId[64];
        /// <summary>
        /// The situation type.
        /// </summary>
        char type[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The situation type opposite of this situation, if any.
        /// </summary>
        char typeOpposite[MAX_SITUATION_TYPE_LENGTH];
        /// <summary>
        /// The unique identifiers of the notifications configured for this situation.
        /// </summary>
        char** notificationIds;
        /// <summary>
        /// The number of seconds after which a generated event state will be set to AutoAcked.
        /// </summary>
        int autoAcknowledgeTime;
        /// <summary>
        /// The seconds to wait between audible notifications.
        /// </summary>
        int audibleLoopDelay;
        /// <summary>
        /// The amount of times to play audible notifications.
        /// </summary>
        int audiblePlayCount;
        /// <summary>
        /// The size of <see cref="notificationIds"/>.
        /// </summary>
        int notificationIdSize;
        /// <summary>
        /// The severity of the generated event, from 1 (highest) to 10 (lowest).
        /// </summary>
        int severity;
        /// <summary>
        /// The size of <see cref="snoozeIntervals"/>.
        /// </summary>
        int snoozeIntervalSize;
        /// <summary>
        /// The size of <see cref="sourceDeviceTypes"/>.
        /// </summary>
        int sourceDeviceTypesSize;
        /// <summary>
        /// The default snooze intervals, in seconds, for a generated event.
        /// </summary>
        int* snoozeIntervals;
        /// <summary>
        /// A list of device types that may be the source of events for this situation.
        /// <para>NOTE: This field is informational for aiding clients, especially in rule creation.</para>
        /// </summary>
        VxDeviceType::Value* sourceDeviceTypes;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isAckNeeded = false;
            this->shouldAudiblyNotify = false;
            this->shouldExpandBanner = false;
            this->shouldLog = false;
            this->shouldNotify = false;
            this->shouldPopupBanner = false;
            VxZeroArray(this->name);
            VxZeroArray(this->servicePropertyId);
            VxZeroArray(this->serviceType);
            VxZeroArray(this->sourceDeviceId);
            VxZeroArray(this->type);
            VxZeroArray(this->typeOpposite);
            this->notificationIds = nullptr;
            this->autoAcknowledgeTime = 0;
            this->audibleLoopDelay = 0;
            this->audiblePlayCount = 0;
            this->notificationIdSize = 0;
            this->severity = 0;
            this->snoozeIntervalSize = 0;
            this->sourceDeviceTypesSize = 0;
            this->snoozeIntervals = nullptr;
            this->sourceDeviceTypes = nullptr;
        }
    };
}

#endif // IVxSituation_h__
