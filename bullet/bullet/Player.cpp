#include "pch.h"
#include "Player.h"

void Player::Init()
{
	m_pPool = new BulletPool(MAX);
	m_Clip.resize(m_pPool->GetBulletMax);
	for (auto i : m_Clip)
	{
		i = m_pPool->GetBullet();
	}
}

Player::Player()
{
	Init();
}

Player::~Player()
{
	SAFE_DELETE(m_pPool);
}
