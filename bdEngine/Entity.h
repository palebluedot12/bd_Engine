#pragma once
#include "CommonInclude.h"

// �̸� �����ֱ� ���� �뵵
class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetName(const std::wstring& name) { mName = name; }
	std::wstring& GetName() { return mName; }

private:
	std::wstring m_Name;
};

