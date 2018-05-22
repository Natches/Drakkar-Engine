#include <ResourceManager/Resource/Resource.hpp>

namespace drak {
template<typename T>
Resource<T>::Resource(const std::string& filename) 
	: m_filename(filename), m_loadState(ELoadState::PENDING) {
}
template<typename T>
Resource<T>::Resource(const std::string& filename, T&& resource) 
	: m_resource(std::move(resource)), m_filename(filename), m_loadState(ELoadState::READY) {
}

template<typename T>
Resource<T>::Resource(Resource&& resource) 
	: m_resource(std::move(resource.m_resource)), m_filename(std::move(resource.m_filename)),
	m_loadState(resource.m_loadState) {
}

template<typename T>
Resource<T>::Resource() {
	if constexpr(std::is_pointer_v<T>)
		delete m_resource;
}

template<typename T>
Resource<T>& Resource<T>::operator=(Resource&& resource) {
	m_resource = std::move(resource.m_resource);
	m_filename = std::move(resource.m_filename);
	m_loadState = resource.m_loadState;
}

} // namespace drak