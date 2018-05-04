#pragma once
#include <Core/Core.hpp>
#include <Core/Engine/Event.hpp>
#include <Core/Timer/FrameTimer.hpp>
#include <Threading/Thread/ThreadPool.hpp>
//#include <Engine/Physics/PhysicsSystem.hpp>
//#include <Engine/Scene/LevelSystem.hpp>
//#include <Video/VideoSystem.hpp>
//#include <Video/Graphics/Rendering/RenderSystem.hpp>

namespace drak {
class IManualSceneBlueprint;
class PhysicsSystem;
class LevelSystem;
namespace gfx {
	class RenderSystem;
}
namespace video {
	class VideoSystem;
	class AWindow;
}

namespace events {
struct EngineEvent : public Event {
};
class EngineEventDispatcher : public DefaultEventDispatcher {
	friend class core::Engine;
public:
	enum : EventType {
		STARTUP_BEGIN,
		STARTUP_END,
		UPDATE_START,
		UPDATE_LOOP_START,
		UPDATE_LOOP_END,
		UPDATE_END,
		SHUTDOWN_START,
		SHUTDOWN_END
	};
};
}
namespace core {

class Engine final {
	DK_NONMOVABLE_NONCOPYABLE(Engine)

public:
	DRAK_API int startup();
	DRAK_API int shutdown();
	DRAK_API void startLoop();
	events::EngineEventDispatcher& GetEventDispatcher() { return m_eventDispatcher; }
	DRAK_API static void StopGame();
	DRAK_API void loadScene(IManualSceneBlueprint& sceneBluePrint);
	DRAK_API void loadScene(const char* name);
	DRAK_API static Engine& Get() {
		static Engine engine;
		return engine;
	}
	DRAK_API ~Engine();
	DRAK_API PhysicsSystem& getPhysicsSystem();
	DRAK_API time::FrameTimer& GetFrameTimer();
	DRAK_API LevelSystem& currentLevel();
	inline time::FrameTimer& getFrameTimer() { return s_frameTime; }
	template <typename T>
	void createAll();
	thread::ThreadPool m_pool;
private:
	DRAK_API Engine();
	time::FrameTimer	s_frameTime;
	PhysicsSystem*		m_pPhysicsSystem;
	LevelSystem*		m_pLevelSystem;
	video::VideoSystem*	m_pVideoSystem;
	gfx::RenderSystem*	m_pRenderSystem;
	video::AWindow*		m_pMainWindow;
	events::EngineEventDispatcher m_eventDispatcher;

	DRAK_API static bool running;

};

} // namespace core
} // namespace drak

#define CurrentLevel drak::core::Engine::Get().currentLevel()
#define DeltaTime drak::core::Engine::Get().getFrameTimer().deltaTime()