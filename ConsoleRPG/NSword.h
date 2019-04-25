#pragma once
#include "Weapon.h"
class NSword :
	public Weapon
{
public:
	NSword();
	~NSword();
	virtual bool WeaponSkill() const override;
};

