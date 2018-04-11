#include <ResourceManager/ResourceManager.hpp>

namespace drak {

ResourceManager::~ResourceManager() {

}

ResourcePtr ResourceManager::createResource(const std::string& filename) {
	auto resLoc = m_resources.find(filename);
	if (resLoc == m_resources.end())
		return std::make_shared<Resource>(filename);
	return resLoc->second;
}

} // namespace drak