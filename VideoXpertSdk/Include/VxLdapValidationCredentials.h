#ifndef VxLdapValidationCredentials_h__
#define VxLdapValidationCredentials_h__

#include "VxPrimitives.h"
#include "VxUtilities.h"
#include "VxMacros.h"

namespace VxSdk {
    /// <summary>
    /// Represents credentials that are used to verify the connection to the LDAP server. The information
    /// will not be stored.
    /// </summary>
    struct VxLdapValidationCredentials {
    public:
        /// <summary>
        /// Initializes a new instance of the <see cref="VxLdapValidationCredentials"/> struct.
        /// </summary>
        VxLdapValidationCredentials() {
            Clear();
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="VxLdapValidationCredentials"/> struct.
        /// </summary>
        /// <param name="ref">The reference.</param>
        VxLdapValidationCredentials(const VxLdapValidationCredentials& ref) {
            this->isServerTlsEnabled = ref.isServerTlsEnabled;
            this->isSsoEnabled = ref.isSsoEnabled;
            this->isTwoStageBindingEnabled = ref.isTwoStageBindingEnabled;
            this->useLdapUsersAndRoles = ref.useLdapUsersAndRoles;
            Utilities::StrCopySafe(this->baseDn, ref.baseDn);
            Utilities::StrCopySafe(this->objectClasses, ref.objectClasses);
            Utilities::StrCopySafe(this->password, ref.password);
            Utilities::StrCopySafe(this->searchAttributes, ref.searchAttributes);
            Utilities::StrCopySafe(this->searchDnAccount, ref.searchDnAccount);
            Utilities::StrCopySafe(this->searchDnPassword, ref.searchDnPassword);
            Utilities::StrCopySafe(this->serverName, ref.serverName);
            Utilities::StrCopySafe(this->ssoDomain, ref.ssoDomain);
            Utilities::StrCopySafe(this->username, ref.username);
            Utilities::StrCopySafe(this->vxRootDn, ref.vxRootDn);
            Utilities::StrCopySafe(this->vxSystemDn, ref.vxSystemDn);
            this->serverPort = ref.serverPort;
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="VxLdapValidationCredentials"/> class.
        /// </summary>
        ~VxLdapValidationCredentials() {
            Clear();
        }

        /// <summary>
        /// Clears this instance.
        /// </summary>
        void Clear() {
            this->isServerTlsEnabled = false;
            this->isSsoEnabled = false;
            this->isTwoStageBindingEnabled = false;
            this->useLdapUsersAndRoles = false;
            VxZeroArray(this->baseDn);
            VxZeroArray(this->objectClasses);
            VxZeroArray(this->password);
            VxZeroArray(this->searchAttributes);
            VxZeroArray(this->searchDnAccount);
            VxZeroArray(this->searchDnPassword);
            VxZeroArray(this->serverName);
            VxZeroArray(this->ssoDomain);
            VxZeroArray(this->username);
            VxZeroArray(this->vxRootDn);
            VxZeroArray(this->vxSystemDn);
            this->serverPort = 0;
        }

    public:
        /// <summary>
        /// Indicates whether or not SSL/TLS security is enabled for the LDAP server.
        /// </summary>
        bool isServerTlsEnabled;
        /// <summary>
        /// Indicates whether or not single sign-on is enabled.
        /// </summary>
        bool isSsoEnabled;
        /// <summary>
        /// Indicates whether or not two stage binding authentication is enabled.
        /// </summary>
        bool isTwoStageBindingEnabled;
        /// <summary>
        /// Indicates whether or not LDAP will be used to manage users and roles.
        /// <remarks>
        /// <c>false</c> to only use the LDAP server for authentication; the VideoXpert system will manage users and
        /// roles itself. <c>true</c> to manage user accounts and role assignments in the LDAP system. Note that
        /// permissions on roles will still be managed by the VideoXpert system.
        /// </remarks>
        /// </summary>
        bool useLdapUsersAndRoles;
        /// <summary>
        /// The location in the LDAP database that will be used to search for and authenticate user entries.
        /// </summary>
        /// <example>ou=Service Accounts, dc=Pelco, dc=org</example>
        char baseDn[1024];
        /// <summary>
        /// The LDAP object classes to search for users.
        /// </summary>
        /// <example>user, inetOrgPerson</example>
        char objectClasses[1024];
        /// <summary>
        /// The user password.
        /// <remarks>Ignored if <see cref="isSsoEnabled"/> is <c>true</c>.</remarks>
        /// </summary>
        char password[64];
        /// <summary>
        /// Attributes against which to match the user’s identity/name.
        /// </summary>
        /// <example>cn, mail</example>
        char searchAttributes[1024];
        /// <summary>
        /// The superuser DN account in the LDAP directory to use for performing searches there.
        /// <remarks>
        /// If <see cref="isSsoEnabled"/> SSO is <c>true</c>, this account should have write permissions on
        /// the <see cref="vxRootDn"/>. Should be supplied if <see cref="isTwoStageBindingEnabled"/> or
        /// <see cref="useLdapUsersAndRoles"/> are <c>true</c>; ignored otherwise.
        /// </remarks>
        /// </summary>
        /// <example>CN=users, DC=mycorp</example>
        char searchDnAccount[1024];
        /// <summary>
        /// The password for the superuser DN account in the LDAP directory that performs searches.
        /// <remarks>
        /// Should be supplied if <see cref="isTwoStageBindingEnabled"/> or <see cref="useLdapUsersAndRoles"/> are
        /// <c>true</c>; ignored otherwise.
        /// </remarks>
        /// </summary>
        char searchDnPassword[64];
        /// <summary>
        /// The hostname or IP address of the LDAP server.
        /// </summary>
        char serverName[256];
        /// <summary>
        /// The Active Directory/Kerberos domain used for single sign-on.
        /// <remarks>Ignored if <see cref="isSsoEnabled"/> is <c>false</c>.</remarks>
        /// </summary>
        char ssoDomain[1024];
        /// <summary>
        /// The user login name.
        /// </summary>
        char username[64];
        /// <summary>
        /// The LDAP container under which VideoXpert system information for all sites is stored; this should be the
        /// same for all sites.
        /// <remarks>
        /// Should be supplied if <see cref="useLdapUsersAndRoles"/> is <c>true</c>; ignored otherwise.
        /// </remarks>
        /// </summary>
        char vxRootDn[1024];
        /// <summary>
        /// The site specific LDAP container; unique per VideoXpert site. This DN should contain the
        /// <see cref="vxRootDn"/> (which is a suffix of this full DN).
        /// <remarks>
        /// Should be supplied if <see cref="useLdapUsersAndRoles"/> is <c>true</c>; ignored otherwise.
        /// </remarks>
        /// </summary>
        char vxSystemDn[1024];
        /// <summary>
        /// Port number of the LDAP server.
        /// </summary>
        int serverPort;
    };
}

#endif // VxLdapValidationCredentials_h__
