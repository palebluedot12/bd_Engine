#pragma once
#include <d2d1.h>

class RenderManager
{
public:
	void Initialize();
	void Render();
	
private:
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
};

