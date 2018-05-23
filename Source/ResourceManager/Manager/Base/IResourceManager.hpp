#pragma once

#include <string>
#include <ResourceManager/Resource/Resource.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>

namespace drak {

template<typename T>
class IResourceManager {
protected:
	virtual ~IResourceManager() = default;
	virtual ResourcePtr<T> get(const std::string& name) = 0;
	virtual typename Resource<T>::ELoadState state(const std::string& name) const = 0;
	virtual void preload(const definition::ResourceName& rNames) = 0;
	virtual void preload(const std::string& filename) = 0;
	virtual void unload(const std::string& name) = 0;
	virtual bool contain(const std::string& name) const = 0;
};

} //namespace drak