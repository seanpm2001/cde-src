: generate conf info
#
# @(#)conf.sh (AT&T Bell Laboratories) 06/22/95
#
# this script generates these files from the table file in the first arg
# the remaining args are the C compiler name and flags
#
#	conflib.h	common generator definitions
#	conflim.h	limits.h generator code
#	confmap.c	internal index to external op map data
#	confmap.h	internal index to external op map definitions
#	confstr.c	confstr() implementation
#	conftab.c	readonly string table data
#	conftab.h	readonly string table definitions
#	confuni.h	unistd.h generator code
#	pathconf.c	pathconf() and fpathconf() implementation
#	sysconf.c	sysconf() implementation
#
# you may think it should be simpler
# but in the process you shall be confused
#

case $RANDOM in
$RANDOM)	shell=bsh ;;
*)		shell=ksh ;;
esac
test -f $1 || { echo "$0: $1: cannot read" >&2; exit 1; }
exec < $1
generated="/* : : generated by $0 from $1 : : */"
shift
case $# in
0)	cc=cc ;;
*)	cc=$* ;;
esac

ifs=$IFS
sym=[A-Za-z_]*
tmp=CF_$$

rm -f $tmp.*
trap "rm -f $tmp.*" 0 1 2

cat > $tmp.u <<!
	/*
	 * some implementations (could it beee aix) think empty
	 * definitions constitute symbolic constants
	 */

	{
	long	num;
	char*	str;
	int	hit;
!

# walk through the table

case $shell in
ksh)	integer len limit_max name_max ;;
esac
limit_max=0
name_max=1
line=
next=
standards=
while	:
do	prev=$line
	line=$next
	IFS=""
	read next
	eof=$?
	IFS=$ifs
	case $line in
	""|\#*)	continue ;;
	"	"*)
		set x $line
		shift
		echo "$*" >> $tmp.h
		;;
	*)	set x $line
		shift; name=$1
		conf_name=$name
		shift; index=$1
		conf_index=$index
		shift; standard=$1
		case " $standards " in
		*" $standard "*)
			;;
		*)	standards="$standards $standard"
			;;
		esac
		conf_standard=CONF_${standard}
		shift; call=$1
		case $call in
		CS)	conf_call=CONF_confstr
			;;
		PC)	conf_call=CONF_pathconf
			;;
		SC)	conf_call=CONF_sysconf
			;;
		XX)	conf_call=CONF_nop
			;;
		*)	echo "$0: $name: $call: invalid call" >&2
			exit 1
			;;
		esac
		shift; section=$1
		conf_section=$section
		shift; flags=$1
		conf_flags=0
		case $flags in
		*[ABCDEGHIJKOPQRTVWYZa-z1-9_]*)
			echo "$0: $name: $flags: invalid flag(s)" >&2
			exit 1
			;;
		esac
		case $flags in
		*F*)	conf_flags="${conf_flags}|CONF_FEATURE" ;;
		esac
		case $flags in
		*L*)	conf_flags="${conf_flags}|CONF_LIMIT" ;;
		esac
		case $flags in
		*M*)	conf_flags="${conf_flags}|CONF_MINMAX" ;;
		esac
		case $flags in
		*N*)	conf_flags="${conf_flags}|CONF_NOSECTION" ;;
		esac
		case $flags in
		*S*)	conf_flags="${conf_flags}|CONF_STANDARD" ;;
		esac
		case $flags in
		*U*)	conf_flags="${conf_flags}|CONF_UNDERSCORE" ;;
		esac
		case $shell in
		ksh)	conf_flags=${conf_flags#0?} ;;
		esac
		shift; values=$*
		set x $prev
		set x $2 $next
		case $conf_name in
		$2|$3)	conf_flags="${conf_flags}|CONF_PREFIXED" ;;
		esac
		case $flags in
		*L*)	conf_value=$conf_name ;;
		*)	conf_value=0 ;;
		esac
		local=LOCAL
		case $section in
		[01])	;;
		*)	case $flags in
			*N*)	;;
			*)	name=${section}_${name} ;;
			esac
			local=${local}${section}
			standard=${standard}${section}
			;;
		esac
		case $call in
		XX)	conf_op=0
			;;
		*)	case $flags in
			*S*)	conf_op=_${call}_${standard}_${name} ;;
			*)	conf_op=_${call}_${name} ;;
			esac
			cat >> $tmp.u <<!
	printf("#undef	${conf_op}\n");
	printf("#define ${conf_op}	(-${index})\n");
!
			cat > $tmp.c <<!
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE	1
#endif
#include <sys/types.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
main()
{
#ifndef ${conf_op}
	printf("#define ${conf_op}	%d\n", ${conf_op});
#endif
	return 0;
}
!
			if	$cc -o $tmp.exe $tmp.c >/dev/null 2>&1
			then	$tmp.exe >> $tmp.e 2>/dev/null
			fi
			echo ${index} ${conf_op} >> $tmp.m
			;;
		esac
		case $standard:$flags in
		C:*)	;;
		*:*L*)	case $next in
			"	"*)
				values="_${local}_${conf_name} $values"
				;;
			esac
			{
			echo "	hit = 0;"
			case $call in
			PC)	cat <<!
#if _lib_pathconf && defined(${conf_op})
	if ((num = pathconf("/", ${conf_op})) != -1)
		hit = 1;
	else
#endif
!
				;;
			SC)	cat <<!
#if _lib_sysconf && defined(${conf_op})
	if ((num = sysconf(${conf_op})) != -1)
		hit = 1;
	else
#endif
!
				;;
			esac
			echo "	{"
			endif=
			default=
			for i in $conf_name $values
			do	case $i in
				_${standard}_${conf_name})
					;;
				$sym)	cat <<!
#ifdef	${i}
	if (!hit && ${i} > 0)
	{
		hit = 1;
		num = ${i};
	}
#else
!
					endif="#endif
$endif"
					case $conf_op:$flags:$i in
					0*|*X*:*)
						;;
					*:*:$conf_name)
						echo "#ifndef	${conf_op}"
						endif="#endif
$endif"
						;;
					esac
					;;
				*)	case $default in
					"")	default=${i} ;;
					esac
					;;
				esac
			done
			case $default in
			?*)	cat <<!
	if (!hit)
	{
		hit = 1;
		num = ${default};
	}
!
				;;
			esac
			echo "${endif}	}"
			cat <<!
	if (hit) printf("#define ${conf_name}		%ld\n", num);
	else num = -1;
	lim[${limit_max}] = num;
#ifndef ${conf_name}
#define ${conf_name}	lim[${limit_max}]
#endif
!
			} >> $tmp.l
			case $shell in
			ksh)	((limit_max=limit_max+1)) ;;
			*)	limit_max=`expr $limit_max + 1` ;;
			esac
			;;
		esac
		case $standard:$flags in
		C:*)	;;
		*:*[FM]*)
			case $flags in
			*M*)	header=l ;;
			*)	header=u ;;
			esac
			minmax=
			for i in $values
			do	case $i in
				$sym)	;;
				*)	minmax=${i} ;;
				esac
			done
			macro=_${standard}_${conf_name}
			conf_value=${macro}
			values="$values ${macro}"
			case $minmax in
			"")	default=1 ;;
			*)	default=$minmax ;;
			esac
			{
			case $call in
			CS)	type="char*" var=str fmt='\"%s\"' ;;
			*)	type=long var=num fmt='%ld' ;;
			esac
			cat <<!
#if defined(${macro})
	{
		static ${type}	x[2] = { ${default}, ${macro} };
		if ((sizeof(x)/sizeof(x[0])) == 1)
		{
			printf("#undef	${macro}\n");
			${var} = x[0];
		}
		else ${var} = x[1];
	}
!
			case $minmax in
			?*)	cat <<!
#else
	${var} = ${minmax};
#endif
!
				;;
			esac
			cat <<!
	printf("#define ${macro}	${fmt}\n", ${var});
!
			case $minmax in
			"")	cat <<!
#endif
!
				;;
			esac
			} >> $tmp.$header
			;;
		esac
		case $call in
		CS)	conf_value=0 ;;
		esac
		echo $conf_name $conf_section $conf_standard $conf_value $conf_flags $conf_call $conf_op >> $tmp.G
		case $shell in
		ksh)	len=${#conf_name}
			if	((len>=name_max))
			then	((name_max=len+1))
			fi
			;;
		*)	if	expr length ${conf_name} \>= ${name_max} >/dev/null
			then	name_max=`expr length ${conf_name} + 1`
			fi
			;;
		esac
		case $conf_op in
		0)	;;
		*)	{
			echo "#ifdef	${conf_op}
	case ${conf_op}:"
			endif="#endif"
			minmax=
			for i in $name $values
			do	case $i in
				$sym)	echo "#ifdef	$i
		return($i-0);
#else"
					endif="$endif
#endif"
					;;
				*)	case $flags in
					*M*)	minmax=$i ;;
					esac
					;;
				esac
			done
			case $minmax in
			?*)	echo "		return($minmax-0);" ;;
			*)	echo "		break;" ;;
			esac
			echo "$endif"
			} >> $tmp.c$call
			;;
		esac
		;;
	esac
	case $eof in
	0)	;;
	*)	break ;;
	esac
done
IFS=$ifs

# internal to external map

base=confmap
{
cat <<!
#pragma prototyped
#define ${base}		_conf_map
${generated}
extern const short	${base}[];
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.h || mv $tmp.c ${base}.h

sort -n $tmp.m | {
case $shell in
ksh)	integer next ;;
esac
next=0
while	read index macro
do	case $shell in
	ksh)	while	:
		do	((next=next+1))
			((next>=$index)) && break
			echo "	-1,"
		done
		;;
	*)	while	:
		do	next=`expr $next + 1`
			expr $next \>= $index > /dev/null && break
			echo "	-1,"
		done
		;;
	esac
	cat <<!
#ifdef	$macro
	$macro,
#else
	-1,
#endif
!
done
echo $next >&3
} > $tmp.c 3> $tmp.x
map_max=`cat $tmp.x`
{
cat <<!
#pragma prototyped
#include "FEATURE/limits.lcl"
#include "FEATURE/unistd.lcl"
#include "${base}.h"

${generated}
!
if	test -s $tmp.e
then	cat <<!

/*
 * enum used on an extensible namespace -- bad idea
 */

!
	cat $tmp.e
fi
cat <<!

/*
 * internal to external conf index map
 */

const short ${base}[] =
{
	$map_max,
!
cat $tmp.c
echo "};"
} | proto > $tmp.m
cmp -s $tmp.m ${base}.c || mv $tmp.m ${base}.c

# conf string table

base=conftab
case $shell in
ksh)	((name_max=(name_max+3)/4*4)) ;;
*)	name_max=`expr \( $name_max + 3 \) / 4 \* 4` ;;
esac
{
cat <<!
#pragma prototyped

#ifndef _CONFTAB_H
#define _CONFTAB_H

${generated}

#define conf		_conf_data
#define conf_elements	_conf_ndata

#define prefix		_conf_prefix
#define prefix_elements	_conf_nprefix

#define CONF_nop	0
#define	CONF_confstr	1
#define CONF_pathconf	2
#define CONF_sysconf	3

!
index=0
for standard in $standards
do	echo "#define CONF_${standard}	${index}"
	case $shell in
	ksh)	((index=index+1)) ;;
	*)	index=`expr ${index} + 1` ;;
	esac
done
cat <<!

#define CONF_DEFINED	(1<<0)
#define CONF_FEATURE	(1<<1)
#define CONF_LIMIT	(1<<2)
#define CONF_MINMAX	(1<<3)
#define CONF_NOSECTION	(1<<4)
#define CONF_PREFIXED	(1<<5)
#define CONF_STANDARD	(1<<6)
#define CONF_UNDERSCORE	(1<<7)
#define CONF_USER	(1<<8)

typedef struct
{
	const char	name[${name_max}];
	long		value;
	short		flags;
	short		standard;
	short		section;
	short		call;
	short		op;
} Conf_t;

typedef struct
{
	const char	name[8];
	short		length;
	short		standard;
	short		call;
} Prefix_t;

extern const Conf_t	conf[];
extern int		conf_elements;

extern const Prefix_t	prefix[];
extern int		prefix_elements;

#endif
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.h || mv $tmp.c ${base}.h

{
cat <<!
#pragma prototyped
#include <ast.h>
#include "${base}.h"

${generated}

/*
 * prefix strings -- the first few are indexed by Conf_t.standard
 */

const Prefix_t prefix[] =
{
!
for standard in $standards
do	case $shell in
	ksh)	len=${#standard} ;;
	*)	len=`expr length ${standard}` ;;
	esac
	echo "	\"${standard}\",	${len},	CONF_${standard},	-1,"
done
cat <<!
	"CS",		2,	CONF_POSIX,	CONF_confstr,
	"PC",		2,	CONF_POSIX,	CONF_pathconf,
	"SC",		2,	CONF_POSIX,	CONF_sysconf,
};

int	prefix_elements = elementsof(prefix);

/*
 * conf strings sorted in ascending order
 */

const Conf_t conf[] =
{
!
if	test -f $tmp.G
then	sort -u < $tmp.G |
	while	read name section standard value flags call op
	do	case $value in
		$sym)	echo "\"$name\",
#ifdef	$value
	$value, $flags|CONF_DEFINED,
#else
	0, $flags,
#endif
	$standard, $section, $call, $op,"
			;;
		*)	echo \"$name\", $value, $flags, $standard, $section, $call, $op,
			;;
		esac
	done
else	echo '""'
fi
cat <<!
};

int	conf_elements = elementsof(conf);
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.c || mv $tmp.c ${base}.c

# conf generator definitions

base=conflib
{
cat <<!
#pragma prototyped
#define _ast_sysconf(x)	0
#define _sysconf(x)	0

${generated}

!
cat $tmp.h
cat <<!
#undef	_ast_sysconf
#undef	_sysconf
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.h || mv $tmp.c ${base}.h

# limits.h generation code

base=conflim
{
cat <<!
	/*
	 * some implementations (could it beee aix) think empty
	 * definitions constitute symbolic constants
	 */

	{
	long	num;
	char*	str;
	int	hit;
	long	lim[${limit_max}];

!
cat $tmp.l
echo "	}"
} > $tmp.c
cmp -s $tmp.c ${base}.h || mv $tmp.c ${base}.h

# unistd.h generation code

base=confuni
echo "	}" >> $tmp.u
cmp -s $tmp.u ${base}.h || mv $tmp.u ${base}.h

# confstr implementation

base=confstr pfx=CS
{
cat <<!
#pragma prototyped
#include <ast.h>
#include <error.h>

${generated}

#include "confmap.h"
#include "conflib.h"

static char*
local_${base}(int op)
{
	switch (op)
	{
!
test -f $tmp.c${pfx} && cat $tmp.c${pfx}
cat <<!
	default:
		break;
	}
	return(0);
}

size_t
${base}(int op, char* buf, size_t siz)
{
	char*	s;
	int	n;
#if _lib_${base}
#undef	${base}
	if (((n = op) >= 0 || -op <= confmap[0] && (n = confmap[-op]) >= 0) && (n = ${base}(n, buf, siz)) > 0)
		return(n);
#endif
	if (s = local_${base}(op))
	{
		if ((n = strlen(s) + 1) >= siz)
		{
			if (siz == 0)
				return(n + 1);
			buf[n = siz - 1] = 0;
		}
		memcpy(buf, s, n);
		return(n);
	}
	errno = EINVAL;
	return(0);
}
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.c || mv $tmp.c ${base}.c

# pathconf implementation

base=pathconf pfx=PC
{
cat <<!
#pragma prototyped
#include <ast.h>
#include <error.h>

${generated}

#include "confmap.h"
#include "conflib.h"

static long
statconf(struct stat* st, int op)
{
	switch (op)
	{
!
test -f $tmp.c${pfx} && cat $tmp.c${pfx}
cat <<!
	default:
		break;
	}
	errno = EINVAL;
	return(-1);
}

long
f${base}(int fd, int op)
{
	int		n;
	struct stat	st;
#if _lib_f${base}
#undef	f${base}
	if ((n = op) >= 0 || -op <= confmap[0] && (n = confmap[-op]) >= 0)
	{
		long	val;
		int	olderrno;
		int	syserrno;

		olderrno = errno;
		errno = 0;
		val = f${base}(fd, n);
		syserrno = errno;
		errno = olderrno;
		if (val != -1L || syserrno == 0)
			return(val);
	}
#endif
	return((n = fstat(fd, &st)) ? n : statconf(&st, op));
}

long
${base}(const char* path, int op)
{
	int		n;
	struct stat	st;
#if _lib_${base}
#undef	${base}
	if ((n = op) >= 0 || -op <= confmap[0] && (n = confmap[-op]) >= 0)
	{
		long	val;
		int	olderrno;
		int	syserrno;

		olderrno = errno;
		errno = 0;
		val = ${base}(path, n);
		syserrno = errno;
		errno = olderrno;
		if (val != -1L || syserrno == 0)
			return(val);
	}
#endif
	return((n = stat(path, &st)) ? n : statconf(&st, op));
}
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.c || mv $tmp.c ${base}.c

# sysconf implementation

base=sysconf pfx=SC
{
cat <<!
#pragma prototyped
#include <ast.h>
#include <error.h>

${generated}

#include "confmap.h"
#include "conflib.h"

long
${base}(int op)
{
	int	n;
#if _lib_${base}
#undef	${base}
	if ((n = op) >= 0 || -op <= confmap[0] && (n = confmap[-op]) >= 0)
	{
		long	val;
		int	olderrno;
		int	syserrno;

		olderrno = errno;
		errno = 0;
		val = ${base}(n);
		syserrno = errno;
		errno = olderrno;
		if (val != -1L || syserrno == 0)
			return(val);
	}
#endif
	switch (op)
	{
!
test -f $tmp.c${pfx} && cat $tmp.c${pfx}
cat <<!
	default:
		break;
	}
	errno = EINVAL;
	return(-1);
}
!
} | proto > $tmp.c
cmp -s $tmp.c ${base}.c || mv $tmp.c ${base}.c
