#include <ResourceManager/ResourceManager.hpp>

namespace drak {

template<class R>
ResourcePtr ResourceManager<R>::preloadResource(const std::string& filename) {
	auto resLoc = m_resources.find(filename);
	if (resLoc == m_resources.end())
		m_resources[filename] = std::make_shared<Resource>(filename);
	return resLoc->second;
}

template<class R>
ResourcePtr ResourceManager<R>::loadResource(const std::string& filename) {
	
}

} // namespace drak