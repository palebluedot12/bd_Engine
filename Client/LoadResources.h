#pragma once
#include "..\\bdEngine\\ResourceManager.h"
#include "..\\bdEngine\\Texture.h"

void LoadResources()
{
	ResourceManager::Load<Texture>(L"BG", L"C:\\D2D\\bd_Engine\\Resources\\Earth.png");
}
