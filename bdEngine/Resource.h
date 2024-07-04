#pragma once
#include "Entity.h"

class Resource abstract : public Entity // �߻� Ŭ���� => �޸� �Ҵ� X, ��ӹ޾Ƽ��� ���
{
public:
	Resource(eResourceType type);
	virtual ~Resource();

	virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ�

	const std::wstring& GetPath() { return m_Path; }
	void SetPath(const std::wstring& path) { m_Path = path; }

private:
	const eResourceType m_Type;
	std::wstring m_Path;
};

//Resource test;
//class Texture : public Resource;
//class AudioClip : public Resource;