#include "GameManager.h"


// DC ��� D2D �޼ҵ��� ��ü
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
