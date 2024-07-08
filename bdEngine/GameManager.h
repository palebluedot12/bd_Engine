#pragma once
#include "CommonInclude.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Initialize(HWND hwnd);
	void Run();
	void Update();
	void LateUpdate();
	void Render();

	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }

private:
	UINT mWidth;
	UINT mHeight;
};

