i#include <curses.h>
#include <iostream>
using namespace std;
#include "component.h"
#include "menu.h"
#include "menuitem.h"
#include "screen.h"
#include "view.h"
CMenu::CMenu(int x, int sx, const char * text, CContainer * s, CController * c): CContainer(c)
{
	m_posx = x;
	m_posy = 0;
	m_width = sx;
	m_height = 3;
	SetColor(CView::WHITE);
	SetText(text);
	SetScreen(s);
	m_list = new CList<CComponent>(m_ctrl);
}
void CMenu::Show(){ 
	CView::GetView()->Rectangle(m_posx, m_posy, m_width, m_height, m_color);
	CView::GetView()->DrawText(m_posx+1, m_posy+1, m_text.c_str(), m_color);
}
bool CMenu::OnMouse(int x, int y)
{
	m_select = 0;
	if(IsInside(x, y) == true)
	{
		if(m_new != 0 && m_manage != 0)
		{
			Hide();
			return true;
		}
		if(m_item !=0 && m_item2 != 0)
		{
			Hide();
			return true;
		}
		Init();
		return true;
	}
	else
	{
		CList<CComponent>::iterator i; 
		for (i=m_list->begin(); i!=m_list->end(); ++i)
		{
			if((*i)->OnMouse(x, y))
			{
				m_select = *i;
			}
		}
		if(m_select == 0)
		{
			return false;
		}
		else if(m_select == m_new)
		{
			Hide();
		}
		else if(m_select == m_manage)
		{
			Hide();
		}
		Hide();
		return false; 
	}
}
void CMenu::Init()
{
	ShowAllList();
}
void CMenu::Hide()
{
	CView::GetView()->EraseRect(m_posx, m_posy+3, m_width, m_height*3);;
	CList<CComponent> * list = m_list;
	m_list = new CList<CComponent>(m_ctrl);
	if(list != 0)
		delete list;
	if(m_new != 0)
		delete m_new;
		m_new = (CMenuItem *)0;
	if(m_manage != 0)
		delete m_manage;
		m_manage = (CMenuItem *)0;
	if(m_item != 0)
		delete m_item;
		m_item = (CMenuItem *)0;
	if(m_item2 != 0)
		delete m_item2;
		m_item2 = (CMenuItem *)0;
}