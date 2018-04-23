#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Serialization\Serializer.hpp>
#include <Engine\Engine.hpp>
#include <fstream>
#include <PxPhysicsAPI.h>
using namespace drak;
using namespace core;
using namespace serialization;
using namespace components;

LevelSystem::LevelSystem() {

}

LevelSystem::~LevelSystem() {
	for (unsigned int i = 0; i < m_gameObjects.size(); ++i) {
		delete m_gameObjects[i];
	}
}

void drak::LevelSystem::SerializeLevel() {
	std::stringstream out;
	Serialize<EExtension::JSON>(out);
	std::fstream file;
	file.open("Scene.json", std::fstream::out);
	if (file.is_open()) {
		file << out.rdbuf();
		file.close();
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
	drak::serialization::Serializer::LoadFile<EExtension::JSON, LevelSystem>(*this, "Scene");
	return true;
}

void LevelSystem::shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
	SerializeLevel();
}