#pragma once

// ������Ʈ ����
enum class eComponentType
{
	Transform,
	SpriteRenderer,
	Script,
	Camera,
	End,
};

//������Ʈ ����
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