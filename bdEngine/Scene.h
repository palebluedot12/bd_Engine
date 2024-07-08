#pragma once
#include "Entity.h"
#include "GameObject.h"
#include "Layer.h"

class Scene : public Entity
{
public:
	Scene();
	~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);

	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject(GameObject* gameObject, const eLayerType type);
	Layer* GetLayer(const eLayerType type) { return m_Layers[(UINT)type]; }

private:
	void CreateLayers();

private:
	// Scene�� Layer����, Layer���� Object���� ���� ����
	std::vector<Layer*> m_Layers;
};
