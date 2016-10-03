#include "radio.h"
#include "radiogroup.h"
#include "view.h"
CRadio::CRadio(int x, int y, const char * text, CContainer * s): CComponent(x, y, 1, 1), m_checked(false)
{
	SetText(text);
	SetScreen(s);
}
CRadio::CRadio(int x, int y, const char * text, CContainer * s, bool checked): CComponent(x, y, 1, 1), m_checked(false)
{
	SetText(text);
	SetScreen(s);
	if(checked == true)
	{
		m_checked = true;
	}
}

void CRadio::Show()
{ 
	CView::GetView()->DrawRadio(m_posx, m_posy, m_text.c_str(), m_checked, m_color);
}
bool CRadio::OnMouse(int x, int y)
{
	CRadioGroup * t = (CRadioGroup *)m_screen;
	if(IsInside(x, y) == true)
	{
		if(t->GetSelect() != this && t->GetSelect() != 0)
		{
			t->GetSelect()->OnUnCheck();
		}
		OnCheck();
	}
	t->ShowAllList();
	return false;
}

bool CRadio::GetChecked()
{
	return m_checked;
}
void CRadio::OnCheck()
{
	m_checked = true;
}
void CRadio::OnUnCheck()
{
	m_checked = false;
}