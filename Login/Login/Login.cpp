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
	m_LoginData["test1"]->SetData("1q2w3e4r", "�̸���", 20, LoginData::Gender::Male);
	m_LoginData.insert(Insert("test2", new User()));
	m_LoginData["test2"]->SetData("q1w2e3r4", "������", 20, LoginData::Gender::Female);
}

bool Login::SignID()
{
	int nTmp = 0;
	std::string strID;
	std::cout << "ȸ�� ������ �����մϴ�." << std::endl;
	std::cout << "���̵�� ��й�ȣ�� �Է��ؼ���" << std::endl;
	while (true)
	{
		std::cout << "���̵� : "; std::cin >> strID;
		if (FindID(strID))
			std::cout << "�ش� ���̵� �̹� ���� �մϴ�." << std::endl;
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
		std::cout << "�̴�� ȸ�������� �Ͻðڽ��ϰ�? 1. Ȯ��  2. ���  ";
		std::cin >> nTmp;
		if (std::cin.fail() || nTmp>2 ||  nTmp<1)
		{
			std::cout << "����� �Է����ּ���" << std::endl;
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
		std::cout << "�̹� �α��� ���ֽ��ϴ�." << std::endl;
		return false;
	}

		std::string tmp;
		std::cout << "���̵� �Է��� �ּ��� : ";
		std::cin >> tmp;

		if (FindID(tmp))
		{
			m_LoginUser = m_LoginData[tmp];
	

			std::cout << "�н����带 �Է����ּ��� : ";
			std::cin >> tmp;

			if (tmp == m_LoginUser->GetData().m_strPW)
			{
				std::cout << "�α��� ����" << std::endl;
				return true;
			}
			m_LoginUser = nullptr;
			std::cout << "��й�ȣ�� �ٸ��ϴ�." << std::endl;
		}
		std::cout << "���̵� �������� �ʽ��ϴ�." << std::endl;

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

