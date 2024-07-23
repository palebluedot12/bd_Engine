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
	void Destroy();

	UINT GetWidth() { return m_Width; }
	UINT GetHeight() { return m_Height; }

private:
	UINT m_Width = 1600;
	UINT m_Height = 900;
};

