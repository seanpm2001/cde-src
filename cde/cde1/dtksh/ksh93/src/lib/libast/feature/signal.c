/* $XConsortium: signal.c /main/cde1_maint/1 1995/07/17 23:48:17 drk $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF        *
*                    AT&T BELL LABORATORIES                    *
*         AND IS NOT TO BE DISCLOSED OR USED EXCEPT IN         *
*            ACCORDANCE WITH APPLICABLE AGREEMENTS             *
*                                                              *
*          Copyright (c) 1994 AT&T Bell Laboratories           *
*              Unpublished & Not for Publication               *
*                     All Rights Reserved                      *
*                                                              *
*       The copyright notice above does not evidence any       *
*      actual or intended publication of such source code      *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                   advsoft@research.att.com                   *
*                 Randy Hackbarth 908-582-5245                 *
*                  Dave Belanger 908-582-7427                  *
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
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#endif

#line 9
#include <signal.h>

struct _m_
{
	char*		text;
	char*		name;
	int		value;
};

#define elementsof(x)	(sizeof(x)/sizeof(x[0]))

static struct _m_ map[] =
{
#ifdef SIGABRT
"Abort",			"ABRT",		SIGABRT,
#endif
#ifdef SIGALRM
"Alarm call",			"ALRM",		SIGALRM,
#endif
#ifdef SIGAPOLLO
"Apollo",			"APOLLO",	SIGAPOLLO,
#endif
#ifdef SIGBUS
"Bus error",			"BUS",		SIGBUS,
#endif
#ifdef SIGCHLD
"Child status change",		"CHLD",		SIGCHLD,
#endif
#ifdef SIGCLD
"Death of child", 		"CLD",		SIGCLD,
#endif
#ifdef SIGCONT
"Stopped process continued",	"CONT",		SIGCONT,
#endif
#ifdef SIGDEBUG
"Debug trap",			"DEBUG",	SIGDEBUG,
#endif
#ifdef SIGEMT
"EMT trap",			"EMT",		SIGEMT,
#endif
#ifdef SIGERR
"ERR trap",			"ERR",		SIGERR,
#endif
#ifdef SIGEXIT
"Exit",				"EXIT",		SIGEXIT,
#endif
#ifdef SIGFPE
"Floating exception",		"FPE",		SIGFPE,
#endif
#ifdef SIGHUP
"Hangup",			"HUP",		SIGHUP,
#endif
#ifdef SIGILL
"Illegal instruction",		"ILL",		SIGILL,
#endif
#ifdef SIGINT
"Interrupt",			"INT",		SIGINT,
#endif
#ifdef SIGIO
"IO possible",			"IO",		SIGIO,
#endif
#ifdef SIGIOT
"IOT trap",			"IOT",		SIGIOT,
#endif
#ifdef SIGKILL
"Killed",			"KILL",		SIGKILL,
#endif
#ifdef SIGLAB
"LAB trap",			"LAB",		SIGLAB,
#endif
#ifdef SIGKILL
"Killed",			"KILL",		SIGKILL,
#endif
#ifdef SIGLOST
"Resources lost",		"LOST",		SIGLOST,
#endif
#ifdef SIGPHONE
"Phone status change",		"PHONE",	SIGPHONE,
#endif
#ifdef SIGPIPE
"Broken Pipe",			"PIPE",		SIGPIPE,
#endif
#ifdef SIGPOLL
"Poll event",			"POLL",		SIGPOLL,
#endif
#ifdef SIGPROF
"Profiling time alarm",		"PROF",		SIGPROF,
#endif
#ifdef SIGPWR
"Power fail",			"PWR",		SIGPWR,
#endif
#ifdef SIGQUIT
"Quit",				"QUIT",		SIGQUIT,
#endif
#ifdef SIGSEGV
"Memory fault",			"SEGV",		SIGSEGV,
#endif
#ifdef SIGSSTOP
"Sendable stop",		"SSTOP",	SIGSSTOP,
#endif
#ifdef gould
"Stack overflow",		"STKOV",	28,
#endif
#ifdef SIGSTOP
"Stopped (signal)",		"STOP",		SIGSTOP,
#endif
#ifdef SIGSYS
"Bad system call", 		"SYS",		SIGSYS,
#endif
#ifdef SIGTERM
"Terminated",			"TERM",		SIGTERM,
#endif
#ifdef SIGTINT
"Interrupt (terminal)",		"TINT",		SIGTINT,
#endif
#ifdef SIGTRAP
"Trace/BPT trap",		"TRAP",		SIGTRAP,
#endif
#ifdef SIGTSTP
"Stopped",			"TSTP",		SIGTSTP,
#endif
#ifdef SIGTTIN
"Stopped (tty input)",		"TTIN",		SIGTTIN,
#endif
#ifdef SIGTTOU
"Stopped (tty output)",		"TTOU",		SIGTTOU,
#endif
#ifdef SIGURG
"Urgent IO",			"URG",		SIGURG,
#endif
#ifdef SIGUSR1
"User signal 1",		"USR1",		SIGUSR1,
#endif
#ifdef SIGUSR2
"User signal 2",		"USR2",		SIGUSR2,
#endif
#ifdef SIGVTALRM
"Virtual time alarm",		"VTALRM",	SIGVTALRM,
#endif
#ifdef SIGWINCH
"Window change", 		"WINCH",	SIGWINCH,
#endif
#ifdef SIGWIND
"Window change",		"WIND",		SIGWIND,
#endif
#ifdef SIGWINDOW
"Window change",		"WINDOW",	SIGWINDOW,
#endif
#ifdef SIGXCPU
"CPU time limit",		"XCPU",		SIGXCPU,
#endif
#ifdef SIGXFSZ
"File size limit",		"XFSZ",		SIGXFSZ,
#endif
0
};

static int		index[64];

extern __MANGLE__ int		printf __PROTO__((const char*, ...));

main()
{
	register int	i;
	register int	j;
	register int	k;

	k = 0;
	for (i = 0; map[i].name; i++)
		if ((j = map[i].value) > 0 && j < elementsof(index))
		{
			if (j > k) k = j;
			index[j] = i;
		}
	printf("#define SIG_MAX	%d\n", k);
	printf("\n");
	printf("char*	sig_name[] =\n");
	printf("{\n");
	for (i = 0; i <= k; i++)
		if (j = index[i]) printf("	\"%s\",\n", map[j].name);
		else printf("	\"%d\",\n", i);
	printf("	0\n");
	printf("};\n");
	printf("\n");
	printf("char*	sig_text[] =\n");
	printf("{\n");
	for (i = 0; i <= k; i++)
		if (j = index[i]) printf("	\"%s\",\n", map[j].text);
		else printf("	\"Signal %d\",\n", i);
	printf("	0\n");
	printf("};\n");
	return(0);
}
