#pragma once
#include <d2d1.h>
#include <dxgi1_4.h>
#include "GameObject.h"
#include <wincodec.h>
#include "Camera.h"

extern Camera* mainCamera;

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
	static ID2D1HwndRenderTarget* GetRenderTarget();

	void CreateRandomEarths(int count);
	void UpdateAndRender();
	static void RenderDebugInfo(size_t visibleObjectCount);
	static void UpdateVRAMUsage();


private:
	HWND m_Hwnd;
	ID2D1Factory* pFactory;
	static ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	IWICImagingFactory* pWICFactory;
	IDXGIFactory4* pDXGIFactory;

	static IDXGIAdapter3* m_pAdapter;
	static DXGI_QUERY_VIDEO_MEMORY_INFO m_MemInfo;
	static IDWriteFactory* m_pDWriteFactory;
	static IDWriteTextFormat* m_pTextFormat;

	GameObject m_Player; // 이거 Scene에서 들고있을거임

	void CreateDeviceResources();
	void DiscardDeviceResources();

};

