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
	glBindTextureUnit(0, m_glID);
}

bool GLTexture::loadFromFile(const std::string& filename) {
	I32 dimX, dimY, channels;

	stbi_set_flip_vertically_on_load(true);
	U8* image = stbi_load(filename.c_str(), &dimX, &dimY, &channels, 0);

	if (image) {
		glCreateTextures		(GL_TEXTURE_2D, 1, &m_glID);
		glTextureStorage2D		(m_glID, 4, GL_RGB8, dimX, dimY);
		glTextureSubImage2D		(m_glID, 0, 0, 0, dimX, dimY, GL_RGB, GL_UNSIGNED_BYTE, image);
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);
		glGenerateTextureMipmap	(m_glID);

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