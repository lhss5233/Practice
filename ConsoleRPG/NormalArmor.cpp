#include "pch.h"
#include "NormalArmor.h"



NormalArmor::NormalArmor()
{
	m_nDef = 2;
	m_nAddHp = 0;
	m_strName = "±âº»°©¿Ê";
	m_eArmor = eEquip::NArmor;
}


bool NormalArmor::ArmorSkill() const
{
	return ((rand() % 100 + 1) == 1);
}

