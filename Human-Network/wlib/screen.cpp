i#include <iostream>
using namespace std;
#include "view.h"
#include "screen.h"
#include <curses.h>
CScreen::CScreen():CContainer()
{
	getmaxyx(stdscr, m_height, m_width);
}
void CScreen::Show()
{
	CView::GetView()->Rectangle(0, 0, m_width, m_height, m_color);
	ShowAllList();
}
void CScreen::OnResize()
{
	getmaxyx(stdscr, m_height, m_width);
	Show();
}
void CScreen::Init()
{
	Show();
	CContainer::Init();
}
