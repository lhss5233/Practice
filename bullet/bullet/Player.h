#pragma once

class Player
{
	enum eBullet{
		MAX = 10,
	};

	std::vector<Bullet*> m_Clip;
	BulletPool * m_pPool;
	void Init();
public:
	Player();
	~Player();
};

