i#include "textarea.h"
#include <ncurses.h>
#include <iostream>
using namespace std;
#include "string.h"
#include "view.h"
CTextArea::CTextArea(int x, int y, int sx, int sy, const char * text, CContainer * s): CEditBox(x, y, sx, text, s)
{
	m_height = sy;
}
void CTextArea::Show()
{ 
	CComponent::Show();
	CView::GetView()->DrawTextArea(m_posx+1, m_posy+1, m_text.c_str(), m_color, m_width);	
}
