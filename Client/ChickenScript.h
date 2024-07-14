#pragma once
#include "..\\bdEngine\\Script.h"
#include "..\\bdEngine\\Camera.h"
#include "Player.h"
#include "PlayScene.h"

class ChickenScript : public Script
{
public:

	// FSM
	enum class eState
	{
		SitDown,
		Chase,
		Attack
	};


	ChickenScript();
	~ChickenScript();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetCamera(Camera* camera) { m_Camera = camera; }
	void SetPlayScene(PlayScene* playScene) { m_PlayScene = playScene; }

private:
	void SitDown();
	void Move();
	void UpdateState();
	void Chase();
	void Attack();



private:
	Camera* m_Camera;
	eState m_State;
	class Animator* m_Animator;
	PlayScene* m_PlayScene;
	Player* m_Player;
	float m_AttackTimer;

};

