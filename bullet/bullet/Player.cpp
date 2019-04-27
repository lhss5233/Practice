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
	if (IsOverHeat())
		return;
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

bool Player::IsOverHeat()
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
	
		

	return m_bHeatFlag;
}

Player::Player()
{
	Init();
}

Player::~Player()
{
	SAFE_DELETE(m_pPool);
}
