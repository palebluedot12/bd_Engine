#pragma once
#include "Entity.h"

class Resource abstract : public Entity // 추상 클래스 => 메모리 할당 X, 상속받아서만 사용
{
public:
	Resource(eResourceType type);
	virtual ~Resource();

	virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수

	const std::wstring& GetPath() { return m_Path; }
	void SetPath(const std::wstring& path) { m_Path = path; }

private:
	const eResourceType m_Type;
	std::wstring m_Path;
};

//Resource test;
//class Texture : public Resource;
//class AudioClip : public Resource;