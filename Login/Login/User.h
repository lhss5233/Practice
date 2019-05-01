#pragma once
class User
{
	LoginData m_nLoginData;

public:
	User();
	~User();
	
	LoginData GetData() const;
	
	//프로젝트 처음생성할때 테스트용 데이터를 집어넣기위해 만듬
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

