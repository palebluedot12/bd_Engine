#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

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
	HWND m_Hwnd;
	//HDC mHdc;
	//ID2D1Factory* pFactory;
	//ID2D1HwndRenderTarget* pRenderTarget;
	//ID2D1SolidColorBrush* pBrush;

	float m_Speed;

	GameObject m_Player; // Object는 Scene에서 들고 있는게..??

	void CreateDeviceResources();
	void DiscardDeviceResources();
};

