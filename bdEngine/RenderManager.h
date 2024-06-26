#pragma once
#include <d2d1.h>
#include "GameObject.h"

// 싱글톤으로 바꾸기
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void Initialize(HWND hwnd);
	void Render();
private:
	HWND m_Hwnd;
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;

	GameObject m_Player; // 이거 Scene에서 들고있을거임

	void CreateDeviceResources();
	void DiscardDeviceResources();
};

