#pragma once

class Weapon
{
protected:
	int m_nDamage = 0;
	int m_nCrit = 0;
	eEquip m_eWeapon = eEquip::None;
	std::string m_strName = "";
public:
	Weapon() {};
	~Weapon() {};
	virtual bool WeaponSkill() const = 0;

	int GetCrit() const;
	int GetDmg() const;
	eEquip GetWeapon() const;
	std::string GetName() const;
};

