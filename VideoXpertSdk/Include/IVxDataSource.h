#ifndef IVxDataSource_h__
#define IVxDataSource_h__

#include "VxPrimitives.h"
#include "VxMacros.h"
#include "IVxClip.h"
#include "IVxPtzController.h"
#include "IVxDataSession.h"
#include "VxCollection.h"
#include "IVxDataInterface.h"
#include "IVxDataStorage.h"
#include "IVxResourceRel.h"
#include "IVxUserInfo.h"
#include "IVxTag.h"
#include "IVxGap.h"
#include "IVxBookmark.h"
#include "IVxAnalyticSession.h"
#include "IVxDataSourceConfig.h"

namespace VxSdk {
    struct IVxMember;
    struct IVxPixelSearch;
    struct VxNewPixelSearch;
    struct IVxDevice;

    /// <summary>
    /// Represents a data producer in the system hosted by a device. Each data source provides a list of data
    /// interfaces, which provide a particular protocol used to transmit and control the data produced by this data
    /// source.
    /// </summary>
    struct IVxDataSource {
    public:
        /// <summary>
        /// Adds a new analytic config.
        /// </summary>
        /// <param name="newAnalyticConfig">The new analytic config to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddAnalyticConfig(VxNewAnalyticConfig& newAnalyticConfig) const = 0;
        /// <summary>
        /// Adds a new analytic session.
        /// </summary>
        /// <param name="newAnalyticSession">The new analytic session to be added.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value AddAnalyticSession(VxNewAnalyticSession& newAnalyticSession) const = 0;
        /// <summary>
        /// Gets a value indicating whether pixel search is available for this data source.
        /// </summary>
        /// <param name="canPixelSearch"><c>true</c> if pixel search is available, otherwise <c>false</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CanPixelSearch(bool& canPixelSearch) const = 0;
        /// <summary>
        /// Gets a value indicating whether PTZ is enabled.
        /// </summary>
        /// <param name="canPtz"><c>true</c> if PTZ is enabled, <c>false</c> if not.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CanPtz(bool& canPtz) const = 0;
        /// <summary>
        /// Create a new MJPEG <see cref="IVxDataSession"/>.
        /// </summary>
        /// <param name="dataSession">
        /// <c>nullptr</c> if it fails, else the new MJPEG streams <see cref="IVxDataSession"/>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreateMjpegDataSession(IVxDataSession*& dataSession) const = 0;
        /// <summary>
        /// Creates a new pixel search for this data source.
        /// </summary>
        /// <param name="newPixelSearch">The new pixel search to create.</param>
        /// <param name="pixelSearch">
        /// <c>nullptr</c> if pixel search creation fails, else the new <see cref="IVxPixelSearch"/>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value CreatePixelSearch(VxNewPixelSearch& newPixelSearch, IVxPixelSearch*& pixelSearch) const = 0;
        /// <summary>
        /// Deletes this instance.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of deleting this instance.</returns>
        virtual VxResult::Value Delete() const = 0;
        /// <summary>
        /// Disable this data source. A disabled data source shall not expose any data interface, will not be recorded,
        /// and will not consume any system license feature counts.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of disabling this data source.</returns>
        virtual VxResult::Value Disable() = 0;
        /// <summary>
        /// Enable this data source.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of enabling thisdata source.</returns>
        virtual VxResult::Value Enable() = 0;
        /// <summary>
        /// Gets all data storages associated with this data source; includes edge and failover data storages.
        /// <para>Available filters: kAdvancedQuery, kCommissioned, kId, kModifiedSince, kName, kType.</para>
        /// </summary>
        /// <param name="dataStorageCollection">A <see cref="VxCollection"/> of data storages.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAllDataStorages(VxCollection<IVxDataStorage**>& dataStorageCollection) const = 0;
        /// <summary>
        /// Gets the list of analytic capabilities that are supported.
        /// </summary>
        /// <param name="analyticCapabilities">The analytic capabilities that are supported.</param>
        /// <param name="size">The size of <paramref name="analyticCapabilities"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticCapabilities(VxAnalyticCapability::Value* analyticCapabilities, int& size) const = 0;
        /// <summary>
        /// Get the analytic configurations for this data source.
        /// </summary>
        /// <param name="analyticConfigCollection">A <see cref="VxCollection"/> of the analytic configs for this data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticConfigs(VxCollection<IVxAnalyticConfig**>& analyticConfigCollection) const = 0;
        /// <summary>
        /// Gets the analytic sessions for this data source.
        /// <para>Available filters: kAdvancedQuery, kDataSourceId, kDeviceId, kId, kModifiedSince.</para>
        /// </summary>
        /// <param name="analyticSessionCollection">
        /// A <see cref="VxCollection"/> of the analytic sessions for this data source.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAnalyticSessions(VxCollection<IVxAnalyticSession**>& analyticSessionCollection) const = 0;
        /// <summary>
        /// Gets all possible audio resource relations for this data source (both linked and non-linked). Each linked
        /// resource shall be considered to be associated to this data source while non-linked resources shall not be
        /// (they are available to be associated).
        /// <para>Available filters: kAdvancedQuery, kAllTags, kAllPrivateTags, kLinked.</para>
        /// </summary>
        /// <param name="resourceRelCollection">A <see cref="VxCollection"/> of related resources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAudioRelations(VxCollection<IVxResourceRel**>& resourceRelCollection) const = 0;
        /// <summary>
        /// Gets the list of analytic behavior types that are supported.
        /// </summary>
        /// <param name="analyticBehaviorTypes">The analytic behavior types that are supported..</param>
        /// <param name="size">The size of <paramref name="analyticBehaviorTypes"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetAvailableAnalyticBehaviorTypes(VxAnalyticBehaviorType::Value* analyticBehaviorTypes, int& size) const = 0;
        /// <summary>
        /// Gets the bookmarks associated with this data source.
        /// <para>
        /// Available filters: kAdvancedQuery, kDataSourceId, kDataSourceType, kDescription, kGroupId, kId, kLocked,
        /// kModifiedSince, kName, kSearchEndTime, kSearchStartTime, kTime.
        /// </para>
        /// </summary>
        /// <param name="bookmarkCollection">A <see cref="VxCollection"/> of the associated bookmarks.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetBookmarks(VxCollection<IVxBookmark**>& bookmarkCollection) const = 0;
        /// <summary>
        /// Gets the clips associated with this data source.
        /// <para>
        /// Available filters: kDataSourceId, kEndTime, kEvent, kFramerate, kSearchEndTime, kSearchStartTime,
        /// kStartTime.
        /// </para>
        /// </summary>
        /// <param name="clipCollection">A <see cref="VxCollection"/> of the associated clips.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetClips(VxCollection<IVxClip**>& clipCollection) const = 0;
        /// <summary>
        /// Gets the data storages associated with this data source.
        /// <para>Available filters: kAdvancedQuery, kCommissioned, kId, kModifiedSince, kName, kType.</para>
        /// </summary>
        /// <param name="dataStorageCollection">A <see cref="VxCollection"/> of data storages.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetDataStorages(VxCollection<IVxDataStorage**>& dataStorageCollection) const = 0;
        /// <summary>
        /// Gets the edge clips associated with this data source; may take a long time (minutes).
        /// <para>
        /// Available filters: kDataSourceId, kEndTime, kEvent, kFramerate, kSearchEndTime, kSearchStartTime,
        /// kStartTime.
        /// </para>
        /// </summary>
        /// <param name="clipCollection">A <see cref="VxCollection"/> of the associated edge clips.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetEdgeClips(VxCollection<IVxClip**>& clipCollection) const = 0;
        /// <summary>
        /// Gets the gaps for this data source.
        /// <para>Available filters: kDataStorageId, kSearchEndTime, kSearchStartTime, kStartTime.</para>
        /// </summary>
        /// <param name="gapCollection">A <see cref="VxCollection"/> of the gaps for this data source.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetGaps(VxCollection<IVxGap**>& gapCollection) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxDevice"/> that hosts this data source.
        /// </summary>
        /// <param name="hostDevice">The host <see cref="IVxDevice"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetHostDevice(IVxDevice*& hostDevice) const = 0;
        /// <summary>
        /// Gets the limits related to this resource.
        /// </summary>
        /// <param name="limits">The limits related to this resource.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLimits(VxLimits*& limits) const = 0;
        /// <summary>
        /// Gets the requested line counts for this data source.
        /// </summary>
        /// <param name="lineCountingRequest">The requested line counts.</param>
        /// <param name="lineCounts"><c>nullptr</c> if the request fails, else the <see cref="VxLineCounts"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetLineCounts(VxLineCountingRequest& lineCountingRequest, VxLineCounts*& lineCounts) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxMember"/> that this data source resides in.
        /// </summary>
        /// <param name="member">The <see cref="IVxMember"/> this data source resides in..</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMember(IVxMember*& member) const = 0;
        /// <summary>
        /// Gets all possible metadata resource relations for this data source (both linked and non-linked). Each
        /// linked resource shall be considered to be associated to this data source while non-linked resources shall
        /// not be (they are available to be associated).
        /// <para>Available filters: kAdvancedQuery, kAllTags, kAllPrivateTags, kLinked.</para>
        /// </summary>
        /// <param name="resourceRelCollection">A <see cref="VxCollection"/> of related resources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMetadataRelations(VxCollection<IVxResourceRel**>& resourceRelCollection) const = 0;
        /// <summary>
        /// Gets the URI to the download location of a metadata "snapshot" from this data source. 
        /// </summary>
        /// <param name="endpoint">The metadata snapshot endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <param name="time">The point in time of the metadata to return (defaults to the current time if not supplied).</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMetadataSnapshotEndpoint(char* endpoint, int& size, char time[64]) const = 0;
        /// <summary>
        /// Gets the motion detection configuration for this data source, if supported.
        /// </summary>
        /// <param name="motionConfig">The motion configuration if supported, otherwise <c>nullptr</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMotionConfiguration(IVxDataSourceConfig::Motion*& motionConfig) const = 0;
        /// <summary>
        /// DEPRECATED
        /// <para>Gets the motion detection configuration for this data source, if supported.</para>
        /// </summary>
        /// <param name="motionConfig">The motion configuration if supported, otherwise <c>nullptr</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMotionConfiguration(IVxConfiguration::Motion*& motionConfig) const = 0;
        /// <summary>
        /// Gets the multiple viewer information for this data source. This information contains details on the
        /// current viewers of this data source.
        /// </summary>
        /// <param name="userInfoCollection">
        /// A <see cref="VxCollection"/> of user information for all viewers of this data source.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetMultiviewInfo(VxCollection<IVxUserInfo**>& userInfoCollection) const = 0;
        /// <summary>
        /// Gets the PTZ configuration for this data source, if supported.
        /// </summary>
        /// <param name="ptzConfig">The PTZ configuration if supported, otherwise <c>nullptr</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPtzConfiguration(IVxDataSourceConfig::Ptz*& ptzConfig) const = 0;
        /// <summary>
        /// Gets the <see cref="IVxPtzController"/> associated with this data source.
        /// </summary>
        /// <param name="ptzController">
        /// <c>nullptr</c> if PTZ is not supported, else the <see cref="IVxPtzController"/>.
        /// </param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetPtzController(IVxPtzController*& ptzController) const = 0;
        /// <summary>
        /// Gets the RTSP stream endpoint URI.
        /// </summary>
        /// <param name="endpoint">The RTSP endpoint.</param>
        /// <param name="size">The size of <paramref name="endpoint"/>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetRtspEndpoint(char* endpoint, int& size) const = 0;
        /// <summary>
        /// Gets the smart compression configuration for this data source, if supported.
        /// </summary>
        /// <param name="smartCompressionConfig">The smart compression configuration if supported, otherwise <c>nullptr</c>.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetSmartCompressionConfiguration(IVxDataSourceConfig::SmartCompression*& smartCompressionConfig) const = 0;
        /// <summary>
        /// Gets the tags associated with this data source.
        /// <para>
        /// Available filters: kAdvancedQuery, kFolder, kId, kModifiedSince, kName, kOwned, kOwner, kParentId,
        /// kResourceId, kResourceType.
        /// </para>
        /// </summary>
        /// <param name="tagCollection">A <see cref="VxCollection"/> of the associated tags.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetTags(VxCollection<IVxTag**>& tagCollection) const = 0;
        /// <summary>
        /// Gets the video encoding configurations for this data source, if supported.
        /// </summary>
        /// <param name="videoEncodingCollection">A <see cref="VxCollection"/> of the video encoding configurations.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetVideoEncodingsConfiguration(VxCollection<IVxDataSourceConfig::VideoEncoding**>& videoEncodingCollection) const = 0;
        /// <summary>
        /// Gets all possible video resource relations for this data source (both linked and non-linked). Each linked
        /// resource shall be considered to be associated to this data source while non-linked resources shall not be
        /// (they are available to be associated).
        /// <para>Available filters: kAdvancedQuery, kAllTags, kAllPrivateTags, kLinked.</para>
        /// </summary>
        /// <param name="resourceRelCollection">A <see cref="VxCollection"/> of related resources.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of the request.</returns>
        virtual VxResult::Value GetVideoRelations(VxCollection<IVxResourceRel**>& resourceRelCollection) const = 0;
        /// <summary>
        /// Refreshes this objects member values by retrieving its current information from the VideoXpert system.
        /// </summary>
        /// <returns>The <see cref="VxResult::Value">Result</see> of refreshing this objects member values.</returns>
        virtual VxResult::Value Refresh() = 0;
        /// <summary>
        /// Sets the name property.
        /// </summary>
        /// <param name="name">The new name value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetName(char name[64]) = 0;
        /// <summary>
        /// Sets the number property.
        /// </summary>
        /// <param name="number">The new number value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetNumber(int number) = 0;
        /// <summary>
        /// Sets the pruningThreshold property.
        /// </summary>
        /// <param name="pruningThreshold">The new threshold, in hours.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetPruningThreshold(int pruningThreshold) = 0;
        /// <summary>
        /// Sets the retentionLimit property.
        /// </summary>
        /// <param name="retentionLimit">The new retention limit value.</param>
        /// <returns>The <see cref="VxResult::Value">Result</see> of setting the property.</returns>
        virtual VxResult::Value SetRetentionLimit(int retentionLimit) = 0;

    public:
        /// <summary>
        /// Indicates whether this data source is currently being captured by a recorder.
        /// </summary>
        bool isCapturing;
        /// <summary>
        /// Indicates whether this data source is currently enabled.
        /// </summary>
        bool isEnabled;
        /// <summary>
        /// Indicates whether the data source is currently being manually recorded (by one or more data storage).
        /// </summary>
        bool isManuallyRecording;
        /// <summary>
        /// Indicates whether the data source is currently recording.
        /// </summary>
        bool isRecording;
        /// <summary>
        /// Indicates whether the live stream is available.
        /// </summary>
        bool hasLive;
        /// <summary>
        /// Indicates whether the recorded video is available.
        /// </summary>
        bool hasRecorded;
        /// <summary>
        /// The encoding of the data source. Usually only provided by metadata sources.
        /// </summary>
        char encoding[64];
        /// <summary>
        /// The unique identifier of the data source.
        /// </summary>
        char id[64];
        /// <summary>
        /// The IP of this data source.
        /// </summary>
        char ip[64];
        /// <summary>
        /// The friendly name of this data source.
        /// </summary>
        char name[64];
        /// <summary>
        /// The URI to retrieve the current live frame.
        /// </summary>
        char snapshotUri[512];
        /// <summary>
        /// The source URI of the data source.
        /// </summary>
        char sourceEndpoint[512];
        /// <summary>
        /// The size of <see cref="capabilities"/>.
        /// </summary>
        int capabilitiesSize;
        /// <summary>
        /// The size of <see cref="dataInterfaces"/>.
        /// </summary>
        int dataInterfaceSize;
        /// <summary>
        /// The zero-based index (per host device) indicating the "position" of the data source (per data source type)
        /// within the host device.
        /// </summary>
        int index;
        /// <summary>
        /// The size of <see cref="linkedPtzInfo"/>.
        /// </summary>
        int linkedPtzInfoSize;
        /// <summary>
        /// The number used to designate the data source.
        /// </summary>
        int number;
        /// <summary>
        /// The threshold, in hours, after which recordings older than this are eligible for pruning. Any recorded media
        /// retained longer than the threshold will be pruned as needed to free space on disk for recording. If set,
        /// this value overrides the threshold in IVxConfiguration::Storage. This is only applicable when the data
        /// source type is video. A value of 0 will disable pruning.
        /// </summary>
        int pruningThreshold;
        /// <summary>
        /// The maximum retention (in hours) that the system will keep recorded data for this data source. Any recorded
        /// data that exceeds this limit will be deleted. If <see cref="IVxConfiguration::Storage::retentionLimit"/> is
        /// also set, the lowest non-zero value will be used. A value of 0 means no retention limit will be used.
        /// </summary>
        int retentionLimit;
        /// <summary>
        /// The data interfaces available for retrieval of data from this data source.
        /// </summary>
        IVxDataInterface** dataInterfaces;
        /// <summary>
        /// List of capabilities supported by this data source, if any.
        /// </summary>
        VxDataSourceCapability::Value* capabilities;
        /// <summary>
        /// The type of media this data source contains.
        /// </summary>
        VxDataSourceType::Value type;
        /// <summary>
        /// The current operational state of the associated device.
        /// </summary>
        VxDeviceState::Value state;
        /// <summary>
        /// Provides information on any data sources that are tracking this data source. Only available if this data
        /// source supports linked PTZ. 
        /// </summary>
        VxLinkedPtzInfo* linkedPtzInfo;

    protected:
        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->capabilities = nullptr;
            this->dataInterfaces = nullptr;
            this->linkedPtzInfo = nullptr;
            VxZeroArray(this->encoding);
            VxZeroArray(this->id);
            VxZeroArray(this->ip);
            VxZeroArray(this->name);
            VxZeroArray(this->snapshotUri);
            VxZeroArray(this->sourceEndpoint);
            this->capabilitiesSize = 0;
            this->dataInterfaceSize = 0;
            this->index = 0;
            this->linkedPtzInfoSize = 0;
            this->number = 0;
            this->pruningThreshold = 0;
            this->retentionLimit = 0;
            this->isCapturing = false;
            this->isEnabled = false;
            this->isManuallyRecording = false;
            this->isRecording = false;
            this->hasLive = false;
            this->hasRecorded = false;
            this->type = VxDataSourceType::kUnknown;
            this->state = VxDeviceState::kUnknown;
        }
    };
}

#endif // IVxDataSource_h__
