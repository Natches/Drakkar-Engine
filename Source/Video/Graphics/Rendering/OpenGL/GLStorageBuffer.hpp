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
class GLStorageBuffer final : public GLObject {
public:
	GLStorageBuffer() = default;
	~GLStorageBuffer();

	void create(U64 bytes, void* pData = nullptr);
	void bind();
	void write(U64 offset, U64 bytes, void* pData);

private:
	void* m_pMappedBufferData;

};

} // namespace gl
} // namespace gfx
} // namespace drak