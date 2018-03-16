#pragma once
#include <Core/Core.hpp>

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
	static bool running;
public:
	DRAK_API static int startup();
	DRAK_API static int shutdown();
	DRAK_API static void startLoop();
	DRAK_API static void stopGame();
};

} // namespace core
} // namespace drak