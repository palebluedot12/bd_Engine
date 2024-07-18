#include "Layer.h"
#include "ResourceManager.h"
#include "Transform.h"

Layer::Layer()
	: mGameObjects{}
{

}
Layer::~Layer()
{

}

void Layer::Initialize()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Initialize();
	}
}

void Layer::Update()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Update();
	}
}
void Layer::LateUpdate()
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->LateUpdate();
	}
}
void Layer::Render(ID2D1RenderTarget* pRenderTarget)
{
	for (GameObject* gameObj : mGameObjects)
	{
		if (gameObj == nullptr)
			continue;

		gameObj->Render(pRenderTarget);
	}
}

void Layer::Destroy()
{
	std::vector<GameObject*> deleteObjects = {};
	findDeadGameObjects(deleteObjects);
	eraseGameObject();
	deleteGameObjects(deleteObjects);
}

void Layer::AddGameObject(GameObject* gameObject, Texture* tex, Vector2 size, float alpha)
{
	if (gameObject == nullptr)
		return;
	
	Transform* tr = gameObject->AddComponent<Transform>();

	if (tex != nullptr)
	{
		SpriteRenderer* sp = gameObject->AddComponent<SpriteRenderer>();
		sp->SetTexture(tex);

		if (size != Vector2::Zero)
		{
			sp->SetSize(size.x, size.y);
			tr->SetSize(size);
			sp->SetAlpha(alpha);
		}
		else
		{
			tr->SetSize(sp->GetSize());
			sp->SetAlpha(alpha);
		}
	}

	mGameObjects.push_back(gameObject);
}

void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
{
	for (GameObject* gameObj : mGameObjects)
	{
		GameObject::eState active = gameObj->GetState();
		if (active == GameObject::eState::Dead)
			gameObjs.push_back(gameObj);
	}
}

void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs)
{
	for (GameObject* obj : deleteObjs)
	{
		delete obj;
		obj = nullptr;
	}
}

void Layer::eraseGameObject()
{
	std::erase_if(mGameObjects,
		[](GameObject* gameObj)
		{
			return (gameObj)->IsDead();
		});
}