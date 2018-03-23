#pragma once
#include <Core/Core.hpp>
#include <Core/Timer/FrameTimer.hpp>
#include <Threading/Thread/ThreadPool.hpp>
namespace drak {
namespace core {



/*!
 * \class Engine
 * \ingroup Core
 * \brief
 *
 */

class Engine final {
	DK_NONMOVABLE_NONCOPYABLE(Engine)

public:
	Engine() = default;
	~Engine() = default;

public:
	static time::FrameTimer s_frameTime;
	static thread::ThreadPool s_pool;
	DRAK_API static int startup();
	DRAK_API static int shutdown();
	DRAK_API static void startLoop();
	DRAK_API static void stopGame();

private:
	static bool running;

};

} // namespace core
} // namespace drak