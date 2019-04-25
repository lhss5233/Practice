#include "pch.h"
#include "LArmor.h"


LArmor::LArmor()
{
	m_nDef = 3;
	m_nAddHp = 10;
	m_strName = "·¹´õ°©¿Ê";
	m_eArmor = eEquip::LArmor;
}

bool LArmor::ArmorSkill() const
{
	return ((rand() % 100 + 1) < 20) ;
}
