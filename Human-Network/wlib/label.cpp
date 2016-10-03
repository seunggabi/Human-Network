#include <iostream>
using namespace std;
#include "label.h"
#include "string.h"
#include "view.h"
CLabel::CLabel(int x, int y, const char * text, CContainer * s): CComponent(x, y, 0, 0) 
{
	SetText(text);
	SetScreen(s);
}
void CLabel::Show(){ 
	CView::GetView()->DrawText(m_posx, m_posy, m_text.c_str(), m_color);
}
bool CLabel::OnMouse(int x, int y)
{
	return false;
}
bool CLabel::OnChar(int c)
{
	return false;
}