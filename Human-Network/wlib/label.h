i#ifndef _LABEL_H
#define _LABEL_H
#include "component.h"
class CView;
class CContainer;
class CLabel : public CComponent
{
	public:
		CLabel(int, int, const char *, CContainer *);
		virtual void Show();  
		virtual bool OnMouse(int, int);
		virtual bool OnChar(int);
};
#endif
