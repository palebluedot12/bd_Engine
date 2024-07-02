#include "PlayScene.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\SpriteRenderer.h"
#include "..\\bdEngine\InputManager.h"
#include "..\\bdEngine\\SceneManager.h"
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
		bg = new Player();
		Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\D2D\\bd_Engine\\Resources\\Earth.png");

		AddGameObject(bg, eLayerType::BackGround);
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
}

void PlayScene::OnEnter()
{
}

void PlayScene::OnExit()
{
	Transform* tr = bg->GetComponent<Transform>();
	tr->SetPos(Vector2(0, 0));
}
