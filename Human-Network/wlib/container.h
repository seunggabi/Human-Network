i#ifndef _CONTAINER_H
#define _CONTAINER_H
#include "component.h"
#include "list.h"
class CController;
class CContainer: public CComponent
{
	protected:
		CController * m_ctrl;
		CList<CComponent> *m_list;
		CComponent * m_select;
	public:
		CContainer();
		CContainer(CController*);
		CComponent * GetSelect();
		void ShowAllList();
		void SetList(CList<CComponent> *);
		CList<CComponent> * GetList();
		virtual bool OnMouse(int, int);
		virtual bool OnChar(int);
		virtual void OnBtn(CComponent *);
		virtual void OnResize();
		virtual void Init();
		virtual bool OnMouseEvent(CEvent *e);
};
#endif