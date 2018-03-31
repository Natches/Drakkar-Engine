#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Video/VideoSettings.hpp>

namespace drak { 
namespace video { class AWindow; }
namespace gfx	{ class IGraphicsDriver; } 
} // Forward Declarations

namespace drak {
namespace video {

/*!
* \class VideoSystem
* \ingroup DrakVideo
* \brief
*
*/
class VideoSystem final {
	DK_NONMOVABLE_NONCOPYABLE(VideoSystem)
public:
	VideoSystem() = default;

	bool startup(const VideoSettings& settings, AWindow*& pMainWindow);
	void shutdown();

	DK_GETTER(gfx::IGraphicsDriver*, graphicsDriver, m_pGfxDriver)

private: 
	gfx::IGraphicsDriver* m_pGfxDriver;
};

} // namespace video
} // namespace drak