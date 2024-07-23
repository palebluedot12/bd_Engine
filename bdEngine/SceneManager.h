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

		// ActiveScene���� ���� �����ָ� Object���鶧 ���� ���� null�� 
		m_ActiveScene = scene;
		scene->Initialize();

		m_Scene.insert(std::make_pair(name, scene));

		return scene;
	}
	static Scene* LoadScene(const std::wstring& name);
	static Scene* GetActiveScene() { return m_ActiveScene; }

	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(ID2D1RenderTarget* pRenderTarget);
	static void Destroy();

private:
	static std::map<std::wstring, Scene*> m_Scene;
	static Scene* m_ActiveScene;
};