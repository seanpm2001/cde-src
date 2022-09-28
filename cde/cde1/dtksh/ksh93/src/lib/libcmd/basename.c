/* $XConsortium: basename.c /main/cde1_maint/3 1995/10/14 01:32:42 montyb $ */
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
static const char id[] = "\n@(#)basename (AT&T Bell Laboratories) 03/01/94\0\n";

#include <cmdlib.h>

static void namebase __PARAM__((Sfio_t *outfile, register char *pathname, char *suffix), (outfile, pathname, suffix)) __OTORP__(Sfio_t *outfile; register char *pathname; char *suffix;){
	register char *first, *last;
	register int n=0;
	for(first=last=pathname; *last; last++);
	/* back over trailing '/' */
	if(last>first)
		while(*--last=='/' && last > first);
	if(last==first && *last=='/')
	{
		/* all '/' or "" */
		if(*first=='/')
			if(*++last=='/')	/* keep leading // */
				last++;
	}
	else
	{
		for(first=last++;first>pathname && *first!='/';first--);
		if(*first=='/')
			first++;
		/* check for trailing suffix */
		if(suffix && (n=strlen(suffix)) && n<(last-first))
		{
			if(memcmp(last-n,suffix,n)==0)
				last -=n;
		}
	}
	if(last>first)
		sfwrite(outfile,first,last-first);
	sfputc(outfile,'\n');
}

int
b_basename __PARAM__((int argc,register char *argv[]), (argc, argv)) __OTORP__(int argc;register char *argv[];){
	register int  n;

	NoP(id[0]);
	cmdinit(argv);
	while (n = optget(argv, " pathname [suffix]")) switch (n)
	{
	case ':':
		error(2, opt_info.arg);
		break;
	case '?':
		error(ERROR_usage(2), opt_info.arg);
		break;
	}
	argv += opt_info.index;
	argc -= opt_info.index;
	if(error_info.errors || argc < 1 || argc > 2)
		error(ERROR_usage(2),optusage(NiL));
	namebase(sfstdout,argv[0],argv[1]);
	return(0);
}
