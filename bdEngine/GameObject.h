#pragma once
#include "CommonInclude.h"
#include <d2d1.h>

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

	//ID2D1Factory* pFactory;
	//ID2D1HwndRenderTarget* pRenderTarget;
	//ID2D1SolidColorBrush* pBrush;
	//void CreateDeviceResources();
	//void DiscardDeviceResources();

};

