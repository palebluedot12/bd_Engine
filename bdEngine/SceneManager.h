#pragma once
#include "Scene.h"

class SceneManager
{
public:
	template <typename T>
	static Scene* CreateScene(const std::wstring& name)
	{
		T* scene = new T();
		scene->SetName(name);
		scene->Initialize();

		m_Scene.insert(std::make_pair(name, scene));

		return scene;
	}
	static Scene* LoadScene(const std::wstring& name)
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

	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(ID2D1RenderTarget* pRenderTarget);

private:
	static std::map<std::wstring, Scene*> m_Scene;
	static Scene* m_ActiveScene;
};