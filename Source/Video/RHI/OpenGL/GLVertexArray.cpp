#include <GL/glew.h>
#include <Video/RHI/OpenGL/GLVertexArray.hpp>

namespace drak {
namespace video {
namespace ogl {

#pragma region Static Initialization
GLVertexArray* GLVertexArray::s_pCurrent = nullptr;
#pragma endregion

GLVertexArray::GLVertexArray() {

}

GLVertexArray::~GLVertexArray() {

}

void GLVertexArray::Bind() {
	s_pCurrent = this;
}

} // namespace ogl
} // namespace gfx
} // namespace drak