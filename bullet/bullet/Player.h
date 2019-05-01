#pragma once

class Player
{

	class BulletPool * m_pPool = nullptr;

	enum eBullet
	{
		MAX = 20,
	};

	std::vector<Bullet*> m_Clip;
	int m_nMax = 0;
	int m_nIndex = 0;
	int m_nHeat = 0;
	int m_nMaxHeat = 100;
	bool m_bHeatFlag = false;

	bool iscooler = false;
	bool reinforce = false;
	bool extended_magazine = false;
public:
	Player();
	~Player();
	void Init();
	void Reload();
	void Bang();
	bool IsOverHeat();

	void incooler();
	void uncooler();

	void inreinforce();
	void unreinforce();

	void inExtended_magazine();
	void unExtended_magazine();


};

