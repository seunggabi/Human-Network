i#ifndef _MENUITEM_H
#define _MENUITEM_H
#include "button.h"
class CContainer;
class CMenuItem : public CButton
{
	public:
		CMenuItem(int, int, int, const char *, CContainer *);
};
#endif
