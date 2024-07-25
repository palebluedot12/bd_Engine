#include "ChickenScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "PlayScene.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Collider.h"
#include <functional>
#include "ChickenScript.h"
#include "ChickenSitDownState.h"
#include "ChickenChaseState.h"
#include "ChickenAttackState.h"

ChickenScript::ChickenScript()
	: m_State(ChickenScript::State::SitDown)
	, m_AttackTimer(0.0f)

{
    m_StateMachine.SetOwner(this);
    m_StateMachine.AddState(State::SitDown, std::make_unique<ChickenSitDownState>());
    m_StateMachine.AddState(State::Chase, std::make_unique<ChickenChaseState>());
    m_StateMachine.AddState(State::Attack, std::make_unique<ChickenAttackState>());

    m_StateMachine.SetState(State::SitDown);
}

ChickenScript::~ChickenScript()
{
}

void ChickenScript::Start()
{
    m_Animator = gameObject->GetComponent<Animator>();
    co = gameObject->AddComponent<BoxCollider2D>();
    co->size = { 25, 25 };
    m_Movement = gameObject->AddComponent<Movement>();
    m_Movement->SetSpeed(70.0f);

    if (m_PlayScene)
    {
        m_Player = m_PlayScene->GetPlayer();
    }
}

void ChickenScript::Update()
{
    if (!m_Player)
        return;

    if (m_Animator == nullptr)
    {
        m_Animator = GetOwner()->GetComponent<Animator>();
    }

    m_StateMachine.Update();

}
