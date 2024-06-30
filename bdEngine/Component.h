#pragma once
#include "Entity.h"

class GameObject;
class Component : public Entity
{
public:
	Component();
	~Component();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

	void SetOwner(GameObject* owner) { m_Owner = owner; };
	GameObject* GetOwner() { return m_Owner; }
private:
	GameObject* m_Owner;
	// 전방선언
};