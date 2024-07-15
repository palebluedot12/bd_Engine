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
    //Vector2 size = tr->GetScale() * 500; // Scale size by 100

	if (mainCamera)
		pos = mainCamera->CalculatePosition(pos);



    D2D1_RECT_F rect = D2D1::RectF(
        pos.x + offset.x,
        pos.y + offset.y,
        pos.x + offset.x + GetOwner()->GetComponent<SpriteRenderer>()->GetSize().x,
        pos.y + offset.y + GetOwner()->GetComponent<SpriteRenderer>()->GetSize().y
    );

    // Create a green brush
    ID2D1SolidColorBrush* pBrush;
    pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &pBrush);

    // Draw the rectangle
    pRenderTarget->DrawRectangle(rect, pBrush);

    // Release the brush
    pBrush->Release();


    //Vector2 screenPos = mainCamera->WorldToScreenPoint(pos);

    //D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Identity();
    //transform = transform * D2D1::Matrix3x2F::Translation(-sprite.size.x / 2, -sprite.size.y / 2);
    //transform = transform * D2D1::Matrix3x2F::Scale(scale.x, scale.y);
    //transform = transform * D2D1::Matrix3x2F::Rotation(rot);
    //transform = transform * D2D1::Matrix3x2F::Translation(screenPos.x, screenPos.y);

    //pRenderTarget->SetTransform(transform);

    //D2D1_RECT_F srcRect = D2D1::RectF(
    //    sprite.leftTop.x, sprite.leftTop.y,
    //    sprite.leftTop.x + sprite.size.x, sprite.leftTop.y + sprite.size.y
    //);

    //D2D1_RECT_F destRect = D2D1::RectF(0, 0, sprite.size.x, sprite.size.y);

    //pRenderTarget->DrawBitmap(pBitmap, destRect, 1.0f,
    //    D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, srcRect);

    //pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());



}