/* $XConsortium: national.h /main/cde1_maint/1 1995/07/17 23:54:12 drk $ */
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

#line 1

/* @(#)national.h	1.5 */

/*
 *  national.h -  definitions for international character sets
 *
 *   David Korn
 *   AT&T Bell Laboratories
 *   Room 5D-112
 *   Murray Hill, N. J. 07974
 *   Tel. x7975
 *
 */

/*
 * This data must be defined for each country in defs.c
 */

#ifndef HIGHBIT
#   define HIGHBIT		(1<<(CHAR_BIT-1))
#endif /* HIGHBIT */

#ifndef ESS_MAXCHAR	/* allow multiple includes */

/*
 *  This section may change from country to country
 */

#define ESS_MAXCHAR	2	/* Maximum number of non-escape bytes
				   for any and all character sets */
#define	CCS1_IN_SIZE	2
#define	CCS1_OUT_SIZE	2
#define	CCS2_IN_SIZE	1
#define	CCS2_OUT_SIZE	1
#define	CCS3_IN_SIZE	2
#define	CCS3_OUT_SIZE	2

/*
 * This part is generic
 */

#define MARKER		0x100	/* Must be invalid character */
#define ESS2		0x8e	/* Escape to char set 2 */
#define ESS3		0x8f	/* Escape to char set 3 */
#define ESS_SETMASK	(3<<(7*ESS_MAXCHAR))	/* character set bits */

#define	echarset(c)	((c)==ESS3?3:((c)==ESS2)?2:((c)>>7)&1)
#define icharset(i)	((i)>>(7*ESS_MAXCHAR)&3)

#define in_csize(s)	int_charsize[s]
#define out_csize(s)	int_charsize[s+4]

extern char int_charsize[8];

#endif /* ESS_MAXCHAR */
