#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/TextureManager.hpp>
#include <Converter/ResourceDefinitions.hpp>

using namespace drak::core;
using namespace drak::geom;
using namespace drak::gfx;
using namespace drak::definition;

namespace drak {

void TextureManager::preload(const ResourceName& rName) {
	for (auto name : rName.names) {
		if (name.second == EFileType::TEXTURE)
			m_map[name.first] = TexturePtr();
	}
}

void TextureManager::load(const std::string& filename, std::vector<definition::Texture>& inTextures) {
	for (auto& texture : inTextures) {

		new (m_map[texture.name].get()) Resource<gfx::Texture>(filename,
			gfx::Texture(texture.name, std::move(texture.pixels),
				texture.width, texture.height, texture.format, texture.channels));

		m_map[texture.name]->loadState(Resource<gfx::Texture>::ELoadState::READY);
	}
}

void TextureManager::reload(std::vector<definition::Texture>& inTextures) {
	for (auto& texture : inTextures) {
		m_map[texture.name]->loadState(Resource<gfx::Texture>::ELoadState::LOADING);

		new (&m_map[texture.name]->m_resource)
			gfx::Texture(texture.name, std::move(texture.pixels),
			texture.width, texture.height, texture.format, texture.channels);

		m_map[texture.name]->loadState(Resource<gfx::Texture>::ELoadState::READY);
	}
}

} // namespace drak