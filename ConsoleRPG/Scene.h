#pragma once

#include"SceneManger.h"
class Scene
{
public:
	Scene(SceneManger * a_pParent);
	virtual ~Scene();
	
	virtual eScene GetScene() const = 0;

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void KeyInput(eKey a_eKey);

public:
	class SceneManger * m_refParent = nullptr;
};


