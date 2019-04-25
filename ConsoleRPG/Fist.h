#pragma once
#include "Weapon.h"
class Fist :
	public Weapon
{
public:
	Fist();
	~Fist();
	virtual bool WeaponSkill() const override;

};

