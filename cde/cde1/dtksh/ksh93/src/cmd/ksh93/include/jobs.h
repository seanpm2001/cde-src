/* $XConsortium: jobs.h /main/cde1_maint/3 1995/10/14 00:08:10 montyb $ */
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
                  
#ifndef JOB_NFLAG
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

/*
 *	Interface to job control for shell
 *	written by David Korn
 *
 */

#define JOBTTY	2

#include	<ast.h>
#include	<sfio.h>
#ifndef SIGINT
#   include	<signal.h>
#endif /* !SIGINT */
#include	"FEATURE/options"

#undef JOBS
#if defined(SIGCLD) && !defined(SIGCHLD)
#   define SIGCHLD	SIGCLD
#endif
#ifdef SIGCHLD
#   define JOBS	1
#   include	"terminal.h"
#   ifdef FIOLOOKLD
	/* Ninth edition */
	extern __MANGLE__ int tty_ld, ntty_ld;
#	define OTTYDISC	tty_ld
#	define NTTYDISC	ntty_ld
#   endif	/* FIOLOOKLD */
#else
#   undef SIGTSTP
#   undef SH_MONITOR
#   define SH_MONITOR	0
#   define job_set(x)
#   define job_reset(x)
#endif

struct process
{
	struct process *p_nxtjob;	/* next job structure */
	struct process *p_nxtproc;	/* next process in current job */
	pid_t		p_pid;		/* process id */
	pid_t		p_pgrp;		/* process group */
	pid_t		p_fgrp;		/* process group when stopped */
	short		p_job;		/* job number of process */
	unsigned short	p_exit;		/* exit value or signal number */
	unsigned char	p_flag;		/* flags - see below */
	int		p_env;		/* subshell environment number */
#ifdef JOBS
	off_t		p_name;		/* history file offset for command */
	struct termios	p_stty;		/* terminal state for job */
#endif /* JOBS */
};

struct jobs
{
	struct process	*pwlist;	/* head of process list */
	pid_t		curpgid;	/* current process gid id */
	pid_t		parent;		/* set by fork() */
	pid_t		mypid;		/* process id of shell */
	pid_t		mypgid;		/* process group id of shell */
	pid_t		mytgid;		/* terminal group id of shell */
	int		numpost;	/* number of posted jobs */
	short		fd;		/* tty descriptor number */
#ifdef JOBS
	int		suspend;	/* suspend character */
	int		linedisc;	/* line dicipline */
#endif /* JOBS */
	char		in_critical;	/* set when in critical region */
	char		jobcontrol;	/* turned on for real job control */
	char		waitsafe;	/* wait will not block */
	char		waitall;	/* wait for all jobs in pipe */
	char		toclear;	/* job table needs clearing */
	unsigned char	*freejobs;	/* free jobs numbers */
};

/* flags for joblist */
#define JOB_LFLAG	1
#define JOB_NFLAG	2
#define JOB_PFLAG	4
#define JOB_NLFLAG	8

extern __MANGLE__ struct jobs job;

#ifdef JOBS
extern __MANGLE__ const char	e_jobusage[];
extern __MANGLE__ const char	e_kill[];
extern __MANGLE__ const char	e_done[];
extern __MANGLE__ const char	e_running[];
extern __MANGLE__ const char	e_coredump[];
extern __MANGLE__ const char	e_killcolon[];
extern __MANGLE__ const char	e_no_proc[];
extern __MANGLE__ const char	e_no_job[];
extern __MANGLE__ const char	e_jobsrunning[];
extern __MANGLE__ const char	e_nlspace[];
extern __MANGLE__ const char	e_access[];
extern __MANGLE__ const char	e_terminate[];
extern __MANGLE__ const char	e_no_jctl[];
#ifdef SIGTSTP
   extern __MANGLE__ const char	e_no_start[];
#endif /* SIGTSTP */
#ifdef NTTYDISC
   extern __MANGLE__ const char	e_newtty[];
   extern __MANGLE__ const char	e_oldtty[];
#endif /* NTTYDISC */
#endif	/* JOBS */

/*
 * The following are defined in jobs.c
 */

extern __MANGLE__ void	job_clear __PROTO__((void));
extern __MANGLE__ void	job_bwait __PROTO__((char**));
extern __MANGLE__ int	job_walk __PROTO__((Sfio_t*,int(*)(struct process*,int),int,char*[]));
extern __MANGLE__ int	job_kill __PROTO__((struct process*,int));
extern __MANGLE__ void	job_wait __PROTO__((pid_t));
extern __MANGLE__ int	job_post __PROTO__((pid_t,pid_t));
extern __MANGLE__ int	job_chksave __PROTO__((pid_t));
#ifdef JOBS
	extern __MANGLE__ void	job_init __PROTO__((int));
	extern __MANGLE__ int	job_close __PROTO__((void));
	extern __MANGLE__ int	job_list __PROTO__((struct process*,int));
	extern __MANGLE__ int	job_terminate __PROTO__((struct process*,int));
	extern __MANGLE__ int	job_switch __PROTO__((struct process*,int));
#else
#	define job_init(flag)
#	define job_close()	(0)
#endif	/* JOBS */


#endif /* !JOB_NFLAG */
