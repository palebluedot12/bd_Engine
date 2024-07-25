#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"
#include "Player.h"
#include "PlayScene.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Movement.h"
#include "..\\bdEngine\\Animator.h"
#include "FSM.h"
#include <memory>

class ChickenState;

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

	void Start();
	//void Initialize() override;
	void Update() override;
	//void LateUpdate() override;
	//void Render(ID2D1RenderTarget* pRenderTarget) override;

	Animator* GetAnimator() { return m_Animator; }
	Movement* GetMovement() { return m_Movement; }
	Player* GetPlayer() { return m_Player; }
	void SetCamera(Camera* camera) { m_Camera = camera; }
	void SetPlayScene(PlayScene* playScene) { m_PlayScene = playScene; }

private:
	void UpdateState();

private:
	Camera* m_Camera;
	State m_State;
	Animator* m_Animator;
	PlayScene* m_PlayScene;
	Player* m_Player;
	float m_AttackTimer;
	Movement* m_Movement;
	Vector2 direction;

	ChickenState* m_CurrentState;
	std::map<State, std::unique_ptr<ChickenState>> m_States;

public:
	BoxCollider2D* co;
	Transform* tr;
};

