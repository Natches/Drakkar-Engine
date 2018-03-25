#pragma once

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Video/Graphics/RHI/OpenGL/GLTexture.hpp>

namespace drak {
namespace video {
namespace gl {

GLTexture::GLTexture() {

}

GLTexture::~GLTexture() {
	glDeleteTextures(1, &m_glID);
}

void GLTexture::use() const {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_glID);
}

bool GLTexture::loadFromFile(const std::string& filename) {
	I32 dimX, dimY, channels;

	stbi_set_flip_vertically_on_load(true);
	U8* image = stbi_load(filename.c_str(), &dimX, &dimY, &channels, STBI_rgb);

	if (image) {
		glCreateTextures	(GL_TEXTURE_2D, 1, &m_glID);
		glTextureStorage2D	(m_glID, 1, GL_RGB8, dimX, dimY);
		glTextureSubImage2D	(m_glID, 0, 0, 0, dimX, dimY, GL_RGB, GL_UNSIGNED_BYTE, image);
		glTextureParameteri	(m_glID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri	(m_glID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//	glBindTextureUnit	(0, m_glID);

		// ... texture arrays
		// ... parameter flexibility
		// ... mipmap generation

		stbi_image_free(image);

		return true;
	}
	return false;
}

} // namespace gl
} // namespace video
} // namespace drak