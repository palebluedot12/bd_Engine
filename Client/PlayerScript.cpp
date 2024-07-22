#include "PlayerScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "..\\bdEngine\\Collider.h"

PlayerScript::PlayerScript()
	: m_Movement(nullptr)
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::Start()
{
	co = gameObject->AddComponent<BoxCollider2D>();
	co->size = { 25, 25 };
	co->offset = { 0, 15 };
	m_Movement = gameObject->AddComponent<Movement>();
	m_Movement->SetSpeed(100.0f);
}


void PlayerScript::Update()
{
	if (m_Animator == nullptr)
	{
		m_Animator = GetOwner()->GetComponent<Animator>();
	}

	switch (m_State)
	{
	case PlayerScript::eState::SitDown:
		SitDown();
		break;
	case PlayerScript::eState::Walk:
		Move();
		break;
	case PlayerScript::eState::Sleep:
		break;
	case PlayerScript::eState::Attack:
		break;
	default:
		break;
	}
}

void PlayerScript::LateUpdate()
{

}

void PlayerScript::Render(ID2D1RenderTarget* pRenderTarget)
{
}


void PlayerScript::SitDown()
{
	if (Input::GetKey(eKeyCode::Right))
	{
		m_State = PlayerScript::eState::Walk;
		m_Animator->PlayAnimation(L"RightWalk");
	}
	if (Input::GetKey(eKeyCode::Left))
	{
		m_State = PlayerScript::eState::Walk;
		m_Animator->PlayAnimation(L"LeftWalk");
	}
	if (Input::GetKey(eKeyCode::Up))
	{
		m_State = PlayerScript::eState::Walk;
		m_Animator->PlayAnimation(L"UpWalk");
	}
	if (Input::GetKey(eKeyCode::Down))
	{
		m_State = PlayerScript::eState::Walk;
		m_Animator->PlayAnimation(L"DownWalk");
	}
}

void PlayerScript::Move()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPosition();

	if (Input::GetKey(eKeyCode::Right))
	{
		pos.x += 100.0f * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::Left))
	{
		pos.x -= 100.0f * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::Up))
	{
		pos.y -= 100.0f * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::Down))
	{
		pos.y += 100.0f * Time::DeltaTime();
	}

	tr->SetPosition(pos);

	if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left)
		|| Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
	{
		m_State = PlayerScript::eState::SitDown;
		m_Animator->PlayAnimation(L"SitDown", false);
	}

	//OutputDebugStringW(L"Player Position: ");
	//OutputDebugStringW(std::to_wstring(tr->GetPosition().x).c_str());
	//OutputDebugStringW(L", ");
	//OutputDebugStringW(std::to_wstring(tr->GetPosition().y).c_str());
	//OutputDebugStringW(L"\n");
}


void PlayerScript::OnCollisionEnter(Collider* other)
{
	//other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(600.0f, 600.0f));
}

void PlayerScript::OnCollisionStay(Collider* other)
{
}

void PlayerScript::OnCollisionExit(Collider* other)
{
}


