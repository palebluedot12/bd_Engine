#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"
#include "..\\bdEngine\\BoxCollider2D.h"

class PlayerScript : public Script
{
public:

	// FSM
	enum class eState
	{
		SitDown,
		Walk,
		Sleep,
		Attack
	};


	PlayerScript();
	~PlayerScript();

	//void Initialize();
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetCamera(Camera* camera) { m_Camera = camera; }

private:
	void SitDown();
	void Move();
	void Start();

private:
	Camera* m_Camera;
	eState m_State;
	class Animator* m_Animator;

public:
	BoxCollider2D* co;                    // 렉트콜라이더 컴포넌트
};