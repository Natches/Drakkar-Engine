#pragma once

#include <ResourceManager/ResourceDefinitions.hpp>

namespace std {
class string;
} //namespace std

namespace drak {
class AResource;

template<typename T>
class IResourceManager {
	virtual ResourcePtr<T> get(const std::string& name) const = 0;
	virtual AResource::ELoadState state(const std::string& name) const = 0;
	virtual void registerResource(ResourcePtr<T>&& res) = 0;
	virtual void unRegister(const std::string& name) = 0;
};

} //namespace drak