#pragma once
#include <d2d1.h>
#include "GameObject.h"

// �̱������� �ٲٱ�
// D2DRenderer
class RenderManager
{
public:
	static RenderManager* Get()
	{
		static RenderManager renderer;
		return &renderer;
	}
public:
	RenderManager();
	~RenderManager();
	void Initialize(HWND hwnd);
	void Render();
	HRESULT CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap);
	ID2D1HwndRenderTarget* GetRenderTarget() { return pRenderTarget; }

private:
	HWND m_Hwnd;
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	
	// D2D1��Ʈ�� ������ ���� �̹��� ó�� �������̽�
	IWICImagingFactory* pWICFactory;

	
	GameObject m_Player; // �̰� Scene���� �����������

	void CreateDeviceResources();
	void DiscardDeviceResources();
};

