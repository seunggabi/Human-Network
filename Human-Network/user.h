#include "string.h"
i#ifndef _USER_H
#define _USER_H
class CUser {
	public:	
		CUser();  
		CUser(const char *, const char *, const char *, const char *, const char *, int, const char *);
		void SetName(const char *);
		void SetId(const char *);
		void SetSex(const char *);
		void SetTel(const char *);
		void SetEmail(const char *);
		void SetRank(int);
		void SetMemo(const char *);
		const char * GetName();
		const char * GetId();
		const char * GetSex();
		const char * GetTel();
		const char * GetEmail();
		int GetRank();
		const char * GetMemo();
		const char * GetRankName();
		void SetNeighbor(CUser *);
		CUser * GetNeighbor();

	protected:

	private:
		CString m_name;
		CString m_id;
		CString m_sex;
		CString m_tel;
		CString m_email;
		int m_rank;
		CString m_memo;
		CUser * m_neighbor;
};
#endif
