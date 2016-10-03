i#include <iostream>
using namespace std;
#include "button.h"
#include "view.h"
#include "box.h"
#include "event.h"
#include "mouselistener.h"
CButton::CButton(int x, int y, int sx, const char * text, CContainer * s): CComponent(x, y, sx, 3) 
{
	SetColor(CView::WHITE);
	SetText(text);
	SetScreen(s);
}
void CButton::Show(){ 
	CComponent::Show();
	CView::GetView()->DrawText(m_posx+1, m_posy+1, m_text.c_str(), m_color);
}
bool CButton::OnMouse(int x, int y)
{
	if(IsInside(x, y) == true)
	{
		Active();
		return true;
		Show();
	}
	else
	{
		return false;
	}
}
void CButton::Active()
{
	CString str = CBox::GetBox()->GetText();
	str += "#";
	if(str == "선택된 개체없음#")
	{
		str = "";
	}
	str += GetText();
	CBox::GetBox()->SetText(str.c_str());
	CBox::GetBox()->Show();
}