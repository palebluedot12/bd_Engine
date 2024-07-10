#include "RenderManager.h"
#include <wincodec.h>
#include <iostream>
#include "ResourceManager.h"
#include "Transform.h"
#include "CommonInclude.h"

Camera* mainCamera = nullptr;

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	DiscardDeviceResources();
	if (pFactory) pFactory->Release();
	if (pWICFactory) pWICFactory->Release();
}

void RenderManager::Initialize(HWND hwnd)
{
	m_Hwnd = hwnd;
	//mHdc = GetDC(hwnd);
	HRESULT hr = CoInitialize(NULL);

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
	if (FAILED(hr)) {
		std::cerr << "Failed to create D2D factory. HRESULT: " << hr << std::endl;
		return;
	}

	if (SUCCEEDED(hr))
	{
		/*
		Direct3D 장치에 바인딩된 리소스를 만듭니다.
		Direct3D 장치가 손실된 경우(예: 디스플레이 변경, 원격, 비디오 카드 제거 등)
		리소스를 다시 생성해야 하는 경우를 대비하여 모두 여기에 중앙 집중화되어 있습니다.
		*/
		RECT rc;
		GetClientRect(hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top);

		// Create a Direct2D render target.
		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hwnd, size),
			&pRenderTarget);
	}

	if (SUCCEEDED(hr))
	{
		// WIC 팩토리 초기화
		hr = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&pWICFactory)
		);
	}


	if (FAILED(hr)) {
		std::cerr << "Failed to create WIC factory. HRESULT: " << hr << std::endl;
		return;
	}

	CreateDeviceResources();

}

void RenderManager::Render()
{

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

HRESULT RenderManager::CreateD2DBitmapFromFile(const WCHAR* szFilePath, ID2D1Bitmap** ppID2D1Bitmap)
{
	if (!pWICFactory)
	{
		return E_FAIL;
	}

	HRESULT hr;
	// Create a decoder
	IWICBitmapDecoder* pDecoder = NULL;
	IWICFormatConverter* pConverter = NULL;

	hr = pWICFactory->CreateDecoderFromFilename(
		szFilePath,                      // Image to be decoded
		NULL,                            // Do not prefer a particular vendor
		GENERIC_READ,                    // Desired read access to the file
		WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
		&pDecoder                        // Pointer to the decoder
	);

	// Retrieve the first frame of the image from the decoder
	IWICBitmapFrameDecode* pFrame = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pFrame);
	}

	//Step 3: Format convert the frame to 32bppPBGRA
	if (SUCCEEDED(hr))
	{
		hr = pWICFactory->CreateFormatConverter(&pConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pConverter->Initialize(
			pFrame,                          // Input bitmap to convert
			GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
			WICBitmapDitherTypeNone,         // Specified dither pattern
			NULL,                            // Specify a particular palette 
			0.f,                             // Alpha threshold
			WICBitmapPaletteTypeCustom       // Palette translation type
		);
	}

	if (SUCCEEDED(hr))
	{
		hr = GetRenderTarget()->CreateBitmapFromWicBitmap(pConverter, NULL, ppID2D1Bitmap);
	}

	// 파일을 사용할때마다 다시 만든다.
	if (pConverter)
		pConverter->Release();

	if (pDecoder)
		pDecoder->Release();

	if (pFrame)
		pFrame->Release();

	return hr;
}


//void RenderManager::UpdateAndRender()
//{
//	if (!mainCamera) return;
//
//	// 모든 객체 업데이트
//	for (auto& earth : m_Earths)
//	{
//		earth->Update();
//	}
//
//	// 카메라 컬링 수행
//	mainCamera->CullObjects(m_Earths);
//
//	// 실제 렌더링
//	pRenderTarget->BeginDraw();
//
//	const auto& visibleObjects = mainCamera->GetVisibleObjects();
//	for (const auto& obj : visibleObjects)
//	{
//		obj->Render(pRenderTarget);
//	}
//
//	RenderDebugInfo(visibleObjects.size());
//
//	pRenderTarget->EndDraw();
//}

void RenderManager::RenderDebugInfo(size_t visibleObjectCount)
{
	// VRAM 사용량 계산
	DXGI_QUERY_VIDEO_MEMORY_INFO memInfo = {};

	// VRAM 정보를 가져오는 코드...
	wchar_t debugText[256];
	swprintf_s(debugText, L"Visible Objects: %zu\nVRAM Usage: %d MB\nCamera pos: ",
		visibleObjectCount, memInfo.CurrentUsage / (1024 * 1024));

	ID2D1SolidColorBrush* pBrush;
	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pBrush);

	// 텍스트 포맷 생성 (한 번만 생성하고 재사용하는 것이 좋음)
	IDWriteFactory* pDWriteFactory;
	DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pDWriteFactory));
	IDWriteTextFormat* pTextFormat;
	pDWriteFactory->CreateTextFormat(L"Arial", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 20, L"en-us", &pTextFormat);

	pRenderTarget->DrawText(
		debugText,
		wcslen(debugText),
		pTextFormat,
		D2D1::RectF(10, 10, 200, 100),
		pBrush
	);

	pBrush->Release();
	pTextFormat->Release();
	pDWriteFactory->Release();
}
