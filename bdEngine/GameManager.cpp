#include "GameManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include <d2d1.h>

#pragma comment(lib, "d2d1")


GameManager::GameManager()
   
{
}

GameManager::~GameManager()
{
   
}

// DC ��� D2D �޼ҵ��� ��ü
void GameManager::Initialize(HWND hwnd)
{
    Input::Initailize();
}

void GameManager::Run()
{
	Update();
	LateUpdate();
	Render();
}

void GameManager::Update()
{
    Input::Update();

    //mSpeed += 1.0f;
}

void GameManager::LateUpdate()
{
}

void GameManager::Render()
{
    // clearRenderTarget
    // Time::Render
    // SceneManager::Render => ActiveSceneã�Ƽ� Render
    // ���������!--------------------------------------
    // 
    // ���������δ� -------------------------------------
    // Scene::Render
    // Layer �������� Render
    // GameObj�� ����..
    // Component�� ����...
    RenderManager::Render();

}