#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/ModelManager.hpp>
#include <Converter/ResourceDefinitions.hpp>

using namespace drak::core;
using namespace drak::geom;
using namespace drak::gfx;
using namespace drak::definition;

namespace drak {

void ModelManager::preload(const std::string& names, const std::string& filename) {
	Base::preload(names, filename);
}

void ModelManager::preload(const ResourceName& rName, const std::string& filename) {
	for (auto& name : rName.names) {
		if ((name.second & EFileType::MODEL) == EFileType::MODEL && name.first.c_str() != "")
			m_map[name.first] = ModelPtr(new Resource<gfx::Model>(filename));
	}
}

void ModelManager::load(const std::string& filename, std::vector<definition::Model>& inModels) {
	for (auto& model : inModels) {
		if (model.mesh.c_str() != "") {
			if (!m_map[model.mesh].get())
				m_map[model.mesh].reset(new Resource<gfx::Model>(filename));
			new (m_map[model.mesh].get()) Resource<gfx::Model>(filename,
				gfx::Model(model.mesh, model.material, model.skinned));

			m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::READY);
		}
	}
}

void ModelManager::reload(std::vector<definition::Model>& inModels) {
	for (auto& model : inModels) {
		m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::LOADING);

		new (&m_map[model.mesh]->m_resource) gfx::Model(model.mesh, model.material, model.skinned);

		m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::READY);
	}
}

} // namespace drak