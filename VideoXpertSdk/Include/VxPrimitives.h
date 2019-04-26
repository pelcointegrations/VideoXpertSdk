#ifndef VxPrimitives_h__
#define VxPrimitives_h__

namespace VxSdk {
    /// <summary>
    /// Global Defines
    /// </summary>
    #define MAX_UUID_LENGTH         1024

    /// <summary>
    /// Values that represent the current acknowledgement state of an event.
    /// </summary>
    struct VxAckState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The event needs acknowledgement.</summary>
            kAckNeeded,
            /// <summary>The event is acknowledged.</summary>
            kAcked,
            /// <summary>The event is auto-acknowledged.</summary>
            kAutoAcked,
            /// <summary>No event acknowledgement is needed.</summary>
            kNoAckNeeded,
            /// <summary>The event has been silenced.</summary>
            kSilenced
        };
    };

    /// <summary>
    /// Values that represent the state of an alarm input.
    /// </summary>
    struct VxAlarmState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The alarm input is active.</summary>
            kActive,
            /// <summary>The alarm input is inactive.</summary>
            kInactive
        };
    };

    /// <summary>
    /// Values that represent possible monitor layouts.
    /// </summary>
    struct VxCellLayout {
        enum Value {
            /// <summary>A 1x1 monitor layout.</summary>
            k1x1,
            /// <summary>A 1x2 monitor layout.</summary>
            k1x2,
            /// <summary>A 2x1 monitor layout.</summary>
            k2x1,
            /// <summary>A 2x2 monitor layout.</summary>
            k2x2,
            /// <summary>A 2x3 monitor layout.</summary>
            k2x3,
            /// <summary>A 3x2 monitor layout.</summary>
            k3x2,
            /// <summary>A 3x3 monitor layout.</summary>
            k3x3,
            /// <summary>A 4x3 monitor layout.</summary>
            k4x3,
            /// <summary>A 4x4 monitor layout.</summary>
            k4x4,
            /// <summary>A 5x5 monitor layout.</summary>
            k5x5,
            /// <summary>A 1 plus 12 monitor layout.</summary>
            k1plus12,
            /// <summary>A 2 plus 8 monitor layout.</summary>
            k2plus8,
            /// <summary>A 3 plus 4 monitor layout.</summary>
            k3plus4,
            /// <summary>A 1 plus 5 monitor layout.</summary>
            k1plus5,
            /// <summary>A 1 plus 7 monitor layout.</summary>
            k1plus7,
            /// <summary>A 12 plus 1 monitor layout.</summary>
            k12plus1,
            /// <summary>A 8 plus 2 monitor layout.</summary>
            k8plus2,
            /// <summary>A 1 plus 1 plus 4 monitor layout.</summary>
            k1plus1plus4,
            /// <summary>A 1 plus 4 tall monitor layout.</summary>
            k1plus4tall,
            /// <summary>A 1 plus 4 wide monitor layout.</summary>
            k1plus4wide,
            /// <summary>A monitor wall layout.</summary>
            kMonitorWall
        };
    };

    /// <summary>
    /// Values that represent collection filter types.
    /// </summary>
    struct VxCollectionFilterItem {
        enum Value {
            /// <summary>No filter.</summary>
            kNone,
            /// <summary>The maximum number of items to return per page.</summary>
            kCount,
            /// <summary>Filter by data source id.</summary>
            kDataSourceId,
            /// <summary>Filter by start time.</summary>
            kSearchStartTime,
            /// <summary>Filter by end time.</summary>
            kSearchEndTime,
            /// <summary>Filter by name.</summary>
            kName,
            /// <summary>Filter by id.</summary>
            kId,
            /// <summary>The start index.</summary>
            kStart,
            /// <summary>Filter by type.</summary>
            kType,
            /// <summary>Filter by situation type.</summary>
            kSituationType,
            /// <summary>True to return only items that are not assigned.</summary>
            kUnassigned,
            /// <summary>Filter by data source number.</summary>
            kDataSourceNumber,
            /// <summary>Filter by the description value.</summary>
            kDescription,
            /// <summary>Return items that have been modified since the given time.</summary>
            kModifiedSince,
            /// <summary>Filter by the time value.</summary>
            kTime,
            /// <summary>Filter by the end time value.</summary>
            kEndTime,
            /// <summary>Filter by the start time value.</summary>
            kStartTime,
            /// <summary>Filter by the event value.</summary>
            kEvent,
            /// <summary>Filter by the framerate value.</summary>
            kFramerate,
            /// <summary>Filter by the client type value.</summary>
            kClientType,
            /// <summary>True to return only owned items.</summary>
            kOwned,
            /// <summary>Filter by owner.</summary>
            kOwner,
            /// <summary>Filter by the username value.</summary>
            kUsername,
            /// <summary>Filter by comma-separated list of tag names.</summary>
            kAllTags,
            /// <summary>True to return only items that are capturing.</summary>
            kCapturing,
            /// <summary>Filter by IP.</summary>
            kIp,
            /// <summary>Filter by number.</summary>
            kNumber,
            /// <summary>True to return only items that are recording.</summary>
            kRecording,
            /// <summary>Filter by the state value.</summary>
            kState,
            /// <summary>True to return only items that are commissioned.</summary>
            kCommissioned,
            /// <summary>Filter by model.</summary>
            kModel,
            /// <summary>Filter by serial.</summary>
            kSerial,
            /// <summary>Filter by vendor.</summary>
            kVendor,
            /// <summary>Filter by version.</summary>
            kVersion,
            /// <summary>Filter by the ack state value.</summary>
            kAckState,
            /// <summary>Filter by the ack user value.</summary>
            kAckUser,
            /// <summary>Filter by generator device id.</summary>
            kGeneratorDeviceId,
            /// <summary>True to return items that were sent to the client.</summary>
            kNotifies,
            /// <summary>Filter by severity.</summary>
            kSeverity,
            /// <summary>Filter by source device id.</summary>
            kSourceDeviceId,
            /// <summary>Filter by source username.</summary>
            kSourceUserName,
            /// <summary>Filter by the percent complete value.</summary>
            kPercentComplete,
            /// <summary>Filter by the size value.</summary>
            kSize,
            /// <summary>Filter by status.</summary>
            kStatus,
            /// <summary>Filter by resource id.</summary>
            kResourceId,
            /// <summary>True to return items that are internal to the server and read-only</summary>
            kInternal,
            /// <summary>Filter by the audible notification value.</summary>
            kAudibleNotify,
            /// <summary>Filter by the log value.</summary>
            kLog,
            /// <summary>Filter by the notify value.</summary>
            kNotify,
            /// <summary>Filter by resource type.</summary>
            kResourceType,
            /// <summary>True to return only items that are linked.</summary>
            kLinked,
            /// <summary>Filter by comma-separated list of tag names owned by the current user.</summary>
            kAllPrivateTags,
            /// <summary>True to return items that are currently being manually recorded.</summary>
            kManualRecording,
            /// <summary>Filter by first name.</summary>
            kFirstName,
            /// <summary>Filter by last name.</summary>
            kLastName,
            /// <summary>Filter by items that have a specific property defined.</summary>
            kHasProperty,
            /// <summary>Filter by items that have a specific status.</summary>
            kHasStatus,
            /// <summary>Filter by comma-separated list of tag names.</summary>
            kDataSourceAllTags,
            /// <summary>Filter by comma-separated list of tag names owned by the current user.</summary>
            kDataSourceAllPrivateTags,
            /// <summary>Filter by data source name.</summary>
            kDataSourceName,
            /// <summary>
            /// Filter by the name of the key in the properties map corresponding to the service identifier.
            /// </summary>
            kServicePropertyId,
            /// <summary>Filter by a image type, useful when filtering Drawings.</summary>
            kImageType,
            /// <summary>Filter by advanced query.</summary>
            kAdvancedQuery,
            /// <summary>Filter by all public and private tags (tags_all).</summary>
            kTagsAll,
            /// <summary>True to return only items that are enabled.</summary>
            kEnabled,
            /// <summary>Filter by the intiated time value.</summary>
            kInitiated,
            /// <summary>Filter by data storage id.</summary>
            kDataStorageId,
            /// <summary>True to return only items that have been trashed.</summary>
            kTrashed,
            /// <summary>Filter by data source type.</summary>
            kDataSourceType,
            /// <summary>Filter by device id.</summary>
            kDeviceId,
            /// <summary>Filter by driver type.</summary>
            kDriverType,
            /// <summary>Filter by encoding type.</summary>
            kEncoding,
            /// <summary>True to return only items that are folders.</summary>
            kFolder,
            /// <summary>Filter by group id.</summary>
            kGroupId,
            /// <summary>True to return only items that have folder tags.</summary>
            kHasFolderTags,
            /// <summary>Filter by layer name.</summary>
            kLayerName,
            /// <summary>True to return only items that require a license.</summary>
            kLicenseRequired,
            /// <summary>True to return only items that are locked.</summary>
            kLocked,
            /// <summary>Filter by parent id.</summary>
            kParentId,
            /// <summary>Filter by provider type.</summary>
            kProvider
        };
    };

    /// <summary>
    /// Values that represent the current cluster configuration status.
    /// </summary>
    struct VxConfigStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The cluster is configured.</summary>
            kConfigured,
            /// <summary>The cluster is being configured.</summary>
            kConfiguring,
            /// <summary>Cluster configuration failed.</summary>
            kFailed,
            /// <summary>The cluster is unconfigured.</summary>
            kUnconfigured
        };
    };

    /// <summary>
    /// Values that represent the particular type of a data source.
    /// </summary>
    struct VxDataSourceType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A video data source.</summary>
            kVideo,
            /// <summary>An audio data source.</summary>
            kAudio,
            /// <summary>A metadata data source.</summary>
            kMetadata,
        };
    };

    /// <summary>
    /// Values that represent hardware type of a data storage.
    /// </summary>
    struct VxDataStorageType  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A Digital Sentry device.</summary>
            kDigitalSentry,
            /// <summary>An NSM network video recorder device.</summary>
            kNSM,
            /// <summary>A VideoXpert storage device.</summary>
            kVideoXpertStorage,
            /// <summary>An edge storage device.</summary>
            kEdge
        };
    };

    /// <summary>
    /// Values that represent days of the week.
    /// </summary>
    struct VxDayOfWeek  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Monday.</summary>
            kMonday,
            /// <summary>Tuesday.</summary>
            kTuesday,
            /// <summary>Wednesday.</summary>
            kWednesday,
            /// <summary>Thursday.</summary>
            kThursday,
            /// <summary>Friday.</summary>
            kFriday,
            /// <summary>Saturday.</summary>
            kSaturday,
            /// <summary>Sunday.</summary>
            kSunday
        };
    };

    /// <summary>
    /// Values that represent the operational state of a device.
    /// </summary>
    struct VxDeviceState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The device is offline.</summary>
            kOffline,
            /// <summary>The device is online.</summary>
            kOnline
        };
    };

    /// <summary>
    /// Values that represent the current status of a device.
    /// </summary>
    struct VxDeviceStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Being prepared for use.</summary>
            kInitializing,
            /// <summary>Invalid/missing credentials.</summary>
            kUnauthenticated,
            /// <summary>Device identity mismatch.</summary>
            kIdInconsistent,
            /// <summary>NSM5200 manager.</summary>
            kNsmManager,
            /// <summary>NSM5200 member.</summary>
            kNsmMember
        };
    };

    /// <summary>
    /// Values that represent device types.
    /// </summary>
    struct VxDeviceType {
        enum Value {
            /// <summary>A VideoXpert Accessory Server device.</summary>
            kAcc,
            /// <summary>An Access Control device.</summary>
            kAccessController,
            /// <summary>A VideoXpert all in one device (i.e. VxPro).</summary>
            kAllInOne,
            /// <summary>A camera device.</summary>
            kCamera,
            /// <summary>A VideoXpert Core device.</summary>
            kCore,
            /// <summary>A decoder device.</summary>
            kDecoder,
            /// <summary>An encoder device.</summary>
            kEncoder,
            /// <summary>An external device.</summary>
            kExternal,
            /// <summary>A generic device.</summary>
            kGeneric,
            /// <summary>A VideoXpert MediaGateway device.</summary>
            kMg,
            /// <summary>A monitor device.</summary>
            kMonitor,
            /// <summary>A network storage device.</summary>
            kRecorder,
            /// <summary>A UI device.</summary>
            kUi,
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown
        };
    };

    /// <summary>
    /// Values that represent which provider is associated with a drawing
    /// </summary>
    struct VxDrawingProvider {
        enum Value {
            /// <summary>Unset or unknown provider</summary>
            kUnknown,
            /// <summary>Esri drawing provider</summary>
            kEsri,
            /// <summary>Serenity drawing provider</summary>
            kSerenity
        };
    };

    /// <summary>
    /// Values that represent the format of exported data.
    /// </summary>
    struct VxExportFormat {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>MKV file(s) contained withing a zip file.</summary>
            kMkvZip
        };
    };

    /// <summary>
    /// Values that represent status of an export.
    /// </summary>
    struct VxExportStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The export is in progress.</summary>
            kExporting,
            /// <summary>The export has failed.</summary>
            kFailed,
            /// <summary>The export is queued to start.</summary>
            kPending,
            /// <summary>The export has completed successfully.</summary>
            kSuccessful
        };
    };

    /// <summary>
    /// Values that represent the reason for the current status of an export.
    /// </summary>
    struct VxExportStatusReason {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The export data is unretrievable.</summary>
            kExportDataUnretrievable,
            /// <summary>The export storage is full.</summary>
            kExportStorageFull,
            /// <summary>The export storage is unauthenticated.</summary>
            kExportStorageUnauthenticated,
            /// <summary>The export storage is unavailable.</summary>
            kExportStorageUnavailable
        };
    };

    /// <summary>
    /// Values that represent focus directions.
    /// </summary>
    struct VxFocusDirection {
        enum Value {
            /// <summary>Stop focus movement.</summary>
            kStop,
            /// <summary>Focus farther.</summary>
            kFar,
            /// <summary>Focus nearer.</summary>
            kNear
        };
    };

    /// <summary>
    /// Values that represent the reason for a gap.
    /// </summary>
    struct VxGapReason {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Camera offline.</summary>
            kCameraOffline,
            /// <summary>Not supported.</summary>
            kNotSupported,
            /// <summary>Storage device offline.</summary>
            kStorageOffline,
            /// <summary>Stream loss.</summary>
            kStreamLoss,
            /// <summary>Stream source changed.</summary>
            kStreamSourceChanged,
            /// <summary>Time jump.</summary>
            kTimeJump,
            /// <summary>Transport changed.</summary>
            kTransportChanged,
            /// <summary>Write error.</summary>
            kWriteError
        };
    };

    /// <summary>
    /// Values that represent event types sent from the VxSDK.
    /// </summary>
    struct VxInternalEventType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The connection to the VideoXpert system was lost.</summary>
            kSystemConnectionLost,
            /// <summary>The connection to the VideoXpert system was restored.</summary>
            kSystemConnectionRestored,
            /// <summary>The grace license has expired.</summary>
            kGraceLicenseExpired,
            /// <summary>The license on the system has expired.</summary>
            kSystemLicenseExpired
        };
    };

    /// <summary>
    /// Values that represent iris directions.
    /// </summary>
    struct VxIrisDirection {
        enum Value {
            /// <summary>Stop iris movement.</summary>
            kStop,
            /// <summary>Close the iris.</summary>
            kClose,
            /// <summary>Open the iris.</summary>
            kOpen
        };
    };

    /// <summary>
    /// Values that represent logging severity levels.
    /// </summary>
    struct VxLogLevel  {
        enum Value
        {
            /// <summary>Trace log level.</summary>
            kTrace,
            /// <summary>Debug log level.</summary>
            kDebug,
            /// <summary>Info log level.</summary>
            kInfo,
            /// <summary>Warning log level.</summary>
            kWarning,
            /// <summary>Error log level.</summary>
            kError,
            /// <summary>Fatal log level.</summary>
            kFatal,
            /// <summary>Disable logging.</summary>
            kNone
        };
    };

    /// <summary>
    /// Values that represent motion detection modes.
    /// </summary>
    struct VxMotionMode {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Camera based motion detection.</summary>
            kCamera,
            /// <summary>Motion detection disabled.</summary>
            kDisabled,
            /// <summary>Recorder based motion detection.</summary>
            kRecorder
        };
    };

    /// <summary>
    /// Values that represent available overlays.
    /// </summary>
    struct VxOverlayType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Motion overlay.</summary>
            kMotion
        };
    };

    /// <summary>
    /// Values that represent a permission type.
    /// </summary>
    struct VxPermissionId  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>View live media.</summary>
            kViewLiveMedia,
            /// <summary>Use PTZ mode.</summary>
            kUsePtzMode,
            /// <summary>Lock PTZ mode.</summary>
            kLockPtzMode,
            /// <summary>Record media.</summary>
            kRecordMedia,
            /// <summary>Launch saved views remotely.</summary>
            kLaunchSavedViewsRemotely,
            /// <summary>Access alarms.</summary>
            kAccessAlarms,
            /// <summary>Access relays.</summary>
            kAccessRelays,
            /// <summary>View recorded media.</summary>
            kViewRecordedMedia,
            /// <summary>System bookmarks.</summary>
            kSystemBookmarks,
            /// <summary>System locks.</summary>
            kSystemLocks,
            /// <summary>Export media clips.</summary>
            kExportMediaClips,
            /// <summary>Manage exports.</summary>
            kManageExports,
            /// <summary>Use map.</summary>
            kUseMap,
            /// <summary>View maps.</summary>
            kViewMaps,
            /// <summary>Place cameras on map.</summary>
            kPlaceCamerasOnMap,
            /// <summary>Manage map files.</summary>
            kManageMapFiles,
            /// <summary>Define ptz presets.</summary>
            kDefinePtzPresets,
            /// <summary>Manage camera tours.</summary>
            kManageCameraTours,
            /// <summary>Access user workspaces.</summary>
            kAccessUserWorkspaces,
            /// <summary>Manage system workspaces.</summary>
            kManageSystemWorkspaces,
            /// <summary>AuditUser activity.</summary>
            kAuditUserActivity,
            /// <summary>Multiview qty.</summary>
            kMultiviewQty,
            /// <summary>View event history.</summary>
            kViewEventHistory,
            /// <summary>Handle events.</summary>
            kHandleEvents,
            /// <summary>Configure events.</summary>
            kConfigureEvents,
            /// <summary>Manage user accounts.</summary>
            kManageUserAccounts,
            /// <summary>Assign roles to users.</summary>
            kAssignRolesToUsers,
            /// <summary>Reset user passwords.</summary>
            kResetUserPasswords,
            /// <summary>Manage roles.</summary>
            kManageRoles,
            /// <summary>Manage system tags.</summary>
            kManageSystemTags,
            /// <summary>Manage I/O.</summary>
            kManageIO,
            /// <summary>Manage device licenses.</summary>
            kManageDeviceLicenses,
            /// <summary>Update device software.</summary>
            kUpdateDeviceSoftware,
            /// <summary>Setup edge devices.</summary>
            kSetupEdgeDevices,
            /// <summary>Manage display devices.</summary>
            kManageDisplayDevices,
            /// <summary>Configure monitor wall decoders.</summary>
            kConfigureMonitorWallDecoders,
            /// <summary>Manage system licenses.</summary>
            kManageSystemLicenses,
            /// <summary>Set system locale options.</summary>
            kSetSystemLocaleOptions,
            /// <summary>Define system shortcuts.</summary>
            kDefineSystemShortcuts,
            /// <summary>Configure recording.</summary>
            kConfigureRecording,
            /// <summary>View system health.</summary>
            kViewSystemHealth,
            /// <summary>Manage system servers.</summary>
            kManageSystemServers,
            /// <summary>Manage member systems.</summary>
            kManageMemberSystems
        };
    };

    /// <summary>
    /// Values that represent the type of a phone number.
    /// </summary>
    struct VxPhoneType {
        enum Value {
            /// <summary>Home number.</summary>
            kHome,
            /// <summary>Home fax number.</summary>
            kHomeFax,
            /// <summary>Mobile number.</summary>
            kMobile,
            /// <summary>Other number.</summary>
            kOther,
            /// <summary>Pager number.</summary>
            kPager,
            /// <summary>Work number.</summary>
            kWork,
            /// <summary>Work fax number.</summary>
            kWorkFax
        };
    };

    /// <summary>
    /// Values that represent the video framerate level.
    /// </summary>
    struct VxRecordingFramerate {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Low framerate.</summary>
            kLow,
            /// <summary>Normal framerate.</summary>
            kNormal
        };
    };

    /// <summary>
    /// Values that represent the type of trigger that caused the recording.
    /// </summary>
    struct VxRecordingType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Hardware or software alarm.</summary>
            kAlarm,
            /// <summary>Video analytic (non-motion).</summary>
            kAnalytic,
            /// <summary>General system event.</summary>
            kEvent,
            /// <summary>Manual user initiation.</summary>
            kManual,
            /// <summary>Motion anayltic.</summary>
            kMotion,
            /// <summary>Time-based (continuous); no event.</summary>
            kTimed
        };
    };

    /// <summary>
    /// Values that represent the state of a relay output.
    /// </summary>
    struct VxRelayState {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The relay output is active.</summary>
            kActive,
            /// <summary>The relay output is inactive.</summary>
            kInactive
        };
    };

    /// <summary>
    /// Values that represent the stream rendering types.
    /// </summary>
    struct VxRenderType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Evo renderer.</summary>
            kEvo,
            /// <summary>Optera 180 renderer.</summary>
            kOptera180,
            /// <summary>Optera 270 renderer.</summary>
            kOptera270,
            /// <summary>Optera 360 renderer.</summary>
            kOptera360,
            /// <summary>Standard renderer.</summary>
            kStandard
        };
    };

    /// <summary>
    /// Values that represent a type of resource.
    /// </summary>
    struct VxResourceType  {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>A data source resource.</summary>
            kDataSource,
            /// <summary>A device resource.</summary>
            kDevice,
            /// <summary>A user resource.</summary>
            kUser,
            /// <summary>A drawing resource.</summary>
            kDrawing,
            /// <summary>A data storage resource.</summary>
            kDataStorage,
            /// <summary>A tag resource.</summary>
            kTag,
            /// <summary>A relay output resource.</summary>
            kRelayOutput
        };
    };

    /// <summary>
    /// Values that represent the result of calls to the VideoXpert system.
    /// </summary>
    struct VxResult {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknownError,
            /// <summary>The action was successful.</summary>
            kOK,
            /// <summary>The VideoXpert system version is not supported.</summary>
            kUnsupportedVersion,
            /// <summary>The size value was not sufficient enough to allocate the collection.</summary>
            kInsufficientSize,
            /// <summary>The login credentials were invalid.</summary>
            kInvalidLoginInfo,
            /// <summary>The attempted action is unsupported by the system.</summary>
            kActionUnavailable,
            /// <summary>A parameter was invalid.</summary>
            kInvalidParameters,
            /// <summary>There was an error communicating to the device.</summary>
            kCommunicationError,
            /// <summary>No valid license was found on the VideoXpert system.</summary>
            kInvalidLicense,
            /// <summary>Camera is unavailable, data cannot be retrieved at this time.</summary>
            kCameraUnavailable,
            /// <summary>
            /// No further stream data is currently available (the edge of a currently recording clip has been
            /// reached); more data will be available shortly.
            /// </summary>
            kEdgeOfStream,
            /// <summary>
            /// No further stream data is available (the end of all recorded data has been reached; no further data is
            /// currently be recorded).
            /// </summary>
            kEndOfStream,
            /// <summary>
            /// The server is unable to initiate any new stream sessions due to having reached its stream count
            /// capacity.
            /// </summary>
            kNoAvailableStreams,
            /// <summary>Storage is unavailable, data cannot be retrieved at this time.</summary>
            kStorageUnavailable,
            /// <summary>The data needed to perform the export operation can not be retrieved.</summary>
            kExportDataUnretrievable,
            /// <summary>The export storage location does not have enough free space to store the export.</summary>
            kExportStorageFull,
            /// <summary> The export storage location is not accessible due to invalid credentials.</summary>
            kExportStorageUnauthenticated,
            /// <summary>
            /// The export storage location is not accessible; this may be due to an invalid location, network issue,
            /// or storage issue.
            /// </summary>
            kExportStorageUnavailable,
            /// <summary>
            /// The requested operation is not possible due to a conflict with the resource. Typically this is due to a
            /// violation of a uniqueness property on one of the resource’s fields.
            /// </summary>
            kConflict,
            /// <summary>The server has insufficient resources to satisfy the request.</summary>
            kInsufficientResources,
            /// <summary>
            /// The server is not in an appropriate state to be able to service this request. The server requires
            /// intervention in order to resolve this.
            /// </summary>
            kNotReady,
            /// <summary>
            /// The server is not in an appropriate state to be able to service this request due to an authentication
            /// issue between it and another entity. The server requires intervention in order to resolve this.
            /// </summary>
            kNotReadyUnauthenticated,
            /// <summary>
            /// The server is not in an appropriate state to be able to service this request due to an authorization
            /// issue between it and another entity. The server requires intervention in order to resolve this.
            /// </summary>
            kNotReadyUnauthorized,
            /// <summary>The requested operation failed.</summary>
            kOperationFailed,
            /// <summary>
            /// The server is incapable of handling the client request due to the size of the resulting response. What
            /// constitutes ’too large’ is entirely up to the server.
            /// </summary>
            kResponseTooLarge,
            /// <summary>
            /// The license that was supplied has an activation conflict with an existing license (e.g. duplicate
            /// activation IDs).
            /// </summary>
            kActivationConflict,
            /// <summary>The activation failed due to communication error with the FNO licensing server.</summary>
            kActivationHostNotFound,
            /// <summary>The activation failed.</summary>
            kActivationFailed,
            /// <summary>
            /// The license that was supplied is not compatible with the device and/or system that it is being applied
            /// to.
            /// </summary>
            kIncompatibleLicense,
            /// <summary>
            /// A valid license is available but the available count on that license is fully utilized.
            /// </summary>
            kLicenseCountExceeded,
            /// <summary>
            /// A valid license is required to utilize this method on the resource; no valid license found.
            /// </summary>
            kLicenseRequired,
            /// <summary>Unable to apply the license; valid LDAP administrator credentials are required.</summary>
            kLicenseReqLdapAdmin,
            /// <summary>
            /// Unable to commission (or float) a feature because no valid license is available for it.
            /// </summary>
            kNoLicense,
            /// <summary>
            /// Camera is in use (or the usage dwell time is active) by same or higher authority user.
            /// </summary>
            kCameraInUse,
            /// <summary>Camera is locked by same or higher authority user.</summary>
            kCameraLocked,
            /// <summary>Locked by lower authority user, may override.</summary>
            kNeedOverride,
            /// <summary>
            /// An attempt to set an invalid value on a writable field was made. The value may be invalid due to being
            /// out of range, unavailable, etc.
            /// </summary>
            kInvalidValue,
            /// <summary>
            /// An attempt to set a new port number failed because the port number is already in use.
            /// </summary>
            kPortInUse,
            /// <summary>An attempt to edit a read-only field was made.</summary>
            kReadOnlyField,
            /// <summary>
            /// An attempt to edit a locked resource was made by a user that does not own the IVxResourceLock.
            /// </summary>
            kResourceLocked,
            /// <summary>A request was made using expired authentication credentials.</summary>
            kAuthExpired,
            /// <summary>
            /// A password with an insufficient number of digits was supplied in an attempt to create a new user
            /// password.
            /// </summary>
            kPasswordReqMoreDigits,
            /// <summary>
            /// A password with an insufficient number of lowercase letters was supplied in an attempt to create a new
            /// user password.
            /// </summary>
            kPasswordReqMoreLower,
            /// <summary>
            /// A password with an insufficient number of special characters was supplied in an attempt to create a new
            /// user password.
            /// </summary>
            kPasswordReqMoreSpecial,
            /// <summary>
            /// A password with an insufficient number of uppercase letters was supplied in an attempt to create a new
            /// user password.
            /// </summary>
            kPasswordReqMoreUpper,
            /// <summary>
            /// A password of insufficient length was supplied in an attempt to create a new user password.
            /// </summary>
            kPasswordTooShort,
            /// <summary>
            /// A password too similar to a previous password was supplied in an attempt to create a new user password.
            /// </summary>
            kPasswordTooSimilar,
            /// <summary>
            /// The requested operation is not possible due to a permission conflict with the resource. Typically this
            /// is due to a violation of permission hierarchy (e.g. a nested permission is being assigned without its
            /// parent permission already assigned).
            /// </summary>
            kPermissionConflict,
            /// <summary>An unauthenticated request was made (i.e. invalid username and/or password).</summary>
            kUnauthenticated,
            /// <summary>
            /// An unauthorized request was made (i.e. user does not have permission to access the resource).
            /// </summary>
            kUnauthorized,
            /// <summary>The SDK license key is empty.</summary>
            kSdkLicenseKeyEmpty,
            /// <summary>The SDK license key data is invalid.</summary>
            kSdkLicenseKeyInvalid,
            /// <summary>The license on the server does not support this version of the SDK.</summary>
            kSdkLicenseVersionInvalid,
            /// <summary>The license on the server has expired.</summary>
            kSdkLicenseExpired,
            /// <summary>
            /// The license associated with the license key was not found on the server, but the license grace period
            /// is active.
            /// </summary>
            kSdkLicenseGracePeriodActive,
            /// <summary>
            /// The license associated with the license key was not found on the server and the license grace period
            /// has expired.
            /// </summary>
            kSdkLicenseGracePeriodExpired
        };
    };

    /// <summary>
    /// Values that represent schedule recording actions.
    /// </summary>
    struct VxScheduleAction {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>
            /// Record only the resource (associated with the schedule) that was the source of the event causing the
            /// schedule trigger to activate.
            /// </summary>
            kEventSourceRecord,
            /// <summary>Record all resources associated with the schedule.</summary>
            kRecord
        };
    };

    /// <summary>
    /// Values that represent the status of a search.
    /// </summary>
    struct VxSearchStatus {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The search has completed.</summary>
            kComplete,
            /// <summary>The search is in progress.</summary>
            kInProgress
        };
    };

    /// <summary>
    /// Values that represent snapshot filter types.
    /// </summary>
    struct VxSnapshotFilterItem {
        enum Value {
            /// <summary>No filter.</summary>
            kNone,
            /// <summary>Time (RFC 3339 format) at which the initial image should start .</summary>
            kStartTime,
            /// <summary>Time (RFC 3339 format) at which no further images should be returned.</summary>
            kEndTime,
            /// <summary>Scale to given width in pixels, maintaining ratio.</summary>
            kWidth,
            /// <summary>Return multiple images offset by this amount of time, in seconds, between images.</summary>
            kOffset
        };
    };

    /// <summary>
    /// Values that represent media stream encoding formats.
    /// </summary>
    struct VxStreamFormat {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>H.264 encoding format.</summary>
            kH264,
            /// <summary>H.265 encoding format.</summary>
            kH265,
            /// <summary>MPEG-4 encoding format.</summary>
            kMpeg4,
            /// <summary>JPEG encoding format.</summary>
            kJpeg,
            /// <summary>G.711 encoding format.</summary>
            kG711,
            /// <summary>Metadata stream format.</summary>
            kMetadata
        };
    };

    /// <summary>
    /// Values that represent stream protocols.
    /// </summary>
    struct VxStreamProtocol {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>The Mjpeg (pull) protocol.</summary>
            kMjpegPull,
            /// <summary>The RTSP/RTP protocol.</summary>
            kRtspRtp
        };
    };

    /// <summary>
    /// Values that represent the types of system licenses.
    /// </summary>
    struct VxSystemLicenseType {
        enum Value {
            /// <summary>An error or unknown value was returned.</summary>
            kUnknown,
            /// <summary>Enterprise system license.</summary>
            kEnterprise,
            /// <summary>Professional system license.</summary>
            kProfessional,
            /// <summary>Unlicensed system.</summary>
            kUnlicensed
        };
    };

    /// <summary>
    /// Values that represent zoom directions.
    /// </summary>
    struct VxZoomDirection {
        enum Value {
            /// <summary>Do not perform a zoom action.</summary>
            kNone,
            /// <summary>Stop zoom movement.</summary>
            kStop,
            /// <summary>Zoom in.</summary>
            kIn,
            /// <summary>Zoom out.</summary>
            kOut
        };
    };
}

#endif // VxPrimitives_h__
