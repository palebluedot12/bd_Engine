#include "Chicken.h"
#include "..\\bdEngine\\InputManager.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\Time.h"

void Chicken::Initialize()
{
	GameObject::Initialize();
}

void Chicken::Update()
{
	GameObject::Update();
}

void Chicken::LateUpdate()
{
	GameObject::LateUpdate();
}

void Chicken::Render(ID2D1RenderTarget* pRenderTarget)
{
	GameObject::Render(pRenderTarget);
}
