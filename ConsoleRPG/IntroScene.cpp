#include "pch.h"

#include "Scene.h"
#include "SceneManger.h"



IntroScene::IntroScene(SceneManger * a_pParent) : Scene{ a_pParent } {};


IntroScene::~IntroScene()
{
}

eScene IntroScene::GetScene() const
{
	return eScene::Intro;
}

void IntroScene::Init() 
{
	Render();
}

void IntroScene::Render() 
{
	system("cls");
	std::cout << "======================================" << std::endl;
	std::cout << "ConsloeRPG를 시작합니다." << std::endl;
	std::cout << "게임을 시작하려면 숫자1을 종료하려면 q를 입력해주세요." << std::endl;
}

void IntroScene::KeyInput(eKey a_eKey)
{
	switch (a_eKey)
	{
	case eKey::Start: { m_refParent->ChangeScene(eScene::Stage1); }break;

	default:
		break;
	}
}


