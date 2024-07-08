#pragma once

// 업데이트 순서
enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Script,
	Camera,
	End,
};

//업데이트 순서
enum class eLayerType
{
	None,
	BackGround,
	//Tree 
	//character
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