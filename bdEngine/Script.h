#pragma once
#include "Component.h"

// Script�� GameObject�� Componentó�� �ٴ´�
class Script : public Component
{
public:
	Script();
	~Script();

	virtual void Start() {} // ������Ʈ�� �߰��� ���� �ٷ� ȣ��˴ϴ�.

	virtual void Initialize() override
	{
		gameObject = GetOwner();
		Start();
	}
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	virtual void OnCollisionEnter(class Collider* other);
	virtual void OnCollisionStay(class Collider* other);
	virtual void OnCollisionExit(class Collider* other);

	GameObject* gameObject;

};

