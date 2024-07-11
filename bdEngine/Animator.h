#pragma once
#include "Component.h"
#include "Animation.h"
#include <functional>

class Animator : public Component
{
public:
	struct Event
	{
		void operator=(std::function<void()> func)
		{
			mEvent = std::move(func);
		}

		void operator()()
		{
			if (mEvent)
				mEvent();
		}

		std::function<void()> mEvent;
	};

	struct Events
	{
		Event startEvent;
		Event completeEvent;
		Event endEvent;
	};

	Animator();
	~Animator();

	void Initialize() override;
	void Update()  override;
	void LateUpdate()  override;
	void Render(ID2D1RenderTarget* pRenderTarget)  override;

	void CreateAnimation(const std::wstring& name
		, Texture* spriteSheet
		, Vector2 leftTop
		, Vector2 size
		, Vector2 offset
		, UINT spriteLegth
		, float duration);
	void CreateAnimationByFolder(const std::wstring& name
		, const std::wstring& path
		, Vector2 offset, float duration);

	Animation* FindAnimation(const std::wstring& name);
	void PlayAnimation(const std::wstring& name, bool loop = true);

	Events* FindEvents(const std::wstring& name);
	std::function<void()>& GetStartEvent(const std::wstring& name);
	std::function<void()>& GetCompleteEvent(const std::wstring& name);
	std::function<void()>& GetEndEvent(const std::wstring& name);

	bool IsComplete() { return m_ActiveAnimation->IsComplete(); }

private:
	std::map<std::wstring, Animation*> m_Animations;
	Animation* m_ActiveAnimation;
	bool m_bLoop;										// 계속 반복할지?

	//Event
	std::map<std::wstring, Events*> m_Events;
};

