i#include <iostream>
using namespace std;
#include "controller.h"
#include "list.h"
#include "radiogroup.h"
#include "radio.h"
CRadioGroup::CRadioGroup(int x, int y, CController * c):CContainer()
{
	m_ctrl = c;
	m_posx = x;
	m_posy = y;
}
void CRadioGroup::Init()
{
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	
	CRadio * m_sex_m = new CRadio(m_posx, m_posy, "여자", this);
	CRadio * m_sex_f = new CRadio(m_posx+10, m_posy, "남자", this, true);

	SetList(list);

	m_list->AddComponent(m_sex_m);
	m_list->AddComponent(m_sex_f);

	ShowAllList();
}
void CRadioGroup::Show()
{
	Init();
}
CRadio * CRadioGroup::GetSelect()
{
	CList<CComponent>::iterator i; 
	for (i=m_list->begin(); i!=m_list->end(); ++i)
	{
		if(((CRadio*)*i)->GetChecked())
		{
			m_select = *i;
			return (CRadio*)m_select;
		}
	}
}