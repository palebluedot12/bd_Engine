#pragma once
#include "CommonInclude.h"

// 이름 지어주기 위한 용도
class Entity
{
public:
	Entity();
	virtual ~Entity();

	void SetName(const std::wstring& name) { m_Name = name; }
	std::wstring& GetName() { return m_Name; }

private:
	std::wstring m_Name;
};

