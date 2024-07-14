#include "ChickenScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "PlayScene.h"

ChickenScript::ChickenScript()
	: m_State(ChickenScript::eState::SitDown)
	, m_AttackTimer(0.0f)

{
}

ChickenScript::~ChickenScript()
{
}

void ChickenScript::Initialize()
{
	if (m_PlayScene)
	{
		m_Player = m_PlayScene->GetPlayer();
	}
}

void ChickenScript::Update()
{
    if (!m_Player || !m_Animator)
        return;

    UpdateState();

    switch (m_State)
    {
    case eState::SitDown:
        SitDown();
        break;
    case eState::Chase:
        Chase();
        break;
    case eState::Attack:
        Attack();
        break;
    }
}

void ChickenScript::UpdateState()
{
    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
    float distance = (playerPos - chickenPos).Length();

    if (distance > 500.0f)
    {
        m_State = eState::SitDown;
    }
    else if (distance > 100.0f && distance <= 300.0f)
    {
        m_State = eState::Chase;
    }
    else if (distance <= 100.0f)
    {
        m_State = eState::Attack;
    }
}

void ChickenScript::Chase()
{
    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
    Vector2 direction = (playerPos - chickenPos).Normalized();

    Transform* tr = GetOwner()->GetComponent<Transform>();
    Vector2 newPos = chickenPos + direction * 80.0f * Time::DeltaTime();
    tr->SetPosition(newPos);

    if (direction.x > 0)
    {
        m_Animator->PlayAnimation(L"RightWalk", true);
    }
    else
    {
        m_Animator->PlayAnimation(L"LeftWalk", true);
    }
}

void ChickenScript::Attack()
{
    m_AttackTimer += Time::DeltaTime();
    if (m_AttackTimer >= 1.0f)
    {
        m_Animator->PlayAnimation(L"Attack", false);
        m_AttackTimer = 0.0f;
    }
}

void ChickenScript::LateUpdate()
{

}

void ChickenScript::Render(ID2D1RenderTarget* pRenderTarget)
{

}

void ChickenScript::SitDown()
{
    m_Animator->PlayAnimation(L"LeftSit", true);
}

void ChickenScript::Move()
{
	
}
