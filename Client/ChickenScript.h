#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"
#include "Player.h"
#include "PlayScene.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Movement.h"
#include "FSM.h"

class ChickenScript : public Script
{
public:

	// FSM
	enum class State
	{
		SitDown,
		Chase,
		Attack
	};

	ChickenScript();
	~ChickenScript();

	//void Initialize() override;
	void Update() override;
	//void LateUpdate() override;
	//void Render(ID2D1RenderTarget* pRenderTarget) override;
	void Start();

	void SetCamera(Camera* camera) { m_Camera = camera; }
	void SetPlayScene(PlayScene* playScene) { m_PlayScene = playScene; }

private:
	void EnterSitDown();
	void UpdateSitDown();
	void ExitSitDown();

	void EnterChase();
	void UpdateChase();
	void ExitChase();

	void EnterAttack();
	void UpdateAttack();
	void ExitAttack();

	void OnAttackAnimationComplete();
	void UpdateState();

private:
	Camera* m_Camera;
	State m_State;
	class Animator* m_Animator;
	PlayScene* m_PlayScene;
	Player* m_Player;
	float m_AttackTimer;
	Movement* m_Movement;
	FSM<ChickenScript, State> m_StateMachine;
	Vector2 direction;

public:
	BoxCollider2D* co;
	Transform* tr;
};

