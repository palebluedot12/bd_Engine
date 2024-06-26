#include "GameObject.h"
#include "InputManager.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	if (Input::GetKey(eKeyCode::A))
	{
		mX -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::D))
	{
		mX += 0.01f;
	}
	if (Input::GetKey(eKeyCode::W))
	{
		mY -= 0.01f;
	}
	if (Input::GetKey(eKeyCode::S))
	{
		mX += 0.01f;
	}
}

void GameObject::LateUpdate()
{
}

void GameObject::Render()
{
	

}
