i#ifndef _SCREEN_H
#define _SCREEN_H
#include "container.h"
class CScreen :public CContainer
{
	public:	
		CScreen();  
		virtual void Init();
		virtual void Show();
		virtual void OnResize();
};
#endif