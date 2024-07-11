#include "BoxCollider2D.h"
#include "Transform.h"
#include "GameObject.h"
#include "RenderManager.h"
#include "Camera.h"


BoxCollider2D::BoxCollider2D()
	: Collider(eColliderType::Rect2D)
{
}
BoxCollider2D::~BoxCollider2D()
{
}
void BoxCollider2D::Initialize()
{
}
void BoxCollider2D::Update()
{
}
void BoxCollider2D::LateUpdate()
{
}
void BoxCollider2D::Render(ID2D1RenderTarget* pRenderTarget)
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();
    Vector2 offset = GetOffset();
    //Vector2 size = GetSize() * 500; // Scale size by 100

	if (mainCamera)
		pos = mainCamera->CalculatePosition(pos);

    // 하드코딩 교체
    D2D1_RECT_F rect = D2D1::RectF(
        pos.x + offset.x,
        pos.y + offset.y,
        pos.x + offset.x + 500.0f,
        pos.y + offset.y + 500.0f
    );

    // Create a green brush
    ID2D1SolidColorBrush* pBrush;
    pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pBrush);

    // Draw the rectangle
    pRenderTarget->DrawRectangle(rect, pBrush);

    // Release the brush
    pBrush->Release();
}