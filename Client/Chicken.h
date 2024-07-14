#pragma once
#include "..\\bdEngine\\GameObject.h"

class Chicken : public GameObject
{
public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

private:

};
