#pragma once
#include "Resource.h"

class ResourceManager
{
public:
	template <typename T>
	static T* Find(const std::wstring& key)
	{
		auto iter = m_Resources.find(key);
		if (iter == m_Resources.end())
			return nullptr;

		return dynamic_cast<T*>(iter->second);
	}

	template <typename T>
	static T* Load(const std::wstring& key, const std::wstring& path)
	{
		T* resource = ResourceManager::Find<T>(key);
		if (resource != nullptr)
			return resource;

		resource = new T();
		if (FAILED(resource->Load(path)))
			assert(false);

		resource->SetName(key);
		resource->SetPath(path);
		m_Resources.insert(std::make_pair(key, resource));

		return resource;
	}

private:
	static std::map<std::wstring, Resource*> m_Resources;
};

