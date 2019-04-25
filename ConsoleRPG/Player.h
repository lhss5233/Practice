#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "Monster.h"
#include <string>
class Player
{

	int m_nHp = 0;
	int m_nNowHp = 0;
	int m_nArmorCount = 0;
	int m_nWeaponCount = 0;
	class	 Armor * m_Armor = nullptr;
	class Weapon * m_Weapon = nullptr;
public:
	Player();
	~Player();

	void EquipArmor();
	void EquipWeapon();
	void Init();

	int GetHp() const;
	int GetNowHp() const;
	int GetDamage() const;
	int GetDef() const;
	void Attack(Monster * a_M);
	
	void GetHealItem(int a_V);
	void Info() const;

};

