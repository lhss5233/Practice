#include "pch.h"
#include "User.h"


User::User()
{
}


User::~User()
{
}

LoginData User::GetData() const
{
	return m_nLoginData;
}

void User::SetData(std::string a_PW, std::string a_Name, int a_Age, LoginData::Gender a_Gender,std::string a_Hint)
{
	m_nLoginData.m_strPW = a_PW;
	m_nLoginData.m_strName = a_Name;
	m_nLoginData.m_nAge = a_Age;
	m_nLoginData.m_eGender = a_Gender;
	m_nLoginData.m_PWHint = a_Hint;
}

void User::SetName()
{
	std::string Tmp;
	while (true)
	{
		std::cout << "이름을 입력해 주세요 (2글자 이상 공백없이 한글만 혹은 4글자 이상 영문) :  ";
		std::cin >> Tmp;
		if (Tmp.length() < 4 || Tmp[0] == ' ' || Tmp[1] == ' ')
			std::cout << "잘못입력하셨습니다." << std::endl;
		else
			break;
	}
	m_nLoginData.m_strName = Tmp;
}

void User::SetGender()
{
	char CGender;

	while (true)
	{
		std::cout << "성별 : 1. 남자  2.여자   "; std::cin >> CGender;
		switch (CGender)
		{
		case '1': { m_nLoginData.m_eGender = LoginData::Gender::Male; return; }break;
		case '2': {  m_nLoginData.m_eGender = LoginData::Gender::Female; return; }break;
		default:
			std::cout << "잘못된 입력입니다 " << std::endl;
			break;
		}
	}
}

void User::SetAge()
{
	int tmp = 0;
	while (true)
	{
		std::cout << "나이 : ";  std::cin >> tmp;
		if (std::cin.fail())
		{
			std::cout << "숫자만 입력해 주세요" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		else
		{
			m_nLoginData.m_nAge = tmp;
			break;
		}
	}
}

void User::SetPW()
{
	std::string Tmp;
	while (true)
	{
	std::cout << "비밀번호 : "; std::cin >> m_nLoginData.m_strPW;
		std::cout << "비밀번호 재확인 : "; std::cin >> Tmp;
		if (m_nLoginData.m_strPW == Tmp)
		{
			break;
		}
		else
			std::cout << "비밀번호가 다릅니다. 다시 입력해 주세요. " << std::endl;

	}
}


void User::ChangeInfo()
{
	std::string tmp;
	std::cout << "비밀번호를 입력해주세요 : "; std::cin >> tmp;
	if (m_nLoginData.m_strPW != tmp)
	{
		std::cout << "비밀번호가 일치하지 않습니다." << std::endl;
		return;
	}
	SetGender();
	SetAge();
	SetName();
}
void User::SetHint()
{
	std::string tmp;
	std::cout << "비밀번호의 힌트...." << std::endl;
	std::cout << "당신이 졸업한 초등학교는? : ";
	std::cin >> tmp;
	m_nLoginData.m_PWHint = tmp;

}
bool User::Find_PW()
{
	std::string tmp;
	std::cout << "비밀번호의 힌트를 입력하세요.." << std::endl;
	std::cout << "당신이 졸업한 초등학교는? : ";
	for (int i = 3; i >= 0; i--)
	{
		std::cin >> tmp;

		if (tmp == m_nLoginData.m_PWHint)
		{
			std::cout << "정답입니다. 당신의 비밀번호는 :";
			std::cout << LoginMng()->GetUser()->GetData().m_strPW << std::endl;
			std::cout << "입니다." << std::endl;
			return true;
		}
		else if (i == 0)
		{
			std::cout << "횟수 초과" << std::endl;
			return false;
		}
		else
		{
			std::cout << "틀렸습니다. 다시해보세요 남은 횟수 :" <<i<<std::endl;
		}
	}
	


}