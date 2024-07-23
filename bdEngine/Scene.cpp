#include "Scene.h"
#include <typeinfo>

Scene::Scene()
	: m_Layers{}
{
	CreateLayers();
}
Scene::~Scene()
{
	for (Layer* layer : m_Layers)
	{
		delete layer;
		layer = nullptr;
	}
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
	std::vector<GameObject*> visibleObjects;

	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		const std::vector<GameObject*>& layerObjects = layer->GetGameObjects();
		std::vector<GameObject*> layerVisibleObjects = CollisionManager::GetVisibleObjects(mainCamera, layerObjects);
		visibleObjects.insert(visibleObjects.end(), layerVisibleObjects.begin(), layerVisibleObjects.end());

		//layer->Render(pRenderTarget);
	}

	for (GameObject* obj : visibleObjects)
	{
		obj->Render(pRenderTarget);
	}

	m_UsedVRAM = RenderManager::Get()->GetUsedVRAM();
	RenderManager::RenderDebugInfo(visibleObjects.size() - 1, m_UsedVRAM);
}

void Scene::Destroy()
{
	for (Layer* layer : m_Layers)
	{
		if (layer == nullptr)
			continue;

		layer->Destroy();
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

