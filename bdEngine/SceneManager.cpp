#include "SceneManager.h"

std::map<std::wstring, Scene*> SceneManager::m_Scene = {};
Scene* SceneManager::m_ActiveScene = nullptr;

void SceneManager::Initialize()
{
}

void SceneManager::Update()
{
	m_ActiveScene->Update();
}

void SceneManager::LateUpdate()
{
	m_ActiveScene->LateUpdate();
}

void SceneManager::Render(ID2D1RenderTarget* pRenderTarget)
{
	m_ActiveScene->Render(pRenderTarget);
}
