i#include <iostream>
using namespace std;
#include "box.h"
#include "view.h"
CBox * CBox::GetBox()
{
	static CBox m_box(70, 5, "선택된 개체없음");
	return &m_box;
}
CBox::CBox(int x, int y, const char * text): CComponent(x, y, 30, 20) 
{
	SetColor(CView::YELLOW);
	SetText(text);
}
void CBox::Show(){ 
	CComponent::Show();
	CView::GetView()->DrawBox(m_posx, m_posy, m_text.c_str(), m_color);
}
void CBox::SetText(const char * t)
{
	m_text.SetString(t);
}
bool CBox::OnMouse(int x, int y)
{
	return false;
}
