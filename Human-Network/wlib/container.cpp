i#include <iostream>
using namespace std;
#include "container.h"
#include "controller.h"
#include "view.h"

CContainer::CContainer(): CComponent()
{
	m_ctrl = new CController();
	m_list = (CList<CComponent> *) 0;
}

CContainer::CContainer(CController * c)
{
	m_ctrl = c;
	m_list = (CList<CComponent> *) 0;
}
CComponent * CContainer::GetSelect()
{
	return m_select;
}
void CContainer::ShowAllList(){
	m_list->ShowAllComponents();
}
CList<CComponent> * CContainer::GetList()
{
	return m_list;
}
void CContainer::SetList(CList<CComponent> *t){
	m_list = t;
}
bool CContainer::OnMouse(int x, int y)
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
	if(m_select != 0)
	{
		OnBtn(m_select);
	}
	return false;
}
bool CContainer::OnChar(int c)
{
	if(m_select != 0)
	{
		m_select->OnChar(c);
	}
	return false;
}
void CContainer::Init()
{
	ShowAllList();

	m_ctrl->Start(this);

	delete CView::GetView();
	delete m_ctrl;

}
void CContainer::OnResize(){}
void CContainer::OnBtn(CComponent * t){}
bool CContainer::OnMouseEvent(CEvent *e)
{
	AddListener(new CBListener(this));
	if (e->IsMouseLeft())
	{
		m_listener->MouseLeftAction(e);
	}
	else if (e->IsMouseRight()){
		m_listener->MouseRightAction(e);
	} 
}
