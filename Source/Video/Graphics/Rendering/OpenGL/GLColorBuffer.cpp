#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

void GLColorBuffer::bind() {
	glBindFramebuffer(GL_FRAMEBUFFER, m_glID);
}

void GLColorBuffer::create(I32 dimX, I32 dimY) {
	// TODO (Simon):
	//		- Replace texture code block with DSA equivalent
	//		- Affect a member GLTexture
	//		- Add more attachments (at least depth)

	glCreateFramebuffers(1, &m_glID);
	glGenTextures	(1, &m_texID);
	glBindTexture	(GL_TEXTURE_2D, m_texID);
	glTexImage2D	(GL_TEXTURE_2D, 0, GL_RGB, dimX, dimY, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri	(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture	(GL_TEXTURE_2D, 0);

	glNamedFramebufferTexture(m_glID, GL_COLOR_ATTACHMENT0, m_texID, 0);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texID, 0);
}

} // namespace gl
} // namespace gfx
} // namespace drak