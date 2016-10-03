i#ifndef _CHANGBOX_H
#define _CHANGBOX_H
#include "component.h"
class CContainer;
class CChangeBox :public CComponent{
	public:	
		CChangeBox(int, int, int, CContainer *);
		virtual void Show();  
		virtual bool OnMouse(int, int);
		void RankName();
		void GetRankName();
};
#endif