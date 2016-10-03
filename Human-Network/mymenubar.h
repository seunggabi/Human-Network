i#ifndef _MYMENUBAR_H
#define _MYMENUBAR_H
#include "menubar.h"
class CMyMenu;
class CMyMenuBar :public CMenuBar{
	public:	
		CMyMenuBar(CContainer * s);
		virtual void Init();
		CMyMenu * GetMenu();
		CMyMenu * GetMenu2();
	protected:
		CMyMenu * m_menu;
		CMyMenu * m_menu2;
};
#endif
