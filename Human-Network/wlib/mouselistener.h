i#ifndef _MOUSELISTENER_H
#define _MOUSELISTENER_H
#include "event.h"
class CComponent;
class CMouseListener
{
	public:
		CMouseListener(CComponent * h):m_host(h){}
		virtual void MouseLeftAction(CEvent *e)=0;
		virtual void MouseRightAction(CEvent *e)=0;
	protected:
		CComponent * m_host;
};
#endif