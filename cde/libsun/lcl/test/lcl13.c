/* lcl13 - LctNMsgText type (header and body) send mail sample */
/* for header or body is null case */

#include <stdio.h>
#include <locale.h>

#include "lcl.h"

static char *load_file(char *);
static void print_segment(LclCharsetSegmentSet *segs);
static void print_charset_list(LclCharsetList *list);

int
main(int argc, char **argv)
{
    char *locale;
    char *body;
    char *header;
    LCLd lcld;
    LCTd lclt;
    LclError	*ret;
    LclCharsetSegmentSet *segs;
    LclCharsetList	*list;
    char	*body_charset;
    int n;

    setlocale(LC_ALL, "");

    if ((locale = setlocale(LC_CTYPE, NULL)) == NULL) {
	fprintf(stderr, "Locale is not set correctly.\n");
	return 1;
    }

    header = load_file("header.euc-jp");
    body = load_file("body.euc-jp");

    /* open lcld */
    lcld = lcl_open(locale);
    if (!lcld) {
	fprintf(stderr, "Failed: lcl_open()\n");
	return 1;
    }


    /*** body processing ***/
    /* create lclt from mail body */
    lclt = lct_create(lcld, 
		      LctNSourceType, LctNMsgText, LctNNone, body,
		      LctNSourceForm, LctNDisplayForm,
		      LctNKeepReference, LctNKeepByReference,
		      NULL);

    if (!lclt) {
	fprintf(stderr, "Failed: lcl_create()\n");
	return 1;
    }

    /*** optional - user can chose the mail charset encoding ***/
    /* get charset candidates (shown to user) */
    ret = lct_getvalues(lclt,
                        LctNOutGoingStreamForm,
                            LctNBodyPossibleCharsetList, &list,
                        NULL);
    if (ret) {
        fprintf(stderr, "Failed: lcl_getvalues()\n");
        lcl_destroy_error(ret);
        return 1;
    }
    print_charset_list(list);

    /* set the one of candidates (chosen by user)*/
    n = 0;
    lct_setvalues(lclt,
                  LctNOutGoingStreamForm,
                  LctNBodyCharset, list->charset[n],
                  NULL);
    lcl_destroy_charset_list(list);
    /*** end of optional ***/

    /* get converted body */
    ret = lct_getvalues(lclt,
			LctNOutGoingStreamForm,
			LctNBodySegment, &segs,
			NULL);

    if (ret) {
	fprintf(stderr, "Failed: lcl_getvalues()\n");
	return 1;
    }
    print_segment(segs);

    /* get body charset for header processing */
    ret = lct_getvalues(lclt,
                        LctNOutGoingStreamForm,
                        LctNBodyCharset, &body_charset,
                        NULL);
    if (ret) {
        fprintf(stderr, "Failed: lcl_getvalues()\n");
        lcl_destroy_error(ret);
        return 1;
    }
    fprintf(stderr, "body_charset = %s\n", body_charset);

    /* destroy */
    lct_destroy(lclt);


    /*** header processing ***/
    /* create lclt from mail header */
    lclt = lct_create(lcld, 
		      LctNSourceType, LctNMsgText, header, LctNNone,
		      LctNSourceForm, LctNDisplayForm,
		      LctNKeepReference, LctNKeepByReference,
		      NULL);

    if (!lclt) {
	fprintf(stderr, "Failed: lcl_create()\n");
	return 1;
    }

    /* set body charset */
    lct_setvalues(lclt,
                  LctNOutGoingStreamForm,
                  LctNBodyCharset, body_charset,
                  NULL);
    free(body_charset);

    /* get converted header */
    ret = lct_getvalues(lclt,
			LctNOutGoingStreamForm,
			LctNHeaderSegment, &segs,
			NULL);

    if (ret) {
	fprintf(stderr, "Failed: lcl_getvalues()\n");
	lcl_destroy_error(ret);
	return 1;
    }
    print_segment(segs);

    /* destroy */
    lct_destroy(lclt);


    /* close */
    lcl_close(lcld);

    return 0;
}


#include <sys/stat.h>

static char *
load_file(char *filename)
{
    struct stat	fs;
    char *buf = NULL;
    FILE *fp;

    if (!filename || !*filename)
	return NULL;

    if(stat(filename, &fs))
	return NULL;

    if ((fp = fopen(filename, "r")) == (FILE *) NULL)
	return NULL;

    if ((buf = (char *) malloc(fs.st_size + 1)) == (char *) NULL)
	return NULL;

    if (fread(buf, 1, (fs.st_size + 1), fp) == 0)
	return NULL;

    buf[fs.st_size] = (char) 0;

    fclose(fp);

    return buf;
}

void
print_segment(LclCharsetSegmentSet *segs)
{
        int     i;
        char    *buf;

        for(i = 0; i < segs->num; i++){
                fprintf(stderr, "seg[%d].charset = %s\n", i, segs->seg[i].charset);
                buf = (char *)malloc(segs->seg[i].size + 1);
                if(buf == (char *)NULL)
                        return;
                strncpy(buf, segs->seg[i].segment, segs->seg[i].size);
                buf[segs->seg[i].size] = (char)0;
                fprintf(stderr, "seg[%d].segment = %s\n", i, buf);
                free(buf);
        }
}

static void
print_charset_list(LclCharsetList *list)
{
        int     i;

        for(i = 0; i < list->num; i++)
                fprintf(stderr, "charset[%d] : %s\n", i, list->charset[i]);
}
