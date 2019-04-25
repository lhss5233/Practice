#include "pch.h"
#include "Weapon.h"

int Weapon::GetCrit() const{	return m_nCrit;}
int Weapon::GetDmg() const {return m_nDamage; }
eEquip Weapon::GetWeapon() const { return m_eWeapon; }
std::string Weapon::GetName() const { return m_strName; }
