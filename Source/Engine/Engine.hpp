#pragma once

#include <Core/Core.hpp>
#include <Core/Engine/Event.hpp>
#include <Core/Timer/FrameTimer.hpp>
#include <Threading/Thread/ThreadPool.hpp>

namespace drak {

#pragma region Forward Declarations
class IManualSceneBlueprint;
class PhysicsSystem;
class LevelSystem;

namespace gfx {
	class RenderSystem;
} // namespace gfx

namespace video {
	class VideoSystem;
	class AWindow;
} // namespace video

namespace events {
struct EngineEvent : public Event { };

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
} // namespace events
#pragma endregion 

namespace core {
class Engine final {
	DK_NONMOVABLE_NONCOPYABLE(Engine)

public:
	DRAK_API ~Engine();

	//---------------------------------------------------------------------------------------------
	//	Static Methods
	DRAK_API static void StopGame();

	//---------------------------------------------------------------------------------------------
	//	Core Functionality
	DRAK_API int					startup(bool editorMode = false);
	DRAK_API int					shutdown();
	DRAK_API void					startLoop();
	DRAK_API void					renderScene();
	DRAK_API void					loadScene(IManualSceneBlueprint& sceneBlueprint);
	DRAK_API void					loadScene(const char* name);

	//---------------------------------------------------------------------------------------------
	//	Getters
	DRAK_API PhysicsSystem&			getPhysicsSystem();
	DRAK_API LevelSystem&			currentLevel();

	events::EngineEventDispatcher&	GetEventDispatcher()	{ return m_eventDispatcher; }

	time::FrameTimer&				getFrameTimer()			{ return s_frameTime; }
	thread::ThreadPool m_pool;

private:
	static Engine* m_pInstance;
	DRAK_API Engine();

	DRAK_API static bool			s_running;

	time::FrameTimer				s_frameTime;
	PhysicsSystem*					m_pPhysicsSystem;
	LevelSystem*					m_pLevelSystem;
	video::AWindow*					m_pMainWindow;
	video::VideoSystem*				m_pVideoSystem;
	gfx::RenderSystem*				m_pRenderSystem;
	events::EngineEventDispatcher	m_eventDispatcher;
	events::EngineEvent				m_evt;
	bool							m_editorMode;
};

} // namespace core
} // namespace drak

#define EngineCurrentLevel drak::core::Engine::Get().currentLevel()
#define EnginePhysicsSystem drak::core::Engine::Get().getPhysicsSystem()
#define DeltaTime drak::core::Engine::Get().getFrameTimer().deltaTime()