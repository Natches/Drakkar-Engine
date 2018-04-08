#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLFrameBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLFrameBuffer::~GLFrameBuffer() {
	if (m_glID != GL_INVALID)
		glDeleteFramebuffers(1, &m_glID);
}

void GLFrameBuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, m_glID);
}

void GLFrameBuffer::create(I32 dimX, I32 dimY) {
	// TODO (Simon): 
	//		- Replace texture code block with DSA equivalent
	//		- Affect a member GLTexture
	//		- Add more attachments (at least depth)

	glCreateFramebuffers(1, &m_glID);
	glGenTextures	(1, &m_texColor);
	glBindTexture	(GL_TEXTURE_2D, m_texColor);
	glTexImage2D	(GL_TEXTURE_2D, 0, GL_RGB, dimX, dimY, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture	(GL_TEXTURE_2D, 0);

	glNamedFramebufferTexture(m_glID, GL_COLOR_ATTACHMENT0, m_texColor, 0);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texColor, 0);
}

} // namespace gl
} // namespace gfx
} // namespace drak