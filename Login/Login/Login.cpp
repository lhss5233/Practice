#include "pch.h"
#include "Login.h"


Login::Login()
{

	m_LoginData.insert(Insert("test1", new LoginData()));
	m_LoginData["test1"]->m_strPW = "1q2w3e4r";
	m_LoginData["test1"]->m_nAge = 20;
	m_LoginData["test1"]->m_strName = "�̸���";
	m_LoginData["test1"]->m_strPhone = "010-0000-0000";
	m_LoginData["test1"]->m_eGender = LoginData::Gender::Male;
	m_LoginData.insert(Insert("test2", new LoginData()));
	m_LoginData["test2"]->m_strPW = "q1w2e3r4";
	m_LoginData["test2"]->m_nAge = 20;
	m_LoginData["test2"]->m_strName = "������";
	m_LoginData["test2"]->m_strPhone = "010-0000-0001";
	m_LoginData["test2"]->m_eGender = LoginData::Gender::Female;
}


Login::~Login()
{
}

void Login::ChangeInfo()
{
}

bool Login::SignID()
{
	
	std::cout << "ȸ�� ������ �����մϴ�." << std::endl;
	std::cout << "���̵�� ��й�ȣ�� �Է��ؼ���" << std::endl;

	return true;
}

bool Login::FindID(std::string a_V)
{
	if (m_LoginData.empty())
		return true;
	if (m_LoginData.find(a_V) == m_LoginData.end())
		return false;

	return true;
}
