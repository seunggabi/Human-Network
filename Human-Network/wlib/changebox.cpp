i#include <iostream>
using namespace std;
#include "changebox.h"
#include "string.h"
#include "view.h"
CChangeBox::CChangeBox(int x, int y, int sx, CContainer * s): CComponent(x, y, sx, 3) 
{
	SetText("등급을 선택해 주세요");
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
		case 1: SetText("빨간회원"); break;
		case 2: SetText("초록회원"); break;
		case 3: SetText("노란회원"); break;
		case 4: SetText("파란회원"); break;
		case 5: SetText("보라회원"); break;
		case 6: SetText("청록회원"); break;
		case 7: SetText("하얀회원"); break;
	}
}