/* $XConsortium: modex.c /main/cde1_maint/3 1995/10/14 01:21:53 montyb $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif
#include "modelib.h"

/*
 * convert internal mode to external
 */

#undef	modex

int
modex __PARAM__((register int i), (i)) __OTORP__(register int i;){
#if _S_IDPERM && _S_IDTYPE
	return(i);
#else
	register int	x;
	register int	c;

	x = 0;
#if _S_IDPERM
	x |= (i & 07777);
#else
	for (c = 0; c < PERMLEN; c++)
		if (i & permmap[c++])
			x |= permmap[c];
#endif
#if _S_IDTYPE
	x |= (i & X_IFMT);
#else
	if (S_ISREG(i)) x |= X_IFREG;
	else if (S_ISDIR(i)) x |= X_IFDIR;
#ifdef S_ISLNK
	else if (S_ISLNK(i)) x |= X_IFLNK;
#endif
	else if (S_ISBLK(i)) x |= X_IFBLK;
	else if (S_ISCHR(i)) x |= X_IFCHR;
#ifdef S_ISCTG
	else if (S_ISCTG(i)) x |= X_IFCTG;
#endif
	else if (S_ISFIFO(i)) x |= X_IFIFO;
#ifdef S_ISSOCK
	else if (S_ISSOCK(i)) x |= X_IFSOCK;
#endif
#endif
	return(x);
#endif
}
