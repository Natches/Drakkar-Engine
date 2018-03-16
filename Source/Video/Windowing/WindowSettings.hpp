#pragma once

#include <Core/Core.hpp>

namespace drak {
namespace video {

struct WindowSettings {
	const char*		title;
	I32				resX, resY;

	/*
	enum class DisplayMode : U8 {
		SHOWN,
		FULLSCREEN,
		MINIMIZED,
		MAXIMIZED,
		HIDDEN
	} displayMode;
	*/
};

}
} // namespace drak