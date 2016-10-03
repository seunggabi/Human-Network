i#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;
#include "controller.h"
#include "component.h"
template <class T>
class CList{
	private:
		T *m_start;
		CController * m_ctrl;
	public:
		CList<T>(CController * c)
			: m_start(0), m_ctrl(c){}
		void ShowAllComponents()
		{
			T * t;
			for (t=m_start; t!=0; t = t->GetNeighbor()){
				t->Show();
			}
		}
		void AddComponent(T *t)
		{
			t->SetNeighbor(m_start);
			m_start = t;
		}
		T * GetStart()
		{
			return m_start;
		}
		void ChangeAllColor(int color)
		{	
			T * t;
			for (t=m_start; t!=0; t = t->GetNeighbor()){
				t->SetColor(color);
			}
		}
		class iterator
		{
			private:
				T * m_p;
			public:
				iterator()
				{
					m_p = 0;
				}
				iterator(T *p)
				{
					m_p = p;
				}
				T * Get()
				{
					return m_p;
				}
				void operator ++ ()
				{
					m_p = m_p->GetNeighbor();
				}
				bool operator != (iterator x)
				{
					return m_p != x.Get();
				}
				T * operator * ()
				{
					return m_p;
				}
		};
		iterator begin()
		{
			return iterator(m_start);
		}
		iterator end()
		{
			return iterator((T *)0);
		}
};
#endif

