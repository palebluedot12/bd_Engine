#include "Texture.h"
#include "GameManager.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern GameManager application;

Texture::Texture()
	: Resource(eResourceType::Texture)
{
}

Texture::~Texture()
{
}
HRESULT Texture::Load(const std::wstring& path)
{
	// 확장자 전까지
	std::wstring ext
		= path.substr(path.find_last_of(L".") + 1);

	//bmp 일때
	if (ext == L"bmp")
	{
		//m_Type = eTextureType::Bmp;
		//m_Bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
		//	, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		//if (m_Bitmap == nullptr)
		//	return S_FALSE;

		//BITMAP info = {};
		//GetObject(mBitmap, sizeof(BITMAP), &info);

		//m_Width = info.bmWidth;
		//m_Height = info.bmHeight;

		//HDC mainDC = application.GetHdc();
		//mHdc = CreateCompatibleDC(mainDC);

		//HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		//DeleteObject(oldBitmap);

	}
	else if (ext == L"png")
	{
		//m_Type = eTextureType::Png;
		//m_Image = Gdiplus::Image::FromFile(path.c_str());
		//if (mImage == nullptr)
		//	return S_FALSE;

		//m_Width = m_Image->GetWidth();
		//m_Height = m_Image->GetHeight();
	}

	return S_OK;
}