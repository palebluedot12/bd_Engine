#pragma once
#include "Component.h"
#include "BoxCollider2D.h"

class Camera : public Component
{

public:
	Camera();
	~Camera();

	Vector2 CalculatePosition(Vector2 pos); //{ return pos - m_Distance; }; 
	//void SetTarget(GameObject* target) { m_Target = target; }
	void SetTarget(GameObject* target);
	void Move(const Vector2& offset);
	void UpdateViewMatrix();
	//D2D1::Matrix3x2F GetViewMatrix() const { return m_ViewMatrix; }
	Vector2 GetLookPosition() const { return m_LookPosition; }
	Vector2 GetResolution() const { return m_Resolution; }
	void SetOffset(const Vector2& offset) { m_Offset = offset; }

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	Vector2 WorldToScreenPoint(const Vector2& worldPos)
	{
		Vector2 viewPos = (worldPos - m_LookPosition) * m_Zoom;
		return viewPos + GetViewportCenter();
	}

	Vector2 GetViewportCenter() const
	{
		// 뷰포트 크기의 절반을 반환
		return Vector2(1600.0f / 2.0f, 900.0f / 2.0f);
	}

	D2D1::Matrix3x2F GetViewMatrix() const
	{
		return m_ViewMatrix;
	}

	BoxCollider2D* GetViewportCollider() const { return m_ViewportCollider; }
	void UpdateViewportCollider();

private:
	//std::vector<GameObject*> mGameObjects;
	class GameObject* m_Target;
	Vector2 m_Distance;				// 카메라가 이동한 거리
	Vector2 m_Resolution = { 1600.0f, 900.0f };
	Vector2 m_LookPosition;			// 카메라가 바라보고있는 좌표
	D2D1::Matrix3x2F m_ViewMatrix;
	float m_Zoom;
	Vector2 m_Offset;

	BoxCollider2D* m_ViewportCollider;

	std::vector<GameObject*> m_VisibleObjects;



};

