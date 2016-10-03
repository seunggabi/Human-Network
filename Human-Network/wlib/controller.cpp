i#include <iostream>
using namespace std;
#include "container.h"
#include "controller.h"
#include "list.h"
#include "view.h"
#include "screen.h"
#include "event.h"
#include <ncurses.h>
#include <ctype.h>

#define KEY_ESC 27
CController::CController()
{
}
void CController::Start(CContainer *container){
	int c;
	int action = 0;
	MEVENT event;
	mousemask(BUTTON1_PRESSED | BUTTON3_PRESSED, NULL);

	// main Loop
	while ( (c = getch()) != KEY_ESC ){
		// �Ʒ� ������ �Է� �� �׽�Ʈ��.
		char buf[20];
		sprintf(buf, "%d    ", c);
		CView::GetView()->DrawText(80,0,buf,CView::WHITE);
		if (c == KEY_MOUSE){
			if (getmouse(&event) == OK)
			{
				action = 0;
				if (event.bstate & BUTTON1_PRESSED)
				{
					action = 1;
				}
				else if(event.bstate & BUTTON3_PRESSED)
				{
					action = 2;
				}
				if(container->OnMouseEvent(new CEvent(event.x, event.y, action)))
				{
					break;
				}
			}
		} else if ( c == KEY_RESIZE ){
			container->OnResize();
			CView::GetView()->DrawText(0,0,"���� ũ�� ����", CView::GREEN);
		} else {
			// �������� ��� �������� �����༭ ó���ϰ� �Ѵ�.
			// WinList�� ���� ���õ� �������� �Է��� ����������Ѵ�.
			container->OnChar(c);
		}
	}

}