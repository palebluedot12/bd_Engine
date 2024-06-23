#include "GameManager.h"


// DC 대신 D2D 메소드들로 대체
void GameManager::Initialize(HWND hwnd)
{
	mHwnd = hwnd;
	mHdc = GetDC(hwnd);
}

void GameManager::Run()
{
	Update();
	LateUpdate();
	Render();
}

void GameManager::Update()
{
}

void GameManager::LateUpdate()
{
}

void GameManager::Render()
{
}
