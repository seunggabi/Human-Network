i#ifndef _MYMENU_H
#define _MYMENU_H
#include "menu.h"
class CMyMenu :public CMenu{
	public:	
		CMyMenu(int x, int sx, const char * text, CContainer * s, CController * c);
		virtual bool OnMouse(int x, int y);
		void SetMenuColor(int color);
		void Init();
};
#endif
