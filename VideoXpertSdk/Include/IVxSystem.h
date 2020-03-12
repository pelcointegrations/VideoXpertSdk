#ifndef IVxSystem_h__
#define IVxSystem_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxBookmark.h"
#include "IVxDataObject.h"
#include "IVxDevice.h"
#include "IVxEvent.h"
#include "IVxExport.h"
#include "IVxLicense.h"
#include "IVxMonitor.h"
#include "IVxLog.h"
#include "IVxRole.h"
#include "IVxSituation.h"
#include "IVxTag.h"
#include "IVxTimeTable.h"
#include "VxCollection.h"
#include "VxNewBookmark.h"
#include "VxNewDataObject.h"
#include "VxNewEvent.h"
#include "VxNewExport.h"
#include "VxNewMember.h"
#include "VxNewSituation.h"
#include "VxNewTag.h"
#include "VxNewUser.h"

namespace VxSdk {
    struct VxNewTimeTable;
    struct VxNewDevice;

    /// <summary>
    /// Represents a VideoXpert system and allows the user to manage the system and devices.
    /// </summary>
    struct IVxSystem {
    public:
        /// <summary>
        /// Acknowledge all events.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AcknowledgeAllEvents() const = 0;
        /// <summary>
        /// Adds a new analytic session.
        /// </summary>
        /// <param name="newAnalyticSession">The new analytic session to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddAnalyticSession(VxNewAnalyticSession& newAnalyticSession) const = 0;
        /// <summary>
        /// Adds a new bookmark on the VideoXpert system.
        /// </summary>
        /// <param name="newBookmark">The new bookmark to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddBookmark(VxNewBookmark& newBookmark) const = 0;
        /// <summary>
        /// Creates a new data object.
        /// </summary>
        /// <param name="newDataObject">The new data object to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDataObject(VxNewDataObject& newDataObject) const = 0;
        /// <summary>
        /// Adds a device to the VideoXpert system.
        /// </summary>
        /// <param name="newDevice">The new device to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDevice(VxNewDevice& newDevice) const = 0;
        /// <summary>
        /// Creates a new drawing.
        /// </summary>
        /// <param name="newDrawing">The new drawing to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddDrawing(VxNewDrawing& newDrawing) const = 0;
        /// <summary>
        /// Adds a new manual recording to the VideoXpert system.
        /// </summary>
        /// <param name="newManualRecording">The new manual recording to be added to the system.</param>
        /// <param name="manualRecordingItem">
        /// <c>nullptr</c> if it fails, else the new <see cref="IVxManualRecording"/>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddManualRecording(VxNewManualRecording& newManualRecording, IVxManualRecording*& manualRecordingItem) const = 0;
        /// <summary>
        /// Adds a new member system to be aggregated.
        /// </summary>
        /// <param name="newMember">The new member system to be aggregated.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddMember(VxNewMember& newMember) const = 0;
        /// <summary>
        /// Adds a new role to the system.
        /// </summary>
        /// <param name="roleName">The new role to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddRole(const char* roleName) const = 0;
        /// <summary>
        /// Adds a new rule to the system.
        /// </summary>
        /// <param name="newRule">The new rule to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddRule(VxNewRule& newRule) const = 0;
        /// <summary>
        /// Adds a new schedule to the system.
        /// </summary>
        /// <param name="newSchedule">The new schedule to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddSchedule(VxNewSchedule& newSchedule) const = 0;
        /// <summary>
        /// Adds a new situation to the system.
        /// </summary>
        /// <param name="newSituation">The new situation to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddSituation(VxNewSituation& newSituation) const = 0;
        /// <summary>
        /// Adds a new tag to the system.
        /// </summary>
        /// <param name="newTag">The new tag to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddTag(VxNewTag& newTag) const = 0;
        /// <summary>
        /// Adds a new time table to the system.
        /// </summary>
        /// <param name="newTimeTable">The new time table to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddTimeTable(VxNewTimeTable& newTimeTable) const = 0;
        /// <summary>
        /// Adds a new user to the system.
        /// </summary>
        /// <param name="newUser">The new user to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddUser(VxNewUser& newUser) const = 0;
        /// <summary>
        /// Creates a new export on the VideoXpert system.
        /// </summary>
        /// <param name="newExport">The new export to be added to the system.</param>
        /// <param name="exportItem"><c>nullptr</c> if it fails, else the new <see cref="IVxExport"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateExport(VxNewExport& newExport, IVxExport*& exportItem) const = 0;
        /// <summary>
        /// Adds a new monitor to the system.
        /// </summary>
        /// <param name="newMonitor">The new monitor to be added to the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateMonitor(VxNewMonitor& newMonitor) const = 0;
        /// <summary>
        /// Adds a new monitor wall to the system.
        /// </summary>
        /// <param name="monitorWallName">The name of the new monitor wall to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateMonitorWall(const char* monitorWallName) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Gets the access points residing on the system.
        /// <para>Available filters: kAdvancedQuery, kHasStatus, kId, kModifiedSince, kName, kState, kType.</para>
        /// </summary>
        /// <param name="accessPointCollection">
        /// A <see cref="VxCollection"/> of the access points residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAccessPoints(VxCollection<IVxAccessPoint**>& accessPointCollection) const = 0;
        /// <summary>
        /// Gets the alarm inputs residing on the system.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kState.</para>
        /// </summary>
        /// <param name="alarmInputCollection">
        /// A <see cref="VxCollection"/> of the alarm inputs residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAlarmInputs(VxCollection<IVxAlarmInput**>& alarmInputCollection) const = 0;
        /// <summary>
        /// Gets the analytic sessions on this system.
        /// <para>Available filters: kAdvancedQuery, kDataSourceId, kDeviceId, kId, kModifiedSince.</para>
        /// </summary>
        /// <param name="analyticSessionCollection">
        /// A <see cref="VxCollection"/> of the analytic sessions on this system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticSessions(VxCollection<IVxAnalyticSession**>& analyticSessionCollection) const = 0;
        /// <summary>
        /// Gets the authentication configuration.
        /// </summary>
        /// <param name="authConfig">The authentication configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAuthenticationConfiguration(IVxConfiguration::Auth*& authConfig) const = 0;
        /// <summary>
        /// Gets the current bookmark automatic unlock time value.
        /// </summary>
        /// <param name="autoUnlockTime">The bookmark auto-unlock time (in days).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetBookmarkAutoUnlockTime(int& autoUnlockTime) const = 0;
        /// <summary>
        /// Gets the bookmark configuration.
        /// </summary>
        /// <param name="bookmarkConfig">The bookmark configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetBookmarkConfiguration(IVxConfiguration::Bookmark*& bookmarkConfig) const = 0;
        /// <summary>
        /// Gets the bookmarks residing on the system.
        /// <para>
        /// Available filters: kAdvancedQuery, kDataSourceId, kDataSourceType, kDescription, kGroupId, kId, kLocked,
        /// kModifiedSince, kName, kSearchEndTime, kSearchStartTime, kTime.
        /// </para>
        /// </summary>
        /// <param name="bookmarkCollection">
        /// A <see cref="VxCollection"/> of the bookmarks residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetBookmarks(VxCollection<IVxBookmark**>& bookmarkCollection) const = 0;
        /// <summary>
        /// Gets the cluster configuration.
        /// </summary>
        /// <param name="clusterConfig">The cluster configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetClusterConfiguration(IVxConfiguration::Cluster*& clusterConfig) const = 0;
        /// <summary>
        /// Gets the user currently accessing the system.
        /// </summary>
        /// <param name="user">The user currently accessing the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetCurrentUser(IVxUser*& user) const = 0;
        /// <summary>
        /// Gets the data objects residing on the system.
        /// <para>Available filters: kClientType, kModifiedSince, kOwned, kOwner.</para>
        /// </summary>
        /// <param name="dataObjectCollection">
        /// A <see cref="VxCollection"/> of data objects residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataObjects(VxCollection<IVxDataObject**>& dataObjectCollection) const = 0;
        /// <summary>
        /// Gets the data sources from the VideoXpert system.
        /// <para>
        /// Available filters: kAdvancedQuery, kAllTags, kCapturing, kCommissioned, kEnabled, kEncoding,
        /// kHasFolderTags, kId, kIp, kManualRecording, kModifiedSince, kName, kNumber, kRecording, kState, kType,
        /// kUnassigned.
        /// </para>
        /// </summary>
        /// <param name="dataSourceCollection">
        /// A <see cref="VxCollection"/> of the data sources associated with the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the data storages residing on the system.
        /// <para>Available filters: kAdvancedQuery, kCommissioned, kId, kModifiedSince, kName, kType.</para>
        /// </summary>
        /// <param name="dataStorageCollection">
        /// A <see cref="VxCollection"/> of data storages residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorages(VxCollection<IVxDataStorage**>& dataStorageCollection) const = 0;
        /// <summary>
        /// Gets the device assignments residing on the system.
        /// <para>Available filters: kDataSourceId, kDataStorageId, kDeviceId, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceAssignmentCollection">A <see cref="VxCollection"/> of the device assignments.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDeviceAssignments(VxCollection<IVxDeviceAssignment**>& deviceAssignmentCollection) const = 0;
        /// <summary>
        /// Gets the devices from the VideoXpert system.
        /// <para>
        /// Available filters: kAdvancedQuery, kCommissioned, kDriverType, kHasStatus, kId, kIp, kModel,
        /// kModifiedSince, kName, kSerial, kState, kType, kVendor, kVersion.
        /// </para>
        /// </summary>
        /// <param name="deviceCollection">
        /// A <see cref="VxCollection"/> of the devices associated with the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDevices(VxCollection<IVxDevice**>& deviceCollection) const = 0;
        /// <summary>
        /// Gets the drawings from the VideoXpert system.
        /// <para>Available filters: kAdvancedQuery, kImageType, kModifiedSince, kName, kProvider.</para>
        /// </summary>
        /// <param name="drawingCollection">
        /// A <see cref="VxCollection"/> of the drawings associated with the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDrawings(VxCollection<IVxDrawing**>& drawingCollection) const = 0;
        /// <summary>
        /// Gets all of the available device drivers on this system.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince, kName, kVendor, kVersion.</para>
        /// </summary>
        /// <param name="driverCollection">A <see cref="VxCollection"/> of available drivers.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDrivers(VxCollection<IVxDriver**>& driverCollection) const = 0;
        /// <summary>
        /// Gets the events residing on the system.
        /// <para>
        /// Available filters: kAdvancedQuery, kAckState, kAckUser, kGeneratorDeviceId, kId, kModifiedSince, kNotifies,
        /// kSearchEndTime, kSearchStartTime, kSeverity, kSituationType, kSourceDeviceId, kSourceUserName, kTime.
        /// </para>
        /// </summary>
        /// <param name="eventCollection">A <see cref="VxCollection"/> of the events residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetEvents(VxCollection<IVxEvent**>& eventCollection) const = 0;
        /// <summary>
        /// Gets the exports residing on the system.
        /// <para>
        /// Available filters: kDataSourceAllTags, kDataSourceAllPrivateTags, kDataSourceName, kDataSourceNumber,
        /// kModifiedSince, kName, kOwner, kPercentComplete, kSize, kStatus, kTrashed.
        /// </para>
        /// </summary>
        /// <param name="exportCollection">A <see cref="VxCollection"/> of the exports residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetExports(VxCollection<IVxExport**>& exportCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this system.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the LDAP configuration.
        /// </summary>
        /// <param name="ldapConfig">The LDAP configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLdapConfiguration(IVxConfiguration::Ldap*& ldapConfig) const = 0;
        /// <summary>
        /// Gets the license for the system.
        /// </summary>
        /// <param name="license">The license for the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLicense(IVxLicense*& license) const = 0;
        /// <summary>
        /// Gets the manual recordings residing on the system.
        /// <para>Available filters: kAdvancedQuery, kDataSourceId, kId, kModifiedSince, kOwner.</para>
        /// </summary>
        /// <param name="manualRecordingCollection">
        /// A <see cref="VxCollection"/> of the manual recordings residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetManualRecordings(VxCollection<IVxManualRecording**>& manualRecordingCollection) const = 0;
        /// <summary>
        /// Gets the member systems that this system is aggregating.
        /// <para>Available filters: kAdvancedQuery, kHost, kId, kModifiedSince, kName, kState.</para>
        /// </summary>
        /// <param name="memberCollection">
        /// A <see cref="VxCollection"/> of the aggregated member systems.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMembers(VxCollection<IVxMember**>& memberCollection) const = 0;
        /// <summary>
        /// Gets the monitors residing on the system.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kNumber.</para>
        /// </summary>
        /// <param name="monitorCollection">
        /// A <see cref="VxCollection"/> of the monitors residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitors(VxCollection<IVxMonitor**>& monitorCollection) const = 0;
        /// <summary>
        /// Gets the monitor walls residing on the system.
        /// <para>Available filters: kAdvancedQuery, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="monitorWallCollection">
        /// A <see cref="VxCollection"/> of the monitor wallss residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitorWalls(VxCollection<IVxMonitorWall**>& monitorWallCollection) const = 0;
        /// <summary>
        /// Gets the relay outputs residing on the system.
        /// <para>Available filters: kAdvancedQuery, kEnabled, kId, kModifiedSince, kName, kState.</para>
        /// </summary>
        /// <param name="relayOutputCollection">
        /// A <see cref="VxCollection"/> of the relay outputs residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRelayOutputs(VxCollection<IVxRelayOutput**>& relayOutputCollection) const = 0;
        /// <summary>
        /// Gets the roles residing on the system.
        /// <para>Available filters: kAdvancedQuery, kId, kInternal, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="roleCollection">A <see cref="VxCollection"/> of roles residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRoles(VxCollection<IVxRole**>& roleCollection) const = 0;
        /// <summary>
        /// Gets the rules residing on the system.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kNumber.</para>
        /// </summary>
        /// <param name="ruleCollection">A <see cref="VxCollection"/> of rules residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRules(VxCollection<IVxRule**>& ruleCollection) const = 0;
        /// <summary>
        /// Gets the schedules residing on the system.
        /// <para>Available filters: kAdvancedQuery, kDataSourceId, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="scheduleCollection">A <see cref="VxCollection"/> of schedules residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSchedules(VxCollection<IVxSchedule**>& scheduleCollection) const = 0;
        /// <summary>
        /// Gets the general server configuration.
        /// </summary>
        /// <param name="serverConfig">The server configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetServerConfiguration(IVxConfiguration::Server*& serverConfig) const = 0;
        /// <summary>
        /// Gets the situations residing on the system.
        /// <para>
        /// Available filters: kAdvancedQuery, kAudibleNotify, kHasProperty, kLog, kModifiedSince, kName, kNotify,
        /// kServicePropertyId, kSeverity, kSourceDeviceId, kType.
        /// </para>
        /// </summary>
        /// <param name="situationCollection">
        /// A <see cref="VxCollection"/> of the situations residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSituations(VxCollection<IVxSituation**>& situationCollection) const = 0;
        /// <summary>
        /// Gets the SMTP configuration.
        /// </summary>
        /// <param name="smtpConfig">The SMTP configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSmtpConfiguration(IVxConfiguration::Smtp*& smtpConfig) const = 0;
        /// <summary>
        /// Gets the SNMP agent configuration.
        /// </summary>
        /// <param name="snmpConfig">The SNMP agent configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSnmpConfiguration(IVxConfiguration::Snmp*& snmpConfig) const = 0;
        /// <summary>
        /// Gets the tags residing on the system.
        /// <para>
        /// Available filters: kAdvancedQuery, kFolder, kId, kModifiedSince, kName, kOwned, kOwner, kParentId,
        /// kResourceId, kResourceType.
        /// </para>
        /// </summary>
        /// <param name="tagCollection">A <see cref="VxCollection"/> of tags residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTags(VxCollection<IVxTag**>& tagCollection) const = 0;
        /// <summary>
        /// Gets the time tables residing on the system.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="timeTableCollection">
        /// A <see cref="VxCollection"/> of time tables residing on the system.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTimeTables(VxCollection<IVxTimeTable**>& timeTableCollection) const = 0;
        /// <summary>
        /// Gets the Twilio SMS configuration.
        /// </summary>
        /// <param name="twilioConfig">The Twilio SMS configuration.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTwilioConfiguration(IVxConfiguration::Twilio*& twilioConfig) const = 0;
        /// <summary>
        /// Gets the users residing on the system.
        /// <para>Available filters: kAdvancedQuery, kFirstName, kLastName, kModifiedSince, kName.</para>
        /// </summary>
        /// <param name="userCollection">A <see cref="VxCollection"/> of users residing on the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetUsers(VxCollection<IVxUser**>& userCollection) const = 0;
        /// <summary>
        /// Inserts a new event into the system.
        /// </summary>
        /// <param name="newEvent">The new event to be injected into the system.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value InsertEvent(VxNewEvent& newEvent) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the bookmark automatic unlock time, which will automatically unlock any locked bookmark that has an
        /// <see cref="IVxBookmarkLock::endTime"/> older than this number of days. If 0, no automatic unlock will be
        /// performed.
        /// </summary>
        /// <param name="autoUnlockTime">The bookmark auto-unlock time (in days).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetBookmarkAutoUnlockTime(int autoUnlockTime) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Start receiving internal event notifications sent by the VxSDK.
        /// </summary>
        /// <param name="callback">The callback to be used when an internal event is received.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StartInternalNotifications(VxInternalEventCallback callback) const = 0;
        /// <summary>
        /// Start receiving event notifications using the settings for the current user.
        /// </summary>
        /// <param name="callback">The callback to be used when an event is received.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StartNotifications(VxEventCallback callback) const = 0;
        /// <summary>
        /// Start receiving event notifications by situation type, regardless of user settings.
        /// </summary>
        /// <param name="callback">The callback to be used when an event is received.</param>
        /// <param name="situationCollection">The situations to subscribe to.</param>
        /// <param name="userNotification"><c>true</c> to receive user role notifications, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StartNotifications(VxEventCallback callback, VxCollection<IVxSituation**>& situationCollection, bool userNotification = false) const = 0;
        /// <summary>
        /// Stop receiving all internal event notifications.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StopInternalNotifications() const = 0;
        /// <summary>
        /// Stop receiving all event notifications.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value StopNotifications() const = 0;
        /// <summary>
        /// Validates member administrator credentials.
        /// </summary>
        /// <param name="isValid"><c>true</c> if the administrator credentials are determined to be valid, otherwise <c>false</c>.</param>
        /// <param name="host">The host address.</param>
        /// <param name="port">The host port.</param>
        /// <param name="username">The username for access to the member.</param>
        /// <param name="password">The password for access to the member.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of validating the credentials.</returns>
        virtual VxResult::Value ValidateMember(bool& isValid, const char* host, int port, const char* username, const char* password) = 0;

    public:
        /// <summary>
        /// The grace license expiration time (if applicable).
        /// </summary>
        char graceLicenseExpirationTime[64];
        /// <summary>
        /// The unique identifier of the VideoXpert system.
        /// </summary>
        char id[64];
        /// <summary>
        /// The friendly name of the VideoXpert system.
        /// </summary>
        char name[64];

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            VxZeroArray(this->graceLicenseExpirationTime);
            VxZeroArray(this->id);
            VxZeroArray(this->name);
        }
    };
}

#endif // IVxSystem_h__
