#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "GameManager.h"

extern GameManager application;


Camera::Camera()
	: Component(eComponentType::Camera)
	, m_Distance(Vector2::Zero)
	, m_Resolution(Vector2(1600.0f, 900.0f))
	, m_LookPosition(Vector2::Zero)
	, m_Target(nullptr)
{
}

Camera::~Camera()
{
}

void Camera::Initialize()
{
	m_Resolution.x = application.GetWidth();
	m_Resolution.y = application.GetHeight();
}
void Camera::Update()
{
	// 타겟이 있으면 카메라의 LookPos를 target좌표로 설정, 기본적으로는 Owner의 좌표
	if (m_Target)
	{
		Transform* tr = m_Target->GetComponent<Transform>();
		m_LookPosition = tr->GetPosition();
	}

	Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	m_LookPosition = cameraTr->GetPosition();

	// 가장 min 과 max로까지 카메라가 움직였을 때 resolution / 2 만큼 공간 뜨니까
	m_Distance = m_LookPosition - (m_Resolution / 2.0f);
}
void Camera::LateUpdate()
{

}
void Camera::Render(ID2D1RenderTarget* pRenderTarget)
{
}