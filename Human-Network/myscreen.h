i#ifndef _MYSCREEN_H
#define _MYSCREEN_H
#include "screen.h"
class CButton;
class CDialog;
class CMyScreen :public CScreen{
	public:	
		CMyScreen();  
		virtual void Init();
		void SetFormDlg(CDialog *);
		void SetListDlg(CDialog *);
		CDialog * GetListDlg();
		CDialog * GetFormDlg();
		virtual void OnForm();
		virtual void OnList();
	private:
		CDialog * m_form_dlg;
		CDialog * m_list_dlg;
};
#endif
