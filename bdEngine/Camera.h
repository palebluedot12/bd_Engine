#pragma once
#include "Component.h"

class Camera : public Component
{

public:
	// �������� 500��ŭ ����������, �׷����� ��ǥ�� �� �ݴ�� 500��ŭ ���� �ȴ�
	Vector2 CalculatePosition(Vector2 pos) { return pos - m_Distance; }; 

	Camera();
	~Camera();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

private:
	//std::vector<GameObject*> mGameObjects;
	class GameObject* m_Target;
	Vector2 m_Distance;				// ī�޶� �̵��� �Ÿ�
	Vector2 m_Resolution;
	Vector2 m_LookPosition;			// ī�޶� �ٶ󺸰��ִ� ��ǥ

};

