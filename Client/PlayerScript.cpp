#include "PlayerScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"
#include "..\\bdEngine\\Animator.h"
#include "..\\bdEngine\\Collider.h"
#include <functional>
#include "PlayerScript.h"
#include "PlayerSitDownState.h"
#include "PlayerWalkState.h"

PlayerScript::PlayerScript()
	: m_Movement(nullptr)
{
	m_States.emplace(State::SitDown, std::make_unique<PlayerSitDownState>());
	m_States.emplace(State::Walk, std::make_unique<PlayerWalkState>());
	m_CurrentState = m_States[State::SitDown].get();
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

	UpdateState();
	m_CurrentState->Update(this);
}


void PlayerScript::UpdateState()
{
	State newState = m_CurrentState->GetNextState(this);
	if (m_States[newState].get() != m_CurrentState)
	{
		m_CurrentState->Exit(this);
		m_CurrentState = m_States[newState].get();
		m_CurrentState->Enter(this);
	}
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

