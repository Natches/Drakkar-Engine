#pragma once

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/IRenderHardware.hpp>

namespace drak {
namespace gfx {

/*!
* \class RenderSystem
* \ingroup Graphics
* \brief
*
*/
class RenderSystem final
{
	DK_NONMOVABLE_NONCOPYABLE(RenderSystem)
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	bool startup();
	void shutdown();

	void startFrame();
	void showFrame();

private:
	IRenderHardware* m_pRenderHardware;
};

} // namespace gfx
} // namespace drak
