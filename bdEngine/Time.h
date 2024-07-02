#pragma once
#include "CommonInclude.h"

class Time
{
public:
	static void Initailize();
	static void Update();
	static void Render(ID2D1RenderTarget* pRenderTarget);

	static float DeltaTime() { return DeltaTimeValue; }

private:
	static LARGE_INTEGER CpuFrequency;
	static LARGE_INTEGER PrevFrequency;
	static LARGE_INTEGER CurrentFrequency;
	static float DeltaTimeValue;
};

