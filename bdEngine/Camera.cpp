#include "Camera.h"
#include "Transform.h"
#include "GameObject.h"
#include "GameManager.h"

extern GameManager application;


Camera::Camera()
	: Component(eComponentType::Camera)
	, m_Distance(Vector2::Zero)
	, m_Resolution(Vector2(1600.0f, 900.0f))
	, m_LookPosition(m_Resolution.x / 2, m_Resolution.y / 2)
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
	UpdateViewMatrix();
}
void Camera::Update()
{
	// 타겟이 있으면 카메라의 LookPos를 target좌표로 설정, 기본적으로는 Owner의 좌표
	if (m_Target)
	{
		Transform* tr = m_Target->GetComponent<Transform>();
		m_LookPosition = tr->GetPosition() + m_Offset;
	}
	UpdateViewMatrix();

}
void Camera::LateUpdate()
{

}
void Camera::Render(ID2D1RenderTarget* pRenderTarget)
{
}

Vector2 Camera::CalculatePosition(Vector2 pos)
{
	return WorldToScreenPoint(pos);

}

void Camera::SetTarget(GameObject* target)
{
	m_Target = target;
	if (m_Target)
	{
		Transform* targetTransform = m_Target->GetComponent<Transform>();
		m_LookPosition = targetTransform->GetPosition();
	}
}

void Camera::Move(const Vector2& offset)
{
	m_LookPosition += offset;
}


// 월드 좌표를 화면 좌표로 변환하는데 사용.
// 모든 객체의 좌표를 카메라의 LookPostion만큼 뺀다.
// 모든 객체의 크기와 위치를 m_Zoom 비율로 조정한다.
void Camera::UpdateViewMatrix()
{
	D2D1::Matrix3x2F translation = D2D1::Matrix3x2F::Translation(-m_LookPosition.x, -m_LookPosition.y);
	D2D1::Matrix3x2F scale = D2D1::Matrix3x2F::Scale(m_Zoom, m_Zoom);
	m_ViewMatrix = scale * translation;

	//OutputDebugStringW((L"Camera Position: " + std::to_wstring(m_LookPosition.x)
	//	+ L", " + std::to_wstring(m_LookPosition.y) + L"\n").c_str());
}