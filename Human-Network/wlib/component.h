i#ifndef _COMPONENT_H
#define _COMPONENT_H
#include "string.h"
#include "mouselistener.h"
class CView;
class CEvent;
class CContainer;
class CComponent
{
	protected:
		int m_posx, m_posy; 
		int m_width, m_height;
		int m_color;
		CComponent * m_neighbor ;
		CString m_text;
		CContainer * m_screen;
		CMouseListener * m_listener;
	public:
		CComponent();
		CComponent(int, int, int, int);
		bool IsInside(int, int);
		void ChangeColor();
		void SetColor(int);
		int GetColor();
		void SetNeighbor(CComponent *);
		CComponent * GetNeighbor();
		void SetScreen(CContainer *);
		CContainer * GetScreen();
		virtual void SetText(const char *);
		virtual const char * GetText();
		virtual void Show();
		virtual bool OnMouse(int, int);
		virtual bool OnChar(int);
		virtual void AddListener(CMouseListener *);
		virtual bool OnMouseEvent(CEvent *e);
		class CBListener: public CMouseListener
		{
			public:
				CBListener(CComponent * host);
				void MouseLeftAction(CEvent *e);
				void MouseRightAction(CEvent *e);
		};
};
#endif