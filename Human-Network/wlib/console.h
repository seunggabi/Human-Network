i#ifndef _CONSOLE_H
#define _CONSOLE_H
#include <iostream>
using namespace std;
class CConsole {
	public:
		static CConsole * GetConsole();
		void Show(string);
	private:
		CConsole(); 
		string m_text;
		int curLine;
		int color;
};
#endif