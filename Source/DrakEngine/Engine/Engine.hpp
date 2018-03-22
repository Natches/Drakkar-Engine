#pragma once
#include <Core/Core.hpp>
namespace drak {
namespace time {
	class FrameTimer;
}
class PhysicsSystem;
class SceneSystem;
class IManualSceneBlueprint;
namespace core {
/*!
 * \class Engine
 * \ingroup Core
 * \brief
 *
 */

class DRAK_API Engine final {
	DK_NONMOVABLE_NONCOPYABLE(Engine)

public:
	Engine();
	~Engine() = default;

public:
	int startup();
	int shutdown();
	void startLoop();
	static void stopGame();
	void loadScene(IManualSceneBlueprint& sceneBluePrint);
private:
	time::FrameTimer& s_frameTime;
	PhysicsSystem& physicsSystem;
	SceneSystem& sceneSystem;
	static bool running;
};

} // namespace core
} // namespace drak