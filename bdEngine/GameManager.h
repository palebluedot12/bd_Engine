#pragma once
#include "CommonInclude.h"

class GameManager
{
public:
	void Initialize(HWND hwnd);
	void Run();
	void Update();
	void LateUpdate();
	void Render();

private:
	HWND mHwnd;
	HDC mHdc;
};

