#pragma once
#include "CommonInclude.h"

class GameManager
{
public:
	GameManager();
	~GameManager();
	void Initialize(HWND hwnd);
	void Run();
	void Update();
	void LateUpdate();
	void Render();

private:
	
	float m_Speed;
};

