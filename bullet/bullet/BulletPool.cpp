#include "pch.h"
#include "BulletPool.h"


BulletPool::BulletPool(const int& a_V) : m_nMax{ a_V } {};

void BulletPool::Init()
{
	for (int i = 0; i < m_nMax; ++i)
	{
		m_vBulletPool.emplace_back(new Bullet());
	}
}

BulletPool::~BulletPool()
{
	for (int i = 0; i < m_vBulletPool.size(); ++i)
	{
		SAFE_DELETE(m_vBulletPool[i]);
	}
	m_vBulletPool.clear();
}

int BulletPool::GetBulletMax() const
{
	return m_nMax;
}

Bullet* BulletPool::GetBullet()
{
	Bullet * tmp = m_vBulletPool[m_nIndex];
	m_vBulletPool[m_nIndex++] = nullptr;
	return tmp;
}

void BulletPool::returnBullet(Bullet * a_V)
{
	if (m_nIndex / m_nMax)
		m_nIndex = 0;

	m_vBulletPool[m_nIndex] = a_V;
	m_nIndex++;
}
