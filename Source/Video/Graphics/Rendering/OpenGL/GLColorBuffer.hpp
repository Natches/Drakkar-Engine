#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>
#include <Video/Graphics/Rendering/Base/IColorBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

class GLColorBuffer final : public GLObject, public IColorBuffer {
public:
	GLColorBuffer() = default;
	~GLColorBuffer() = default;

	void attach() override;
	void create(I32 dimX, I32 dimY) override;
};

} // namespace gl
} // namespace gfx
} // namespace drak