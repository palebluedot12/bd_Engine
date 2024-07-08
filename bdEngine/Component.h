#pragma once
#include "Entity.h"

class GameObject;
class Component : public Entity
{
public:
	Component(eComponentType type);
	~Component();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);

	void SetOwner(GameObject* owner) { m_Owner = owner; };
	GameObject* GetOwner() { return m_Owner; }
	eComponentType GetType() { return m_Type; }

private:
	GameObject* m_Owner;
	eComponentType m_Type;
};