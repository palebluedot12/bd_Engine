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
#include "..\\bdEngine\\Camera.h"
#include "PlayerScript.h"
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
	// Main Camera
	GameObject* cameraObj = Instantiate<GameObject>(eLayerType::None);
	Camera* cameraComp = cameraObj->AddComponent<Camera>();
	mainCamera = cameraComp;

	//camera->AddComponent<PlayerScript>();

	PlayerScript* cameraScript = cameraObj->AddComponent<PlayerScript>();
	cameraScript->SetCamera(cameraComp);

	m_Player = Instantiate<Player>
		(eLayerType::BackGround, Vector2(300.0f, 50.0f));
	SpriteRenderer* sr = m_Player->AddComponent<SpriteRenderer>();
	sr->SetSize(100.0f, 100.0f);
	//m_Player->AddComponent<PlayerScript>();
	Texture* bgtex = ResourceManager::Find<Texture>(L"BG");
	sr->SetTexture(bgtex);

	GameObject* sun = Instantiate<GameObject>(eLayerType::Object, Vector2(400.0f, .0f));
	SpriteRenderer* sr2 = sun->AddComponent<SpriteRenderer>();
	sr2->SetSize(500.0f, 500.0f);
	Texture* bg2tex = ResourceManager::Find<Texture>(L"Sun");
	sr2->SetTexture(bg2tex);
	
	// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
	Scene::Initialize();
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
