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
	//���ӿ�����Ʈ ��������� ���ҽ��� ���� Load�صθ� ����.
	bg = Instantiate<Player>
		(eLayerType::BackGround, Vector2(300.0f, -50.0f));
	SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

	Texture* bg = ResourceManager::Find<Texture>(L"BG");
	sr->SetTexture(bg);

	// ���� ������Ʈ �����Ŀ� ���̾�� ���ӿ�����Ʈ���� init�Լ��� ȣ��
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
