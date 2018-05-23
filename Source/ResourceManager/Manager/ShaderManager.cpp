#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/ShaderManager.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLShader.hpp>

namespace drak {

ShaderPtr ShaderManager::get(const std::string& name) const {
	if (m_map.find(name) != m_map.end())
		return m_map.at(name);
	else
		return nullptr;
}

void ShaderManager::preload(const std::string& name) {
	if (m_map.find(name) == m_map.end())
		m_map[name] = ShaderPtr();
}

void ShaderManager::load(const std::string& name, const std::string& vertFile, const std::string& fragFile) {
	new (m_map[name].get()) drak::Resource<gfx::IShader*>(vertFile + "," + fragFile, new gfx::gl::GLShader());
	std::string shaderPath("./Resource/Shader/");
	if (!m_map[name]->m_resource->loadFromFile(shaderPath + vertFile, shaderPath + fragFile)) {
		std::cout << "Failed to Load shader :" << name << std::endl;
		unload(name);
		return;
	}
	m_map[name]->loadState(Resource<gfx::IShader*>::ELoadState::READY);
}

void ShaderManager::unload(const std::string& name) {
	m_map[name].reset();
	m_map.erase(name);
}

void ShaderManager::reload(const std::string& name) {
	if (m_map[name]->loadState() == Resource<gfx::IShader*>::ELoadState::READY) {
		m_map[name]->loadState(Resource<gfx::IShader*>::ELoadState::LOADING);
		std::string vertFile(m_map[name]->filename().begin(),
			m_map[name]->filename().begin() + m_map[name]->filename().find(","));
		std::string fragFile(
			m_map[name]->filename().begin() + m_map[name]->filename().find(",") + 1,
			m_map[name]->filename().end());

		std::string shaderPath("./Resource/Shader/");
		if (!m_map[name]->m_resource->loadFromFile(shaderPath + vertFile, shaderPath + fragFile)) {
			std::cout << "Failed to Load shader :" << name << std::endl;
			unload(name);
			return;
		}
		m_map[name]->loadState(Resource<gfx::IShader*>::ELoadState::READY);
	}
}

bool ShaderManager::contain(const std::string & name) const {
	return m_map.find(name) != m_map.end();
}

} //namespace drak