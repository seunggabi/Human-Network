i#ifndef _BUTTON_H
#define _BUTTON_H
#include "component.h"
class CContainer;
class CEvent;
class CButton : public CComponent
{
	public:
		CButton(int, int, int, const char *, CContainer *);
		virtual void Show();  
		virtual bool OnMouse(int, int);
		void Active();
};
#endif