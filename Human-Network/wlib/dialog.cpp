i#include <iostream>
using namespace std;
#include "controller.h"
#include "list.h"
#include "button.h"
#include "dialog.h"
#include "view.h"
CDialog::CDialog(int x, int y): CContainer() 
{
	m_posx = x;
	m_posy = y;
	m_width = 40;
	m_height = 42;
	
	m_ctrl = new CController();
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	SetList(list);
}
void CDialog::Show(){ 
	CView::GetView()->Rectangle(m_posx, m_posy, m_width, m_height,  m_color);
	m_list->ShowAllComponents();
}
void CDialog::Hide(){ 
	CView::GetView()->EraseRect(m_posx, m_posy, m_width, m_height);
}
bool CDialog::OnMouse(int x, int y)
{
	m_select = 0;
	CList<CComponent>::iterator i; 
	for (i=m_list->begin(); i!=m_list->end(); ++i)
	{
		if((*i)->OnMouse(x, y))
		{
			m_select = *i;
		}
	}
	if(m_select == m_btn_ok || m_select == m_btn_cancel)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CDialog::DoModal()
{
	Init();
	Show();
	m_ctrl->Start(this);

	OnBtn(m_select);
	delete m_ctrl;
	Hide();
	return m_okay;
}
void CDialog::OnBtn(CComponent * c)
{
	if(m_btn_ok == c)
	{
		m_okay = true;
	}
	else if(m_btn_cancel == c)
	{
		m_okay = false;
	}
}
void CDialog::SetButtonOk(CButton * b)
{
	m_btn_ok = b;
}
void CDialog::SetButtonCancel(CButton * b)
{
	m_btn_cancel = b;
}
void CDialog::Init()
{	
	m_ctrl = new CController();
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	SetList(list);

	CButton * btn_ok = new CButton(m_posx+2, m_posy+37, 15, "  ÀúÀå", this);
	CButton * btn_cancel = new CButton(m_posx+22, m_posy+37, 15, "  ´Ý±â", this);

	SetButtonOk(btn_ok);
	SetButtonCancel(btn_cancel);
	m_list->AddComponent(btn_ok);
	m_list->AddComponent(btn_cancel);
}
