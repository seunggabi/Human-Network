#include "console.h"
#include "view.h"
CConsole * CConsole::GetConsole()
{
	static CConsole m_static_console;
	return &m_static_console;
}
CConsole::CConsole()
{
	m_text = "";
	curLine = 0;
	color = 0;
	CView::GetView()->Rectangle(70, 0, 30, 20, CView::YELLOW);
}
void CConsole::Show(string msg)
{
	if (curLine== 0){
		CView::GetView()->EraseRect(71, 1, 28, 18);
	}
	CView::GetView()->DrawText(71, curLine+1, msg.c_str(), CView::WHITE);
	curLine = (curLine+1)%18;
}
