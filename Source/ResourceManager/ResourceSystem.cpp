#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

core::EError ResourceSystem::unloadAll(const std::string& filename) {
	return core::EError();
}

core::EError ResourceSystem::reloadAll(const std::string& filename) {
	return core::EError();
}

core::EError ResourceSystem::startup() {
	// m_pModelManager = new ModelManager();
	return core::EError();
}

core::EError ResourceSystem::shutdown() {
	// delete m_pModelManager;
	return core::EError();
}

} // namespace drak