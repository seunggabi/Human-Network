i#include "view.h"
#include "menuitem.h"
CMenuItem::CMenuItem(int x, int y, int sx, const char * text, CContainer * s): CButton(x, y, sx, text, s) 
{
	SetColor(CView::WHITE);
}