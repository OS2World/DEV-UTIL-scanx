/****************************** Module Header *******************************
*
* Module Name: drvaccess.h
*
* Wireless LAN driver API library driver access module header
*
* Copyright (c) WLan Project 2003
*
* $Id: drvaccess.h,v 1.31 2007/04/03 23:14:48 cla Exp $
*
* ===========================================================================
*
* This file is part of the WLan Project and is free software.  You can
* redistribute it and/or modify it under the terms of the GNU Library General
* Public License as published by the Free Software Foundation, in version 2
* as it comes in the "COPYING.LIB" file of the WLan Project CVS tree.
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
* License for more details.
*
****************************************************************************/

#ifndef DRVACCESS_H
#define DRVACCESS_H

#pragma pack( 1)

/* return value of WLanOpenDriver */
#define WLAN_NODRIVER (ULONG) -1

/* uknown IP interface number where it cannot be determined */
#define WLAN_UNKNOWNIPINTERFACE (ULONG) -1


/* some maxlen values */
#define WLAN_SSID_MAXLEN    33
#define WLAN_BSSID_MAXLEN    6
#define WLAN_KEY_COUNT       4
#define WLAN_KEY_MAXLEN     14
#define WLAN_KEY_WEP64LEN    5
#define WLAN_KEY_WEP128LEN  13
#define WLAN_NETNAME_MAXLEN 32
#define WLAN_PSK_MAXLEN     63

/* ----------------------------------------------- */

// NOTE: layout of DRIVERREVDATA is
//       used by genprism.dim directly !!!

typedef struct _DRIVERREVDATA {
  USHORT         usMajorRev;
  USHORT         usMinorRev;
  ULONG          ulCapabilities;
} DRIVERREVDATA, *PDRIVERREVDATA;

/* values for DRIVERREVDATA.ulCapabilities */
#define WLAN_CAP_GET_SIGNAL          0x00000001L
#define WLAN_CAP_WEP                 0x00000002L
#define WLAN_CAP_TALLIES             0x00000004L
#define WLAN_CAP_INF_SIGNAL          0x00000008L
#define WLAN_CAP_INF_CONFIG          0x00000010L
#define WLAN_CAP_SET_CONFIG          0x00000020L
#define WLAN_CAP_RAW_CMD             0x00000040L
#define WLAN_CAP_RADIO_CONTROL       0x00000080L
#define WLAN_CAP_WPA                 0x00000100L

/* non-genprism values for DRIVERREVDATA.ulCapabilities */
/* implemented by new driver interface modules          */
#define WLAN_CAP_SCAN                0x80000000L
#define WLAN_CAP_POWERMODE           0x40000000L
#define WLAN_CAP_MULTNETWORKS        0x20000000L
#define WLAN_CAP_AUTOCREATEIBBS      0x10000000L

/* ----------------------------------------------- */

// NOTE: layout of SIGNALDATA is
//       used by genprism.dim directly !!!

typedef struct _SIGNALDATA {
  USHORT         usStatus;
  USHORT         usQuality;
  USHORT         usSignalLevel;
  USHORT         usNoiseLevel;
  USHORT         usTxRate;
} SIGNALDATA, *PSIGNALDATA;

/* range values for SIGNALDATA.usQuality */
#define WLAN_QUAL_MINLEVEL  0
#define WLAN_QUAL_MAXLEVEL 60

/* values for SIGNALDATA.usStatus                        */
/* driver returns values up to 0x06 - WLAN_SIGNAL_NOCARD */
/* all other values set by XWLAN GUI only                */
#define WLAN_SIGNAL_CONNNONE     0x00
#define WLAN_SIGNAL_CONN20       0x01
#define WLAN_SIGNAL_CONN40       0x02
#define WLAN_SIGNAL_CONN60       0x03
#define WLAN_SIGNAL_CONN80       0x04
#define WLAN_SIGNAL_CONN100      0x05
#define WLAN_SIGNAL_NOCARD       0x06
#define WLAN_SIGNAL_NODRIVER     0x07
#define WLAN_SIGNAL_DISABLED     0x08
#define WLAN_SIGNAL_SEARCHING    0x09
#define WLAN_SIGNAL_SCANNING     0x0A
#define WLAN_SIGNAL_CONFIGURING  0x0B
#define WLAN_SIGNAL_NODATAACCESS 0x0C
#define WLAN_SIGNAL_IPDISABLED   0x0D
#define WLAN_SIGNAL_SCRIPT       0x0E
#define WLAN__MAX_SIGNAL (WLAN_SIGNAL_SCRIPT + 1)

/* ----------------------------------------------- */

// NOTE: layout of SSIDDATA is
//       used by genprism.dim directly !!!

typedef struct _SSIDDATA {
  USHORT         usStatus;
  CHAR           szSSID[ WLAN_SSID_MAXLEN + 1];
  CHAR           achCurrentBSSID[ WLAN_BSSID_MAXLEN];
} SSIDDATA, *PSSIDDATA;

/* values for SSIDDATA.usStatus                                */
/* driver returns values up to 0x06 - WLAN_STATUS_CONNECTEDWDS */
/* all other values set by XWLAN GUI only                      */
#define WLAN_STATUS_NOCARDDETECTED      0x00
#define WLAN_STATUS_DISABLED            0x01
#define WLAN_STATUS_SEARCHING           0x02
#define WLAN_STATUS_CONNECTEDIBBS       0x03
#define WLAN_STATUS_CONNECTEDESS        0x04
#define WLAN_STATUS_OUTOFRANGE          0x05
#define WLAN_STATUS_CONNECTEDWDS        0x06
#define WLAN_STATUS_INTERNALERROR       0x07
#define WLAN_STATUS_NOTINSTALLED        0x08
#define WLAN_STATUS_CONFIGURING         0x09
#define WLAN_STATUS_NODATAACCESS        0x0A
#define WLAN_STATUS_IPDISABLED          0x0B
#define WLAN_STATUS_SCRIPT              0x0C
#define WLAN__MAX_STATUS (WLAN_STATUS_SCRIPT + 1)

#define WLAN_STATUS_STRLIST { "NOCARDDETECTED", "DISABLED", "SEARCHING", "CONNECTEDIBBS", "CONNECTEDESS", "OUTOFRANGE", "CONNECTEDWDS", "INTERNALERROR", "NOTINSTALLED", "CONFIGURING", "NODATAACCESS", "IPDISABLED", "SCRIPT"}

/* ----------------------------------------------- */

// NOTE: layout of ENCRYPTIONDATA/WEPDATA is
//       used by genprism.dim directly !!!

typedef struct _WEPDATA {
  USHORT         usTransmitKey;
  UCHAR          auchKey[ WLAN_KEY_COUNT][ WLAN_KEY_MAXLEN];
  USHORT         auchKeyType[ WLAN_KEY_COUNT];
} WEPDATA, *PWEPDATA;

typedef struct _WPADATA {
  USHORT         usReserved;
  CHAR           szPsk[ WLAN_PSK_MAXLEN + 1];
} WPADATA, *PWPADATA;

typedef struct _KEYDATA {
  union {
    WEPDATA        wep;
    WPADATA        wpa;
  };
} KEYDATA, *PKEYDATA;

// NOTE: layout of ENCRYPTIONDATA/WEPDATA is
//       used by genprism.dim directly !!!

typedef struct _ENCRYPTIONDATA {
  USHORT         usEncType;
  USHORT         usExcludeUnencrypted;
  USHORT         usAuthType;
  KEYDATA        keydata;
} ENCRYPTIONDATA, *PENCRYPTIONDATA;

/* values for ENCRYPTIONDATA.usEncType */
#define WLAN_ENC_DISABLED          0x0000
#define WLAN_ENC_WEP64             0x0001
#define WLAN_ENC_WEP128            0x0002
#define WLAN_ENC_WPA_PSK           0x0003
#define WLAN_ENC_WPA2_PSK          0x0004

/* NLS independant abbreviations for a string array */
#define WLAN_ENC_TYPELIST { "-", "WEP64", "WEP128", "WPA-PSK", "WPA2-PSK"}

/* values for ENCRYPTIONDATA.usExcludeUnencrypted */
#define WLAN_FILTER_EXCLUDENONE   0
#define WLAN_FILTER_EXCLUDEUNENC  1

/* values for ENCRYPTIONDATA.usAuthType */
#define WLAN_AUTHMODE_OPEN     0
#define WLAN_AUTHMODE_SHARED   1
#define WLAN_AUTHMODE_ANY      2

/* ----------------------------------------------- */

// NOTE: layout of CONNECTIONDATA is
//       used by genprism.dim directly !!!

typedef struct _CONNECTIONDATA {
  USHORT         usConnType;
  USHORT         usCreateNetwork;
  UCHAR          auchNetworkName[ WLAN_NETNAME_MAXLEN];
  USHORT         usNameLength;
} CONNECTIONDATA, *PCONNECTIONDATA;

/* values for CONNECTIONDATA.usConnType */
#define WLAN_STATIONMODE_BSS   0
#define WLAN_STATIONMODE_ADHOC 1

/* macros to add or extract network type from/to CONNECTIONDATA.usConnType */
#define WLAN_SETNETWORKTYPE(v,t) (v | (t<<8))
#define WLAN_GETNETWORKTYPE(v)   ((v & 0xff00)>>8)

/* ----------------------------------------------- */

#define WLAN_DRVNAME_MAXLEN     8
#define WLAN_DRVTITLE_MAXLEN   64

typedef struct _DRIVERCONFIG {
  CHAR           szDriverName[ WLAN_DRVNAME_MAXLEN  + 1];
  CHAR           szDriverTitle[ WLAN_DRVTITLE_MAXLEN + 1];
  ULONG          ulIpInterface;
  HFILE          hfileDriver;
  HMODULE        hmod;
} DRIVERCONFIG, *PDRIVERCONFIG;

typedef struct _DRIVERLIST {
  ULONG          ulDriverCount;
  DRIVERCONFIG   adc[ 1];
} DRIVERLIST, *PDRIVERLIST;

#define WLAN_DRIVERLIST_SIZE(e) (sizeof( DRIVERLIST) + ((e - 1) * sizeof( DRIVERCONFIG)))

/* ----------------------------------------------- */

typedef struct _SCANINFO {
  ULONG          ulLength;
  CHAR           szSSID[ WLAN_SSID_MAXLEN + 1];
  CHAR           achBSSID[ WLAN_BSSID_MAXLEN];
  ULONG          ulStationType;
  ULONG          ulNetworkType;
  ULONG          ulChannel;
  BOOL           fPrivacy;
  ULONG          ulQuality;
  CHAR           chMacAddress[ 6];
} SCANINFO, *PSCANINFO;

typedef struct _SCANINFOLIST {
  ULONG          ulInfoCount;
  SCANINFO       asi[ 1];
} SCANINFOLIST, *PSCANINFOLIST;

/* values for SCANINFO.ulStationType */
#define WLAN_STATIONTYPE_ESS     0
#define WLAN_STATIONTYPE_IBSS    1

/* values for SCANINFO.ulNetworkType */
#define WLAN_NETWORKTYPE_80211A_11MBIT  0x0000
#define WLAN_NETWORKTYPE_80211B_11MBIT  0x0001
#define WLAN_NETWORKTYPE_80211A_54MBIT  0x0002
#define WLAN_NETWORKTYPE_80211G_54MBIT  0x0003
#define WLAN_NETWORKTYPE_ANY            0xFFFF

#define WLAN_INFOLIST_SIZE(e) (sizeof( SCANINFOLIST) + ((e - 1) * sizeof( SCANINFO)))

/* ----------------------------------------------- */

/* values for WLanGetDriverMode / WLanSetDriverMode */
#define WLAN_DRVMODE_POWER                  0x0001
#define WLAN_DRVMODE_NETWORKINUSE           0x0002
#define WLAN_DRVMODE_RTSTHRESHOLD           0x0003
#define WLAN_DRVMODE_FRAGTHRESHOLD          0x0004
#define WLAN_DRVMODE_WPASUPCONTROL          0x8000

/* values for WLAN_DRVMODE_POWER */
#define WLAN_POWERMODE_CAM              0
#define WLAN_POWERMODE_MAXPSP           1
#define WLAN_POWERMODE_FASTPSP          2

/* values for WLAN_DRVMODE_NETWORKINUSE */
#define WLAN_SELNETWORK_ANY            0x0000
#define WLAN_SELNETWORK_80211B_11MBIT  0x0001
#define WLAN_SELNETWORK_80211G_54MBIT  0x0002
#define WLAN_SELNETWORK_80211A_54MBIT  0x0003

/* values for WLAN_DRVMODE_WPASUP_DEBUGLEVEL */
#define WLAN_SUPPLICANTDEBUGLEVEL_MSGDUMP    0
#define WLAN_SUPPLICANTDEBUGLEVEL_DEBUG      1
#define WLAN_SUPPLICANTDEBUGLEVEL_INFO       2
#define WLAN_SUPPLICANTDEBUGLEVEL_WARNING    3
#define WLAN_SUPPLICANTDEBUGLEVEL_ERROR      4

/* ----------------------------------------------- */

#pragma pack()


#ifndef DIM_H

/* prototypes */
APIRET WLanDriverAccessInitialize( VOID);
APIRET WLanDriverAccessTerminate( VOID);
APIRET WLanQueryGlobalCapabilities( PULONG pulGlobalCapabilities);

BOOL APIENTRY WLanIsDriverSupported( PSZ pszDriverName);
APIRET APIENTRY WLanQueryAvailableDrivers( PDRIVERLIST pdl, PULONG pulDriverCount);
APIRET APIENTRY WLanQueryDriverTitle( PSZ pszDriverName, PSZ pszBuffer, ULONG ulBuflen);

HFILE APIENTRY WLanOpenDriver( PSZ pszDriverName);
APIRET APIENTRY WLanGetDriverInfo( HFILE hfileDriver, PDRIVERREVDATA pdrd);
APIRET APIENTRY WLanGetSSIDInfo( HFILE hfileDriver, PSSIDDATA psd);
APIRET APIENTRY WLanGetSNRInfo( HFILE hfileDriver, PSIGNALDATA psd);
APIRET APIENTRY WLanSetupConnection( HFILE hfileDriver, PCONNECTIONDATA pcd, PENCRYPTIONDATA ped);
APIRET APIENTRY WLanEnableRadio( HFILE hfileDriver, BOOL fEnable);
APIRET APIENTRY WLanQueryIpInterface( HFILE hfileDriver, PULONG pulInterface);
APIRET APIENTRY WLanCloseDriver( HFILE hfileDriver);
APIRET APIENTRY WLanScan( HFILE hfileDriver, PSCANINFOLIST psil, PULONG pulInfoCount);
APIRET APIENTRY WLanGetDriverMode(  HFILE hfileDriver, ULONG ulMode, PULONG pulValue);
APIRET APIENTRY WLanSetDriverMode(  HFILE hfileDriver, ULONG ulMode, ULONG ulValue);

#endif // ! DIM_H

#endif // DRVACCESS_H

