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

// DC 대신 D2D 메소드들로 대체
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
    // SceneManager::Render => ActiveScene찾아서 Render
    // 여기까지만!--------------------------------------
    // 
    // 내부적으로는 -------------------------------------
    // Scene::Render
    // Layer 루프돌며 Render
    // GameObj들 돌며..
    // Component들 돌며...
    RenderManager::Render();

}