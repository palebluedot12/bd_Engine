#include "GameManager.h"
#include <d2d1.h>

#pragma comment(lib, "d2d1")


GameManager::GameManager()
    : mHwnd(nullptr)
    , pFactory(nullptr)
    , pRenderTarget(nullptr)
    , pBrush(nullptr)
    , mSpeed(0)
{
}

GameManager::~GameManager()
{
    DiscardDeviceResources();
    if (pFactory) pFactory->Release();
}

// DC 대신 D2D 메소드들로 대체
void GameManager::Initialize(HWND hwnd)
{
	mHwnd = hwnd;
	//mHdc = GetDC(hwnd);
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
    CreateDeviceResources();

}

void GameManager::Run()
{
	Update();
	LateUpdate();
	Render();
}

void GameManager::Update()
{
    mSpeed += 1.0f;
}

void GameManager::LateUpdate()
{
}

void GameManager::Render()
{
    if (!pRenderTarget)
        CreateDeviceResources();

    pRenderTarget->BeginDraw();
    pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

    pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &pBrush);

    D2D1_RECT_F rectangle = D2D1::RectF(100.0f + mSpeed, 100.0f, 200.0f + mSpeed, 200.0f);
    pRenderTarget->FillRectangle(&rectangle, pBrush);

    pBrush->Release();

    HRESULT hr = pRenderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET)
    {
        DiscardDeviceResources();
    }
}

void GameManager::CreateDeviceResources()
{
    if (!pRenderTarget)
    {
        RECT rc;
        GetClientRect(mHwnd, &rc);

        D2D1_SIZE_U size = D2D1::SizeU(
            rc.right - rc.left,
            rc.bottom - rc.top
        );

        pFactory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(mHwnd, size),
            &pRenderTarget
        );
    }
}

void GameManager::DiscardDeviceResources()
{
    if (pRenderTarget) pRenderTarget->Release();
    if (pBrush) pBrush->Release();
    pRenderTarget = nullptr;
    pBrush = nullptr;
}
