#pragma once

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLElementBuffer
* \ingroup DrakVideo
* \brief
*
*/
class GLElementBuffer final
{
public:
	GLElementBuffer() = default;
	~GLElementBuffer() = default;

	DK_GETTER(GLuint, glID, m_glID)

private:
	GLuint m_glID;
};

} // namespace gl
} // namespace gfx
} // namespace drak
