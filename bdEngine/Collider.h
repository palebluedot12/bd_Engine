#pragma once
#include "Component.h"

class Collider : public Component
{
public:
	Collider(eColliderType type);
	~Collider();

	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	virtual void OnCollisionEnter(Collider* other);
	virtual void OnCollisionStay(Collider* other);
	virtual void OnCollisionExit(Collider* other);
	 
	Vector2 GetOffset() { return m_Offset; }
	void SetOffset(Vector2 offset) { m_Offset = offset; }
	UINT32 GetID() { return m_ID; }
	Vector2 GetSize() { return m_Size; }
	void SetSize(Vector2 size) { m_Size = size; }
	eColliderType GetColliderType() { return m_Type; }

private:
	static UINT CollisionID;

	UINT32 m_ID;
	Vector2 m_Offset;
	Vector2 m_Size;
	eColliderType m_Type;
	//Charcater type;
};