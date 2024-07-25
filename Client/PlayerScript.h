#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Movement.h"
#include "..\\bdEngine\\Animator.h"
#include "FSM.h"
#include <memory>

// FSM
enum class PlayerStateType
{
	SitDown,
	Walk,
	Sleep,
	Attack
};

class PlayerState;

class PlayerScript : public Script
{
public:

	PlayerScript();
	~PlayerScript();

	void Start();
	//void Initialize();
	void Update() override;
	//void LateUpdate() override;
	//void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetCamera(Camera* camera) { m_Camera = camera; }

	void OnCollisionEnter(class Collider* other);
	void OnCollisionStay(class Collider* other);
	void OnCollisionExit(class Collider* other);

	Animator* GetAnimator() { return m_Animator; }
	Movement* GetMovement() { return m_Movement; }

	using State = PlayerStateType;


private:
	void UpdateState();

	//void SitDown();
	//void Move();
	//void Start();

private:
	Camera* m_Camera;
	State m_State;
	class Animator* m_Animator;
	Movement* m_Movement;
	PlayerState* m_CurrentState;
	std::map<State, std::unique_ptr<PlayerState>> m_States;

public:
	BoxCollider2D* co;                    // 렉트콜라이더 컴포넌트
};