/* $XConsortium: hashdump.c /main/cde1_maint/3 1995/10/14 00:37:38 montyb $ */
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
#include "hashlib.h"

/*
 * dump HASH_* flags
 */

static void
dumpflags __PARAM__((register int flags), (flags)) __OTORP__(register int flags;){
	if (flags & HASH_ALLOCATE) sfprintf(sfstderr, "allocate ");
	if (flags & HASH_BUCKET) sfprintf(sfstderr, "bucket ");
	if (flags & HASH_FIXED) sfprintf(sfstderr, "fixed ");
	if (flags & HASH_HASHED) sfprintf(sfstderr, "hashed ");
	if (flags & HASH_RESIZE) sfprintf(sfstderr, "resize ");
	if (flags & HASH_SCANNING) sfprintf(sfstderr, "scanning ");
	if (flags & HASH_STATIC) sfprintf(sfstderr, "static ");
	if (flags & HASH_VALUE) sfprintf(sfstderr, "value ");
}

/*
 * dump hash table bucket info
 */

static void
dumpbucket __PARAM__((register Hash_table_t* tab, int flags), (tab, flags)) __OTORP__(register Hash_table_t* tab; int flags;){
	register Hash_bucket_t**	sp;
	register Hash_bucket_t*		b;
	Hash_bucket_t**			sx;
	int				n;
	unsigned char*			s;

	NoP(flags);
	sx = tab->table + tab->size;
	for (sp = tab->table; sp < sx; sp++)
	{
		n = 0;
		for (b = *sp; b; b = b->next)
			if (!(b->hash & HASH_DELETED) && (!(tab->flags & HASH_VALUE) || b->value))
				n++;
		if (n)
		{
			sfprintf(sfstderr, "%5d %2d :", sp - tab->table, n);
			for (b = *sp; b; b = b->next)
				if (!(b->hash & HASH_DELETED) && (!(tab->flags & HASH_VALUE) || b->value))
				{
					if (n = tab->root->namesize)
					{
						sfprintf(sfstderr, " 0x");
						s = (unsigned char*)hashname(b);
						while (n-- > 0)
							sfprintf(sfstderr, "%02x", *s++);
					}
					else sfprintf(sfstderr, " %s", hashname(b));
					if (b->hash & HASH_FLAGS)
					{
						sfprintf(sfstderr, "|");
						if (b->hash & HASH_HIDES) sfprintf(sfstderr, "hides|");
						if (b->hash & HASH_HIDDEN) sfprintf(sfstderr, "hidden|");
						if (b->hash & HASH_KEEP) sfprintf(sfstderr, "keep|");
						if (b->hash & HASH_OPAQUED) sfprintf(sfstderr, "opaque|");
					}
					if (tab->flags & HASH_VALUE) sfprintf(sfstderr, "=0x%08lx", (long)b->value);
				}
			sfprintf(sfstderr, "\n");
		}
	}
	sfprintf(sfstderr, "\n");
}

/*
 * dump info on a single table
 */

static void
dumptable __PARAM__((register Hash_table_t* tab, register int flags), (tab, flags)) __OTORP__(register Hash_table_t* tab; register int flags;){
	Hash_table_t*	scope;
	int		level;

	sfprintf(sfstderr, "        name:        %s", tab->name ? tab->name : "*no name*");
	if (scope = tab->scope)
	{
		level = 1;
		while (scope = scope->scope) level++;
		sfprintf(sfstderr, " level %d scope on 0x%08lx", level, (unsigned long)tab->scope);
	}
	sfprintf(sfstderr, "\n");
	sfprintf(sfstderr, "        address:     0x%08lx\n", (unsigned long)tab);
	sfprintf(sfstderr, "        flags:       ");
	if (tab->frozen) sfprintf(sfstderr, "frozen=%d ", tab->frozen);
	dumpflags(tab->flags);
	sfprintf(sfstderr, "\n");
	sfprintf(sfstderr, "        size:        %d\n", tab->size);
	sfprintf(sfstderr, "        buckets:     %d\n", tab->buckets);
	sfprintf(sfstderr, "        bucketsize:  %d\n", tab->bucketsize * sizeof(char*));
	sfprintf(sfstderr, "\n");
	if ((flags | tab->flags) & HASH_BUCKET) dumpbucket(tab, flags);
}

/*
 * dump hash table root info
 */

static void
dumproot __PARAM__((register Hash_root_t* root, register int flags), (root, flags)) __OTORP__(register Hash_root_t* root; register int flags;){
	register Hash_table_t*	tab;

	sfprintf(sfstderr, "    root\n");
	sfprintf(sfstderr, "        address:     0x%08lx\n", (unsigned long)root);
	sfprintf(sfstderr, "        flags:       ");
	dumpflags(root->flags);
	if (root->namesize) sfprintf(sfstderr, "namesize=%d ", root->namesize);
	if (root->local->alloc) sfprintf(sfstderr, "alloc=0x%08lx ", (unsigned long)root->local->alloc);
	if (root->local->compare) sfprintf(sfstderr, "compare=0x%08lx ", (unsigned long)root->local->compare);
	if (root->local->free) sfprintf(sfstderr, "free=0x%08lx ", (unsigned long)root->local->free);
	if (root->local->hash) sfprintf(sfstderr, "hash=0x%08lx ", (unsigned long)root->local->hash);
	if (root->local->region) sfprintf(sfstderr, "region=0x%08lx handle=0x%08lx ", (unsigned long)root->local->region, (unsigned long)root->local->handle);
	sfprintf(sfstderr, "\n");
	sfprintf(sfstderr, "        meanchain:   %d\n", root->meanchain);
	sfprintf(sfstderr, "        accesses:    %d\n", root->accesses);
	sfprintf(sfstderr, "        collisions:  %d\n", root->collisions);
	sfprintf(sfstderr, "\n");
	for (tab = root->references; tab; tab = tab->next)
		dumptable(tab, flags);
}

/*
 * dump hash table accounting info
 * if tab is 0 then dump all tables in hash_info.list
 * flags are HASH_* flags that specifiy optional dump info
 */

void
hashdump __PARAM__((register Hash_table_t* tab, int flags), (tab, flags)) __OTORP__(register Hash_table_t* tab; int flags;){
	register Hash_root_t*	root;

	sfprintf(sfstderr, "\nhash table information:\n\n");
	if (tab) dumproot(tab->root, flags);
	else for (root = hash_info.list; root; root = root->next)
		dumproot(root, flags);
	sfsync(sfstderr);
}
