#include <Video/Graphics/Rendering/RenderSystem.hpp>
#include <Windowing/Input/Keyboard.hpp>

using namespace drak::events;
using namespace drak::function;

namespace drak {
namespace gfx {

bool RenderSystem::startup(IRenderer* pRenderer) {
	Keyboard::Get().addEventListener(
		KeyEvent::KEY_UP,
		new MemberFunction<RenderSystem, void, const Event*>
		(this, &RenderSystem::onKeyUp, &Keyboard::Get().event()));

	m_pRenderer = pRenderer;
	m_pRenderer->info();

	m_pRenderer->depthTest(true);
	m_pRenderer->blendTest(true);
	m_pRenderer->cullTest(true);

	return true;
}

void RenderSystem::shutdown() {
	
}

void RenderSystem::render() {

}

void RenderSystem::startFrame() {
	m_pRenderer->clear();

	
}

void RenderSystem::opaquePass() {
	
}

void RenderSystem::transparentPass() {
	
}

void RenderSystem::endFrame() {
}

void RenderSystem::onKeyUp(const events::Event* pEvt) {
	static bool toggle = false;

	auto k = static_cast<const KeyEvent*>(pEvt);
	DK_SELECT(k->key)
		DK_CASE(Key::KEY_0, m_pRenderer->multisampling(toggle); toggle = !toggle)
	DK_END
}


} // namespace gfx
} // namespace drak