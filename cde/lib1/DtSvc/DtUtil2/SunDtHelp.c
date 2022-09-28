#pragma ident	"@(#)SunDtHelp.c	1.3	97/04/07 SMI"
/*
 *+SNOTICE
 *
 *      RESTRICTED CONFIDENTIAL INFORMATION:
 *
 *      The information in this document is subject to special
 *      restrictions in a confidential disclosure agreement bertween
 *      HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
 *      document outside HP, IBM, Sun, USL, SCO, or Univel wihtout
 *      Sun's specific written approval.  This documment and all copies
 *      and derivative works thereof must be returned or destroyed at
 *      Sun's request.
 *
 *      Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 *
 *+ENOTICE
 */

#include <stdio.h>
#include <dlfcn.h>
#include <Dt/Help.h>

#pragma weak DtCreateHelpDialog = _DtCreateHelpDialog
#pragma weak DtCreateHelpQuickDialog = _DtCreateHelpQuickDialog
#pragma weak DtHelpQuickDialogGetChild = _DtHelpQuickDialogGetChild
#pragma weak DtHelpReturnSelectedWidgetId = _DtHelpReturnSelectedWidgetId

typedef Widget (*SUNWWidgetProc)();
typedef int (*SUNWIntProc)();

typedef struct _SUNWHelpProcList {
    SUNWWidgetProc	DtCreateHelpDialogSym;
    SUNWWidgetProc	DtCreateHelpQuickDialogSym;
    SUNWWidgetProc	DtHelpQuickDialogGetChildSym;
    SUNWIntProc		DtHelpReturnSelectedWidgetIdSym;
} SUNWHelpProcList;

static SUNWHelpProcList		*pmySUNWProcList = NULL;
static void			*libDtHelpHandle = NULL;

int SUNWDtHelpdlopen()
{
    pmySUNWProcList = (SUNWHelpProcList *)malloc(sizeof(SUNWHelpProcList));
    libDtHelpHandle = dlopen("libDtHelp.so.1", RTLD_LAZY | RTLD_GLOBAL);
    if (libDtHelpHandle == NULL) {
	char *my_err_msg;

	my_err_msg = dlerror();
	printf("%s\n", my_err_msg);
	return(FALSE);
    }
    pmySUNWProcList->DtCreateHelpDialogSym = (SUNWWidgetProc)
			 dlsym(libDtHelpHandle, "DtCreateHelpDialog");
    pmySUNWProcList->DtCreateHelpQuickDialogSym = (SUNWWidgetProc)
			 dlsym(libDtHelpHandle, "DtCreateHelpQuickDialog");
    pmySUNWProcList->DtHelpQuickDialogGetChildSym = (SUNWWidgetProc)
			 dlsym(libDtHelpHandle, "DtHelpQuickDialogGetChild");
    pmySUNWProcList->DtHelpReturnSelectedWidgetIdSym = (SUNWIntProc)
			 dlsym(libDtHelpHandle, "DtHelpReturnSelectedWidgetId");

    return(TRUE);
}

Widget _DtCreateHelpDialog(
    Widget parent,
    char *name,
    ArgList al,
    Cardinal ac)
{
    if (!pmySUNWProcList && !SUNWDtHelpdlopen())
        return(NULL);

    return ((*pmySUNWProcList->DtCreateHelpDialogSym)(parent, name, al, ac));
}

Widget _DtCreateHelpQuickDialog(
    Widget parent,
    char *name,
    ArgList al,
    Cardinal ac)
{
    if (!pmySUNWProcList && !SUNWDtHelpdlopen())
        return(NULL);

    return ((*pmySUNWProcList->DtCreateHelpQuickDialogSym)(parent, name, al, ac));
}

Widget _DtHelpQuickDialogGetChild(
        Widget widget,
        unsigned char child )
{
    if (!pmySUNWProcList && !SUNWDtHelpdlopen())
        return(NULL);

    return ((*pmySUNWProcList->DtHelpQuickDialogGetChildSym)(widget, child));
}

int _DtHelpReturnSelectedWidgetId(
    Widget parent,
    Cursor cursor,
    Widget  *widget)
{
    if (!pmySUNWProcList && !SUNWDtHelpdlopen())
        return(NULL);

    return ((*pmySUNWProcList->DtHelpReturnSelectedWidgetIdSym)(parent, cursor,
							    widget));
}
