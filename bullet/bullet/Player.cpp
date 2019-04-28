#include "pch.h"
#include "Player.h"

void Player::Init()
{
	m_pPool = new BulletPool(MAX);

	m_Clip.resize(m_pPool->GetBulletMax());
	m_nMax = m_Clip.size();
	for (auto& i : m_Clip)
	{
		i = m_pPool->GetBullet();

	//	std::cout << i->m_nDmg << " " << i->m_nHeat << " " << i->m_nSpeed << std::endl;
	}
}

void Player::Reload()
{
	m_nIndex = m_nMax-1;
	
	while (m_nIndex != -1)
	{
		if (m_Clip[m_nIndex] == nullptr)
			m_Clip[m_nIndex] = m_pPool->GetBullet();

		--m_nIndex;
	}
	m_nIndex = 0;
}

void Player::Bang()
{
	if (reinforce)
	{
		if (IsOverHeat())
			return;
		if (extended_magazine)
		{
			if (m_nIndex >= m_nMax)
			{
				std::cout << "�Ѿ��� �����մϴ�. ���������ּ���." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "�ѿ����" << std::endl;
		}
		else
		{
			if (m_nIndex >= (m_nMax-10))
			{
				std::cout << "�Ѿ��� �����մϴ�. ���������ּ���." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "�ѿ����" << std::endl;
		}
	}
	else
	{
		if (IsOverHeat())
			return;
		if (extended_magazine)
		{
			if (m_nIndex >= m_nMax)
			{
				std::cout << "�Ѿ��� �����մϴ�. ���������ּ���." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "��" << std::endl;
		}
		else
		{
			if (m_nIndex >= (m_nMax-10))
			{
				std::cout << "�Ѿ��� �����մϴ�. ���������ּ���." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "��" << std::endl;
		}

	}
}

bool Player::IsOverHeat()
{
	if (iscooler)
	{
		if (m_bHeatFlag == false && m_nHeat >= m_nMaxHeat*2)
			m_bHeatFlag = true;

		if (m_bHeatFlag)
		{
			if (m_nHeat <= 0)
				m_bHeatFlag = false;
			std::cout << "���������Դϴ�. " << std::endl;
			m_nHeat -= 20;
		}
	}
	else
	{
		if (m_bHeatFlag == false && m_nHeat >= m_nMaxHeat)
			m_bHeatFlag = true;

		if (m_bHeatFlag)
		{
			if (m_nHeat <= 0)
				m_bHeatFlag = false;
			std::cout << "���������Դϴ�. " << std::endl;
			m_nHeat -= 10;
		}
	}

	
		

	return m_bHeatFlag;
}

void Player::incooler()
{
	std::cout << "������ " << std::endl;
	iscooler = true;
}
void Player::uncooler()
{
	std::cout << "������ " << std::endl;
	iscooler = false;
}
void Player::inreinforce()
{
	std::cout << "������ȭ" << std::endl;
	reinforce = true;
}
void Player::unreinforce()
{
	std::cout << "������ȭ����" << std::endl;
	reinforce = false;
}

void Player::inExtended_magazine()
{
	std::cout << "Ȯ��źâ����" << std::endl;
	extended_magazine = true;
}
void Player::unExtended_magazine()
{
	std::cout << "Ȯ��źâ����" << std::endl;
	extended_magazine = false;
}






Player::Player()
{
	Init();
}

Player::~Player()
{
	SAFE_DELETE(m_pPool);
}
