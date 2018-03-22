#pragma once

#include <Video/Graphics/RHI/OpenGL/GLObject.hpp>

namespace drak {
namespace video {
namespace gl {

class GLFrameBuffer final : public GLObject {
public:
	GLFrameBuffer();
	~GLFrameBuffer();

	void create();
	void bind();
};

} // namespace gl
} // namespace video
} // namespace drak