#pragma once
#include "..\\bdEngine\\Scene.h"

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render() override;

private:

};