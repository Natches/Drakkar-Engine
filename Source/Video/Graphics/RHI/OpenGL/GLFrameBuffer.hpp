#pragma once

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

class GLFrameBuffer final {
public:
	GLFrameBuffer();
	~GLFrameBuffer();

	void create();
	void bind();

private:
	GLuint m_glID;
};

} // namespace gl
} // namespace video
} // namespace drak