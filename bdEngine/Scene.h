#pragma once
#include "Entity.h"
#include "GameObject.h"

class Scene : public Entity
{
public:
	Scene();
	~Scene();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	virtual void OnEnter();
	virtual void OnExit();

	void AddGameObject(GameObject* gameObject);

private:
	std::vector<GameObject*> mGameObjects;
};
