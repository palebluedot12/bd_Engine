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
    if (m_Texture == nullptr)
    {
        assert(false && "Texture NULL");
        return;
    }

    Transform* tr = GetOwner()->GetComponent<Transform>();
    Vector2 pos = tr->GetPosition();
    float rot = tr->GetRotation();
    Vector2 scale = tr->GetScale();

    ID2D1Bitmap* pBitmap = m_Texture->GetBitmap();
    if (pBitmap == nullptr)
    {
        assert(false && "Bitmap NULL");
        return;
    }

    D2D1_SIZE_F originalSize = pBitmap->GetSize();
    renderSize = m_UseCustomSize ? m_Size : Vector2(originalSize.width, originalSize.height);

    // ���� ��ǥ�� ��ũ�� ��ǥ�� ��ȯ
    Vector2 screenPos = mainCamera->WorldToScreenPoint(pos);

    // ��ȯ ��� ����
    D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Identity();
    transform = transform * D2D1::Matrix3x2F::Translation(-renderSize.x / 2, -renderSize.y / 2);
    transform = transform * D2D1::Matrix3x2F::Scale(scale.x, scale.y);
    transform = transform * D2D1::Matrix3x2F::Rotation(rot);
    transform = transform * D2D1::Matrix3x2F::Translation(screenPos.x, screenPos.y);

    // ���� ��ȯ ��� ����
    D2D1::Matrix3x2F currentTransform;
    pRenderTarget->GetTransform(&currentTransform);

    // ���ο� ��ȯ ��� ����
    pRenderTarget->SetTransform(transform * currentTransform);

    // ��������Ʈ �׸���
    D2D1_RECT_F destinationRect = D2D1::RectF(0, 0, renderSize.x, renderSize.y);
    pRenderTarget->DrawBitmap(
        pBitmap,
        destinationRect,
        m_Alpha,
        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
        D2D1::RectF(0, 0, originalSize.width, originalSize.height)
    );

    // ���� ��ȯ ��ķ� ����
    pRenderTarget->SetTransform(currentTransform);
}