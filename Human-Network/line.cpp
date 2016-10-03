i#include <iostream>
using namespace std;
#include "controller.h"
#include "checkbox.h"
#include "button.h"
#include "list.h"
#include "line.h"
#include "user.h"
CLine::CLine(int x, int y, CController * c, CUser * u):CContainer()
{
	m_ctrl = c;
	m_posx = x;
	m_posy = y;
	m_user = u;
}
void CLine::Init()
{
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	
	m_check = new CCheckBox(m_posx, m_posy, 3, "");
	CButton * m_name = new CButton(m_posx+2, m_posy, 10, m_user->GetName(), this);
	CButton * m_id = new CButton(m_posx+11, m_posy, 10, m_user->GetId(), this);

	SetList(list);

	m_list->AddComponent(m_check);
	m_list->AddComponent(m_name);
	m_list->AddComponent(m_id);
	m_list->ChangeAllColor(m_user->GetRank());
	ShowAllList();
}
void CLine::Show()
{
	Init();
}
bool CLine::GetChecked()
{
	return m_check->GetChecked();
}
CUser * CLine::GetUser()
{
	return m_user;
}
bool CLine::OnMouse(int x, int y)
{
	CComponent  * t;
	m_select = 0;
	for (t=m_list->GetStart(); t!=0; t = t->GetNeighbor())
	{
		if(t->OnMouse(x, y))
		{
			m_select = t;
		}
	}
	if(m_select !=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
