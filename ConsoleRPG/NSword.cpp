#include "pch.h"
#include "NSword.h"


NSword::NSword()
{
	m_nCrit = 2;
	m_nDamage = 8;
	m_strName = "��";
	m_eWeapon = eEquip::NFist;
}


NSword::~NSword()
{
}

bool NSword::WeaponSkill() const
{
	return  ((rand() % 100 + 1) <20);
}
