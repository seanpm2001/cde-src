/* $XConsortium: fmtelapsed.c /main/cde1_maint/3 1995/10/14 01:18:52 montyb $ */
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
#include <ast.h>

char*
fmtelapsed __PARAM__((register unsigned long t, register int n), (t, n)) __OTORP__(register unsigned long t; register int n;){
	register unsigned long	s;

	static int		amt[] = { 1, 60, 60, 24, 7, 4, 12, 20 };
	static char		chr[] = "smhdwMYS";

	static char		tms[8][7];
	static int		tm;

	if (t == 0L) return("0");
	if (t == ~0L) return("%");
	if (++tm >= elementsof(tms)) tm = 0;
	s = t / n;
	if (s < 60) sfsprintf(tms[tm], sizeof(tms[tm]), "%d.%02ds", s % 100, (t * 100 / n) % 100);
	else
	{
		for (n = 1; n < elementsof(amt) - 1; n++)
		{
			if ((t = s / amt[n]) < amt[n + 1]) break;
			s = t;
		}
		sfsprintf(tms[tm], sizeof(tms[tm]), "%d%c%02d%c", (s / amt[n]) % 100, chr[n], s % amt[n], chr[n - 1]);
	}
	return(tms[tm]);
}
