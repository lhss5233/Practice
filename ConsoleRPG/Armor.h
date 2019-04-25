#pragma once
class Armor
{
protected:
	int m_nDef = 0;
	int m_nAddHp = 0;
	eEquip m_eArmor = eEquip::None;
	std::string m_strName = "";
public:
	Armor() {};
	~Armor() {};
	virtual bool ArmorSkill() const = 0;
	int GetDef()	const;
	int GetAddHp() const;
	eEquip GetArmor() const;
	std::string GetName() const;
};

