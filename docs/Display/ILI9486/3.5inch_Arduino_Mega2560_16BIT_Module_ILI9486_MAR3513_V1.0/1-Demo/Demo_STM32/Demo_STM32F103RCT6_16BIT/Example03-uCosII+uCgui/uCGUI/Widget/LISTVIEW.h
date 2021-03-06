/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              ?C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : LISTVIEW.h
Purpose     : LISTVIEW include
--------------------END-OF-HEADER-------------------------------------
*/

#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "WM.h"
#include "DIALOG.h"      /* Req. for Create indirect data structure */
#include "HEADER.h"

#if GUI_WINSUPPORT

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

/*********************************************************************
*
*       Color indices
*/
#define LISTVIEW_CI_UNSEL    0
#define LISTVIEW_CI_SEL      1
#define LISTVIEW_CI_SELFOCUS 2

/*********************************************************************
*
*       Public Types
*
**********************************************************************
*/

typedef WM_HMEM LISTVIEW_Handle;

/*********************************************************************
*
*       Create functions
*
**********************************************************************
*/

LISTVIEW_Handle LISTVIEW_Create        (int x0, int y0, int xsize, int ysize, WM_HWIN hParent, int Id, int Flags, int SpecialFlags);
LISTVIEW_Handle LISTVIEW_CreateAttached(WM_HWIN hParent, int Id, int SpecialFlags);
LISTVIEW_Handle LISTVIEW_CreateIndirect(const GUI_WIDGET_CREATE_INFO* pCreateInfo, WM_HWIN hWinParent, int x0, int y0, WM_CALLBACK* cb);
LISTVIEW_Handle LISTVIEW_CreateEx      (int x0, int y0, int xsize, int ysize, WM_HWIN hParent,
                                        int WinFlags, int ExFlags, int Id);

/*********************************************************************
*
*       Standard member functions
*
**********************************************************************
*/

#define LISTVIEW_Delete(hObj)        WM_DeleteWindow    (hObj)
#define LISTVIEW_DisableMemdev(hObj) WM_DisableMemdev   (hObj)
#define LISTVIEW_EnableMemdev(hObj)  WM_EnableMemdev    (hObj)
#define LISTVIEW_Invalidate(hObj)    WM_InvalidateWindow(hObj)
#define LISTVIEW_Paint(hObj)         WM_Paint           (hObj)

/*********************************************************************
*
*       Member functions
*
**********************************************************************
*/

void             LISTVIEW_AddColumn     (LISTVIEW_Handle hObj, int Width, const char * s, int Align);
void             LISTVIEW_AddRow        (LISTVIEW_Handle hObj, const GUI_ConstString * ppText);
void             LISTVIEW_DecSel        (LISTVIEW_Handle hObj);
void             LISTVIEW_DeleteColumn  (LISTVIEW_Handle hObj, unsigned Index);
void             LISTVIEW_DeleteRow     (LISTVIEW_Handle hObj, unsigned Index);
GUI_COLOR        LISTVIEW_GetBkColor    (LISTVIEW_Handle hObj, unsigned Index);
const GUI_FONT GUI_UNI_PTR * LISTVIEW_GetFont       (LISTVIEW_Handle hObj);
HEADER_Handle    LISTVIEW_GetHeader     (LISTVIEW_Handle hObj);
unsigned         LISTVIEW_GetNumColumns (LISTVIEW_Handle hObj);
unsigned         LISTVIEW_GetNumRows    (LISTVIEW_Handle hObj);
int              LISTVIEW_GetSel        (LISTVIEW_Handle hObj);
GUI_COLOR        LISTVIEW_GetTextColor  (LISTVIEW_Handle hObj, unsigned Index);
void             LISTVIEW_IncSel        (LISTVIEW_Handle hObj);
void             LISTVIEW_SetBkColor    (LISTVIEW_Handle hObj, unsigned int Index, GUI_COLOR Color);
void             LISTVIEW_SetColumnWidth(LISTVIEW_Handle hObj, unsigned int Index, int Width);
void             LISTVIEW_SetFont       (LISTVIEW_Handle hObj, const GUI_FONT GUI_UNI_PTR * pFont);
int              LISTVIEW_SetGridVis    (LISTVIEW_Handle hObj, int Show);
void             LISTVIEW_SetItemBkColor(LISTVIEW_Handle hObj, unsigned Column, unsigned Row, unsigned int Index, GUI_COLOR Color);
void             LISTVIEW_SetItemText   (LISTVIEW_Handle hObj, unsigned Column, unsigned Row, const char * s);
void             LISTVIEW_SetItemTextColor(LISTVIEW_Handle hObj, unsigned Column, unsigned Row, unsigned int Index, GUI_COLOR Color);
void             LISTVIEW_SetLBorder    (LISTVIEW_Handle hObj, unsigned BorderSize);
void             LISTVIEW_SetRBorder    (LISTVIEW_Handle hObj, unsigned BorderSize);
unsigned         LISTVIEW_SetRowHeight  (LISTVIEW_Handle hObj, unsigned RowHeight);
void             LISTVIEW_SetSel        (LISTVIEW_Handle hObj, int Sel);
void             LISTVIEW_SetTextAlign  (LISTVIEW_Handle hObj, unsigned int Index, int Align);
void             LISTVIEW_SetTextColor  (LISTVIEW_Handle hObj, unsigned int Index, GUI_COLOR Color);

/*********************************************************************
*
*       Global functions
*
**********************************************************************
*/

GUI_COLOR        LISTVIEW_SetDefaultBkColor  (unsigned Index, GUI_COLOR Color);
const GUI_FONT GUI_UNI_PTR * LISTVIEW_SetDefaultFont     (const GUI_FONT GUI_UNI_PTR * pFont);
GUI_COLOR        LISTVIEW_SetDefaultGridColor(GUI_COLOR Color);
GUI_COLOR        LISTVIEW_SetDefaultTextColor(unsigned Index, GUI_COLOR Color);

#if defined(__cplusplus)
  }
#endif

#endif   /* if GUI_WINSUPPORT */
#endif   /* LISTVIEW_H */
