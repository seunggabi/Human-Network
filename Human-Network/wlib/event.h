i#ifndef _EVENT_H
#define _EVENT_H
class CEvent
{
	public: 
		static const int BUTTON_DOWN=1, BUTTON_UP=2;
		int m_x, m_y, m_t;  
		CEvent(int x, int y, int t):m_x(x), m_y(y), m_t(t){}
		bool IsMouseLeft(){ return m_t == BUTTON_DOWN; }
		bool IsMouseRight(){ return m_t == BUTTON_UP; }
};
#endif