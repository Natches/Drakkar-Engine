#include <Core/Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Core/Scene/SceneSystem.h>
#include <Core/Timer/FrameTimer.hpp>
DK_LOG_CATEGORY_DEFINE(EngineLog)
DK_LOG_CATEGORY_DECLARE(EngineLog, ELoggerVerbosity::DEBUG)
namespace drak {

	time::FrameTimer& core::Engine::s_frameTime = time::FrameTimer();
namespace core {
	bool Engine::running = true;

	int Engine::startup()
	{
		DK_LOG(EngineLog, ELoggerVerbosity::DEBUG, "Init systems\n")
		//Init systems
		SceneSystem::Startup();
		s_frameTime.start();
		return 0;
	}

	int Engine::shutdown()
	{
		DK_LOG(EngineLog, ELoggerVerbosity::DEBUG, "Shutdown systems\n")
		SceneSystem::Shutdown();
		return 0;
	}

	void Engine::startLoop()
	{
		Scene* scene = SceneSystem::GetScene();
		std::list<AGameObject*> gameObjects = scene->GetGameObjects();
		std::list<AGameObject*>::iterator it = gameObjects.begin();
		while (it != gameObjects.end())
		{
			(*it)->Start();
			std::advance(it, 1);
		}
		while (running)
		{
			s_frameTime.update();
			DK_LOG(EngineLog, ELoggerVerbosity::DEBUG,"DeltaTime: %f\n",s_frameTime.deltaTime());
			std::list<AGameObject*> gameObjects = scene->GetGameObjects();
			std::list<AGameObject*>::iterator it = gameObjects.begin();
			for (unsigned int i = 0; i < gameObjects.size(); ++i)
			{
				(*it)->Update();
				std::advance(it, 1);
			}
		}
	}

 void Engine::stopGame()
	{
		Engine::running = false;
	}

} // namespace core
} // namespace drak