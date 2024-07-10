#include "Collider.h"
#include "GameObject.h"
#include "Script.h"

UINT Collider::CollisionID = 1;

Collider::Collider(eColliderType type)
	: Component(eComponentType::Collider)
	, m_Type(type)
	, m_ID(CollisionID++)
	, m_Size(Vector2::One)
{

}

Collider::~Collider()
{
}

void Collider::Initialize()
{
}

void Collider::Update()
{
}

void Collider::LateUpdate()
{
}

void Collider::Render(HDC hdc)
{
}

void Collider::OnCollisionEnter(Collider* other)
{
	Script* script = GetOwner()->GetComponent<Script>();
	script->OnCollisionEnter(other);
}

void Collider::OnCollisionStay(Collider* other)
{
	Script* script = GetOwner()->GetComponent<Script>();
	script->OnCollisionStay(other);
}

void Collider::OnCollisionExit(Collider* other)
{
	Script* script = GetOwner()->GetComponent<Script>();
	script->OnCollisionExit(other);
}