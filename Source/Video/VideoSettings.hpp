#pragma once

#include <Windowing/Window/WindowSettings.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>

namespace drak {
namespace video {

struct VideoSettings {
	WindowSettings	window;
	gfx::ERenderer	renderer;
};

} // namespace video
} // namespace drak