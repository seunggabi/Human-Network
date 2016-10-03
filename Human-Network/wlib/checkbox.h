i#ifndef _CHECKBOX_H
#define _CHECKBOX_H
#include "component.h"
class CCheckBox : public CComponent
{
	protected:
		bool m_checked;
	public:
		CCheckBox(int, int, int, const char *);
		bool GetChecked();
		void ToggleChecked();
		virtual void Show();
		virtual bool OnMouse(int, int);
};
#endif