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
}

void Player::Render(ID2D1RenderTarget* pRenderTarget)
{
	GameObject::Render(pRenderTarget);
}