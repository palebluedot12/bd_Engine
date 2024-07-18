#pragma once
#include "Component.h"

// Script는 GameObject에 Component처럼 붙는다
class Script : public Component
{
public:
	Script();
	~Script();

	virtual void Start() {} // 컴포넌트를 추가한 직후 바로 호출됩니다.

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

