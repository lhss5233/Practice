#include "pch.h"
#include "Fist.h"


Fist::Fist()
{
	m_nCrit = 2;
	m_nDamage = 7;
	m_strName = "аж╦т";
	m_eWeapon = eEquip::NFist;
}


Fist::~Fist() {}
bool Fist::WeaponSkill() const
{
	return ((rand() % 100 + 1) == 1);
}


