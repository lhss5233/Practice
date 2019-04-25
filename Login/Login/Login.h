#pragma once


class Login
{
	using Insert = std::pair<std::string, LoginData*>;

	std::map<std::string, LoginData*> m_LoginData;


	LoginData* m_LoginUser = nullptr;
	std::string m_strID = "";
	std::string m_strPW = "";

	
public:
	Login();
	~Login();

	void ChangeInfo();
	bool SignID();
	bool FindID(std::string a_V);
};

