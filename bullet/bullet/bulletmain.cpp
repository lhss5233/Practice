// bullet.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

using namespace std;

int main()
{
	Player _player;
	//기본, 쿨러X, 강선강화X, 확장탄창 X
	for (int i = 0; i < 20; i++) 
	{
		_player.Bang();
	}
	_player.Reload();
	for (int i = 0; i < 20; i++)
	{
		_player.Bang();
	}
	
	_player.Reload();
	getchar();


	// 쿨러O , 강선강화O, 확장탄창O
	_player.incooler(); 
	_player.inreinforce();
	_player.inExtended_magazine();
	for (int i = 0; i < 20; i++) 
	{
		_player.Bang();
	}
	_player.Bang();
	_player.Reload();
	for (int i = 0; i < 20; i++)
	{
		_player.Bang();
	}
	_player.Bang();
	_player.Reload();
	for (int i = 0; i < 20; i++)
	{
		_player.Bang();
	}

	getchar();

	for (int i = 0; i < 10; i++)
	{
		_player.Bang();
	}
	_player.Reload();
	//강화,확탄,쿨러 헤제
	_player.uncooler();
	_player.unreinforce();
	_player.unExtended_magazine();
	for (int i = 0; i < 30; i++)
	{
		_player.Bang();
	}

}
