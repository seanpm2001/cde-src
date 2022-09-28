/* 
 * @OSF_COPYRIGHT@
 * (c) Copyright 1990, 1991, 1992, 1993, 1994 OPEN SOFTWARE FOUNDATION, INC.
 * ALL RIGHTS RESERVED
 *  
*/ 
/*
 * HISTORY
 * Motif Release 1.2.5
*/
/*   $XConsortium: BitmapsI.h /main/cde1_maint/2 1995/08/18 18:51:20 drk $ */
/*
*  (c) Copyright 1987, 1988, 1989, 1990, 1991, 1992 HEWLETT-PACKARD COMPANY */
/*************************************<+>*************************************
 *****************************************************************************
 **
 **   File:        BitmapsI.h
 **
 **   Description: This file contains a set of predefines bitmaps
 **		   which are used by the image caching functions.
 **
 ****************************************************************************
 ************************************<+>*************************************/

#ifndef _XmBitmapsI_h
#define _XmBitmapsI_h

#ifdef __cplusplus
extern "C" {
#endif

static _XmConst unsigned char bitmaps [20][32] =
{
   {  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*  Solid Background  */
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  },

   {  0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22,	/*  25 percent  */
      0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22,
      0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22,
      0x88, 0x88, 0x22, 0x22, 0x88, 0x88, 0x22, 0x22  },

   {  0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA,	/*  50 percent  */
      0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA,
      0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA,
      0x55, 0x55, 0xAA, 0xAA, 0x55, 0x55, 0xAA, 0xAA  },

   {  0x55, 0x55, 0xFF, 0xFF, 0xAA, 0xAA, 0xFF, 0xFF,	/*  75 percent  */
      0x55, 0x55, 0xFF, 0xFF, 0xAA, 0xAA, 0xFF, 0xFF,
      0x55, 0x55, 0xFF, 0xFF, 0xAA, 0xAA, 0xFF, 0xFF,
      0x55, 0x55, 0xFF, 0xFF, 0xAA, 0xAA, 0xFF, 0xFF  },

   {  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,	/*  Vertical tile  */
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55  },

   {  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,	/*  Horizontal tile */ 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00  },

   {  0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,	/*  Vertical  */
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
      0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55  },

   {  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,	/*  Horizontal  */ 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
      0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00  },

   {  0x77, 0x77, 0xbb, 0xbb, 0xdd, 0xdd, 0xee, 0xee,	/*  Slant Left  */
      0x77, 0x77, 0xbb, 0xbb, 0xdd, 0xdd, 0xee, 0xee, 
      0x77, 0x77, 0xbb, 0xbb, 0xdd, 0xdd, 0xee, 0xee, 
      0x77, 0x77, 0xbb, 0xbb, 0xdd, 0xdd, 0xee, 0xee  },

   {  0xee, 0xee, 0xdd, 0xdd, 0xbb, 0xbb, 0x77, 0x77,	/*  Slant Right  */
      0xee, 0xee, 0xdd, 0xdd, 0xbb, 0xbb, 0x77, 0x77, 
      0xee, 0xee, 0xdd, 0xdd, 0xbb, 0xbb, 0x77, 0x77, 
      0xee, 0xee, 0xdd, 0xdd, 0xbb, 0xbb, 0x77, 0x77  },

   {  						
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /*  Default Cascade  */ 
     0x00, 0x03, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x18,  
     0xff, 0x3f, 0x00, 0x18, 0x00, 0x0c, 0x00, 0x06,  
     0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   },

   {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /* Default CheckMark */
      0x00, 0x00, 0x00, 0x60, 0x00, 0x30, 0x00, 0x18, 
      0x00, 0x0c, 0x08, 0x06, 0x18, 0x03, 0xb0, 0x01, 
      0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  }, 
   {  						
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  /*  Default menu dash */ 
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
     0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00   },
};


static _XmConst char * bitmap_name_set[] =
{
   "background",
   "25_foreground",
   "50_foreground",
   "75_foreground",
   "vertical_tile",
   "horizontal_tile",
   /* for bc reason with 1.2.2, we have to put back the old names,
      but we also need to keep the new ones, for 1.2.3 users */
   "vertical",
   "horizontal",
   "slant_right",
   "slant_left",
   "menu_cascade",
   "menu_checkmark",
   "menu_dash"
};

#define MAX_BUILTIN_IMAGES	13

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#endif /* _XmBitmapsI_h */
/* DON'T ADD STUFF AFTER THIS #endif */
