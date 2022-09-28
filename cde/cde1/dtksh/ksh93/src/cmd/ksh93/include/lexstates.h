/* $XConsortium: lexstates.h /main/cde1_maint/3 1995/10/14 00:08:19 montyb $ */
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
                  
#ifndef S_BREAK
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

#define S_BREAK	1	/* end of token */
#define S_EOF	2	/* end of buffer */
#define S_NL	3	/* new-line when not a token */
#define S_RES	4	/* first character of reserved word */
#define S_NAME	5	/* other identifier characters */
#define S_REG	6	/* non-special characters */
#define S_TILDE	7	/* first char is tilde */
#define S_PUSH	8
#define S_POP	9
#define S_BRACT	10
#define S_LIT	11	/* literal quote character */
#define S_NLTOK	12	/* new-line token */
#define S_OP	13	/* operator character */
#define S_PAT	14	/* pattern characters * and ? */
#define S_EPAT	15	/* pattern char when followed by ( */
#define S_EQ	16	/* assignment character */
#define S_COM	17	/* comment character */
#define S_MOD1	18	/* ${...} modifier character - old quoting */
#define S_MOD2	19	/* ${...} modifier character - new quoting */
#define S_ERR	20	/* invalid character in ${...} */
#define S_SPC1	21	/* special prefix characters after $ */
#define S_SPC2	22	/* special characters after $ */
#define S_DIG	23	/* digit character after $*/
#define S_ALP	24	/* alpahbetic character after $ */
#define S_LBRA	25	/* left brace after $ */
#define S_RBRA	26	/* right brace after $ */
#define S_PAR	27	/* set for $( */
#define S_ENDCH	28	/* macro expansion terminator */
#define S_SLASH	29	/* / character terminates ~ expansion  */
#define S_COLON	30	/* for character : */
#define S_LABEL	31	/* for goto label */
#define S_EDOL	32	/* ends $identifier */
#define S_BRACE	33	/* left brace */
#define S_DOT	34	/* . char */
#define S_META	35	/* | & ; < > inside ${...} reserved for future use */
#define S_SPACE	S_BREAK	/* IFS space characters */
#define S_DELIM	S_RES	/* IFS delimter characters */
#define S_MBYTE S_NAME	/* IFS first byte of multi-byte char */
/* The following must be the highest numbered states */
#define S_QUOTE	36	/* double quote character */
#define S_GRAVE	37	/* old comsub character */
#define S_ESC	38	/* escape character */
#define S_DOL	39	/* $ subsitution character */
#define S_ESC2	40	/* escape character inside '...' */

/* These are the lexical state table names */
#define ST_BEGIN	0
#define ST_NAME		1
#define ST_NORM		2
#define ST_LIT		3
#define ST_QUOTE	4
#define ST_NESTED	5
#define ST_DOL		6
#define ST_BRACE	7
#define ST_DOLNAME	8
#define ST_MACRO	9
#define ST_QNEST	10
#define ST_NONE		11

#define isaname(c)	(sh_lexstates[ST_NAME][c]==0)
#define isadigit(c)	(sh_lexstates[ST_DOL][c]==S_DIG)
#define isaletter(c)	(sh_lexstates[ST_DOL][c]==S_ALP && (c)!='.')
#define isastchar(c)	((c)=='@' || (c)=='*')
#define isexp(c)	(sh_lexstates[ST_MACRO][c]==S_PAT||(c)=='$'||(c)=='`')
#define ismeta(c)	(sh_lexstates[ST_NAME][c]==S_BREAK)

extern __MANGLE__ char *sh_lexstates[ST_NONE];
extern __MANGLE__ const char *sh_lexrstates[ST_NONE];
extern __MANGLE__ const char e_lexversion[];
extern __MANGLE__ const char e_lexspace[];
extern __MANGLE__ const char e_lexslash[];
extern __MANGLE__ const char e_lexlabignore[];
extern __MANGLE__ const char e_lexlabunknown[];
extern __MANGLE__ const char e_lexsyntax1[];
extern __MANGLE__ const char e_lexsyntax2[];
extern __MANGLE__ const char e_lexsyntax3[];
extern __MANGLE__ const char e_lexobsolete1[];
extern __MANGLE__ const char e_lexobsolete2[];
extern __MANGLE__ const char e_lexobsolete3[];
extern __MANGLE__ const char e_lexobsolete4[];
extern __MANGLE__ const char e_lexobsolete5[];
extern __MANGLE__ const char e_lexobsolete6[];
extern __MANGLE__ const char e_lexusebrace[];
extern __MANGLE__ const char e_lexusequote[];
extern __MANGLE__ const char e_lexescape[];
extern __MANGLE__ const char e_lexquote[];
extern __MANGLE__ const char e_lexnested[];
extern __MANGLE__ const char e_lexbadchar[];
extern __MANGLE__ const char e_lexlongquote[];
extern __MANGLE__ const char e_lexfuture[];
extern __MANGLE__ const char e_lexzerobyte[];
#endif
