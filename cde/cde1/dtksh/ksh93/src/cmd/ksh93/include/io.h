/* $XConsortium: io.h /main/cde1_maint/3 1995/10/14 00:08:00 montyb $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
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
*                    {research,attmail}!dgk                    *
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
#include	<sfio.h>

#ifndef IOBSIZE
#   define  IOBSIZE	1024
#endif /* IOBSIZE */
#define IOMAXTRY	20

/* used for output of shell errors */
#define ERRIO		2

#define IOREAD		001
#define IOWRITE		002
#define IODUP 		004
#define IOSEEK		010
#define IONOSEEK	020
#define IOTTY 		040
#define IOCLEX 		0100
#define IOCLOSE		(IOSEEK|IONOSEEK)


/*
 * The remainder of this file is only used when compiled with shell
 */

#ifdef KSHELL

#define sh_inuse(f2)	(sh.fdptrs[f2])

extern __MANGLE__ int	sh_iocheckfd __PROTO__((int));
extern __MANGLE__ void 	sh_ioinit __PROTO__((void));
extern __MANGLE__ int 	sh_iomovefd __PROTO__((int));
extern __MANGLE__ int	sh_iorenumber __PROTO__((int,int));
extern __MANGLE__ void 	sh_pclose __PROTO__((int[]));
extern __MANGLE__ void 	sh_iorestore __PROTO__((int));
extern __MANGLE__ Sfio_t 	*sh_iostream __PROTO__((int));
struct ionod;
extern __MANGLE__ int	sh_redirect __PROTO__((struct ionod*,int));
extern __MANGLE__ void 	sh_iosave __PROTO__((int,int));
extern __MANGLE__ void 	sh_iounsave __PROTO__((void));
extern __MANGLE__ int	sh_chkopen __PROTO__((const char*));
extern __MANGLE__ int	sh_ioaccess __PROTO__((int,int));

/* the following are readonly */
extern __MANGLE__ const char	e_pexists[];
extern __MANGLE__ const char	e_query[];
extern __MANGLE__ const char	e_history[];
extern __MANGLE__ const char	e_argtype[];
extern __MANGLE__ const char	e_create[];
extern __MANGLE__ const char	e_tmpcreate[];
extern __MANGLE__ const char	e_exists[];
extern __MANGLE__ const char	e_file[];
extern __MANGLE__ const char	e_formspec[];
extern __MANGLE__ const char	e_badregexp[];
extern __MANGLE__ const char	e_open[];
extern __MANGLE__ const char	e_toomany[];
extern __MANGLE__ const char	e_pipe[];
extern __MANGLE__ const char	e_flimit[];
extern __MANGLE__ const char	e_unknown[];
extern __MANGLE__ const char	e_devnull[];
extern __MANGLE__ const char	e_profile[];
extern __MANGLE__ const char	e_sysprofile[];
extern __MANGLE__ const char	e_stdprompt[];
extern __MANGLE__ const char	e_supprompt[];
extern __MANGLE__ const char	e_ambiguous[];
#endif /* KSHELL */
