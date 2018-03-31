#include <Video/Graphics/Rendering/RenderSystem.hpp>

namespace drak {
namespace gfx {

bool RenderSystem::startup(IGraphicsDriver* pDriver) {
	m_pDriver = pDriver;
	return true;
}

void RenderSystem::shutdown() {

}

void RenderSystem::startFrame() {
	m_pDriver->clear();
}

void RenderSystem::showFrame() {

}


} // namespace gfx
} // namespace drak