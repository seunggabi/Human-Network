i#include "string.h"
#include <string.h>
#include <stdlib.h>

CString::CString():m_str(0)
{
}
CString::~CString()
{
	free(m_str);
}
CString::CString(const char * str)
{
	m_str = strdup(str);
}
void CString::Add(CString &str)
{
	Add(str.c_str());
}
void CString::Add(const char * str)
{
	m_str = (char*)realloc(m_str, strlen(m_str)+strlen(str)+1);
	strcat(m_str, str);
}
void CString::Add(char chr)
{
	int len = strlen(m_str);
	m_str = (char*)realloc(m_str, len+2);
	*(m_str+len) = chr;
	*(m_str+len+1) = 0;
}
CString CString::substr(int begin, int end)
{
	CString temp;
	int idx=0;
	char * t =  (char*)malloc(end-begin+1);	
	for( int i=begin; i<end; i++ )
	{
		*(t+idx++) = *(m_str+i);
	}
	*(t+idx) = 0;
	temp.SetString(t);
	return temp;
}
int CString::Length()
{
	return strlen(m_str);
}
void CString::SetString(char chr)
{
	char * t = m_str;
	m_str = (char*)malloc(2);
	m_str[0] = chr;
	m_str[1] = 0;
	free(t);
}
void CString::SetString(const char * str)
{
	char * t = m_str;
	m_str = strdup(str);
	free(t);
}
const char * CString::c_str()
{
	return m_str;
}
CString & CString::operator = (char chr)
{
	SetString(chr);
	return *this;
}
CString & CString::operator = (const char * str)
{
	SetString(str);
	return *this;
}
CString & CString::operator = (CString & str)
{
	SetString(str.c_str());
	return *this;
}
CString & CString::operator += (const char * str)
{
	m_str = (char*)realloc(m_str, strlen(m_str)+strlen(str)+1);
	strcat(m_str, str);
	return *this;
}
CString & CString::operator += (char chr)
{
	int len = strlen(m_str);
	m_str = (char*)realloc(m_str, len+2);
	*(m_str+len) = chr;
	*(m_str+len+1) = 0;
	return *this;
}
CString & CString::operator += (CString & str)
{
	*this += str.c_str();
	return *this;
}
CString & CString::operator -- (int n)
{
	int len = strlen(m_str);
	*(m_str+len-1)=0;
	return *this;
}
bool CString::operator == (const char * str)
{
	if(strcmp(m_str, str))
	{
		return false;
	}
	else
	{
		return true;
	}
}
