i#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <iostream>
using namespace std;
class CString
{
	private:
		char * m_str;
	public:
		CString(const char *);
		CString();
		~CString();
		void Add(CString &);
		void Add(const char *);
		void Add(char);
		CString substr(int begin, int end);
		int Length();
		void SetString(const char *);
		void SetString(char);
		const char * c_str();
		CString & operator = (const char *);
		CString & operator = (char);
		CString & operator = (CString &);
		CString & operator += (const char *);
		CString & operator += (CString &);
		CString & operator -- (int);
		CString & operator += (char);
		bool operator == (const char *);
};
#endif
