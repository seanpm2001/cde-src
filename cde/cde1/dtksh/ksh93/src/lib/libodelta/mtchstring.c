/* $XConsortium: mtchstring.c /main/cde1_maint/3 1995/10/14 01:39:00 montyb $ */
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
#include	"update.h"


/*
**	Find the longest prefix of tar that match some substring of src
**	This uses an inverted index for speed.
*/
#define ALPHA	(256)	/* alphabet size */

static void freemem __PARAM__((long* n_index, char*** index), (n_index, index)) __OTORP__(long* n_index; char*** index;){
	register int i;
	if(n_index && index)
	{
		for(i = 0; i < ALPHA; ++i)
			if(n_index[i] > 0)
				free(index[i]);
		free(index);
		free(n_index);
	}
}

/* initial assumptions: src[0] == tar[0] && src+n_match <= endsrc */
static long domatch __PARAM__((char* src, char* endsrc, char* tar, char* endtar, long n_match), (src, endsrc, tar, endtar, n_match)) __OTORP__(char* src; char* endsrc; char* tar; char* endtar; long n_match;){
	register char	*sp, *tp;

	/* see if this really improves on the current match */
	for(sp = src+n_match, tp = tar+n_match; sp > src; --sp, --tp)
		if(*sp != *tp)
			break;

	/* got an improvement, match as many more as we can */
	if(sp == src)
	{
		sp = src+n_match+1;
		tp = tar+n_match+1;
		for(; sp < endsrc && tp < endtar; ++sp, ++tp)
			if(*sp != *tp)
				break;
	}
	return tp-tar;
}

/* the real thing */
long	mtchstring __PARAM__((char* src, long n_src, char* tar, long n_tar, char** match), (src, n_src, tar, n_tar, match)) __OTORP__(char* src; long n_src; char* tar; long n_tar; char** match;){
	char		*endsrc, *endtar;
	long		n_match;
	register int	i;
	register long	n_ind;
	register char	**ind;
	static long	*N_index = 0;
	static char	*Cursrc = 0, ***Index = 0;
	static int	Alloced = 0;

	/* free old inverted indices if necessary */
	if(src != Cursrc)
	{
		if(Alloced)
			freemem(N_index,Index);
		Alloced = 0;
		Cursrc = 0;
	}

	/* nothing to do */
	if(!src || n_src <= 0 || !tar || n_tar <= 0)
		return 0;

	endsrc = src + n_src;
	endtar = tar + n_tar;

	/* build new index structure */
	if(src != Cursrc)
	{
		Cursrc = src;
		Alloced = 1;
		if(N_index = (long*) malloc(ALPHA*sizeof(long)))
		{
			register char	*sp;

			memzero(N_index,ALPHA*sizeof(long));
			if(!(Index = (char ***) malloc(ALPHA*sizeof(char**))))
			{
				free(N_index);
				N_index = 0;
				Alloced = 0;
			}
			else for(sp = src; sp < endsrc; ++sp)
			{
				i = (int)(*((unsigned char *)(sp)));
				ind = Index[i];
				n_ind = N_index[i];

				/* make sure we have space */
				if((n_ind%ALPHA) == 0)
				{
					ind = n_ind == 0 ?
					      (char**)malloc(ALPHA*sizeof(char *)) :
					      (char**)realloc(ind,(n_ind+ALPHA)*sizeof(char*));
					Index[i] = ind;
				}
				if(ind)
				{
					ind[n_ind] = sp;
					N_index[i] += 1;
				}
				else
				{
					freemem(N_index,Index);
					N_index = 0;
					Index = 0;
					Alloced = 0;
					break;
				}
			}
		}
	}

	/* find longest matching prefix */
	i = (int)(*((unsigned char *)(tar)));
	ind   = Alloced ? Index[i] : (char**)0;
	n_ind = Alloced ? N_index[i] : -1;
	n_match = 0;
	while(1)
	{
		register long m;

		if(ind)
		{
			src = n_ind > 0 ? *ind++ : endsrc;
			n_ind -= 1;
		}
		else for(; src+n_match < endsrc; ++src)
			if(*src == *tar)
				break;
		if(src+n_match >= endsrc)
			break;

		if((m = domatch(src,endsrc,tar,endtar,n_match)) > n_match)
		{
			n_match = m;
			*match = src;
			if(tar+n_match >= endtar)
				break;
		}
	}

	return n_match;
}
