#pragma once
#include "CommonInclude.h"
#include "Component.h"
#include "SpriteRenderer.h"

void Destroy(GameObject* gameObject);

class GameObject
{
public:
	enum class eState
	{
		Active,
		Paused,			// 화면에는 안뜨지만 메모리에 남겨는 둠
		Dead,			
		End
	};

	friend void Destroy(GameObject* gameObject);

	GameObject();
	~GameObject();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(ID2D1RenderTarget* pRenderTarget);

	template <typename T>
	T* AddComponent()
	{
		T* comp = new T();
		comp->Initialize();
		comp->SetOwner(this);

		mComponents[(UINT)comp->GetType()] = comp;
		//mComponents.push_back(comp);

		return comp;
	}

	template <typename T>
	T* GetComponent()
	{
		T* component = nullptr;
		for (Component* comp : mComponents)
		{
			component = dynamic_cast<T*>(comp);
			if (component)
				break;
		}

		return component;
	}

	eState GetState() { return m_State; }
	void SetActive(bool power)
	{
		if (power == true) m_State = eState::Active;
		if (power == false) m_State = eState::Paused;
	}
	bool IsActive() { return m_State == eState::Active; }
	bool IsDead() { return m_State == eState::Dead; }

private:
	void InitializeTransform();
	void death() { m_State = eState::Dead; }

private:
	eState m_State;
	std::vector<Component*> mComponents;
};
