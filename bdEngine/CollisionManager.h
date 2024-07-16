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
	// 유니티처럼 충돌 레이어 만듦. 충돌 감지할 오브젝트들끼리만 체크
	static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
	static std::unordered_map<UINT64, bool> mCollisionMap;	// 충돌중인지 아닌지

};

