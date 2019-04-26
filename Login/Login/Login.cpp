#include "pch.h"
#include "Login.h"




Login::~Login()
{
	for (auto i : m_LoginData)
	{
		SAFE_DELETE(i.second);
	}

	m_LoginData.clear();
}


void Login::Init()
{
	m_LoginData.insert(Insert("test1", new User()));
	m_LoginData["test1"]->SetData("1q2w3e4r", "이몽룡", 20, LoginData::Gender::Male);
	m_LoginData.insert(Insert("test2", new User()));
	m_LoginData["test2"]->SetData("q1w2e3r4", "성춘향", 20, LoginData::Gender::Female);
}

bool Login::SignID()
{
	int nTmp = 0;
	std::string strID;
	std::cout << "회원 가입을 시작합니다." << std::endl;
	std::cout << "아이디와 비밀번호를 입력해세요" << std::endl;
	while (true)
	{
		std::cout << "아이디 : "; std::cin >> strID;
		if (FindID(strID))
			std::cout << "해당 아이디가 이미 존재 합니다." << std::endl;
		else
			break;
	}
	User * pTmp = new User();
	pTmp->SetPW();
	pTmp->SetName();
	pTmp->SetAge();
	pTmp->SetGender();
	
	
	while (true)
	{
		std::cout << "이대로 회원가입을 하시겠습니가? 1. 확인  2. 취소  ";
		std::cin >> nTmp;
		if (std::cin.fail() || nTmp>2 ||  nTmp<1)
		{
			std::cout << "제대로 입력해주세요" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		if (nTmp == 2)
		{
			SAFE_DELETE(pTmp);
			return false;
		}
		
		m_LoginData.insert(Insert(strID, pTmp));
		break;
	}

	return true;
}
bool Login::FindID(std::string a_V) const
{

	if (m_LoginData.empty())
		return false;
	if (m_LoginData.find(a_V) == m_LoginData.end())
		return false;

	return true;
}

bool Login::UserLogin()
{
	if (m_LoginUser != nullptr)
	{
		std::cout << "이미 로그인 되있습니다." << std::endl;
		return false;
	}

		std::string tmp;
		std::cout << "아이디를 입력해 주세요 : ";
		std::cin >> tmp;

		if (FindID(tmp))
		{
			m_LoginUser = m_LoginData[tmp];
	

			std::cout << "패스워드를 입력해주세요 : ";
			std::cin >> tmp;

			if (tmp == m_LoginUser->GetData().m_strPW)
			{
				std::cout << "로그인 성공" << std::endl;
				return true;
			}
			m_LoginUser = nullptr;
			std::cout << "비밀번호가 다릅니다." << std::endl;
		}
		std::cout << "아이디가 존재하지 않습니다." << std::endl;

		return false;
}

User * Login::GetUser()
{
	if (m_LoginUser == nullptr)
		assert(false && "arg ERROR");
	return m_LoginUser;
}

void Login::UserLogout()
{
	m_LoginUser = nullptr;
}

