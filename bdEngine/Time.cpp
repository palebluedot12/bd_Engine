#include "Time.h"

LARGE_INTEGER Time::CpuFrequency = {};
LARGE_INTEGER Time::PrevFrequency = {};
LARGE_INTEGER Time::CurrentFrequency = {};
float Time::DeltaTimeValue = 0.0f;

void Time::Initailize()
{
	// Cpu ���� ������
	QueryPerformanceFrequency(&CpuFrequency);

	// ���α׷��� ���� ���� �� ���� ������
	QueryPerformanceCounter(&PrevFrequency);
}

void Time::Update()
{
	QueryPerformanceCounter(&CurrentFrequency);

	// Current - Prev ���� ������ �� ���ϰ�, �װ� CPU ���� �������� ������ => 1�����Ӵ� �ɸ� �ð�.
	float differenceFrequency
		= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
	DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
	PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
}
void Time::Render(ID2D1RenderTarget* pRenderTarget)
{
	static float time = 0.0f;

	time += DeltaTimeValue;
	float fps = 1.0f / DeltaTimeValue;

	wchar_t str[50] = L"";
	swprintf_s(str, 50, L"Time : %d", (int)fps);
	int len = wcsnlen_s(str, 50);

	//TextOut(hdc, 0, 0, str, len);
}