#ifndef IVxDevice_h__
#define IVxDevice_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "IVxAccessPoint.h"
#include "IVxAlarmInput.h"
#include "IVxDataSource.h"
#include "IVxLog.h"
#include "IVxMonitor.h"
#include "IVxRelayOutput.h"
#include "VxCollection.h"
#include "IVxAnalyticSession.h"

namespace VxSdk {
    struct IVxDbBackups;
    struct IVxDataStorage;
    struct IVxDeviceAssignment;

    /// <summary>
    /// Represents a particular physical device in the system.
    /// </summary>
    struct IVxDevice {
    public:
        /// <summary>
        /// Adds a new analytic session.
        /// </summary>
        /// <param name="newAnalyticSession">The new analytic session to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddAnalyticSession(VxNewAnalyticSession& newAnalyticSession) const = 0;
        /// <summary>
        /// Gets a value indicating whether this device is capable of generating logs.
        /// </summary>
        /// <param name="canCreateLogs">
        /// <c>true</c> if this device is capable of generating logs, <c>false</c> if not.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CanCreateLogs(bool& canCreateLogs) const = 0;
        /// <summary>
        /// Creates a new log, the contents of which shall be determined by the server by default.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateLog() const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Remove the device and its hosted data sources and data storages. If the device is assigned to a data
        /// storage, it shall be unassigned.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value DeleteDevice() const = 0;
        /// <summary>
        /// Gets the access points residing on the device.
        /// <para>Available filters: kAdvancedQuery, kHasStatus, kId, kModifiedSince, kName, kState, kType.</para>
        /// </summary>
        /// <param name="accessPointCollection">
        /// A <see cref="VxCollection"/> of the access points residing on the device.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAccessPoints(VxCollection<IVxAccessPoint**>& accessPointCollection) const = 0;
        /// <summary>
        /// Gets the alarm inputs hosted by this device.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kState.</para>
        /// </summary>
        /// <param name="alarmInputCollection">
        /// A <see cref="VxCollection"/> of the alarm inputs hosted by this device.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAlarmInputs(VxCollection<IVxAlarmInput**>& alarmInputCollection) const = 0;
        /// <summary>
        /// Gets the analytic sessions hosted by this device.
        /// <para>Available filters: kAdvancedQuery, kDataSourceId, kDeviceId, kId, kModifiedSince.</para>
        /// </summary>
        /// <param name="analyticSessionCollection">
        /// A <see cref="VxCollection"/> of the analytic sessions hosted by this device.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticSessions(VxCollection<IVxAnalyticSession**>& analyticSessionCollection) const = 0;
        /// <summary>
        /// Gets the data sources hosted by this device.
        /// <para>
        /// Available filters: kAdvancedQuery, kAllTags, kCapturing, kCommissioned, kEnabled, kEncoding, kHasFolderTags,
        /// kId, kIp, kManualRecording, kModifiedSince, kName, kNumber, kRecording, kState, kType, kUnassigned.
        /// </para>
        /// </summary>
        /// <param name="dataSourceCollection">A <see cref="VxCollection"/> of the associated data sources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataSources(VxCollection<IVxDataSource**>& dataSourceCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDataStorage"/> hosted by this device, if any.
        /// </summary>
        /// <param name="dataStorage">
        /// The <see cref="IVxDataStorage"/> hosted by this device if available, otherwise <c>nullptr</c>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorage(IVxDataStorage*& dataStorage) const = 0;
        /// <summary>
        /// Gets the database backup information for this device, if any.
        /// </summary>
        /// <param name="databaseBackups">
        /// The <see cref="IVxDbBackups"/> for the device if available, otherwise <c>nullptr</c>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDatabaseBackups(IVxDbBackups*& databaseBackups) const = 0;
        /// <summary>
        /// Gets the assignments to a data storage for this device.
        /// <para>Available filters: kDataSourceId, kDataStorageId, kDeviceId, kModifiedSince.</para>
        /// </summary>
        /// <param name="deviceAssignmentCollection">A <see cref="VxCollection"/> of the device assignments.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDeviceAssignments(VxCollection<IVxDeviceAssignment**>& deviceAssignmentCollection) const = 0;
        /// <summary>
        /// Gets the diagnostic information for this device.
        /// </summary>
        /// <param name="diagnostics">The diagnostic information.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDiagnostics(VxDiagnostics*& diagnostics) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the logs for this device.
        /// <para>Available filters: kInitiated, kModifiedSince.</para>
        /// </summary>
        /// <param name="logCollection">A <see cref="VxCollection"/> of the logs present on this device.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLogs(VxCollection<IVxLog**>& logCollection) const = 0;
        /// <summary>
        /// Gets the monitors residing on the device.
        /// <para>Available filters: kAdvancedQuery, kId, kModifiedSince, kName, kNumber.</para>
        /// </summary>
        /// <param name="monitorCollection">
        /// A <see cref="VxCollection"/> of the monitors residing on the device.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMonitors(VxCollection<IVxMonitor**>& monitorCollection) const = 0;
        /// <summary>
        /// Gets the relay outputs hosted by this device.
        /// <para>Available filters: kAdvancedQuery, kEnabled, kId, kModifiedSince, kName, kState.</para>
        /// </summary>
        /// <param name="relayOutputCollection">
        /// A <see cref="VxCollection"/> of the relay outputs hosted by this device.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRelayOutputs(VxCollection<IVxRelayOutput**>& relayOutputCollection) const = 0;
        /// <summary>
        /// Gets a value indicating whether this device provides any diagnostic information.
        /// </summary>
        /// <param name="hasDiagnostics">
        /// <c>true</c> if this device provides diagnostic information, <c>false</c> if not.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value HasDiagnostics(bool& hasDiagnostics) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Replace an offline device with a new device. Not available for all types of devices.
        /// </summary>
        /// <param name="replacementDeviceId">The ID of the replacement device</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of replacing this device.</returns>
        virtual VxResult::Value Replace(const char* replacementDeviceId) = 0;
        /// <summary>
        /// Sets the port property.
        /// </summary>
        /// <param name="port">The new port value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDevicePort(int port) = 0;
        /// <summary>
        /// Sets the driver type identifier property.
        /// </summary>
        /// <param name="driverTypeId">The new driver type identifier value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetDriverTypeId(char driverTypeId[64]) = 0;
        /// <summary>
        /// Sets the endpoints property, which is a list of source URIs that the device will support.
        /// </summary>
        /// <param name="endpoints">The source URIs.</param>
        /// <param name="endpointsSize"> The size of <see cref="endpoints"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetEndpoints(char** endpoints, int endpointsSize) = 0;
        /// <summary>
        /// Sets the hostname property. If set, takes precedence over the ip.
        /// </summary>
        /// <param name="hostname">The new hostname value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetHostname(char hostname[256]) = 0;
        /// <summary>
        /// Sets the ip property.
        /// </summary>
        /// <param name="ip">The new ip value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetIp(char ip[64]) = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the password property.
        /// </summary>
        /// <param name="password">The new password value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPassword(char password[64]) = 0;
        /// <summary>
        /// Sets the username property.
        /// </summary>
        /// <param name="username">The new username value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetUsername(char username[64]) = 0;
        /// <summary>
        /// Sets the version property.
        /// </summary>
        /// <param name="version">The new version value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetVersion(char version[64]) = 0;
        /// <summary>
        /// Silences all audible alarms on the device.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value Silence() const = 0;
        /// <summary>
        /// Triggers a refresh of this <see cref="IVxDevice"/> on the VideoXpert system; updating it
        /// by retrieving the latest information directly from the device.
        /// </summary>
        /// <returns>
        /// The <see cref="VxResult::Value">Result</see> of refreshing the <see cref="IVxDevice"/>.
        /// </returns>
        virtual VxResult::Value TriggerRefresh() = 0;

    public:
        /// <summary>
        /// Indicates whether the device is commissioned.
        /// </summary>
        bool isCommissioned;
        /// <summary>
        /// Indicates whether a license is required for commissioning the device.
        /// </summary>
        bool isLicenseRequired;
        /// <summary>
        /// The driver device identifier.
        /// </summary>
        char driverDeviceId[64];
        /// <summary>
        /// The driver type identifier used for device communication.
        /// </summary>
        char driverTypeId[64];
        /// <summary>
        /// Hostname of the device. If set, takes precedence over the ip. The combination of hostname, ip, port and
        /// type must be unique.
        /// </summary>
        char hostname[256];
        /// <summary>
        /// The unique identifier of the device.
        /// </summary>
        char id[64];
        /// <summary>
        /// The IP of the device.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The device model name.
        /// </summary>
        char model[64];
        /// <summary>
        /// The friendly name of the device.
        /// </summary>
        char name[64];
        /// <summary>
        /// The serial number of the device.
        /// </summary>
        char serial[64];
        /// <summary>
        /// The account username used to communicate with the device, if any.
        /// </summary>
        char username[64];
        /// <summary>
        /// The device vendor, if any.
        /// </summary>
        char vendor[64];
        /// <summary>
        /// The current version of software running on the device.
        /// </summary>
        char version[64];
        /// <summary>
        /// The virtual IP of the device, if any.
        /// </summary>
        char virtualIp[64];
        /// <summary>
        /// List of source URIs that the device will support.
        /// </summary>
        char** endpoints;
        /// <summary>
        /// List of supported features that may be licensed for use by this device.
        /// </summary>
        char** licensableFeatures;
        /// <summary>
        /// List of supported features that are currently licensed for use by this device.
        /// </summary>
        char** licensedFeatures;
        /// <summary>
        /// The size of <see cref="endpoints"/>.
        /// </summary>
        int endpointsSize;
        /// <summary>
        /// The size of <see cref="licensableFeatures"/>.
        /// </summary>
        int licensableFeaturesSize;
        /// <summary>
        /// The size of <see cref="licensedFeatures"/>.
        /// </summary>
        int licensedFeaturesSize;
        /// <summary>
        /// The host port.
        /// </summary>
        int port;
        /// <summary>
        /// The size of <see cref="status"/>.
        /// </summary>
        int statusSize;
        /// <summary>
        /// The current operational state of the device.
        /// </summary>
        VxDeviceState::Value state;
        /// <summary>
        /// The current device status.
        /// </summary>
        VxDeviceStatus::Value* status;
        /// <summary>
        /// The type of device.
        /// </summary>
        VxDeviceType::Value type;

    public:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isCommissioned = false;
            this->isLicenseRequired = false;
            VxZeroArray(this->driverDeviceId);
            VxZeroArray(this->driverTypeId);
            VxZeroArray(this->hostname);
            VxZeroArray(this->id);
            VxZeroArray(this->ip);
            VxZeroArray(this->model);
            VxZeroArray(this->name);
            VxZeroArray(this->serial);
            VxZeroArray(this->username);
            VxZeroArray(this->vendor);
            VxZeroArray(this->version);
            VxZeroArray(this->virtualIp);
            this->port = 0;
            this->endpointsSize = 0;
            this->licensableFeaturesSize = 0;
            this->licensedFeaturesSize = 0;
            this->statusSize = 0;
            this->endpoints = nullptr;
            this->licensableFeatures = nullptr;
            this->licensedFeatures = nullptr;
            this->status = nullptr;
            this->state = VxDeviceState::kUnknown;
            this->type = VxDeviceType::kUnknown;
        }
    };
}

#endif // IVxDevice_h__