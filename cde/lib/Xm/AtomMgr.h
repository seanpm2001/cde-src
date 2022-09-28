/* 
 * @OSF_COPYRIGHT@
 * (c) Copyright 1990, 1991, 1992, 1993, 1994 OPEN SOFTWARE FOUNDATION, INC.
 * ALL RIGHTS RESERVED
 *  
*/ 
/*
 * HISTORY
 * Motif Release 1.2.5
*/
/*   $XConsortium: AtomMgr.h /main/cde1_maint/2 1995/08/18 18:50:42 drk $ */
/*
*  (c) Copyright 1987, 1988, 1989, 1990, 1991, 1992 HEWLETT-PACKARD COMPANY */
#ifndef _XmAtomMgr_h
#define _XmAtomMgr_h

#include <Xm/Xm.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XM_ATOM_CACHE

#ifdef XM_ATOM_CACHE
/********    Public Function Declarations    ********/
#ifdef _NO_PROTO

extern Atom XmInternAtom() ;
extern String XmGetAtomName() ;

#else

extern Atom XmInternAtom( 
                        Display *display,
                        String name,
#if NeedWidePrototypes
                        int only_if_exists) ;
#else
                        Boolean only_if_exists) ;
#endif /* NeedWidePrototypes */
extern String XmGetAtomName( 
                        Display *display,
                        Atom atom) ;

#endif /* _NO_PROTO */
/********    End Public Function Declarations    ********/
#else /* XM_ATOM_CACHE */
#define XmInternAtom(display, name, only_if_exists) \
		XInternAtom(display, name, only_if_exists)
#define XmGetAtomName(display, atom) \
		XGetAtomName(display, atom)
#endif /* XM_ATOM_CACHE */

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#define XmNameToAtom(display, atom) \
        XmGetAtomName(display, atom)

#endif /* _XmAtomMgr_h */
