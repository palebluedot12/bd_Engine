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
	void SetSize(float x, float y) { m_Size.x = x; m_Size.y = y; m_UseCustomSize = true; }
	Vector2 GetSize() const { return m_Size; }

private:
	Vector2 m_Size;
	Texture* m_Texture;
	bool m_UseCustomSize;

};