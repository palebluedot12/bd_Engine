#pragma once
#include "CommonInclude.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"

union CollisionID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 id;
};

class CollisionManager
{
public:
	static void Initialize();
	static void Update();
	static void LateUpdate();
	static void Render(ID2D1RenderTarget* pRenderTarget);

	static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
	static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
	static void ColliderCollision(Collider* left, Collider* right);

private:
	// ����Ƽó�� �浹 ���̾� ����. �浹 ������ ������Ʈ�鳢���� üũ
	static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	static std::unordered_map<UINT64, bool> mCollisionMap;	// �浹������ �ƴ���

};

