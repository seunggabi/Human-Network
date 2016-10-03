i#ifndef _LINE_H
#define _LINE_H
#include "container.h"
class CController;
class CCheckBox;
class CUser;
class CLine :public CContainer
{
	public:	
		CLine(int x, int y, CController * c, CUser * u);  
		bool GetChecked();
		virtual void Show();	
		virtual void Init();
		virtual bool OnMouse(int x, int y);
		CUser * GetUser();
	private:
		CUser * m_user;
		CCheckBox * m_check;
};
#endif
