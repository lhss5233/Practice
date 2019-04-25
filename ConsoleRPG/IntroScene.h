#pragma once

#include "Scene.h"
#include "SceneManger.h"


class IntroScene : public Scene
{
public:
	IntroScene(SceneManger * a_pParent);
	virtual ~IntroScene();

	virtual eScene GetScene() const;

	virtual void Init() override;
	virtual void Render() override;
	virtual void KeyInput(eKey a_eKey);

};

