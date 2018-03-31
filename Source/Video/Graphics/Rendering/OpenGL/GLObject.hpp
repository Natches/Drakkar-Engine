#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLObject
* \ingroup DrakVideo
* \brief
*
*/
class GLObject {
public:
	GLObject() = default;
	virtual ~GLObject() = default;

	DK_GETTER_C(GLuint, glID, m_glID)

protected:
	GLuint m_glID;
};

} // namespace gl
} // namespace gfx
} // namespace drak
