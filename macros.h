/****************************** Module Header *******************************
*
* Module Name: macros.h
*
* Wireless LAN Monitor GUI library macros header
*
* Copyright (c) WLan Project 2003
*
* $Id: macros.h,v 1.5 2006/11/12 22:07:11 cla Exp $
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

#ifndef MACROS_H
#define MACROS_H

#ifdef DEBUG

#ifdef __MODULE__
#define __FUNCNAME__ __MODULE__":"__FUNCTION__
#else
#define __FUNCNAME__ __FUNCTION__
#endif

#define FUNCNAME   printf( __FUNCNAME__"\n")
#define FUNCENTER  printf( __FUNCNAME__": ->\n")
#define FUNCEXIT   printf( __FUNCNAME__": <-\n")
#define FUNCEXITRC printf( __FUNCNAME__": <- rc=%u/0x%p\n", rc, rc)
#define FUNCEXITBL printf( __FUNCNAME__": <- result=%u\n", fResult)
#define DPRINTF(p) printf p
#define DMARK      printf( __FUNCNAME__": (%u)\n", __LINE__)

#include <malloc.h>

#define CHECKMEM   fprintf( stderr, "\n%s(%u) : checkmem in %s()\n\n", __FILE__, __LINE__, __FUNCTION__); \
                   fflush( stderr);                                                      \
                   _set_crt_msg_handle( 1);                                     \
                   _dump_allocated( 128);                                       \
                   fprintf( stderr, "\n%s(%u) : heapchk %s()returns %u\n\n", __FILE__, __LINE__, __FUNCTION__, _heapchk());

#else
#define FUNCNAME
#define FUNCENTER
#define FUNCEXIT
#define FUNCEXITRC
#define FUNCEXITBL
#define DPRINTF(p)
#define DMARK
#define CHECKMEM
#endif


#define CR      "\r"
#define LF      "\n"
#define NEWLINE LF

#ifndef MAX
#define MAX(a,b)        (a > b ? a : b)
#endif
#ifndef MIN
#define MIN(a,b)        (a < b ? a : b)
#endif

// some string handling
// internal macro to display a message
#define NEXTSTR(s)               (s+strlen(s)+1)
#define ENDSTR(s)                (s+strlen(s))
#define EOS(s)                   ((PSZ)s + strlen( s))
#define EOSSIZE(s)               (sizeof( s) - strlen( s))

// some basic PM stuff
#define CURRENTHAB                          WinQueryAnchorBlock(HWND_DESKTOP)
#define LASTERROR                           ERRORIDERROR( WinGetLastError( CURRENTHAB))
#define HWNDFRAME                           WinQueryWindow( hwnd, QW_PARENT)
#define SHOWINFO(h,s)                       WinMessageBox( HWND_DESKTOP, h, s, __APPNAME__, -1, MB_OK | MB_INFORMATION | MB_MOVEABLE)
#define SHOWERROR(h,s)                      WinMessageBox( HWND_DESKTOP, h, s, __APPNAME__, -1, MB_CANCEL | MB_ERROR | MB_MOVEABLE)
#define SHOWFATALERROR(h,s)                 WinMessageBox( HWND_DESKTOP, h, s, __APPNAME__" - Fatal Error !", -1, MB_CANCEL | MB_ERROR | MB_MOVEABLE)
#define SETFOCUS(hwnd,id)                   (WinSetFocus( HWND_DESKTOP, WinWindowFromID( hwnd, id)))

// set pointer
#define SETSYSPTR(id)                       (WinSetPointer( HWND_DESKTOP, WinQuerySysPointer( HWND_DESKTOP, id, FALSE)))

// query dialog info
#define WINDOWID(hwnd)                      (WinQueryWindowUShort( hwnd, QWS_ID))
#define CLIENTWINDOWID(hwnd)                (WinQueryWindowUShort( WinWindowFromID( hwnd, FID_CLIENT), QWS_ID))

// query dialog items
#define EXISTSWINDOW(hwnd,id)               (WinWindowFromID ( hwnd, id))

// enable/show dialog item
#define ENABLEWINDOW(hwnd,id,flag)          (WinEnableWindow(  WinWindowFromID( hwnd, id), flag))
#define SHOWWINDOW(hwnd,id,flag)            (WinShowWindow(  WinWindowFromID( hwnd, id), flag))
#define ENABLEWINDOWUPDATE(hwnd,id,flag)    (WinEnableWindowUpdate(  WinWindowFromID( hwnd, id), flag))

// query dialog item values
#define QUERYTEXTVALUE(hwnd,id,buf)         (WinQueryDlgItemText( hwnd, id, sizeof(buf), (PSZ)buf))
#define QUERYTEXTVALUE2(hwnd,id,buf,len)    (WinQueryDlgItemText( hwnd, id, len, (PSZ)buf))
#define QUERYCHECKVALUE(hwnd,id)            ((USHORT) WinSendDlgItemMsg( hwnd, id, BM_QUERYCHECK, 0L, 0L))
#define DLGQUERYSPINNUMVALUE(hwnd,id,pf)    (WinSendDlgItemMsg( hwnd, id, SPBM_QUERYVALUE, MPFROMP( pf), MPFROM2SHORT( 0, SPBQ_ALWAYSUPDATE)))


// set dialog item values
#define SETCHECKVALUE(hwnd,id,check)        (WinSendMsg( WinWindowFromID( hwnd,id), BM_SETCHECK, (MPARAM) (check != 0), 0L))
#define SETTEXTVALUE(hwnd,id,buf)           (WinSetDlgItemText( hwnd,id, buf))
#define SETTITLETEXT(hwnd, buf)             (WinSetWindowText( WinWindowFromID( WinQueryWindow( hwnd, QW_PARENT), FID_TITLEBAR), buf))
#define SETDLGTITLETEXT(hwnd, buf)          (WinSetWindowText( WinWindowFromID( hwnd, FID_TITLEBAR), buf))
#define SETTEXTLIMIT(hwnd,id,buf)           ((BOOL) WinSendDlgItemMsg( hwnd, id, EM_SETTEXTLIMIT, MPFROMSHORT(sizeof(buf)-1), 0L))
#define SETTEXTLIMITA(hwnd,id,size)         ((BOOL) WinSendDlgItemMsg( hwnd, id, EM_SETTEXTLIMIT, MPFROMSHORT(size), 0L))
#define SETREADONLY(hwnd,id,flag)           ((BOOL) WinSendDlgItemMsg( hwnd, id, EM_SETREADONLY, MPFROMSHORT( flag), 0L))
#define SETTEXTLIMIT_S(hwnd,id,size)        ((BOOL) WinSendDlgItemMsg( hwnd, id, EM_SETTEXTLIMIT, MPFROMSHORT(size), 0L))
#define DLGINITSPIN(hwnd,id,high,low)       (WinSendDlgItemMsg( hwnd, id, SPBM_SETLIMITS, MPFROMLONG(high), MPFROMLONG(low)))
#define DLGSETSPIN(hwnd,id,value)           (WinSendDlgItemMsg( hwnd, id, SPBM_SETCURRENTVALUE, MPFROMLONG(value), 0L))

// simple listbox macros
#define INSERTITEM(hwnd,id,text)            ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_INSERTITEM,      MPFROMSHORT( LIT_END), (MPARAM) text))
#define INSERTITEM_S(hwnd,id,text)          ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_INSERTITEM,      MPFROMSHORT( LIT_SORTASCENDING), (MPARAM) text))
#define DELETEITEM(hwnd,id,item)            (        WinSendDlgItemMsg( hwnd, id, LM_DELETEITEM,      MPFROMSHORT( item), 0L))
#define DELETEALLITEMS(hwnd,id)             (        WinSendDlgItemMsg( hwnd, id, LM_DELETEALL,       0L, 0L))
#define SETITEMTEXT(hwnd,id,item,text)      (        WinSendDlgItemMsg( hwnd, id, LM_SETITEMTEXT,     MPFROMSHORT( item), (MPARAM) text))
#define QUERYITEMTEXT(hwnd,id,item,buf)     (        WinSendDlgItemMsg( hwnd, id, LM_QUERYITEMTEXT,   MPFROM2SHORT(item,sizeof(buf)), (MPARAM) buf))
#define QUERYSELECTION(hwnd,id,item)        ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_QUERYSELECTION,  MPFROMSHORT( item), 0L))
#define SETSELECTION(hwnd,id,item)          (        WinSendDlgItemMsg( hwnd, id, LM_SELECTITEM,      MPFROMSHORT(item),MPFROMSHORT(TRUE)))
#define QUERYITEMCOUNT(hwnd,id)             ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_QUERYITEMCOUNT,  0L, 0L))
#define SETITEMHANDLE(hwnd,id,item,handle)  (        WinSendDlgItemMsg( hwnd, id, LM_SETITEMHANDLE,   MPFROMSHORT( item), (MPARAM) handle))
#define QUERYITEMHANDLE(hwnd,id,item)       ((PVOID) WinSendDlgItemMsg( hwnd, id, LM_QUERYITEMHANDLE, MPFROMSHORT( item), 0L))
#define SEARCHITEM(hwnd,id,text)            ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_SEARCHSTRING,    MPFROM2SHORT( 0, LIT_FIRST), (MPARAM) text))
#define QUERYTOPITEM(hwnd,id)               ((ULONG) WinSendDlgItemMsg( hwnd, id, LM_QUERYTOPINDEX,   0, 0))

// pushbutton macros
#define SETDEFBUTTON(hwnd,id)               ((BOOL) WinSendDlgItemMsg( hwnd, id, BM_SETDEFAULT, MPFROMSHORT( TRUE), 0L))

// simulate click on pushbuttons / checkboxes / radiobuttons
// in order to process control code
#define CLICKEDBUTTON(h,i)                  (WinPostMsg( h, WM_CONTROL, MPFROM2SHORT( i, BN_CLICKED), MPFROMLONG( WinWindowFromID( hwnd, i))))
// same for listbox selection
#define SELECTEDLBITEM(h,i)                 (WinPostMsg( h, WM_CONTROL, MPFROM2SHORT( i, LN_SELECT), MPFROMLONG( WinWindowFromID( hwnd, i))))

// menu macros
#define FRAMEWINDOW(h)                      WinQueryWindow( h, QW_PARENT)
#define FRAMEMENU(h)                        WinWindowFromID( WinQueryWindow( h, QW_PARENT), FID_MENU)
#define ENABLEMENUITEM(h,i,c)               WinSendMsg( h, MM_SETITEMATTR, MPFROM2SHORT( i, TRUE), MPFROM2SHORT( MIA_DISABLED, (c) ? ~MIA_DISABLED : MIA_DISABLED))
#define NODISMISSMENUITEM(h,i)              WinSendMsg( h, MM_SETITEMATTR, MPFROM2SHORT( i, TRUE), MPFROM2SHORT( MIA_NODISMISS, MIA_NODISMISS))
#define DELETEMENUITEM(h,i)                 WinSendMsg( h, MM_DELETEITEM, MPFROM2SHORT( i, TRUE), 0)
#define SETMENUCHECKVALUE(h,i,c)            WinSendMsg( h, MM_SETITEMATTR, MPFROM2SHORT( i, TRUE), MPFROM2SHORT( MIA_CHECKED, (c) ? MIA_CHECKED : ~MIA_CHECKED))
#define INSERTMENUITEM(h,p,t)               WinSendMsg( h, MM_INSERTITEM, p, t)
#define QUERYMENUITEMTEXT(h,i,buf)          WinSendMsg( h, MM_QUERYITEMTEXT, MPFROM2SHORT( i, sizeof(buf)), MPFROMP( buf));

// container macros
#define RECORD_EXTRAMEMORY(t) (sizeof( t) - sizeof( RECORDCORE))

// resource macros
#define LOADSTRING(h,i,s)                   WinLoadString( CURRENTHAB, h, i, sizeof( s), s)

// static control macros
#define SETICONHANDLE(h,i,ph)               ((BOOL)     WinSendDlgItemMsg( hwnd, i, SM_SETHANDLE, MPFROMLONG( ph), 0))
#define QUERYICONHANDLE(h,i,ph)             ((HPOINTER) WinSendDlgItemMsg( hwnd, i, SM_QUERYHANDLE, 0, 0))

#endif //MACROS_H

