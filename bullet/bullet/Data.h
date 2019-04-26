#pragma once


#define SAFE_DELETE(x) { if( (x) != nullptr) { delete (x); (x) = nullptr;}}
#define SAFE_DELETE_ARR(x) { if( (x) != nullptr) { delete[] (x); (x) = nullptr;}}




struct  Bullet
{
	Bullet() = default;
	Bullet(const int a_Heat, const int a_Dmg, const int a_Speed) :
		m_nHeat{ a_Heat }, m_nDmg{ a_Dmg }, m_nSpeed{ a_Speed }{};
	int m_nHeat = 5;
	int m_nDmg = 5;
	int m_nSpeed = 2;
};