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
	void Render()  override;

	void SetPos(int x, int y) { mX = x; mY = y; }
	int GetX() { return mX; }
	int GetY() { return mY; }

private:
	int mX;
	int mY;
};