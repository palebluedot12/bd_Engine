#include "Texture.h"
#include "GameManager.h"
#include "RenderManager.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern GameManager application;

Texture::Texture()
	: Resource(eResourceType::Texture)
{
}

Texture::~Texture()
{
	if (m_pBitmap)
	{
		m_pBitmap->Release();
		m_pBitmap = nullptr;
	}
}
HRESULT Texture::Load(const std::wstring& path)
{
	HRESULT hr = RenderManager::Get()->CreateD2DBitmapFromFile(path.c_str(), &m_pBitmap);

	if (SUCCEEDED(hr))
	{
		D2D1_SIZE_F size = m_pBitmap->GetSize();
		m_Width = static_cast<UINT>(size.width);
		m_Height = static_cast<UINT>(size.height);
	}
	else
	{
		// 로드 실패 시 에러 처리
	}
	 
	return hr;
}