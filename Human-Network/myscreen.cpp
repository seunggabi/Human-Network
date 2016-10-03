i#include <iostream>
using namespace std;
#include "myscreen.h"
#include "controller.h"
#include "view.h"
#include "checkbox.h"
#include "editbox.h"
#include "button.h"
#include "label.h"
#include "box.h"
#include "myform.h"
#include "myfile.h"
#include "mylist.h"
#include "mymenubar.h"

CMyScreen::CMyScreen():CScreen(){
	m_select = 0;
}
void CMyScreen::Init()
{
	CList<CComponent> * list = new CList<CComponent>(m_ctrl);
	CLabel *title = new CLabel(40, 1, "인맥관리 프로그램", this);
	CMyMenuBar *menubar = new CMyMenuBar(this);
	CMyForm *myForm = new CMyForm(5, 3);
	CMyList *myList = new CMyList(5, 3);

	SetList(list);

	m_list->AddComponent(title);
	m_list->AddComponent(menubar);
	m_list->AddComponent(CBox::GetBox());
	SetFormDlg((CDialog*)myForm);
	SetListDlg((CDialog*)myList);
	
	CScreen::Init();
}
void CMyScreen::SetFormDlg(CDialog * d)
{
	m_form_dlg = d;
}
void CMyScreen::SetListDlg(CDialog * d)
{
	m_list_dlg = d;
}
CDialog * CMyScreen::GetFormDlg()
{
	return m_form_dlg;
}
CDialog * CMyScreen::GetListDlg()
{
	return m_list_dlg;
}
void CMyScreen::OnForm()
{
	m_form_dlg->DoModal();
}
void CMyScreen::OnList()
{
	m_list_dlg->DoModal();
}
