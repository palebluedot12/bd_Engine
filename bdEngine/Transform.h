#pragma once
#include "Entity.h"
#include "Component.h"

struct Pos
{
	int mX;
	int mY;
};

class Transform : public Component
{
public:
	Transform();
	~Transform();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetPosition(Vector2 pos) { m_Position.x = pos.x; m_Position.y = pos.y; }
	Vector2 GetPosition() { return m_Position; }

private:
	Vector2 m_Position;
};