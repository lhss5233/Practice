#pragma once



class SceneManger
{

	enum CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR };
#pragma region SINGLETON

	static inline SceneManger * m_pInstance = nullptr;

	SceneManger() = default;
	~SceneManger();

	SceneManger  operator=(SceneManger&) = delete;
	SceneManger(SceneManger &&) = delete;
	SceneManger(const SceneManger&) = delete;
public:
	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManger();
		}
	}
	static SceneManger*  GetInstance()
	{
		return m_pInstance;
	}
	static void ReleaseInstance() 
	{ SAFE_DELETE(m_pInstance);}

#pragma endregion

public:
	void Init()
	{
		setcursortype(NOCURSOR);
		ChangeScene(eScene::Intro);
	}
	void Update();
	void Render();
	
	bool KeyInput(char c);

	static eKey Getkey_withchar(char c);
	void ChangeScene(eScene a_eScene);
	
	void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
private:

	class Scene * m_pNowScene = nullptr;
};

#define InitSceneMng()		{SceneManger::CreateInstance(); SceneManger::GetInstance()->Init();}
#define SceneMng()			(SceneManger::GetInstance())
#define ReleaseSceneMng()	(SceneManger::ReleaseInstance())
