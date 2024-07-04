#include "SpriteRenderer.h"
#include <cassert>


SpriteRenderer::SpriteRenderer()
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Initialize()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(ID2D1RenderTarget* pRenderTarget)
{
	
	assert(m_pBitmap != nullptr);
	//pRenderTarget->SetTransform(m_WorldTransform);
	pRenderTarget->DrawBitmap(m_pBitmap);

}

void SpriteRenderer::ImageLoad(const std::wstring& path)
{
	// 어 떻 게 구 현 하 지 . . . 
}
