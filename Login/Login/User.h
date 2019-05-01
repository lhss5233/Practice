#pragma once
class User
{
	LoginData m_nLoginData;

public:
	User();
	~User();
	
	LoginData GetData() const;
	
	//������Ʈ ó�������Ҷ� �׽�Ʈ�� �����͸� ����ֱ����� ����
	void SetData(std::string a_PW, std::string a_Name, int a_Age,
		LoginData::Gender a_Gender, std::string a_Hint);

	void SetName();
	void SetGender();
	void SetAge();
	void SetPW();
	void SetHint();

	bool Find_PW();
	
	void ChangeInfo();
};

