#include <ResourceManager/Manager/Base/AResourceManager.hpp>

namespace drak {

template<typename T, typename Map>
ResourcePtr<T> AResourceManager<T, Map>::get(const std::string& name) {
	if (m_map.find(name) != m_map.end())
		return m_map.at(name);
	else
		return nullptr;
}

template<typename T, typename Map>
typename Resource<T>::ELoadState AResourceManager<T, Map>::state(const std::string& name) const {
	if (m_map.find(name) != m_map.end())
		return m_map.at(name)->loadState();
	else
		return Resource<T>::ELoadState::UNKNOWN;
}


template<typename T, typename Map>
void AResourceManager<T, Map>::preload(const std::string& filename) {
	if (m_map.find(filename) == m_map.end())
		m_map[filename] = ResourcePtr<T>();
}

template<typename T, typename Map>
void AResourceManager<T, Map>::unload(const std::string& name) {
	m_map[name].reset();
	m_map.erase(name);
}

template<typename T, typename Map>
bool AResourceManager<T, Map>::contain(const std::string& name) const {
	return m_map.find(name) != m_map.end();
}

} // namespace drak