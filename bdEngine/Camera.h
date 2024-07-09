#pragma once
#include "Component.h"

class Camera : public Component
{

public:
	Camera();
	~Camera();

	// �������� 500��ŭ ����������, �׷����� ��ǥ�� �� �ݴ�� 500��ŭ ���� �ȴ�
	Vector2 CalculatePosition(Vector2 pos); //{ return pos - m_Distance; }; 
	void SetTarget(GameObject* target) { m_Target = target; }
	void Move(const Vector2& offset);
	void UpdateViewMatrix();
	D2D1::Matrix3x2F GetViewMatrix() const { return m_ViewMatrix; }
	Vector2 GetLookPosition() const { return m_LookPosition; }
	Vector2 GetResolution() const { return m_Resolution; }

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void CullObjects(const std::vector<GameObject*>& objects);
	const std::vector<GameObject*>& GetVisibleObjects() const { return m_VisibleObjects; }



private:
	//std::vector<GameObject*> mGameObjects;
	class GameObject* m_Target;
	Vector2 m_Distance;				// ī�޶� �̵��� �Ÿ�
	Vector2 m_Resolution;
	Vector2 m_LookPosition;			// ī�޶� �ٶ󺸰��ִ� ��ǥ
	D2D1::Matrix3x2F m_ViewMatrix;
	float m_Zoom;

	std::vector<GameObject*> m_VisibleObjects;


};

