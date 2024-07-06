#include "Texture.h"
#include "GameManager.h"
#include "RenderManager.h"

// �ش� ���������� �������� �˸��� Ű���� extern
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
		// �ε� ���� �� ���� ó��
	}
	 
	return hr;
}