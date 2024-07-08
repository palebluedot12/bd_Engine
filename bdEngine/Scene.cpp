#include "Scene.h"

Scene::Scene()
	: m_Layers{}
{
	CreateLayers();
}
Scene::~Scene()
{
}
void Scene::Initialize()
{
	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		layer->Initialize();
	}
}
void Scene::Update()
{
	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		layer->Update();
	}
}
void Scene::LateUpdate()
{
	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		layer->LateUpdate();
	}
}
void Scene::Render(ID2D1RenderTarget* pRenderTarget)
{
	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		layer->Render(pRenderTarget);
	}
}

void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
{
	m_Layers[(UINT)type]->AddGameObject(gameObj);
}

void Scene::CreateLayers()
{
	m_Layers.resize((UINT)eLayerType::Max);
	for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
	{
		m_Layers[i] = new Layer();
	}
}

void Scene::OnEnter()
{

}

void Scene::OnExit()
{

}