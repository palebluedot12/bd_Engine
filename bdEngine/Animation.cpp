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

    if (mainCamera)
        pos = mainCamera->CalculatePosition(pos);

    Sprite sprite = m_AnimationSheet[m_Index];

    // D2D 비트맵 가져오기
    ID2D1Bitmap* pBitmap = m_Texture->GetBitmap();
    if (pBitmap == nullptr)
    {
        assert(false && "Bitmap NULL");
        return;
    }

    //// 렌더링 상태 저장
    //pRenderTarget->SaveDrawingState(nullptr);

    // 변환 설정
    D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Translation(pos.x, pos.y) *
        D2D1::Matrix3x2F::Rotation(rot) *
        //D2D1::Matrix3x2F::Scale() *
        D2D1::Matrix3x2F::Translation(-pos.x, -pos.y);

    pRenderTarget->SetTransform(transform);

    // 소스 및 대상 사각형 정의
    D2D1_RECT_F srcRect = D2D1::RectF(
        sprite.leftTop.x, sprite.leftTop.y,
        sprite.leftTop.x + sprite.size.x, sprite.leftTop.y + sprite.size.y
    );

    D2D1_RECT_F destRect = D2D1::RectF(
        pos.x - (sprite.size.x / 2.0f) + sprite.offset.x,
        pos.y - (sprite.size.y / 2.0f) + sprite.offset.y,
        pos.x + (sprite.size.x / 2.0f) + sprite.offset.x,
        pos.y + (sprite.size.y / 2.0f) + sprite.offset.y
    );

    // 비트맵 그리기
    pRenderTarget->DrawBitmap(pBitmap, destRect, 1.0f,
        D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, srcRect);

    // 디버그용 사각형 그리기 (필요한 경우)
    // ID2D1SolidColorBrush* pBrush;
    // pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &pBrush);
    // pRenderTarget->DrawRectangle(D2D1::RectF(pos.x, pos.y, pos.x + 10, pos.y + 10), pBrush);
    // pBrush->Release();

    // 렌더링 상태 복원
    //pRenderTarget->RestoreDrawingState(nullptr);
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