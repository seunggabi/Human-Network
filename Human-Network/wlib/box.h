i#ifndef _BOX_H
#define _BOX_H
#include "component.h"
class CBox : public CComponent
{
	private:
		CBox(int, int, const char *);
	public:
		static CBox * GetBox();
		virtual void Show(); 
		virtual void SetText(const char *);
		virtual bool OnMouse(int, int);
};
#endif