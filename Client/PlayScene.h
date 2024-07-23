#pragma once
#include "..\\bdEngine\\Scene.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(ID2D1RenderTarget* pRenderTarget) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:
	class Player* m_Player;
	int m_Time;
	GameObject* cat;

public:
	Player* GetPlayer() const { return m_Player; }
};