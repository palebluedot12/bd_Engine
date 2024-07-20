#include "Script.h"
#include "Collider.h"

Script::Script()
	: Component(eComponentType::Script)
{
}

Script::~Script()
{
}

//void Script::Initialize()
//{
//}

void Script::Update()
{
}

void Script::LateUpdate()
{
}

void Script::Render(ID2D1RenderTarget* pRenderTarget)
{
}

void Script::OnCollisionEnter(Collider* other)
{
}

void Script::OnCollisionStay(Collider* other)
{
}

void Script::OnCollisionExit(Collider* other)
{
}

