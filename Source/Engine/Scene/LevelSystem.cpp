#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>
using namespace drak;
using namespace core;

LevelSystem::LevelSystem() {

}

LevelSystem::~LevelSystem() {
	for (unsigned int i = 0; i < m_gameObjects.size(); ++i) {
		delete m_gameObjects[i];
	}
}

void LevelSystem::loadScene(const char* name) {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Load and build Scene from file\n");
}

void LevelSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*this);
}

bool LevelSystem::startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	return true;
}

void LevelSystem::shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
}