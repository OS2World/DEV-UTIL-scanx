
#ifndef _NTNDIS_
#define _NTNDIS_

#ifdef __cplusplus
extern "C" {
#endif

//
//  Required OIDs
//
#define OID_GEN_SUPPORTED_LIST                  0x00010101
#define OID_GEN_HARDWARE_STATUS                 0x00010102
#define OID_GEN_MEDIA_SUPPORTED                 0x00010103
#define OID_GEN_MEDIA_IN_USE                    0x00010104
#define OID_GEN_MAXIMUM_LOOKAHEAD               0x00010105
#define OID_GEN_MAXIMUM_FRAME_SIZE              0x00010106
#define OID_GEN_LINK_SPEED                      0x00010107
#define OID_GEN_TRANSMIT_BUFFER_SPACE           0x00010108
#define OID_GEN_RECEIVE_BUFFER_SPACE            0x00010109
#define OID_GEN_TRANSMIT_BLOCK_SIZE             0x0001010A
#define OID_GEN_RECEIVE_BLOCK_SIZE              0x0001010B
#define OID_GEN_VENDOR_ID                       0x0001010C
#define OID_GEN_VENDOR_DESCRIPTION              0x0001010D
#define OID_GEN_CURRENT_PACKET_FILTER           0x0001010E
#define OID_GEN_CURRENT_LOOKAHEAD               0x0001010F
#define OID_GEN_DRIVER_VERSION                  0x00010110
#define OID_GEN_MAXIMUM_TOTAL_SIZE              0x00010111
#define OID_GEN_PROTOCOL_OPTIONS                0x00010112
#define OID_GEN_MAC_OPTIONS                     0x00010113
#define OID_GEN_MEDIA_CONNECT_STATUS            0x00010114
#define OID_GEN_MAXIMUM_SEND_PACKETS            0x00010115
#define OID_GEN_VENDOR_DRIVER_VERSION           0x00010116
#define OID_GEN_SUPPORTED_GUIDS                 0x00010117
#define OID_GEN_NETWORK_LAYER_ADDRESSES         0x00010118  // Set only
#define OID_GEN_TRANSPORT_HEADER_OFFSET         0x00010119  // Set only
#define OID_GEN_MACHINE_NAME                    0x0001021A
#define OID_GEN_RNDIS_CONFIG_PARAMETER          0x0001021B  // Set only
#define OID_GEN_VLAN_ID                         0x0001021C

//
//  Optional OIDs
//
#define OID_GEN_MEDIA_CAPABILITIES              0x00010201
#define OID_GEN_PHYSICAL_MEDIUM                 0x00010202

//
//  Required statistics
//
#define OID_GEN_XMIT_OK                         0x00020101
#define OID_GEN_RCV_OK                          0x00020102
#define OID_GEN_XMIT_ERROR                      0x00020103
#define OID_GEN_RCV_ERROR                       0x00020104
#define OID_GEN_RCV_NO_BUFFER                   0x00020105

//
//  Optional statistics
//
#define OID_GEN_DIRECTED_BYTES_XMIT             0x00020201
#define OID_GEN_DIRECTED_FRAMES_XMIT            0x00020202
#define OID_GEN_MULTICAST_BYTES_XMIT            0x00020203
#define OID_GEN_MULTICAST_FRAMES_XMIT           0x00020204
#define OID_GEN_BROADCAST_BYTES_XMIT            0x00020205
#define OID_GEN_BROADCAST_FRAMES_XMIT           0x00020206
#define OID_GEN_DIRECTED_BYTES_RCV              0x00020207
#define OID_GEN_DIRECTED_FRAMES_RCV             0x00020208
#define OID_GEN_MULTICAST_BYTES_RCV             0x00020209
#define OID_GEN_MULTICAST_FRAMES_RCV            0x0002020A
#define OID_GEN_BROADCAST_BYTES_RCV             0x0002020B
#define OID_GEN_BROADCAST_FRAMES_RCV            0x0002020C

#define OID_GEN_RCV_CRC_ERROR                   0x0002020D
#define OID_GEN_TRANSMIT_QUEUE_LENGTH           0x0002020E

#define OID_GEN_GET_TIME_CAPS                   0x0002020F
#define OID_GEN_GET_NETCARD_TIME                0x00020210
#define OID_GEN_NETCARD_LOAD                    0x00020211
#define OID_GEN_DEVICE_PROFILE                  0x00020212

//
// The following is exported by NDIS itself and is only queryable. It returns
// the time in milliseconds a driver took to initialize.
//
#define OID_GEN_INIT_TIME_MS                    0x00020213
#define OID_GEN_RESET_COUNTS                    0x00020214
#define OID_GEN_MEDIA_SENSE_COUNTS              0x00020215
#define OID_GEN_FRIENDLY_NAME                   0x00020216
#define OID_GEN_MINIPORT_INFO                   0x00020217
#define OID_GEN_RESET_VERIFY_PARAMETERS         0x00020218


//
//  These are connection-oriented general OIDs.
//  These replace the above OIDs for connection-oriented media.
//
#define OID_GEN_CO_SUPPORTED_LIST               OID_GEN_SUPPORTED_LIST
#define OID_GEN_CO_HARDWARE_STATUS              OID_GEN_HARDWARE_STATUS
#define OID_GEN_CO_MEDIA_SUPPORTED              OID_GEN_MEDIA_SUPPORTED
#define OID_GEN_CO_MEDIA_IN_USE                 OID_GEN_MEDIA_IN_USE
#define OID_GEN_CO_LINK_SPEED                   OID_GEN_LINK_SPEED
#define OID_GEN_CO_VENDOR_ID                    OID_GEN_VENDOR_ID
#define OID_GEN_CO_VENDOR_DESCRIPTION           OID_GEN_VENDOR_DESCRIPTION
#define OID_GEN_CO_DRIVER_VERSION               OID_GEN_DRIVER_VERSION
#define OID_GEN_CO_PROTOCOL_OPTIONS             OID_GEN_PROTOCOL_OPTIONS
#define OID_GEN_CO_MAC_OPTIONS                  OID_GEN_MAC_OPTIONS
#define OID_GEN_CO_MEDIA_CONNECT_STATUS         OID_GEN_MEDIA_CONNECT_STATUS
#define OID_GEN_CO_VENDOR_DRIVER_VERSION        OID_GEN_VENDOR_DRIVER_VERSION
#define OID_GEN_CO_SUPPORTED_GUIDS              OID_GEN_SUPPORTED_GUIDS
#define OID_GEN_CO_GET_TIME_CAPS                OID_GEN_GET_TIME_CAPS
#define OID_GEN_CO_GET_NETCARD_TIME             OID_GEN_GET_NETCARD_TIME
#define OID_GEN_CO_MINIMUM_LINK_SPEED           0x00020120

//
//  These are connection-oriented statistics OIDs.
//
#define OID_GEN_CO_XMIT_PDUS_OK                 OID_GEN_XMIT_OK
#define OID_GEN_CO_RCV_PDUS_OK                  OID_GEN_RCV_OK
#define OID_GEN_CO_XMIT_PDUS_ERROR              OID_GEN_XMIT_ERROR
#define OID_GEN_CO_RCV_PDUS_ERROR               OID_GEN_RCV_ERROR
#define OID_GEN_CO_RCV_PDUS_NO_BUFFER           OID_GEN_RCV_NO_BUFFER


#define OID_GEN_CO_RCV_CRC_ERROR                OID_GEN_RCV_CRC_ERROR
#define OID_GEN_CO_TRANSMIT_QUEUE_LENGTH        OID_GEN_TRANSMIT_QUEUE_LENGTH
#define OID_GEN_CO_BYTES_XMIT                   OID_GEN_DIRECTED_BYTES_XMIT
#define OID_GEN_CO_BYTES_RCV                    OID_GEN_DIRECTED_BYTES_RCV
#define OID_GEN_CO_NETCARD_LOAD                 OID_GEN_NETCARD_LOAD
#define OID_GEN_CO_DEVICE_PROFILE               OID_GEN_DEVICE_PROFILE
#define OID_GEN_CO_BYTES_XMIT_OUTSTANDING       0x00020221

//
// IEEE 802.11 OIDs
//
#define OID_802_11_BSSID                        0x0D010101
#define OID_802_11_SSID                         0x0D010102
#define OID_802_11_NETWORK_TYPES_SUPPORTED      0x0D010203
#define OID_802_11_NETWORK_TYPE_IN_USE          0x0D010204
#define OID_802_11_TX_POWER_LEVEL               0x0D010205
#define OID_802_11_RSSI                         0x0D010206
#define OID_802_11_RSSI_TRIGGER                 0x0D010207
#define OID_802_11_INFRASTRUCTURE_MODE          0x0D010108
#define OID_802_11_FRAGMENTATION_THRESHOLD      0x0D010209
#define OID_802_11_RTS_THRESHOLD                0x0D01020A
#define OID_802_11_NUMBER_OF_ANTENNAS           0x0D01020B
#define OID_802_11_RX_ANTENNA_SELECTED          0x0D01020C
#define OID_802_11_TX_ANTENNA_SELECTED          0x0D01020D
#define OID_802_11_SUPPORTED_RATES              0x0D01020E
#define OID_802_11_DESIRED_RATES                0x0D010210
#define OID_802_11_CONFIGURATION                0x0D010211
#define OID_802_11_STATISTICS                   0x0D020212
#define OID_802_11_ADD_WEP                      0x0D010113
#define OID_802_11_REMOVE_WEP                   0x0D010114
#define OID_802_11_DISASSOCIATE                 0x0D010115
#define OID_802_11_POWER_MODE                   0x0D010216
#define OID_802_11_BSSID_LIST                   0x0D010217
#define OID_802_11_AUTHENTICATION_MODE          0x0D010118
#define OID_802_11_PRIVACY_FILTER               0x0D010119
#define OID_802_11_BSSID_LIST_SCAN              0x0D01011A
#define OID_802_11_WEP_STATUS                   0x0D01011B
// Renamed to reflect better the extended set of encryption status
#define OID_802_11_ENCRYPTION_STATUS            OID_802_11_WEP_STATUS
#define OID_802_11_RELOAD_DEFAULTS              0x0D01011C
// Added to allow key mapping and default keys
#define OID_802_11_ADD_KEY                      0x0D01011D
#define OID_802_11_REMOVE_KEY                   0x0D01011E
#define OID_802_11_ASSOCIATION_INFORMATION      0x0D01011F
#define OID_802_11_TEST                         0x0D010120

//
// IEEE 802.11 Structures and definitions
//
// new types for Media Specific Indications

#define NDIS_802_11_LENGTH_SSID         32
#define NDIS_802_11_LENGTH_RATES        8
#define NDIS_802_11_LENGTH_RATES_EX     16

typedef enum _NDIS_802_11_STATUS_TYPE
{
    Ndis802_11StatusType_Authentication,
    Ndis802_11StatusTypeMax    // not a real type, defined as an upper bound
} NDIS_802_11_STATUS_TYPE, *PNDIS_802_11_STATUS_TYPE;

typedef UCHAR   NDIS_802_11_MAC_ADDRESS[6];

typedef struct _NDIS_802_11_STATUS_INDICATION
{
    NDIS_802_11_STATUS_TYPE StatusType;
} NDIS_802_11_STATUS_INDICATION, *PNDIS_802_11_STATUS_INDICATION;

// mask for authentication/integrity fields
#define NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS        0x0f

#define NDIS_802_11_AUTH_REQUEST_REAUTH             0x01
#define NDIS_802_11_AUTH_REQUEST_KEYUPDATE          0x02
#define NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR     0x06
#define NDIS_802_11_AUTH_REQUEST_GROUP_ERROR        0x0E

typedef struct _NDIS_802_11_AUTHENTICATION_REQUEST
{
    ULONG Length;            // Length of structure
    NDIS_802_11_MAC_ADDRESS Bssid;
    ULONG Flags;
} NDIS_802_11_AUTHENTICATION_REQUEST, *PNDIS_802_11_AUTHENTICATION_REQUEST;

// Added new types for OFDM 5G and 2.4G
typedef enum _NDIS_802_11_NETWORK_TYPE
{
    Ndis802_11FH,
    Ndis802_11DS,
    Ndis802_11OFDM5,
    Ndis802_11OFDM24,
    Ndis802_11NetworkTypeMax    // not a real type, defined as an upper bound
} NDIS_802_11_NETWORK_TYPE, *PNDIS_802_11_NETWORK_TYPE;

typedef struct _NDIS_802_11_NETWORK_TYPE_LIST
{
    ULONG                       NumberOfItems;  // in list below, at least 1
    NDIS_802_11_NETWORK_TYPE    NetworkType [1];
} NDIS_802_11_NETWORK_TYPE_LIST, *PNDIS_802_11_NETWORK_TYPE_LIST;

typedef enum _NDIS_802_11_POWER_MODE
{
    Ndis802_11PowerModeCAM,
    Ndis802_11PowerModeMAX_PSP,
    Ndis802_11PowerModeFast_PSP,
    Ndis802_11PowerModeMax      // not a real mode, defined as an upper bound
} NDIS_802_11_POWER_MODE, *PNDIS_802_11_POWER_MODE;

typedef ULONG   NDIS_802_11_TX_POWER_LEVEL; // in milliwatts

//
// Received Signal Strength Indication
//
typedef LONG   NDIS_802_11_RSSI;           // in dBm

typedef struct _NDIS_802_11_CONFIGURATION_FH
{
    ULONG           Length;             // Length of structure
    ULONG           HopPattern;         // As defined by 802.11, MSB set
    ULONG           HopSet;             // to one if non-802.11
    ULONG           DwellTime;          // units are Kusec
} NDIS_802_11_CONFIGURATION_FH, *PNDIS_802_11_CONFIGURATION_FH;

typedef struct _NDIS_802_11_CONFIGURATION
{
    ULONG           Length;             // Length of structure
    ULONG           BeaconPeriod;       // units are Kusec
    ULONG           ATIMWindow;         // units are Kusec
    ULONG           DSConfig;           // Frequency, units are kHz
    NDIS_802_11_CONFIGURATION_FH    FHConfig;
} NDIS_802_11_CONFIGURATION, *PNDIS_802_11_CONFIGURATION;

typedef ULONG  NDIS_802_11_KEY_INDEX;

// typedef ULONGLONG   NDIS_802_11_KEY_RSC;

// // Key mapping keys require a BSSID
// typedef struct _NDIS_802_11_KEY
// {
//     ULONG           Length;             // Length of this structure
//     ULONG           KeyIndex;           
//     ULONG           KeyLength;          // length of key in bytes
//     NDIS_802_11_MAC_ADDRESS BSSID;
//     NDIS_802_11_KEY_RSC KeyRSC;
//     UCHAR           KeyMaterial[1];     // variable length depending on above field
// } NDIS_802_11_KEY, *PNDIS_802_11_KEY;

typedef struct _NDIS_802_11_REMOVE_KEY
{
    ULONG           Length;             // Length of this structure
    ULONG           KeyIndex;           
    NDIS_802_11_MAC_ADDRESS BSSID;      
} NDIS_802_11_REMOVE_KEY, *PNDIS_802_11_REMOVE_KEY;

typedef struct _NDIS_802_11_WEP
{
    ULONG           Length;             // Length of this structure
    ULONG           KeyIndex;           // 0 is the per-client key, 1-N are the
                                        // global keys
    ULONG           KeyLength;          // length of key in bytes
    UCHAR           KeyMaterial[1];     // variable length depending on above field
} NDIS_802_11_WEP, *PNDIS_802_11_WEP;


typedef enum _NDIS_802_11_NETWORK_INFRASTRUCTURE
{
    Ndis802_11IBSS,
    Ndis802_11Infrastructure,
    Ndis802_11AutoUnknown,
    Ndis802_11InfrastructureMax         // Not a real value, defined as upper bound
} NDIS_802_11_NETWORK_INFRASTRUCTURE, *PNDIS_802_11_NETWORK_INFRASTRUCTURE;

// Add new authentication modes
typedef enum _NDIS_802_11_AUTHENTICATION_MODE
{
    Ndis802_11AuthModeOpen,
    Ndis802_11AuthModeShared,
    Ndis802_11AuthModeAutoSwitch,
    Ndis802_11AuthModeWPA,
    Ndis802_11AuthModeWPAPSK,
    Ndis802_11AuthModeWPANone,
    Ndis802_11AuthModeMax               // Not a real mode, defined as upper bound
} NDIS_802_11_AUTHENTICATION_MODE, *PNDIS_802_11_AUTHENTICATION_MODE;

typedef UCHAR   NDIS_802_11_RATES[NDIS_802_11_LENGTH_RATES];        // Set of 8 data rates
typedef UCHAR   NDIS_802_11_RATES_EX[NDIS_802_11_LENGTH_RATES_EX];  // Set of 16 data rates

typedef struct _NDIS_802_11_SSID
{
    ULONG   SsidLength;         // length of SSID field below, in bytes;
                                // this can be zero.
    UCHAR   Ssid[NDIS_802_11_LENGTH_SSID];           // SSID information field
} NDIS_802_11_SSID, *PNDIS_802_11_SSID;


typedef struct _NDIS_WLAN_BSSID
{
    ULONG                               Length;             // Length of this structure
    NDIS_802_11_MAC_ADDRESS             MacAddress;         // BSSID
    UCHAR                               Reserved[2];
    NDIS_802_11_SSID                    Ssid;               // SSID
    ULONG                               Privacy;            // WEP encryption requirement
    NDIS_802_11_RSSI                    Rssi;               // receive signal
                                                            // strength in dBm
    ULONG                               NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION           Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE  InfrastructureMode;
    NDIS_802_11_RATES                   SupportedRates;
} NDIS_WLAN_BSSID, *PNDIS_WLAN_BSSID;

typedef struct _NDIS_802_11_BSSID_LIST
{
    ULONG           NumberOfItems;      // in list below, at least 1
    NDIS_WLAN_BSSID Bssid[1];
} NDIS_802_11_BSSID_LIST, *PNDIS_802_11_BSSID_LIST;

// Added Capabilities, IELength and IEs for each BSSID
typedef struct _NDIS_WLAN_BSSID_EX
{
    ULONG                               Length;             // Length of this structure
    NDIS_802_11_MAC_ADDRESS             MacAddress;         // BSSID
    UCHAR                               Reserved[2];
    NDIS_802_11_SSID                    Ssid;               // SSID
    ULONG                               Privacy;            // WEP encryption requirement
    NDIS_802_11_RSSI                    Rssi;               // receive signal
                                                            // strength in dBm
    ULONG                               NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION           Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE  InfrastructureMode;
    NDIS_802_11_RATES_EX                SupportedRates;
    ULONG                               IELength;
    UCHAR                               IEs[1];
} NDIS_WLAN_BSSID_EX, *PNDIS_WLAN_BSSID_EX;

typedef struct _NDIS_802_11_BSSID_LIST_EX
{
    ULONG                   NumberOfItems;      // in list below, at least 1
    NDIS_WLAN_BSSID_EX      Bssid[1];
} NDIS_802_11_BSSID_LIST_EX, *PNDIS_802_11_BSSID_LIST_EX;

typedef struct _NDIS_802_11_FIXED_IEs 
{
    UCHAR Timestamp[8];
    USHORT BeaconInterval;
    USHORT Capabilities;
} NDIS_802_11_FIXED_IEs, *PNDIS_802_11_FIXED_IEs;

typedef struct _NDIS_802_11_VARIABLE_IEs 
{
    UCHAR ElementID;
    UCHAR Length;    // Number of bytes in data field
    UCHAR data[1];
} NDIS_802_11_VARIABLE_IEs, *PNDIS_802_11_VARIABLE_IEs;

typedef  ULONG   NDIS_802_11_FRAGMENTATION_THRESHOLD;

typedef  ULONG   NDIS_802_11_RTS_THRESHOLD;

typedef  ULONG   NDIS_802_11_ANTENNA;

typedef enum _NDIS_802_11_PRIVACY_FILTER
{
    Ndis802_11PrivFilterAcceptAll,
    Ndis802_11PrivFilter8021xWEP
} NDIS_802_11_PRIVACY_FILTER, *PNDIS_802_11_PRIVACY_FILTER;

// Added new encryption types
// Also aliased typedef to new name
typedef enum _NDIS_802_11_WEP_STATUS
{
    Ndis802_11WEPEnabled,
    Ndis802_11Encryption1Enabled = Ndis802_11WEPEnabled,
    Ndis802_11WEPDisabled,
    Ndis802_11EncryptionDisabled = Ndis802_11WEPDisabled,
    Ndis802_11WEPKeyAbsent,
    Ndis802_11Encryption1KeyAbsent = Ndis802_11WEPKeyAbsent,
    Ndis802_11WEPNotSupported,
    Ndis802_11EncryptionNotSupported = Ndis802_11WEPNotSupported,
    Ndis802_11Encryption2Enabled,
    Ndis802_11Encryption2KeyAbsent,
    Ndis802_11Encryption3Enabled,
    Ndis802_11Encryption3KeyAbsent
} NDIS_802_11_WEP_STATUS, *PNDIS_802_11_WEP_STATUS,
  NDIS_802_11_ENCRYPTION_STATUS, *PNDIS_802_11_ENCRYPTION_STATUS;

typedef enum _NDIS_802_11_RELOAD_DEFAULTS
{
    Ndis802_11ReloadWEPKeys
} NDIS_802_11_RELOAD_DEFAULTS, *PNDIS_802_11_RELOAD_DEFAULTS;

#define NDIS_802_11_AI_REQFI_CAPABILITIES      1
#define NDIS_802_11_AI_REQFI_LISTENINTERVAL    2
#define NDIS_802_11_AI_REQFI_CURRENTAPADDRESS  4

#define NDIS_802_11_AI_RESFI_CAPABILITIES      1
#define NDIS_802_11_AI_RESFI_STATUSCODE        2
#define NDIS_802_11_AI_RESFI_ASSOCIATIONID     4

typedef struct _NDIS_802_11_AI_REQFI
{
    USHORT Capabilities;
    USHORT ListenInterval;
    NDIS_802_11_MAC_ADDRESS  CurrentAPAddress;
} NDIS_802_11_AI_REQFI, *PNDIS_802_11_AI_REQFI;

typedef struct _NDIS_802_11_AI_RESFI
{
    USHORT Capabilities;
    USHORT StatusCode;
    USHORT AssociationId;
} NDIS_802_11_AI_RESFI, *PNDIS_802_11_AI_RESFI;

typedef struct _NDIS_802_11_ASSOCIATION_INFORMATION
{
    ULONG                   Length;
    USHORT                  AvailableRequestFixedIEs;
    NDIS_802_11_AI_REQFI    RequestFixedIEs;
    ULONG                   RequestIELength;
    ULONG                   OffsetRequestIEs;
    USHORT                  AvailableResponseFixedIEs;
    NDIS_802_11_AI_RESFI    ResponseFixedIEs;
    ULONG                   ResponseIELength;
    ULONG                   OffsetResponseIEs;
} NDIS_802_11_ASSOCIATION_INFORMATION, *PNDIS_802_11_ASSOCIATION_INFORMATION;

typedef struct _NDIS_802_11_AUTHENTICATION_EVENT
{
    NDIS_802_11_STATUS_INDICATION       Status;
    NDIS_802_11_AUTHENTICATION_REQUEST  Request[1];
} NDIS_802_11_AUTHENTICATION_EVENT, *PNDIS_802_11_AUTHENTICATION_EVENT;
        
typedef struct _NDIS_802_11_TEST
{
    ULONG Length;
    ULONG Type;
    union
    {
        NDIS_802_11_AUTHENTICATION_EVENT AuthenticationEvent;
        NDIS_802_11_RSSI RssiTrigger;
    };
} NDIS_802_11_TEST, *PNDIS_802_11_TEST;

#endif // _NTNDIS_

