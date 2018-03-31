#pragma once

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/Base/IGraphicsDriver.hpp>

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

	bool startup(IGraphicsDriver* pDriver);
	void shutdown();

	void startFrame();
	void showFrame();

private:
	IGraphicsDriver* m_pDriver;
};

} // namespace gfx
} // namespace drak
