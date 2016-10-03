i#include <ncurses.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "view.h"
CView::~CView()
{
	endwin();
}
CView * CView::GetView()
{
	static CView m_static_view;
	return &m_static_view;
}
CView::CView()
{
	// Default 생성자
	initscr(); cbreak(); noecho(); nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0); // curs_set(1); 하면 커서가 보임.

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}
void CView::DrawText(int x, int y, const char * str, int color)
{
	::move(y, x);
	::attron(COLOR_PAIR(color));
	::addstr(str);
	::refresh();
}
void CView::DrawTextArea(int x, int y, const char * str, int color, int width)
{
	int len = strlen(str);
	int line = -1;

	::attron(COLOR_PAIR(color));
	for(int i=0;i<len;i++)
	{
		int posx = i%(width-2);
		if( posx == 0)
		{
			line++;
		}
		::move(y+line, x+posx);
		::hline(str[i],1);
	}
	::refresh();
}
void CView::EraseRect(int x, int y, int width, int height)
{
	for (int i=0; i<height; i++){
		move(y+i, x);
		hline(' ', width);
	}
}
void CView::Rectangle(int x, int y, int width, int height, int color)
{
	if (width<=0 || height <=0) return;
	EraseRect(x, y, width, height);
	::attron(COLOR_PAIR(color));
	::move(y, x); 
	::hline('-', width); 
	::move(y+height-1, x); 
	::hline('-', width); 
	::move(y, x);
	::vline('|', height);
	::move(y, x+width-1);
	::vline('|', height);
	::move(y,x); ::addstr("+");
	::move(y+height-1,x); ::addstr("+");
	::move(y,x+width-1); ::addstr("+");
	::move(y+height-1,x+width-1); ::addstr("+");

	::refresh();
	::attroff(COLOR_PAIR(color));
}
void CView::DrawCheckBox(int x, int y, const char * name, bool checked, int color)
{
	::attron(COLOR_PAIR(color));
	
	if(checked == true)
	{
		::move(y+1, x+1); ::addstr("V");
	}

	::move(y+1, x+2); ::addstr("|");
	::move(y+1, x+3); ::addstr(name);

	::refresh();
	::attroff(COLOR_PAIR(color));
}
void CView::DrawBox(int x, int y, const char * name, int color)
{
	int len = strlen(name);
	::attron(COLOR_PAIR(color));
	int j=0;
	int idx=0;
	for(int i=0; i<len; i++)
	{
		if(name[i] == '#')
		{
			idx=0;
			j++;
			continue;
		}
		if(name[i] == ' ')
		{
			continue;
		}
		::attron(COLOR_PAIR(WHITE));
		::move(y+1+j, x+idx+1);
		::vline(name[i],1);
		idx++;
	}
	::refresh();
	::attroff(COLOR_PAIR(color));
}
void CView::DrawRadio(int x, int y, const char * name, bool checked, int color)
{
	::attron(COLOR_PAIR(color));
	
	if(checked == true)
	{
		::move(y, x); ::addstr("◎");
	}
	else
	{
		::move(y, x); ::addstr("○");
	}

	::move(y, x+3); ::addstr(name);

	::refresh();
	::attroff(COLOR_PAIR(color));
}
