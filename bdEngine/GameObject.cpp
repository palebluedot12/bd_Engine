#include "GameObject.h"
#include "InputManager.h"
#include "Time.h"
#include "Transform.h"

GameObject::GameObject()
	: m_State(eState::Active)
{
	mComponents.resize((UINT)eComponentType::End);
	InitializeTransform();
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
		if (comp == nullptr)
			continue;
		comp->Initialize();
	}
}


void GameObject::Update()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Update();
	}
}

void GameObject::LateUpdate()
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->LateUpdate();
	}
}

void GameObject::Render(ID2D1RenderTarget* pRenderTarget)
{
	for (Component* comp : mComponents)
	{
		if (comp == nullptr)
			continue;
		comp->Render(pRenderTarget);
	}


}

void GameObject::InitializeTransform()
{
	AddComponent<Transform>();
}

void Destroy(GameObject* gameObject)
{
	if (gameObject != nullptr)
		gameObject->death();
}
