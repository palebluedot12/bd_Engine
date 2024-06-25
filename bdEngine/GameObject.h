#pragma once
#include "CommonInclude.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Update();
	void LateUpdate();
	void Render();

	void SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	float GetPositionX() { return mX; }
	float GetPositionY() { return mY; }

private:
	float mX;
	float mY;

};

