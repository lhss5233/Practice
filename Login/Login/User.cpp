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
		std::cout << "�̸��� �Է��� �ּ��� (2���� �̻� ������� �ѱ۸� Ȥ�� 4���� �̻� ����) :  ";
		std::cin >> Tmp;
		if (Tmp.length() < 4 || Tmp[0] == ' ' || Tmp[1] == ' ')
			std::cout << "�߸��Է��ϼ̽��ϴ�." << std::endl;
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
		std::cout << "���� : 1. ����  2.����   "; std::cin >> CGender;
		switch (CGender)
		{
		case '1': { m_nLoginData.m_eGender = LoginData::Gender::Male; return; }break;
		case '2': {  m_nLoginData.m_eGender = LoginData::Gender::Female; return; }break;
		default:
			std::cout << "�߸��� �Է��Դϴ� " << std::endl;
			break;
		}
	}
}

void User::SetAge()
{
	int tmp = 0;
	while (true)
	{
		std::cout << "���� : ";  std::cin >> tmp;
		if (std::cin.fail())
		{
			std::cout << "���ڸ� �Է��� �ּ���" << std::endl;
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
	std::cout << "��й�ȣ : "; std::cin >> m_nLoginData.m_strPW;
		std::cout << "��й�ȣ ��Ȯ�� : "; std::cin >> Tmp;
		if (m_nLoginData.m_strPW == Tmp)
		{
			break;
		}
		else
			std::cout << "��й�ȣ�� �ٸ��ϴ�. �ٽ� �Է��� �ּ���. " << std::endl;

	}
}


void User::ChangeInfo()
{
	std::string tmp;
	std::cout << "��й�ȣ�� �Է����ּ��� : "; std::cin >> tmp;
	if (m_nLoginData.m_strPW != tmp)
	{
		std::cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << std::endl;
		return;
	}
	SetGender();
	SetAge();
	SetName();
}
void User::SetHint()
{
	std::string tmp;
	std::cout << "��й�ȣ�� ��Ʈ...." << std::endl;
	std::cout << "����� ������ �ʵ��б���? : ";
	std::cin >> tmp;
	m_nLoginData.m_PWHint = tmp;

}
bool User::Find_PW()
{
	std::string tmp;
	std::cout << "��й�ȣ�� ��Ʈ�� �Է��ϼ���.." << std::endl;
	std::cout << "����� ������ �ʵ��б���? : ";
	for (int i = 3; i >= 0; i--)
	{
		std::cin >> tmp;

		if (tmp == m_nLoginData.m_PWHint)
		{
			std::cout << "�����Դϴ�. ����� ��й�ȣ�� :";
			std::cout << LoginMng()->GetUser()->GetData().m_strPW << std::endl;
			std::cout << "�Դϴ�." << std::endl;
			return true;
		}
		else if (i == 0)
		{
			std::cout << "Ƚ�� �ʰ�" << std::endl;
			return false;
		}
		else
		{
			std::cout << "Ʋ�Ƚ��ϴ�. �ٽ��غ����� ���� Ƚ�� :" <<i<<std::endl;
		}
	}
	


}