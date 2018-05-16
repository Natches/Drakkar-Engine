#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/AResource.hpp>
#include <ResourceManager/IResourceManager.hpp>
#include <ResourceManager/ResourceDefinitions.hpp>

namespace drak {

namespace geom {
class AMesh;
} //namespace geom

class MeshManager final : public IResourceManager<AMesh> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(MeshManager)

public:
	virtual ResourcePtr<geom::AMesh> get(const std::string& name) const override;
	virtual AResource::ELoadState state(const std::string& name) const override;
	virtual void registerResource(ResourcePtr<geom::AMesh>&& res) override;
	virtual void unRegister(const std::string & name) override;

private:
	MeshManager();

private:
	MeshMap m_meshes;
};

} // namespace drak