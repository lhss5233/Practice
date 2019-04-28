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
				std::cout << "총알이 부족합니다. 재장전해주세요." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "뚜우우우왕" << std::endl;
		}
		else
		{
			if (m_nIndex >= (m_nMax-10))
			{
				std::cout << "총알이 부족합니다. 재장전해주세요." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "뚜우우우왕" << std::endl;
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
				std::cout << "총알이 부족합니다. 재장전해주세요." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "빵" << std::endl;
		}
		else
		{
			if (m_nIndex >= (m_nMax-10))
			{
				std::cout << "총알이 부족합니다. 재장전해주세요." << std::endl;;
				return;
			}
			m_nHeat += m_Clip[m_nIndex]->m_nHeat;

			m_pPool->returnBullet(m_Clip[m_nIndex]);
			m_Clip[m_nIndex++] = nullptr;

			std::cout << "빵" << std::endl;
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
			std::cout << "과열상태입니다. " << std::endl;
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
			std::cout << "과열상태입니다. " << std::endl;
			m_nHeat -= 10;
		}
	}

	
		

	return m_bHeatFlag;
}

void Player::incooler()
{
	std::cout << "쿨러장착 " << std::endl;
	iscooler = true;
}
void Player::uncooler()
{
	std::cout << "쿨러헤제 " << std::endl;
	iscooler = false;
}
void Player::inreinforce()
{
	std::cout << "강선강화" << std::endl;
	reinforce = true;
}
void Player::unreinforce()
{
	std::cout << "강선강화헤제" << std::endl;
	reinforce = false;
}

void Player::inExtended_magazine()
{
	std::cout << "확장탄창장착" << std::endl;
	extended_magazine = true;
}
void Player::unExtended_magazine()
{
	std::cout << "확장탄창헤제" << std::endl;
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
