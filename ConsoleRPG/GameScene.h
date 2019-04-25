#pragma once
#include "Scene.h"
#include "SceneManger.h"
#include "Player.h"


class GameScene :
	public Scene
{
	int m_nX = 0;
	int m_nY = 0;
	using Key =  std::pair<int, int>;
	std::map<Key,class Monster*> m_Monster;
	std::map<int,Key> m_key;
	Player m_Player;
	HealItem m_ITem;
	sMap StageData;
	Key WinXY;
	int m_nStage = 0;
	
	int m_NowStage[StageX][StageY];

public:
	GameScene(SceneManger * a_pParent);
	virtual ~GameScene();

	virtual eScene GetScene()const;

	virtual void Init(); 

	virtual void Update();
	virtual void Render();

	virtual void KeyInput(eKey a_eKey);

	void Clear();
};

