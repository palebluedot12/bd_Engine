#include "SceneManager.h"

std::map<std::wstring, Scene*> SceneManager::m_Scene = {};
Scene* SceneManager::m_ActiveScene = nullptr;

Scene* SceneManager::LoadScene(const std::wstring& name)
{
	if (m_ActiveScene)
		m_ActiveScene->OnExit();

	// 없으면 end 반환함
	std::map<std::wstring, Scene*>::iterator iter
		= m_Scene.find(name);

	if (iter == m_Scene.end())
		return nullptr;

	m_ActiveScene = iter->second;
	m_ActiveScene->OnEnter();

	return iter->second;
}

void SceneManager::Initialize()
{
	//m_ActiveScene->Initialize();
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
