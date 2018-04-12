#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLTexture.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLTexture::GLTexture() {

}

GLTexture::~GLTexture() {
	glDeleteTextures(1, &m_glID);
}

void GLTexture::bind() const {
	glBindTextureUnit(0, m_glID);
}

bool GLTexture::loadFromFile(const char* filename, bool verticalFlip) {
	stbi_set_flip_vertically_on_load(verticalFlip);

	I32 dimX, dimY, channels;
	U8* img = stbi_load(filename, &dimX, &dimY, &channels, 0);

	GLenum format	= channels == 3 ? GL_RGB : GL_RGBA;
	GLenum formatSz	= format == GL_RGB ? GL_RGB8 : GL_RGBA8;

	if (img) {
		glCreateTextures		(GL_TEXTURE_2D, 1, &m_glID);
		glTextureStorage2D		(m_glID, 8, format, dimX, dimY);
		glTextureSubImage2D		(m_glID, 0, 0, 0, dimX, dimY, formatSz, GL_UNSIGNED_BYTE, img);
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);
		glGenerateTextureMipmap	(m_glID);

		stbi_image_free(img);

		return true;
	}
	return false;
}

} // namespace gl
} // namespace gfx
} // namespace drak