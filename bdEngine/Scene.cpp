#include "Scene.h"

Scene::Scene()
	: mLayers{}
{
	CreateLayers();
}
Scene::~Scene()
{
}
void Scene::Initialize()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Initialize();
	}
}
void Scene::Update()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Update();
	}
}
void Scene::LateUpdate()
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->LateUpdate();
	}
}
void Scene::Render(ID2D1RenderTarget* pRenderTarget)
{
	for (Layer* layer : mLayers)
	{
		if (layer == nullptr)
			continue;

		layer->Render(pRenderTarget);
	}
}

void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
{
	mLayers[(UINT)type]->AddGameObject(gameObj);
}

void Scene::CreateLayers()
{
	mLayers.resize((UINT)eLayerType::Max);
	for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
	{
		mLayers[i] = new Layer();
	}
}

void Scene::OnEnter()
{

}

void Scene::OnExit()
{

}