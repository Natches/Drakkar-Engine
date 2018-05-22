#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>
#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

class GLFrameBuffer final : public GLObject, public IFrameBuffer {
public:
	GLFrameBuffer() = default;
	~GLFrameBuffer();

	void bind() override;
	void create(I32 dimX, I32 dimY) override;

private:
	// TODO (Simon):
	//		- Texture retrieval (at least composite frame)
	//		- Member GLTexture (one for each attachment)
	GLuint m_texColor; 
};

} // namespace gl
} // namespace gfx
} // namespace drak