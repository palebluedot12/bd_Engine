#pragma once
#include "CommonInclude.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include "Camera.h"

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
	static bool Intersect(Collider* left, Collider* right);
	static std::vector<GameObject*> GetVisibleObjects(const Camera* camera, const std::vector<GameObject*>& objects);

private:
	// ����Ƽó�� �浹 ���̾� ����. �浹 ������ ������Ʈ�鳢���� üũ
	static std::bitset<(UINT)eLayerType::Max> m_CollisionLayerMatrix[(UINT)eLayerType::Max];
	static std::unordered_map<UINT64, bool> m_CollisionMap;
};

