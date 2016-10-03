i#include "myfile.h"
CMyFile::CMyFile()
{
}

CMyFile * CMyFile::GetFile()
{
	static CMyFile m_static_file;
	return &m_static_file;
}
ofstream * CMyFile::GetOfp()
{
	return &m_ofp;
}
ifstream * CMyFile::GetIfp()
{
	return &m_ifp;
}
void CMyFile::Set(const char * str)
{
	m_ifp.open(str);
	m_ofp.open(str, fstream::app);
}
void CMyFile::Append(const char * str)
{
	Open();
	m_ofp<<str;
	Close();
}
void CMyFile::AddUser(CUser * user)
{
	Open();
	m_ofp<<DataChecker(user->GetName())<<" ";
	m_ofp<<DataChecker(user->GetId())<<" ";
	m_ofp<<DataChecker(user->GetSex())<<" ";
	m_ofp<<DataChecker(user->GetTel())<<" ";
	m_ofp<<DataChecker(user->GetEmail())<<" ";
	m_ofp<<user->GetRank()<<" ";
	m_ofp<<DataChecker(user->GetMemo())<<endl;
	Close();
}
void CMyFile::Open()
{
	Set("user.txt");
}
void CMyFile::Close()
{
	m_ifp.close();
	m_ofp.close();
}
CUser * CMyFile::GetUser()
{
	if(!m_ifp.is_open())
	{
		Open();
	}
	char name[30]={0};
	char id[10]={0};
	char sex[10]={0};
	char tel[20]={0};
	char email[30]={0};
	int rank=7;
	char memo[255]={0};
	if(!m_ifp.eof())
	{
		m_ifp>>name>>id>>sex>>tel>>email>>rank>>memo;
		if(sex[0] == 0)
		{
			Close();
			return (CUser*)0;
		}
		else
		{
			CUser * user = new CUser(name, id, sex, tel, email, rank, memo);
			return user;
		}
	}
	else
	{
		Close();
		return (CUser*)0;
	}
}
const char * CMyFile::DataChecker(const char * str)
{
	if(str[0] != 0)
	{
		return str;
	}
	else
	{
		return "¹ÌÀÔ·Â";
	}
}
void CMyFile::NewFile()
{
	m_ofp.open("user.txt");
	Close();
}
