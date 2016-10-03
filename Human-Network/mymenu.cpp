i#include "view.h"
#include "mymenubar.h"
#include "mymenu.h"
#include "myscreen.h"
CMyMenu::CMyMenu(int x, int sx, const char * text, CContainer * s, CController * c) : CMenu(x, sx, text, s, c){}
bool CMyMenu::OnMouse(int x, int y)
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
			((CMyScreen*)GetScreen()->GetScreen())->OnForm();
		}
		else if(m_select == m_manage)
		{
			Hide();
			((CMyScreen*)GetScreen()->GetScreen())->OnList();
		}
		else if(m_select == m_item)
		{
			Hide();
			SetMenuColor(CView::RED);
		}
		else if(m_select == m_item2)
		{
			Hide();
			SetMenuColor(CView::GREEN);
		}
		Hide();
		return false; 
	}
}
void CMyMenu::SetMenuColor(int color)
{
	((CMyMenuBar*)GetScreen())->GetMenu()->SetColor(color);
	((CMyMenuBar*)GetScreen())->GetMenu2()->SetColor(color);
	GetScreen()->SetColor(color);
	GetScreen()->GetScreen()->Show();
}
void CMyMenu::Init()
{
	if(m_text == "메뉴")
	{
		m_new = new CMenuItem(m_posx, m_posy+3, m_width, "등록", this);
		m_manage = new CMenuItem(m_posx, m_posy+6, m_width, "관리", this);
		m_list->AddComponent(m_new);
		m_list->AddComponent(m_manage);
		m_item = 0;
		m_item2 = 0;
	}
	else
	{
		m_item = new CMenuItem(m_posx, m_posy+3, m_width, "빨강", this);
		m_item2 = new CMenuItem(m_posx, m_posy+6, m_width, "초록", this);
		m_list->AddComponent(m_item);
		m_list->AddComponent(m_item2);
		m_new = 0;
		m_manage = 0;
	}
	CMenu::Init();
}
