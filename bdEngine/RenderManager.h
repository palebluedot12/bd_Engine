#pragma once
#include <d2d1.h>
#include "GameObject.h"

// �̱������� �ٲٱ�
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

	GameObject m_Player; // �̰� Scene���� �����������

	void CreateDeviceResources();
	void DiscardDeviceResources();
};

