i#include <iostream>
using namespace std;
#include "myform.h"
#include "button.h"
#include "editbox.h"
#include "changebox.h"
#include "label.h"
#include "radiogroup.h" 
#include "radio.h"
#include "textarea.h"
#include "myfile.h"
#include "mylist.h"
#include "user.h"

CMyForm::CMyForm(int x, int y): CDialog(x, y)
{
	m_user = 0;
	m_edit = false;	
}
CMyForm::CMyForm(int x, int y, CUser * u, CContainer * c): CDialog(x, y)
{
	m_user = u;
	m_edit = true;
	m_screen = c;
}
void CMyForm::Init()
{
	SetMode();
	CLabel * l_name = new CLabel(m_posx+5, m_posy+3, "이름", this);
	CLabel * l_id = new CLabel(m_posx+5, m_posy+7, "ID", this);
	CLabel * l_sex = new CLabel(m_posx+5, m_posy+11, "성별", this);
	CLabel * l_tel = new CLabel(m_posx+5, m_posy+15, "전화번호", this);
	CLabel * l_email = new CLabel(m_posx+5, m_posy+19, "E-mail", this);
	CLabel * l_rank = new CLabel(m_posx+5, m_posy+23, "등급", this);
	CLabel * l_memo = new CLabel(m_posx+5, m_posy+27, "메모", this);

	m_list->AddComponent(l_name);
	m_list->AddComponent(l_id);
	m_list->AddComponent(l_sex);
	m_list->AddComponent(l_tel);
	m_list->AddComponent(l_email);
	m_list->AddComponent(l_rank);
	m_list->AddComponent(l_memo);
}
const char * CMyForm::GetName()
{
	return m_name->GetText();
}
const char * CMyForm::GetId()
{
	return m_id->GetText();
}
const char * CMyForm::GetSex()
{
	return m_sex_group->GetSelect()->GetText();
}
const char * CMyForm::GetTel()
{
	return m_tel->GetText();
}
const char * CMyForm::GetEmail()
{
	return m_email->GetText();
}
int CMyForm::GetRank()
{
	return m_rank->GetColor();
}
const char * CMyForm::GetMemo()
{
	return m_memo->GetText();
}
void CMyForm::OnBtn(CComponent * c)
{
	if(m_btn_ok == (CButton*)c && !m_edit)
	{
		m_okay = true;
		CUser * user = new CUser(GetName(), GetId(), GetSex(), GetTel(), GetEmail(), GetRank(), GetMemo());
		CMyFile::GetFile()->AddUser(user);
	}
	else if(m_btn_cancel == (CButton*)c && m_edit)
	{
		m_okay = false;
		m_user->SetMemo(GetMemo());
		((CMyList*)m_screen)->Save();
	}
	else if(m_btn_cancel == (CButton*)c)
	{
		m_okay = false;
	}
}
void CMyForm::SetMode()
{
	if(!m_edit)
	{
		CDialog::Init();
		m_name = new CEditBox(m_posx+15, m_posy+2, 10, "", this);
		m_id = new CEditBox(m_posx+15, m_posy+6, 10, "", this);
		m_sex_group = new CRadioGroup(m_posx+15, m_posy+11, m_ctrl);
		m_tel = new CEditBox(m_posx+15, m_posy+14, 20, "", this);
		m_email = new CEditBox(m_posx+15, m_posy+18, 23, "", this);
		m_rank = new CChangeBox(m_posx+15, m_posy+22, 23, this);
		m_memo = new CTextArea(m_posx+15, m_posy+25, 23, 10, "", this);

		m_list->AddComponent(m_sex_group);
		m_list->AddComponent(m_name);
		m_list->AddComponent(m_id);
		m_list->AddComponent(m_tel);
		m_list->AddComponent(m_email);
		m_list->AddComponent(m_rank);
		m_list->AddComponent(m_memo);
	}
	else
	{
		m_ctrl = new CController();
		CList<CComponent> * list = new CList<CComponent>(m_ctrl);
		SetList(list);
		CButton * btn_ok = new CButton(m_posx+12, m_posy+36, 15, "  OK", this);	
		CButton * btn_cancel = new CButton(m_posx+22, m_posy+36, 15, "  Cancel", this);

		SetButtonOk(btn_ok);
		SetButtonCancel(btn_cancel);
		m_list->AddComponent(btn_cancel);

		e_name = new CLabel(m_posx+15, m_posy+3, m_user->GetName(), this);
		e_id = new CLabel(m_posx+15, m_posy+7, m_user->GetId(), this);
		e_sex = new CLabel(m_posx+15, m_posy+11, m_user->GetSex(), this);
		e_tel = new CLabel(m_posx+15, m_posy+15, m_user->GetTel(), this);
		e_email = new CLabel(m_posx+15, m_posy+19, m_user->GetEmail(), this);
		e_rank = new CLabel(m_posx+15, m_posy+23, m_user->GetRankName(), this);
		m_memo = new CTextArea(m_posx+15, m_posy+26, 23, 10, m_user->GetMemo(), this);

		m_list->AddComponent(e_name);
		m_list->AddComponent(e_id);
		m_list->AddComponent(e_sex);
		m_list->AddComponent(e_tel);
		m_list->AddComponent(e_email);
		m_list->AddComponent(e_rank);
		m_list->AddComponent(m_memo);
	}
}
