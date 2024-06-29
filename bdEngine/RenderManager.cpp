#include "RenderManager.h"
#include <iostream>

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	DiscardDeviceResources();
	if (pFactory) pFactory->Release();
}

void RenderManager::Initialize(HWND hwnd)
{
	m_Hwnd = hwnd;
	//mHdc = GetDC(hwnd);
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
	if (FAILED(hr)) {
		std::cerr << "Failed to create D2D factory. HRESULT: " << hr << std::endl;
		return;
	}
	CreateDeviceResources();

	m_Player.SetPosition(0, 0);
}

void RenderManager::Render()
{
	if (!pRenderTarget)
		CreateDeviceResources();

	pRenderTarget->BeginDraw();
	pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &pBrush);

	D2D1_RECT_F rectangle = D2D1::RectF(100.0f, 100.0f, 200.0f, 200.0f);
	pRenderTarget->FillRectangle(&rectangle, pBrush);

	pBrush->Release();

	HRESULT hr = pRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		DiscardDeviceResources();
	}
}

void RenderManager::CreateDeviceResources()
{
	if (!pRenderTarget)
	{
		RECT rc;
		GetClientRect(m_Hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top
		);

		pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_Hwnd, size),
			&pRenderTarget
		);
	}
}

void RenderManager::DiscardDeviceResources()
{
	if (pRenderTarget) pRenderTarget->Release();
	if (pBrush) pBrush->Release();
	pRenderTarget = nullptr;
	pBrush = nullptr;
}
