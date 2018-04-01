#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLColorBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

void GLColorBuffer::attach() {
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_glID, 0);
}

void GLColorBuffer::create(I32 dimX, I32 dimY) {
	glGenTextures	(1, &m_glID);
	glBindTexture	(GL_TEXTURE_2D, m_glID);
	glTexImage2D	(GL_TEXTURE_2D, 0, GL_RGB, dimX, dimY, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture	(GL_TEXTURE_2D, 0);
}

} // namespace gl
} // namespace gfx
} // namespace drak