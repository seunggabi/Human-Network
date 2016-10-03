i#ifndef _MYFORM_H
#define _MYFORM_H
#include "dialog.h"
class CRadioGroup;
class CView;
class CChangeBox;
class CUser;
class CLabel;
class CButton;
class CEditBox;
class CTextArea;
class CMyForm : public CDialog
{
	protected:
		CLabel * e_name;
		CLabel * e_id;
		CLabel * e_sex;
		CLabel * e_tel;
		CLabel * e_email;
		CLabel * e_rank;
		CEditBox * m_name;
		CEditBox * m_id;
		CEditBox * m_tel;
		CEditBox * m_email;
		CChangeBox * m_rank;
		CRadioGroup * m_sex_group;
		CTextArea * m_memo;
		CUser * m_user;
		bool m_edit;
		CContainer * m_screen;
	public:
		CMyForm(int x, int y);
		CMyForm(int x, int y, CUser *, CContainer *);
		const char * GetName();
		const char * GetId();
		const char * GetSex();
		const char * GetTel();
		const char * GetEmail();
		int GetRank();
		const char * GetMemo();
		virtual void Init();
		virtual void OnBtn(CComponent *);
		void SetMode();
};

#endif
