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

ChickenScript::ChickenScript()
	: m_State(ChickenScript::State::SitDown)
	, m_AttackTimer(0.0f)

{
    m_StateMachine.SetOwner(this);
    m_StateMachine.AddState(State::SitDown,
        &ChickenScript::EnterSitDown,
        &ChickenScript::UpdateSitDown,
        &ChickenScript::ExitSitDown);

    m_StateMachine.AddState(State::Chase,
        &ChickenScript::EnterChase,
        &ChickenScript::UpdateChase,
        &ChickenScript::ExitChase);

    m_StateMachine.AddState(State::Attack,
        &ChickenScript::EnterAttack,
        &ChickenScript::UpdateAttack,
        &ChickenScript::ExitAttack);

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

    UpdateState();
    m_StateMachine.Update(); 
}

void ChickenScript::UpdateState()
{
    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
    float distance = (playerPos - chickenPos).Length();

    State newState = m_StateMachine.GetCurrentState();

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

    m_StateMachine.SetState(newState);

}

void ChickenScript::EnterSitDown()
{
    m_Animator->PlayAnimation(L"LeftSit", true);
}

void ChickenScript::UpdateSitDown()
{
    m_Movement->SetDirection(Vector2::Zero);
}

void ChickenScript::ExitSitDown()
{
}

void ChickenScript::EnterChase()
{
}

void ChickenScript::UpdateChase()
{
    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
    direction = (playerPos - chickenPos).Normalized();

    m_Movement->SetDirection(direction);

    const std::wstring& currentAnim = m_Animator->GetActiveAnimationName();
    if (direction.x > 0)
    {
        // 같은 애니메이션의 첫번째 인덱스가 계속해서 실행 안되게끔, 실행하고자 하는 애니메이션이 현재 실행중이지 않을 때만
        if (currentAnim != L"RightWalk")
            m_Animator->PlayAnimation(L"RightWalk", true);
    }
    else
    {
        if (currentAnim != L"LeftWalk")
            m_Animator->PlayAnimation(L"LeftWalk", true);
    }

}

void ChickenScript::ExitChase()
{
}

void ChickenScript::EnterAttack()
{
    m_Animator->PlayAnimation(L"Attack", true);
    m_Animator->GetCompleteEvent(L"Attack") = std::bind(&ChickenScript::OnAttackAnimationComplete, this);

}

void ChickenScript::OnAttackAnimationComplete()
{
    // 공격 애니메이션이 끝났을 때 실행될 로직
}


void ChickenScript::UpdateAttack()
{
    m_Movement->SetDirection(Vector2::Zero);
    // 공격 중 추가 로직
}

void ChickenScript::ExitAttack()
{
}
