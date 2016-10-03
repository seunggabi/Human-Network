i#ifndef _RADIO_H
#define _RADIO_H
#include "component.h"
class CContainer;
class CRadio : public CComponent
{
	protected:
		bool m_checked;
	public:
		CRadio(int, int, const char *, CContainer *);
		CRadio(int, int, const char *, CContainer *, bool);
		bool GetChecked();
		void OnCheck();
		void OnUnCheck();
		virtual void Show();
		virtual bool OnMouse(int, int);
};
#endif
