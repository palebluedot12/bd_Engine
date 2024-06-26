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

// DC ��� D2D �޼ҵ��� ��ü
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
    // SceneManager::Render => ActiveSceneã�Ƽ� Render
    // ���������!--------------------------------------
    // 
    // ���������δ� -------------------------------------
    // Scene::Render
    // Layer �������� Render
    // GameObj�� ����..
    // Component�� ����...

}