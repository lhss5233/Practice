#pragma once
class Monster
{
protected:
	int m_nHp = 0;
	int m_nDef = 0;
	int m_nDmg = 0;
	std::string m_strName = "";
public:
	Monster();
	~Monster();

	
	virtual bool Skill() const = 0;

	void Info() const;
	void Battle(int a_V);
	
	int GetHP() const;
	int GetDef() const;
	int GetDmg() const;
	std::string GetName() const;
};
