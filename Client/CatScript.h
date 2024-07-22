#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Transform.h"

class CatScript : public Script
{
public:
	enum class eState
	{
		SitDown,
		Walk,
		Sleep,
		LayDown,
		Attack,
	};

	enum class eDirection
	{
		Left,
		Right,
		Down,
		Up,
		End,
	};

	CatScript();
	~CatScript();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

private:
	void sitDown();
	void move();
	void layDown();

	void PlayWalkAnimationByDirection(eDirection dir);
	void translate(Transform* tr);

private:
	eState mState;
	class Animator* mAnimator;
	eDirection mDirection;
	float mTime;

};
