#include "PlayScene.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\SpriteRenderer.h"
#include "..\\bdEngine\InputManager.h"
#include "..\\bdEngine\\SceneManager.h"
#include "..\\bdEngine\\Object.h"
#include "..\\bdEngine\\RenderManager.h"
#include "..\\bdEngine\\ResourceManager.h"
#include "..\\bdEngine\\Texture.h"
#include "TitleScene.h"
#include "Player.h"


PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	// // 오브젝트 추가
	//GameObject* obj = new GameObject();
	//AddGameObject(obj);

	{
		//bg = new Player();
		//Transform* tr
		//	= bg->AddComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));

		//tr->SetName(L"TR");

		//SpriteRenderer* sr
		//	= bg->AddComponent<SpriteRenderer>();
		//sr->SetName(L"SR");
		//sr->ImageLoad(L"C:\\D2D\\bd_Engine\\Resources\\Earth.png");

		//AddGameObject(bg, eLayerType::BackGround);
		bg = Instantiate<Player>(eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		
		Texture* bg = ResourceManager::Find<Texture>(L"BG");
		sr->S

	}
}

void PlayScene::Update()
{
	Scene::Update();
}

void PlayScene::LateUpdate()
{
}

void PlayScene::Render(ID2D1RenderTarget* pRenderTarget)
{
	Scene::Render(pRenderTarget);
}

void PlayScene::OnEnter()
{
}

void PlayScene::OnExit()
{
	//Transform* tr = bg->GetComponent<Transform>();
	//tr->SetPosition(Vector2(0, 0));
}
