#include "mymenu.h"
#include "mymenubar.h"
#include "myscreen.h"
CMyMenuBar::CMyMenuBar(CContainer * s) : CMenuBar(s)
{
	Init();
}
void CMyMenuBar::Init()
{
	m_menu = new CMyMenu(m_posx, 10, "메뉴", this, m_ctrl);
	m_menu2 = new CMyMenu(m_posx+10, 10, "색상", this, m_ctrl);

	m_list->AddComponent(m_menu);
	m_list->AddComponent(m_menu2);
}
CMyMenu * CMyMenuBar::GetMenu()
{
	return m_menu;
}
CMyMenu * CMyMenuBar::GetMenu2()
{
	return m_menu2;
}
