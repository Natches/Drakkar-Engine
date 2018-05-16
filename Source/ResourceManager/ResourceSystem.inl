#include <ResourceManager/ResourceSystem.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <Serialization/MetaData.hpp>
#include <Converter/ResourceDefinitions.hpp>

namespace drak {

template<typename T>
core::EError ResourceSystem::loadOrGet(const std::string& filename, ResourcePtr<T>& out) {
	using namespace serialization;
	static_assert(std::is_same_v<T, Model> || std::is_same_v<T, Mesh> || std::is_same_v<T, Texture> ||
		std::is_same_v<T, IShader>, "Type Non Recognized !!");
	core::EError err;
	if constexpr(std::is_same_v<T, Model> || std::is_same_v<T, Mesh> || std::is_same_v<T, Texture>) {
		/*if (io::AllExtension(filename.c_str()) == "drakResource.bin") {
			if constexpr(std::is_same_v<T, Model> || std::is_same_v<T, Mesh>)
			definition::Model inT;
			if ((err = Serializer::LoadFromFile(inT, filename)) != core::EError::NO_ERROR) {
				std::cout << "ResourceSystem : Error While Loading this file : " << filename << "\n";
				return err;
			}
		}
		else {
			m_converter.convert(1, &filename.c_str());
			definition::T inT;
			if ((err = Serializer::LoadFromFile(inT, std::string(io::FileNameNoExtension(filename)) + "drakResource.bin")) != core::EError::NO_ERROR) {
				std::cout << "ResourceSystem : Error While Loading this file : " << filename << "\n";
				return err;
			}
		}*/
	}
	else if constexpr (std::is_same_v<T, IShader>) {

	}
	return core::EError::NO_ERROR;
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