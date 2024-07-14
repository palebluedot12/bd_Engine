#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"

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

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetCamera(Camera* camera) { m_Camera = camera; }

private:
	void SitDown();
	void Move();

private:
	Camera* m_Camera;
	eState m_State;
	class Animator* m_Animator;
};

