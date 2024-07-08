#include "Component.h"

Component::Component(eComponentType type)
	:m_Type(type)
{

}

Component::~Component()
{
}

void Component::Initialize()
{
}

void Component::Update()
{
}

void Component::LateUpdate()
{
}

void Component::Render(ID2D1RenderTarget* pRenderTarget)
{
}
