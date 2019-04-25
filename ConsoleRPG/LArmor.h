#pragma once
#include "Armor.h"
class LArmor :
	public Armor
{
public:
	LArmor();
	~LArmor()= default;

	virtual bool ArmorSkill() const override;
};

