#pragma once
#include "Resource.h"
#include "Texture.h"

class Animation : public Resource
{
public:
	struct Sprite
	{
		Vector2 leftTop;
		Vector2 size;
		Vector2 offset;
		float duration;

		Sprite()
			: leftTop(Vector2::Zero)
			, size(Vector2::Zero)
			, offset(Vector2::Zero)
			, duration(0.0f)
		{

		}
	};

	Animation();
	~Animation();

	HRESULT Load(const std::wstring& path) override;

	void Update();
	void Render(ID2D1RenderTarget* pRenderTarget);

	void CreateAnimation(const std::wstring& name
		, Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 sizei
		, Vector2 offset
		, UINT spriteLegth
		, float duration);

	void Reset();

	bool IsComplete() { return m_bComplete; }
	void SetAnimator(class Animator* animator) { m_Animator = animator; }


private:
	class Animator* m_Animator;					// ������ ������� �ִϸ�����
	Texture* m_Texture;

	std::vector<Sprite> m_AnimationSheet;
	int m_Index;
	float m_Time;
	bool m_bComplete;							// ������ �� ���Ҵ°�?
};