#include <Video/Graphics/Rendering/RenderSystem.hpp>

namespace drak {
namespace gfx {

bool RenderSystem::startup() {

}

void RenderSystem::shutdown() {

}

void RenderSystem::startFrame() {
	m_pRenderHardware->clear();
}

void RenderSystem::showFrame() {

}


} // namespace gfx
} // namespace drak