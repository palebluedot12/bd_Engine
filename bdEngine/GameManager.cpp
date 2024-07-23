#include "GameManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Time.h"
#include <d2d1.h>

#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")

GameManager::GameManager()
   
{
}

GameManager::~GameManager()
{
   
}

void GameManager::Initialize(HWND hwnd)
{
    RenderManager::Get()->Initialize(hwnd);
    Input::Initailize();
    Time::Initailize();
    CollisionManager::Initialize();
    SceneManager::Initialize();
}

void GameManager::Run()
{
	Update();
	LateUpdate();
	Render();
    Destroy();
}

void GameManager::Update()
{
    Input::Update();
    Time::Update();
    CollisionManager::Update();
    SceneManager::Update();

    //mSpeed += 1.0f;
}

void GameManager::LateUpdate()
{
    CollisionManager::LateUpdate();
    SceneManager::LateUpdate();
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

    Time::Render(RenderManager::Get()->GetRenderTarget());
    CollisionManager::Render(RenderManager::Get()->GetRenderTarget());
    SceneManager::Render(RenderManager::Get()->GetRenderTarget());

    RenderManager::Get()->GetRenderTarget()->EndDraw();

}

void GameManager::Destroy()
{
    SceneManager::Destroy();
}
