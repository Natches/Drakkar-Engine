#pragma once

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
};

} // namespace core
} // namespace drak