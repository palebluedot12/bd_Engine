#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"
#include "SpriteRenderer.h"

template <typename T>
static T* Instantiate(eLayerType type)
{
	T* gameObject = new T();
	Scene* activeScene = SceneManager::GetActiveScene();
	Layer* layer = activeScene->GetLayer(type);
	layer->AddGameObject(gameObject);

	return gameObject;
}

//template <typename T>
//static T* Instantiate(eLayerType type, Vector2 position)
//{
//	T* gameObject = new T();
//	Scene* activeScene = SceneManager::GetActiveScene();
//	Layer* layer = activeScene->GetLayer(type);
//	layer->AddGameObject(gameObject);
//
//	Transform* tr = gameObject->GetComponent<Transform>();
//	tr->SetPosition(position);
//
//	return gameObject;
//}

template <typename T>
static T* Instantiate(eLayerType type, Vector2 position, Vector2 size = Vector2(-1, -1))
{
	T* gameObject = new T();
	Scene* activeScene = SceneManager::GetActiveScene();
	Layer* layer = activeScene->GetLayer(type);
	layer->AddGameObject(gameObject);

	Transform* tr = gameObject->GetComponent<Transform>();
	tr->SetPosition(position);

	SpriteRenderer* sr = gameObject->GetSpriteRenderer();
	if (sr)
	{
		if (size.x > 0 && size.y > 0)
		{
			sr->SetSize(size);
		}
	}

	return gameObject;
}
