/*******************************************************************************
**
**  timezone.h
**
**  #pragma ident "@(#)timezone.h	1.7 96/11/12 Sun Microsystems, Inc."
**
**  $XConsortium: timezone.h /main/cde1_maint/1 1995/07/14 23:16:12 drk $
**
**  RESTRICTED CONFIDENTIAL INFORMATION:
**
**  The information in this document is subject to special
**  restrictions in a confidential disclosure agreement between
**  HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
**  document outside HP, IBM, Sun, USL, SCO, or Univel without
**  Sun's specific written approval.  This document and all copies
**  and derivative works thereof must be returned or destroyed at
**  Sun's request.
**
**  Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
**
*******************************************************************************/

/*									*
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc. 				*
 */

#ifndef _TIMEZONE_H
#define _TIMEZONE_H

typedef enum {mytime, customtime} Timezonetype;
typedef struct {
	Widget          	frame;
	Widget          	form;
	Widget			timezone_rc_mgr;
	Widget			mytime;
	Widget			customtime;
	Widget			gmtlabel;
	Widget			gmtcombo;
	Widget			hourlabel;
	Widget			cancelbutton;
	Widget			helpbutton;
	Widget			okbutton;
	Widget			applybutton;
	Widget			timezone_message;
	Timezonetype		timezone_type;
	char			mytimezone[BUFSIZ];
}Timezone;

extern caddr_t	make_timezone(Calendar*);

#endif
