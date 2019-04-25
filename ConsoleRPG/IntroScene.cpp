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
	std::cout << "ConsloeRPG�� �����մϴ�." << std::endl;
	std::cout << "������ �����Ϸ��� ����1�� �����Ϸ��� q�� �Է����ּ���." << std::endl;
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


