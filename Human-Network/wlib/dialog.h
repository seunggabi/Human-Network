i#ifndef _DIALOG_H
#define _DIALOG_H
#include "container.h"
class CButton;
class CDialog : public CContainer
{
	protected:
		bool m_okay;
		CButton * m_btn_ok;
		CButton * m_btn_cancel;
	public:
		static const bool ID_OK=true, ID_CANCEL=false;
		CDialog(int, int);
		bool DoModal();
		virtual void Show();
		virtual void Hide();
		virtual bool OnMouse(int, int);
		virtual void OnBtn(CComponent *);
		void SetButtonOk(CButton *);
		void SetButtonCancel(CButton *);
		virtual void Init();
};
#endif