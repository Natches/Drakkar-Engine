#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Resource/Resource.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>

namespace drak {
namespace gfx {
class IShader;
} //namespace gfx

class ShaderManager final {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(ShaderManager)

public:
	ShaderPtr get(const std::string& name) const;
	void preload(const std::string& name);
	void load(const std::string& name, const std::string& vertFile, const std::string& fragFile);
	void unload(const std::string& name);
	void reload(const std::string& name);
	bool contain(const std::string& name)const;

private:
	ShaderManager() = default;
	virtual ~ShaderManager() = default;
	ShaderMap m_map;
};

} // namespace drak