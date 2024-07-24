#include "CatScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "PlayScene.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\Collider.h"

CatScript::CatScript()
    : m_State(CatScript::eState::SitDown)
    , m_AttackTimer(0.0f)

{
}

CatScript::~CatScript()
{
}

void CatScript::Start()
{
    co = gameObject->AddComponent<BoxCollider2D>();
    co->size = { 25, 25 };
    co->offset = { 0, 5 };
    m_Movement = gameObject->AddComponent<Movement>();
}

void CatScript::Update()
{
    if (!m_Player)
        return;

    if (m_Animator == nullptr)
    {
        m_Animator = GetOwner()->GetComponent<Animator>();
    }

    //UpdateState();

    switch (m_State)
    {
    case eState::SitDown:
        SitDown();
        break;
    case eState::Chase:
        //Chase();
        break;
    case eState::Attack:
        //Attack();
        break;
    }


}

//void ChickenScript::UpdateState()
//{
//    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
//    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
//    float distance = (playerPos - chickenPos).Length();
//
//    if (distance > 300.0f)
//    {
//        m_State = eState::SitDown;
//    }
//    else if (distance > 10.0f && distance <= 300.0f)
//    {
//        m_State = eState::Chase;
//    }
//    else if (distance <= 10.0f)
//    {
//        m_State = eState::Attack;
//    }
//}

//void CatScript::Chase()
//{
//    Vector2 playerPos = m_Player->GetComponent<Transform>()->GetPosition();
//    Vector2 chickenPos = GetOwner()->GetComponent<Transform>()->GetPosition();
//    Vector2 direction = (playerPos - chickenPos).Normalized();
//
//    //Transform* tr = GetOwner()->GetComponent<Transform>();
//    //Vector2 newPos = chickenPos + direction * 70.0f * Time::DeltaTime();
//    //tr->SetPosition(newPos);
//
//    // TODO : 와리가리 버그 => Attack하면서 움직이면 안됨
//    m_Movement->SetDirection(direction);
//
//    if (direction.x > 0)
//    {
//        m_Animator->PlayAnimation(L"RightWalk", true);
//    }
//    else
//    {
//        m_Animator->PlayAnimation(L"LeftWalk", true);
//    }
//}

void CatScript::LateUpdate()
{

}

void CatScript::Render(ID2D1RenderTarget* pRenderTarget)
{

}

void CatScript::SitDown()
{
    m_Animator->PlayAnimation(L"LeftSit", true);

    if (m_Movement)
        m_Movement->SetDirection(Vector2::Zero);
}

void CatScript::Move()
{

}
