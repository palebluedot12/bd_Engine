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
	ID2D1Bitmap* GetBitmap() const { return m_pBitmap; }

	//eTextureType GetTextureType() { return m_Type; }
	// Gdiplus::Image* GetImage() { return mImage; }

private:
	//eTextureType m_Type;
	// Gdiplus::Image* mImage;
	ID2D1Bitmap* m_pBitmap = nullptr;
	UINT m_Width;
	UINT m_Height;
};