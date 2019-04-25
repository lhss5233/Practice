#include "pch.h"
#include "Monster.h"


Monster::Monster(){}
Monster::~Monster(){}

void Monster::Info() const
{
	sMap::gotoxy(45, 9); std::cout << m_strName << std::endl;
	sMap::gotoxy(45, 10); std::cout << "체력 : "<< GetHP() << std::endl;
	sMap::gotoxy(45, 11); std::cout << "공격력 : "<< m_nDmg << std::endl;
	sMap::gotoxy(45, 12); std::cout << "방어력 : "<< m_nDef << std::endl;

}

void Monster::Battle(int a_V)
{
	m_nHp -= a_V - m_nDef;
}

int Monster::GetHP() const { return m_nHp; }
int Monster::GetDef() const { return m_nDef; }
int Monster::GetDmg() const { return m_nDmg; }
std::string Monster::GetName() const{return m_strName;}

