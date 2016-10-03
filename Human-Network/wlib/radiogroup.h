i#ifndef _RADIOGROUP_H
#define _RADIOGROUP_H
#include "container.h"
class CController;
class CRadio;
class CRadioGroup :public CContainer
{
	public:	
		CRadioGroup(int, int, CController *);
		CRadio * GetSelect();
		void Show();	
		void Init();
};
#endif
