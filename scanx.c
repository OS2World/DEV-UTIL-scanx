
/***********************************************************************

scanx

Copyright (c) 2012 Steven Levine and Associates, Inc.
All rights reserved.

This program is free software licensed under the terms of the GNU
General Public License, Version 2.  The GPL Software License can be found
in gnugpl2.txt or at http://www.gnu.org/licenses/licenses.html#GPL

2012-05-24 SHL Baseline
2012-06-23 SHL Default buffer to 32K-1 (the max supported)

Build as Watcom OS/2 VIO app using makefile

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>			// atol
#include <string.h>

#define INCL_DOS
#define INCL_DOSERRORS

#include <os2.h>

// from genmac xwlan
#include "ntndis.h"
#include "drvaccess.h"
#include "ioctl.hpp"
#include "macros.h"

// ===========================================

#define	PGM_ID		"scanx"
#define VERSION		1
#define	REVISION	0

// Disable to find unreferenced variables
// #pragma disable_message(202);

//===========================================

#if 0					// Enable to include markings
static char *Copyright[] = {
  "Copyright (c) 2012 Steven Levine and Associates, Inc.",
  "All rights reserved."
};
#endif

int main(int argc, char **argv);
int sub(void);

// #define OIDGET(h,i,d) _oidGet(h, i, &d, sizeof(d))
static APIRET _oidGet(HFILE hfileDriver, ULONG ulOid, PVOID pvData,
		      ULONG ulDataLen)
{
  APIRET rc = NO_ERROR;
  ULONG aulParms[4];
  ULONG ulParmLen;

  do {
    // check parms
    if (!pvData) {
      rc = ERROR_INVALID_PARAMETER;
      break;
    }
    memset(pvData, 0, ulDataLen);

    // setup parameters
    memset(aulParms, 0, sizeof(aulParms));
    aulParms[0] = ulOid;
    aulParms[1] = ulDataLen;		// need to pass length of data also
    // here !
    ulParmLen = sizeof(aulParms);

    // get data
    rc = DosDevIOCtl(hfileDriver, GENMAC_CATEGORY, GENMAC_WRAPPER_OID_GET,
		     aulParms, ulParmLen, &ulParmLen,
		     pvData, ulDataLen, &ulDataLen);
    if (rc != NO_ERROR) {
      printf("DosDevIOCtl failed with error %lu at %u\n", rc, __LINE__);
      break;
    }

    // check for OID error
    if (aulParms[3])
      rc = ERROR_INVALID_FUNCTION;

    if (rc != NO_ERROR)
      if ((rc != ERROR_INVALID_FUNCTION) &&
	  (aulParms[0] != OID_802_11_BSSID) && (aulParms[3] != 0xc0010011)) {
	printf
	  ("XWLAN: OIDGET rc %u - OID: 0x%08x - len 0x%08x - parm2 0x%08x - OID rc 0x%08x\n",
	   rc, aulParms[0], aulParms[1], aulParms[2], aulParms[3]);
      }

  } while (FALSE);

  return rc;
}

// --------------------------------------------------------------------------

#define OIDSET(h,i,d) _oidSet(h, i, &d, sizeof(d))
static APIRET _oidSet(HFILE hfileDriver, ULONG ulOid, PVOID pvData,
		      ULONG ulDataLen)
{
  APIRET rc = NO_ERROR;
  ULONG aulParms[4];
  ULONG ulParmLen;
  ULONG ulValue;

  do {
    // check parms
    if (!pvData) {
      rc = ERROR_INVALID_PARAMETER;
      break;
    }

    // setup parameters
    memset(aulParms, 0, sizeof(aulParms));
    aulParms[0] = ulOid;
    aulParms[1] = ulDataLen;		// need to pass length of data also
					// here !
    ulParmLen = sizeof(aulParms);

    if (pvData)
      ulValue = *((PULONG) pvData);

    // get data
    rc = DosDevIOCtl(hfileDriver, GENMAC_CATEGORY, GENMAC_WRAPPER_OID_SET,
		     aulParms, ulParmLen, &ulParmLen,
		     pvData, ulDataLen, &ulDataLen);
    if (rc != NO_ERROR) {
      printf("DosDevIOCtl failed with error %lu at %u\n", rc, __LINE__);
      break;
    }

    // check for OID error
    if (aulParms[3]) {
      rc = ERROR_INVALID_FUNCTION;
      printf("XWLAN: OIDSET rc %u - OID: 0x%08x - len 0x%08x - parm2 0x%08x - OID rc 0x%08x, returned data 0x%08x\n",
	     rc, aulParms[0], aulParms[1], aulParms[2], aulParms[3], ulValue);
    }

  } while (FALSE);

  return rc;
}

#define GENMAC_MAXLEVEL -35
#define GENMAC_MINLEVEL -95

static USHORT _getQualityFromLevel(LONG lSignalLevel)
{
  USHORT usQuality;
  LONG lQuality;

  // Min/Max calculation with -95 dbm (minimum) to -35 dbm (maximum)
  // s = -35 -> 100% -35 + 95 = 60 60 * 60 / 60 = 60 XWLAN 100%
  // s = -95 -> 0% -95 + 95 = 0 0 * 60 / 65 = 0 XWLAN 0%

  // adjust signal value to positive - make sure to keep lower/upper
  // boundary
  lQuality = lSignalLevel - GENMAC_MINLEVEL;
  if (lQuality < 0)
    lQuality = 0;
  if (lQuality > -GENMAC_MINLEVEL)
    lQuality = -GENMAC_MINLEVEL;

  // adjust to XWLAN signal value
  usQuality =
    lQuality * WLAN_QUAL_MAXLEVEL / (GENMAC_MAXLEVEL - GENMAC_MINLEVEL);

  // make sure we don't exceed maximum value
  usQuality = MIN(usQuality, WLAN_QUAL_MAXLEVEL);

  return usQuality;
}

typedef struct _CHANNEL
{
  ULONG ulChannel;
  ULONG ulFrequency;
} CHANNEL, *PCHANNEL;

static CHANNEL achnList[] = {
  {1, 2412000},	// 2.4 Ghz band
  {2, 2417000},
  {3, 2422000},
  {4, 2427000},
  {5, 2432000},
  {6, 2437000},
  {7, 2442000},
  {8, 2447000},
  {9, 2452000},
  {10, 2457000},
  {11, 2462000},
  {12, 2467000},
  {13, 2472000},
  {34, 5170000},				// 5 Ghz band
  {36, 5180000},
  {38, 5190000},
  {40, 5200000},
  {42, 5210000},
  {44, 5220000},
  {46, 5230000},
  {48, 5240000},
  {52, 5260000},
  {56, 5280000},
  {60, 5300000},
  {64, 5320000},
  {149, 5745000},
  {153, 5765000},
  {157, 5785000},
  {161, 5805000}
};

#define MAX_FREQUENCIES (sizeof(achnList) / sizeof(CHANNEL))

// --------------------------------------------------------------------------

ULONG DimHlpGetChannel(ULONG ulFrequency)
{
  ULONG ulChannel = 0;
  PCHANNEL pchn;
  ULONG i;

  for (i = 0, pchn = achnList; i < MAX_FREQUENCIES; i++, pchn++) {
    if (ulFrequency == pchn->ulFrequency) {
      ulChannel = pchn->ulChannel;
      break;
    }
  }

  return ulChannel;
}

/**
 * Main program
 */

int main(int argc, char **argv)
{
  APIRET apiret = NO_ERROR;

  // printf("Built with __WATCOMC__ %d\n", __WATCOMC__);

  BYTE *pbListData;
  ULONG ulListDataBytes = 0;
  BOOL fDummy = 0;
  HFILE hfileDriver = NULLHANDLE;
  ULONG ulAction;
  PNDIS_802_11_BSSID_LIST_EX pble;
  PNDIS_WLAN_BSSID_EX pbe;

  SCANINFO si;
  ULONG ulItemsCopied = 0;
  ULONG ulSSIDLength;

  do {
    PSZ pszDriverName = "WRND32$";
    UINT argNdx;

    for (argNdx = 1; argNdx < argc; argNdx++) {
      if (ulListDataBytes) {
	apiret = 1;			// To many args
	break;
      }
      ulListDataBytes = atol(argv[1]);
      if (ulListDataBytes == 0)
	apiret = 1;			// Bad number
      if (ulListDataBytes > 32767) {
	printf("Buffer size limited to 32767 by driver\n");
	apiret = 1;			// Bad number
      }
    } // for

    if (apiret) {
      printf("Usage: scanx [buffersize]\n");
      break;
    }

    if (!ulListDataBytes)
      ulListDataBytes = 32767;	// Default

    pbListData = malloc(ulListDataBytes);

    if (pbListData == NULL) {
      printf("Can not allocate %ld bytes\n", ulListDataBytes);
      apiret = 1;
      break;
    }

    apiret =
      DosOpen(pszDriverName, &hfileDriver, &ulAction, 0, FILE_NORMAL,
	      OPEN_ACTION_OPEN_IF_EXISTS | OPEN_ACTION_FAIL_IF_NEW,
	      OPEN_SHARE_DENYNONE, NULL);
    if (apiret != NO_ERROR) {
      printf("DosOpen %s failed with error %lu at %u\n",
	     pszDriverName, apiret, __LINE__);
      break;
    }
    // initiate scan (parm fDummy used to keep the macro satisfied)
    apiret = OIDSET(hfileDriver, OID_802_11_BSSID_LIST_SCAN, fDummy);
    if (apiret != NO_ERROR) {
      printf
	("OIDSET OID_802_11_BSSID_LIST_SCAN failed with error %lu at %u\n",
	 apiret, __LINE__);
      break;
    }

    // give up some time
    DosSleep(1000);

    apiret = _oidGet(hfileDriver, OID_802_11_BSSID_LIST, pbListData, ulListDataBytes);
    if (apiret != NO_ERROR) {
      printf
	("OIDGET OID_802_11_BSSID_LIST failed with error %lu at %u\n",
	 apiret, __LINE__);
      break;
    }

    pble = (PNDIS_802_11_BSSID_LIST_EX)pbListData;

    printf("\nOIDGET OID_802_11_BSSID_LIST returned %lu items\n\n",
	   pble->NumberOfItems);

    // if nothing found, bail out
    if (!pble->NumberOfItems)
      break;

    for (ulItemsCopied = 0, pbe = pble->Bssid;
	 ulItemsCopied < pble->NumberOfItems;
	 ulItemsCopied++, pbe =
	 (PNDIS_WLAN_BSSID_EX) ((PBYTE) pbe + pbe->Length)) {
      // copy item
      ulSSIDLength = MIN(pbe->Ssid.SsidLength, sizeof(si.szSSID) - 1);
      strncpy(si.szSSID, (char *)pbe->Ssid.Ssid, ulSSIDLength);
      si.szSSID[ulSSIDLength] = 0;

      memcpy(si.achBSSID, pbe->MacAddress, sizeof(si.achBSSID));

      si.ulStationType = pbe->InfrastructureMode;
      si.ulNetworkType = pbe->NetworkTypeInUse;
      si.ulChannel = DimHlpGetChannel(pbe->Configuration.DSConfig);
      si.fPrivacy = pbe->Privacy;
      memcpy(si.chMacAddress, pbe->MacAddress, sizeof(si.chMacAddress));
      si.ulQuality = _getQualityFromLevel(pbe->Rssi);

      printf("SSID: %s, level %ld dBm +%d=%u (%u%%)\n",
	     si.szSSID,
	     pbe->Rssi,
	     -GENMAC_MINLEVEL,
	     si.ulQuality,
	     si.ulQuality * 100 / WLAN_QUAL_MAXLEVEL);
    } // for
  } while (0); // once

  if (hfileDriver) {
    DosClose(hfileDriver);
    hfileDriver = NULLHANDLE;
  }

  if (apiret)
    printf("Exiting with rc %u\n", apiret);

  return apiret;

} // main

// The end
