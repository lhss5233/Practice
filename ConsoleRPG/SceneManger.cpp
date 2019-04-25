#include "pch.h"
#include "Scene.h"
#include "SceneManger.h"

#include "IntroScene.h"

SceneManger::~SceneManger()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManger::Update()
{
	m_pNowScene->Update();
}

void SceneManger::Render()
{
	m_pNowScene->Render();
}

bool SceneManger::KeyInput(char c)
{
	eKey e = Getkey_withchar(c);

	if (e == eKey::None) { return false; }

	m_pNowScene->KeyInput(e);

	return true;
}

eKey SceneManger::Getkey_withchar(char c)
{
	switch (c)
	{
	case '1':	{return eKey::Start;	}break;
	case'w':	{ return eKey::Up;	}break;
	case 's':	{ return eKey::Down;}break;
	case 'a':	{ return eKey::Left;	}break;
	case 'd':	{ return eKey::Right;}break;
	default:	{ return eKey::None;	}break;
	}

	return eKey();
}

void SceneManger::ChangeScene(eScene a_eScene)
{
	if (m_pNowScene != nullptr &&
		m_pNowScene->GetScene() == a_eScene){return;	}
	SAFE_DELETE(m_pNowScene);

	switch (a_eScene)
	{
	case eScene::Intro: { m_pNowScene = new IntroScene(this); }break;
	case eScene::Stage1: {m_pNowScene = new GameScene(this); } break;
	default: assert(false && ""); break;
	}

	m_pNowScene->Init();
}


