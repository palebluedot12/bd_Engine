#include "Transform.h"

Transform::Transform()
	: Component(eComponentType::Transform)
	, m_Scale(Vector2(1.0f, 1.0f))
{
}

Transform::~Transform()
{
}

void Transform::Initialize()
{
}

void Transform::Update()
{
}

void Transform::LateUpdate()
{
}

void Transform::Render(ID2D1RenderTarget* pRenderTarget)
{
}
