/* $XConsortium: XpmWrFFrP.c /main/cde1_maint/1 1995/07/17 18:22:31 drk $ */
/*
 * (c) Copyright 1993, 1994 Hewlett-Packard Company                     *
 * (c) Copyright 1993, 1994 International Business Machines Corp.       *
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.                      *
 * (c) Copyright 1993, 1994 Novell, Inc.                                *
 */
/* Copyright 1990-92 GROUPE BULL -- See license conditions in file COPYRIGHT */
/*****************************************************************************\
* XpmWrFFrP.c:                                                                *
*                                                                             *
*  XPM library                                                                *
*  Write a pixmap and possibly its mask to an XPM file                        *
*                                                                             *
*  Developed by Arnaud Le Hors                                                *
\*****************************************************************************/

#include "xpmP.h"
#ifdef VMS
#include "sys$library:string.h"
#else
#if defined(SYSV) || defined(SVR4)
#include <string.h>
#else
#include <strings.h>
#endif
#endif

int
_DtXpmWriteFileFromPixmap(display, filename, pixmap, shapemask, attributes)
    Display *display;
    char *filename;
    Pixmap pixmap;
    Pixmap shapemask;
    XpmAttributes *attributes;
{
    XImage *image = NULL;
    XImage *shapeimage = NULL;
    unsigned int width = 0;
    unsigned int height = 0;
    int ErrorStatus;
    unsigned int dum;
    int dummy;
    Window win;

    /*
     * get geometry 
     */
    if (attributes && attributes->valuemask & XpmSize) {
	width = attributes->width;
	height = attributes->height;
    } else {
	if (pixmap)
	    XGetGeometry(display, pixmap, &win, &dummy, &dummy,
			 &width, &height, &dum, &dum);
	else if (shapemask)
	    XGetGeometry(display, shapemask, &win, &dummy, &dummy,
			 &width, &height, &dum, &dum);
    }

    /*
     * get the images 
     */
    if (pixmap)
	image = XGetImage(display, pixmap, 0, 0, width, height,
			  AllPlanes, ZPixmap);
    if (shapemask)
	shapeimage = XGetImage(display, shapemask, 0, 0, width, height,
			       AllPlanes, ZPixmap);

    /*
     * write them out 
     */
    ErrorStatus = _DtXpmWriteFileFromImage(display, filename, image, shapeimage,
					attributes);
    if (image)
	XDestroyImage(image);
    if (shapeimage)
	XDestroyImage(shapeimage);

    return (ErrorStatus);
}
