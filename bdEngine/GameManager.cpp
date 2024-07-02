#include "GameManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "Time.h"
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
    RenderManager::Get()->Initialize(hwnd);
    Input::Initailize();
    Time::Initailize();
    SceneManager::Initialize();
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
    Time::Update();
    SceneManager::Update();

    //mSpeed += 1.0f;
}

void GameManager::LateUpdate()
{
}

void GameManager::Render()
{
    // clearRenderTarget
    // Time::Render
    // SceneManager::Render (ActiveSceneã�Ƽ� Render)
    // ���⿣ ��ױ�����!--------------------------------------
    // 
    // ���������δ� -------------------------------------
    // Scene::Render
    // Layer �������� Render
    // GameObj�� ����..
    // Component�� ����...

    RenderManager::Get()->GetRenderTarget()->BeginDraw();
    RenderManager::Get()->GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::Black));

    Time::Render(pRenderTarget);
    SceneManager::Render(pRenderTarget);

    RenderManager::Get()->GetRenderTarget()->EndDraw();

}