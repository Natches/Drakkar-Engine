#include "SceneSystem.h"
#include "Log.hpp"
DEFINE_CATEGORY(SCENE_SYSTEM_LOG)
DECLARE_CATEGORY(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG)
using namespace drak;
using namespace core;

SceneSystem::SceneSystem()
{
}


SceneSystem::~SceneSystem()
{
}

void SceneSystem::LoadScene(const char* name)
{
	DRAK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Load and build Scene from file/n")
}

void SceneSystem::LoadScene(IManualSceneBlueprint& sceneBluePrint)
{
	Scene scene;
	sceneBluePrint.Build(scene);
}

bool SceneSystem::Startup()
{
	DRAK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Startup Scene System\n")
	return true;
}

void SceneSystem::Shutdown()
{
	DRAK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Shutdown Scene System\n")
}

Scene::Scene()
{
}

Scene::~Scene()
{
}

void drak::core::MyTestSceneBlueprint::Build(Scene& scene)
{
	DRAK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Build manual scene for MyTestScene\n")
}
