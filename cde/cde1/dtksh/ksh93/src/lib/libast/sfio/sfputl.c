/* $XConsortium: sfputl.c /main/cde1_maint/3 1995/10/14 01:12:49 montyb $ */
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
#include	"sfhdr.h"

/*	Write out a long value in a portable format
**
**	Written by Kiem-Phong Vo (06/27/90)
*/

#if __STD_C
_sfputl(reg Sfio_t* f, reg long v)
#else
_sfputl(f,v)
reg Sfio_t	*f;	/* write a portable long to this stream */
reg long	v;	/* the value to be written */
#endif
{
#define N_ARRAY		(2*sizeof(long))
	reg uchar	*s, *ps;
	reg int		n, p;
	uchar		c[N_ARRAY];

	if(f->mode != SF_WRITE && _sfmode(f,SF_WRITE,0) < 0)
		return -1;
	SFLOCK(f,0);

	s = ps = &(c[N_ARRAY-1]);
	if(v < 0)
	{	/* add 1 to avoid 2-complement problems with -SF_MAXINT */
		v = -(v+1);
		*s = (uchar)(SFSVALUE(v) | SF_SIGN);
	}
	else	*s = (uchar)(SFSVALUE(v));
	v = (ulong)v >> SF_SBITS;

	while(v > 0)
	{	*--s = (uchar)(SFUVALUE(v) | SF_MORE);
		v = (ulong)v >> SF_UBITS;
	}
	n = (ps-s)+1;

	if(n > 4 || SFWPEEK(f,ps,p) < n)
		n = SFWRITE(f,(Void_t*)s,n); /* write the hard way */
	else
	{	switch(n)
		{
		case 4 : *ps++ = *s++;
		case 3 : *ps++ = *s++;
		case 2 : *ps++ = *s++;
		case 1 : *ps++ = *s++;
		}
		f->next = ps;
	}

	SFOPEN(f,0);
	return n;
}
