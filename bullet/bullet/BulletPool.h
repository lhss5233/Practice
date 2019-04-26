#pragma once
class BulletPool
{
	std::vector<Bullet*> m_vBulletPool;
	int m_nMax = 0;
	int m_nIndex = 0;
	void Init();

public:
	BulletPool(const int& a_V) : m_nMax{ a_V } {};
	~BulletPool();

	int GetBulletMax()const;
	Bullet* GetBullet();
	void returnBullet(Bullet * a_V);
};

