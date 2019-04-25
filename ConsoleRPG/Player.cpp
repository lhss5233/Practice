#include "pch.h"
#include "Player.h"
#include "Fist.h"
#include "NSword.h"
#include "NormalArmor.h"
#include "LArmor.h"

Player::Player(){Init();}


Player::~Player()
{
	SAFE_DELETE(m_Armor);
	SAFE_DELETE(m_Weapon);
}

void Player::EquipArmor()
{
	m_nArmorCount++;
	if (m_Armor != nullptr && m_nArmorCount == (int)m_Armor->GetArmor())
		return;

	if(m_Armor != nullptr)
		m_nHp -= m_Armor->GetAddHp();
	SAFE_DELETE(m_Armor);
	

	switch (m_nArmorCount)
	{
	case (int)eEquip::NArmor:
	{ 
		m_Armor = new NormalArmor(); 
		m_nHp += m_Armor->GetAddHp();
		m_nNowHp += m_Armor->GetAddHp(); 
	} break;
	case (int)eEquip::LArmor: 
	{ 
		m_Armor = new LArmor();
		m_nHp += m_Armor->GetAddHp(); 
		m_nNowHp += m_Armor->GetAddHp();
	} break;
	case (int)eEquip::SArmor: { }break;
	default:
		assert(false && "Item Index ERROR");
		break;
	}

}

void Player::EquipWeapon()
{
	m_nWeaponCount++;
	if (m_Weapon != nullptr && m_nWeaponCount == (int)m_Weapon->GetWeapon())
		return;

	SAFE_DELETE(m_Weapon);

	switch (m_nWeaponCount)
	{
	case (int)eEquip::NFist: { m_Weapon = new Fist(); } break;
	case (int)eEquip::NSword: {  m_Weapon = new NSword(); } break;
	case (int)eEquip::SSword: { }break;
	default:
		assert(false && "Item Index ERROR");
		break;
	}

}

void Player::Init()
{
	EquipWeapon();
	EquipArmor();
	m_nHp += 100 ;
	m_nNowHp = m_nHp;
}

int Player::GetHp() const			{ return m_nHp; }
int Player::GetNowHp() const	{ return m_nNowHp; }
int Player::GetDamage() const	{ return m_Weapon->GetDmg();}
int Player::GetDef() const		{ return m_Armor->GetDef(); }

void Player::Attack(Monster * a_M)
{
	int tmp = 1;
	if (rand() % 2)
	{
		if(m_Weapon->WeaponSkill())
			a_M->Battle(m_Weapon->GetDmg() * m_Weapon->GetCrit());
		else
			a_M->Battle(m_Weapon->GetDmg());

		if (a_M->GetHP() <= 0)
				return;
		if (m_Armor->ArmorSkill())
			tmp++;
		m_nNowHp -= a_M->GetDmg() - m_Armor->GetDef()*tmp;
	}
	else
	{

		if (m_Armor->ArmorSkill())
			tmp++;
		m_nNowHp -= a_M->GetDmg() - m_Armor->GetDef()*tmp;
		if (m_nNowHp < 0)
			return ;
		if (m_Weapon->WeaponSkill())
			a_M->Battle(m_Weapon->GetDmg() * m_Weapon->GetCrit());
		else
			a_M->Battle(m_Weapon->GetDmg());

	}
}

void Player::GetHealItem(int a_V)
{
	if (m_nNowHp + a_V > m_nHp)
		m_nNowHp = m_nHp;
	else
		m_nNowHp += a_V;
}

void Player::Info() const
{
	
	sMap::gotoxy(43, 2); std::cout << "체력: " << m_nNowHp << "/" << m_nHp << std::endl;
	sMap::gotoxy(43, 3); std::cout << "방어력 : " << m_Armor->GetDef() << std::endl;
	sMap::gotoxy(43, 4); std::cout << "공격력 : " << m_Weapon->GetDmg() << std::endl;
	sMap::gotoxy(43, 5); std::cout << "방어구 : " << m_Armor->GetName() << std::endl;
	sMap::gotoxy(43, 6); std::cout << "무기 : " << m_Weapon->GetName() << std::endl;
}
