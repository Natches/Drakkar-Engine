#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

template<typename T>
core::EError ResourceSystem::loadOrGet(const std::string& filename, ResourcePtr<T>& out) {
	static_assert(std::is_same_v<T, Mesh> || std::is_same_v<T, Texture> ||
		std::is_same_v<T, Shader>, "Type Non Recognized !!")
	if constexpr(std::is_same_v<T, Model>) {

	}
	else if constexpr (std::is_same_v<T, Mesh>) {

	}
	else if constexpr (std::is_same_v<T, Texture>) {

	}
	else if constexpr (std::is_same_v<T, Shader>) {

	}
	return core::EError();
}

template<typename T>
core::EError ResourceSystem::unload(const std::string& filename) {
	return core::EError();
}

template<typename T>
core::EError ResourceSystem::reload(const std::string& filename, ResourcePtr<T>& out) {
	return core::EError();
}

} // namespace drak