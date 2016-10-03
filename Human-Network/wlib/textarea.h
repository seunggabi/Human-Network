i#ifndef _TEXTAREA_H
#define _TEXTAREA_H
#include "editbox.h"
class CContainer;
class CTextArea : public CEditBox
{
	public:
		CTextArea(int, int, int, int, const char *, CContainer *);
		virtual void Show();  
};
#endif
