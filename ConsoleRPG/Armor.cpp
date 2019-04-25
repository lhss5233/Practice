#include "pch.h"
#include "Armor.h"

int Armor::GetDef() const{	return m_nDef;}
int Armor::GetAddHp() const { return m_nAddHp; }
eEquip Armor::GetArmor() const { return m_eArmor; }
std::string Armor::GetName() const { return m_strName; }
