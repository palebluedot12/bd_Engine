#pragma once
#include "Component.h"

class Camera : public Component
{

public:
	Camera();
	~Camera();

	// 우측으로 500만큼 움직였으면, 그려지는 좌표는 그 반대로 500만큼 가면 된다
	Vector2 CalculatePosition(Vector2 pos); //{ return pos - m_Distance; }; 
	void SetTarget(GameObject* target) { m_Target = target; }
	void Move(const Vector2& offset);
	void UpdateViewMatrix();
	D2D1::Matrix3x2F GetViewMatrix() const { return m_ViewMatrix; }

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

private:
	//std::vector<GameObject*> mGameObjects;
	class GameObject* m_Target;
	Vector2 m_Distance;				// 카메라가 이동한 거리
	Vector2 m_Resolution;
	Vector2 m_LookPosition;			// 카메라가 바라보고있는 좌표
	D2D1::Matrix3x2F m_ViewMatrix;
	float m_Zoom;

};

