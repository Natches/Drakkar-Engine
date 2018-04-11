#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Windowing/Window/AWindow.hpp>

using namespace drak::components;

namespace drak {
namespace core {
thread::ThreadPool core::Engine::s_pool;
bool Engine::running = true;

Engine::Engine() {

}

Engine::~Engine() {

}

PhysicsSystem& Engine::getPhysicsSystem()
{
	return physicsSystem;
}

DRAK_API time::FrameTimer& Engine::GetFrameTimer() {
	return s_frameTime;
}

int Engine::startup() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	video::WindowSettings	winSettings		= { "Drakkar Engine", 1600, 900 };
	video::VideoSettings	videoSettings	= { winSettings, gfx::ERenderer::OPENGL };

	// TODO (Simon): Check for failed startups
	videoSystem.startup(videoSettings, pMainWindow);
	renderSystem.startup(videoSystem.renderer());
	physicsSystem.Startup();
	levelSystem.startup();
	s_pool.startup();
	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	levelSystem.shutdown();
	physicsSystem.Shutdown();
	renderSystem.shutdown();
	videoSystem.shutdown();
	
	Logbook::CloseLogs();
	s_pool.shutdown();

	return 0;
}

void Engine::startLoop() {
	s_frameTime.start();

	std::vector<AGameObject*>& gameObjects = levelSystem.getGameObjects();
	for (auto g : gameObjects)
		g->start();
	
	while (pMainWindow->isOpen()) {
		s_frameTime.update();
		pMainWindow->pollEvents();

		gameObjects = levelSystem.getGameObjects();
		for (U64 i = 0, size = gameObjects.size(); i < size; ++i)
			gameObjects[i]->update();

		if(physicsSystem.advance(s_frameTime.deltaTime(), levelSystem))
				physicsSystem.updateComponents(levelSystem);

		pMainWindow->clear();
		renderSystem.startFrame();
		renderSystem.forwardRender(levelSystem.getScene());
		
		renderSystem.endFrame();
		pMainWindow->swapBuffers();
	}
	s_frameTime.stop();
}

void Engine::StopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	levelSystem.loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak