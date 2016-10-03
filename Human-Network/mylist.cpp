i#include <iostream>
using namespace std;
#include "mylist.h"
#include "myform.h"
#include "myfile.h"
#include "line.h"
#include "button.h"
#include "checkbox.h"
CMyList::CMyList(int x, int y): CDialog(x, y)
{
	m_user_list = 0;
}
void CMyList::Init()
{
	m_ctrl = new CController();
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	SetList(list);
	Read();
	SetSize(60, m_cnt);
	CButton * btn_ok = new CButton(m_posx+35, m_posy+1, 15, "  »èÁ¦", this);
	CButton * btn_cancel = new CButton(m_posx+35, m_posy+4, 15, "  ´Ý±â", this);

	SetButtonOk(btn_ok);
	SetButtonCancel(btn_cancel);
	m_list->AddComponent(btn_ok);
	m_list->AddComponent(btn_cancel);
}
void CMyList::SetUserList(CList<CUser> * list)
{
	m_user_list = list;
}
CList<CUser> * CMyList::GetUserList()
{
	return m_user_list;
}
void CMyList::Read()
{
	m_cnt = 0;
	CList<CUser> * user_list = new CList<CUser>(m_ctrl);
	SetUserList(user_list);
	CUser * t;
	while(t = CMyFile::GetFile()->GetUser())
	{
		m_user_list->AddComponent(t);
		m_list->AddComponent(new CLine(m_posx+3, m_posy+2+m_cnt*4, m_ctrl, t));
		m_cnt++;
	}
}
void CMyList::SetSize(int x, int cnt)
{
	int y;
	
	if(cnt == 0)
	{
		y = 8;
	}
	else
	{
		y = 4+4*cnt;
	}

	m_width = x;
	m_height = y;
}
void CMyList::OnBtn()
{
	m_form = new CMyForm(10, 5, ((CLine*)GetSelect())->GetUser(), this);
	m_form->DoModal();
	Show();
}
bool CMyList::OnMouse(int x, int y)
{
	CComponent  * t;
	m_select = 0;
	for (t=m_list->GetStart(); t!=0; t = t->GetNeighbor())
	{
		if(t->OnMouse(x, y))
		{
			m_select = t;
		}
	}
	if(m_select != m_btn_cancel && m_select != m_btn_ok && m_select != 0)
	{
		OnBtn();
	}
	if(m_select == m_btn_cancel)
	{
		return true;
	}
	else if(m_select == m_btn_ok)
	{
		Remove();
		return false;
	}
	else
	{
		return false;
	}
}
bool CMyList::Remove()
{
	CComponent * t;
	CComponent * tmp;
	for(t=m_list->GetStart()->GetNeighbor(); t->GetNeighbor()!=0; )
	{
		if(((CLine*)t->GetNeighbor())->GetChecked())
		{
			tmp = t->GetNeighbor();
			t->SetNeighbor(t->GetNeighbor()->GetNeighbor());	
			delete tmp;
		}
		else
		{
			t=t->GetNeighbor();
		}
	}
	Save();
}
bool CMyList::Save()
{
	CComponent * t;
	CMyFile::GetFile()->NewFile();
	for(t=m_list->GetStart()->GetNeighbor()->GetNeighbor(); t!=0; t=t->GetNeighbor())
	{
		CMyFile::GetFile()->AddUser(((CLine*)t)->GetUser());
	}
	Show();
}
