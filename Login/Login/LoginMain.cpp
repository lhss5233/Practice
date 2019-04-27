// Login.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

using namespace std;




int main()
{
	LOGIN_INTI(); //초기값: 아뒤비번이름나이성별힌트
	
	//---------------------- //일반 로그인--------------------------
	if (LoginMng()->UserLogin())
	{
		cout << LoginMng()->GetUser()->GetData().m_strPW << endl;
		cout << LoginMng()->GetUser()->GetData().m_nAge << endl;
		cout << LoginMng()->GetUser()->GetData().m_strName << endl;

		LoginMng()->UserLogout();
	}
	
	else
	{
		//로그인 실패하면 안됨
		cout << LoginMng()->GetUser()->GetData().m_strPW << endl;
		cout << LoginMng()->GetUser()->GetData().m_nAge << endl;
		cout << LoginMng()->GetUser()->GetData().m_strName << endl;
		LoginMng()->UserLogout();

	}
	getchar();
	system("cls");
//------------------//로그인 후 개인정보 변경--------------------------------------------------------
	if (LoginMng()->UserLogin()) 
	{
		LoginMng()->UserLogin(); //로그인 후 로그인 또 되는지?

		cout << LoginMng()->GetUser()->GetData().m_strPW << endl;
		cout << LoginMng()->GetUser()->GetData().m_nAge << endl;
		cout << LoginMng()->GetUser()->GetData().m_strName << endl;

		LoginMng()->GetUser()->ChangeInfo();

		cout << LoginMng()->GetUser()->GetData().m_strPW << endl;
		cout << LoginMng()->GetUser()->GetData().m_nAge << endl;
		cout << LoginMng()->GetUser()->GetData().m_strName << endl;

		LoginMng()->UserLogout();
	}
	//---------------//회원가입 후 로그인----------------------------------------------------
	getchar();
	system("cls");
	LoginMng()->SignID(); 
	if (LoginMng()->UserLogin())
	{

		cout << LoginMng()->GetUser()->GetData().m_strPW << endl;
		cout << LoginMng()->GetUser()->GetData().m_nAge << endl;
		cout << LoginMng()->GetUser()->GetData().m_strName << endl;
		LoginMng()->UserLogout();

	}

	ReleaseLoginMng(); //new한거 삭제~~~~
}

