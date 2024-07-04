#pragma once
#include "Resource.h"

class Texture : public Resource
{
public:
	enum class eTextureType
	{
		Bmp,
		Png,
		None,
	};

	Texture();
	~Texture();

	virtual HRESULT Load(const std::wstring& path) override;

	UINT GetWidth() { return m_Width; }
	UINT GetHeight() { return m_Height; }
	ID2D1RenderTarget* GetRenderTarget() { return pRenderTarget; }
	eTextureType GetTextureType() { return m_Type; }
	// Gdiplus::Image* GetImage() { return mImage; }

private:
	eTextureType m_Type;
	// Gdiplus::Image* mImage;
	ID2D1Bitmap* m_pBitmap = nullptr;
	ID2D1RenderTarget* pRenderTarget;

	UINT m_Width;
	UINT m_Height;
};