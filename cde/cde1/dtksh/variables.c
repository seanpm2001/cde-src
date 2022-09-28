/* $XConsortium: variables.c /main/cde1_maint/1 1995/07/18 00:58:39 drk $ */
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

#line 1

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
#define __VOID__	__V_
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#line 3
#define mount	_AST__mount
#include	<ast.h>
#include	"FEATURE/options"
#include	"FEATURE/dynamic"
#include	<shell.h>
#include	"shtable.h"
#include	"name.h"
#include	"exextra.h"
#include	"docall.h"
#include	"msgs.h"


/*
 * This is the list of built-in shell variables and default values
 * and default attributes.
 */

const struct shtable2 shtab_variables[] =
{
	"PATH",		0,				(char*)0,
	"PS1",		0,				(char*)0,
	"PS2",		NV_NOFREE, 			"> ",
	"IFS",		NV_NOFREE, 			" \t\n",
	"PWD",		0,				(char*)0,
	"HOME",		0,				(char*)0,
	"MAIL",		0,				(char*)0,
	"REPLY",	0,				(char*)0,
	"SHELL",	NV_NOFREE,			"/bin/sh",
	"EDITOR",	0,				(char*)0,
	"MAILCHECK",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"RANDOM",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"ENV",		0,				(char*)0,
	"HISTFILE",	0,				(char*)0,
	"HISTSIZE",	0,				(char*)0,
	"HISTEDIT",	NV_NOFREE,			(char*)0,
	"HISTCMD",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"FCEDIT",	NV_NOFREE,			"/bin/ed",
	"CDPATH",	0,				(char*)0,
	"MAILPATH",	0,				(char*)0,
	"PS3",		NV_NOFREE, 			"#? ",
	"OLDPWD",	0,				(char*)0,
	"VISUAL",	0,				(char*)0,
	"COLUMNS",	0,				(char*)0,
	"LINES",	0,				(char*)0,
	"PPID",		NV_NOFREE|NV_INTEGER,		(char*)0,
	"_",		NV_EXPORT,			(char*)0,
	"TMOUT",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"SECONDS",	NV_NOFREE|NV_INTEGER|NV_DOUBLE,	(char*)0,
	"LINENO",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"OPTARG",	0,				(char*)0,
	"OPTIND",	NV_NOFREE|NV_INTEGER,		(char*)0,
	"PS4",		0,				(char*)0,
	"FPATH",	0,				(char*)0,
	"LANG",		0,				(char*)0,
	"LC_CTYPE",	0,				(char*)0,
	"FIGNORE",	0,				(char*)0,
	".sh",		0,				(char*)0,
	".sh.edchar",	0,				(char*)0,
	".sh.edcol",	0,				(char*)0,
	".sh.edtext",	0,				(char*)0,
	".sh.edmode",	0,				(char*)0,
	".sh.name",	0,				(char*)0,
	".sh.subscript",0,				(char*)0,
	".sh.value",	0,				(char*)0,
	".sh.version",	NV_NOFREE,			(char*)(&e_version[5]),
#ifdef SHOPT_FS_3D
	"VPATH",	0,				(char*)0,
#endif /* SHOPT_FS_3D */
#ifdef SHOPT_VPIX
	"DOSPATH",	0,				(char*)0,
	"VPIXDIR",	0,				(char*)0,
#endif	/* SHOPT_VPIX */
#ifdef MULTIBYTE
	"CSWIDTH",	0,				(char*)0,
#endif /* MULTIBYTE */
#ifdef apollo
	"SYSTYPE",	0,				(char*)0,
#endif /* apollo */
EXKSH_EXTRA_VAR
	"",	0,					(char*)0
};

