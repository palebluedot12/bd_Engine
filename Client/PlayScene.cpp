#include "PlayScene.h"
#include "..\\bdEngine\\GameObject.h"
#include "..\\bdEngine\\Transform.h"
#include "..\\bdEngine\\SpriteRenderer.h"
#include "..\\bdEngine\InputManager.h"
#include "..\\bdEngine\\SceneManager.h"
#include "..\\bdEngine\\Object.h"
#include "..\\bdEngine\\RenderManager.h"
#include "..\\bdEngine\\ResourceManager.h"
#include "..\\bdEngine\\CollisionManager.h"
#include "..\\bdEngine\\Texture.h"
#include "..\\bdEngine\\Camera.h"
#include "PlayerScript.h"
#include "ChickenScript.h"
#include "TitleScene.h"
#include "Player.h"
#include "..\\bdEngine\\CommonInclude.h"
#include "..\\bdEngine\\BoxCollider2D.h"
#include "..\\bdEngine\\CircleCollider2D.h"
#include "..\\bdEngine\\Animator.h"
#include "Chicken.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Object, true);

	// ī�޶� ������Ʈ ����
	GameObject* cameraObj = Instantiate<GameObject>(eLayerType::None);
	Camera* cameraComp = cameraObj->AddComponent<Camera>();
	mainCamera = cameraComp;

	// �÷��̾� ����
	m_Player = Instantiate<Player>(eLayerType::Player, Vector2(784.0f, 434.0f));
	PlayerScript* playerScript = m_Player->AddComponent<PlayerScript>();
	
	// ī�޶� ���� ������ �� �ְ�
	//playerScript->SetCamera(cameraComp);

	// ī�޶� Ư�� ������Ʈ�� ����ٴϰ�
	cameraComp->SetTarget(m_Player);

	Texture* catTexture = ResourceManager::Find<Texture>(L"Cat");
	Animator* animator = m_Player->AddComponent<Animator>();
	animator->CreateAnimation(L"DownWalk", catTexture,
		Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"RightWalk", catTexture,
		Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"UpWalk", catTexture,
		Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"LeftWalk", catTexture,
		Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"SitDown", catTexture,
		Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
	animator->CreateAnimation(L"Grooming", catTexture,
		Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

	animator->PlayAnimation(L"SitDown", false);
	m_Player->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));

	Chicken* chicken = Instantiate<Chicken>(eLayerType::Player, Vector2(200.0f, 50.0f));
	ChickenScript* chickenScript = chicken->AddComponent<ChickenScript>();
	chickenScript->SetPlayScene(this);
	Texture* ckTex = ResourceManager::Find<Texture>(L"Chicken");
	Animator* ckAnimator = chicken->AddComponent<Animator>();
	ckAnimator->CreateAnimation(L"RightWalk", ckTex
		, Vector2(0.0f, 16.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);
	ckAnimator->CreateAnimation(L"LeftWalk", ckTex
		, Vector2(0.0f, 48.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);
	ckAnimator->CreateAnimation(L"LeftSit", ckTex
		, Vector2(0.0f, 64.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 2, 0.1f);
	ckAnimator->CreateAnimation(L"Attack", ckTex
		, Vector2(0.0f, 96.0f), Vector2(16.0f, 16.0f), Vector2::Zero, 4, 0.1f);

	ckAnimator->PlayAnimation(L"LeftSit", false);
	chicken->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));
	BoxCollider2D* ckCol = chicken->AddComponent<BoxCollider2D>();

	GameObject* sun = Instantiate<GameObject>(eLayerType::Object, Vector2(500.0f, 300.0f));
	SpriteRenderer* sr2 = sun->AddComponent<SpriteRenderer>();
	sr2->SetSize(500.0f, 500.0f);
	Texture* bg2tex = ResourceManager::Find<Texture>(L"Sun");
	sr2->SetTexture(bg2tex);
	BoxCollider2D* sunCol = sun->AddComponent<BoxCollider2D>();

	// �� 100��
	for (int i = 0; i < 500; ++i)
	{
		float randomX = static_cast<float>(rand() % 5000 - 2500); 
		float randomY = static_cast<float>(rand() % 5000 - 2500);
		Vector2 randomPosition(randomX, randomY);

		GameObject* star = Instantiate<GameObject>(eLayerType::Object, randomPosition);

		SpriteRenderer* srStar = star->AddComponent<SpriteRenderer>();
		srStar->SetSize(50.0f, 50.0f);

		Texture* starTexture = ResourceManager::Find<Texture>(L"Star");
		srStar->SetTexture(starTexture);
		srStar->SetAlpha(0.5f);

		BoxCollider2D* starCol = star->AddComponent<BoxCollider2D>();
	}

	
	// ���� ������Ʈ �����Ŀ� ���̾�� ���ӿ�����Ʈ���� init�Լ��� ȣ��
	Scene::Initialize();
}

void PlayScene::Update()
{
	Scene::Update();
	//RenderManager::Get()->UpdateAndRender();

}

void PlayScene::LateUpdate()
{
}

void PlayScene::Render(ID2D1RenderTarget* pRenderTarget)
{
	Scene::Render(pRenderTarget);
	//RenderManager::Get()->UpdateAndRender();

}

void PlayScene::OnEnter()
{
}

void PlayScene::OnExit()
{
	//Transform* tr = bg->GetComponent<Transform>();
	//tr->SetPosition(Vector2(0, 0));
}
