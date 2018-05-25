#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/MaterialManager.hpp>
#include <Converter/ResourceDefinitions.hpp>

using namespace drak::core;
using namespace drak::geom;
using namespace drak::gfx;
using namespace drak::definition;

namespace drak {

void MaterialManager::preload(const std::string& names, const std::string& filename) {
	Base::preload(names, filename);
}

void MaterialManager::preload(const ResourceName& rName, const std::string& filename) {
	for (auto name : rName.names) {
		if (name.second == EFileType::MATERIAL)
			m_map[name.first] = MaterialPtr(new Resource<gfx::Material>(filename));
	}
}

void MaterialManager::load(const std::string& filename, std::vector<definition::Material>& inMaterials) {
	for (auto& material : inMaterials) {
		if (!m_map[material.name].get())
			m_map[material.name].reset(new Resource<gfx::Material>(filename));
		new (m_map[material.name].get()) Resource<gfx::Material>(filename,
			gfx::Material(material.name, std::move(material.albedo), std::move(material.normal),
				std::move(material.diffuseColor), std::move(material.specularColor),
				std::move(material.ambientColor), std::move(material.transparentColor),
				material.opacity, material.shininess, material.shininessStrength,
				material.wireframe, material.twoSided));

		m_map[material.name]->loadState(Resource<gfx::Material>::ELoadState::READY);
	}
}

void MaterialManager::reload(std::vector<definition::Material>& inMaterials) {
	for (auto& material : inMaterials) {
		m_map[material.name]->loadState(Resource<gfx::Material>::ELoadState::LOADING);
		new (&m_map[material.name]->m_resource)
			gfx::Material(material.name, std::move(material.albedo), std::move(material.normal),
				std::move(material.diffuseColor), std::move(material.specularColor),
				std::move(material.ambientColor), std::move(material.transparentColor),
				material.opacity, material.shininess, material.shininessStrength,
				material.wireframe, material.twoSided);

		m_map[material.name]->loadState(Resource<gfx::Material>::ELoadState::READY);
	}
}

} // namespace drak