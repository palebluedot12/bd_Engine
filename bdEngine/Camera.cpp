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
	// Ÿ���� ������ ī�޶��� LookPos�� target��ǥ�� ����, �⺻�����δ� Owner�� ��ǥ
	if (m_Target)
	{
		Transform* tr = m_Target->GetComponent<Transform>();
		m_LookPosition = tr->GetPosition();
	}

	Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	m_LookPosition = cameraTr->GetPosition();

	// ���� min �� max�α��� ī�޶� �������� �� resolution / 2 ��ŭ ���� �ߴϱ�
	m_Distance = m_LookPosition - (m_Resolution / 2.0f);
}
void Camera::LateUpdate()
{

}
void Camera::Render(ID2D1RenderTarget* pRenderTarget)
{
}