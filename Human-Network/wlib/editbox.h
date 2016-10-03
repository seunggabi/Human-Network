i#ifndef _EDITBOX_H
#define _EDITBOX_H
#include "component.h"
class CContainer;
class CEditBox : public CComponent
{
	public:
		CEditBox(int, int, int, const char *, CContainer *);
		virtual void Show();  
		virtual bool OnMouse(int, int);
		virtual bool OnChar(int);
};
#endif