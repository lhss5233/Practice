#pragma once
#include "Armor.h"

class NormalArmor :
	public Armor
{
public:
	NormalArmor();
	~NormalArmor()=default;

	virtual bool ArmorSkill() const override;

};

