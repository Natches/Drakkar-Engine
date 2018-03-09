#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace ogl {

class GLVertexArray final {
public:
	GLVertexArray();
	~GLVertexArray();

	void Bind();

private:
	static GLVertexArray* s_pCurrent;
};

} // namespace ogl
} // namespace gfx
} // namespace drak

