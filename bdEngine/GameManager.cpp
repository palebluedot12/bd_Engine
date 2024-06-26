#include "GameManager.h"
#include "InputManager.h"
#include <d2d1.h>

#pragma comment(lib, "d2d1")


GameManager::GameManager()
    : m_Hwnd(nullptr)
    , pFactory(nullptr)
    , pRenderTarget(nullptr)
    , pBrush(nullptr)
    , m_Speed(0)
{
}

GameManager::~GameManager()
{
    DiscardDeviceResources();
    if (pFactory) pFactory->Release();
}

// DC 대신 D2D 메소드들로 대체
void GameManager::Initialize(HWND hwnd)
{
	m_Hwnd = hwnd;
	//mHdc = GetDC(hwnd);
    D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory);
    CreateDeviceResources();

    m_Player.SetPosition(0, 0);

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

    m_Player.Update();

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

}