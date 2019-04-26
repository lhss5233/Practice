#pragma once
#include "User.h"

//Ŭ���� �缳�� �ʿ�

class Login
{
	using Insert = std::pair< std::string, User* >;
	//���� ������ ���
	std::map< std::string, User* > m_LoginData;
	
	//���� ����
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
	//���̵� ����Ȯ��
	bool FindID(std::string a_V) const;

	bool UserLogin();
	//�α��� ��������
	User * GetUser();

	void UserLogout();
};

#define LOGIN_INTI() { Login::CreateInstance(); Login::GetInstance()->Init();}
#define LoginMng()  (Login::GetInstance())
#define ReleaseLoginMng() (Login::ReleaseInstance())
