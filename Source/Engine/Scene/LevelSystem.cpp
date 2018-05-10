#include <PrecompiledHeader/pch.hpp>
//#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
//#include <Serialization\Serializer.hpp>
//#include <Engine\Engine.hpp>
//#include <fstream>
//#include <PxPhysicsAPI.h>
using namespace drak;
using namespace core;
using namespace serialization;
using namespace components;

LevelSystem::LevelSystem() {

}

LevelSystem::~LevelSystem() {
}

void drak::LevelSystem::SerializeLevel() {
	Serializer::SerializeToFile<EExtension::JSON, LevelSystem>(*this, "./", "Scene");
}

void LevelSystem::loadScene(const char* name) {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Load and build Scene from file\n");
	std::string file;
	file += "./";
	file += name;
	Serializer::LoadFromFile<EExtension::JSON, LevelSystem>(*this, file.c_str());
	for (U32 i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i].setLevel(this);
	}
}

void LevelSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*this);
}

bool LevelSystem::startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_DOWN,
		new function::MemberFunction<LevelSystem, void, const events::Event*>(this, &LevelSystem::SerializeEvent, &events::Keyboard::Get().event()));
	return true;
}

void LevelSystem::moveChildren(const Transform& parentTransform, const std::vector<U32>& children) {
	for (U32 i = 0; i < children.size(); ++i) {
		m_gameObjects[children[i]].getComponent<Transform>().globalPosition = parentTransform.globalPosition + math::Rotate(parentTransform.globalRotation, m_gameObjects[children[i]].getComponent<Transform>().localPosition);
		m_gameObjects[children[i]].getComponent<Transform>().globalRotation = parentTransform.globalRotation * m_gameObjects[children[i]].getComponent<Transform>().localRotation;
		m_gameObjects[children[i]].getComponent<Transform>().globalScale = parentTransform.globalScale * m_gameObjects[children[i]].getComponent<Transform>().localScale;
		m_gameObjects[children[i]].getComponent<Transform>().dirty = true;
		moveChildren(m_gameObjects[children[i]].getComponent<Transform>(), m_gameObjects[children[i]].children());
	}
}

void drak::LevelSystem::propogateMovementFromRoots() {
	for (I32 i = 0; i < m_rootIdxs.size(); ++i) {
		moveChildren(m_gameObjects[m_rootIdxs[i]].getComponent<Transform>(), m_gameObjects[m_rootIdxs[i]].children());
	}
}

void LevelSystem::SerializeEvent(const events::Event* pEvent) {
	if (!pEvent)
		return;
	const  events::KeyEvent* ke = static_cast<const  events::KeyEvent*>(pEvent);
	if (ke->key == events::Key::KEY_SPACE)
		SerializeLevel();
}

void LevelSystem::shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
	SerializeLevel();
}