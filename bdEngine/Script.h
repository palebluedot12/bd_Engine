#pragma once
#include "Component.h"

// Script는 GameObject가 Component처럼 들고 있는다
class Script : public Component
{
public:
	Script();
	~Script();
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

};

