#include <PrecompiledHeader/pch.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>
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
	Serializer::LoadFromFile<EExtension::JSON, LevelSystem>(*this, "./Scene");
	for (U32 i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i].setLevel(this);
	}
}

void LevelSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*this);
}

bool LevelSystem::startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	//events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_DOWN,
	//	new function::MemberFunction<LevelSystem, void, const events::Event*>(this, &LevelSystem::SerializeEvent, &events::Keyboard::Get().event()));

	return true;
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