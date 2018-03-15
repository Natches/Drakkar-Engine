#pragma once
#include <Core/Core.hpp>
#include <Core/SceneSystem.h>

namespace drak {
namespace core {

/*!
 * \class Engine
 * \ingroup Core
 * \brief 
 *
 */

class Engine final {
private:
	SceneSystem sceneSystem;
	static bool running;
public:
	DRAK_API SceneSystem& getSceneSystem();
	DRAK_API int startup();
	DRAK_API int shutdown();
	DRAK_API void startLoop();
	DRAK_API static void stopGame();
};

} // namespace core
} // namespace drak