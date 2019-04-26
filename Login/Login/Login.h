#pragma once
#include "User.h"

//클래스 재설계 필요

class Login
{
	using Insert = std::pair< std::string, User* >;
	//유저 데이터 목록
	std::map< std::string, User* > m_LoginData;
	
	//현제 유저
	User* m_LoginUser = nullptr;
	
#pragma region SingleTon
	static inline Login * m_pInstance = nullptr;
	Login() = default;
	
	Login operator=(Login&) = delete;
	Login(const Login&) = delete;
	Login(Login &&) = delete;
	
	~Login();

public:
	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Login();
		}
	}

	static Login* GetInstance()
	{
		return m_pInstance;
	}
	static void ReleaseInstance()
	{
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

public:	  
	void Init();

	bool SignID();
	//아이디 존재확인
	bool FindID(std::string a_V) const;

	bool UserLogin();
	//로그인 유저접근
	User * GetUser();

	void UserLogout();
};

#define LOGIN_INTI() { Login::CreateInstance(); Login::GetInstance()->Init();}
#define LoginMng()  (Login::GetInstance())
#define ReleaseLoginMng() (Login::ReleaseInstance())
