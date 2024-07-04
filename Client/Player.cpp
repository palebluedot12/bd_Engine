#include "Player.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Time.h"

void Player::Initialize()
{
	GameObject::Initialize();
}

void Player::Update()
{
	GameObject::Update();
}

void Player::LateUpdate()
{
	GameObject::LateUpdate();

	if (Input::GetKey(eKeyCode::Right))
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos.x += 100.0f * Time::DeltaTime();
		tr->SetPosition(pos);
	}
}

void Player::Render(ID2D1RenderTarget* pRenderTarget)
{
	GameObject::Render(pRenderTarget);
}