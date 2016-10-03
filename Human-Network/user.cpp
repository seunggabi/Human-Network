i#include "user.h"
CUser::CUser(){
	// Default ������
}
CUser::CUser(const char * name, const char * id, const char * sex, const char * tel, const char * email, int rank, const char * memo)
{
	SetName(name);
	SetId(id);
	SetSex(sex);
	SetTel(tel);
	SetEmail(email);
	SetRank(rank);
	SetNeighbor(0);
	SetMemo(memo);
}

void CUser::SetName(const char * str)
{
	m_name.SetString(str);
}
void CUser::SetId(const char * str)
{
	m_id.SetString(str);
}
void CUser::SetSex(const char * str)
{
	m_sex.SetString(str);
}
void CUser::SetTel(const char * str)
{
	m_tel.SetString(str);
}
void CUser::SetEmail(const char * str)
{
	m_email.SetString(str);
}
void CUser::SetRank(int rank)
{
	m_rank = rank;
}
void CUser::SetMemo(const char * str)
{
	m_memo.SetString(str);
}
const char * CUser::GetName()
{
	return m_name.c_str();
}
const char * CUser::GetId()
{
	return m_id.c_str();
}
const char * CUser::GetSex()
{
	return m_sex.c_str();
}
const char * CUser::GetTel()
{
	return m_tel.c_str();
}
const char * CUser::GetEmail()
{
	return m_email.c_str();
}
int CUser::GetRank()
{
	return m_rank;
}
const char * CUser::GetMemo()
{
	return m_memo.c_str();
}
CUser * CUser::GetNeighbor()
{
	return m_neighbor;
}
void CUser::SetNeighbor(CUser * user)
{
	m_neighbor = user;
}
const char * CUser::GetRankName()
{

	switch(GetRank())
	{
		case 1: return "����ȸ��"; break;
		case 2: return "�ʷ�ȸ��"; break;
		case 3: return "���ȸ��"; break;
		case 4: return "�Ķ�ȸ��"; break;
		case 5: return "����ȸ��"; break;
		case 6: return "û��ȸ��"; break;
		case 7: return "�Ͼ�ȸ��"; break;
	}
}
