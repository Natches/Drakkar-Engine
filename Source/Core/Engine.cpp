#include <Core/Engine.hpp>
DK_LOG_CATEGORY_DEFINE(EngineLog)
DK_LOG_CATEGORY_DECLARE(EngineLog, LoggerVerbosity::DEBUG)
namespace drak {
namespace core {



	SceneSystem& Engine::GetSceneSystem()
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
		while (running)
		{

		}
	}

	void Engine::stopGame()
	{
		running = false;
	}

} // namespace core
} // namespace drak