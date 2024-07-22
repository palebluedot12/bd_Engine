#include "Movement.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"

Movement::Movement()
    : Component(eComponentType::Movement)
    , m_Direction(Vector2::Zero)
    , m_Speed(100.0f)
{
}

Movement::~Movement()
{
}

void Movement::Update()
{
    Transform* transform = GetOwner()->GetComponent<Transform>();
    Vector2 position = transform->GetPosition();
    position += m_Direction * m_Speed * Time::DeltaTime();
    transform->SetPosition(position);
}