/* $XConsortium: aliases.c /main/cde1_maint/1 1995/07/17 23:06:00 drk $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*          Copyright (c) 1993 AT&T Bell Laboratories           *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Advanced Software Technology Department            *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                    {ulysses,attmail}!dgk                     *
*                     dgk@ulysses.att.com                      *
*                   David Korn 908-582-7975                    *
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

#include	<ast.h>
#include	<signal.h>
#include	"FEATURE/options"
#include	"FEATURE/dynamic"
#include	"shtable.h"
#include	"name.h"

#include <X11/X.h>
#include <X11/Intrinsic.h>
#include <X11/IntrinsicP.h>
#define NO_AST
#include "dtksh.h"
#undef NO_AST
#include "dtextra.h"
#include "xmextra.h"
#include "msgs.h"

/*
 * This is the table of built-in aliases.  These should be exported.
 */

const struct shtable2 shtab_aliases[] =
{
#ifdef SHOPT_FS_3D
	"2d",		NV_NOFREE|NV_EXPORT,	"set -f;_2d",
#endif /* SHOPT_FS_3D */
	"autoload",	NV_NOFREE|NV_EXPORT,	"typeset -fu",
	"command",	NV_NOFREE|NV_EXPORT,	"command ",
	"fc",		NV_NOFREE|NV_EXPORT,	"hist",
	"float",	NV_NOFREE|NV_EXPORT,	"typeset -E",
	"functions",	NV_NOFREE|NV_EXPORT,	"typeset -f",
	"hash",		NV_NOFREE|NV_EXPORT,	"alias -t --",
	"history",	NV_NOFREE|NV_EXPORT,	"hist -l",
	"integer",	NV_NOFREE|NV_EXPORT,	"typeset -i",
	"nameref",	NV_NOFREE|NV_EXPORT,	"typeset -n",
	"nohup",	NV_NOFREE|NV_EXPORT,	"nohup ",
	"r",		NV_NOFREE|NV_EXPORT,	"hist -s",
	"redirect",	NV_NOFREE|NV_EXPORT,	"command exec",
	"times",	NV_NOFREE|NV_EXPORT,	"{ { time;} 2>&1;}",
	"type",		NV_NOFREE|NV_EXPORT,	"whence -v",
#ifdef SIGTSTP
	"stop",		NV_NOFREE|NV_EXPORT,	"kill -s STOP",
	"suspend", 	NV_NOFREE|NV_EXPORT,	"kill -s STOP $$",
#endif /*SIGTSTP */

DTK_EXTRA_ALIAS

	"",		0,			(char*)0
};
