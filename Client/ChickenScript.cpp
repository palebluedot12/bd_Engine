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
    m_States.emplace(State::SitDown, std::make_unique<ChickenSitDownState>());
    m_States.emplace(State::Chase, std::make_unique<ChickenChaseState>());
    m_States.emplace(State::Attack, std::make_unique<ChickenAttackState>());

    m_CurrentState = m_States[State::SitDown].get();
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

    UpdateState();
    m_CurrentState->Update(this);
}

void ChickenScript::UpdateState()
{
    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
    float distance = (playerPos - chickenPos).Length();

    State newState;

    if (distance > 300.0f)
    {
        newState = State::SitDown;
    }
    else if (distance > 10.0f && distance <= 300.0f)
    {
        newState = State::Chase;
    }
    else if (distance <= 10.0f)
    {
        newState = State::Attack;
    }

    // 현재 State의 Exit 호출 후, 새로 바뀐 State의 Enter 호출
    if (m_States[newState].get() != m_CurrentState)
    {
        m_CurrentState->Exit(this);
        m_CurrentState = m_States[newState].get();
        m_CurrentState->Enter(this);
    }

}
