#pragma once
#include "Component.h"

// Script�� GameObject�� Componentó�� ��� �ִ´�
class Script : public Component
{
public:
	 void Initialize() override;
	 void Update() override;
	 void LateUpdate() override;
	 void Render(ID2D1RenderTarget* pRenderTarget) override;

};

