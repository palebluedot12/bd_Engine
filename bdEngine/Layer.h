#pragma once
#include "..\\bdEngine\\Entity.h"
#include "CommonInclude.h"
#include "GameObject.h"

// 그려지는 순서
class Layer : public Entity
{
public:
	Layer();
	~Layer();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);
	virtual void Destroy();

	void AddGameObject(GameObject* gameObject);
	const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }

private:
	void findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs);
	void deleteGameObjects(std::vector<GameObject*> gameObjs);
	void eraseGameObject();

private:
	//eLayerType mType;
	std::vector<GameObject*> mGameObjects;

};
