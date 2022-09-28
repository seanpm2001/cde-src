/* $XConsortium: revlib.c /main/cde1_maint/3 1995/10/14 01:36:58 montyb $ */
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
#include	<cmdlib.h>

#define BUFSIZE			SF_BUFSIZE
#define rounddown(n,size)	(((n)-1)&~((size)-1))

/*
 * copy the lines starting at offset <start> from in <in> to <out>
 * in reverse order
 */
int rev_line __PARAM__((Sfio_t *in, Sfio_t *out, off_t start), (in, out, start)) __OTORP__(Sfio_t *in; Sfio_t *out; off_t start;){
	register char *cp, *cpold;
	register int n, nleft=0;
	char buff[BUFSIZE];
	off_t offset;
	if(sfseek(in,(off_t)0,SEEK_CUR) < 0)
	{
		Sfio_t *tmp = sftmp(4*SF_BUFSIZE);
		if(!tmp)
			return(-1);
		if(start>0)
			sfmove(in, (Sfio_t*)0, (long)start, -1);
		if(sfmove(in, tmp, SF_UNBOUND, -1) < 0)
			return(-1);
		in = tmp;
		start=0;
	}
	if((offset = sfseek(in,(off_t)0,SEEK_END)) <= start)
		return(0);
	offset = rounddown(offset,BUFSIZE);
	while(1)
	{
		n = BUFSIZE;
		if(offset < start)
		{
			n -= (start-offset);
			offset = start;
		}
		sfseek(in, offset, SEEK_SET);
		if((n=sfread(in, buff, n)) <=0)
			break;
		cp = buff+n;
		n = *buff;
		*buff = '\n';
		while(1)
		{
			cpold = cp;
			if(nleft==0)
				cp--;
			if(cp==buff)
			{
				nleft= 1;
				break;
			}
			while(*--cp != '\n');
			if(cp==buff && n!='\n')
			{
				*cp = n;
				nleft += cpold-cp;
				break;
			}
			else
				cp++;
			if(sfwrite(out,cp,cpold-cp) < 0)
				return(-1);
			if(nleft)
			{
				if(nleft==1)
					sfputc(out,'\n');
				else if(sfmove(in,out,nleft,-1) < 0)
					return(-1);
				nleft = 0;
			}
		}
		if(offset <= start)
			break;
		offset -= BUFSIZE;
	}
	if(nleft)
	{
		sfseek(in, start, SEEK_SET);
		if(sfmove(in,out,nleft,-1) < 0)
			return(-1);
	}
	return(0);
}
