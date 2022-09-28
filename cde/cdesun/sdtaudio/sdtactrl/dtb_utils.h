/*
 * File: dtb_utils.h
 * CDE Application Builder General Utility Functions
 *
 * This file was generated by dtcodegen, from project sdtactrl
 *
 *    ** DO NOT MODIFY BY HAND - ALL MODIFICATIONS WILL BE LOST **
 */
#ifndef _DTB_UTILS_H_
#define _DTB_UTILS_H_

#include <stdlib.h>
#include <X11/Intrinsic.h>
#include <Xm/Xm.h>
#include <Dt/Dnd.h>

/*
 * Function type for client session save callback
 */
typedef Boolean (*DtbClientSessionSaveCB) (
    Widget,
    char *,
    char ***,
    int *
);
typedef struct {
    char	*help_text;
    char	*help_volume;
    char	*help_locationID;
} DtbObjectHelpDataRec, *DtbObjectHelpData;

/*
 * Returns answer value for modal MessageBox
 */
typedef enum {
    DTB_ANSWER_NONE,
    DTB_ANSWER_ACTION1,
    DTB_ANSWER_ACTION2,
    DTB_ANSWER_ACTION3,
    DTB_ANSWER_CANCEL,
    DTB_ANSWER_HELP
} DTB_MODAL_ANSWER;

/*
 * Values for MessageBox default button
 */
typedef enum {
    DTB_ACTION1_BUTTON,
    DTB_ACTION2_BUTTON,
    DTB_ACTION3_BUTTON,
    DTB_CANCEL_BUTTON,
    DTB_NONE
} DTB_BUTTON;

/*
 * Types/ways of centering an object
 */
typedef enum {
    DTB_CENTER_NONE,
    DTB_CENTER_POSITION_VERT,
    DTB_CENTER_POSITION_HORIZ,
    DTB_CENTER_POSITION_BOTH
} DTB_CENTERING_TYPES;


/*
 * Types for Drag and Drop utilities
 */
typedef enum
{
    DTB_DND_UNDEF = 0,
    DTB_DND_ANIMATE,
    DTB_DND_CONVERT,
    DTB_DND_DELETE,
    DTB_DND_DRAG_START,
    DTB_DND_DROPPED_ON,
    DTB_DND_DROPPED_ON_ROOT_WINDOW,
    DTB_DND_FINISH,
    DTB_DND_RECEIVE_DATA,
    DTB_DND_REGISTER
} DTB_DND_REQUEST;

typedef struct
{
    DtDndProtocol      protocol;
    unsigned char      operations;     /* XmCopy | XmMove | XmLink */
    Boolean            bufferIsText;
    Boolean            allowDropOnRootWindow;
    int                numItems;
    Widget             cursor;         /* from DtDndCreateSourceIcon() */
} DtbDndDragStartInfoRec, *DtbDndDragStartInfo;

typedef struct
{
    Boolean    droppedOnRootWindow;
} DtbDndDroppedOnRootWindowInfoRec, *DtbDndDroppedOnRootWindowInfo;

typedef void   (*DtbDndDragCallback)(
                       DTB_DND_REQUEST                 request,
                       DtbDndDragStartInfo             dragStart,
                       DtDndConvertCallback            convert,
                       DtbDndDroppedOnRootWindowInfo   droppedOnRootWindow,
                       DtDndConvertCallback            deleteSource,
                       DtDndDragFinishCallback         finish
               );

typedef unsigned long  DtbDragSiteHandle;


typedef struct {
DtDndProtocol      	protocols;
unsigned char      	operations;     /* XmCopy | XmMove | XmLink */
Boolean            	textIsBuffer;
Boolean            	preservePreviousRegistration;
Boolean		respondToDropsOnChildren;
} DtbDndDropRegisterInfoRec, *DtbDndDropRegisterInfo;

typedef void	(*DtbDndDropCallback)(
			Widget				widget,
			DTB_DND_REQUEST			request,
			DtbDndDropRegisterInfo		registerInfo,
			DtDndTransferCallback		receiveInfo,
			DtDndDropAnimateCallback	animateInfo
		);

typedef unsigned long	DtbDropSiteHandle;


/*
 * Types of group layout
 */
typedef enum {
    DTB_GROUP_NONE,
    DTB_GROUP_ROWS,
    DTB_GROUP_COLUMNS,
    DTB_GROUP_ROWSCOLUMNS
} DTB_GROUP_TYPES;

/*
 * Types/ways of aligning the children of a group
 */
typedef enum {
    DTB_ALIGN_NONE,
    DTB_ALIGN_TOP,
    DTB_ALIGN_RIGHT,
    DTB_ALIGN_BOTTOM,
    DTB_ALIGN_LEFT,
    DTB_ALIGN_VCENTER,
    DTB_ALIGN_HCENTER,
    DTB_ALIGN_LABELS
} DTB_ALIGN_TYPES;

/*
 * Structure to store attributes of a group
 */
typedef struct {
    DTB_GROUP_TYPES     group_type;
    DTB_ALIGN_TYPES     row_align;
    DTB_ALIGN_TYPES     col_align;
    int                 margin;
    int                 num_rows;
    int                 num_cols;
    int                 hoffset;
    int                 voffset;
    Widget              ref_widget;
} DtbGroupInfo;



/*
 * Application Builder utility functions
 */
int dtb_cvt_file_to_pixmap(
    String	fileName,
    Widget	widget,
    Pixmap	*pixmapReturnPtr
);
int dtb_set_label_pixmaps(
    Widget	widget,
    Pixmap	labelPixmap,
    Pixmap	labelInsensitivePixmap
);
int dtb_set_label_from_bitmap_data(
    Widget		widget,
    int			width,
    int			height,
    unsigned char	*bitmapData
);
Boolean dtb_file_has_extension(
    String	fileName, 
    String	extension
);
int dtb_cvt_filebase_to_pixmap(
    Widget	widget,
    String	fileBase,
    String	extension,
    Pixmap	*pixmap_ptr
);
int dtb_cvt_image_file_to_pixmap(
		Widget	widget,
		String	fileName,
		Pixmap	*pixmap
);
int dtb_set_label_from_image_file(
		Widget	widget,
		String	fileName
);
unsigned long dtb_cvt_resource_from_string(
    Widget		parent,
    String		res_type,
    unsigned int	size_of_type,
    String		res_str_value,
    unsigned long	error_value
);
Pixmap dtb_create_greyed_pixmap(
    Widget	widget,
    Pixmap	pixmap
);
void dtb_save_toplevel_widget(
    Widget	toplevel
);
Widget dtb_get_toplevel_widget();
void dtb_remove_sash_focus(
    Widget	widget
);
void dtb_save_command(
    char	*argv0
);
char *  dtb_get_command();
String dtb_get_exe_dir(void);
void dtb_help_dispatch(
    Widget 	widget,
    XtPointer 	clientData,
    XtPointer 	callData
);
void dtb_more_help_dispatch(
    Widget 	widget,
    XtPointer 	clientData,
    XtPointer 	callData
);
void dtb_help_back_hdlr(
    Widget 	widget,
    XtPointer 	clientData,
    XtPointer 	callData
);
void dtb_do_onitem_help();
int dtb_show_help_volume_info(
    char	*volume_name,
    char	*location_id
);
void  dtb_call_help_callback(
    Widget widget,
    XtPointer clientData,
    XtPointer callData
);
int  dtb_popup_menu_register(Widget popupMenu, Widget parent);
int dtb_drag_site_register(
                        Widget 			widget,
			DtbDndDragCallback	callback,
			DtDndProtocol		protocol,
			unsigned char		operations,
			Boolean			bufferIsText,
			Boolean			allowDropOnRootWindow,
			Pixmap			cursor,
			Pixmap			cursorMask,
			DtbDragSiteHandle	*dragSiteHandleOut
);
int dtb_drop_site_register(
                        Widget                  widget,
                        DtbDndDropCallback      callback,
                        DtDndProtocol		protocols,
                        unsigned char           operations,
                        Boolean                 dropsOnChildren,
                        Boolean                 preservePreviousRegistration,
                        DtbDropSiteHandle       *dropSiteHandleOut
);
void dtb_children_center(
    Widget		form,
    DTB_CENTERING_TYPES	type
);
void dtb_children_uncenter(
    Widget		form,
    DTB_CENTERING_TYPES	type
);
void dtb_center(
    Widget		form_child,
    DTB_CENTERING_TYPES	type
);
void dtb_uncenter(
    Widget		form_child,
    DTB_CENTERING_TYPES	type
);
void dtb_children_align(
    Widget		parent,
    DTB_GROUP_TYPES	group_type,
    DTB_ALIGN_TYPES	row_align,
    DTB_ALIGN_TYPES	col_align,
    int			margin,
    int			num_rows,
    int			num_cols,
    int			hoffset,
    int			voffset
);
void dtb_session_save(
    Widget 	widget,
    XtPointer 	clientData,
    XtPointer 	callData
);
DtbClientSessionSaveCB dtb_get_client_session_saveCB();


#define dtb_cvt_string_to_pixel(parent, str) \
        ((Pixel)dtb_cvt_resource_from_string( \
                   (parent), XtRPixel, sizeof(Pixel), (str), 0))

#endif /* _DTB_UTILS_H_ */
