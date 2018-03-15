#include <Core/Engine.hpp>
DK_LOG_CATEGORY_DEFINE(EngineLog)
DK_LOG_CATEGORY_DECLARE(EngineLog, LoggerVerbosity::DEBUG)
namespace drak {
namespace core {

	bool Engine::running = true;

	SceneSystem& Engine::getSceneSystem()
	{
		return sceneSystem;
	}

	int Engine::startup()
	{
		DK_LOG(EngineLog, LoggerVerbosity::DEBUG, "Init systems\n")
		//Init systems
		sceneSystem.Startup();
		return 0;
	}

	int Engine::shutdown()
	{
		DK_LOG(EngineLog, LoggerVerbosity::DEBUG, "Shutdown systems\n")
		sceneSystem.Shutdown();
		return 0;
	}

	void Engine::startLoop()
	{
		Scene* scene = sceneSystem.GetScene();
		std::list<AGameObject*> gameObjects = scene->GetGameObjects();
		std::list<AGameObject*>::iterator it = gameObjects.begin();
		while (it != gameObjects.end())
		{
			(*it)->Start();
			std::advance(it, 1);
		}
		while (running)
		{
			std::list<AGameObject*> gameObjects = scene->GetGameObjects();
			std::list<AGameObject*>::iterator it = gameObjects.begin();
			for (unsigned int i = 0; i < gameObjects.size(); ++i)
			{
				std::advance(it, i);
				(*it)->Update();
			}
		}
	}

 void Engine::stopGame()
	{
		Engine::running = false;
	}

} // namespace core
} // namespace drak