#pragma once
#include "..\\bdEngine\\Entity.h"
#include "CommonInclude.h"
#include "GameObject.h"

// �׷����� ����
class Layer : public Entity
{
public:
	Layer();
	~Layer();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);

	void AddGameObject(GameObject* gameObject);

private:
	//eLayerType mType;
	std::vector<GameObject*> mGameObjects;

};
