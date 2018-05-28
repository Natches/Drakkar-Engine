#include <PrecompiledHeader/pch.hpp>

#include <Converter/ModelImporter.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLTexture::GLTexture() {

}

GLTexture::~GLTexture() {
	if (m_glID != GL_INVALID)
		glDeleteTextures(1, &m_glID);
}

void GLTexture::bind() const {
	glBindTextureUnit(0, m_glID);
}

bool GLTexture::loadFromFile(const char* filename, bool verticalFlip) {
	definition::Texture tex;
	tools::importer::loadTextureFromFile(filename, tex);
	GLenum formatSz	= tex.format == GL_RGB ? GL_RGB8 : GL_RGBA8;

	if (tex.pixels.size() > 0) {
		glCreateTextures		(GL_TEXTURE_2D, 1, &m_glID);
		glTextureStorage2D		(m_glID, 8, formatSz, tex.width, tex.height);
		glTextureSubImage2D		(m_glID, 0, 0, 0, tex.width, tex.height, tex.format, 
								 GL_UNSIGNED_BYTE, tex.pixels.data());
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureParameteri		(m_glID, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri		(m_glID, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);
		glGenerateTextureMipmap	(m_glID);
		return true;
	}
	return false;
}


} // namespace gl
} // namespace gfx
} // namespace drak