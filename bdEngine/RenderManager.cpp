#include "RenderManager.h"
#include <iostream>
//#include <wincodec.h>
#include "ResourceManager.h"
#include "Transform.h"
//#include "CommonInclude.h"

Camera* mainCamera = nullptr;
ID2D1HwndRenderTarget* RenderManager::pRenderTarget = nullptr;
IDXGIAdapter3* RenderManager::m_pAdapter = nullptr;
DXGI_QUERY_VIDEO_MEMORY_INFO RenderManager::m_MemInfo = {};
IDWriteFactory* RenderManager::m_pDWriteFactory = nullptr;
IDWriteTextFormat* RenderManager::m_pTextFormat = nullptr;


RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	DiscardDeviceResources();
	if (pFactory) pFactory->Release();
	if (pWICFactory) pWICFactory->Release();
	if (m_pAdapter)
	{
		m_pAdapter->Release();
		m_pAdapter = nullptr;
	}
	if (m_pDWriteFactory) m_pDWriteFactory->Release();
	if (m_pTextFormat) m_pTextFormat->Release();
}

void RenderManager::Initialize(HWND hwnd)
{
	m_Hwnd = hwnd;
	HRESULT hr = CoInitialize(NULL);

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
	if (FAILED(hr)) {
		std::cerr << "Failed to create D2D factory. HRESULT: " << hr << std::endl;
		return;
	}

	if (SUCCEEDED(hr))
	{
		/*
		Direct3D ��ġ�� ���ε��� ���ҽ��� ����ϴ�.
		Direct3D ��ġ�� �սǵ� ���(��: ���÷��� ����, ����, ���� ī�� ���� ��)
		���ҽ��� �ٽ� �����ؾ� �ϴ� ��츦 ����Ͽ� ��� ���⿡ �߾� ����ȭ�Ǿ� �ֽ��ϴ�.
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
		// WIC ���丮 �ʱ�ȭ
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

	// TODO : VRAM ������� ���� ��ü ����. 
	if (SUCCEEDED(hr))
	{
		// Create DXGI factory
		hr = CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)&pDXGIFactory);
	}
	if (SUCCEEDED(hr))
	{
		pDXGIFactory->EnumAdapters(0, reinterpret_cast<IDXGIAdapter**>(&pDXGIAdapter));
	}
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

	// ������ ����Ҷ����� �ٽ� �����.
	if (pConverter)
		pConverter->Release();

	if (pDecoder)
		pDecoder->Release();

	if (pFrame)
		pFrame->Release();

	return hr;
}

ID2D1HwndRenderTarget* RenderManager::GetRenderTarget()
{
	return pRenderTarget;
}

void RenderManager::RenderDebugInfo(size_t visibleObjectCount, int vram)
{
	// VRAM ������ �������� �ڵ�...
	wchar_t debugText[256];
	swprintf_s(debugText, L"Visible Objects: %zu\nVRAM Usage : %d",
		visibleObjectCount, vram);

	ID2D1SolidColorBrush* pBrush;
	pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pBrush);

	// �ؽ�Ʈ ���� ���� (�� ���� �����ϰ� �����ϴ� ���� ����)
	IDWriteFactory* pDWriteFactory;
	DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&pDWriteFactory));
	IDWriteTextFormat* pTextFormat;
	pDWriteFactory->CreateTextFormat(L"Arial", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 30, L"en-us", &pTextFormat);

	pRenderTarget->DrawText(
		debugText,
		wcslen(debugText),
		pTextFormat,
		D2D1::RectF(10, 10, 400, 100),
		pBrush
	);

	pBrush->Release();
	//pTextFormat->Release();
	//pDWriteFactory->Release();
}


size_t RenderManager::GetUsedVRAM()
{
	DXGI_QUERY_VIDEO_MEMORY_INFO videoMemoryInfo;
	pDXGIAdapter->QueryVideoMemoryInfo(0, DXGI_MEMORY_SEGMENT_GROUP_LOCAL, &videoMemoryInfo);
	return videoMemoryInfo.CurrentUsage / 1024 / 1024;
}