#pragma once
#include "Entity.h"
#include "Component.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	void ImageLoad(const std::wstring& path);

private:
	ID2D1Bitmap* m_pBitmap = nullptr;

};