#pragma once
#include "..\\bdEngine\\Script.h"

class PlayerScript : public Script
{
public:
	PlayerScript();
	~PlayerScript();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;


private:
};

