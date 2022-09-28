/* $XConsortium: cat.c /main/cde1_maint/4 1995/10/16 19:42:09 montyb $ */
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
static const char id[] = "\n@(#)cat (AT&T Bell Laboratories) 05/09/95\0\n";

#include <cmdlib.h>

#define RUBOUT	0177

/* control flags */
#define B_FLAG		(1<<0)
#define E_FLAG		(1<<1)
#define F_FLAG		(1<<2)
#define N_FLAG		(1<<3)
#define S_FLAG		(1<<4)
#define T_FLAG		(1<<5)
#define U_FLAG		(1<<6)
#define V_FLAG		(1<<7)

/* character types */
#define T_ENDBUF	1
#define T_CONTROL	2
#define T_NEWLINE	3
#define T_EIGHTBIT	4
#define T_CNTL8BIT	5

#define printof(c)	((c)^0100)

static char	states[UCHAR_MAX+1];

/*
 * called for any special output processing
 */

static int
vcat __PARAM__((Sfio_t *fdin, Sfio_t *fdout, int flags), (fdin, fdout, flags)) __OTORP__(Sfio_t *fdin; Sfio_t *fdout; int flags;){
	register unsigned char*	cp;
	register unsigned char*	cpold;
	register int		n;
	register int		line = 1;
	register unsigned char*	endbuff;
	unsigned char*		inbuff;
	int			printdefer = (flags&(B_FLAG|N_FLAG));
	int			lastchar;

	static unsigned char	meta[4] = "M-";

	for (;;)
	{
		/* read in a buffer full */
		if (!(inbuff = (unsigned char*)sfreserve(fdin, SF_UNBOUND, 0)))
			return(sfslen() ? -1 : 0);
		if ((n = sfslen()) <= 0)
			return(n);
		cp = inbuff;
		lastchar = *(endbuff = cp + --n);
		*endbuff = 0;
		if (printdefer)
		{
			if (states[*cp]!=T_NEWLINE || !(flags&B_FLAG))
				sfprintf(fdout,"%6d\t",line);
			printdefer = 0;
		}
		while (endbuff)
		{
			cpold = cp;
			/* skip over ASCII characters */
			while ((n = states[*cp++]) == 0);
			if (n==T_ENDBUF)
			{
				if (cp>endbuff)
				{
					if (!(n = states[lastchar]))
					{
						*endbuff = lastchar;
						cp++;
					}
					else
					{
						if (--cp > cpold)
							sfwrite(fdout,(char*)cpold,cp-cpold);
						if (endbuff==inbuff)
							*++endbuff = 0;
						cp = cpold = endbuff;
						cp[-1] = lastchar;
						if (n==T_ENDBUF)
							n = T_CONTROL;
						
					}
					endbuff = 0;
				}
				else n = T_CONTROL;
			}
			if (--cp>cpold)
				sfwrite(fdout,(char*)cpold,cp-cpold);
			switch(n)
			{
				case T_CNTL8BIT:
					meta[2] = '^';
					do
					{
						n = (*cp++)&~0200;
						meta[3] = printof(n);
						sfwrite(fdout,(char*)meta,4);
					}
					while ((n=states[*cp])==T_CNTL8BIT);
					break;
				case T_EIGHTBIT:
					do
					{
						meta[2] = (*cp++)&~0200;
						sfwrite(fdout,(char*)meta,3);
					}
					while ((n=states[*cp])==T_EIGHTBIT);
					break;
				case T_CONTROL:
					do
					{
						n = *cp++;
						sfputc(fdout,'^');
						sfputc(fdout,printof(n));
					}
					while ((n=states[*cp])==T_CONTROL);
					break;
				case T_NEWLINE:
					if (flags&S_FLAG)
					{
						while (states[*++cp]==T_NEWLINE)
							line++;
						cp--;
					}
					do
					{
						cp++;
						if (flags&E_FLAG)
							sfputc(fdout,'$');
						sfputc(fdout,'\n');
						if (!(flags&(N_FLAG|B_FLAG)))
							continue;
						line++;
						if (cp < endbuff)
							sfprintf(fdout,"%6d\t",line);
						else printdefer = 1;
					}
					while (states[*cp]==T_NEWLINE);
					break;
			}
		}
	}
}

int
b_cat __PARAM__((int argc, char** argv), (argc, argv)) __OTORP__(int argc; char** argv;){
	register int		n;
	register int		flags = 0;
	register char*		cp;
	register Sfio_t*	fp;
	int			att;

	NoP(id[0]);
	NoP(argc);
	cmdinit(argv);
	att = !strcmp(astconf("UNIVERSE", NiL, NiL), "att");
	while (n = optget(argv, "benstuv [file...] ")) switch (n)
	{
	case 'b':
		flags |= B_FLAG;
		break;
	case 'e':
		flags |= E_FLAG;
		break;
	case 'n':
		flags |= N_FLAG;
		break;
	case 's':
		flags |= att ? F_FLAG : S_FLAG;
		break;
	case 't':
		flags |= T_FLAG;
		break;
	case 'u':
		flags |= U_FLAG;
		break;
	case 'v':
		flags |= V_FLAG;
		break;
	case ':':
		error(2, opt_info.arg);
		break;
	case '?':
		error(ERROR_usage(2), opt_info.arg);
		break;
	}
	argv += opt_info.index;
	if (error_info.errors)
		error(ERROR_usage(2), optusage(NiL));
	if (flags&V_FLAG)
	{
		memset(states, T_CONTROL, ' ');
		states[RUBOUT] = T_CONTROL;
		memset(states+0200, T_EIGHTBIT, 0200);
		memset(states+0200, T_CNTL8BIT,  ' ');
		states[RUBOUT|0200] = T_CNTL8BIT;
		states['\n'] = 0;
	}
	states[0] = T_ENDBUF;
	if (att)
	{
		if (flags&V_FLAG)
		{
			states['\n'|0200] = T_EIGHTBIT;
			if (!(flags&T_FLAG))
			{
				states['\t'] = states['\f'] = 0;
				states['\t'|0200] = states['\f'|0200] = T_EIGHTBIT;
			}
		}
	}
	else if (flags)
	{
		flags |= V_FLAG;
		if (!(flags&T_FLAG))
			states['\t'] = 0;
	}
	if (flags&B_FLAG)
	{
		flags &= ~(N_FLAG|E_FLAG);
		flags |= (V_FLAG|S_FLAG);
	}
	if (flags&N_FLAG)
	{
		flags &= ~(B_FLAG|S_FLAG|E_FLAG);
		flags |= V_FLAG;
	}
	if (flags&V_FLAG)
		states['\n'] = T_NEWLINE;
	if (cp = *argv)
		argv++;
	do
	{
		if (!cp || streq(cp,"-"))
			fp = sfstdin;
		else if (!(fp = sfopen(NiL, cp, "r")))
		{
			if (!(flags&F_FLAG))
				error(ERROR_system(0), "%s: cannot open", cp);
			error_info.errors = 1;
			continue;
		}
		if (flags&U_FLAG)
			sfsetbuf(fp, (__V_*)fp, -1);
		if (flags&V_FLAG) n = vcat(fp, sfstdout, flags);
		else if ((n = sfmove(fp, sfstdout, SF_UNBOUND, -1)) >= 0 && (!sfeof(fp) || sferror(sfstdout)))
			n = -1;
		if (fp != sfstdin)
			sfclose(fp);
		if (n < 0)
		{
			if (cp) error(ERROR_system(0), "%s: cannot copy", cp);
			else error(ERROR_system(0), "cannot copy");
			if (sferror(sfstdout)) break;
		}
	} while (cp = *argv++);
	return(error_info.errors);
}
