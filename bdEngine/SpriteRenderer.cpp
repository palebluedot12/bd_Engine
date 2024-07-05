#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "RenderManager.h"
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
	//assert(m_pBitmap != nullptr);
	////pRenderTarget->SetTransform(m_WorldTransform);
	//pRenderTarget->DrawBitmap(m_pBitmap);

    if (m_Texture == nullptr)
    {
        assert(false && "Texture is not set");
        return;
    }

    Transform* tr = GetOwner()->GetComponent<Transform>();
    Vector2 pos = tr->GetPosition();

    ID2D1Bitmap* pBitmap = m_Texture->GetBitmap();
    if (pBitmap == nullptr)
    {
        assert(false && "Bitmap is null");
        return;
    }

    D2D1_SIZE_F originalSize = pBitmap->GetSize();
    D2D1_RECT_F destinationRect = D2D1::RectF(
        pos.x, 
        pos.y, 
        pos.x + originalSize.width, 
        pos.y + originalSize.height
    );

    pRenderTarget->DrawBitmap(
        pBitmap,
        destinationRect,
        1.0f,  // Opacity
        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
        D2D1::RectF(0, 0, originalSize.width, originalSize.height)  // Source rectangle
    );
}