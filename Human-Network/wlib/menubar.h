i#ifndef _MENUBAR_H
#define _MENUBAR_H
#include "container.h"
#include "menu.h"
#include "menuitem.h"
class CMenuBar :public CContainer
{
	public:	
		CMenuBar(CContainer *);
		virtual void Show();  
		virtual bool OnMouse(int, int); 
		virtual void Init();
	protected:
		int m_win_width;
		int m_win_height;
		CMenu * m_menu;
		CMenu * m_menu2;
};
#endif
