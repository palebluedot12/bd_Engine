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
	m_LookPosition = { 800, 450 };
	UpdateViewMatrix();
}
void Camera::Update()
{
	// 타겟이 있으면 카메라의 LookPos를 target좌표로 설정, 기본적으로는 Owner의 좌표
	if (m_Target)
	{
		Transform* tr = m_Target->GetComponent<Transform>();
		m_LookPosition = tr->GetPosition();
	}

	//Transform* cameraTr = GetOwner()->GetComponent<Transform>();
	//m_LookPosition = cameraTr->GetPosition();

	//// 가장 min 과 max로까지 카메라가 움직였을 때 resolution / 2 만큼 공간 뜨니까
	//m_Distance = m_LookPosition - (m_Resolution / 2.0f);

	UpdateViewMatrix();

}
void Camera::LateUpdate()
{

}
void Camera::Render(ID2D1RenderTarget* pRenderTarget)
{
}

void Camera::CullObjects(const std::vector<GameObject*>& objects)
{
	m_VisibleObjects.clear();
	Vector2 cameraPos = GetLookPosition();
	Vector2 cameraSize = GetResolution();

	for (const auto& obj : objects)
	{
		SpriteRenderer* sr = obj->GetComponent<SpriteRenderer>();
		if (!sr) continue;

		Transform* tr = obj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 size = sr->GetSize();

		Vector2 viewPos = CalculatePosition(pos);

		bool isVisible =
			viewPos.x + size.x / 2 > 0 &&
			viewPos.x - size.x / 2 < cameraSize.x &&
			viewPos.y + size.y / 2 > 0 &&
			viewPos.y - size.y / 2 < cameraSize.y;

		if (isVisible)
		{
			m_VisibleObjects.push_back(obj);
		}
	}
}

Vector2 Camera::CalculatePosition(Vector2 pos)
{
	D2D1_POINT_2F point = D2D1::Point2F(pos.x, pos.y);
	D2D1_POINT_2F transformedPoint = m_ViewMatrix.TransformPoint(point);
	return Vector2(transformedPoint.x, transformedPoint.y);
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