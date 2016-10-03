i#ifndef _MYLIST_H
#define _MYLIST_H
#include "dialog.h"
class list;
class CMyForm;
class CUser;
class CMyList : public CDialog
{
	protected:
		CList<CUser> * m_user_list;
		CMyForm * m_form;
		int m_cnt;
	public:
		CMyList(int x, int y);
		virtual void Init();
		void SetUserList(CList<CUser> *);
		CList<CUser> * GetUserList();
		void Read();
		void SetSize(int x, int cnt);
		virtual void OnBtn();
		virtual bool OnMouse(int x, int y);
		bool Remove();
		bool Save();
};
#endif
