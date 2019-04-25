#pragma once
#include "Monster.h"

class MiniMonster
	: public Monster
{

public:
	MiniMonster();
	~MiniMonster();

	virtual bool Skill() const override;
};

