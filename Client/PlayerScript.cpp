#include "PlayerScript.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Time.h"

PlayerScript::PlayerScript()
{
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::Initialize()
{
}

void PlayerScript::Update()
{
	if (Input::GetKey(eKeyCode::Right))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 150.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
	if (Input::GetKey(eKeyCode::Left))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x -= 150.0f * Time::DeltaTime();

		tr->SetPosition(pos);
	}
	if (Input::GetKey(eKeyCode::Up))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.y -= 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
	if (Input::GetKey(eKeyCode::Down))
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.y += 100.0f * Time::DeltaTime();

		tr->SetPosition(pos);
	}

}

void PlayerScript::LateUpdate()
{
}

void PlayerScript::Render(ID2D1RenderTarget* pRenderTarget)
{
}
