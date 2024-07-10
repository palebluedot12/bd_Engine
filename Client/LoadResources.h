#pragma once
#include "..\\bdEngine\\ResourceManager.h"
#include "..\\bdEngine\\Texture.h"

void LoadResources()
{
	ResourceManager::Load<Texture>(L"BG", L"..\\Resources\\Earth.png");
	ResourceManager::Load<Texture>(L"Sun", L"..\\Resources\\Sun.png");
	ResourceManager::Load<Texture>(L"Stars", L"..\\Resources\\stars.png");
	ResourceManager::Load<Texture>(L"Star", L"..\\Resources\\star.png");


}
