i#include <iostream>
using namespace std;
#include "changebox.h"
#include "string.h"
#include "view.h"
CChangeBox::CChangeBox(int x, int y, int sx, CContainer * s): CComponent(x, y, sx, 3) 
{
	SetText("����� ������ �ּ���");
	SetScreen(s);
}
void CChangeBox::Show(){ 
	CComponent::Show();
	CView::GetView()->DrawText(m_posx+1, m_posy+1, m_text.c_str(), m_color);
	
}
bool CChangeBox::OnMouse(int x, int y)
{
	bool TF;
	if(IsInside(x, y) == true)
	{
		ChangeColor();
		RankName();
		TF = true;
	}
	else
	{
		TF = false;
	}
	Show();
	return TF;
}
void CChangeBox::RankName()
{
	switch(GetColor())
	{
		case 1: SetText("����ȸ��"); break;
		case 2: SetText("�ʷ�ȸ��"); break;
		case 3: SetText("���ȸ��"); break;
		case 4: SetText("�Ķ�ȸ��"); break;
		case 5: SetText("����ȸ��"); break;
		case 6: SetText("û��ȸ��"); break;
		case 7: SetText("�Ͼ�ȸ��"); break;
	}
}