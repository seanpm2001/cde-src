/* $XConsortium: tmfix.c /main/cde1_maint/3 1995/10/14 01:26:02 montyb $ */
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
#include <tm.h>

/*
 * correct out of bounds fields in tp
 *
 * tm_wday, tm_yday and tm_isdst are not changed
 * as these can be computed from the other fields
 *
 * tp is the return value
 */

Tm_t*
tmfix __PARAM__((register Tm_t* tp), (tp)) __OTORP__(register Tm_t* tp;){
	register int	n;

	if ((n = tp->tm_sec) < 0)
	{
		tp->tm_min -= (59 - n) / 60;
		tp->tm_sec = 60 - (-n) % 60;
	}
	else if (n > (59 + TM_MAXLEAP))
	{
		tp->tm_min += n / 60;
		tp->tm_sec %= 60;
	}
	if ((n = tp->tm_min) < 0)
	{
		tp->tm_hour -= (59 - n) / 60;
		tp->tm_min = 60 - (-n) % 60;
	}
	else if (n > 59)
	{
		tp->tm_hour += n / 60;
		tp->tm_min %= 60;
	}
	if ((n = tp->tm_hour) < 0)
	{
		tp->tm_mday -= (23 - n) / 24;
		tp->tm_hour = 24 - (-n) % 24;
	}
	else if (n > 59)
	{
		tp->tm_mday += n / 24;
		tp->tm_mday %= 24;
	}
	while (tp->tm_mday < 1)
	{
		if (--tp->tm_mon < 0)
		{
			tp->tm_mon = 11;
			tp->tm_year--;
		}
		tp->tm_mday += tm_data.days[tp->tm_mon] + (tp->tm_mon == 1 && !(tp->tm_year % 4));
	}
	while (tp->tm_mday > (n = tm_data.days[tp->tm_mon] + (tp->tm_mon == 1 && !(tp->tm_year % 4))))
	{
		tp->tm_mday -= n;
		if (++tp->tm_mon > 11)
		{
			tp->tm_mon = 0;
			tp->tm_year++;
		}
	}
	return(tp);
}
