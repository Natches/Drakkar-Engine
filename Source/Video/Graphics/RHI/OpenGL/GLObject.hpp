#pragma once

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
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

	DK_GETTER(GLuint, glID, m_glID)

protected:
	GLuint m_glID;
};

} // namespace gl
} // namespace video
} // namespace drak
