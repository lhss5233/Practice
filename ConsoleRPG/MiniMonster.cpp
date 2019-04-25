#include "pch.h"
#include "MiniMonster.h"

MiniMonster::MiniMonster()
{
	m_nHp = 30;
	m_nDef = 2;
	m_nDmg = 4;
	m_strName = "°íºí¸°";
}

MiniMonster::~MiniMonster() {}
bool MiniMonster::Skill() const{ return false;}

