#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/ModelManager.hpp>
#include <Converter/ResourceDefinitions.hpp>

using namespace drak::core;
using namespace drak::geom;
using namespace drak::gfx;
using namespace drak::definition;

namespace drak {

void ModelManager::preload(const std::string& names) {
	Base::preload(names);
}

void ModelManager::preload(const ResourceName& rName) {
	for (auto name : rName.names) {
		if ((name.second & EFileType::MODEL) == EFileType::MODEL)
			m_map[name.first] = ModelPtr((Resource<gfx::Model>*)(new char[sizeof(Resource<gfx::Model>)]));
	}
}

void ModelManager::load(const std::string& filename, std::vector<definition::Model>& inModels) {
	for (auto& model : inModels) {

		new (m_map[model.mesh].get()) Resource<gfx::Model>(filename,
			gfx::Model(model.mesh, model.material));

		m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::READY);
	}
}

void ModelManager::reload(std::vector<definition::Model>& inModels) {
	for (auto& model : inModels) {
		m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::LOADING);

		new (&m_map[model.mesh]->m_resource) gfx::Model(model.mesh, model.material);

		m_map[model.mesh]->loadState(Resource<gfx::Model>::ELoadState::READY);
	}
}

} // namespace drak