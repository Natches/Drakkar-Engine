#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

class GLVertexBuffer final {
public:
	GLVertexBuffer();
	~GLVertexBuffer();

	void create();
	void bind();

private:
	GLuint m_glID;
};

} // namespace gl
} // namespace video
} // namespace drak