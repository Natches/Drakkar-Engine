#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLUniformBuffer
* \ingroup DrakVideo
* \brief
*
*/
class GLUniformBuffer final : public GLObject {
public:
	GLUniformBuffer() = default;
	~GLUniformBuffer();

	void create(U64 bytes, void* pData = nullptr);
	void bind();
	void write(U64 offset, U64 bytes, void* pData);

private:
	U64	bytes;
};

} // namespace gl
} // namespace gfx
} // namespace drak