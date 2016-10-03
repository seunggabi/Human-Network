i#ifndef _MYFILE_H
#define _MYFILE_H
#include "user.h"
#include <fstream>
using namespace std;
class CMyFile {
	public:	
		static CMyFile * GetFile();
		ofstream * GetOfp();
		ifstream * GetIfp();
		void Set(const char *);
		void Append(const char *);
		void AddUser(CUser *);
		void Close();
		void Open();
		CUser * GetUser();
		const char * DataChecker(const char *);
		void NewFile();
	private:
		CMyFile();  
		ifstream m_ifp;
		ofstream m_ofp;
};
#endif
