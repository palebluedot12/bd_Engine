#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "RenderManager.h"
#include <cassert>


SpriteRenderer::SpriteRenderer()
    : Component(eComponentType::SpriteRenderer)
    , m_Size(100.0f, 100.0f)
    , m_UseCustomSize(false)

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
        assert(false && "Texture NULL");
        return;
    }

    Transform* tr = GetOwner()->GetComponent<Transform>();
    Vector2 pos = tr->GetPosition();
    float rot = tr->GetRotation();

    pos = mainCamera->CalculatePosition(pos);                   // 카메라 좌표 적용

    ID2D1Bitmap* pBitmap = m_Texture->GetBitmap();
    if (pBitmap == nullptr)
    {
        assert(false && "Bitmap NULL");
        return;
    }

    D2D1_SIZE_F originalSize = pBitmap->GetSize();
    Vector2 renderSize;

    if (m_UseCustomSize)
    {
        renderSize = m_Size;
    }
    else
    {
        renderSize = Vector2(originalSize.width, originalSize.height);
    }


    D2D1_RECT_F destinationRect = D2D1::RectF(
        pos.x,
        pos.y,
        pos.x + renderSize.x,
        pos.y + renderSize.y
    );

    D2D1::Matrix3x2F currentTransform;
    pRenderTarget->GetTransform(&currentTransform);

    pRenderTarget->SetTransform(mainCamera->GetViewMatrix() * currentTransform);

    pRenderTarget->DrawBitmap(
        pBitmap,
        destinationRect,
        m_Alpha,  // Opacity
        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
        D2D1::RectF(0, 0, originalSize.width, originalSize.height)  // Source rectangle
    );

    pRenderTarget->SetTransform(currentTransform);  // 원래 변환 행렬로 복원
}