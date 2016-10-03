i#include <iostream>
using namespace std;
#include "component.h"
#include "container.h"
#include "string.h"
#include "view.h"
CComponent::CComponent()
{
	m_posx = 0;
	m_posy = 0;
	m_width = 0;
	m_height = 0;
	m_color = CView::WHITE;
}
CComponent::CComponent(int x, int y, int sx, int sy)
{
	m_posx = x;
	m_posy = y;
	m_width = sx;
	m_height = sy;
	m_color = CView::WHITE;
}
bool CComponent::IsInside(int x, int y){
	if ( m_posx <= x && x <= m_posx+m_width &&
			m_posy <= y && y <= m_posy + m_height ){
		return true;
	} else {
		return false;
	}
}
void CComponent::ChangeColor()
{
	if(m_color < 7)
	{
		m_color++;
	}
	else
	{
		m_color=1;
	}
}
void CComponent::SetColor(int color){
	m_color = color;
}
int CComponent::GetColor()
{
	return m_color;
}
void CComponent::SetNeighbor(CComponent *t)
{
	m_neighbor = t;
}
CComponent * CComponent::GetNeighbor()
{
	return m_neighbor;
}
void CComponent::SetScreen(CContainer * s)
{
	m_screen = s;
}
CContainer * CComponent::GetScreen()
{
	return m_screen;
}
void CComponent::SetText(const char * text)
{
	m_text.SetString(text);
}
const char * CComponent::GetText()
{
	return m_text.c_str();
}
void CComponent::Show(){ 
	CView::GetView()->Rectangle(m_posx, m_posy, m_width, m_height, m_color);
	
}
bool CComponent::OnMouse(int x, int y)
{
	return false;
}
bool CComponent::OnChar(int c)
{
	return false;
}
void CComponent::AddListener(CMouseListener * ml)
{
	m_listener = ml;
}
CComponent::CBListener::CBListener(CComponent * host): CMouseListener(host){}
void CComponent::CBListener::MouseLeftAction(CEvent *e)
{
	m_host->OnMouse(e->m_x, e->m_y);
}
void CComponent::CBListener::MouseRightAction(CEvent *e)
{
	m_host->OnMouse(e->m_x, e->m_y);
}
bool CComponent::OnMouseEvent(CEvent *e)
{
	AddListener(new CBListener(this));
	if (e->IsMouseLeft())
	{
		m_listener->MouseLeftAction(e);
	}
	else if (e->IsMouseRight()){
		m_listener->MouseRightAction(e);
	} 
}