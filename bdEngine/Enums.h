#pragma once

// 업데이트 순서
enum class eComponentType
{
	Transform,
	Collider,
	Script,
	SpriteRenderer,
	Animator,
	Camera,
	End,
};

//업데이트 순서
enum class eLayerType
{
	None,
	BackGround,
	//Tree 
	Object,
	Player,
	Max = 16,
};

enum class eResourceType
{
	Texture,
	AudioClip,
	Prefab,
	End,
};

enum class eColliderType
{
	Circle2D,
	Rect2D,
	End,
};