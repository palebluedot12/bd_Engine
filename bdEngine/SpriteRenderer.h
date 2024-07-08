#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void SetTexture(Texture* texture) { m_Texture = texture; }
	void SetSize(Vector2 size) { m_Size = size; m_UseCustomSize = true; }

private:
	Vector2 m_Size;
	Texture* m_Texture;
	bool m_UseCustomSize;
};