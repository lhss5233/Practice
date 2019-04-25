#include "pch.h"

#include"GameScene.h"
#include "MiniMonster.h"


GameScene::GameScene(SceneManger * a_pParent) : Scene{ a_pParent } { }

GameScene::~GameScene(){}

eScene GameScene::GetScene() const { return eScene::Stage1; }

void GameScene::Init()
{
	srand((unsigned int)time(NULL));
	memcpy(m_NowStage, StageData.arrStage[m_nStage], sizeof(m_NowStage));
	
	for (int x = 0; x < StageX; x++)
	{
		for (int y = 0; y < StageY; y++)
		{
			if (m_NowStage[x][y] == 6)
			{
				Key s = std::make_pair(x, y);
				Monster * tmp = new MiniMonster();
				m_Monster.insert(std::pair<Key, Monster*>(s, tmp));
			}
			if (m_NowStage[x][y] == 3 || m_NowStage[x][y] == 5)
			{
				Key s = std::make_pair(x, y);
				m_key.insert(std::pair<int,Key>(m_NowStage[x][y], s));
			}
			if (m_NowStage[x][y] == 9)
				WinXY = std::make_pair(x, y);
		}
	}
}

void GameScene::Update()
{
	if (m_Player.GetNowHp() < 0)
	{
		SceneMng()->ChangeScene(eScene::Intro);
	}
	if (m_NowStage[WinXY.first][WinXY.second] == 10)
	{
		system("cls");
		std::cout << "==================== 1Stage Clear ====================" << std::endl;

		Sleep(5000);
			/*
		Clear();
		m_nStage++;
		Init();*/
	}
}
void GameScene::Render()
{
	int x, y;
	system("cls");
	for (x = 0; x < StageX; x++)
	{
		for (y = 0; y < StageY; y++)
		{
			switch (m_NowStage[x][y])
			{
			case 0: { std::cout << "  "; } break;
			case 1: { std::cout << "¢Ã"; } break;
			case 2: { std::cout << "¡Ù"; } break;
			case 3: { std::cout << "¡Ú"; } break;
			case 4: { std::cout << "¢Î"; } break;
			case 5: { std::cout << "¢Ï"; } break;
			case 6: 	{ std::cout << "¢¼"; } break;
			case 7: { std::cout << "¢¿"; } break;
			case 8: { std::cout << "¢À"; } break;
			case 9: { std::cout << "¢Á"; } break;
			case 10: { std::cout << "¢¾"; m_nX = x;  m_nY = y; } break;
			case 11: { std::cout << "¢Â"; } break;
			case 12: { std::cout << "¡å"; } break;
			default: 
				assert(false && "Map Data Error");
				break;
			}
		}
		std::cout << std::endl;
	}
	if (m_NowStage[m_nX][m_nY - 1] == 6)
	{
		Key k(m_nX, m_nY - 1);
		m_Monster[k]->Info();
	}
	else if (m_NowStage[m_nX][m_nY + 1] == 6)
	{
		Key k(m_nX, m_nY + 1);
		m_Monster[k]->Info();
	}
	else if (m_NowStage[m_nX - 1][m_nY] == 6)
	{
		Key k(m_nX -1, m_nY);
		m_Monster[k]->Info();
	}
	else if (m_NowStage[m_nX + 1][m_nY] == 6)
	{
		Key k(m_nX +1, m_nY);
		m_Monster[k]->Info();
	}

	
	StageData.MapInfo();
	m_Player.Info();
	StageData.gotoxy(0, StageX+1);
}

void GameScene::KeyInput(eKey a_eKey)
{
	int a_X = 0, a_Y = 0;
	switch (a_eKey)
	{
	case eKey::Left:
		a_Y = -1;
		break;
	case eKey::Up:
		a_X = -1;
		break;
	case eKey::Right:
		a_Y = 1;
		break;
	case eKey::Down:
		a_X = 1;
		break;
	default:
		break;
	}
	if (m_NowStage[m_nX + a_X][m_nY + a_Y] == 0 || m_NowStage[m_nX + a_X][m_nY + a_Y] == 9)
	{
		m_NowStage[m_nX][m_nY] = 0;
		m_NowStage[m_nX + a_X][m_nY + a_Y] = 10;
	}
	if (m_NowStage[m_nX + a_X][m_nY + a_Y] == 6)
	{
		if (m_Monster[std::pair<int, int>(m_nX + a_X, m_nY + a_Y)]->GetHP() > 0)
		{
			m_Player.Attack(m_Monster[std::pair<int, int>(m_nX + a_X, m_nY + a_Y)]);
		}
		else
		{
			m_NowStage[m_nX][m_nY] = 0;
			m_NowStage[m_nX + a_X][m_nY + a_Y] = 10;
		}
	}
	if (m_NowStage[m_nX + a_X][m_nY + a_Y] == 7 || m_NowStage[m_nX + a_X][m_nY + a_Y] == 8)
	{
		if (m_NowStage[m_nX + a_X][m_nY + a_Y] % 8)
			m_Player.GetHealItem(m_ITem.LowHeal);
		else
			m_Player.GetHealItem(m_ITem.Heal);

		m_NowStage[m_nX][m_nY] = 0;
		m_NowStage[m_nX + a_X][m_nY + a_Y] = 10;
	}
	if (m_NowStage[m_nX + a_X][m_nY + a_Y] == 11 || m_NowStage[m_nX + a_X][m_nY + a_Y] == 12)
	{
		if (m_NowStage[m_nX + a_X][m_nY + a_Y] % 12)
			m_Player.EquipWeapon();	
		else
			m_Player.EquipArmor();
		
		m_NowStage[m_nX][m_nY] = 0;
		m_NowStage[m_nX + a_X][m_nY + a_Y] = 10;
	}
	if (m_NowStage[m_nX + a_X][m_nY + a_Y] == 2 || m_NowStage[m_nX + a_X][m_nY + a_Y] == 4)
	{
		if (m_NowStage[m_nX + a_X][m_nY + a_Y] % 4)
			m_NowStage[m_key[3].first][m_key[3].second] = 0;
		else
			m_NowStage[m_key[5].first][m_key[5].second] = 0;

		m_NowStage[m_nX][m_nY] = 0;
		m_NowStage[m_nX + a_X][m_nY + a_Y] = 10;
	}
}
