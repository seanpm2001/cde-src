/*
 * @(#)ui_imagetool.h 1.18 97/03/19
 *
 * Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
 */

#ifndef	_UI_IMAGETOOL_H
#define	_UI_IMAGETOOL_H

#include <Xm/Xm.h>

/*
 * imagetool_ui.h - User interface object and function declarations.
 * This file was generated by `gxv' from `imagetool.G'.
 * DO NOT EDIT BY HAND.
 */

/* File Menu menu items... */
#define OPENFC 		1
#define OPENAS		2
#define SAVE		4
#define SAVEAS		5
#define SAVESELECTIONAS 6
#define SAVEPAGEASIMAGE 7
#define PRINTONE        9
#define PRINTPREVIEW	10
#define PRINTD	        11

/* View Menu menu items... */
#define IMAGEINFO	1
#define PAGEVIEW	3
#define PSOPTIONS	4

/* Edit Menu menu items... */
#define	UNDO		1
#define	PALETTE		3
#define PROPERTIES	4

/* Defaults for Print preview pop up */
#define	PRINT_PREVIEW_PAGE_FACTOR 	32

/* Default page size */
#define DEFAULT_PAGE_SIZE	0

/* No header page */
#define NO_HEADER_PAGE	0
#define HEADER_PAGE	1

/* Units to print */
#define INCHES   	0
#define CM      	1

/* page range choices */
#define PAGE_AS_IMAGE	0
#define ALL_PAGES	1

/* position choices */
#define CENTERED        0
#define MARGINS         1

/* orientation choices */
#define PORTRAIT	0
#define LANDSCAPE	1

/* Default choices for Zoom and Rotate Choices */
#define DEFAULT_ZOOM		100      /* For images only */
#define DEFAULT_ANGLE		90

/* inches/cm/pixel values from choices */
#define INCHES		0
#define CM		1

extern Widget   	FileMenuCreate();
extern Widget   	ViewMenuCreate();
extern Widget   	EditMenuCreate();
extern Widget   	HelpMenuCreate();

typedef struct {
	XtAppContext    app_context;
        Widget          top_level;
	Widget          mainw;
        Widget          form;
	Widget          toolbar;
        Widget          menu_bar;
        Widget          file_button;
        Widget          file_menu;
	Widget          open_item;
	Widget          openas_item;
	Widget          save_item;
	Widget          saveas_item;
	Widget          savesel_item;
	Widget          savepage_item;
	Widget          printone_item;
	Widget          printprev_item;
	Widget          print_item;
	Widget          exit_item;
        Widget          view_button;
        Widget          view_menu;
        Widget          imageinfo_item;
        Widget          overview_item;
        Widget          controls_item;
        Widget          edit_button;
        Widget          edit_menu;
        Widget          undo_item;
        Widget          palette_item;
        Widget          props_item;
        Widget          snap_item;
        Widget          help_button;
	Widget          goto_label;
	Widget          goto_scale;
	Widget          goto_pgno;
	Widget          drag_icon;
	Widget          pgfwd_button;
	Widget          pgback_button;
	Widget          scrolledw;
	Widget          canvas;
	Widget          hscroll;
	Widget 	        vscroll;
	Widget	        ps_canvas;
	Widget          left_footer;
	Widget          right_footer;
	Dimension       footer_height;
	Dimension       sb_width;
	Dimension       extra_height;

} BaseObjects;

extern BaseObjects	*base;

extern BaseObjects	*BaseObjectsInitialize();

extern Widget           open_dialog;
extern Boolean          open_showing;
extern Widget           OpenObjectsInitialize();

extern Widget           save_dialog;
extern Boolean          save_showing;
extern Widget           SaveObjectsInitialize();

typedef struct {
       Widget           shell;
       Widget           dialog;
       Widget           format_label;
       Widget           format_list;
       Boolean          showing;
} OpenAsObjects;

extern OpenAsObjects   *OpenAsObjectsInitialize();

extern OpenAsObjects   *openas;

typedef enum {SAVE_OK_BUTTON = 0,
              SAVE_CANCEL_BUTTON = 1,
              SAVE_UNDEFINED = -1} SaveAsButton;

typedef struct {
       Widget           shell;
       Widget           dialog;
       Widget           format_label;
       Widget           format_list;
       Widget           compression_menu;
       Widget           none_item;
       Widget           unix_item;
       Widget           encoded_item;
       Widget           lzw_item;
       Widget           jpeg_item;
       Widget           colors_menu; 
       Widget           bw_item;
       Widget           colors_256_item;
       Widget           colors_millions_item;
       Boolean          showing;
       SaveAsButton     button_selected;
} SaveAsObjects;

extern SaveAsObjects   *SaveAsObjectsInitialize();

extern SaveAsObjects   *saveas;

typedef struct {
        Widget          shell;
	Widget          dialog;
	Widget          form;
        Widget          page;
        Window          prev_win;
	Widget          print_button;
	Widget          cancel_button;
	Widget          help_button;
	Dimension       extra_height;
	Dimension       extra_width;
	Boolean         showing;
} PrintPrevObjects;

extern PrintPrevObjects	*print_prev;

extern PrintPrevObjects	*PrintPrevObjectsInitialize ();

typedef struct {
	Widget          shell;
	Widget          dialog;
	Widget          copies_label;
	Widget          copies_value;
	Widget          copies_text;
	Widget          header_label;
	Widget          header_checkbox;
	Widget          printer_label;
	Widget          printer_list;
	Widget          size_label;
	Widget          size_list;
	Widget          range_label;
	Widget          range_radio;
	Widget          this_page_toggle;
	Widget          orig_toggle;
	Widget          image_size_label;
	Widget          image_size_value;
	Widget          image_size_text;
	Widget          percent_label;
	Widget          image_size_slider;
	Widget          orientation_label;
	Widget          orientation_radio;
	Widget          portrait_toggle;
	Widget          landscape_toggle;
	Widget          position_label;
	Widget          position_radio;
	Widget          centered_toggle;
	Widget          margin_toggle;
	Widget          top_text;
	Widget          left_text;
	Widget          top_inches_label;
	Widget          left_inches_label;
	Widget          top_cm_label;
	Widget          left_cm_label;
	Widget          in_item;
	Widget          cm_item;
	Widget          units_menu;
	Widget          print_button;
	Widget          cancel_button;
	Widget          help_button;
	Boolean         showing;
} PrintObjects;

extern PrintObjects     *print;

extern PrintObjects     *PrintObjectsInitialize();

typedef struct {
        Widget          shell;
        Widget          dialog;
        Widget          pan_button;
        Widget          select_button;
        Widget          vflip_button;
        Widget          hflip_button;
        Widget          rotate_r_button;
        Widget          rotate_l_button;
        Widget          rotate_value;
        Widget          rotate_text;
        Widget          rotate_scale;
        Widget          zoom_button;
        Widget          zoom_value;
	Widget          zoom_text;
        Widget          zoom_scale;
        Widget          revert_button;
        Widget          cancel_button;
        Widget          help_button;

        Pixmap          pan_pixmap;
        Pixmap          select_pixmap;
        Pixmap          vflip_pixmap;
        Pixmap          hflip_pixmap;
        Pixmap          rotate_r_pixmap;
        Pixmap          rotate_l_pixmap;
        Pixmap          zoom_pixmap;
        Pixmap          degrees_pixmap;
	Boolean         showing;
} PaletteObjects;

extern PaletteObjects   *palette;

extern PaletteObjects   *PaletteObjectsInitialize();

typedef struct {
	Cursor        pan_cursor;
} CursorObjects;

extern CursorObjects	*cursor;

extern CursorObjects 	*CursorObjectsInitialize();

typedef struct {
	Widget  	shell;
	Widget          dialog;
	Widget          height_label;
	Widget          height;
	Widget  	width_label;
	Widget  	width;
	Widget  	colors_label;
	Widget  	colors;
	Widget  	size_label;
	Widget  	size;
	Widget  	format_label;
	Widget  	format;
	Widget  	cancel_button;
	Widget  	help_button;
	Boolean         showing;
} InfoObjects;

extern InfoObjects	*info;

extern InfoObjects	*InfoObjectsInitialize();

typedef struct {
        Widget           shell;
        Widget           dialog; 
	int              width;
	int              height;
	Widget           form;
	Widget           start_page_label;
	Widget           end_page_label;
        Widget           scrolledw;
        Widget           vscroll;
        Widget           hscroll;
	int              nrows;
	int              extra_width;
	int              extra_height;
	Dimension        dialog_width;
	Widget           pix_form;
	Widget          *buttons;
        Widget           goto_label;
        Widget           goto_value;
        Widget           goto_text;
        Widget           display_button;
        Widget           cancel_button;
        Widget           help_button;
	Boolean          thumbnails_created;
	Boolean          showing;
} PgOverviewObjects;

extern PgOverviewObjects *pg_overview;

extern PgOverviewObjects *PgOverviewObjectsInitialize();

typedef struct {
        Widget          shell;
        Widget          dialog;
        Widget          rotate_label;
        Widget          order_label;
        Widget          pgsize_label;
	Widget          radio1;
	Widget          radio2;
	Widget          degrees_menu;
	Widget          degrees_0;
	Widget          degrees_90;
	Widget          degrees_180;
	Widget          degrees_270;
        Widget          right_toggle;
        Widget          left_toggle;	
	Widget          lpf;
        Widget          fpf;
	Widget          size_list;
	Widget          ok_button;
	Widget          apply_button;
	Widget          cancel_button;
	Widget          help_button;
	Boolean         showing;
} PgControlsObjects;

extern PgControlsObjects *pg_controls;

extern PgControlsObjects *PgControlsObjectsInitialize();

typedef struct {
        Widget          shell;
        Widget          dialog;
        Widget          view_label;
        Widget          colors_label;
        Widget          display_label;
        Widget          ps_label;
	Widget          grayscale_toggle;
	Widget          color_toggle;
	Widget          depth1_toggle;
	Widget          depth4_toggle;
	Widget          depth8_toggle;
	Widget          depth16_toggle;
	Widget          depth24_toggle;
	Widget          colorps_toggle;
	Widget          bwps_toggle;
        Widget          radio1;
        Widget          radio2;
        Widget          radio3;
        Widget          opendoc_button;
	Widget          ok_button;
	Widget          apply_button;
	Widget          reset_button;
	Widget          cancel_button;
	Widget          help_button;
	Boolean         showing;
} PropertiesObjects;

extern PropertiesObjects	*properties;

extern PropertiesObjects	*PropertiesObjectsInitialize();

#endif /* _UI_IMAGETOOL_H */
