i#include <iostream>
using namespace std;
#include "checkbox.h"
#include "view.h"
CCheckBox::CCheckBox(int x, int y, int sx, const char * text): CComponent(x, y, sx, 3), m_checked(false)
{
	SetText(text);
}

void CCheckBox::Show()
{ 
	CComponent::Show();
	CView::GetView()->DrawCheckBox(m_posx, m_posy, m_text.c_str(), m_checked, m_color);
	
}
bool CCheckBox::OnMouse(int x, int y)
{
	if(IsInside(x, y) == true)
	{
		ToggleChecked();
		Show();
	}
	return false;
}

bool CCheckBox::GetChecked()
{
	return m_checked;
}
void CCheckBox::ToggleChecked()
{
	if(m_checked == true)
	{
		m_checked = false;
	}
	else
	{
		m_checked = true;
	}
}