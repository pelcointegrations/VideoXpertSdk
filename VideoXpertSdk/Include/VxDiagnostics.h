#ifndef VxDiagnostics_h__
#define VxDiagnostics_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"
#include "VxResourceRef.h"

namespace VxSdk {
    /// <summary>
    /// Represents a collection of device diagnostics. Each diagnostic is represented by a list of that diagnostic’s type. When
    /// multiple diagnostics exist in the list, the diagnostic identifier may be used to distinguish between them.
    /// </summary>
    struct VxDiagnostics {
        /// <summary>
        /// Represents data session information.
        /// </summary>
        struct Assignments {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Assignments"/> struct.
            /// </summary>
            Assignments() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Assignments"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Assignments(const Assignments& ref) {
                this->bitrate = ref.bitrate;
                this->maxBitrate = ref.maxBitrate;
                this->dataSources = ref.dataSources;
                this->maxDataSources = ref.maxDataSources;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Assignments"/> class.
            /// </summary>
            ~Assignments() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->bitrate = 0;
                this->maxBitrate = 0;
                this->dataSources = 0;
                this->maxDataSources = 0;
            }

        public:
            /// <summary>
            /// Total bitrate that is currently assigned.
            /// </summary>
            float bitrate;
            /// <summary>
            /// Maximum bitrate that may be assigned.
            /// </summary>
            float maxBitrate;
            /// <summary>
            /// Number of data sources currently assigned.
            /// </summary>
            int dataSources;
            /// <summary>
            /// Maximum number of data sources that may be assigned.
            /// </summary>
            int maxDataSources;
        };

        /// <summary>
        /// Represents backup power diagnostic information.
        /// </summary>
        struct BackupPower {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="BackupPower"/> struct.
            /// </summary>
            BackupPower() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="BackupPower"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            BackupPower(const BackupPower& ref) {
                this->isEnabled = ref.isEnabled;
                Utilities::StrCopySafe(this->id, ref.id);
                this->remaining = ref.remaining;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="BackupPower"/> class.
            /// </summary>
            ~BackupPower() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isEnabled = false;
                VxZeroArray(this->id);
                this->remaining = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if currently on backup power, <c>false</c> otherwise.
            /// </summary>
            bool isEnabled;
            /// <summary>
            /// Backup power identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Estimated backup time remaining (in minutes). 0 if no backup is available.
            /// </summary>
            int remaining;
        };

        /// <summary>
        /// Represents database health information.
        /// </summary>
        struct Database {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Database"/> struct.
            /// </summary>
            Database() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Database"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Database(const Database& ref) {
                Utilities::StrCopySafe(this->id, ref.id);
                this->statusProgress = ref.statusProgress;
                this->status = ref.status;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Database"/> class.
            /// </summary>
            ~Database() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->id);
                this->statusProgress = 0;
                this->status = VxDatabaseStatus::kUnknown;
            }

        public:

            /// <summary>
            /// Database identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Specifies how close the current status operation is to completion (e.g. rebuilding). Defaults
            /// to 0 if no ongoing status operation is in progress.
            /// </summary>
            int statusProgress;
            /// <summary>
            /// Database health status.
            /// </summary>
            VxDatabaseStatus::Value status;
        };

        /// <summary>
        /// Represents eventing information.
        /// </summary>
        struct Eventing {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Eventing"/> struct.
            /// </summary>
            Eventing() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Eventing"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Eventing(const Eventing& ref) {
                this->eventRate = ref.eventRate;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Eventing"/> class.
            /// </summary>
            ~Eventing() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->eventRate = 0;
            }

        public:

            /// <summary>
            /// The average event rate (events per hour).
            /// </summary>
            int eventRate;
        };

        /// <summary>
        /// Represents fan specific diagnostic information.
        /// </summary>
        struct Fan {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Fan"/> struct.
            /// </summary>
            Fan() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Fan"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Fan(const Fan& ref) {
                this->isOk = ref.isOk;
                Utilities::StrCopySafe(this->id, ref.id);
                this->rpm = ref.rpm;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Fan"/> class.
            /// </summary>
            ~Fan() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isOk = false;
                VxZeroArray(this->id);
                this->rpm = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if the fan status is ok, <c>false</c> if the fan is failed.
            /// </summary>
            bool isOk;
            /// <summary>
            /// Fan identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// RPM of the fan.
            /// </summary>
            int rpm;
        };

        /// <summary>
        /// Represents hard disk drive (HDD) diagnostic information. Contains information on the health of
        /// individual hard disks.
        /// </summary>
        struct Hdd {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Hdd"/> struct.
            /// </summary>
            Hdd() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Hdd"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Hdd(const Hdd& ref) {
                this->isOk = ref.isOk;
                Utilities::StrCopySafe(this->id, ref.id);
                Utilities::StrCopySafe(this->model, ref.model);
                this->statusProgress = ref.statusProgress;
                this->status = ref.status;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Hdd"/> class.
            /// </summary>
            ~Hdd() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isOk = false;
                VxZeroArray(this->id);
                VxZeroArray(this->model);
                this->statusProgress = 0;
                this->status = VxHddStatus::kUnknown;
            }

        public:
            /// <summary>
            /// <c>true</c> if the HDD status is ok, <c>false</c> if the HDD is failed.
            /// </summary>
            bool isOk;
            /// <summary>
            /// Disk identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Drive model identifier.
            /// </summary>
            char model[256];
            /// <summary>
            /// Specifies how close the current status operation is to completion (e.g. rebuilding). Defaults
            /// to 0 if no ongoing status operation is in progress.
            /// </summary>
            int statusProgress;
            /// <summary>
            /// Current drive health status.
            /// </summary>
            VxHddStatus::Value status;
        };

        /// <summary>
        /// Represents load diagnostic information. May be used to indicate load on a CPU, application, etc.
        /// The <see cref="type"/> will distinguish the entity being represented.
        /// </summary>
        struct Load {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Load"/> struct.
            /// </summary>
            Load() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Load"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Load(const Load& ref) {
                this->percent = ref.percent;
                this->type = ref.type;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Load"/> class.
            /// </summary>
            ~Load() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->percent = 0;
                this->type = VxLoadType::kUnknown;
            }

        public:
            /// <summary>
            /// Percentage being used.
            /// </summary>
            int percent;
            /// <summary>
            /// The type of load this resource is referencing.
            /// </summary>
            VxLoadType::Value type;
        };

        /// <summary>
        /// Represents network diagnostic information.
        /// </summary>
        struct Network {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Network"/> struct.
            /// </summary>
            Network() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Network"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Network(const Network& ref) {
                Utilities::StrCopySafe(this->id, ref.id);
                this->bandwidthTotal = ref.bandwidthTotal;
                this->bandwidthUsed = ref.bandwidthUsed;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Network"/> class.
            /// </summary>
            ~Network() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->id);
                this->bandwidthTotal = 0;
                this->bandwidthUsed = 0;
            }

        public:
            /// <summary>
            /// Network identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Total amount of bandwidth available (in kbps).
            /// </summary>
            int bandwidthTotal;
            /// <summary>
            /// Amount of bandwidth in use (in kbps).
            /// </summary>
            int bandwidthUsed;
        };

        /// <summary>
        /// Represents power supply diagnostic information.
        /// </summary>
        struct Power {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Power"/> struct.
            /// </summary>
            Power() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Power"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Power(const Power& ref) {
                this->isOk = ref.isOk;
                Utilities::StrCopySafe(this->id, ref.id);
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Power"/> class.
            /// </summary>
            ~Power() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isOk = false;
                VxZeroArray(this->id);
            }

        public:
            /// <summary>
            /// <c>true</c> if power supply is online. <c>false</c> otherwise.
            /// </summary>
            bool isOk;
            /// <summary>
            /// Power identifier.
            /// </summary>
            char id[256];
        };

        /// <summary>
        /// Represents storage retention information.
        /// </summary>
        struct Retention {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Retention"/> struct.
            /// </summary>
            Retention() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Retention"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Retention(const Retention& ref) {
                this->retentionTime = ref.retentionTime;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Retention"/> class.
            /// </summary>
            ~Retention() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->retentionTime = 0;
            }

        public:
            /// <summary>
            /// Current media storage retention time (in hours).
            /// </summary>
            int retentionTime;
        };

        /// <summary>
        /// Represents storage diagnostic information. Contains information on the capacity and usage of local storage.
        /// </summary>
        struct Storage {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Storage"/> struct.
            /// </summary>
            Storage() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Storage"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Storage(const Storage& ref) {
                this->isOnline = ref.isOnline;
                Utilities::StrCopySafe(this->id, ref.id);
                this->total = ref.total;
                this->used = ref.used;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Storage"/> class.
            /// </summary>
            ~Storage() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                this->isOnline = false;
                VxZeroArray(this->id);
                this->total = 0;
                this->used = 0;
            }

        public:
            /// <summary>
            /// <c>true</c> if storage is online and available. <c>false</c> otherwise.
            /// </summary>
            bool isOnline;
            /// <summary>
            /// Storage identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Total amount of storage present (in MB).
            /// </summary>
            int total;
            /// <summary>
            /// Amount of storage in use (in MB).
            /// </summary>
            int used;
        };

        /// <summary>
        /// Represents temperature sensor diagnostic information.
        /// </summary>
        struct Temperature {
        public:
            /// <summary>
            /// Initializes a new instance of the <see cref="Temperature"/> struct.
            /// </summary>
            Temperature() {
                Clear();
            }

            /// <summary>
            /// Initializes a new instance of the <see cref="Temperature"/> struct.
            /// </summary>
            /// <param name="ref">The reference.</param>
            Temperature(const Temperature& ref) {
                Utilities::StrCopySafe(this->id, ref.id);
                this->degrees = ref.degrees;
                this->thresholdHigh = ref.thresholdHigh;
                this->thresholdLow = ref.thresholdLow;
            }

            /// <summary>
            /// Finalizes an instance of the <see cref="Temperature"/> class.
            /// </summary>
            ~Temperature() {
                Clear();
            }

            /// <summary>
            /// Clears this instance.
            /// </summary>
            void Clear() {
                VxZeroArray(this->id);
                this->degrees = 0;
                this->thresholdHigh = 0;
                this->thresholdLow = 0;
            }

        public:
            /// <summary>
            /// Temperature identifier.
            /// </summary>
            char id[256];
            /// <summary>
            /// Temperature reading (in Celsius).
            /// </summary>
            int degrees;
            /// <summary>
            /// Temperature threshold over which normal operating temperature is exceeded (in Celsius).
            /// </summary>
            int thresholdHigh;
            /// <summary>
            /// Temperature threshold under which normal operating temperature is exceeded (in Celsius).
            /// </summary>
            int thresholdLow;
        };

        /// <summary>
        /// Initializes a new instance of the <see cref="VxDiagnostics"/> struct.
        /// </summary>
        VxDiagnostics() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxDiagnostics"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxDiagnostics(const VxDiagnostics& ref) {
            this->assignments = ref.assignments;
            this->eventing = ref.eventing;
            this->retention = ref.retention;

            this->backupPowerSize = ref.backupPowerSize;
            this->backupPowers = nullptr;
            if (ref.backupPowers != nullptr) {
                this->backupPowers = new BackupPower[ref.backupPowerSize];
                for (int i = 0; i < ref.backupPowerSize; i++)
                    this->backupPowers[i] = BackupPower(ref.backupPowers[i]);
            }

            this->databasesSize = ref.databasesSize;
            this->databases = nullptr;
            if (ref.databases != nullptr) {
                this->databases = new Database[ref.databasesSize];
                for (int i = 0; i < ref.databasesSize; i++)
                    this->databases[i] = Database(ref.databases[i]);
            }


            this->fansSize = ref.fansSize;
            this->fans = nullptr;
            if (ref.fans != nullptr) {
                this->fans = new Fan[ref.fansSize];
                for (int i = 0; i < ref.fansSize; i++)
                    this->fans[i] = Fan(ref.fans[i]);
            }

            this->hddsSize = ref.hddsSize;
            this->hdds = nullptr;
            if (ref.hdds != nullptr) {
                this->hdds = new Hdd[ref.hddsSize];
                for (int i = 0; i < ref.hddsSize; i++)
                    this->hdds[i] = Hdd(ref.hdds[i]);
            }

            this->loadsSize = ref.loadsSize;
            this->loads = nullptr;
            if (ref.loads != nullptr) {
                this->loads = new Load[ref.loadsSize];
                for (int i = 0; i < ref.loadsSize; i++)
                    this->loads[i] = Load(ref.loads[i]);
            }

            this->networksSize = ref.networksSize;
            this->networks = nullptr;
            if (ref.networks != nullptr) {
                this->networks = new Network[ref.networksSize];
                for (int i = 0; i < ref.networksSize; i++)
                    this->networks[i] = Network(ref.networks[i]);
            }

            this->powersSize = ref.powersSize;
            this->powers = nullptr;
            if (ref.powers != nullptr) {
                this->powers = new Power[ref.powersSize];
                for (int i = 0; i < ref.powersSize; i++)
                    this->powers[i] = Power(ref.powers[i]);
            }

            this->storagesSize = ref.storagesSize;
            this->storages = nullptr;
            if (ref.storages != nullptr) {
                this->storages = new Storage[ref.storagesSize];
                for (int i = 0; i < ref.storagesSize; i++)
                    this->storages[i] = Storage(ref.storages[i]);
            }

            this->temperaturesSize = ref.temperaturesSize;
            this->temperatures = nullptr;
            if (ref.temperatures != nullptr) {
                this->temperatures = new Temperature[ref.temperaturesSize];
                for (int i = 0; i < ref.temperaturesSize; i++)
                    this->temperatures[i] = Temperature(ref.temperatures[i]);
            }
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxDiagnostics"/> class.
        /// </summary>
        ~VxDiagnostics() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->assignments.Clear();
            this->eventing.Clear();
            this->retention.Clear();
            this->backupPowerSize = 0;
            this->databasesSize = 0;
            this->fansSize = 0;
            this->hddsSize = 0;
            this->loadsSize = 0;
            this->networksSize = 0;
            this->powersSize = 0;
            this->storagesSize = 0;
            this->temperaturesSize = 0;
            this->backupPowers = nullptr;
            this->databases = nullptr;
            this->fans = nullptr;
            this->hdds = nullptr;
            this->loads = nullptr;
            this->networks = nullptr;
            this->powers = nullptr;
            this->storages = nullptr;
            this->temperatures = nullptr;
        }

    public:
        /// <summary>
        /// The assignment diagnostics.
        /// </summary>
        Assignments assignments;
        /// <summary>
        /// The backup power diagnostics.
        /// </summary>
        BackupPower* backupPowers;
        /// <summary>
        /// The database diagnostics.
        /// </summary>
        Database* databases;
        /// <summary>
        /// The eventing diagnostics.
        /// </summary>
        Eventing eventing;
        /// <summary>
        /// The fan diagnostics.
        /// </summary>
        Fan* fans;
        /// <summary>
        /// The hdd diagnostics.
        /// </summary>
        Hdd* hdds;
        /// <summary>
        /// The load diagnostics.
        /// </summary>
        Load* loads;
        /// <summary>
        /// The network diagnostics.
        /// </summary>
        Network* networks;
        /// <summary>
        /// The power diagnostics.
        /// </summary>
        Power* powers;
        /// <summary>
        /// The retention diagnostics.
        /// </summary>
        Retention retention;
        /// <summary>
        /// The storage diagnostics.
        /// </summary>
        Storage* storages;
        /// <summary>
        /// The temperature diagnostics.
        /// </summary>
        Temperature* temperatures;

        /// <summary>
        /// The size of <see cref="backupPowers"/>.
        /// </summary>
        int backupPowerSize;
        /// <summary>
        /// The size of <see cref="databases"/>.
        /// </summary>
        int databasesSize;
        /// <summary>
        /// The size of <see cref="fans"/>.
        /// </summary>
        int fansSize;
        /// <summary>
        /// The size of <see cref="hdds"/>.
        /// </summary>
        int hddsSize;
        /// <summary>
        /// The size of <see cref="loads"/>.
        /// </summary>
        int loadsSize;
        /// <summary>
        /// The size of <see cref="networks"/>.
        /// </summary>
        int networksSize;
        /// <summary>
        /// The size of <see cref="powers"/>.
        /// </summary>
        int powersSize;
        /// <summary>
        /// The size of <see cref="storages"/>.
        /// </summary>
        int storagesSize;
        /// <summary>
        /// The size of <see cref="temperatures"/>.
        /// </summary>
        int temperaturesSize;
    };
}

#endif // VxDiagnostics_h__