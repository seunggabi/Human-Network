i#ifndef _MENU_H
#define _MENU_H
#include "container.h"
#include "menuitem.h"
class CMenu :public CContainer
{
	public:	
		CMenu(int x, int sx, const char *, CContainer *, CController *);
		virtual void Show();  
		virtual bool OnMouse(int, int); 
		virtual void Init();
		virtual void Hide();
	protected:
		int m_win_width;
		int m_win_height;
		CMenuItem * m_new;
		CMenuItem * m_manage;
		CMenuItem * m_item;
		CMenuItem * m_item2;
};
#endif
