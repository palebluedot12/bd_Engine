#include "GameObject.h"
#include "InputManager.h"
#include "Time.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
	for (Component* comp : mComponents)
	{
		delete comp;
		comp = nullptr;
	}
}

void GameObject::Initialize()
{
	for (Component* comp : mComponents)
	{
		comp->Initialize();
	}
}


void GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		comp->Update();
	}
}

void GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		comp->LateUpdate();
	}
}

void GameObject::Render()
{
	for (Component* comp : mComponents)
	{
		comp->Render();
	}


}