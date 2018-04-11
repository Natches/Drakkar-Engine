#pragma once

#include <memory>
#include <unordered_map>

#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

template<class R>
class ResourceManager {
public:
	virtual ~ResourceManager() = default;

	using ResourcePtr = std::shared_ptr<R>;
	virtual ResourcePtr preloadResource(const std::string& filename);
	virtual ResourcePtr loadResource(const std::string& filename);

protected:
	virtual ResourcePtr loadImpl(const std::string& filename) = 0;

protected:
	friend void ResourceSystem::startup();
	ResourceManager() = default;

protected:
	using ResourceMap = std::unordered_map<std::string, ResourcePtr>;
	ResourceMap m_resources;
};

} // namespace drak