#pragma once

#include <Windowing/Window/WindowSettings.hpp>
#include <Video/Graphics/Rendering/Base/IGraphicsDriver.hpp>

namespace drak {
namespace video {

struct VideoSettings {
	WindowSettings			window;
	gfx::EGraphicsDriver	gfxDriver;
};

} // namespace video
} // namespace drak