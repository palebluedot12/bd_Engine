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
	m_Zoom = 1.0f;
	m_LookPosition = Vector2::Zero;
	UpdateViewMatrix();
}
void Camera::Update()
{
	// Ÿ���� ������ ī�޶��� LookPos�� target��ǥ�� ����, �⺻�����δ� Owner�� ��ǥ
	if (m_Target)
	{
		Transform* tr = m_Target->GetComponent<Transform>();
		m_LookPosition = tr->GetPosition();
	}

	//Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	//m_LookPosition = cameraTr->GetPosition();

	//// ���� min �� max�α��� ī�޶� �������� �� resolution / 2 ��ŭ ���� �ߴϱ�
	//m_Distance = m_LookPosition - (m_Resolution / 2.0f);

	UpdateViewMatrix();

}
void Camera::LateUpdate()
{

}
void Camera::Render(ID2D1RenderTarget* pRenderTarget)
{
}

void Camera::Move(const Vector2& offset)
{
	m_LookPosition += offset;
}

void Camera::UpdateViewMatrix()
{
	D2D1::Matrix3x2F translation = D2D1::Matrix3x2F::Translation(
		-m_LookPosition.x + m_Resolution.x / 2.0f,
		-m_LookPosition.y + m_Resolution.y / 2.0f
	);

	D2D1::Matrix3x2F scale = D2D1::Matrix3x2F::Scale(m_Zoom, m_Zoom,
		D2D1::Point2F(m_Resolution.x / 2.0f, m_Resolution.y / 2.0f));

	m_ViewMatrix = scale * translation;
}