#pragma once

#define SAFE_DELETE(x) { if( (x) != nullptr) { delete (x); (x) = nullptr;}}
#define SAFE_DELETE_ARR(x) { if( (x) != nullptr) { delete[] (x); (x) = nullptr;}}


struct LoginData
{
	enum class Gender
	{
		Male = 0,
		Female,
	};

	
	int m_nAge = 0;
	Gender m_eGender = Gender::Male;


	std::string	m_strPW = "";
	std::string	m_strName = "";
	std::string	m_strPhone = "";
};