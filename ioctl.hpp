/****************************** Module Header *******************************
*
* Module Name: ioctl.hpp
*
* genmac I/O control definition header file
*
* Copyright (c) Willybald Meyer, WLan Project 2005
*
* $Id: ioctl.hpp,v 1.1 2005/09/07 20:21:35 cla Exp $
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

#ifndef     IOCTL_HPP
#define     IOCTL_HPP

#define     GENMAC_CATEGORY         0x99
#define     GENMAC_READ_PHY_ADDR    0x01
#define     GENMAC_READ_MII_REG     0x02
#define     GENMAC_WRITE_MII_REG    0x03
#define     GENMAC_READ_PHY_TYPE    0x04

#define     GENMAC_GET_DEBUGLEVEL   0x10
#define     GENMAC_SET_DEBUGLEVEL   0x11

#define     GENMAC_QUERY_DEV_BUS    0x20

#define     GENMAC_HELPER_REQUEST   0x30
#define     GENMAC_HELPER_RETURN    0x31

#define     GENMAC_WRAPPER_OID_GET  0x40
#define     GENMAC_WRAPPER_OID_SET  0x41

#endif

