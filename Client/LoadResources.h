#pragma once
#include "..\\bdEngine\\ResourceManager.h"
#include "..\\bdEngine\\Texture.h"

void LoadResources()
{
	ResourceManager::Load<Texture>(L"BG", L"..\\Resources\\Earth.png");
}
