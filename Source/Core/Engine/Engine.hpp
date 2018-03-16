#pragma once
#include <Core/Core.hpp>

#include <Core/Utils/ClassUtils.h>

namespace drak {

namespace time {

class FrameTimer;

} // namespace time
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
	static void update();

public:
	static time::FrameTimer& s_frameTime;
	// System X
	// System Y
	// ...
private:
	static bool running;
public:
	DRAK_API static int startup();
	DRAK_API static int shutdown();
	DRAK_API static void startLoop();
	DRAK_API static void stopGame();
};

} // namespace core
} // namespace drak