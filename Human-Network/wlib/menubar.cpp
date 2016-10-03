i#include <curses.h>
#include <iostream>
using namespace std;
#include "component.h"
#include "menubar.h"
#include "screen.h"
#include "view.h"
#include "menu.h"
#include "menuitem.h"
CMenuBar::CMenuBar(CContainer * s): CContainer()
{
	m_posx = 0;
	m_posy = 0;
	m_height = 3;
	SetColor(CView::WHITE);
	SetScreen(s);
	m_list = new CList<CComponent>(m_ctrl);
}
void CMenuBar::Show(){ 
	getmaxyx(stdscr, m_win_height, m_win_width);
	CView::GetView()->Rectangle(m_posx, m_posy, m_win_width, m_height, m_color);
	ShowAllList();
}
bool CMenuBar::OnMouse(int x, int y)
{
	m_select = 0;
	CList<CComponent>::iterator i; 
	for (i=m_list->begin(); i!=m_list->end(); ++i)
	{
		if((*i)->OnMouse(x, y))
		{
			m_select = *i;
		}
		else
		{
			((CMenu*)(*i))->Hide();
		}
	}
	return true;
}
void CMenuBar::Init()
{
	m_menu = new CMenu(m_posx, 10, "메뉴", this, m_ctrl);
	m_menu2 = new CMenu(m_posx+10, 10, "색상", this, m_ctrl);

	m_list->AddComponent(m_menu);
	m_list->AddComponent(m_menu2);
}