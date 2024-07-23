#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"
#include "CollisionManager.h"
#include "RenderManager.h"
#include <string>

class Scene : public Entity
{
public:
	Scene();
	~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);
	virtual void Destroy();

	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject(GameObject* gameObject, const eLayerType type);
	Layer* GetLayer(const eLayerType type) { return m_Layers[(UINT)type]; }

	int m_UsedVRAM = 0;

	template <typename T>
	void DestroyObjectsWithComponent(eLayerType layerType)
	{
		Layer* layer = GetLayer(layerType);
		auto& objects = layer->GetGameObjects();
		for (auto it = objects.rbegin(); it != objects.rend(); ++it)
		{
			GameObject* obj = *it;
			if (obj->GetComponent<T>() != nullptr)
			{
				object::Destroy(obj);
				break;
			}
		}
	}

private:
	void CreateLayers();

private:
	// Scene은 Layer들을, Layer들은 Object들을 갖고 있음
	std::vector<Layer*> m_Layers;
};
