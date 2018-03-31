#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

class GLFrameBuffer final : public GLObject {
public:
	GLFrameBuffer();
	~GLFrameBuffer();

	void create();
	void bind();
};

} // namespace gl
} // namespace gfx
} // namespace drak