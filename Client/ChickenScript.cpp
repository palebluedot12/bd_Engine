#include "ChickenScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "PlayScene.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Collider.h"

ChickenScript::ChickenScript()
	: m_State(ChickenScript::State::SitDown)
	, m_AttackTimer(0.0f)

{
    m_StateMachine.AddState(State::SitDown,
        [this](State*) { EnterSitDown(); },
        [this](State*) { UpdateSitDown(); },
        [this](State*) { ExitSitDown(); });

    m_StateMachine.AddState(State::Chase,
        [this](State*) { EnterChase(); },
        [this](State*) { UpdateChase(); },
        [this](State*) { ExitChase(); });

    m_StateMachine.AddState(State::Attack,
        [this](State*) { EnterAttack(); },
        [this](State*) { UpdateAttack(); },
        [this](State*) { ExitAttack(); });

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
    //switch (m_State)
    //{
    //    case State::SitDown:
    //        SitDown();
    //        break;
    //    case State::Chase:
    //        Chase();
    //        break;
    //    case State::Attack:
    //        Attack();
    //        break;
    //}

    
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
    Vector2 direction = (playerPos - chickenPos).Normalized();

    m_Movement->SetDirection(direction);

    if (direction.x > 0)
    {
        m_Animator->PlayAnimation(L"RightWalk", true);
    }
    else
    {
        m_Animator->PlayAnimation(L"LeftWalk", true);
    }
}

void ChickenScript::ExitChase()
{
}

void ChickenScript::EnterAttack()
{
    m_Animator->PlayAnimation(L"Attack", false);

    //// Use animation event to prevent interruption
    //m_Animator->GetCompleteEvent(L"Attack") = [this]()
    //    {
    //        m_AttackTimer = 1.0f; // Set a cooldown timer
    //    };

    m_Animator->GetCompleteEvent(L"Attack") = &ChickenScript::OnAttackAnimationComplete;

}

void ChickenScript::OnAttackAnimationComplete()
{
    // 공격 애니메이션이 끝났을 때 실행될 로직
    //m_StateMachine.SetState(State::Chase); 
}


void ChickenScript::UpdateAttack()
{
    m_Movement->SetDirection(Vector2::Zero);

    // 공격 중 추가 로직
}

void ChickenScript::ExitAttack()
{
}
