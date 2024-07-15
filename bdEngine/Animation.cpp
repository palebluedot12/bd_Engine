#include "Animation.h"
#include "Transform.h"
#include "RenderManager.h"
#include "GameObject.h"
#include "Animator.h"

Animation::Animation()
	: Resource(eResourceType::Animation)
	, m_Animator(nullptr)
	, m_Texture(nullptr)
	, m_AnimationSheet{}
	, m_Index(-1)
	, m_Time(0.0f)
	, m_bComplete(false)
{
}

Animation::~Animation()
{
}

HRESULT Animation::Load(const std::wstring& path)
{
	return E_NOTIMPL;
}

void Animation::Update()
{
	if (m_bComplete)
		return;

	m_Time += Time::DeltaTime();

	if (m_AnimationSheet[m_Index].duration < m_Time)
	{
		m_Time = 0.0f;
		if (m_Index < m_AnimationSheet.size() - 1)
			m_Index++;
		else
			m_bComplete = true;
	}
}

void Animation::Render(ID2D1RenderTarget* pRenderTarget)
{
    if (m_Texture == nullptr || pRenderTarget == nullptr)
        return;

    GameObject* gameObj = m_Animator->GetOwner();
    Transform* tr = gameObj->GetComponent<Transform>();
    Vector2 pos = tr->GetPosition();
    float rot = tr->GetRotation();
    Vector2 scale = tr->GetScale();

    //if (mainCamera)
    //    pos = mainCamera->CalculatePosition(pos);

    Sprite sprite = m_AnimationSheet[m_Index];
    ID2D1Bitmap* pBitmap = m_Texture->GetBitmap();
    if (pBitmap == nullptr)
    {
        assert(false && "Bitmap NULL");
        return;
    }

    Vector2 screenPos = mainCamera->WorldToScreenPoint(pos);

    D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Identity();
    transform = transform * D2D1::Matrix3x2F::Translation(-sprite.size.x / 2, -sprite.size.y / 2);
    transform = transform * D2D1::Matrix3x2F::Scale(scale.x, scale.y);
    transform = transform * D2D1::Matrix3x2F::Rotation(rot);
    transform = transform * D2D1::Matrix3x2F::Translation(screenPos.x, screenPos.y);

    pRenderTarget->SetTransform(transform);

    D2D1_RECT_F srcRect = D2D1::RectF(
        sprite.leftTop.x, sprite.leftTop.y,
        sprite.leftTop.x + sprite.size.x, sprite.leftTop.y + sprite.size.y
    );

    D2D1_RECT_F destRect = D2D1::RectF(0, 0, sprite.size.x, sprite.size.y);

    pRenderTarget->DrawBitmap(pBitmap, destRect, 1.0f,
        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, srcRect);

    pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
}

void Animation::CreateAnimation(const std::wstring& name, Texture* spriteSheet
	, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
{
	m_Texture = spriteSheet;
	for (size_t i = 0; i < spriteLength; i++)
	{
		Sprite sprite = {};
		sprite.leftTop.x = leftTop.x + (size.x * i);
		sprite.leftTop.y = leftTop.y;
		sprite.size = size;
		sprite.offset = offset;
		sprite.duration = duration;

		m_AnimationSheet.push_back(sprite);
	}
}

void Animation::Reset()
{
	m_Time = 0.0f;
	m_Index = 0;
	m_bComplete = false;
}