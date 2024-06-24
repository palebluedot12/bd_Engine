#pragma once
#include "CommonInclude.h"
#include <d2d1.h>

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

private:
	HWND mHwnd;
	//HDC mHdc;
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;

	float mSpeed;

	void CreateDeviceResources();
	void DiscardDeviceResources();
};

