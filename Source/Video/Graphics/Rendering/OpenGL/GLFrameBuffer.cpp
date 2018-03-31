#include <GL/glew.h>
#include <Video/Graphics/Rendering/OpenGL/GLFrameBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLFrameBuffer::GLFrameBuffer() {

}

GLFrameBuffer::~GLFrameBuffer() {

}

void GLFrameBuffer::create() {
	glGenBuffers(1, &m_glID);
}

void GLFrameBuffer::bind() {

}

} // namespace gl
} // namespace gfx
} // namespace drak