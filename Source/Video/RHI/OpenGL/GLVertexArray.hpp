#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

class GLVertexArray final {
public:
	GLVertexArray();
	~GLVertexArray();

	void create();
	void bind();

private:
	GLuint m_glID;
};

} // namespace gl
} // namespace gfx
} // namespace drak

