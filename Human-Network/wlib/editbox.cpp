i#include <ncurses.h>
#include <iostream>
using namespace std;
#include "editbox.h"
#include "string.h"
#include "view.h"
CEditBox::CEditBox(int x, int y, int sx, const char * text, CContainer * s): CComponent(x, y, sx, 3) 
{
	SetText(text);
	SetScreen(s);
}
void CEditBox::Show()
{ 
	CComponent::Show();
	CView::GetView()->DrawText(m_posx+1, m_posy+1, m_text.c_str(), m_color);	
}
bool CEditBox::OnMouse(int x, int y)
{
	bool TF;
	if(IsInside(x, y) == true)
	{
		SetColor(CView::CYAN);
		TF = true;
	}
	else
	{
		SetColor(CView::WHITE);
		TF = false;
	}
	Show();
	return TF;
}
bool CEditBox::OnChar(int c)
{
	if(c == KEY_BACKSPACE)
	{
		m_text--;
	}
	else
	{
		m_text+=c;
	}
	Show();
	return false;
}